#include "Updater_Funtion.h"
#define Pattern_Respawn "\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xEB\x1A\x6A\x01\x6A\xFF\x6A\x01\x8B\x55\x10\x52\x8B\x45\x0C\x50\x8B\x4D\x08\x51\x8B\x4D\x00" 
#define Mask_Respawn "xx????x????xxxxxxxxxxxxxxxxxxxxxx?" 
#define Pattern_WallShot "\x75\x1F\xC7\x45\x00\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\x8D\x4D\xC0\xFF\x15\x00\x00\x00\x00\x8B\x45\xA8" 
#define Mask_WallShot "xxxx?????xx?????xxxxx????xxx" 
#define Pattern_FastPlant "\x72\x2E\x83\x7D\xFC\x00\x74\x14\x8B\x45\xF8\x3B\x45\xF4\x75\x0C\x8B\x4D\xF8" 
#define Mask_FastPlant "xxxxx?xxxxxxxxxxxxx" 
#define Pattern_pNightVision "\x55\x8B\xEC\x51\x89\x4D\xFC\x8B\x45\xFC\x83\xB8\xA4\x01\x00\x00\x00\x75\x2A\x6A\x00" 
#define Mask_pNightVision "xxxxxxxxxxxxxxxxxxxxx" 
#define Pattern_PTRTeam "\x8b\x55\xC4\x8b\x82\x00\x00\x00\x00\x25\x00\x00\x00\x00\x79"
#define Mask_PTRTeam "xxxxx????x????x"
#define Pattern_AIM "\x51\x8B\x4D\x00\x81\xC1\x00\x00\x00\x00\xFF\x15\x00\x00\x00\x00\x8B\x55\x00\x8B\x8A\x00\x00\x00\x00\xE8"
#define Mask_AIM "xxx?xx????xx????xx?xx????x"
#define Pattern_Recoil "\x8B\x80\x00\x00\x00\x00\x8B\xE5\x5D\xC3\xCC\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xCC\x00\x00\x00\x00\x00\x00\x00\x8B\x45\xFC\x05\x00\x00\x00\x00\x8B\xE5\x5D\xC3\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xCC\x55\x8B\xEC\x51\x89\x4D\xFC\x8B\x45\xFC\x05\x00\x00\x00\x00\x8B\xE5\x5D\xC3\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xCC\x55\x8B\xEC\x51\x89\x4D\xFC\x8B\x45\xFC\x8B\x80"
#define Mask_Recoil "xx????xxxxx??????????x???????xxxx????xxxx????????????xxxxxxxxxxxx????xxxx????????????xxxxxxxxxxxxx"
#define Pattern_gPRenderText "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x90\x68\x00\x00\x00\x00\xFA"
#define Mask_gPRenderText "xxxxxxxxxxxxxxxxxxxxxx????x"
#define Pattern_i3Bypass "\x8B\x81\x00\x00\x00\x00\x8B\x08\x52\x8B\x54\x24\x0C\x8B\x92\x00\x00\x00\x00\x8B\x12\x8B\x52\x34"
#define Mask_i3Bypass "xx??xxxxxxxxxxx??xxxxxxx"
#define Pattern_BaseWeapon "\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x89\x45\x00\x8B\x4D\x00\x8B\x11"
#define Mask_BaseWeapon "xx????x????xx?xx?xx"
#define Pattern_WeaponBugs "\xBE\x00\x00\x00\x00\x65\x43\x68"
#define Mask_WeaponBugs "x????xxx"
#define Pattern_Wtw "\x89\x8b\x34\x01"
#define Mask_Wtw "xxxx"
#define Pattern_SetUserDeath "\xC6\x81\x00\x00\x00\x00\x00\x8B\x55\xFC\x69\xD2\x00\x00\x00\x00\x8B\x45\xF8"
#define Mask_SetUserDeath "xx???xxxxxxx????xxx"

#define Pattern_HookESP "\x8D\x85\x00\x00\x00\x00\x50\x8D\x8B\x00\x00\x00\x00\x88\x93\x00\x00\x00\x00"
#define Mask_HookESP "xx???xxxx???xxx???x"


UCHAR uPeler	[] = {0xEB, 0x05, 0xE9, 0x00, 0x00, 0x00, 0x00, 0x8B, 0x55, 0xFC, 0x89};
UCHAR FloadAVK	[] = {0xE8, 0x00, 0x00, 0x00, 0x00, 0xA1, 0x00, 0x00, 0x00, 0x00, 0x33, 0xC5, 0x89, 0x45, 0x00, 0x56, 0x50, 0x8D, 0x45}; 
UCHAR FLODKICK [] = {0x55, 0x8B, 0xEC, 0x6A, 0xFF, 0x68, 0x98, 0xC9, 0x91, 0x00, 0x64, 0xA1, 0x00, 0x00, 0x00, 0x00, 0x50, 0xB8, 0x70, 0x2D};

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
DWORD FrameDX       = (DWORD)LoadLibraryA("i3FrameWorkDx.dll"); 

DWORD HookBaseRender	= (DWORD)GetProcAddress(hGfxDx, "?g_pRenderContext@@3PAVi3RenderContext@@A")- dwi3GfxDx;
DWORD dwBaseAddress   = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x89\x45\x00\x8B\x4D\x00\x8B\x11","xx????x????xx?xx?xx");
DWORD dwBullet        = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x51\x8B\x4D\x00\x81\xC1\x00\x00\x00\x00\xFF\x15\x00\x00\x00\x00\x8B\x55\x00\x8B\x8A\x00\x00\x00\x00\xE8","xxx?xx????xx????xx?xx????x");
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
DWORD DwSetEvent		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\xE8\x00\x00\x00\x00\xA1\x00\x00\x00\x00\x33\xC5\x89\x45\x00\x56\x50\x8D\x45","x????x????xxxx?xxxx");
DWORD dwInvincible    = FindPattern(dwPBExe,0xA00000 ,(PBYTE)"\x6F\x12\x83\x3C","xxxx");
DWORD	 DwSetNetChara    = FindPattern(dwPBExe,i3PBExe,(PBYTE) "\xFF\xD0\xEB\x00\x8B\xE5\x5D\xC2\x04\x00\xCC\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xCC\x55\x8B\xEC\x83\xEC\x00\x89\x4D\xD0\x83\x7D\x00\x00\x74\x00","xxx?xxxxx?x??????????xxxxxx?xxxxx??x?");
DWORD dwSuicide       = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x00\x89\x4D\x00\x51\xD9\xE8","xxxxx?xx?xxx");
DWORD dwPrimary       = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x88\x00\x00\x00\x00\x51\xFF\x15\x00\x00\x00\x00\x83\xC4\x00\x8B\x55\x00\xC7\x82\x00\x00\x00\x00\x00\x00\x00\x00\x5E\x8B\xE5\x5D\xC3","xx????xxx????xx?xx?xx????????xxxxx");
DWORD dwWallShot      = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x75\x00\xC7\x45\x00\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\x8D\x4D\x00\xFF\x15\x00\x00\x00\x00\x8B\x45\x00","x?xx?????xx?????xx?xx????xx?");
DWORD FakeReplac      = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x30\x89\x4D\xD0\x83\x7D\x08\x00\x74","xxxxxxxxxxxx?x");
DWORD DwPTRIdle		    = FindPattern(dwPBExe, i3PBExe,(PBYTE)"\x8B\xE5\x5D\xC2\x04\x00\xCC\x00\x00\x00\x00\xCC\x55\x8B\xEC\x51\x89\x4D\xFC\x8B\x45\xFC\x8B\x80","xxxxx?x????xxxxxxxxxxxxx");
DWORD gi3Ammo	= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B\x45\xFC\x8B\x4D\x08\x89\x88\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D","xx????xxxxxxxxxxx??xxxxxxxxxxxxxx");
DWORD DwAmmo1		= FindPattern(gi3Ammo+1,i3PBExe,(PBYTE)"\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B\x45\xFC\x8B\x4D\x08\x89\x88\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D","xx????xxxxxxxxxxx??xxxxxxxxxxxxxx");
DWORD DwAmmo2		= FindPattern(DwAmmo1+1,i3PBExe,(PBYTE)"\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B\x45\xFC\x8B\x4D\x08\x89\x88\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D","xx????xxxxxxxxxxx??xxxxxxxxxxxxxx");
DWORD DwAmmo3		= FindPattern(DwAmmo2+1,i3PBExe,(PBYTE)"\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B\x45\xFC\x8B\x4D\x08\x89\x88\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D","xx????xxxxxxxxxxx??xxxxxxxxxxxxxx");
DWORD dwPTRRecoil	= FindPattern(dwPBExe, i3PBExe, (PBYTE)Pattern_Recoil, Mask_Recoil);
DWORD DoLineCollision = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x55\x8B\xEC\x83\xEC\x0C\x89\x4D\xF4\xC6\x45\xFF\x00\x83\x7D\x08\x00\x75","xxxxxxxxxxx??xxx?x");
DWORD CamPosition     = FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x53\x8B\xDC\x83\xEC\x08\x83\xE4\xF0\x83\xC4\x04\x55\x8B\x6B\x04\x89\x6C\x24\x04\x8B\xEC\x81\xEC\xA0\x00\x00\x00\x89\x4D\xFC\x83\x3D","xxxxxxxxxxxxxxxxxxxxxxxxx???xxxxx");
DWORD DwPTRVicible		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8B\x45\x08\x8B\x4D\xDC\xC7\x84\x81\x00\x00\x00\x00\x03\x00\x00\x00\x8B\x4D\xF8","xxxxxxxxx????xxxxxxx"	);
DWORD DwPlayerSpeed		= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x00\x00\x00\x40\xE1\x7A\x84\x3F","xxxxxxxx");
DWORD DwNames			= FindPattern(dwPBExe,i3PBExe,(PBYTE)"\x8D\x84\x10\x00\x00\x00\x00\x8B\xE5\x5D\xC2\x04\x00\x55\x8B\xEC\x51\x89\x4D\xFC\x8B\x45\xFC\x8B\x88","xxx????xxxxx?xxxxxxxxxxxx");

DWORD OFSSkill, OFSHelmed, OFSReplace, WTF, WTW, ResultSmoke, OFSBullet, ResultBomb, ResultQuick, ResultPTRAmmo,ResultNorecoil;
DWORD ResultHook, ResultBaseAddress, ResultKill, ResultPing, ResultScore, ResultBaseBullet,ResultBullet,ResultRafid,ResultRafid2;
DWORD ResultSkill, ResultSkill2, ResultRespawn, ResultMajor, ResultBugWeapon, ResultSuicide,ResultUserDeath,ResultSetEvent;
DWORD ResultBaseHealth, ResultBaseHealth2, ResultBasePlayer, ResultBasePlayer2, ResultBaseAmmo, ResultBaseAmmo2,PTRAmmoA,PTRAmmoB,PTRAmmoC,PTRAmmoD;
DWORD ResultDoLine,ResultCamPos ,ResultEventFire,ResultSetNetChara,ResultTeam,PTR_Target,ResultPTRTarget,ResultRespawn2,ResultPlayer;
DWORD ResultName,ResultGHOST,ResultHealth,ResultGetButton,ResultInvincible,ResultPrimary,ResultSecondary,ResultWallShot,PTRProtectA,PTRProtectB,PTRProtectC,PTRProtectD;
DWORD PTR_Idle,PTR_Idle2,ResultPTRIdle,ResultPRIMARYSIZE,ResultSECONDARYSIZE,ResultMALESIZE,ResultBOMBSIZE,ResultSMOKESIZE,ResultPTRAmmoA,ResultPTRAmmoB,ResultPTRAmmoC;
DWORD PTR_NoRecoil,ResultPTR,ResultPlayerSpeed,ResultPTRAddCharaHealth,ResultNames,ResultPTRVicible,PTR_BaseAmmo,PTR_AmmoKanan,PTR_AmmoKiri,ResultMelee,OFS_CamPosition,OFS_DoLineCollision;
void MenuX_Updater(){
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwBaseAddress + 0x2), &ResultBaseAddress, sizeof(ResultBaseAddress), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwBullet + 0xC ), &ResultBullet, sizeof(ResultBaseBullet), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwSkill + 0x4), &OFSSkill, sizeof(OFSSkill), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwKill + 0x3), &ResultKill, sizeof(ResultKill), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwPing + 0x2), &ResultPing, sizeof(ResultPing), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwScore + 0x3), &ResultScore, sizeof(ResultScore), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwQuick + 0x2), &ResultQuick, sizeof(ResultQuick), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwHook + 0x2), &ResultHook, sizeof(ResultHook), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwUser+0x2), &ResultUserDeath, sizeof(ResultUserDeath), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwTeam+0xC), &ResultTeam, sizeof(ResultTeam), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwPTRpTarget2+0xE), &ResultPTRTarget, sizeof(ResultPTRTarget), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwPlayer+0xC)	,&ResultPlayer,sizeof(ResultPlayer)		,NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwName+0xC),&ResultName,sizeof(ResultName)		,NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwGhost+0x9),&ResultGHOST	,sizeof(ResultGHOST)		,NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwGetButton+0x12), &ResultGetButton, sizeof(ResultGetButton), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwPrimary + 0x2), &OFSReplace, sizeof(OFSReplace), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwPTRIdle+0x18), &ResultPTRIdle, sizeof(ResultPTRIdle), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwAmmo1+0x11),&ResultPTRAmmoA, sizeof(ResultPTRAmmoA), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwAmmo2+0x11),&ResultPTRAmmoB, sizeof(ResultPTRAmmoB), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwAmmo3+0x11),&ResultPTRAmmoC, sizeof(ResultPTRAmmoC), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwPTRRecoil+0x2), &ResultPTR, sizeof(ResultPTR), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwPTRVicible+0x9), &ResultPTRVicible, sizeof(ResultPTRVicible), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwNames+0x3), &ResultNames, sizeof(ResultNames), NULL);

//--------------------------------------------------------------------
ResultBasePlayer      = ResultBaseAddress - dwPBExe;
ResultBasePlayer2     = ResultBaseAddress;
ResultBaseHealth      = ResultBaseAddress - dwPBExe - 0x34;
ResultBaseHealth2     = ResultBaseAddress - 0x34;
ResultBaseAmmo        = ResultBaseAddress - dwPBExe - 0x38;
ResultBaseAmmo2       = ResultBaseAddress - 0x38;
ResultUserDeath       = ResultUserDeath;
ResultBaseBullet      = ResultBullet -dwPBExe;
ResultSetEvent		  = DwSetEvent - 0x16;
ResultPTRAmmo         = ResultQuick + 0x4;
ResultNorecoil        = ResultQuick + 0x18;
PTR_Target            = ResultQuick + 0x20;
ResultRespawn2        = ResultTeam - 0x19B0;
ResultSkill2          = OFSSkill;
ResultSkill           = ResultSkill2 - 0x1;//
PTR_Idle		      = ResultPTRIdle - 0x1;
PTR_Idle2		      = ResultPTRIdle + 0x4;
ResultRespawn         = ResultSkill2 + 0x1;
ResultPrimary         = OFSReplace + 0x5A0;
ResultRafid           = ResultNorecoil - 0x7C;
ResultRafid2          = ResultNorecoil - 0x54;
ResultSecondary       = ResultPrimary + 0x4;
ResultMelee           = ResultPrimary + 0x8;
ResultSmoke           = ResultPrimary + 0x10;
ResultInvincible      = dwInvincible - dwPBExe;
ResultWallShot        = dwWallShot - dwPBExe;
ResultSuicide         = dwSuicide - dwPBExe;
ResultSetNetChara     = FakeReplac;
ResultGHOST           = 0x260;
ResultHealth          = 0x264;
ResultBugWeapon       = dwUnyuk - dwPBExe;
ResultDoLine          = DwDoLine;
ResultCamPos          = DwCamPos;
ResultEventFire       = DwEventFire;
HookBaseRender        = HookBaseRender;
ResultHook            = ResultHook;
WTF                   = dwWTF - dwNxChara - 0x1000;
ResultPRIMARYSIZE		= 0x1C;
ResultSECONDARYSIZE		= 0x20;
ResultMALESIZE			= 0x24;
ResultBOMBSIZE			= 0x28;
ResultSMOKESIZE			= 0x2C;
PTRAmmoA				= ResultPTRAmmoA;
PTRAmmoB				= ResultPTRAmmoB;
PTRAmmoC				= ResultPTRAmmoC - 0x4;
PTRAmmoD				= ResultPTRAmmoC;
PTRProtectA			= PTRAmmoC + 0x8;
PTRProtectB			= PTRAmmoC + 0x10;
PTRProtectC			= PTRAmmoC + 0x24;
PTRProtectD			= PTRAmmoC + 0x68;
PTR_NoRecoil			=ResultPTR;
	PTR_BaseAmmo			=ResultPTR - 0x14;
	PTR_AmmoKanan			=ResultPTR + 0x744;
	PTR_AmmoKiri			=ResultPTR + 0x73C;
    OFS_DoLineCollision     = DoLineCollision;
	OFS_CamPosition         = CamPosition;
	ResultPTRAddCharaHealth	= ResultPTRVicible + 0x44;
	ResultPlayerSpeed		= DwPlayerSpeed - dwPBExe;

//Writelog("#define ResultBasePlayer			0x%X", ResultBasePlayer);
//Writelog("#define ResultBasePlayer2			0x%X", ResultBasePlayer2);
//Writelog("#define ResultBaseHealth			0x%X", ResultBaseHealth);
//Writelog("#define ResultBaseHealth2			0x%X", ResultBaseHealth2);
//Writelog("#define ResultBaseAmmo			0x%X", ResultBaseAmmo);
//Writelog("#define ResultBaseAmmo2			0x%X", ResultBaseAmmo2);
//Writelog("#define ResultUserDeath			0x%X", ResultUserDeath);
//Writelog("#define ResultBaseBullet			0x%X", ResultBaseBullet);
//Writelog("#define ResultPTRAmmo			    0x%X", ResultPTRAmmo);
//Writelog("#define PTR_Target			    0x%X", PTR_Target);
//Writelog("#define ResultPTRTarget		  	0x%X", ResultPTRTarget);
//Writelog("#define ResultNorecoil			0x%X", ResultNorecoil);
//Writelog("#define ResultSkill2			    0x%X", ResultSkill2);
//Writelog("#define ResultSkill			    0x%X", ResultSkill);
//Writelog("#define ResultRespawn			    0x%X", ResultRespawn);
//Writelog("#define ResultRespawn2			0x%X", ResultRespawn2);
//Writelog("#define ResultTeam		         	0x%X", ResultTeam);
//Writelog("#define ResultGHOST		         	0x%X", ResultGHOST);
//Writelog("#define ResultHealth		         	0x%X", ResultHealth);
//Writelog("#define ResultPrimary			    0x%X", ResultPrimary);
//Writelog("#define ResultSmoke			    0x%X", ResultSmoke);
//Writelog("#define ResultBugWeapon			0x%X", ResultBugWeapon);
////Writelog("#define ResultMagnet			0x%X", ResultMagnet);
//Writelog("#define ResultWallShot			0x%X", ResultWallShot);
//Writelog("#define ResultInvincible			0x%X", ResultInvincible);
//Writelog("#define ResultSuicide			    0x%X", ResultSuicide);
//Writelog("#define ResultPlayer			    0x%X", ResultPlayer);
//Writelog("#define ResultName			    0x%X", ResultName);
//Writelog("#define BugWall        		    0x%X", WTF);
//Writelog("#define ResultDoLine			0x%X", ResultDoLine);
//Writelog("#define ResultCamPos			0x%X", ResultCamPos);
//Writelog("#define ResultEventFire	    0x%X", ResultEventFire);
//Writelog("#define ResultSetNetChara			    0x%X", FakeReplac);
//Writelog("#define ResultPing			    0x%X", ResultPing);
//Writelog("#define ResultScore			    0x%X", ResultScore);
//Writelog("#define HookBaseRender			0x%X", HookBaseRender);
//Writelog("#define ResultHook			    0x%X", ResultHook);
//ShellExecute(NULL, "open", "Notepad.exe", GetDirectoryFile("Loger.txt"), NULL, SW_SHOWNORMAL);
//
//ExitProcess(0);
#define OFS_Idle        ResultBasePlayer2-0x8
#define ALIVESIZE			0x24

Beep(500, 500);

}

#define NAMESIZE    0x21
#define RANKSIZE    0x2B
#define HPSIZE      0x24
#define IDSIZE      0x01
#define WEAPSIZE    0x158
//========================================================================================
#define OFS_Soccer				0x35E20D79
#define Candy_Granade			0x35E20D6C
#define Lantern_Grenade			0x35E20D6F
#define Decoy_Bomb				0x35E20D72
#define Bread_Grenade			0x35E20D70
#define WP_Smoke				0x35E20D64
#define WP_SmokeD				0x35E20D5D
#define Blue_Bomb				0x35E20D74

#define PlayerBody		0x548 
#define CoordinateX		0x11C
#define CoordinateZ		0x120
#define CoordinateY		0x124
#define CoordinateX2	0x110
#define CoordinateZ2	0x114
#define CoordinateY2	0x118

#define ADR_AntiPI1 0x60D124 
#define ADR_AntiPI2 0x699DD4
#define ADR_AntiPI3 0x630014 