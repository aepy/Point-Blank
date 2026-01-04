#pragma warning(disable: 4996)
using namespace std;
ofstream infile;
DWORD FindPattern( DWORD dwStart, DWORD dwLen, BYTE* pszPatt, char pszMask[] ) 
{ 
	unsigned int i = NULL; 
	int iLen = strlen( pszMask ) - 1; 
	for( DWORD dwRet = dwStart; dwRet < dwStart + dwLen; dwRet++ ) 
	{ 
		if( *(BYTE*)dwRet == pszPatt[i] || pszMask[i] == '?' ) 
		{ 
			if( pszMask[i+1] == '\0' ) return( dwRet - iLen ); i++; 
		} 
		else i = NULL; 
	} return NULL; 
} 
DWORD GetSizeofCode( const char* szModuleName ) 
{ 
	HMODULE hModule = GetModuleHandleA( szModuleName ); 
	if ( !hModule ) return NULL; 
	PIMAGE_DOS_HEADER pDosHeader = PIMAGE_DOS_HEADER( hModule ); 
	if( !pDosHeader ) return NULL; 
	PIMAGE_NT_HEADERS pNTHeader = PIMAGE_NT_HEADERS( (LONG)hModule + pDosHeader->e_lfanew ); 
	if( !pNTHeader ) return NULL; 
	PIMAGE_OPTIONAL_HEADER pOptionalHeader = &pNTHeader->OptionalHeader; 
	if( !pOptionalHeader ) return NULL; 
	return pOptionalHeader->SizeOfCode; 
}
char *GetDirectoryFile(char *filename);
void __cdecl add_log (const char * fmt, ...);
void thethread();
char dlldir[320];
//--------------------------------------------------------------------
/*DWORD FindPattern( DWORD dwStart, DWORD dwLen, BYTE* pszPatt, char pszMask[]){ 
unsigned int i = NULL; 
int iLen = strlen( pszMask ) - 1; 
for( DWORD dwRet = dwStart; dwRet < dwStart + dwLen; dwRet++ ){ 
if( *(BYTE*)dwRet == pszPatt[i] || pszMask[i] == '?' ){ 
if( pszMask[i+1] == '\0' ) return( dwRet - iLen ); i++; 
} 
else i = NULL; 
}
return NULL; 
}
//--------------------------------------------------------------------
DWORD GetSizeofCode( const char* szModuleName ) { 
HMODULE hModule = GetModuleHandleA( szModuleName ); 
if ( !hModule ) return NULL; 
PIMAGE_DOS_HEADER pDosHeader = PIMAGE_DOS_HEADER( hModule ); 
if( !pDosHeader ) return NULL; 
PIMAGE_NT_HEADERS pNTHeader = PIMAGE_NT_HEADERS( (LONG)hModule + pDosHeader->e_lfanew ); 
if( !pNTHeader ) return NULL; 
PIMAGE_OPTIONAL_HEADER pOptionalHeader = &pNTHeader->OptionalHeader; 
if( !pOptionalHeader ) return NULL; 
return pOptionalHeader->SizeOfCode; 
}*/
//--------------------------------------------------------------------
char *GetDirectoryFile(char *filename)
{
static char path[320];
strcpy(path, dlldir);
strcat(path, filename);
return path;
}
//--------------------------------------------------------------------
void __cdecl Writelog (const char *fmt, ...)
{
if(infile != NULL)
{
if(!fmt) { return; }

va_list va_alist;
char logbuf[256] = {0};

va_start (va_alist, fmt);
_vsnprintf (logbuf+strlen(logbuf), sizeof(logbuf) - strlen(logbuf), fmt, va_alist);
va_end (va_alist);

infile << logbuf << endl;
}
}
