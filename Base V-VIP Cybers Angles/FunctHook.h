//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
#define ES  0 //EndScene
#define DIP 1 //DrawIndexedPrimitive
#define E8 2 //Reset
#define ZE 3 //Reset
#define RES 4 //Reset
DWORD PosE8;
DWORD PosRES;
DWORD PosZE;
DWORD PosDIP;
DWORD PosES;
DWORD BackEndSceneD3D;
BYTE backupES[9];


int Detourb8(DWORD SrcVA, DWORD DstVA, DWORD Size, unsigned char *lpBackup)
{

	if (Size > 0) {
        ReadProcessMemory(GetCurrentProcess(), (LPVOID)SrcVA, lpBackup, Size, NULL);
    }
	DWORD DetourVA, dwProtect, i;
	#define SIZEOF_MOVEAX_JMPEAX 7
	if ( SrcVA && DstVA && Size >= SIZEOF_MOVEAX_JMPEAX )
	{
		DetourVA = (DWORD)VirtualAlloc( NULL, Size + SIZEOF_MOVEAX_JMPEAX, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if ( DetourVA && VirtualProtectEx(GetCurrentProcess(),(void*)SrcVA, Size, PAGE_READWRITE, &dwProtect ))
		{
			for ( i=0; i < Size; i++ ) {
				*(BYTE*)( DetourVA + i ) = *(BYTE*)( SrcVA + i );
			}
			*(BYTE*)( DetourVA + Size + 0 ) = 0xB8;
			*(DWORD*)( DetourVA + Size + 1 ) = ( SrcVA + Size );
			*(WORD*)( DetourVA + Size + 5 ) = 0xE0FF;
			*(BYTE*)( SrcVA + 0 ) = 0xB8;
			*(DWORD*)( SrcVA + 1 ) = ( DstVA );
			*(WORD*)( SrcVA + 5 ) = 0xE0FF;
			VirtualProtectEx(GetCurrentProcess(),(void*)SrcVA, Size, dwProtect, &dwProtect );
			VirtualProtectEx(GetCurrentProcess(),(void*)DetourVA, Size + SIZEOF_MOVEAX_JMPEAX, PAGE_EXECUTE_READ, &dwProtect);
	    	return DetourVA;
		}
	}
	return (0);
}



PBYTE HookVTableFunction( PDWORD* dwVTable, PBYTE dwHook, INT Index )
{

     DWORD dwOld = 0;
//-----------------------------------------
    Sleep(-0);
	VirtualProtect((void*)((*dwVTable) + (Index*4) ), 0, PAGE_EXECUTE_READWRITE, &dwOld);
    PBYTE pOrig = ((PBYTE)(*dwVTable)[Index]);
    (*dwVTable)[Index] = (DWORD)dwHook;
	//memcpy(pOrig, dwVTable, ds);
	VirtualProtect((void*)((*dwVTable) + (Index*4)), 0, dwOld, &dwOld);
    Sleep(-0);
//-----------------------------------------------------
    Sleep(-0);
//---------------------------------------------------------------
	//memcpy(pOrig,(void*)(pOrig), 4);  
//----------------------------------------------------------------------------
    return pOrig;
}
//-----------------------------------------------------------------------------------
void _patchMEM(unsigned long dwBaseAddr, unsigned char* dwPatchVal, int size)
{
	DWORD Protect;
    VirtualProtect((void*)dwBaseAddr, size, PAGE_EXECUTE_READWRITE, &Protect);
    memcpy((void*)dwBaseAddr, dwPatchVal, size);
	VirtualProtect((void*)dwBaseAddr, size, Protect, &Protect);
}

void hook(PDWORD target, PDWORD myFunction)
{
	DWORD Jmpto=((DWORD)(myFunction)-(DWORD)target)-7;
	DWORD a;
    VirtualProtect(target, 10, PAGE_EXECUTE_READWRITE, &a);
	*(PBYTE)((DWORD)(target))=0x60;
	*(PBYTE)((DWORD)(target)+1)=0x61;
	*(PBYTE)((DWORD)(target)+2)=0xE9;
    *(PDWORD)((DWORD)(target)+3)=Jmpto;
	VirtualProtect(target, 10, a, &a);
}

void *DetourFunc(BYTE *src, const BYTE *dst, const int len=0)
{
        BYTE *jmp = (BYTE*)malloc(len+5);
        DWORD dwback;
        VirtualProtect(src, len, PAGE_READWRITE, &dwback);
        memcpy(jmp, src, len);  jmp += len;
        jmp[0] = 0xE9;
        *(DWORD*)(jmp+1) = (DWORD)(src+len - jmp) - 5;
        src[0] = 0xE9;
        *(DWORD*)(src+1) = (DWORD)(dst - src) - 5;
        VirtualProtect(src, len, dwback, &dwback);
        return (jmp-len);
}


void *DetourFunc1(BYTE *src, const BYTE *dst, const int len=0)
{
        BYTE *jmp = (BYTE*)malloc(len+5);
        DWORD dwback;
        VirtualProtect(src, len, PAGE_READWRITE, &dwback);
        memcpy(jmp, src, len);  jmp += len;
        jmp[0] = 0xE9;
        *(DWORD*)(jmp+1) = (DWORD)(src+len - jmp) - 5;
        src[0] = 0xE9;
        *(DWORD*)(src+1) = (DWORD)(dst - src) - 5;
        VirtualProtect(src, len, dwback, &dwback);
        return (jmp-len);
}