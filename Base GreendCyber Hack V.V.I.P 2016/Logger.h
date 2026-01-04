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
if(infile)
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
DWORD NxCharakter2 = (DWORD)LoadLibraryA("NxCharacter.2.8.1.dll");
DWORD i3NxChara       = GetSizeofCode("NxCharacter.2.8.1.dll");
//--------------------------------------------------------------------
DWORD ModulePBGI	    = (DWORD)GetModuleHandleA("PointBlank.exe");;
DWORD ModuleSizePB      = GetSizeofCode("PointBlank.exe");
 DWORD ModuleDX		= (DWORD)GetModuleHandle("i3BaseDx_Cli.dll");
DWORD ModuleSizeDX	= GetSizeofCode("i3BaseDx_Cli.dll"); 
#define Pattern_Weapon3						"\x74\x0A\xE8\x27\x00\x00\x00\xA1"
#define Mask_Weapon3						"xxxx???x"
#define Pattern_Weapon4						"\x74\x0A\xE8\xE3\x00\x00\x00\xA1"
#define Mask_Weapon4						"xxxx???x"
#define Pattern_Weapon5						"\x74\x31\x8B\x00\x00\x00\xC7\x08"
#define Mask_Weapon5						"xxx???xx"
#define Pattern_Weapon6						"\x74\x26\x8B\x00\x00\x00\xC7\x08"
#define Mask_Weapon6						"xxx???xx"
#define Pattern_QuickChange	 "\x55\x8B\xEC\x83\xEC\x00\x89\x4D\x00\x8B\x00\x00\xE8\x00\x00\x00\x00\x0F\xB6\x00\x85\x00\x75\x04\xD9\xEE\xEB\x00\x8B\x00\x00\xE8\x00\x00\x00\x00\x00\x00\xFF\x15\x00\x00\x00\x00\x85\xC0\x74\x00\x8B\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\x15\x00\x00\x00\x00\x8B\xC8\xFF\x15\x00\x00\x00\x00\xD9\x5D\x00\xEB\x0D\xF3\x0F\x10\x05\x00\x00\x00\x00\xF3\x0F\x11\x45\x00\xD9\x45\x00\x8B\xE5\x5D\xC3"
#define Mask_QuickChange	 "xxxxx?xx?x??x????xx?x?xxxxx?x??x??????xx????xxx?x?????????xx????xxxx????xx?xxxxxx????xxxx?xx?xxxx"

//--------------------------------------------------------------------
DWORD HookBaseRender	= (DWORD)GetProcAddress(hGfxDx, "?g_pRenderContext@@3PAVi3RenderContext@@A")- dwi3GfxDx;
DWORD dwBaseAddress   = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x89\x45\x00\x8B\x4D\x00\x8B\x11","xx????x????xx?xx?xx");
DWORD dwBullet        = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x51\x8B\x4D\x00\x81\xC1\x00\x00\x00\x00\xFF\x15\x00\x00\x00\x00\x8B\x55\x00\x8B\x8A\x00\x00\x00\x00\xE8","xxx?xx????xx????xx?xx????x");
DWORD DwSetEvent		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\xE8\x00\x00\x00\x00\xA1\x00\x00\x00\x00\x33\xC5\x89\x45\x00\x56\x50\x8D\x45","x????x????xxxx?xxxx");
DWORD dwSkill         = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x0F\xB6\x94\x01\x00\x00\x00\x00","xxxx????");
DWORD dwHelmed        = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8D\x84\x10\x00\x00\x00\x00\xEB\x00\xEB\x00\x8B\x4D","xxx????x?x?xx");
DWORD dwKill          = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8D\x84\x81\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x00\x00\x55\x8B\xEC\x83\xEC","xxx????xxxx??xxxxx");
DWORD dwPing          = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8A\x80\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x00\x00\xCC\x55\x8B\xEC\x51\x89\x4D\x00\x8B\x4D\x00","xx????xxxx??xxxxxxx?xx?");
DWORD dwScore         = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8D\x84\x81\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x00\x00\x55\x8B\xEC\x51\x89\x4D\x00","xxx????xxxx??xxxxxx?");
DWORD dwQuick         = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x89\x81\x00\x00\x00\x00\x8B\x55\x00\x83\xBA\x00\x00\x00\x00\x00\x75\x00\x6A\x00\x68\x00\x00\x00\x00\x68\x00\x00\x00\x00\x6A\x00", "xx????xx?xx?????x?x?x????x????x?");
DWORD dwUnyuk         = FindPattern(dwPBExe,0xA00000,(PBYTE) "\xBE\x00\x00\x00\x00\x65\x43\x68","x????xxx");
DWORD dwHook          = FindPattern(dwi3GfxDx,i3GfxDx,(PBYTE)"\x8B\x80\x00\x00\x00\x00\x8B\x08\x8D\x54\x24\x00\x52\x50\x8B\x41\x00\xFF\xD0","xx????xxxxx?xxxx?xx");
DWORD dwWTF           = FindPattern(dwNxChara,i3NxChara,(PBYTE)"\x5E\x00\xD9\x46\x00\xD9\x44\x24\x00\xD9\xC0\xDE\xC2\xD9\xC9\xD9\x5E\x00\xD9\x46\x00\xD8\xC3\xD9\x5E\x00\xD9\x46\x00\xD8\xC2\xD9\x5E\x00\xD9\x46\x00","x?xx?xxx?xxxxxxxx?xx?xxxx?xx?xxxx?xx?");
DWORD dwUser	      = FindPattern(dwPBExe, i3PBExe,(PBYTE)"\xC6\x81\x00\x00\x00\x00\x00\x8B\x55\xFC\x69\xD2\x00\x00\x00\x00\x8B\x45\xF8", "xx???xxxxxxx????xxx");
DWORD dwCamPosition	  = FindPattern(dwPBExe, i3PBExe, (PBYTE)"\x61\x74\x29\x00\x6D\x5F\x70\x41\x6E\x69\x6D\x5B\x6D\x5F\x65\x52", "xxx?xxxxxxxxxxxx");
DWORD	 DwDoLine         = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x00\x89\x4D\xF4\xC6\x45\xFF\x00\x83\x7D\x00\x00\x75\x2A\x6A\x00","xxxxx?xxxxxx?xx??xxx?");
DWORD	 DwCamPos         = FindPattern(dwPBExe,i3PBExe,(PBYTE) "\x53\x8B\xDC\x83\xEC\x00\x83\xE4\x00\x83\xC4\x00\x55\x8B\x6B\x00\x89\x6C\x24\x00\x8B\xEC\x81\xEC\x00\x00\x00\x00\x89\x4D\xFC\x83\x3D\x00\x00\x00\x00\x00\x75\x00","xxxxx?xx?xx?xxx?xxx?xxxx????xxxxx?????x?");
DWORD	 DwEventFire      = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x00\x56\x89\x4D\xD8\x83\x7D\x00\x00\x75\x00\x6A\x00","xxxxx?xxxxxx??x?x?");
DWORD dwTeam			= FindPattern(dwPBExe, i3PBExe, (PBYTE)"\x55\x8B\xEC\x51\x89\x4D\xFC\x8B\x45\xFC\x8B\x88\x00\x00\x00\x00\x51\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\xC8\xE8\x00\x00\x00\x00\x8B\xE5\x5D\xC3", "xxxxxxxxxxxx????xxx????x????xxx????xxxx");
DWORD DwPTRpTarget2	      = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x83\xF8\xFF\x0F\x00\x00\x00\x00\x00\x8B\x55\xA0\x8B\x8A","xxxx?????xxxxx");
DWORD dwPlayer			= FindPattern(dwPBExe, i3PBExe, (PBYTE)"\x83\xC4\x14\x8B\x4D\xF4\x8B\x55\xF0\x89\x84\x8A\x00\x00\x00\x00"	,"xxxxxxxxxxxx????");
DWORD dwName			= FindPattern(dwPBExe, i3PBExe, (PBYTE)"\x8B\x55\x08\x6B\xD2\x00\x8B\x45\xFC\x8D\x84\x10","xxxxx?xxxxxx");
DWORD dwGhost			= FindPattern(dwPBExe, i3PBExe, (PBYTE)"\x6B\xD2\x24\x8B\x45\xD0\x8D\x8C\x10\x00\x00\x00\x00\x89\x4D\xFC","xxxxxxxxx????xxx");
DWORD DwGetButton            = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x4D\xF0\xC7\x81\x00\x00\x00\x00\x00\x00\x00\x00\x8B\x4D\xF8\xFF\x15\x00\x00\x00\x00\x83\xE0\x01","xxxxx????????xxxxx????xxx");
DWORD dwInvincible    = FindPattern(dwPBExe,0xA00000 ,(PBYTE)"\x6F\x12\x83\x3C","xxxx");
DWORD	 DwSetNetChara    = FindPattern(dwPBExe,i3PBExe,(PBYTE) "\xFF\xD0\xEB\x00\x8B\xE5\x5D\xC2\x04\x00\xCC\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xCC\x55\x8B\xEC\x83\xEC\x00\x89\x4D\xD0\x83\x7D\x00\x00\x74\x00","xxx?xxxxx?x??????????xxxxxx?xxxxx??x?");
DWORD dwSuicide       = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x00\x89\x4D\x00\x51\xD9\xE8","xxxxx?xx?xxx");
DWORD dwPrimary       = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x88\x00\x00\x00\x00\x51\xFF\x15\x00\x00\x00\x00\x83\xC4\x00\x8B\x55\x00\xC7\x82\x00\x00\x00\x00\x00\x00\x00\x00\x5E\x8B\xE5\x5D\xC3","xx????xxx????xx?xx?xx????????xxxxx");
DWORD dwWallShot      = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x75\x00\xC7\x45\x00\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\x8D\x4D\x00\xFF\x15\x00\x00\x00\x00\x8B\x45\x00","x?xx?????xx?????xx?xx????xx?");
DWORD FakeReplac      = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x30\x89\x4D\xD0\x83\x7D\x08\x00\x74","xxxxxxxxxxxx?x");
DWORD DwPTRIdle		    = FindPattern(dwPBExe, i3PBExe,(PBYTE)"\x8B\xE5\x5D\xC2\x04\x00\xCC\x00\x00\x00\x00\xCC\x55\x8B\xEC\x51\x89\x4D\xFC\x8B\x45\xFC\x8B\x80","xxxxx?x????xxxxxxxxxxxxx");
DWORD DwPTRCaclAmmo		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x6A\x00\x8B\x4D\xE8\xE8\x00\x00\x00\x00\x8B\x55\xE8\xC7\x82","x?xxxx????xxxxx");
DWORD gi3Ammo	= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B\x45\xFC\x8B\x4D\x08\x89\x88\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D","xx????xxxxxxxxxxx??xxxxxxxxxxxxxx");
DWORD DwAmmo1		= FindPattern(gi3Ammo+1,i3PBExe,(PBYTE)"\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B\x45\xFC\x8B\x4D\x08\x89\x88\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D","xx????xxxxxxxxxxx??xxxxxxxxxxxxxx");
DWORD DwAmmo2		= FindPattern(DwAmmo1+1,i3PBExe,(PBYTE)"\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B\x45\xFC\x8B\x4D\x08\x89\x88\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D","xx????xxxxxxxxxxx??xxxxxxxxxxxxxx");
//DWORD DwAmmo3		= FindPattern(DwAmmo2+1,i3PBExe,(PBYTE)"\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B\x45\xFC\x8B\x4D\x08\x89\x88\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D","xx????xxxxxxxxxxx??xxxxxxxxxxxxxx");
DWORD BugHover1			= FindPattern(dwNxChara,0x7FFFFFFF,(PBYTE)"\x1C\x01\x00\x00\x8B\x4E\x18","xx??xxx");
DWORD BugHover2			= FindPattern(dwNxChara,0x7FFFFFFF,(PBYTE)"\x1C\x01\x00\x00\x8B\x51","xx??xx");
DWORD DwPlayerSpeed		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x00\x00\x00\x40\xE1\x7A\x84\x3F","xxxxxxxx");
DWORD i3Damage		  = FindPattern((DWORD)ModulePBGI,(DWORD)ModuleSizePB,(PBYTE)"\xD9\x45\xF0\x5E\x8B\xE5\x5D\xC2\x04","xxxxxxxxx");
DWORD FastPlantRID1		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x44\x61\x6D\x61\x67\x65\x00\x00\x00\x00\x00\x00","xxxxxx??????");
DWORD FastPlantRID2		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x00\x00\x80\x3F","??xx");
DWORD dwPTRRecoil	= FindPattern(dwPBExe, i3PBExe, (PBYTE)"\x8B\x80\x00\x00\x00\x00\x8B\xE5\x5D\xC3\xCC\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xCC\x00\x00\x00\x00\x00\x00\x00\x8B\x45\xFC\x05\x00\x00\x00\x00\x8B\xE5\x5D\xC3\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xCC\x55\x8B\xEC\x51\x89\x4D\xFC\x8B\x45\xFC\x05\x00\x00\x00\x00\x8B\xE5\x5D\xC3\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xCC\x55\x8B\xEC\x51\x89\x4D\xFC\x8B\x45\xFC\x8B\x80", "xx????xxxxx??????????x???????xxxx????xxxx????????????xxxxxxxxxxxx????xxxx????????????xxxxxxxxxxxxx");
DWORD BypassWeapon3		= FindPattern(ModuleDX,ModuleSizeDX,(PBYTE)Pattern_Weapon3,Mask_Weapon3) - ModuleDX;
DWORD BypassWeapon4		= FindPattern(ModuleDX,ModuleSizeDX,(PBYTE)Pattern_Weapon4,Mask_Weapon4) - ModuleDX;							
DWORD BypassWeapon5		= FindPattern(ModuleDX,ModuleSizeDX,(PBYTE)Pattern_Weapon5,Mask_Weapon5) - ModuleDX;
DWORD BypassWeapon6		= FindPattern(ModuleDX,ModuleSizeDX,(PBYTE)Pattern_Weapon6,Mask_Weapon6) - ModuleDX;
DWORD i3QuickChange  = FindPattern(ModulePBGI+1 ,ModuleSizePB ,(PBYTE)Pattern_QuickChange ,Mask_QuickChange);
//DWORD i3NoReload	      = FindPattern((DWORD)ModulePB ,(DWORD)ModuleSizePB*2,(PBYTE)Pattern_NoReload ,Mask_NoReload);
//DWORD xi3QuickChange = FindPattern(ModulePB ,ModuleSizePB ,(PBYTE)Pattern_QuickChange ,Mask_QuickChange);

//--------------------------------------------------------------------
DWORD OFSSkill, OFSHelmed, OFSReplace, WTF, WTW, ResultSmoke, OFSBullet, ResultBomb, ResultQuick, ResultPTRAmmo,ResultNorecoil,ResultPTRCaclKnife,ResultPTRCaclAmmo;
DWORD ResultHook, ResultBaseAddress, ResultKill, ResultPing, ResultScore, ResultBaseBullet,ResultBullet,ResultRafid,ResultRafid2,ResultRANKSIZE,ResultNAMESIZE;
DWORD ResultSkill, ResultSkill2, ResultRespawn, ResultMajor, ResultBugWeapon, ResultSuicide,ResultUserDeath,PlantRID1,PlantRID2;
DWORD ResultBaseHealth, ResultBaseHealth2, ResultBasePlayer, ResultBasePlayer2, ResultBaseAmmo, ResultBaseAmmo2;
DWORD ResultDoLine,ResultCamPos ,ResultEventFire,ResultSetNetChara,ResultTeam,PTR_Target,ResultPTRTarget,ResultRespawn2,ResultPlayer;
DWORD ResultName,ResultGHOST,ResultHealth,ResultGetButton,ResultInvincible,ResultPrimary,ResultSecondary,ResultMelee,ResultWallShot;
DWORD PTR_Idle,PTR_Idle2,ResultPTRIdle,ResultSetEvent,ResultPlayerSpeed,ResultBugHover1,ResultBugHover2;
DWORD AmmoHK691,AmmoHK692,AmmoHK693,AmmoHK694,AmmoHK695,AmmoHK696,PTRAmmoA,PTRAmmoB,PTRAmmoC,PTRAmmoD,PTRProtectA,PTRProtectB,PTRProtectC,PTRProtectD;
DWORD AmmoRPG1,AmmoRPG2,AmmoRPG3,AmmoRPG4,AmmoRPG5,AmmoRPG6,AmmoPrymariFC,AmmoSMOKE,AmmoBOMB,ResultBOMBSIZE,ResultPTRAmmoA,ResultPTRAmmoB,ResultPTRAmmoC;
DWORD AmmoBOMB1,AmmoBOMB2,AmmoBOMB3,AmmoBOMB4,AmmoBOMB5,AmmoBOMB6;
DWORD PisoGila,bOMGila1,bOMGila2,bOMGila3,bOMGila4,bOMGila5,bOMGila6,bOMGila7,bOMGila8,bOMGila9,bOMGila10,bOMGila11,bOMGila12,Ghoster;
DWORD SmokeGila1,SmokeGila2,SmokeGila3,SmokeGila4,SmokeGila5,SmokeGila6;
DWORD PisauGila1,PisauGila2,PisauGila3,PisauGila4,PisauGila5,PisauGila6;
DWORD AmmoGila1,AmmoGila2,AmmoGila3,AmmoGila4,AmmoGila5,AmmoGila6,RETNeoDamage;
DWORD D3D, adr, *vtbl,PTR_BaseAmmo,ResultPTR,PTR_NoRecoil,Resultpesoedan,ResultQuickconge;
//--------------------------------------------------------------------

//------------------------------------------------------------------------------
#define NAMESIZE    0x21
#define RANKSIZE    0x2B
#define HPSIZE      0x24
#define IDSIZE      0x01

#define Bom_biru				0x35E20D74
#define OFS_Soccer				0x35E20D79
#define Candy_Granade			0x35E20D6C
#define Lantern_Grenade			0x35E20D6F
#define Decoy_Bomb				0x35E20D72
#define Bread_Grenade			0x35E20D70
#define WP_Smoke				0x35E20D64
#define WP_SmokeD				0x35E20D5D

#define OFS_BugHover1 0x1643F 
#define OFS_BugHover2 0x191CF 
#define OFS_BugHover3 0x191BA 
#define OFS_BugHover4 0x191CC 
#define OFS_BugHover5 0x191DE

#define OFS_Longknife 0x59981D  // 0x59927D + 0x5A0
//#define OFS_BugHover5 0x191DE
//#define OFS_BugHover5 0x191DE








