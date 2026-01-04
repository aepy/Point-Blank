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
#include "XStr.h"
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
//HMODULE hGfxDx = LoadLibrary("i3GfxDx.dll");
//--------------------------------------------------------------------
HMODULE hGfxDx = LoadLibrary("i3GfxDx.dll");
DWORD dwi3GfxDx       = (DWORD)GetModuleHandleA("i3GfxDx.dll");
DWORD i3GfxDx         = GetSizeofCode("i3GfxDx.dll");
//--------------------------------------------------------------------
DWORD dwPBExe         = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD i3PBExe         = GetSizeofCode("PointBlank.exe");
//--------------------------------------------------------------------
DWORD dwNxChara       = (DWORD)GetModuleHandleA("NxCharacter.2.8.1.dll");
DWORD i3NxChara       = GetSizeofCode("NxCharacter.2.8.1.dll");
DWORD ModuleD3D9	= (DWORD)GetModuleHandleA("d3d9.dll");
DWORD ModuleSizeD3D9= GetSizeofCode("d3d9.dll");

//--------------------------------------------------------------------
DWORD OFSSkill, OFSHelmed, OFSReplace, WTF, WTW, ResultSmoke, OFSBullet, ResultBomb, ResultQuick, ResultPTRAmmo,ResultNorecoil;
DWORD ResultHook,ResultBaseRender, ResultBaseAddress, ResultKill, ResultPing, ResultScore, ResultWallShot, ResultInvincible, ResultPrimary, ResultMelee, ResultBaseBullet,ResultBullet;
DWORD ResultSkill, ResultSkill2, ResultRespawn,ResultRespawn2, ResultMajor, ResultBugWeapon, ResultDeathFly, ResultSuicide,ResultUserDeath;
DWORD ResultBaseWeapon, ResultBaseWeapon2, ResultBaseHealth, ResultBaseHealth2, ResultBasePlayer, ResultBasePlayer2, ResultBaseAmmo, ResultBaseAmmo2, ResultHeadGear, ResultBaret, ResultFloodKick, ResultBaseMove,ResultBaseMove2;
DWORD OFS_GameEventFire,OFS_CamPosition,OFS_DoLineCollision,ResultTeam,ResultFake,OFS_Team,ResultPlayer,PTR_Player,ResultSetEvent;
DWORD ResultPTRAmmoA, ResultPTRAmmoB, ResultPTRAmmoC, NeoPTRAmmoA, NeoPTRAmmoB, NeoPTRAmmoC, NeoPTRAmmoD, NeoPTRProtectA, NeoPTRProtectB, NeoPTRProtectC, NeoPTRProtectD,NeoAmmoL,BackAmmoL,NeoAmmoR,BackAmmoR,NeoAmmoX,BackAmmoX;
DWORD ResultPRIMARYSIZE,ResultSECONDARYSIZE, ResultMALESIZE,ResultBOMBSIZE,ResultSMOKESIZE;
DWORD NeoPTRgetNetCharaInfo,NeoPTRgCharaWeapon,NeoPTRgCharaSeccondary,NeoPTRgCharaKnife,NeoPTRgCharaGranad,NeoPTRgCharaSmoke,NeoUpdateNickOnTarget,RETNeoUpdateNickOnTarget;
DWORD ResultBugHover1, ResultBugHover2, ResultBugHover3, ResultBugHover4, ResultBugHover5;

//--------------------------------------------------------------------
DWORD HookBaseRender	= (DWORD)GetProcAddress(hGfxDx, "?g_pRenderContext@@3PAVi3RenderContext@@A")- dwi3GfxDx;
DWORD dwBaseAddress   = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x89\x45\x00\x8B\x4D\x00\x8B\x11","xx????x????xx?xx?xx");
DWORD dwBullet        = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x51\x8B\x4D\x00\x81\xC1\x00\x00\x00\x00\xFF\x15\x00\x00\x00\x00\x8B\x55\x00\x8B\x8A\x00\x00\x00\x00\xE8","xxx?xx????xx????xx?xx????x");
DWORD dwMajor         = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x88\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\xE5\x5D\xC3\xCC\xCC\xCC\xCC\x55\x8B\xEC","xx????x????xxxxxxxxxx");
DWORD dwSkill         = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x0F\xB6\x94\x01\x00\x00\x00\x00","xxxx????");
DWORD dwHelmed        = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8D\x84\x10\x00\x00\x00\x00\xEB\x00\xEB\x00\x8B\x4D","xxx????x?x?xx");
DWORD dwPrimary       = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x88\x00\x00\x00\x00\x51\xFF\x15\x00\x00\x00\x00\x83\xC4\x00\x8B\x55\x00\xC7\x82\x00\x00\x00\x00\x00\x00\x00\x00\x5E\x8B\xE5\x5D\xC3","xx????xxx????xx?xx?xx????????xxxxx");
DWORD dwKill          = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8D\x84\x81\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x00\x00\x55\x8B\xEC\x83\xEC","xxx????xxxx??xxxxx");
DWORD dwPing          = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8A\x80\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x00\x00\xCC\x55\x8B\xEC\x51\x89\x4D\x00\x8B\x4D\x00","xx????xxxx??xxxxxxx?xx?");
DWORD dwScore         = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8D\x84\x81\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x00\x00\x55\x8B\xEC\x51\x89\x4D\x00","xxx????xxxx??xxxxxx?");
DWORD dwQuick         = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x89\x81\x00\x00\x00\x00\x8B\x55\x00\x83\xBA\x00\x00\x00\x00\x00\x75\x00\x6A\x00\x68\x00\x00\x00\x00\x68\x00\x00\x00\x00\x6A\x00", "xx????xx?xx?????x?x?x????x????x?");
DWORD dwUnyuk         = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\xBE\x43\x47\x61\x6D\x65\x43\x68\x61\x72\x61\x43\x6F\x6C\x6C\x69\x73\x69\x6F\x6E\x43\x6F\x6E\x74\x65\x78\x74\x00\x00","xxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
DWORD dwDeathFly      = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x47\x72\x61\x76\x69\x74\x79\x00","xxxxxxxx");
DWORD dwFloodKick     = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x33\xC5\x89\x45\x00\x56\x50\x8D\x45\x00\x64\x00\x00\x00\x00\x00\x89\x8D\x00\x00\x00\x00\x8D\x8D\x00\x00\x00\x00\xFF\x15\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00","xxxx?xxxx?x?????xx????xx????xx????xx?????");
DWORD dwSuicide       = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x00\x89\x4D\x00\x51\xD9\xE8","xxxxx?xx?xxx");
DWORD dwWallShot      = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x75\x00\xC7\x45\x00\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\x8D\x4D\x00\xFF\x15\x00\x00\x00\x00\x8B\x45\x00","x?xx?????xx?????xx?xx????xx?");
DWORD dwInvincible    = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x6F\x12\x83\x3C","xxxx");
DWORD dwHook          = FindPattern(dwi3GfxDx,i3GfxDx,(PBYTE)"\x8B\x80\x00\x00\x00\x00\x8B\x08\x8D\x54\x24\x00\x52\x50\x8B\x41\x00\xFF\xD0","xx????xxxxx?xxxx?xx");
DWORD dwWTF           = FindPattern(dwNxChara,i3NxChara,(PBYTE)"\x5E\x00\xD9\x46\x00\xD9\x44\x24\x00\xD9\xC0\xDE\xC2\xD9\xC9\xD9\x5E\x00\xD9\x46\x00\xD8\xC3\xD9\x5E\x00\xD9\x46\x00\xD8\xC2\xD9\x5E\x00\xD9\x46\x00","x?xx?xxx?xxxxxxxx?xx?xxxx?xx?xxxx?xx?");
DWORD dwUser	      = FindPattern(dwPBExe, i3PBExe,(PBYTE)"\xC6\x81\x00\x00\x00\x00\x00\x8B\x55\xFC\x69\xD2\x00\x00\x00\x00\x8B\x45\xF8", "xx???xxxxxxx????xxx");
DWORD GameEventFire     = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x28\x56\x89\x4D\xD8\x83","xxxxxxxxxxx");
DWORD CamPosition       = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x53\x8B\xDC\x83\xEC\x08\x83\xE4\xF0\x83\xC4\x04\x55\x8B\x6B\x04\x89\x6C\x24\x04\x8B\xEC\x81\xEC\xA0\x00\x00\x00\x89\x4D\xFC\x83\x3D","xxxxxxxxxxxxxxxxxxxxxxxxx???xxxxx");
DWORD DoLineCollision   = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x0C\x89\x4D\xF4\xC6\x45\xFF\x00\x83\x7D\x08\x00\x75","xxxxxxxxxxx??xxx?x");
DWORD dwTeam			= FindPattern(dwPBExe, i3PBExe, (PBYTE)"\x55\x8B\xEC\x51\x89\x4D\xFC\x8B\x45\xFC\x8B\x88\x00\x00\x00\x00\x51\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\xC8\xE8\x00\x00\x00\x00\x8B\xE5\x5D\xC3", "xxxxxxxxxxxx????xxx????x????xxx????xxxx");
DWORD dwPlayer			= FindPattern(dwPBExe, i3PBExe, (PBYTE)"\x83\xC4\x14\x8B\x4D\xF4\x8B\x55\xF0\x89\x84\x8A\x00\x00\x00\x00"	,"xxxxxxxxxxxx????");
DWORD FakeReplac      = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x30\x89\x4D\xD0\x83\x7D\x08\x00\x74","xxxxxxxxxxxx?x");
DWORD AmmoStatus	  = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B\x45\xFC\x8B\x4D\x08\x89\x88\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D","xx????xxxxxxxxxxx??xxxxxxxxxxxxxx");
DWORD ci3AmmoStatus		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B\x45\xFC\x8B\x4D\x08\x89\x88\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D","xx????xxxxxxxxxxx??xxxxxxxxxxxxxx");
DWORD gi3AmmoStatus		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B\x45\xFC\x8B\x4D\x08\x89\x88\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D","xx????xxxxxxxxxxx??xxxxxxxxxxxxxx");
DWORD DwAmmoStatus1		= FindPattern(gi3AmmoStatus+1,i3PBExe,(PBYTE)"\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B\x45\xFC\x8B\x4D\x08\x89\x88\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D","xx????xxxxxxxxxxx??xxxxxxxxxxxxxx");
DWORD DwAmmoStatus2		= FindPattern(DwAmmoStatus1+1,i3PBExe,(PBYTE)"\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B\x45\xFC\x8B\x4D\x08\x89\x88\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D","xx????xxxxxxxxxxx??xxxxxxxxxxxxxx");
DWORD DwAmmoStatus3		= FindPattern(DwAmmoStatus2+1,i3PBExe,(PBYTE)"\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B\x45\xFC\x8B\x4D\x08\x89\x88\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D","xx????xxxxxxxxxxx??xxxxxxxxxxxxxx");
DWORD DwSetEvent		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\xE8\x00\x00\x00\x00\xA1\x00\x00\x00\x00\x33\xC5\x89\x45\x00\x56\x50\x8D\x45","x????x????xxxx?xxxx");
DWORD BugHover1			= FindPattern(dwNxChara,0x7FFFFFFF,(PBYTE)"\x1C\x01\x00\x00\x8B\x4E\x18","xx??xxx");
DWORD BugHover2			= FindPattern(dwNxChara,0x7FFFFFFF,(PBYTE)"\x1C\x01\x00\x00\x8B\x51","xx??xx");
DWORD BugHover3			= FindPattern(dwNxChara,0x7FFFFFFF,(PBYTE)"\x04\x89\x90\x14","xxxx");
DWORD BugHover4			= FindPattern(dwNxChara,0x7FFFFFFF,(PBYTE)"\x0C\x89\x90\x1C","xxxx");
DWORD BugHover5			= FindPattern(dwNxChara,0x7FFFFFFF,(PBYTE)"\x14\x89\x90\x24","xxxx");
DWORD i3UpdateNickOnTarget = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x83\xB8\x00\x00\x00\x00\x00\x0F\x84\x00\x00\x00\x00\x8B\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x8B","xx????xxx????x???????????????x?????????x");

//--------------------------------------------------------------------
void NNCZUpdater(){
//--------------------------------------------------------------------
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwBaseAddress + 0x2), &ResultBaseAddress, sizeof(ResultBaseAddress), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwBullet + 0xC ), &ResultBullet, sizeof(ResultBaseBullet), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwMajor + 0x2), &ResultMajor, sizeof(ResultMajor), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwSkill + 0x4), &OFSSkill, sizeof(OFSSkill), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwHelmed + 0x3), &OFSHelmed, sizeof(OFSHelmed), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwPrimary + 0x2), &OFSReplace, sizeof(OFSReplace), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwKill + 0x3), &ResultKill, sizeof(ResultKill), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwPing + 0x2), &ResultPing, sizeof(ResultPing), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwScore + 0x3), &ResultScore, sizeof(ResultScore), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwQuick + 0x2), &ResultQuick, sizeof(ResultQuick), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwHook + 0x2), &ResultHook, sizeof(ResultHook), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwUser+0x2), &ResultUserDeath, sizeof(ResultUserDeath), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwTeam+0xC), &ResultTeam, sizeof(ResultTeam), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwPlayer+0xC)	,&ResultPlayer,sizeof(ResultPlayer)		,NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwAmmoStatus1+0x11),&ResultPTRAmmoA, sizeof(ResultPTRAmmoA), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwAmmoStatus2+0x11),&ResultPTRAmmoB, sizeof(ResultPTRAmmoB), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwAmmoStatus3+0x11),&ResultPTRAmmoC, sizeof(ResultPTRAmmoC), NULL);
//--------------------------------------------------------------------
ResultBasePlayer      = ResultBaseAddress - dwPBExe;
ResultBasePlayer2     = ResultBaseAddress;
ResultBaseHealth      = ResultBaseAddress - dwPBExe - 0x34;
ResultBaseHealth2     = ResultBaseAddress - 0x34;
ResultBaseAmmo        = ResultBaseAddress - dwPBExe - 0x38;
ResultBaseAmmo2       = ResultBaseAddress - 0x38;
ResultUserDeath       = ResultUserDeath;
ResultBaseBullet      = ResultBullet -dwPBExe;
ResultPTRAmmo         = ResultQuick + 0x4;
ResultNorecoil        = ResultQuick + 0x18;
ResultSkill2          = OFSSkill;
ResultSkill           = ResultSkill2 - 0x1;//
ResultRespawn         = ResultSkill2 + 0x1;
OFS_Team			  = ResultTeam;
ResultRespawn2        = ResultTeam - 0x19B0;
ResultHeadGear        = OFSHelmed + 0x8;
ResultBaret           = OFSHelmed + 0xC;
ResultPrimary         = OFSReplace + 0x5A0;
ResultMelee           = ResultPrimary + 0x8;
ResultBomb            = ResultPrimary + 0xC;
ResultSmoke           = ResultPrimary + 0x10;
ResultBugWeapon       = dwUnyuk - dwPBExe;
ResultDeathFly        = dwDeathFly - dwPBExe;
ResultWallShot        = dwWallShot - dwPBExe;
ResultInvincible      = dwInvincible - dwPBExe;
ResultSuicide         = dwSuicide - dwPBExe;
PTR_Player			  = ResultPlayer;
WTF                   = dwWTF - dwNxChara - 0x1000;
WTW                   = WTF ;
ResultBaseMove			= ResultBasePlayer - 0x28;
ResultBaseMove2		= ResultBasePlayer2 - 0x28;
	NeoPTRAmmoA				= ResultPTRAmmoA;
	NeoPTRAmmoB				= ResultPTRAmmoB;
	NeoPTRAmmoC				= ResultPTRAmmoC - 0x4;
	NeoPTRAmmoD				= ResultPTRAmmoC;
	NeoPTRProtectA			= NeoPTRAmmoC + 0x8;
	NeoPTRProtectB			= NeoPTRAmmoC + 0x10;
	NeoPTRProtectC			= NeoPTRAmmoC + 0x24;
	NeoPTRProtectD			= NeoPTRAmmoC + 0x68;
	NeoAmmoL				=DwAmmoStatus1;
    BackAmmoL				=DwAmmoStatus1+0x1B;
	NeoAmmoR				=DwAmmoStatus2;
	BackAmmoR				=DwAmmoStatus2+0x1B;
	NeoAmmoX				=DwAmmoStatus3;
	BackAmmoX				=DwAmmoStatus3+0x1B;
	ResultPRIMARYSIZE		= 0x1C;
	ResultSECONDARYSIZE		= 0x20;
	ResultMALESIZE			= 0x24;
	ResultBOMBSIZE			= 0x28;
	ResultSMOKESIZE			= 0x2C;
	ResultSetEvent			= DwSetEvent - 0x16;
	ResultBugHover1			= BugHover1	- dwNxChara;
	ResultBugHover2			= BugHover2 - dwNxChara;
	ResultBugHover3			= BugHover3 - dwNxChara;
	ResultBugHover4			= BugHover4 - dwNxChara;
	ResultBugHover5			= BugHover5 - dwNxChara;
OFS_GameEventFire     = GameEventFire;
OFS_CamPosition       = CamPosition;
OFS_DoLineCollision   = DoLineCollision;
ResultFake            = FakeReplac;
ResultBaseRender      = HookBaseRender;
NeoUpdateNickOnTarget	=i3UpdateNickOnTarget;
RETNeoUpdateNickOnTarget=i3UpdateNickOnTarget+7;
////ini buat tes apakah logger masih benar belum ada yg geser
//Writelog("#define ResultBasePlayer			0x%X", ResultBasePlayer);
//Writelog("#define ResultBasePlayer2			0x%X", ResultBasePlayer2);
//Writelog("#define ResultBaseHealth			0x%X", ResultBaseHealth);
//Writelog("#define ResultBaseHealth			0x%X", ResultBaseHealth2);
//Writelog("#define ResultBaseAmmo			0x%X", ResultBaseAmmo);
//Writelog("#define ResultBaseAmmo			0x%X", ResultBaseAmmo2);
//Writelog("#define ResultUserDeath			0x%X", ResultUserDeath);
//Writelog("#define ResultBaseBullet			0x%X", ResultBaseBullet);
//Writelog("#define ResultSmoke			0x%X", ResultSmoke);
//Writelog("#define ResultRespawn			0x%X", ResultRespawn);
//Writelog("#define ResultRespawn2			0x%X", ResultRespawn2);
//Writelog("#define ResultPrimary			0x%X", ResultPrimary);
//Writelog("#define ResultBugWeapon			0x%X", ResultBugWeapon);
//Writelog("#define ResultWallShot			0x%X", ResultWallShot);
//Writelog("#define ResultSuicide			0x%X", ResultSuicide);
//Writelog("#define ResultInvincible			0x%X", ResultInvincible);
//Writelog("#define WTW			0x%X", WTW);
//Writelog("#define OFS_Team			0x%X", OFS_Team);
//Writelog("#define PTR_Player			0x%X", PTR_Player);
//Writelog("#define ResultHook			0x%X", ResultHook);
//Writelog("#define ResultBaseRender			0x%X", ResultBaseRender);
//
//ExitProcess(0);
}
#define PTR_QuickChange      0x540
#define PTR_BaseAmmo        (PTR_QuickChange + 0x4)
#define PTR_CAMPOS          (PTR_QuickChange + 0x14)
#define g_pPlayerBase			0x7BEF80  	
#define OFS_TEAM		              0x299F4
//#define PTR_Player			0x27B24
#define PTR_GHOST		    0x260
#define PTR_HEALTH		    0x264
#define ALIVESIZE			0x24
#define NAMESIZE			0x21
#define WEAPSIZE			0x158
#define OFFSET_MAGNET       0xADD8D
#define c_pPelorReload		0xBBEF48  	
//--------------------------------------------------------------------
#define OFS_Magnet			0xADD8D
//------------------------[BUG]-------------------------------------
#define OFS_StageInfo		0x3B9A8
#define PTR_PlantBomb		0x230
#define PTR_FloorBomb		0x248
#define OFS_TEAM		    0x299F4
#define OFS_PLAYER		    0x27B24
#define PTR_FallDamage   		0x510
#define PTR_JumpHigh		0x548
#define	BASE_IDLE2		 (BASE_PLAYER2-0x8)
#define BASE_PLAYER2	 0xBD4820
#define ResultPTRIdle		0x1C3
#define ResultPTRIdle2		0x1C7
#define OFS_WallBug        0x16510	 
#define OFS_Ammo2		0xBD47E8
#define WriteGameEvent_fire				0x8F2980 
#define P_BaseTEAM		              0x299F4 // OFS_Team
#define OFS_Melee			0x28180
#define OFS_PRIMARY		 (OFS_SETNETCHARA+0x134) // anjir :v serem main + aja :v 
#define OFS_SECONDARY    (OFS_PRIMARY+0x4)
#define OFS_Primary		0x28178
#define OFS_Secondary		0x2817C
#define OFS_SETNETCHARA  0x28044
#define WEAPONSIZE		 0x158
#define OFS_MALE		 (OFS_SECONDARY+0x4)
#define BASE_HEALTH2	 (BASE_PLAYER2-0x34)
#define CALL_SETWEAPON	 0x537270 
#define OFS_Special			0x28188