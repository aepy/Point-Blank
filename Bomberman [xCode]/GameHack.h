#include <windows.h>
#include <winbase.h>
#include "Function.h"
int AmmoSmoke = NFCZ;
int AmmoBomb = NFCZ;
int BombKiller = NFCZ;
int AutoFire = NFCZ;
int DamageBomb = NFCZ;
int BullKill = NFCZ;
int FreeMove = NFCZ;
int Leopard = NFCZ;
int AutoKillerz = NFCZ;
int AKillerz = NFCZ;
int FrameRate = NFCZ;
int ChamsWeapon = NFCZ;
int FakeSyechrul = NFCZ;
int AutoShot = NFCZ;
int FakeDinan = NFCZ;
int FakeSyechrulCCD = NFCZ;
int SyechrulBrutal = NFCZ;
int DinanBrutal = NFCZ;
int VoteKick = NFCZ;
int OnAutoKiller= NFCZ;
int FastKill = NFCZ;
int FastKill1 = NFCZ;
int AutoKiller=NFCZ;
int AmmoRPG = NFCZ;
int AmmoHK = NFCZ;
int AmmoLC = NFCZ;
int RPGBrutal = NFCZ;
int R_Melee = NFCZ;
int FolderALL= NFCZ;
int KillerKey = NFCZ;
int Killer=NFCZ;
int FakeAbal = NFCZ;
int BULLETPASS = NFCZ;
int Info1=NFCZ;
int Info2=NFCZ;
int Info3=NFCZ;
int Info4=NFCZ;
int Info5=NFCZ;
int Info6=NFCZ;
int HiddenWeapon = NFCZ;
int WHRobot = NFCZ;
int Time = NFCZ;
int Date = NFCZ;
int DontFog = NFCZ;
int PlantBomb = NFCZ;
int WallHack = NFCZ;
int CROSS    = NFCZ;
int NOSMOKE  = NFCZ;
int ChamsTR  = NFCZ;
int ChamsCT = NFCZ;
int ChamsTR2 = NFCZ;
int Tutorial = NFCZ;
int Folder1 = NFCZ;
int Folder2 = NFCZ;
int Folder3 = NFCZ;
int Folder4 = NFCZ;
int Folder5 = NFCZ;
int Folder6 = NFCZ;
int ChamsRainbow = NFCZ;
int Folder7 = NFCZ;
int Folder8 = NFCZ;
int Folder9 = NFCZ;
int Folder10 = NFCZ;
int BulletDinan = NULL;
//--------------------------------------------------------------------
int ESPBone = NFCZ;
int ESPHead = NFCZ;
int ESPLine = NFCZ;
int ESPHealth = NFCZ;
int CallTele = NFCZ; 
int ESPName = NFCZ;
int ESPDistance = NFCZ;
int ESPBox = NFCZ;
int ESPObserver = NFCZ;
//--------------------------------------------------------------------
int NoLife = NFCZ;
int WallShot = NFCZ;
int ZombieCall = NFCZ;
int Invincible = NFCZ;
int Magnet = NFCZ;
int SuicideCall = NFCZ;
int GameFastExit = NFCZ;
int RapidFire = NFCZ;
int BULLETKILL = NFCZ;
//--------------------------------------------------------------------
int Ammo = NFCZ;
int QuickChange = NFCZ;
int NoRecoil = NFCZ;
int FakeReplace = NFCZ;
int BrustKnife = NFCZ;
int FastReload = NFCZ;
int AntiOut = NFCZ;
//--------------------------------------------------------------------
int Wallbug = NFCZ;
int RankHack = NFCZ;
int DeathFly = NFCZ;
int BugUnyu = NFCZ;
int BugLuxivile = NFCZ;
int NoFallDamage = NFCZ;
int FreePlantA = NFCZ;
int JumpHight = NFCZ;
int flash = NFCZ;
//--------------------------------------------------------------------
int AimLock = NFCZ;
int AimBullet = NFCZ;
int AimHead = NFCZ;
int AimBody, BoneIndexSelector = NFCZ;
int AimBodyi = NFCZ;
//--------------------------------------------------------------------
int ReplaceRPG = NFCZ;
int ReplaceRPG2 = NFCZ;
int R_Launcher = NFCZ;
int R_Secondary = NFCZ;
int R_Mele = NFCZ;
int OnRpg = NFCZ;
int Rpg = NFCZ;
int Rep_Item = NFCZ;
int SmokeCall = NULL;
int DamageCall = NULL;
int DAMAGESMOKE =  NULL;
int Bomberman = NFCZ;
//--------------------------------------------------------------------
int BombCall = NULL;
int DamageBombCall = NULL;
int BP_Invi=NFCZ;
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
DWORD StartRouneAmmo, StartRouneAmmo2,StartRouneAmmo3, PisoGila, Ghoster;
//--------------------------------------------------------------------
DWORD FrameDX= (DWORD)LoadLibraryA("i3FrameWorkDx.dll"); 
DWORD ModulePB = (DWORD)LoadLibraryA("PointBlank.exe"); 
DWORD pBaseX = (DWORD)GetModuleHandleA("NxCharacter.2.8.1.dll");
//---------------------------------------------------------------------
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
void SetEvent(int param1, int param2, int param3)
{
	DWORD BaseECX = *(DWORD*)(ResultBasePlayer2);
	__asm
	{
		push 0
		push 0
		push 0
		push param3
		push param2
		push param1
		mov ecx, [BaseECX]
		call ResultSetEvent
	}
}
/*---------------------------------------- Declaration Vote Kick ----------------------------------------------------*/
void VKick()
{
	if (GetBattleState1())
	{
		for(int i = 0; i<=15; i++) 
		{
		int iSlot = GetMyCharaIndex();
		if(iSlot == i)continue;
		int P1=iSlot+1;
		int P2=iSlot+1;
		SetEvent(0xA0,(int)&P1,(int)&P2);//const class CCharaInfo *__thiscall CharaInfoDataBase::getCharaInfo(int) <-- GhostExit Packet
		Sleep(500);
		}
	}
}
DWORD Func_VKick()
{
	if(VoteKick==1)
		VKick();
	return 0;
}
//--------------------------------------------------------------------
void AmmoReload(void){
if(bAmmo == false){
StartRouneAmmo  = GetAmmoIndex(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0xCA8);
StartRouneAmmo2 = GetAmmoIndex(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0xCA8);
StartRouneAmmo3 = GetAmmoIndex(ResultBaseAmmo2, ResultPTRAmmo, 0x28, 0xCA8);
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
for( int iR = 32; iR <= 108; iR += 4 )
WeaponHack2(ResultBaseAmmo2, ResultNorecoil, iR, 0); 
}
//--------------------------------------------------------------------
if(QuickChange == 1){
PacthWeapone(ResultBaseAmmo2, ResultQuick, 0x3C, 0x64, 1069715291);
}


//--------------------------------------------------------------------
//--------------------------------------------------------------------
		if(JumpHight==1){
	if (GetAsyncKeyState(VK_SPACE)&&0x8000){
	{
	if(IsBadReadPtr((void*)ResultBaseAmmo2,4)==0){
	DWORD TheRead = *(PDWORD)((DWORD)(ResultBaseAmmo2))+PTR_JumpHigh;
	if(IsBadReadPtr((void*)TheRead,4)==0){
	DWORD ReadKe1 = *(PDWORD)((DWORD)(TheRead))+0x98;
	DWORD ReadKe2 = *(PDWORD)((DWORD)(TheRead))+0x9C;
	if(IsBadReadPtr((void*)ReadKe1,4)==0){
	*(PDWORD)ReadKe1=0x00000000;}
	if(IsBadReadPtr((void*)ReadKe2,4)==0){
	*(PDWORD)ReadKe2=0x00000000;
	}}}}}}
//------------------------------------------------------------------------

}
//--------------------------------------------------------------------
void FakeEvolution() ;
void FakeSyechrulAnjay() ;
void FakeDinanAnjay() ;
void FakeSyechrulJomblo() ;
//--------------------------------------------------------------------
DWORD  NNCZHack(){
while(1){
if(RankHack){
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
CNames	  *pFake = (CNames*)((dwBase + 0x295D4)+ pTeam->iTeam * 0x21);
DualDinamic->iRank = 0x33;
DualDinamic->iHack = 0xFFFFFF;
if(RankHack==1){
DualDinamic->iRank = 0x30;//b3
DualDinamic	->iHack = 0xFFFF;
strcpy(pFake->szNames,"[U]nknown[H]ack"); // max 16 angka/huruf
}
if(RankHack==2){
DualDinamic->iRank = 0x31;//b4
DualDinamic	->iHack = 0xFFFF;
strcpy(pFake->szNames,"[U]nknown[H]ack"); // max 16 angka/huruf
}
if(RankHack==3){
DualDinamic->iRank = 0x32;//b5
DualDinamic	->iHack = 0xFFFF;
strcpy(pFake->szNames,"[U]nknown[H]ack"); // max 16 angka/huruf
}
if(RankHack==4){
DualDinamic->iRank = 0x33;//b5 gold
DualDinamic	->iHack = 0xFFFF;
strcpy(pFake->szNames,"[U]nknown[H]ack"); // max 16 angka/huruf
}
if(RankHack==5){
DualDinamic->iRank = 0x34;//bom
DualDinamic	->iHack = 0xFFFF;
strcpy(pFake->szNames,"[U]nknown[H]ack"); // max 16 angka/huruf
}
if(RankHack==6){
DualDinamic->iRank = 0x35;//GM
DualDinamic	->iHack = 0xFFFF;
strcpy(pFake->szNames,"[GM] Unknown"); // max 16 angka/huruf
}
}
}
if(BP_Invi ==1)
	{
		DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
		DWORD GM = ModulePB + ResultInvincible;
		PrivateOnly((void *)(GM),(int*)(PBYTE)"\x6F\x12\x83\x40",4);
	}
	if(BP_Invi ==0)
	{
		DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
		DWORD GM = ModulePB + ResultInvincible;
		PrivateOnly((void *)(GM),(int*)(PBYTE)"\x6F\x12\x83\x3C",4);
	}

	if(GetBattleState1()){
	if(AntiOut == 1)
	{
		LongPtr(BASE_IDLE2, 0x18, ResultPTRIdle, 0x41);
		LongPtr(BASE_IDLE2, 0x18, ResultPTRIdle2, 0x42);
	}}
//------------------------------------------------------------------------/
if(BugUnyu ==1){PrivateOnly((void *)(ModulePB + ResultBugWeapon),(int*)(PBYTE)"\xC0",1);}
if(BugUnyu ==0){PrivateOnly((void *)(ModulePB + ResultBugWeapon),(int*)(PBYTE)"\xBE",1);}
//-------------------------------------------------------------------------
		if(NoFallDamage == 1)
	{
		WritePtr(ResultBaseAmmo2, PTR_FallDamage, 0x64047214);
	}


if(WallShot ==1){ DWORD Pointblank = (DWORD)LoadLibraryA("Pointblank.exe"); 
PrivateOnly((void *)(Pointblank + ResultWallShot),(int*)(PBYTE)"\x90\x90",2);
}
if(WallShot ==0){ DWORD Pointblank = (DWORD)LoadLibraryA("Pointblank.exe"); 
PrivateOnly((void *)(Pointblank + ResultWallShot),(int*)(PBYTE)"\x75\x1F",2);

if(BugLuxivile ==1){ 
DWORD Pointblank = (DWORD)LoadLibraryA("NxCharacter.2.8.1.dll"); 
PrivateOnly((void *)(Pointblank + ResultBugHover1),(int*)(PBYTE)"\x3C",1);
PrivateOnly((void *)(Pointblank + ResultBugHover2),(int*)(PBYTE)"\x3C",1);}
if(BugLuxivile ==0){ 
DWORD Pointblank = (DWORD)LoadLibraryA("NxCharacter.2.8.1.dll"); 
PrivateOnly((void *)(Pointblank + ResultBugHover1),(int*)(PBYTE)"\x1C",1);
PrivateOnly((void *)(Pointblank + ResultBugHover2),(int*)(PBYTE)"\x1C",1);}

if(Wallbug==1){
DWORD NxCharakter2 = (DWORD)LoadLibraryA("NxCharacter.2.8.1.dll"); 
PrivateOnly((void *)(NxCharakter2 + WTF),(int*)(PBYTE)"\xFF",1);}
if(Wallbug==0){
DWORD NxCharakter2 = (DWORD)LoadLibraryA("NxCharacter.2.8.1.dll"); 
PrivateOnly((void *)(NxCharakter2 + WTF),(int*)(PBYTE)"\x89\x8B\x34\x01\x00\x00\x89\x93\x38\x01\x00\x00\x89\x83\x3C\x01",16);}
//---------------------------------------------------------------------

if(Magnet==1){PrivateOnly((void *)(FrameDX+ OFS_Magnet),(void*)(PBYTE)"\x30", 1);Sleep(20);}
if(Magnet==0){PrivateOnly((void *)(FrameDX+ OFS_Magnet),(void*)(PBYTE)"\xC0",1);;Sleep(20);}

if(GetBattleState1()){
if(PlantBomb==1){
DWORD Plant = (DWORD)GetModuleHandleA("PointBlank.exe");
cGameBases *GameBase = (cGameBases*) *(DWORD*)(Plant + ResultBasePlayer);
DWORD dwBase = *(DWORD*)(Plant + ResultBasePlayer);
CTeam *pTeam				= ((CTeam*)(dwBase + OFS_Team)); 
DWORD pCalculate2 = *(DWORD*)(dwBase + 0x4 * pTeam->iTeam + 0x27B24);
CPlayers	*Me	= (CPlayers*)(pCalculate2 + 0x64 );
{
GameBase->StageInfo->BombPositionA.x = Me->pos.x;
GameBase->StageInfo->BombPositionA.y = Me->pos.y;
GameBase->StageInfo->BombPositionA.z = Me->pos.z;
}}}
if(GetBattleState1()){
if(PlantBomb==2){
DWORD Plant = (DWORD)GetModuleHandleA("PointBlank.exe");
cGameBases *GameBase = (cGameBases*) *(DWORD*)(Plant + ResultBasePlayer);
DWORD dwBase = *(DWORD*)(Plant + ResultBasePlayer);
CTeam *pTeam				= ((CTeam*)(dwBase + OFS_Team)); 
DWORD pCalculate2 = *(DWORD*)(dwBase + 0x4 * pTeam->iTeam + 0x27B24);
CPlayers	*Me	= (CPlayers*)(pCalculate2 + 0x64 );
{
GameBase->StageInfo->BombPositionB.x = Me->pos.x;
GameBase->StageInfo->BombPositionB.y = Me->pos.y;
GameBase->StageInfo->BombPositionB.z = Me->pos.z;
}}}


DWORD ModulePB				= (DWORD)GetModuleHandle	("PointBlank.exe");
//---------------------------------------------------------------------------------------

//---------------------------------------------------------------------------
//-------------------------------------------------------------------------
class cGameStageInfo
{
public:
char _pad1[PTR_PlantBomb];//#define PTR_PlantBomb
D3DXVECTOR3 BombPositionA; 
};
class cGameBases
{
public:
char _pad1[OFS_StageInfo]; //#define OFS_StageInfo
cGameStageInfo* StageInfo;
};

	}
Sleep(10);
}
return 0;
}
//-----------------------------|FAKE REPLACE|---------------------------------------//
DWORD WINAPI NNCZReplace(LPVOID param){
NNCZReplaceON:
//--------------------------------------------------------------------
if(GetBattleState1()){
if(Rep_Item){
if(Rep_Item == 1){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, OFS_Special + (GetSlot->iTeam * 0x158), 0x35E20D79);
}}
//--------------------------------------------------------------------> Candy Granade
if(Rep_Item == 2){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, OFS_Special + (GetSlot->iTeam * 0x158), 0x35E20D6C);
}}
//--------------------------------------------------------------------> Lantern Grenade
if(Rep_Item == 3){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, OFS_Special + (GetSlot->iTeam * 0x158), 0x35E20D6F);
}}
//--------------------------------------------------------------------> Decoy Bomb
if(Rep_Item == 4){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, OFS_Special + (GetSlot->iTeam * 0x158), 0x35E20D72);
}}
//--------------------------------------------------------------------> Bread Grenade
if(Rep_Item == 5){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, OFS_Special + (GetSlot->iTeam * 0x158), 0x35E20D70);
}}
//--------------------------------------------------------------------> WP Smoke ++
if(Rep_Item == 6){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, OFS_Special + (GetSlot->iTeam * 0x158), 0x35E20D64);
}}
//--------------------------------------------------------------------> WP Smoke D
if(Rep_Item == 7){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, OFS_Special + (GetSlot->iTeam * 0x158), 0x35E20D5D);
}}}
//--------------------------------------------------------------------
if(R_Launcher)
{
//--------------------------------------------------------------------> Famas Launcher 
if(R_Launcher == 1){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, OFS_Primary + (GetSlot->iTeam * 0x158), 0x5F5ECEC);
}}
//--------------------------------------------------------------------> K-201 Exit
if(R_Launcher == 2){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, OFS_Primary + (GetSlot->iTeam * 0x158), 0x5F5ECC3);
}}
//--------------------------------------------------------------------> AK 47 FC
if(R_Launcher == 3){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, OFS_Primary + (GetSlot->iTeam * 0x158), 0x5F5ECF2);
}}
//--------------------------------------------------------------------> AK Sopmod R
if(R_Launcher == 4){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, OFS_Primary + (GetSlot->iTeam * 0x158), 0x5F5ECFC);
}}
//--------------------------------------------------------------------> SCAR D
if(R_Launcher == 5){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, OFS_Primary + (GetSlot->iTeam * 0x158), 0x5F5ED18);
}}
//--------------------------------------------------------------------> RPG-7
if(R_Launcher == 6){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, OFS_Primary + (GetSlot->iTeam * 0x158), 0x5F61F82); 
}}
//--------------------------------------------------------------------> M4 SR-16 FC
if(R_Launcher == 7){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, OFS_Primary + (GetSlot->iTeam * 0x158), 0x5F5ECE5); 
}}
}

if(R_Secondary)
{
//--------------------------------------------------------------------> HK-69
if(R_Secondary == 1){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{
MakePoint(ResultBasePlayer2, OFS_Secondary + (GetSlot->iTeam * 0x158), 0x23D2902A);

}
}}
//--------------------------------------------------------------------> Amok Kukri
if (R_Melee){
if ( R_Melee==1 ) { 
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2); 
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{ 
MakePoint(ResultBasePlayer2, OFS_Melee +(GetSlot->iTeam * 0x158), 0x29D7AF6C);
}}}
//--------------------------------------------------------------------> MINI AXE
if (R_Melee){ 
if ( R_Melee==2 ) { 
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2); 
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{ 
MakePoint(ResultBasePlayer2,  OFS_Melee +(GetSlot->iTeam * 0x158), 0x29D7AF6E);
}}}
//--------------------------------------------------------------------> FANG BLADE
if (R_Melee){ 
if ( R_Melee==3 ) { 
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2); 
CTeam* GetSlot = (CTeam*)(PtrRB + OFS_Team);{ 
MakePoint(ResultBasePlayer2, OFS_Melee +(GetSlot->iTeam * 0x158), 0x29D7AF79);
}}}
//--------------------------------------------------------------------> TEST
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
void FakeSyechrulAnjay() 
{ 

if (FakeSyechrul==1){ 
if (GetBattleState1()){ 
	int i;
for (i = 0 ; i <= 16 ; i++){
MakePoint(dwPBExe + ResultBasePlayer, ResultPrimary + (i*0x158), /*RPG*/0x5F61F82);
	}
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
//-----------------------------------------------------
void FakeSyechrulJomblo() 
{ 

if (FakeSyechrulCCD==1){ 
if (GetBattleState1()){ 
	int i;
for (i = 0 ; i <= 16 ; i++){
MakePoint(dwPBExe + ResultBasePlayer, ResultPrimary + (i*0x158), /*RPG*/0x5F61F82);
	}
DWORD ModuleHandle = (DWORD)GetModuleHandle("PointBlank.exe"); 
DWORD BasePlayer_A = *(DWORD*)(ModuleHandle + ResultBasePlayer); 
DWORD BasePlayer_B = *(DWORD*)(ModuleHandle + ResultBaseHealth); 
int MyIndex = GetMyCharaIndex2(); DWORD CGameCharaManager = CGameCharaBaseShoot(); 
DWORD CGameCharaBase = *(DWORD*)(BasePlayer_B + 0x14 + (MyIndex*4)); 
DWORD pNetCharaInfo = BasePlayer_A + ((ResultRespawn2) + (MyIndex*0x158)); 
SetCharaWeaponSet = (tSetCharaWeaponSet)ResultFake; 
SetCharaWeaponSet(CGameCharaManager, CGameCharaBase, pNetCharaInfo); 
	}
	}}
void FakeDinanAnjay() 
{ 

if (FakeDinan==1){ 
if (GetBattleState1()){ 
FakeEvolution();
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