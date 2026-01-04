
//--------------------------------------------------------------------
#include <windows.h>
#include <windows.h>
#include <string>
#include <d3d9.h>
#include <d3dx9.h>
#include <tchar.h>
#include <iostream>
#include <d3dx9math.h>
#include <fstream>
#include <time.h>
#include <vector>
#include <math.h>
#include <fstream>
#include <cmath>

//--------------------------------------------------------------------
#pragma warning(disable:4244)
#pragma warning(disable:4700)
#pragma warning(disable:4996)
#pragma warning(disable:4305)
using namespace std;
ofstream infile;
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
//------------------------------------------------------------------------------------------------
char *GetDirectoryFile(char *filename);
void __cdecl add_log (const char * fmt, ...);
void thethread();
char dlldir[320];
//--------------------------------------------------------------------
DWORD FindPattern( DWORD dwStart, DWORD dwLen, BYTE* pszPatt, char pszMask[]){ 
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
}
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
//--------------------------------------------------------------------
HMODULE hGfxDx = LoadLibrary("i3GfxDx.dll");
DWORD dwFrameW				= (DWORD)GetModuleHandle("i3FrameworkDx.dll");
DWORD FrameW					= GetSizeofCode("i3FrameworkDx.dll");
//--------------------------------------------------------------------
DWORD dwi3GfxDx       = (DWORD)GetModuleHandleA("i3GfxDx.dll");
DWORD i3GfxDx         = GetSizeofCode("i3GfxDx.dll");
//--------------------------------------------------------------------
DWORD dwPBExe         = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD i3PBExe         = GetSizeofCode("PointBlank.exe");
//--------------------------------------------------------------------
DWORD dwNxChara       = (DWORD)GetModuleHandleA("NxCharacter.2.8.1.dll");
DWORD i3NxChara       = GetSizeofCode("NxCharacter.2.8.1.dll");
//--------------------------------------------------------------------
DWORD HookBaseRender  = (DWORD)GetProcAddress(hGfxDx, "?g_pRenderContext@@3PAVi3RenderContext@@A")- dwi3GfxDx;
DWORD dwHook          = FindPattern(dwi3GfxDx,i3GfxDx,(PBYTE)"\x8B\x80\x00\x00\x00\x00\x8B\x08\x8D\x54\x24\x00\x52\x50\x8B\x41\x00\xFF\xD0","xx????xxxxx?xxxx?xx");
DWORD dwBaseAddress   = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x89\x45\x00\x8B\x4D\x00\x8B\x11","xx????x????xx?xx?xx");
DWORD dwTeam		  = FindPattern(dwPBExe,i3PBExe, (PBYTE)"\x55\x8B\xEC\x51\x89\x4D\xFC\x8B\x45\xFC\x8B\x88\x00\x00\x00\x00\x51\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\xC8\xE8\x00\x00\x00\x00\x8B\xE5\x5D\xC3", "xxxxxxxxxxxx????xxx????x????xxx????xxxx");
DWORD dwQuick         = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x89\x81\x00\x00\x00\x00\x8B\x55\x00\x83\xBA\x00\x00\x00\x00\x00\x75\x00\x6A\x00\x68\x00\x00\x00\x00\x68\x00\x00\x00\x00\x6A\x00", "xx????xx?xx?????x?x?x????x????x?");
DWORD dwKill          = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8D\x84\x81\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x00\x00\x55\x8B\xEC\x83\xEC","xxx????xxxx??xxxxx");
DWORD dwPing          = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8A\x80\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x00\x00\xCC\x55\x8B\xEC\x51\x89\x4D\x00\x8B\x4D\x00","xx????xxxx??xxxxxxx?xx?");
DWORD dwScore         = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8D\x84\x81\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x00\x00\x55\x8B\xEC\x51\x89\x4D\x00","xxx????xxxx??xxxxxx?");
DWORD DwPTRpTarget2	  = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x83\xF8\xFF\x0F\x00\x00\x00\x00\x00\x8B\x55\xA0\x8B\x8A","xxxx?????xxxxx");
DWORD DwGetButton     = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x4D\xF0\xC7\x81\x00\x00\x00\x00\x00\x00\x00\x00\x8B\x4D\xF8\xFF\x15\x00\x00\x00\x00\x83\xE0\x01","xxxxx????????xxxxx????xxx");
DWORD dwBullet        = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x51\x8B\x4D\x00\x81\xC1\x00\x00\x00\x00\xFF\x15\x00\x00\x00\x00\x8B\x55\x00\x8B\x8A\x00\x00\x00\x00\xE8","xxx?xx????xx????xx?xx????x");
DWORD dwUnyuk         = FindPattern(dwPBExe,0xA00000,(PBYTE) "\xBE\x00\x00\x00\x00\x65\x43\x68","x????xxx");
DWORD DwDoLine        = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x00\x89\x4D\xF4\xC6\x45\xFF\x00\x83\x7D\x00\x00\x75\x2A\x6A\x00","xxxxx?xxxxxx?xx??xxx?");
DWORD DwCamPos        = FindPattern(dwPBExe,i3PBExe,(PBYTE) "\x53\x8B\xDC\x83\xEC\x00\x83\xE4\x00\x83\xC4\x00\x55\x8B\x6B\x00\x89\x6C\x24\x00\x8B\xEC\x81\xEC\x00\x00\x00\x00\x89\x4D\xFC\x83\x3D\x00\x00\x00\x00\x00\x75\x00","xxxxx?xx?xx?xxx?xxx?xxxx????xxxxx?????x?");
DWORD DwEventFire     = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x00\x56\x89\x4D\xD8\x83\x7D\x00\x00\x75\x00\x6A\x00","xxxxx?xxxxxx??x?x?");
DWORD dwSuicide       = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x00\x89\x4D\x00\x51\xD9\xE8","xxxxx?xx?xxx");
DWORD SetChara        = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x30\x89\x4D\xD0\x83\x7D\x08\x00\x74","xxxxxxxxxxxx?x");
DWORD dwUser	      = FindPattern(dwPBExe, i3PBExe,(PBYTE)"\xC6\x81\x00\x00\x00\x00\x00\x8B\x55\xFC\x69\xD2\x00\x00\x00\x00\x8B\x45\xF8", "xx???xxxxxxx????xxx");
//--------------------------------------------------------------------
/*addres*/DWORD ResultBasePlayer,ResultBasePlayer2,ResultBaseHealth,ResultBaseHealth2,ResultBaseAmmo,ResultBaseAmmo2,ResultBullet,ResultBugWeapon;
/*PTR*/   DWORD ResultTeam,ResultName,ResultBone,ResultHealth,ResultPlayer,ResultRANK1,ResultRANK2,ResultRESPAWN,ResultPing,ResultKill,ResultScore;
          DWORD ResultQuick,ResultPTRAmmo,ResultNorecoil,ResultTarget,ResultPTRTarget,ResultGetButton,ResultFallDamage,ResultRafidFire,ResultRafidFire2,ResultReRespawn;
/*Other*/ DWORD ResultDoLine,ResultCamPos ,ResultEventFire,ResultSuicide;
          DWORD ResultPrimary,ResultSecondary,ResultMelle,ResultSmoke,ResultExplosive;
/*Hook*/  DWORD ResultBaseAddress,ResultHook;
//--------------------------------------------------------------------
void Bagus_Updater(){
//--------------------------------------------------------------------
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwBaseAddress + 0x2), &ResultBaseAddress, sizeof(ResultBaseAddress), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwHook + 0x2), &ResultHook, sizeof(ResultHook), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwTeam+0xC), &ResultTeam, sizeof(ResultTeam), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwQuick + 0x2), &ResultQuick, sizeof(ResultQuick), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwPing + 0x2), &ResultPing, sizeof(ResultPing), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwScore + 0x3), &ResultScore, sizeof(ResultScore), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwKill + 0x3), &ResultKill, sizeof(ResultKill), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwPTRpTarget2+0xE), &ResultPTRTarget, sizeof(ResultPTRTarget), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwGetButton+0x12), &ResultGetButton, sizeof(ResultGetButton), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwBullet + 0xC ), &ResultBullet, sizeof(ResultBullet), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwUser+0x2), &ResultBone, sizeof(ResultBone), NULL);
//--------------------------------------------------------------------
//-------Addres----//
ResultBasePlayer      = ResultBaseAddress - dwPBExe;
ResultBasePlayer2     = ResultBaseAddress;
ResultBaseHealth      = ResultBaseAddress - dwPBExe - 0x34;
ResultBaseHealth2     = ResultBaseAddress - 0x34;
ResultBaseAmmo        = ResultBaseAddress - dwPBExe - 0x38;
ResultBaseAmmo2       = ResultBaseAddress - 0x38;
//-------PTR ESP---//
ResultTeam            = ResultTeam;
ResultName			  = ResultTeam - 0x420;
ResultBone            = ResultBone;
ResultHealth		  = 0x264;
ResultPlayer		  = ResultTeam - 0x1ED0;
ResultRANK1			  = ResultTeam - 0x1C64;
ResultRANK2			  = ResultTeam - 0x1C63;
ResultRESPAWN		  = ResultTeam - 0x19B0;
ResultPing			  = ResultPing  ;
ResultKill			  = ResultKill  ;
ResultScore			  = ResultScore ;
//-------PTR-------//
ResultQuick           = ResultQuick;
ResultPTRAmmo		  = ResultQuick + 0x4;
ResultNorecoil		  = ResultQuick + 0x18;
ResultTarget          = ResultQuick + 0x20;
ResultPTRTarget       = ResultPTRTarget;
ResultGetButton       = ResultGetButton;
ResultFallDamage	  = ResultQuick + 0x18 - 0x48;
ResultRafidFire		  = ResultQuick + 0x18 - 0x7C;
ResultRafidFire2	  = ResultQuick + 0x18 - 0x54;
ResultReRespawn		  = ResultQuick + 0x18 - 0x48 + 0x3;
//-------Replace---//
ResultPrimary		  = ResultTeam - 0x187C;
ResultSecondary 	  = ResultTeam - 0x187C + 0x4;
ResultMelle			  = ResultTeam - 0x187C + 0x8;
ResultExplosive  	  = ResultTeam - 0x187C + 0xC;
ResultSmoke 		  = ResultTeam - 0x187C + 0x10;
//-------other-----//
ResultBullet          = ResultBullet;
ResultBugWeapon       = dwUnyuk - dwPBExe;
ResultDoLine          = DwDoLine;
ResultCamPos          = DwCamPos;
ResultEventFire       = DwEventFire;
SetChara              = SetChara;
ResultSuicide         = dwSuicide - dwPBExe;
//-------Hook------//
HookBaseRender        = HookBaseRender;
ResultHook            = ResultHook;
	}