#include <windows.h>
#include "File.h"
#include "XStr.h"
Semprul	*_My = NULL;
int Norespawn,xxAccuracy,FileLine,CallAImFunc,Tsung,Tsung2,TsungHS,Tsung5 = NULL;
int xAccuracy;
int CallAmmo = NULL;
int HollowSetan = NULL;
int FastChange = NULL;
int RapidAdvancFire,FlyCacadMode,CallFlyHack,RapidQQ,RelCacadMode = NULL;
int BombEnywhere = NULL;
int BAKSOKA = NULL;
int HeadLock = NULL;
int AimCrotMode,AimCrotModeFake ,ammoroll,DepositAmmo = NULL;
int CallAimCrotMode = NULL;
int WallCrot = NULL;
int PlayerNameV2 = NULL;
int ChamsTR = NULL;
int ChamsTR2 = NULL;
int ChamsCT = NULL;
int ChamsCT2 = NULL;
int Weapon = NULL;
int chamsWeapon = NULL;
int DateTimes = NULL;
int ShowTime ,Suicide,DUp= NULL;
int biar = 1;
int NoFog = NULL;
int Damage1 = NULL;
int UnSmoke = NULL;
int AntiAFK = NULL;
int Gila = NULL;
int Folder1,Folder2,Folder3,Folder4,Folder5,Folder6,Folder7=NULL;
int NoRecoil = NULL;
int AimPelor,AimPelorBadan,AimLockHotkey ,AutoHeS= NULL;
int ReloadMayor = NULL;
int ReplaceCCD = NULL;
int BugtrapEnemy = NULL;
int ReplaceAcc = NULL;
int ReplaceAWP = NULL;
int ReplaceSG = NULL;
int ReplaceSMG = NULL;
int FastKnife = NULL;
int GhostExit,FallDmg = NULL;
int AutoRedyGB = NULL;
int BrustSniperSg = NULL;
int AutoOutGB = NULL;
int ShowName = NULL;
int AutoShoot = NULL;
int Knife = NULL;
int RepeatCall = NULL;
int AutoHS = NULL;
int FlyHack = NULL;
int GhostBuster = NULL;
int UltimateAmmo = NULL;
int ModeFloodVoteKick = NULL;
int FiturRusuh = NULL;
int CrossEnds = NULL;
int Reload;
int DinoSpam = NULL;
int SuicideTruz = NULL;
int StringHacker = 1;
int RenderText = 1;
int HideMenu = 1;
int TargetPelor = NULL;
int PelorSetan = NULL;
int ESPBone = NULL;
int ESPHealth = NULL;
int AutoHeadshot = NULL;
int Accuracy,CallAccuracy,callAimHead = NULL;
int AutoCrotCacad = NULL;
DWORD BackupEDXTele,BackupEDXTeleTod,ReadHSC,ReadHSD,ReadHSF,ReadHSE,ReadHSG,ReadHSH,
ReadDMGA,ReadDMGB,ReadDMGC,ReadDMGD,ReadDMGE,ReadDMGF,ReadDMGG,ReadDMGH,ReadBYPASSKACA,ReadBYPASSD,
ReadBYPASSKELA,ReadBYPASSKELB,ReadBYPASSKELC,ReadBYPASSKELD,ReadBYPASSKELE,ReadBYPASSKELF,ReadBYPASSKELG,ReadBYPASSKELH;
bool bBetrayer = false;
bool bGExit = false;
bool Bbetrayer = true;
bool BGExit = true;
bool Shot = false;
bool HookedShot = false;
int CallReplace = NULL;
bool Keprok,Keprox = false;
bool bPiso = false;



//---------------------------Flod Kick Flayer---------------------//
DWORD PTR_Caller,BaseECX,CallBasePB,Definition,ReDefinition,ReadProcASM, StartRouneAmmo= NULL;
void FloodKickPlayer(int IndexPlayer) {
Sleep(100);
if(Keprox == false){
CallBasePB = (DWORD)GetModuleHandle("Pointblank.exe");
PTR_Caller = (DWORD)(CallBasePB + 0xB2C10);
BaseECX = *(DWORD*)(CallBasePB + g_pPlayerBase);
BYTE pKick[15];
*(BYTE*)(pKick) = IndexPlayer;
Definition = (DWORD)pKick;
ReDefinition = (DWORD)pKick + 0x4;
Sleep(5);
__asm
{
push 0x01
push 0x01
push 0x01
push [ReDefinition]
push [Definition]
push 0x9E
mov ecx,[BaseECX]
call [PTR_Caller]
}
Sleep(100);
Keprox = true;
}
}
//===========================================================================================================//
DWORD WINAPI ThreadFloodVK ()
{
while(1)
{
if(ModeFloodVoteKick == 1)
{
Sleep(100);
Keprox = false;
if(*(PBYTE)c_pPelorReload > NULL){
Sleep(5);
for (int i = 0; i<=15; i++){
int MySlot = _My->GetMyCharaIndex(); 
if( i == MySlot)continue; 
FloodKickPlayer(i);
}}}
Sleep(100);
}
return 0;
}
////----------------SC Extreme Knife-------------------//
void PisoGile(void)
{
	if(bPiso == false){
		PisoGila = TestPacth( c_pPelorReload, PTRWeaponSize2Ammo, 0x24, 0xC94);
	}
	if(Knife == 0){
		bPiso = false;
		PacthWeapone( c_pPelorReload, PTRWeaponSize2Ammo, 0x24, 0xC94, PisoGila);
	}
	if(Knife == 1){
		bPiso = true;
		PacthWeapone( c_pPelorReload, PTRWeaponSize2Ammo, 0x24, 0xC94, PisoGila);
	}
	
}

//----------------SC Ammo Relaod-------------------//
bool bAmmo=false;
void AmmoReloads()
{
	if(bAmmo == false){
			StartRouneAmmo = _My->GetAmmoIndex(c_pPelorReload, 0x548, 0x1C, 0xCA0);
	}
	if(DepositAmmo == 0){
		bAmmo = false;
		_My->gEtWeapon_IndexA( c_pPelorReload, 0x548, 0x1C, 0xCA0, StartRouneAmmo);
    }
	if(DepositAmmo == 1){
		bAmmo = true;
		_My->gEtWeapon_IndexA( c_pPelorReload, 0x548, 0x1C, 0xCA0, StartRouneAmmo);
		}}
//--------------------------Fast Reload----------------------------//
void Reload0DetikCACAD() {
DWORD PBExe = (DWORD)GetModuleHandleA("PointBlank.exe");
if(Reload){
_My->c_WeaponIndex_B(PBExe + g_pPelorReload,0x544,0x1C, 0x30,0x67,0x41);
_My->c_WeaponIndex_B(PBExe + g_pPelorReload,0x544,0x20, 0x30,0x67,0x41); //skrg  oba ganti seluruh offset di logger.h trus build, 
} 
}
DWORD PTRReplace = NULL;
DWORD ValReplace = NULL;
DWORD SizeWeapon = NULL;
 
DWORD ThreadReplace()
{
while(1){
//-------------------------No recoil--------------------------//
if(NoRecoil == 1){
DWORD RecExe = (DWORD)GetModuleHandleA("Pointblank.exe");
_My->WriteHack(((DWORD)RecExe + g_pPelorReload), 0x55C, 0x0C, 0x00000000);//; "void __thiscall Crosshair::CalcRminLen("
_My->WriteHack(((DWORD)RecExe + g_pPelorReload), 0x55C, 0x14, 0x00000000);
_My->WriteHack(((DWORD)RecExe + g_pPelorReload), 0x55C, 0x48, 0x00000000);
_My->WriteHack(((DWORD)RecExe + g_pPelorReload), 0x55C, 0x4C, 0x00000000);
_My->WriteHack(((DWORD)RecExe + g_pPelorReload), 0x55C, 0x50, 0x00000000);
_My->WriteHack(((DWORD)RecExe + g_pPelorReload), 0x55C, 0x38, 0x00000000);
_My->WriteHack(((DWORD)RecExe + g_pPelorReload), 0x55C, 0x3c, 0x00000000);
_My->WriteHack(((DWORD)RecExe + g_pPelorReload), 0x55C, 0x40, 0x00000000);
_My->WriteHack(((DWORD)RecExe + g_pPelorReload), 0x55C, 0x28, 0x00000000);
_My->WriteHack(((DWORD)RecExe + g_pPelorReload), 0x55C, 0x2c, 0x00000000);
_My->WriteHack(((DWORD)RecExe + g_pPelorReload), 0x55C, 0x30, 0x00000000);
_My->WriteHack(((DWORD)RecExe + g_pPelorReload), 0x55C, 0x34, 0x00000000);
_My->WriteHack(((DWORD)RecExe + g_pPelorReload), 0x55C, 0x58, 0x00000000);
_My->WriteHack(((DWORD)RecExe + g_pPelorReload), 0x55C, 0x5c, 0x00000000);
_My->WriteHack(((DWORD)RecExe + g_pPelorReload), 0x55C, 0x68, 0x00000000);
_My->WriteHack(((DWORD)RecExe + g_pPelorReload), 0x55C, 0x60, 0x00000000);
}


Sleep(0.5);
}
return 0;
}//*/

DWORD HookSuicide()
{
while(1)
{
//---------------quick change------------------//
if(FastChange == 1){
PacthWeapone( c_pPelorReload, 0x544, 0xEC, 0x67, 0x41);
}

////////////////AimLock////////////////////
if(CallAImFunc == 1){
if(GetAsyncKeyState(VK_LBUTTON)){
xAccuracy = 1;
}else {
xAccuracy = 0;
}}
//---------------Jumpt------------------//
if (FlyCacadMode == 1)
{
if (GetAsyncKeyState(VK_SPACE))
{
__try
{
*(BYTE*)(*(DWORD*)(BaseRizkyAmmoSemvax2) + 0x500) = 0xFF;
}__except (EXCEPTION_EXECUTE_HANDLER){
}
}
}
//---------------------------------------//
Sleep(0.5);
}
return 0;
}

bool bHookedTele = false;
int GetTeam(char MyT);;
int GetTeam(char MyT){
if(bHookedTele == true){
if (MyT == 0 ||MyT == 2||MyT == 4||MyT == 6||MyT == 8||MyT == 10||MyT == 12||MyT == 14)return 1;
else
if (MyT == 1 ||MyT == 3||MyT == 5||MyT == 7||MyT == 9||MyT == 11||MyT == 13||MyT == 15)return 2;
bHookedTele = false;
}
return 0;
}

DWORD _PTRCall = NULL;
DWORD _PTRWpn = NULL;
DWORD _PTRBull1 = NULL;
DWORD _PTRBull2 = NULL;
DWORD _PTRPis = NULL;
//============================================
int Betrayer = NULL;
DWORD XL;
void GhostHack (){
DWORD pBase = (DWORD)GetModuleHandleA("Pointblank.exe");
DWORD PtrAdr = *(PDWORD)(pBase + g_pPlayerBase);
DWORD ValbasePlayer = pBase + g_pPlayerBase;
DWORD ValbaseESP = pBase + g_pESP;
DWORD ValbaseAMMO = pBase + g_pPelorReload;
CTeam *pTeam = (CTeam*)(PtrAdr + P_BaseTEAM);
CHealth* GetHealth = (CHealth*)((ValbaseESP + 0x264) + pTeam->iTeam * 0x20);
if(*(PBYTE)ValbasePlayer > NULL){//base player
if(bBetrayer == false){
Betrayer = _My->ReadFunct(ValbaseESP, 0x260 + pTeam->iTeam * 0x20);//base esp
VirtualProtect((PVOID*)(Betrayer), 10, PAGE_EXECUTE_READWRITE, &XL);
}
}
if(GhostBuster == 0){
if(!Bbetrayer){
bBetrayer = false;
__try
{
*(DWORD*)(*(DWORD*)(ValbaseESP) + 0x260 + pTeam->iTeam * 0x20) = Betrayer;
VirtualProtect((PVOID*)((ValbaseESP) + 0x260 + pTeam->iTeam * 0x20), 10, PAGE_EXECUTE_READWRITE, &XL);
}__except (EXCEPTION_EXECUTE_HANDLER){
}
Bbetrayer=true;
}}

if(GhostBuster == 1){
if(Bbetrayer){
bBetrayer = true;
__try
{
*(DWORD*)(*(DWORD*)(ValbaseESP) + 0x260 + pTeam->iTeam * 0x20) = Betrayer-1;
VirtualProtect((PVOID*)((ValbaseESP) + 0x260 + pTeam->iTeam * 0x20), 10, PAGE_EXECUTE_READWRITE, &XL);
}__except (EXCEPTION_EXECUTE_HANDLER){
}
Bbetrayer=false;
}
}


//------------- Deklarasi Hotkey -------
if(GetAsyncKeyState(VK_LMENU)&1)
    {
	GhostBuster=!GhostBuster;
	MessageBeep(0);
	Beep(1000,100);
	}
	
//if (GetAsyncKeyState(VK_F1)&1)
//    {
//	ammoroll=!ammoroll;
//	Reload=!Reload;
//	Norespawn=!Norespawn;
//	ESPBone=!ESPBone;
//	PlayerNameV2=!PlayerNameV2;
//	ESPHealth=!ESPHealth;
//	Accuracy=!Accuracy;
//	ESPHealth=!ESPBone;
//	WallCrot=!WallCrot;
//	MessageBeep(0);
//	Beep(1000,100);
//	}
//if(GetAsyncKeyState(VK_DELETE)&1)
//    {
//	ModeFloodVoteKick=!ModeFloodVoteKick;
//	MessageBeep(0);
//	Beep(1000,100);
//	}
}
//-----------------
//if(GetAsyncKeyState(VK_LSHIFT)&1)
//{
//AutoHS=!AutoHS;
//MessageBeep(0);
//Beep(1000,100);
//}