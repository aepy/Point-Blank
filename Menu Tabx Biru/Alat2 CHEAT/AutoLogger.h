/*AutoLogger.h D3D9 PBHacks Last Edit By Fatur Rezo*/
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

/*-------------------------------------------------------------------------------------------------------------------*/
#pragma warning(disable:4244)
#pragma warning(disable:4700)
#pragma warning(disable:4996)
#pragma warning(disable:4305)
using namespace std;
ofstream infile;
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
bool ChekLogPortal = false;
bool CHekHook=false;

/*------------------------------------------- Declaration Function ------------------------------------------------------*/
	/*------------------*/
	bool bReload		= false;
	bool bPiso			= false;
	bool ReadAmmoo		= false;
	bool bAmmo			= false;
	bool bGhost			= false;
	bool XRPG			= false;
	bool XHK69			= false;
	bool XFC			= false;
	bool XSMOKE			= false;
	bool XBOMB			= false;
	/*------------------*/
	DWORD PisoGila,Ghoster;
	DWORD Px,Py,Pz;
	DWORD WeaponMode;
	DWORD AmmoRPG1;
	DWORD AmmoRPG2;
	DWORD AmmoRPG3;
	DWORD AmmoRPG4;
	DWORD AmmoRPG5;
	DWORD AmmoRPG6;
	DWORD AmmoHK691;
	DWORD AmmoHK692;
	DWORD AmmoHK693;
	DWORD AmmoHK694;
	DWORD AmmoHK695;
	DWORD AmmoHK696;
	DWORD AmmoPrymariFC;
	DWORD AmmoPrymariFC2;
	DWORD AmmoPrymariFCProt1;
	DWORD AmmoPrymariFCProt2;
	DWORD AmmoPrymariFCProt3;
	DWORD AmmoPrymariFCProt4;
	DWORD AmmoSMOKE;
	DWORD AmmoBOMB;

/*-------------------------------------------------------------------------------------------------------------------*/
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

char *GetDirectoryFile(char *filename){
	static char path[320];
	strcpy(path, dlldir);
	strcat(path, filename);
	return path;
}

bool CheckWindowsVersion(DWORD dwMajorVersion,DWORD dwMinorVersion,DWORD dwProductType)
{
    OSVERSIONINFOEX VersionInfo;
    ZeroMemory(&VersionInfo,sizeof(OSVERSIONINFOEX));
    VersionInfo.dwOSVersionInfoSize = sizeof(VersionInfo);
    GetVersionEx((OSVERSIONINFO*)&VersionInfo);
        if ( VersionInfo.dwMajorVersion == dwMajorVersion )
        {
                if ( VersionInfo.dwMinorVersion == dwMinorVersion )
                {
                        if ( VersionInfo.wProductType == dwProductType )
                        {
                                return ( TRUE );
                        }
                }
        }
        return ( FALSE );
}

void __cdecl Writelog (const char *fmt, ...){
	if(infile != NULL){
		if(!fmt) { return; }
		va_list va_alist;
		char logbuf[256] = {0};
		va_start (va_alist, fmt);
		_vsnprintf (logbuf+strlen(logbuf), sizeof(logbuf) - strlen(logbuf), fmt, va_alist);
		va_end (va_alist);
		infile << logbuf << endl;
	}
}

/*------------------------------------------- Declaration hModule ------------------------------------------------------*/
HMODULE hGfxDx		= LoadLibrary("i3GfxDx.dll");
DWORD dwFrameW		= (DWORD)GetModuleHandle("i3FrameworkDx.dll");
DWORD FrameW		= GetSizeofCode("i3FrameworkDx.dll");
DWORD dwi3GfxDx     = (DWORD)GetModuleHandleA("i3GfxDx.dll");
DWORD i3GfxDx       = GetSizeofCode("i3GfxDx.dll");
DWORD dwPBExe       = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD i3PBExe       = GetSizeofCode("PointBlank.exe");
DWORD dwNxChara     = (DWORD)GetModuleHandleA("NxCharacter.2.8.1.dll");
DWORD NxCharakter2	= (DWORD)LoadLibraryA("NxCharacter.2.8.1.dll");
DWORD i3NxChara     = GetSizeofCode("NxCharacter.2.8.1.dll");
DWORD ModuleD3D9	= (DWORD)GetModuleHandleA("d3d9.dll");
DWORD ModuleSizeD3D9= GetSizeofCode("d3d9.dll");
DWORD ModulePB      = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD ModuleSizePB  = GetSizeofCode("PointBlank.exe");

/*------------------------------------------- Declaration ArrayOFByte ------------------------------------------------------*/
#define HOOK_PAT_8			"\x8B\xFF\x55\x8B\xEC\xFF\x75\x08\x8B\x01\x6A\x3E\xFF\x90\xF4\x00"
#define HOOK_MAS_8			"xxxxxxxxxxxxxxx?"
#define HOOK_PAT_7			"\x8B\xFF\x55\x8B\xEC\x8B\x55\x08\x8B\x01\x8B\x80\xF4\x00\x00\x00\x52\x6A\x3E\xFF\xD0\x5D\xC2\x04\x00"
#define HOOK_MAS_7			"xxxxxxxxxxxxxxxxxxxxxxxxx"
#define Pattern_AmmoStatus	"\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B\x45\xFC\x8B\x4D\x08\x89\x88\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D"						
#define Mask_AmmoStatus		"xx????xxxxxxxxxxx??xxxxxxxxxxxxxx"
//--------------------------------------------------------------------------------------------------------------------------------//
#define Pattern_PTRgCharaRepleaceWeapon		"\x75\x17\x8B\x00\x08\x69\x00\x00\x00\x00\x00\x8B\x00\xFC\x8D\x84\x00\x00\x00\x00\x00\xEB\x2C\xEB\x15\x8B\x00\x08\x69\x00\x00\x00\x00\x00\x8B\x00\xFC\x8D\x84\x00\x00\x00\x00\x00\xEB\x15\xEB\x13\x8B\x00\x08\x69\x00\x00\x00\x00\x00\x8B\x00\xFC\x8D\x84\x00\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00"
#define Mask_PTRgCharaRepleaceWeapon		"xxx?xx?????x?xxx?????xxxxx?xx?????x?xxx?????xxxxx?xx?????x?xxx?????xxxxx?"
#define Pattern_UpdateNickOnTarget			"\x83\xB8\x00\x00\x00\x00\x00\x0F\x84\x00\x00\x00\x00\x8B\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x8B"							
#define Mask_UpdateNickOnTarget				"xx????xxx????x???????????????x?????????x"
/*------------------------------------------- Declaration DWORD ------------------------------------------------------*/
DWORD OFSSkill, OFSHelmed, OFSReplace, WTF, WTW, ResultSmoke, OFSBullet, ResultBomb, ResultHeadGear, ResultBaret, ResultQuick, ResultPTRAmmo, ResultPTRWeapon,ResultNorecoil, ResultPTRChara, ResultPTRJumper;
DWORD ResultHook, ResultBaseAddress, ResultKill, ResultPing, ResultScore,ResultBullet,ResultRafid,ResultRafid2;
DWORD ResultSkill, ResultSkill2, ResultRespawn, ResultMajor, ResultBugWeapon, ResultSuicide, ResultPlayerSpeed,ResultUserDeath;
DWORD ResultBaseHealth, ResultBaseHealth2, ResultBasePlayer, ResultBasePlayer2, ResultBaseAmmo, ResultBaseAmmo2;
DWORD ResultDoLine,ResultCamPos ,ResultEventFire, ResultDropWeapon, ResultThrowWeapon,ResultSetNetChara,ResultTeam,ResultRespawn2,ResultPlayer;
DWORD ResultName,ResultGHOST,ResultHealth, ResultPLAYER, ResultBONE, ResultSKILL,ResultGetButton,ResultInvincible, ResultPTRAddCharaDeath,ResultPTRCaclKnife, ResultPTRAddCharaHealth,ResultFireSpeed,RETNeoFireSpeed,ResultPrimary,ResultSecondary, ResultMelee,ResultWallShot;
DWORD PTR_Idle,ResultSetEvent,PTR_Idle2,ResultPTRIdle, ResultPTRpTarget, ResultPTRpTarget2, ResultPTRRecoil, ResultNames, ResultPTRCaclAmmo, ResultDeltaX, ResultDeltaY, ResultPTRVicible;
DWORD ResultBugHover1, ResultBugHover2, ResultBugHover3, ResultBugHover4, ResultBugHover5;
DWORD ResultPTRgCharaRepleaceWeapon,ResultPTRgCharaRepleaceSizeWeapon,ResultPTRgCharaRepleaceMaxSizeWeapon;
DWORD NeoPTRgetNetCharaInfo,NeoPTRgCharaWeapon,NeoPTRgCharaSeccondary,NeoPTRgCharaKnife,NeoPTRgCharaGranad,NeoPTRgCharaSmoke,NeoUpdateNickOnTarget,RETNeoUpdateNickOnTarget;
DWORD GetDevice__EndScene;
DWORD NeoEndRender;
DWORD NeoDrawIndexPrim;
DWORD NeoEndRenderTarget;
DWORD NeoDrawIndexPrimTarget;
DWORD EndRenderBCK;
DWORD DrawIndexPrimBCK;
DWORD ResultPRIMARYSIZE,ResultNetChara, ResultSECONDARYSIZE, ResultMALESIZE, ResultBOMBSIZE, ResultSMOKESIZE;
DWORD ResultPTRAmmoA, ResultPTRAmmoB, ResultPTRAmmoC, NeoPTRAmmoA, NeoPTRAmmoB, NeoPTRAmmoC, NeoPTRAmmoD, NeoPTRProtectA, NeoPTRProtectB, NeoPTRProtectC, NeoPTRProtectD,NeoAmmoL,BackAmmoL,NeoAmmoR,BackAmmoR,NeoAmmoX,BackAmmoX;

/*------------------------------------------- Declaration ArrayOFByte ------------------------------------------------------*/
DWORD i3EndRender		= (DWORD)GetProcAddress(hGfxDx, "?EndRender@i3RenderContext@@QAEXXZ")- dwi3GfxDx;
DWORD i3DrawIndexPrim	= (DWORD)GetProcAddress(hGfxDx, "?DrawIndexedPrim@i3RenderContext@@QAEPAVi3Shader@@PAV2@W4I3G_PRIMITIVE@@II@Z")- dwi3GfxDx;
DWORD HookBaseRender	= (DWORD)GetProcAddress(hGfxDx,"?g_pRenderContext@@3PAVi3RenderContext@@A")- dwi3GfxDx;
DWORD dwBaseAddress		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x89\x45\x00\x8B\x4D\x00\x8B\x11","xx????x????xx?xx?xx");
DWORD DwBullet			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x50\x8D\x8D\x14\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x8B\x4D\xEC\xE8\x00\x00\x00\x00\x0F\xB6\xC8\x85\xC9","xxxxxxxx?????xxxx????xxxxx");
DWORD dwSkill			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x0F\xB6\x94\x01\x00\x00\x00\x00","xxxx????");
DWORD DwSKILL			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8D\x84\x10\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xCC\x55\x8B\xEC\x51","xxx????xxxxx?????????????xxxxx");
DWORD dwHelmed			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8D\x84\x10\x00\x00\x00\x00\xEB\x00\xEB\x00\x8B\x4D","xxx????x?x?xx");
DWORD dwKill			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8D\x84\x81\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x00\x00\x55\x8B\xEC\x83\xEC","xxx????xxxx??xxxxx");
DWORD dwPing			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8A\x80\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x00\x00\xCC\x55\x8B\xEC\x51\x89\x4D\x00\x8B\x4D\x00","xx????xxxx??xxxxxxx?xx?");
DWORD dwScore			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8D\x84\x81\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x00\x00\x55\x8B\xEC\x51\x89\x4D\x00","xxx????xxxx??xxxxxx?");
DWORD dwQuick			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x89\x81\x00\x00\x00\x00\x8B\x55\x00\x83\xBA\x00\x00\x00\x00\x00\x75\x00\x6A\x00\x68\x00\x00\x00\x00\x68\x00\x00\x00\x00\x6A\x00", "xx????xx?xx?????x?x?x????x????x?");
DWORD dwUnyuk			= FindPattern(dwPBExe,0xA00000,(PBYTE) "\xBE\x00\x00\x00\x00\x65\x43\x68","x????xxx");
DWORD dwHook			= FindPattern(dwi3GfxDx,i3GfxDx,(PBYTE)"\x8B\x80\x00\x00\x00\x00\x8B\x08\x8D\x54\x24\x00\x52\x50\x8B\x41\x00\xFF\xD0","xx????xxxxx?xxxx?xx");
DWORD dwWTF				= FindPattern(dwNxChara,i3NxChara,(PBYTE)"\x5E\x00\xD9\x46\x00\xD9\x44\x24\x00\xD9\xC0\xDE\xC2\xD9\xC9\xD9\x5E\x00\xD9\x46\x00\xD8\xC3\xD9\x5E\x00\xD9\x46\x00\xD8\xC2\xD9\x5E\x00\xD9\x46\x00","x?xx?xxx?xxxxxxxx?xx?xxxx?xx?xxxx?xx?");
DWORD dwUser			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\xC6\x81\x00\x00\x00\x00\x00\x8B\x55\xFC\x69\xD2\x00\x00\x00\x00\x8B\x45\xF8", "xx???xxxxxxx????xxx");
DWORD dwCamPosition		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x61\x74\x29\x00\x6D\x5F\x70\x41\x6E\x69\x6D\x5B\x6D\x5F\x65\x52", "xxx?xxxxxxxxxxxx");
DWORD DwDoLine			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x00\x89\x4D\xF4\xC6\x45\xFF\x00\x83\x7D\x00\x00\x75\x2A\x6A\x00","xxxxx?xxxxxx?xx??xxx?");
DWORD DwCamPos			= FindPattern(dwPBExe,i3PBExe,(PBYTE) "\x53\x8B\xDC\x83\xEC\x00\x83\xE4\x00\x83\xC4\x00\x55\x8B\x6B\x00\x89\x6C\x24\x00\x8B\xEC\x81\xEC\x00\x00\x00\x00\x89\x4D\xFC\x83\x3D\x00\x00\x00\x00\x00\x75\x00","xxxxx?xx?xx?xxx?xxx?xxxx????xxxxx?????x?");
DWORD DwEventFire		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x00\x56\x89\x4D\xD8\x83\x7D\x00\x00\x75\x00\x6A\x00","xxxxx?xxxxxx??x?x?");
DWORD dwTeam			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x51\x89\x4D\xFC\x8B\x45\xFC\x8B\x88\x00\x00\x00\x00\x51\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\xC8\xE8\x00\x00\x00\x00\x8B\xE5\x5D\xC3", "xxxxxxxxxxxx????xxx????x????xxx????xxxx");
DWORD dwPlayer			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x83\xC4\x14\x8B\x4D\xF4\x8B\x55\xF0\x89\x84\x8A\x00\x00\x00\x00"	,"xxxxxxxxxxxx????");
DWORD dwName			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x55\x08\x6B\xD2\x00\x8B\x45\xFC\x8D\x84\x10","xxxxx?xxxxxx");
DWORD dwGhost			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x6B\xD2\x24\x8B\x45\xD0\x8D\x8C\x10\x00\x00\x00\x00\x89\x4D\xFC","xxxxxxxxx????xxx");
DWORD DwGetButton       = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x4D\xF0\xC7\x81\x00\x00\x00\x00\x00\x00\x00\x00\x8B\x4D\xF8\xFF\x15\x00\x00\x00\x00\x83\xE0\x01","xxxxx????????xxxxx????xxx");
DWORD dwInvincible		= FindPattern(dwPBExe,i3PBExe ,(PBYTE)"\x6F\x12\x83\x3C","xxxx");
DWORD DwSetNetChara		= FindPattern(dwPBExe,i3PBExe,(PBYTE) "\xFF\xD0\xEB\x00\x8B\xE5\x5D\xC2\x04\x00\xCC\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xCC\x55\x8B\xEC\x83\xEC\x00\x89\x4D\xD0\x83\x7D\x00\x00\x74\x00","xxx?xxxxx?x??????????xxxxxx?xxxxx??x?");
DWORD dwSuicide			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x00\x89\x4D\x00\x51\xD9\xE8","xxxxx?xx?xxx");
DWORD dwPrimary			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x88\x00\x00\x00\x00\x51\xFF\x15\x00\x00\x00\x00\x83\xC4\x00\x8B\x55\x00\xC7\x82\x00\x00\x00\x00\x00\x00\x00\x00\x5E\x8B\xE5\x5D\xC3","xx????xxx????xx?xx?xx????????xxxxx");
DWORD dwWallShot		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x75\x00\xC7\x45\x00\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\x8D\x4D\x00\xFF\x15\x00\x00\x00\x00\x8B\x45\x00","x?xx?????xx?????xx?xx????xx?");
DWORD FakeReplac		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x30\x89\x4D\xD0\x83\x7D\x08\x00\x74","xxxxxxxxxxxx?x");
DWORD DwPTRIdle		    = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\xE5\x5D\xC2\x04\x00\xCC\x00\x00\x00\x00\xCC\x55\x8B\xEC\x51\x89\x4D\xFC\x8B\x45\xFC\x8B\x80","xxxxx?x????xxxxxxxxxxxxx");
DWORD DwPTRpTarget2		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x83\xF8\xFF\x0F\x00\x00\x00\x00\x00\x8B\x55\xA0\x8B\x8A","xxxx?????xxxxx");
DWORD DwPTRRecoil		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x80\x00\x00\x00\x00\x8B\xE5\x5D\xC3\xCC\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xCC\x00\x00\x00\x00\x00\x00\x00\x8B\x45\xFC\x05\x00\x00\x00\x00\x8B\xE5\x5D\xC3\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xCC\x55\x8B\xEC\x51\x89\x4D\xFC\x8B\x45\xFC\x05\x00\x00\x00\x00\x8B\xE5\x5D\xC3\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xCC\x55\x8B\xEC\x51\x89\x4D\xFC\x8B\x45\xFC\x8B\x80","xx????xxxxx??????????x???????xxxx????xxxx????????????xxxxxxxxxxxx????xxxx????????????xxxxxxxxxxxxx");
DWORD DwSetEvent		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\xE8\x00\x00\x00\x00\xA1\x00\x00\x00\x00\x33\xC5\x89\x45\x00\x56\x50\x8D\x45","x????x????xxxx?xxxx");
DWORD DwPlayerSpeed		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x00\x00\x00\x40\xE1\x7A\x84\x3F","xxxxxxxx");
DWORD DwPTRVicible		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x45\x08\x8B\x4D\xDC\xC7\x84\x81\x00\x00\x00\x00\x03\x00\x00\x00\x8B\x4D\xF8","xxxxxxxxx????xxxxxxx"	);
DWORD DwNames			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8D\x84\x10\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D\xFC\x8B\x45\xFC\x8B\x88","xxx????xxxxx?xxxxxxxxxxxx");
DWORD DwPTRCaclAmmo		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x6A\x00\x8B\x4D\xE8\xE8\x00\x00\x00\x00\x8B\x55\xE8\xC7\x82","x?xxxx????xxxxx");
DWORD DwDropWeapon		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x24\x89\x4D\xDC\xC7","xxxxxxxxxx");
DWORD DwThrowWeapon		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x48\x89\x4D\xB8\x8B\x0D","xxxxxxxxxxx");
DWORD DwFireSpeed		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\xD9\x45\xF8\x8B\xE5\x5D\xC3\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\x55\x8B\xEC\x83\xEC\x14\x89\x4D\x00\x8B\x45\x00\x8B\x88\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xD9\x5D\xFC","xxxxxxxxxxxxxxxxxxxxxxxxx?xx?xx????x????xxx");
DWORD BugHover1			= FindPattern(dwNxChara,0x7FFFFFFF,(PBYTE)"\x1C\x01\x00\x00\x8B\x4E\x18","xx??xxx");
DWORD BugHover2			= FindPattern(dwNxChara,0x7FFFFFFF,(PBYTE)"\x1C\x01\x00\x00\x8B\x51","xx??xx");
DWORD BugHover3			= FindPattern(dwNxChara,0x7FFFFFFF,(PBYTE)"\x04\x89\x90\x14","xxxx");
DWORD BugHover4			= FindPattern(dwNxChara,0x7FFFFFFF,(PBYTE)"\x0C\x89\x90\x1C","xxxx");
DWORD BugHover5			= FindPattern(dwNxChara,0x7FFFFFFF,(PBYTE)"\x14\x89\x90\x24","xxxx");
DWORD DwDeltaX			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x00\x89\x4D\xF8\x51\xD9\xEE\xD9\x1C\x24\x8B\x45\xF8\x8B\x88\x00\x00\x00\x00\xFF\x15\x00\x00\x00\x00\x51\xD9\x1C\x24","xxxxx?xxxxxxxxxxxxxx????xx????xxxx");
DWORD DwDeltaY			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x00\x89\x4D\xF8\x51\xD9\xEE\xD9\x1C\x24\x8B\x45\xF8\x8B\x88\x00\x00\x00\x00\xFF\x15\x00\x00\x00\x00\x51\xD9\x1C\x24","xxxxx?xxxxxxxxxxxxxx????xx????xxxx");
DWORD DwNetChara		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x69\xC0\x58\x01\x00\x00\x8B\x4D\xFC\x8D\x84\x01\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xCC\x55\x8B\xEC\x51\x89","xxxx??xxxxxx????xxxxx??????????xxxxxx");
DWORD ci3AmmoStatus		= FindPattern(dwPBExe,i3PBExe,(PBYTE)Pattern_AmmoStatus,Mask_AmmoStatus);
DWORD gi3AmmoStatus		= FindPattern(dwPBExe,i3PBExe,(PBYTE)Pattern_AmmoStatus,Mask_AmmoStatus);
DWORD DwAmmoStatus1		= FindPattern(gi3AmmoStatus+1,i3PBExe,(PBYTE)Pattern_AmmoStatus,Mask_AmmoStatus);
DWORD DwAmmoStatus2		= FindPattern(DwAmmoStatus1+1,i3PBExe,(PBYTE)Pattern_AmmoStatus,Mask_AmmoStatus);
DWORD DwAmmoStatus3		= FindPattern(DwAmmoStatus2+1,i3PBExe,(PBYTE)Pattern_AmmoStatus,Mask_AmmoStatus);
DWORD i3UpdateNickOnTarget	= FindPattern(dwPBExe,i3PBExe,(PBYTE)Pattern_UpdateNickOnTarget,Mask_UpdateNickOnTarget);

/*------------------------------------------- Declaration NewModulePB ------------------------------------------------------*/
DWORD FindPTRgCharaRepleaceWeapon   = FindPattern((DWORD)ModulePB						,(DWORD)ModuleSizePB*2		,(PBYTE)Pattern_PTRgCharaRepleaceWeapon			,Mask_PTRgCharaRepleaceWeapon);

/*------------------------------------------- Declaration Auto Logger ------------------------------------------------------*/
void SearchLogger(){
	
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwBaseAddress+0x2), &ResultBaseAddress, sizeof(ResultBaseAddress), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwBullet+0x9), &ResultBullet, sizeof(ResultBullet), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwSkill+0x4), &OFSSkill, sizeof(OFSSkill), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwSKILL+0x3), &ResultSKILL, sizeof(ResultSKILL), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwKill+0x3), &ResultKill, sizeof(ResultKill), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwPing+0x2), &ResultPing, sizeof(ResultPing), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwScore+0x3), &ResultScore, sizeof(ResultScore), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwQuick+0x2), &ResultQuick, sizeof(ResultQuick), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwHook+0x2), &ResultHook, sizeof(ResultHook), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwUser+0x2), &ResultUserDeath, sizeof(ResultUserDeath), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwTeam+0xC), &ResultTeam, sizeof(ResultTeam), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwPlayer+0xC), &ResultPlayer, sizeof(ResultPlayer), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwName+0xC), &ResultName, sizeof(ResultName), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwGhost+0x9), &ResultGHOST, sizeof(ResultGHOST), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwGetButton+0x12), &ResultGetButton, sizeof(ResultGetButton), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwPrimary + 0x2), &OFSReplace, sizeof(OFSReplace), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwPTRIdle+0x18), &ResultPTRIdle, sizeof(ResultPTRIdle), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwPTRpTarget2+0xE), &ResultPTRpTarget2, sizeof(ResultPTRpTarget2), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwPTRRecoil+0x2), &ResultPTRRecoil, sizeof(ResultPTRRecoil), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwPTRVicible+0x9), &ResultPTRVicible, sizeof(ResultPTRVicible), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwNames+0x3), &ResultNames, sizeof(ResultNames), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwPTRCaclAmmo+0xF), &ResultPTRCaclAmmo, sizeof(ResultPTRCaclAmmo), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwDeltaX+0x1A), &ResultDeltaX, sizeof(ResultDeltaX), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwDeltaY+0x3F), &ResultDeltaY, sizeof(ResultDeltaY), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwAmmoStatus1+0x11),&ResultPTRAmmoA, sizeof(ResultPTRAmmoA), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwAmmoStatus2+0x11),&ResultPTRAmmoB, sizeof(ResultPTRAmmoB), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwAmmoStatus3+0x11),&ResultPTRAmmoC, sizeof(ResultPTRAmmoC), NULL);
    ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwNetChara+0xC), &ResultNetChara, sizeof(ResultNetChara), NULL);
    ReadProcessMemory(GetCurrentProcess(),(LPCVOID)(FindPTRgCharaRepleaceWeapon+0x11),&ResultPTRgCharaRepleaceWeapon,sizeof(ResultPTRgCharaRepleaceWeapon),NULL);
	ReadProcessMemory(GetCurrentProcess(),(LPCVOID)(FindPTRgCharaRepleaceWeapon+0x7),&ResultPTRgCharaRepleaceSizeWeapon,sizeof(ResultPTRgCharaRepleaceSizeWeapon),NULL);
	ReadProcessMemory(GetCurrentProcess(),(LPCVOID)(FindPTRgCharaRepleaceWeapon+0x28),&ResultPTRgCharaRepleaceMaxSizeWeapon,sizeof(ResultPTRgCharaRepleaceMaxSizeWeapon),NULL);
	/*------------------------------------------- Declaration Hook New ------------------------------------------------------*/
	if (CheckWindowsVersion(6, 2, VER_NT_WORKSTATION)) // Windows 8 / 8.1
		GetDevice__EndScene = FindPattern((DWORD)ModuleD3D9, (DWORD)ModuleSizeD3D9,(PBYTE)HOOK_PAT_8,HOOK_MAS_8);
	else 
		if (CheckWindowsVersion(6, 0, VER_NT_WORKSTATION) || CheckWindowsVersion(6, 1, VER_NT_WORKSTATION)) // Windows 7 / Vista
			GetDevice__EndScene = FindPattern((DWORD)ModuleD3D9, (DWORD)ModuleSizeD3D9,(PBYTE)HOOK_PAT_7,HOOK_MAS_7);
	if(GetDevice__EndScene<(DWORD)ModuleD3D9)GetDevice__EndScene=0;

	/*------------------------------------------- Declaration Result ------------------------------------------------------*/
	ResultBasePlayer		= ResultBaseAddress - dwPBExe;
	ResultBasePlayer2		= ResultBaseAddress;
	ResultBaseHealth		= ResultBaseAddress - dwPBExe - 0x34;
	ResultBaseHealth2		= ResultBaseAddress - 0x34;
	ResultBaseAmmo			= ResultBaseAddress - dwPBExe - 0x38;
	ResultBaseAmmo2			= ResultBaseAddress - 0x38;
	ResultUserDeath			= ResultUserDeath;
	ResultPTRAmmo			= ResultQuick + 0x4;
	ResultPTRWeapon			= ResultQuick + 0x14;
	ResultNorecoil			= ResultQuick + 0x18;
	ResultPTRJumper			= ResultQuick + 0x18 - 0x4C;
	ResultPTRChara			= ResultQuick + 0x18 - 0x1C;
	ResultRespawn2			= ResultTeam - 0x19B0;
	ResultSkill2			= OFSSkill;
	ResultSkill				= ResultSkill2 - 0x1;
	PTR_Idle				= ResultPTRIdle - 0x1;
	PTR_Idle2				= ResultPTRIdle + 0x4;
	ResultRespawn			= ResultSkill2 + 0x1;
	ResultPrimary			= OFSReplace + 0x5A0;
	ResultRafid				= ResultNorecoil - 0x7C;
	ResultRafid2			= ResultNorecoil - 0x54;
	ResultPTRpTarget		= ResultPTRRecoil + 0x8;
	ResultMelee				= ResultPrimary + 0x8;
	ResultSecondary			= ResultPrimary + 0x4;
	ResultBomb	            = ResultPrimary + 0xC;
	ResultSmoke				= ResultPrimary + 0x10;
	ResultHeadGear			= ResultPrimary - 0x12C;
	ResultBaret				= ResultPrimary - 0x128;
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
	ResultSetEvent			= DwSetEvent - 0x16;
	ResultInvincible		= dwInvincible - dwPBExe;
	ResultPTRCaclKnife	    = ResultPTRCaclAmmo - 0xC;
	ResultPTRAddCharaDeath	= ResultPTRVicible + 0x40;
	ResultPTRAddCharaHealth	= ResultPTRVicible + 0x44;
	NeoPTRgetNetCharaInfo	=ResultPTRgCharaRepleaceWeapon;
	NeoPTRgCharaWeapon		=ResultPTRgCharaRepleaceWeapon-0x24+ResultPTRgCharaRepleaceSizeWeapon;
	NeoPTRgCharaSeccondary	=ResultPTRgCharaRepleaceWeapon-0x20+ResultPTRgCharaRepleaceSizeWeapon;
	NeoPTRgCharaKnife		=ResultPTRgCharaRepleaceWeapon-0x1C+ResultPTRgCharaRepleaceSizeWeapon;
	NeoPTRgCharaGranad		=ResultPTRgCharaRepleaceWeapon-0x18+ResultPTRgCharaRepleaceSizeWeapon;
	NeoPTRgCharaSmoke		=ResultPTRgCharaRepleaceWeapon-0x14+ResultPTRgCharaRepleaceSizeWeapon;
	NeoUpdateNickOnTarget	=i3UpdateNickOnTarget;
	RETNeoUpdateNickOnTarget=i3UpdateNickOnTarget+7;
	ResultFireSpeed			= DwFireSpeed;
	RETNeoFireSpeed			= DwFireSpeed + 5;
	ResultWallShot			= dwWallShot - dwPBExe;
	ResultSuicide			= dwSuicide - dwPBExe;
	ResultPlayerSpeed		= DwPlayerSpeed - dwPBExe;
	ResultSetNetChara		= FakeReplac;
	ResultGHOST				= ResultPTRAddCharaDeath;
	ResultHealth			= ResultPTRAddCharaHealth;
	ResultPLAYER			= ResultSKILL - 0x26C;
	ResultBONE				= ResultUserDeath;
	ResultBugWeapon			= dwUnyuk - dwPBExe;
	ResultDoLine			= DwDoLine;
	ResultCamPos			= DwCamPos;
	ResultEventFire			= DwEventFire;
	ResultDropWeapon		= DwDropWeapon;
	ResultThrowWeapon		= DwThrowWeapon;
	ResultBugHover1			= BugHover1	- dwNxChara;
	ResultBugHover2			= BugHover2 - dwNxChara;
	ResultBugHover3			= BugHover3 - dwNxChara;
	ResultBugHover4			= BugHover4 - dwNxChara;
	ResultBugHover5			= BugHover5 - dwNxChara;
	HookBaseRender			= HookBaseRender;
	ResultHook				= ResultHook;
	NeoEndRender			= i3EndRender;
	NeoDrawIndexPrim		= i3DrawIndexPrim;
	EndRenderBCK			= NeoEndRenderTarget + 6;
	DrawIndexPrimBCK		= NeoDrawIndexPrimTarget + 6;
	NeoEndRenderTarget		= i3EndRender + 0x8;
	NeoDrawIndexPrimTarget	= i3DrawIndexPrim + 0x12D;
	WTF						= dwWTF - dwNxChara - 0x1000;
	ResultPRIMARYSIZE		= 0x1C;
	ResultSECONDARYSIZE		= 0x20;
	ResultMALESIZE			= 0x24;
	ResultBOMBSIZE			= 0x28;
	ResultSMOKESIZE			= 0x2C;
	Beep(500, 500);
}

/*-------------------------------------------------------------------------------------------------------------------*/
#define NAMESIZE			0x21
#define RANKSIZE			0x2B
#define HPSIZE				0x24
#define IDSIZE				0x01
#define PlayerBody			0x548 
#define CoordinateX			0x11C
#define CoordinateZ			0x120
#define CoordinateY			0x124
#define CoordinateX2		0x110
#define CoordinateZ2		0x114
#define CoordinateY2		0x118
#define BypassWeapon1       0x1000EF94
#define BypassWeapon2       0x1000EFC3

/*-------------------------------------------------------------------------------------------------------------------*/