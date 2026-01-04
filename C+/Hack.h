//-------------------------------------------------------------------------------------------------------------||
//------------------------------------|| DISUSUN OLEH HELJUNAI SYAHPUTRA ||------------------------------------||
//-------------------------------------------------------------------------------------------------------------||
#include <windows.h>
#include "File.h"
#include "XStr.h"
//----------------------------------------------------------------------------------
Semprul	*_My = NULL;
LPTSTR PointBlankSTR4 = "PointBlank.exe";
//----------------------------------------------------------------------------------
int Norespawn,xxAccuracy,move,FileLine,CallAImFunc,Tsung,Tsung2,TsungHS,Tsung5 = NULL;
int xAccuracy;
int ESPHealth1,JumpHight,FallDamage = NULL;
int AimBodyf,BP_Invi = NULL;
int Protect,Unyu =0;
int Bug,WShoot,ReplaceCCD2,ZombieCall = NULL;
int AimBodyi;
int DamagePisoTeleKill = NULL;
int PisoTeleKill1 = NULL;
int BOMKILLER = NULL;
int DamagePisoTeleKill1 = NULL;
int AntiIdle = NULL;
int xDepositAmmo = NULL;
int SubMacineGun = NULL;
int Assault,MeleeHack,Shotgun,Sniper,SMG = NULL;
int FastShoot,StatusHotKey = NULL;
int FreeMove,RespawnTerus = NULL;
int PlayerNameV2 = NULL;
int HiddenWeapon = NULL;
int CallAmmo,Magnet,R_Granad = NULL;
int Zombiekillersz = NULL;
int Mini_1,Mini_2,Mini_3;
int MiniMized = 0;
int FSpeed = NULL;
int HeadLock = NULL;
int TeleKontol = NULL;
int AimCrotMode,AimCrotModeFake,DepositAmmo = NULL;
int CallAimCrotMode = NULL;
int WallCrot,BrustKnife = NULL;
int WhRobot = NULL;
int AimBodyc = NULL;
int HeadPink = NULL;
int BulletKiller = NULL;
int HeadPink2 = NULL;
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
int ChamsCT2,Gravity = NULL;
int Weapon = NULL;
int chamsWeapon = NULL;
int chamsWeapon2 = NULL;
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
int TransAmmo = 0;
int ControlFade = 0;
int NoFog = NULL;
int qece=0;
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
int ReplaceAWP,SocerGranade = NULL;
int ReplaceSG = NULL;
int ReplaceSMG = NULL;
int FastKnife = NULL;
int Knife = NULL;
int GhostExit = NULL;
int AutoRedyGB = NULL;
int AutoOutGB = NULL;
int ShowName = NULL;
int AutoShoot,CandyGrenade = NULL;
int RepeatCall = NULL;
int AutoHS = NULL;
int FlyHack,ReplaceRPG = NULL;
int UltimateAmmo,ChocolateGrenade = NULL;
int ModeFloodVoteKick = NULL;
int FiturRusuh = NULL;
int DecoyBoms = NULL;
int KetupatBoms = NULL;
int CrossEnds = NULL;
int Cross,DecoyBomb = NULL;
int WireFrame = NULL;
int Reload;
int WpSmoke = NULL;
int DinoSpam = NULL;
int Quick = NULL;
int AimDatar = NULL;
int RPG, aRPG = NULL;
//-------------------------------------------
int FakeReplace=0;
int	Rep_Item=0;
int R_Launcher=0;
//-------------------------------------------
int SuicideTruz = NULL;
int StringHacker = 1;
int RenderText = 1;
int HideMenu = 1;
int TargetPelor = NULL;
int PelorSetan = NULL;
int ESPBone = NULL;
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
DWORD BackupEDXTele,Ghoster,BackupEDXTeleTod,ReadHSC,ReadHSD,ReadHSF,ReadHSE,ReadHSG,ReadHSH,
ReadDMGA,ReadDMGB,XL,ReadDMGC,ReadDMGD,ReadDMGE,ReadDMGF,ReadDMGG,ReadDMGH,ReadBYPASSKACA,ReadBYPASSD,
ReadBYPASSKELA,ReadBYPASSKELB,ReadBYPASSKELC,ReadBYPASSKELD,ReadBYPASSKELE,ReadBYPASSKELF,ReadBYPASSKELG,ReadBYPASSKELH;
bool bBetrayer = false;
bool bGExit = false;
bool Bbetrayer = true;
bool BGExit = true;
bool Shot = false;
bool HookedShot = false;
int CallReplace = NULL;
bool bGhost = false;
bool Keprok,Keprox = false;
bool bPiso = false;
bool xPiso = false;
bool bGhoster = false;
static BOOL sprite = TRUE;  
//----------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------> Fast Reload
void PachtChara(DWORD B,DWORD A1,DWORD B1, DWORD ISI){
DWORD A=0;
if (IsBadReadPtr((PDWORD)B,4)==0){
A=*(PDWORD)((DWORD)(B))+A1;
if (IsBadReadPtr((PDWORD )A,4)==0){
A=*(PDWORD)((DWORD)(A ))+ B1;
if (IsBadReadPtr((PDWORD)A,4)==0) {
{*(PDWORD)A=ISI;}}}}}
//----------------------------------------------------------------------------------
void Reload0DetikCACAD() {
DWORD PBExe = (DWORD)GetModuleHandleA("PointBlank.exe");
if(Reload){
c_WeaponIndex_B(PBExe + g_pPelorReload,0x544,0x1C, 0x30,0x67,0x41);
c_WeaponIndex_B(PBExe + g_pPelorReload,0x544,0x2C, 0x30,0x67,0x41); 
}}
//----------------------------------------------------------------------------- Fake Replace 
int GetMyCharaIndex()
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA("PointBlank.exe");
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + OFS_Player);
unsigned long dwBase2	= *(DWORD*)(dwI3EXEC + OFS_Player-0x34);
CTeam *MyTeam = (CTeam*) ((dwBase + OFS_TEAM));
return MyTeam->iTeam;
}
//-----------------------------------------------------------------------------
DWORD CGameCharaBaseShoot(void) 
{ 
unsigned long dwBase = *(DWORD*)OFS_Player2-0x34; 
return dwBase; 
}
//---------------------------------------------------------------------------------- 
typedef void (__thiscall * tSetCharaWeaponSet)(DWORD CGameCharaManager,DWORD CGameCharaBase, DWORD pNetCharaInfo); 
tSetCharaWeaponSet SetCharaWeaponSet;
void FakeCyberAngels()
{
if (FakeReplace==1){
if (GetBattleState1()){
DWORD ModuleHandle = (DWORD)GetModuleHandle("PointBlank.exe");
DWORD BasePlayer_A = *(DWORD*)(ModuleHandle + OFS_Player);
DWORD BasePlayer_B = *(DWORD*)(ModuleHandle + OFS_Health);
int MyIndex = GetMyCharaIndex();
DWORD CGameCharaManager = CGameCharaBaseShoot();
DWORD CGameCharaBase = *(DWORD*)(BasePlayer_B + 0x14 + (MyIndex*4));
DWORD pNetCharaInfo = BasePlayer_A + ((0x28044) + (MyIndex*0x158));
SetCharaWeaponSet = (tSetCharaWeaponSet)0x536340;
SetCharaWeaponSet(CGameCharaManager, CGameCharaBase, pNetCharaInfo);
}}
}
//----------------------------------------------------------------------------------> Suicide
void CallSuicide(){
DWORD PBExeModule = (DWORD) GetModuleHandleA("PointBlank.exe");
DWORD PointerCaller = (DWORD) (PBExeModule + OFS_Suicide);
DWORD BaseSuicide = *(DWORD*)(PBExeModule + g_pPelorReload);  
__asm 
{ 
push 0x00
push 0xFFFFFF; 
push 0xFF; 
mov ecx,[BaseSuicide]; 
call [PointerCaller];
}}
//----------------------------------------------------------------------------------
DWORD WINAPI Pemanggil_Fiture(LPVOID param){
while(1){
//----------------------------------------------------------------------------------> Rank Skill
if(Norespawn)
{
DWORD BasePlayer = *(DWORD *)c_pPlayerBase;
CTeam *GetCSlot		= ((CTeam*)(BasePlayer + P_BaseTEAM)); 
for (int iSlot = 0; iSlot<=16;iSlot++)
{
GM	*DualDinamic = (GM*)((BasePlayer + OFS_RANK2)+ GetCSlot->iTeam * 0x2B);
if(Norespawn==1){
DualDinamic->iRank = 0x30;//b3
DualDinamic	->iHack = 0xFFFF;
}
if(Norespawn==2){
DualDinamic->iRank = 0x31;//b4
DualDinamic	->iHack = 0xFFFF;
}
if(Norespawn==3){
DualDinamic->iRank = 0x32;//b5
DualDinamic	->iHack = 0xFFFF;
}
if(Norespawn==4){
DualDinamic->iRank = 0x33;//b5 gold
DualDinamic	->iHack = 0xFFFF;
}
if(Norespawn==5){
DualDinamic->iRank = 0x34;//bom
DualDinamic	->iHack = 0xFFFF;
}
if(Norespawn==6){
DualDinamic->iRank = 0x35;//GM
DualDinamic	->iHack = 0xFFFF;
}
}}
//--------------------------------------------------------------------------------- QC
if(qece==1){
WeaponHack1(OFS_Ammo2, 0x540, 0xEC, 0x64, 1069715291);
}
//---------------------------------------------------------------------------------- Protec Program Ilegal
//---------------------------------------------------------------------------------- Invicible Time
//---------------------------------------------------------------------------------- Bug Unyu-Unyu
//---------------------------------------------------------------------------------- Fast Reload Pistol
//----------------------------------------------------------------------------------> Wallshoot
//---------------------------------------------------------------------------------- Unlimited Ammo Weapon
//----------------------------------------------------------------------------------
if(xAccuracy == 1){
if(GetAsyncKeyState(VK_LBUTTON)){
xAccuracy = 1;
}else {
xAccuracy = 0;
}}
if(Accuracy==1){
if(GetAsyncKeyState(VK_CAPITAL)){
Accuracy = !Accuracy;Beep(2000,200);}}
Sleep(0.5);
}
return 0;
}