#include <windows.h>
#include <winbase.h>
#include "NFCZ_FUNCTION.h"

int WallHack = NFCZ;
int CROSS    = NFCZ;
int NOSMOKE  = NFCZ;

//--------------------------------------------------------------------
int ESPBone = NFCZ;
int ESPHead = NFCZ;
int ESPLine = NFCZ;
int ESPHealth = NFCZ;
int ESPName = NFCZ;
int ESPDistance = NFCZ;
int ESPBox = NFCZ;
int ESPObserver = NFCZ;
//--------------------------------------------------------------------
int NoLife = NFCZ;
int WallShot = NFCZ;
int PlantBomb = NFCZ;
int ZombieCall = NFCZ;
int Invincible = NFCZ;
int SuicideCall = NFCZ;
int GameFastExit = NFCZ;
int RapidFire = NFCZ;
//--------------------------------------------------------------------
int Ammo = NFCZ;
int Quick = NFCZ;
int NoRecoil = NFCZ;
int FakeReplace = NFCZ;
int FSpeed = NFCZ;
int BrustKnife = NFCZ;
int FastReload = NFCZ;
//--------------------------------------------------------------------
int WallBug = NFCZ;
int RankHack = NFCZ;
int DeathFly = NFCZ;
int BugUnyuk = NFCZ;
//--------------------------------------------------------------------
int AimLock = NFCZ;
int AimBullet = NFCZ;
int AimHead = NFCZ;
int AimBody, BoneIndexSelector = NFCZ;
//--------------------------------------------------------------------
int ReplaceRPG = NFCZ;
int HK = NFCZ;
int ReplaceSmoke = NFCZ;
int SmokeCall = NULL;
int DamageCall = NULL;
int DAMAGESMOKE =  NULL;
//--------------------------------------------------------------------
int BombCall = NULL;
int DamageBombCall = NULL;
//--------------------------------------------------------------------
int BulletCall = NULL;
int DamageBulletCall = NULL;

int BulletPistol = NULL;
int DamageBulletPistol = NULL;

int BulletPiso = NULL;
int DamageBulletPiso = NULL;
//--------------------------------------------------------------------
bool Shot = false;
bool bAmmo = false;
bool bPiso = false;
bool Keprox = false;
bool bGhoster = false;
DWORD StartRouneAmmo, StartRouneAmmo2, PisoGila, Ghoster;
//--------------------------------------------------------------------
int GetTeam(char MyTeam){
for(int i = 0; i < 16; i+=2)
if(i == MyTeam)return 2;
for(int i = 1; i < 16; i+=2)
if(i == MyTeam)return 1;
return -1;
}
//--------------------------------------------------------------------
void BrustKnifeXX(void){
if(bPiso == false){
PisoGila = TestPacth(ResultBaseAmmo2, ResultPTRAmmo, ALIVESIZE, 0xC9C);
}
if(BrustKnife==0){
bPiso = false;
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, ALIVESIZE, 0xC9C, PisoGila);
}
if(BrustKnife == 1){
bPiso = true;
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, ALIVESIZE, 0xC9C, PisoGila);
}
}
//--------------------------------------------------------------------
void AmmoReload(void){
if(bAmmo == false){
StartRouneAmmo  = GetAmmoIndex(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0xCA8);
StartRouneAmmo2 = GetAmmoIndex(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0xCA8);	
}
if(Ammo == 0){
bAmmo = false;
GetWeapon_IndexA(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0xCA8, StartRouneAmmo);
GetWeapon_IndexA(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0xCA8, StartRouneAmmo2);
}
if(Ammo == 1){
bAmmo = true;
GetWeapon_IndexA(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0xCA8, StartRouneAmmo);
GetWeapon_IndexA(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0xCA8, StartRouneAmmo2);
}
}

//--------------------------------------------------------------------
typedef void (__thiscall * tCmd_Mati)(DWORD CGameCharaLocalBase, int HPDrain, int a2, int a3);
tCmd_Mati Cmd_Mati;
//--------------------------------------------------------------------
typedef void (__thiscall * tCmd_Damage)(DWORD CGameCharaLocalBase, int HPDrain, int a2, int a3);
tCmd_Damage Cmd_Damage;
//--------------------------------------------------------------------
void BunuhDiri(){
DWORD ModuleHandle = (DWORD)GetModuleHandleA("PointBlank.exe");
Cmd_Mati = (tCmd_Mati)(ModuleHandle + ResultSuicide);
DWORD CGameCharaLocalBase = *(DWORD*)(ModuleHandle + ResultBaseAmmo);
Cmd_Mati(CGameCharaLocalBase,0xFF,0xFFFF,false);
}
//--------------------------------------------------------------------
void Suicide(){
if(SuicideCall){
DWORD ModuleHandle = (DWORD)GetModuleHandleA("PointBlank.exe");
Cmd_Damage = (tCmd_Damage)(ModuleHandle + ResultSuicide);
DWORD CGameCharaLocalBase = *(DWORD*)(ModuleHandle + ResultBaseAmmo);
Cmd_Damage(CGameCharaLocalBase,0xFF,0xFFFF,false);
}
}
//--------------------------------------------------------------------
bool bGhost=false;




DWORD GHOST_Hacks()
{
while(1){
if(GetBattleState1())
			{
unsigned long dwBase	= *(DWORD*)ResultBasePlayer2;
unsigned long dwBase2	= *(DWORD*)ResultBaseHealth2;	
CTeam		*GetSlot	= (CTeam*)(dwBase + OFS_Team);
CHealth		*GetHealth	= (CHealth*)((dwBase2 + PTR_HEALTH) + GetSlot->iTeam * ALIVESIZE);

if(bGhost == false)		
Ghoster					= ReadFunct( ResultBaseHealth2, PTR_GHOST + GetSlot->iTeam * ALIVESIZE);

if(GetHealth->CurHP > 0)
{

if(ZombieCall==0){
bGhost = false;
MakePoint( ResultBaseHealth2, PTR_GHOST + GetSlot->iTeam * ALIVESIZE, Ghoster);
}
if(ZombieCall==1){
BunuhDiri();
bGhost = true;
MakePoint( ResultBaseHealth2, PTR_GHOST + GetSlot->iTeam * ALIVESIZE, Ghoster-1);
}

if(GetHealth->CurHP < 0){
bGhost = false;
MakePoint( ResultBaseHealth2, PTR_GHOST + GetSlot->iTeam * ALIVESIZE, Ghoster);
}

}
}

Sleep(0.5);
}
return 0;
}
void FastReloadWeapon() {
DWORD PBExe = (DWORD)GetModuleHandleA("PointBlank.exe");
if(FastReload){
c_WeaponIndex_B(PBExe + ResultBaseAmmo,ResultPTRAmmo,0x1C, 0x30,0x67,0x41);
c_WeaponIndex_B(PBExe + ResultBaseAmmo,ResultPTRAmmo,0x2C, 0x30,0x67,0x41); 
}


//--------------------------------------------------------------------
if (NoRecoil == 1) { 
for (int i6 = 0x20; i6 <= 0x50; i6 += 4 ) 
WeaponHack2(ResultBaseAmmo2, ResultNorecoil, i6, 0x00000000); 
}
//--------------------------------------------------------------------
if(Quick == 1){
PacthWeapone(ResultBaseAmmo2, ResultPTRAmmo, 0xEC, 0x64, 1069715291);
}
//--------------------------------------------------------------------



	
	}
//--------------------------------------------------------------------
void FakeEvolution() ;
//--------------------------------------------------------------------
DWORD  NNCZHack(){
while(1){
if(RankHack==1){
DWORD dwI3EXEC			= (DWORD)GetModuleHandle("PointBlank.exe");
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + ResultBasePlayer);
CTeam		*pTeam		= ((CTeam*)(dwBase + OFS_Team)); 
int MyTeam = GetTeam(pTeam->iTeam);
for (int i = 0; i <= 16 ; i++){
GM          *DualDinamic = (GM*)((dwBase + ResultSkill2)+ pTeam->iTeam * 0x2B);
HackName	*Name  = (HackName *)((dwBase + 0x295D4)+ pTeam->iTeam * NAMESIZE);
HackName2	*Name2 = (HackName2*)((dwBase + 0x295D4 + 0x4)+ pTeam->iTeam * NAMESIZE);
HackName3	*Name3 = (HackName3*)((dwBase + 0x295D4 + 0x8)+ pTeam->iTeam * NAMESIZE);
HackName4	*Name4 = (HackName4*)((dwBase + 0x295D4 + 0xC)+ pTeam->iTeam * NAMESIZE);
DualDinamic->iRank = 0x33;
DualDinamic->iHack = 0xFFFFFF;
Name ->iName1 = 0x5D4D475B;
Name2->iName2 = 0x5A434E4E;
Name3->iName3 = 0x20202020;
Name4->iName4 = 0x202020;
}
}
//if(Invincible ==1){
//DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
//DWORD GM = ModulePB + ResultInvincible;
//PrivateOnly((void *)(GM),(int*)(PBYTE)"\x6F\x12\x83\x40",4);
//}
//if(Invincible ==0){
//DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
//DWORD GM = ModulePB + ResultInvincible;
//PrivateOnly((void *)(GM),(int*)(PBYTE)"\x6F\x12\x83\x3C",4);
//}
//--------------------------------------------------------------------
if(WallShot ==1){ DWORD Pointblank = (DWORD)LoadLibraryA("Pointblank.exe"); 
PrivateOnly((void *)(Pointblank + ResultWallShot),(int*)(PBYTE)"\x90\x90",2);
}
if(WallShot ==0){ DWORD Pointblank = (DWORD)LoadLibraryA("Pointblank.exe"); 
PrivateOnly((void *)(Pointblank + ResultWallShot),(int*)(PBYTE)"\x75\x1F",2);
}
//////--------------------------------------------------------------------
	

//--------------------------------------------------------------------
Sleep(10);
}
return 0;
}
//--------------------------------------------------------------------
DWORD WINAPI NNCZReplace(LPVOID param){
NNCZReplaceON:
//--------------------------------------------------------------------
if(ReplaceSmoke){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * WEAPSIZE), 0x35E20D79);//soccer
}
}
//--------------------------------------------------------------------
if (ReplaceRPG == 1){

int i;
for (i = 0 ; i <= 16 ; i++){
DWORD BasokaRep = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(BasokaRep + ResultBasePlayer, ResultPrimary + (i*0x158), /*0x23D2902A);*/0x5F61F82); 

}

}
if (ReplaceRPG == 2){

int i;
for (i = 0 ; i <= 16 ; i++){
DWORD BasokaRep = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(BasokaRep + ResultBasePlayer, ResultPrimary + (i*0x158), /*0x23D2902A);*/0x5F5ECF2); 

}

}
if (ReplaceRPG == 3){

int i;
for (i = 0 ; i <= 16 ; i++){
DWORD BasokaRep = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(BasokaRep + ResultBasePlayer, ResultPrimary + (i*0x158), /*0x23D2902A);*/0x5F5ECFC); 

}

}
if (ReplaceRPG == 4){

int i;
for (i = 0 ; i <= 16 ; i++){
DWORD BasokaRep = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(BasokaRep + ResultBasePlayer, ResultPrimary + (i*0x158), /*0x23D2902A);*/0x5F5ED18); 

}
}
if (HK == 1){

int i;
for (i = 0 ; i <= 16 ; i++){
DWORD BasokaRep = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(BasokaRep + ResultBasePlayer, 0x2817C + (i*0x158), /*0x23D2902A);*/0x23D2902A); 

}
}
//--------------------------------------------------------------------
goto NNCZReplaceON;
}

typedef void (__thiscall * tSetCharaWeaponSet)(DWORD CGameCharaManager,DWORD CGameCharaBase, DWORD pNetCharaInfo); 
tSetCharaWeaponSet SetCharaWeaponSet; 

DWORD CGameCharaBaseShoot(void) 
{ 
unsigned long dwBase = *(DWORD*)ResultBaseHealth2;//2
return dwBase;
} 

int GetMyCharaIndex2() 
{ 
DWORD dwI3EXEC = (DWORD)GetModuleHandleA("PointBlank.exe"); 
unsigned long dwBase = *(DWORD*)(dwI3EXEC + ResultBasePlayer); 
unsigned long dwBase2 = *(DWORD*)(dwI3EXEC + ResultBaseHealth2); 
CTeam *MyTeam = (CTeam*) ((dwBase + OFS_Team)); 
return MyTeam->iTeam; 
} 

void FakeEvolution() 
{ 

if (FakeReplace==1){ 
if (GetBattleState1()){ 
DWORD ModuleHandle = (DWORD)GetModuleHandle("PointBlank.exe"); 
DWORD BasePlayer_A = *(DWORD*)(ModuleHandle + ResultBasePlayer); 
DWORD BasePlayer_B = *(DWORD*)(ModuleHandle + ResultBaseHealth); 
int MyIndex = GetMyCharaIndex2(); DWORD CGameCharaManager = CGameCharaBaseShoot(); 
DWORD CGameCharaBase = *(DWORD*)(BasePlayer_B + 0x14 + (MyIndex*4)); 
DWORD pNetCharaInfo = BasePlayer_A + ((ResultRespawn2) + (MyIndex*0x158)); 
SetCharaWeaponSet = (tSetCharaWeaponSet)ResultFake; 
SetCharaWeaponSet(CGameCharaManager, CGameCharaBase, pNetCharaInfo); 
	}
	}
	}
void _Fitur_RapidFire(){
//=========================================//
//             FITUR FIRESPEED             // 
//=========================================//

	if(RapidFire==1)
	{ 

	if(GetAsyncKeyState(0x01)){
	__try 
		{ 
		if (*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+ResultPTRAmmo)+0x38)==1)
			{
			*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30)+0x5D4)=0;
			*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0; } if (*(DWORD*)
				(
				*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+ResultPTRAmmo)+0x38)==0)
				{ 
				*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30)+0x5D4)=0; 
				*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0; 
				} 
	}__except (EXCEPTION_EXECUTE_HANDLER ) 
	{
	Sleep(100);

		}
	} 
	} 
Sleep(0*5); 
	}