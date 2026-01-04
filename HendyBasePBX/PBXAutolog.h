#include <winbase.h>
#include "PBXXStr.h"
DWORD I3Ammo_CALL,I3Ammo_RET,I3IlegalState,I3IlegalStateA,I3IlegalStateB,I3IlegalStateC,I3WeaponBaseA, I3PlayerBaseA, I3WeaponBase, I3DefuseTime,I3SetupTime,I3NamePlayer,ReturnI3NamePlayer,hExe,hStop,hFrame,hGet,hEhsvc;
DWORD BaseChara, adrPlayer, adrWeapon, adrESP, dwEsp;

using namespace std;ofstream infile;
char *GetDirectoryFile(char *filename);
char dlldir[320];
ofstream ofile; 

bool bCompareA(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
for(;*szMask;++szMask,++pData,++bMask)
if(*szMask=='x' && *pData!=*bMask ) 
return false;
return (*szMask) == NULL;
}

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
}}

DWORD FindPattern(DWORD dwAddress,DWORD dwLen,BYTE *bMask,char * szMask)

	{
for(DWORD i=0; i < dwLen; i++)
if( bCompareA( (BYTE*)( dwAddress+i ),bMask,szMask) )
return (DWORD)(dwAddress+i);
return 0;
}

char *GetDirectoryFile(char *filename)
{
static char path[320];
strcpy(path, dlldir);
strcat(path, filename);
return path;
}
//==================================================================================================================================//
UCHAR uPeler	[] = {0xEB, 0x05, 0xE9, 0x00, 0x00, 0x00, 0x00, 0x8B, 0x55, 0xFC, 0x89};
UCHAR BASEWEAP	[] = {0x8B, 0x0D, 0x00, 0x00, 0x00, 0x00, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x89, 0x45, 0x00, 0x8B, 0x4D, 0x00, 0x8B, 0x11};
UCHAR GMSKILL   [] = {0x8D, 0x84, 0x10, 0x00, 0x00, 0x00, 0x00, 0x8B, 0xE5, 0x5D, 0xC2, 0x04, 0x00, 0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,};
BYTE PI_ON [16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
UCHAR GM2		[] = {0x8D, 0x84, 0x01, 0x00, 0x00, 0x00, 0x00, 0x8B, 0xE5, 0x5D, 0xC2, 0x04, 0x00, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC};
//==================================================================================================================================//
DWORD WINAPI SearchOffset(LPVOID param)
{
dwStartAddress = (DWORD)GetModuleHandle("PointBlank.exe");
hStop = dwStartAddress + 0x608000;
dwSize = 0x8E0000;
while(1)
{
		DWORD dwSkillGM						= FindPattern(dwStartAddress,dwSize,(PBYTE)GM2,//"xxxx????xxxx??xxxxxxxxxxxxxx");
		XStr( /*xxx????xxxx??xxxxxxxxxxxxxx*/ 0x07, 0x1B, 0x8B, 0xF3F4F5B1, 0xB0AFAEEA, 0xEBECEDA9, 0xA8E0E1E2, 0xE3E4E5E6, 0xE7D8D9DA, 0xDBDCDD00 ).c());
		ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwSkillGM+3), &Skill, sizeof(Skill), NULL);
		DWORD dwBaseWeapon					= FindPattern(dwStartAddress,dwSize,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x89\x45\x00\x8B\x4D\x00\x8B\x11","xx????x????xx?xx?xx");
		DWORD Skill1						= FindPattern(dwStartAddress,dwSize,(PBYTE)"\x8B\x45\xFC\x8B\xE5\x5D\xC2\x04\x00","xxxxxxxxx");
		DWORD Skill2						= FindPattern(dwStartAddress,dwSize,(PBYTE)"\x89\x4D\xFC\x8B\x45\x14\x50\x8B\x4D\x10\x51\x8B\x55\x0C\x52\x8B\x45\x08\x50\x8B\x4D\xFC\xFF\x15\x00\x00\x00\x00\x8B\x4D\xFC\xC7\x01\x00\x00\x00\x00\x8B\x45\xFC\x8B\xE5\x5D\xC2\x10\x00","xxxxxxxxxxxxxxxxxxxxxxxx????xxxxx????xxxxxxxxx");
		ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwBaseWeapon+0x2), &ResultBase, sizeof(ResultBase), NULL);
//******************************************Convert hasil di atas ke offset asli*****************************************************************//
		ResultBaseWeapon					= ResultBase	 -  dwStartAddress;
		ResultBaseWeapon2					= ResultBase;
		ResultBasePlayer					= ResultBase	 -  dwStartAddress + 0x1C;
		ResultBasePlayer2					= ResultBase + 0x1C;
		ResultBaseHealth                    = ResultBase     -  dwStartAddress - 0x1C + 0x4;
		ResultBaseHealth2                   = ResultBase     - 0x1C + 0x4;
		ResultBaseAmmo                      = ResultBase     -  dwStartAddress - 0x1C;
		ResultBaseAmmo2                     = ResultBase     - 0x1C;
//		ResultBaseVK						= ResultBase - 0x28;
		I3ESP                               = ResultBase - dwStartAddress - 0x18;
		ResultHS							= Skill + 0x1CFC; 
		ResultDMG   						= Skill + 0x1CFC + 0x40;
		ResultBypassPI						= Skill + 0x1CFC + 0x240 ;
		ResultBypassKaca					= Skill + 0x1CFC - 0x280 ;
//==================================================================================================================================//
		Writelog("#define OFS_Weapon		0x%X ", ResultBaseWeapon);
		Writelog("#define OFS_Weapon2		0x%X ", ResultBaseWeapon2);
		Writelog("#define OFS_Player		0x%X ", ResultBasePlayer);
		Writelog("#define OFS_Player2		0x%X ", ResultBasePlayer2);
		Writelog("#define OFS_Health		0x%X ", ResultBaseHealth);
		Writelog("#define OFS_Health2		0x%X ", ResultBaseHealth2);
		Writelog("#define OFS_Ammo			0x%X ", ResultBaseAmmo);
		Writelog("#define OFS_Ammo2			0x%X ", ResultBaseAmmo2);
		Writelog("#define OFS_BaseVK		0x%X ", ResultBaseVK);
		Writelog("#define OFS_Esp			0x%X ", I3ESP);
		Sleep(10);
		}}
//==================================================================================================================================//
