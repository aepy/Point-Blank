#include <windows.h>
#include "File.h"
#include "XStr.h"
Semprul	*_My = NULL;
LPTSTR PointBlankSTR4 = "PointBlank.exe";
int Norespawn,xxAccuracy,move,FileLine,CallAImFunc,Tsung,Tsung2,TsungHS,Tsung5 = NULL;
int xAccuracy;
int Fake;
int BRUTALL =NULL;
int NoFallDamage =NULL;
int ESPHealth1,JumpHight,FallDamage = NULL;
int AimBodyf = NULL;
int BP_Invi = NULL;
int Magnet = NULL;
int Bug,WShoot,ReplaceCCD2,ZombieCall = NULL;
int AimBodyi;
int DamagePisoTeleKill = NULL;
int Zombiekillersz = NULL;
int PisoTeleKill1 = NULL;
int BOMKILLER = NULL;
int DamagePisoTeleKill1 = NULL;
int AntiIdle,xDepositAmmo = NULL;
int SubMacineGun = NULL;
int Assault,MeleeHack,Shotgun,Sniper,SMG = NULL;
int FastShoot,StatusHotKey = NULL;
int FreeMove,RespawnTerus = NULL;
int PlayerNameV2 = NULL;
int HiddenWeapon = NULL;
int CallAmmo,R_Granad = NULL;
int Mini_1,Mini_2,Mini_3;
int MiniMized = 0;
int FSpeed = NULL;
int HeadLock = NULL;
int TeleKontol = NULL;
int AimCrotModeFake,DepositAmmo = NULL;
int CallAimCrotMode = NULL;
int WallCrot,BrustKnife = NULL;
int frpid = NULL;
int WhRobot = NULL;
int AimBodyc = NULL;
int Pistol= NULL;
int HeadPink = NULL;
int BulletKiller = NULL;
int TeleKontol1 =0;
int HeadPink2 = NULL;
//int ZombieReal = NULL;
int Zombie = NULL;
int QuickChange = NULL;
int qHeadPink = NULL;
int qHeadPink2,ReplaceSmoke = NULL;
int Phantom,WeaponSet = NULL;
int Wireframe =NULL;
int Wireframe2 =NULL;
int zWireframe =NULL;
int zWireframe2 =NULL;
int ChamsTR = NULL;
int ChamsTR2 = NULL;
int ChamsCT = NULL;
int FastChange = NULL;
int ChamsCT2,Gravity = NULL;
int Weapon = NULL;
int chamsWeapon = NULL;
int chamsWeapon2 = NULL;
int GhostBuster = NULL;
int ShowTime ,Suicide,DUp= NULL;
int biar = 1;
int Transperency = 255;// Basic transperecy COLOR
int Fade = 0;//Value panggilan fade
int SleepVAL = 5;//Waktu Sleep
int RGBX = 255;
int ResChanged = 0;
#define AMMO_ERROR 3
#define AMMO_SUCCESS 2
#define AMMO_NOT_ENABLED 1
int TextAmmo = 2;
int FadeAmmo = 0;
int qece = NULL;
int TransAmmo = 0;
int ControlFade = 0;
int NoFog = NULL;
int UnSmoke = NULL;
int AntiAFK = NULL;
int FR1,FR2,FR3,FR4,FR5,FR6,FR7,FR8,FR9,FR=NULL;
int RapidAdvancFire,FlyCacadMode,CallFlyHack,RapidQQ,RelCacadMode = NULL;
int NoRecoil = NULL;
int AimPelor,AimPelorBadan,AimLockHotkey ,AutoHeS= NULL;
int ReloadMayor = NULL;
int ReplaceCCD = NULL;
int Wallbug,BreadGrenade = NULL;
int BugtrapEnemy = NULL;
int ReplaceAcc = NULL;
int ReplaceAWP,LenternGrenade = NULL;
int ReplaceSG = NULL;
int ReplaceSMG = NULL;
int FastKnife = NULL;
int Knife = NULL;
int GhostExit = NULL;
int AutoRedyGB = NULL;
int AutoOutGB = NULL;
int ShowName = NULL;
int Kukri =0;
int SuicideCall = NULL;
//-------------------------------------------
int FakeReplace=0;
int RapidFire=0;
int	Rep_Item=0;
int R_Launcher=0;
int R_Brutal=0;
int R_Secondary=0;
int AllReplace=0;
int R_Famas=0;
int LC=0;
int R_Secoandary=0;
//-------------------------------------------
int AutoShoot,CandyGrenade = NULL;
int RepeatCall = NULL;
int AutoHS = NULL;
int AK47FC,HK69,ReplaceRPG = NULL;
int UltimateAmmo,ChocolateGrenade = NULL;
int ModeFloodVoteKick = NULL;
int FiturRusuh = NULL;
int DecoyBoms = NULL;
int KetupatBoms = NULL;
int FreezeRespawn = NULL;
int CrossEnds = NULL;
int AutoHSReall =NULL;
int Cross,DecoyBomb = NULL;
int GoshClasic =NULL;
int UnHape =NULL;
int WireFrame = NULL;
int Reload;
int RankHack = NULL;
int WpSmoke = NULL;
int DinoSpam = NULL;
int Quick = NULL;
int AimDatar = NULL;
int RPG, aRPG = NULL;
int SuicideTruz = NULL;
int StringHacker = 1;
int RenderText = 1;
int HideMenu = 1;
int TargetPelor = NULL;
int PelorSetan = NULL;
int ESPBone = NULL;
int ESPObserver = NULL;
int ESPHealth = NULL;
int ESPHead =NULL;
int ESPRank =NULL;
int ESPDistance =NULL;
int ESPBox =NULL;
int AutoHeadshot = NULL;
int Accuracy,CallAccuracy,callAimHead,AutoHSKey = NULL;
int AutoCrotCacad = NULL;
int BP_NOTICE = NULL;
int BPP_Noclip = NULL;
int Betrayer = NULL;
int aDecoyBoms, bDecoyBoms, cDecoyBoms, dDecoyBoms, eDecoyBoms, fDecoyBoms, gDecoyBoms, hDecoyBoms, iDecoyBoms = NULL;
DWORD BackupEDXTele,BackupEDXTeleTod,ReadHSC,ReadHSD,ReadHSF,ReadHSE,ReadHSG,ReadHSH,
ReadDMGA,ReadDMGB,XL,ReadDMGC,ReadDMGD,ReadDMGE,ReadDMGF,ReadDMGG,ReadDMGH,ReadBYPASSKACA,ReadBYPASSD,
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
bool xPiso = false;

bool bGhoster = false;
static BOOL sprite = TRUE;  

void MouseHook();;
void MouseHook()
{
_asm{
cmp [Shot],0
je Normal
mov eax, 1;
retn
Normal:
mov eax, [ecx+0x2C]// 5 byte
ret
}
}
//----------------------------------------------------------- [[BrustKniffXXXXXXX]]
//void BrustKnifeXX(void){
//if(bPiso == false){
//PisoGila = TestPacth(ResultBaseAmmo2, 0x544, 0x24, 0xC98);
//}
//if(BrustKnife==0){
//bPiso = false;
//PacthWeapon(ResultBaseAmmo2, 0x544, 0x24, 0xC98, PisoGila);
//}
//if(BrustKnife == 1){
//bPiso = true;
//PacthWeapon(ResultBaseAmmo2, 0x544, 0x24, 0xC98, PisoGila);
//}
//}

//----------------------------------------------------------- [[UNLIMITED Ammo]]
DWORD xStartRouneAmmo = NULL;
bool xbAmmo=false;
void AmmoReloads()
{
	if(xbAmmo == false){
			xStartRouneAmmo = _My->GetAmmoIndex(ResultBaseAmmo2, PTRWeaponSize2Ammo, PTRWeaponSize1Ammo, SizeValAmmo);
	}
	if(xDepositAmmo == 0){
		xbAmmo = false;
		_My->gEtWeapon_IndexA( ResultBaseAmmo2, PTRWeaponSize2Ammo, PTRWeaponSize1Ammo, SizeValAmmo, xStartRouneAmmo);
		_My->gEtWeapon_IndexA( ResultBaseAmmo2, PTRWeaponSize2Ammo, PTRSizeHealth, SizeValAmmo, xStartRouneAmmo);
    }
	if(xDepositAmmo == 1){
		xbAmmo = true;
		_My->gEtWeapon_IndexA( ResultBaseAmmo2, PTRWeaponSize2Ammo, PTRWeaponSize1Ammo, SizeValAmmo, xStartRouneAmmo);
		_My->gEtWeapon_IndexA( ResultBaseAmmo2, PTRWeaponSize2Ammo, PTRSizeHealth, SizeValAmmo, xStartRouneAmmo);
		}}
//------------------------------------------------------------------------------> Rapid Fire
void RapidFireWeapon(){
if(RapidFire==1){
__try
{
if (*(DWORD*)(*(DWORD*)(*(DWORD*)(OFS_Ammo2)+0x544)+0x38)==1){
*(DWORD*)(*(DWORD*)(*(DWORD*)(OFS_Ammo2)+0x30)+0x5DC)=0;
*(DWORD*)(*(DWORD*)(OFS_Ammo2)+0x504)=0;
}
if (*(DWORD*)(*(DWORD*)(*(DWORD*)(OFS_Ammo2)+0x544)+0x38)==0){
*(DWORD*)(*(DWORD*)(*(DWORD*)(OFS_Ammo2)+0x30)+0x5DC)=0;
*(DWORD*)(*(DWORD*)(OFS_Ammo2)+0x504)=0;
}
} __except ( EXCEPTION_EXECUTE_HANDLER ) 
{
Sleep(38);
}
Sleep(0*5);
}
}
//----------------------------------------------------------- [[Reoland]]
void PachtChara(DWORD B,DWORD A1,DWORD B1, DWORD ISI){
DWORD A=0;
if (IsBadReadPtr((PDWORD)B,4)==0){
A=*(PDWORD)((DWORD)(B))+A1;
if (IsBadReadPtr((PDWORD )A,4)==0){
A=*(PDWORD)((DWORD)(A ))+ B1;
if (IsBadReadPtr((PDWORD)A,4)==0) {
{*(PDWORD)A=ISI;}}}}}

void Reload0DetikCACAD() {
DWORD PBExe = (DWORD)GetModuleHandleA("PointBlank.exe");
if(Reload){
c_WeaponIndex_B(PBExe + ResultBaseAmmo,0x544,0x1C, 0x30,0x67,0x41);
c_WeaponIndex_B(PBExe + ResultBaseAmmo,0x544,0x2C, 0x30,0x67,0x41); 
}}
//-----------------------------------------------------------------------------
int GetMyCharaIndex()
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA("PointBlank.exe");
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + ResultBasePlayer);
unsigned long dwBase2	= *(DWORD*)(dwI3EXEC + ResultBasePlayer-0x34);
CTeam *MyTeam = (CTeam*) ((dwBase + P_BaseTEAM));
return MyTeam->iTeam;
}
bool GetBattleState2() { 
unsigned long xBase = *(DWORD*)ResultBaseAmmo2; 
if(xBase > NULL)
{ 
return true; 
}return false; 
}
//-----------------------------------------------------------------------------
DWORD CGameCharaBaseShoot(void) 
{ 
unsigned long dwBase = *(DWORD*)ResultBasePlayer2-0x34; 
return dwBase; 
}
//---------------------------------------------------------------------------------- Fake Replace 
typedef void (__thiscall * tSetCharaWeaponSet)(DWORD CGameCharaManager,DWORD CGameCharaBase, DWORD pNetCharaInfo); 
tSetCharaWeaponSet SetCharaWeaponSet;
void FakeAbal()
{
if (FakeReplace==1){
if (GetBattleState2()){
DWORD ModuleHandle = (DWORD)GetModuleHandle("PointBlank.exe");
DWORD BasePlayer_A = *(DWORD*)(ModuleHandle + ResultBasePlayer);
DWORD BasePlayer_B = *(DWORD*)(ModuleHandle + ResultBaseHealth);
int MyIndex = GetMyCharaIndex();
DWORD CGameCharaManager = CGameCharaBaseShoot();
DWORD CGameCharaBase = *(DWORD*)(BasePlayer_B + 0x14 + (MyIndex*4));
DWORD pNetCharaInfo = BasePlayer_A + ((0x28044) + (MyIndex*0x158)); 
SetCharaWeaponSet = (tSetCharaWeaponSet)0x536470;
SetCharaWeaponSet(CGameCharaManager, CGameCharaBase, pNetCharaInfo);
}
}
}
////----------------------------------------------------------- [[B-Uyuk]]
//if(BP_NOTICE ==1){
//DWORD pBaseX = (DWORD)GetModuleHandleA("Pointblank.exe");
//_My->PrivateOnly((void *)(pBaseX + OFS_Unyu),(int*)(PBYTE)"\xC0",1);
//}
//
//
//if(BP_NOTICE ==0){
//DWORD pBaseX = (DWORD)GetModuleHandleA("Pointblank.exe");
//_My->PrivateOnly((void *)(pBaseX + OFS_Unyu),(int*)(PBYTE)"\xBE",1);
//}
//----------------------------------------------------------- [[Hot-Key]]
//if(BRUTALL==1){
//if(GetAsyncKeyState(0x01)&&0x8000){
//if(IsBadReadPtr((void*)OFS_Ammo2,4)==0)
//{
//DWORD TheRead = *(PDWORD)((DWORD)(OFS_Ammo2))+0x544;
//if(IsBadReadPtr((void*)TheRead,4)==0)
//{
//DWORD ReadKe1 = *(PDWORD)((DWORD)(TheRead))+0x38;
//if(IsBadReadPtr((void*)ReadKe1,4)==0)
//{
//*(PDWORD)ReadKe1=0x02;
//Sleep(50);
//}}}}}
//----------------------------------------------------------- [[CallSuicide]]
void KillMySelf(){
DWORD PBExeModule = (DWORD) GetModuleHandleA("PointBlank.exe");
DWORD PointerCaller = (DWORD) (PBExeModule + ResultSuicide);
DWORD BaseSuicide = *(DWORD*)(PBExeModule + ResultBaseAmmo);  
__asm 
{ 
push 0x00
push 0xFFFFFF; 
push 0xFF; 
mov ecx,[BaseSuicide]; 
call [PointerCaller];
}}
//---------------------------------------------------------------------
DWORD NewFiture(LPVOID param){
while(1)
{
//---------------------------------------------------------------------
if(RankHack==1){
DWORD dwI3EXEC			= (DWORD)GetModuleHandle("PointBlank.exe");
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + ResultBasePlayer);
CTeam		*pTeam		= ((CTeam*)(dwBase + OFS_Team)); 
int MyTeam = _My->GetTeam(pTeam->iTeam);
for (int i = 0; i <= 16 ; i++){
GM          *DualDinamic = (GM*)((dwBase + ResultSkill2)+ pTeam->iTeam * 0x2B);
HackName	*Name  = (HackName *)((dwBase + OFS_Names)+ pTeam->iTeam * 0x21);
HackName2	*Name2 = (HackName2*)((dwBase + OFS_Names + 0x4)+ pTeam->iTeam * 0x21);
HackName3	*Name3 = (HackName3*)((dwBase + OFS_Names + 0x8)+ pTeam->iTeam * 0x21);
HackName4	*Name4 = (HackName4*)((dwBase + OFS_Names + 0xC)+ pTeam->iTeam * 0x21);
DualDinamic->iRank = 0x35;
DualDinamic->iHack = 0xFFFFFF;
Name ->iName1 = 0x6B637546;
Name2->iName2 = 0x4D47;
Name3->iName3 = 0x202020;
Name4->iName4 = 0x202020;
}}
//====================== Quick Change  =====================//
if(GetBattleState1()){
if(qece==1){
PatchValue(OFS_Ammo2, 0x540, 0x3C, 0x64, 1069715291);
}}
//----------------------------------------------------------- [[NoFallDamage]]
if(NoFallDamage == 1){
PactJumper(OFS_Ammo2, 0x510, 14);
PactJumper(OFS_Ammo2, 0x510, 172);
PactJumper(OFS_Ammo2, 0x510, 4);
PactJumper(OFS_Ammo2, 0x510, 64);
}
//====================== Freeze Respawn =====================//
if(FreezeRespawn)
{
PatchValue(OFS_Ammo2, 0x18, 0x18, 0xE8, 1069715291);
PatchValue(OFS_Ammo2, 0x18, 0x18, 0xE8, 1069715291);
PatchValue(OFS_Ammo2, 0x18, 0x18, 0xE8, 1069715291);
PatchValue(OFS_Ammo2, 0x18, 0x18, 0xE8, 1069715291);
}
//========================================================================//
///----------------------------------------------------------- [[Invicebel]]
#define OFS_Invicible       0x62E1CC
if(BP_Invi ==1){
DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD GM = ModulePB + OFS_Invicible;
_My->PrivateOnly((void *)(GM),(int*)(PBYTE)"\x6F\x12\x83\x40",4);
}
if(BP_Invi ==0){
DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD GM = ModulePB + OFS_Invicible;
_My->PrivateOnly((void *)(GM),(int*)(PBYTE)"\x6F\x12\x83\x3C",4);
}
//====================================================== [Magnet]]]///----------
if(GetBattleState1()){
if(Magnet ==1){
DWORD Frameon= (DWORD)LoadLibraryA("i3FrameWorkDx.dll");
_My->PrivateOnly((void *)(Frameon + 0xADD8D),(int*)(PBYTE)"\xC0\x63",2);
}
if(Magnet ==0){
DWORD Frameoff= (DWORD)LoadLibraryA("i3FrameWorkDx.dll");
_My->PrivateOnly((void *)(Frameoff + 0xADD8D),(int*)(PBYTE)"\xC0\x30",2);
}}
//====================== Jump Hight =====================//
if(JumpHight==1){ 
if (GetAsyncKeyState(VK_SPACE))
{
__try
{
*(DWORD*)(*(DWORD*)(OFS_Ammo2) + 0x500) = 8;
}__except (EXCEPTION_EXECUTE_HANDLER){
}
}
}
//======================================================//
if(GetBattleState1()){
if(Magnet ==1){
DWORD Frameon= (DWORD)LoadLibraryA("i3FrameWorkDx.dll");
_My->PrivateOnly((void *)(Frameon + 0xADD8D),(int*)(PBYTE)"\xC0\x63",2);
}
if(Magnet ==0){
DWORD Frameoff= (DWORD)LoadLibraryA("i3FrameWorkDx.dll");
_My->PrivateOnly((void *)(Frameoff + 0xADD8D),(int*)(PBYTE)"\xC0\x30",2);
}}
////----------------------------------------------------------- [[No Recoil]]
if (NoRecoil == 1) { 
for (int i6 = 32; i6 <= 108; i6 += 4 ) 
WeaponHack2(OFS_Ammo2, 0x558, i6, 0); }
if(NoFallDamage==1)
{
_patchPTRZ(OFS_Ammo2, 0x513, 14); 
_patchPTRZ(OFS_Ammo2, 0x513, 172); 
_patchPTRZ(OFS_Ammo2, 0x513, 4); 
_patchPTRZ(OFS_Ammo2, 0x513, 64);
}
//----------------------------------------------------------- [[Wallshot]]
if(Wallbug ==1){ //ON
DWORD pBaseX = (DWORD)GetModuleHandleA("NxCharacter.2.8.1.dll");
_My->PrivateOnly((void *)(pBaseX + 0x6510),(int*)(PBYTE)"\xFF",1);
}
if(Wallbug ==0){//OFF
DWORD pBaseX = (DWORD)GetModuleHandleA("NxCharacter.2.8.1.dll");
_My->PrivateOnly((void *)(pBaseX + 0x6510),(int*)(PBYTE)"\x89\x8B\x34\x01\x00\x00\x89\x93\x38\x01\x00\x00\x89\x83\x3C\x01",16);
}
//------------------------------------------------------------------------
if(WShoot ==1){ DWORD Pointblank = (DWORD)LoadLibraryA("Pointblank.exe"); 
_My->PrivateOnly((void *)(Pointblank + ResultWallShot),(int*)(PBYTE)"\x90\x90",2);
}
if(WShoot ==0){ DWORD Pointblank = (DWORD)LoadLibraryA("Pointblank.exe"); 
_My->PrivateOnly((void *)(Pointblank + ResultWallShot),(int*)(PBYTE)"\x75\x1F",2);
}
//------------------------------------------------------------------------
Sleep(0.5);
}
return 0;
}
//-----------------------------------------------------------------------------------------> Replace Granade
DWORD WINAPI NayzReplace(LPVOID param){
Nay_Item:
//--------------------------------------------------------------------> Soccer Granade
if(Rep_Item)
{
////--------------------------------------------------------------------> Candy Granade
if(Rep_Item == 1){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), 0x35E20D6C);
}}
////--------------------------------------------------------------------> Ammo Kukri
if (Kukri==1) { 
unsigned long PtrRB = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{ 
MakePoint(OFS_Player2, ResultMelee + (GetSlot->iTeam * 0x158), 0x29D7AF6C);
}}
//====================== LC =====================//

if (LC==1) { 
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2); 
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{ 
REPALCE(ResultBasePlayer2, ResultPrimary + (GetSlot->iTeam * 0x158), 0x23D2902A);
}}
////--------------------------------------------------------------------> Lantern Grenade
if(Rep_Item == 2){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), 0x35E20D6F);
}}}
//-----------------------------------------------------------------------------------------> Replace Launcher 
if(R_Launcher)
{if(R_Launcher == 1){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, ResultPrimary + (GetSlot->iTeam * 0x158), 0x5F61F82);
}}}
//--------------------------------------------------------------------> Famas Launcher 
if(R_Brutal == 1){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + P_BaseTEAM);{
MakePoint(ResultBasePlayer2, 0x28178 + (GetSlot->iTeam * 0x158), 0x5F5ECEC);
}}
//--------------------------------------------------------------------> K-201 Exit
if(R_Brutal == 2){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + P_BaseTEAM);{
MakePoint(ResultBasePlayer2, 0x28178 + (GetSlot->iTeam * 0x158), 0x5F5ECC3);
}}
//--------------------------------------------------------------------> AK 47 FC
if(R_Brutal == 3){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + P_BaseTEAM);{
MakePoint(ResultBasePlayer2, 0x28178 + (GetSlot->iTeam * 0x158), 0x5F5ECF2);
}}
//--------------------------------------------------------------------> AK Sopmod R
if(R_Brutal == 4){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + P_BaseTEAM);{
MakePoint(ResultBasePlayer2, 0x28178 + (GetSlot->iTeam * 0x158), 0x5F5ECFC);
}}
//--------------------------------------------------------------------> SCAR D
if(R_Brutal == 5){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + P_BaseTEAM);{
MakePoint(ResultBasePlayer2, 0x28178 + (GetSlot->iTeam * 0x158), 0x5F5ED18);
}}
//--------------------------------------------------------------------> HK-69
if(R_Secondary == 1){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + P_BaseTEAM);{
MakePoint(ResultBasePlayer2, 0x2817C + (GetSlot->iTeam * 0x158), 0x23D2902A);
}}//--------------------------------------------------------------------
goto Nay_Item;
}
//---------------------------------------------------------------------------