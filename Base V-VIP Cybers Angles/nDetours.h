#pragma comment (lib, "d3dx9.lib")
#include <windows.h>
//-----------------------------------------------------------------------------------------------------------------------------------
#include <fstream>
//-----------------------------------------------------------------------------------------------------------------------------------

#pragma comment(lib,"detours.lib")
//-----------------------------------------------------------------------------------------------------------------------------------
#include <d3dx9.h>
#pragma comment(lib, "d3dx9.lib")
#ifdef FOR_D3D8
#include "d3dfont8.cpp"
#else
#include "d3dfont9.cpp"
#endif
#include <iostream>
#include <fstream>
#include <time.h>
#pragma warning(disable:4244)
#pragma warning(disable:4996) 
#pragma warning(disable:4305)

using namespace std;

#define ES  0 //EndScene
#define DIP 1 //DrawIndexedPrimitive
#define RES 2 //Reset
bool bMenu = true;
bool runOnce = true;
D3DVIEWPORT9	pViewPort;

LPDIRECT3DTEXTURE9 TexMenu, TexCursor, TexNorm, TexActive;
LPD3DXSPRITE SptMenu;


#include <windows.h>
#include "ADE32.h"

DWORD B8Detours( DWORD  SrcVA, DWORD  DstVA, DWORD  Size )
{
	#define SIZEOF_MOVEAX_JMPEAX 12
	DWORD DetourVA, dwProtect, i;
	if ( SrcVA && DstVA && Size >= SIZEOF_MOVEAX_JMPEAX )
	{
		DetourVA = (DWORD) VirtualAlloc( 
			NULL, Size + SIZEOF_MOVEAX_JMPEAX, 
			MEM_COMMIT, PAGE_EXECUTE_READWRITE );
		if ( DetourVA && VirtualProtect( (VOID*)SrcVA, Size, PAGE_EXECUTE_READWRITE, &dwProtect ) )
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
			VirtualProtect( (VOID*)SrcVA, Size, dwProtect, &dwProtect );
			VirtualProtect( (VOID*)DetourVA, Size + 
				SIZEOF_MOVEAX_JMPEAX, PAGE_EXECUTE_READ, &dwProtect );

	    	return DetourVA;
		}
	}
	return(0);
}

PBYTE HookVTableFunction( PDWORD* dwVTable, PBYTE dwHook, INT Index )
{
    DWORD d = 0;
	DWORD ds = 0;
    Sleep(-0);
    PBYTE pOrig = ((PBYTE)(*dwVTable)[Index]);
    (*dwVTable)[Index] = (DWORD)dwHook;
	memcpy(pOrig, dwVTable, ds);
    Sleep(-0);
    Sleep(-0);
	memcpy(pOrig,(void*)(pOrig), 4);  
	return pOrig;
}
//------------------------------------------------------------------------------------------------------
PBYTE PenkHookVTable( PDWORD* dwVTable, PBYTE dwHook, INT Index )
{
    DWORD dwOld = 0;
    VirtualProtect((void*)((*dwVTable) + (Index*4) ), 4, PAGE_EXECUTE_READWRITE, &dwOld);
    PBYTE pOrig = ((PBYTE)(*dwVTable)[Index]);
    (*dwVTable)[Index] = (DWORD)dwHook;
    VirtualProtect((void*)((*dwVTable) + (Index*4)), 4, dwOld, &dwOld);
    return pOrig;
}
void HookF8(PDWORD target, PDWORD newfunc)
{
	DWORD Jmpto=(DWORD)(newfunc)-(DWORD)target-7;
	DWORD a;
    VirtualProtect(target, 8, PAGE_EXECUTE_READWRITE, &a);
    *(PBYTE)(target)=0x50;
    *(PBYTE)((DWORD)(target)+1)=0x58;
    *(PBYTE)((DWORD)(target)+2)=0xE9;
    *(PDWORD)((DWORD)(target)+3)=Jmpto;
	VirtualProtect(target, 8, a, &a);
}

void *DetourFunc(BYTE *src, const BYTE *dst, const int len)
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

