
#include <windows.h>
#include "File.h"
#include "Variables.h"
bool bReload	= false;
bool bPiso		= false;
bool bBOM,bpeso		= false;
bool ReadAmmoo	= false;
bool bGhost = false;
bool Keprok,Keprox = false;

#define PlayerBody		0x548 
#define CoordinateX		0x11C
#define CoordinateZ		0x120
#define CoordinateY		0x124
#define CoordinateX2	0x110
#define CoordinateZ2	0x114
#define CoordinateY2	0x118
DWORD ModulePB = (DWORD)LoadLibraryA("PointBlank.exe"); 
DWORD Pointblank = (DWORD)LoadLibraryA("NxCharacter.2.8.1.dll"); 
int CallTele =0;
DWORD Px,Py,Pz;
//#define OFS_PLAYER					  0x27B24
bool SetPlayerPos	= false;
bool bHooIsRedTeam	= false;
int pMySlots()
{
	unsigned long dwBase	= *(DWORD*) ResultBasePlayer2;//ResultPlayerBase;
	CTeam *MyTeam			=  (CTeam*)((dwBase + ResultTeam));
	return MyTeam->iTeam;
}
//------------------------------------------------------------------------------------
int IsRedTeam(int iSlot)
{
	if(bHooIsRedTeam == true)
	{
		if (iSlot == 0 ||iSlot == 2||iSlot == 4||iSlot == 6||iSlot == 8||iSlot == 10||iSlot == 12||iSlot == 14)return 1;
		else
		if (iSlot == 1 ||iSlot == 3||iSlot == 5||iSlot == 7||iSlot == 9||iSlot == 11||iSlot == 13||iSlot == 15)return 2;
		bHooIsRedTeam = false;
	}
	return 0;
}

//------------------------------------------------------------------------------------
void TeleMagnet(int PlayerToCall )
{
	unsigned long BasePlayer	= *(DWORD*)ResultBasePlayer2;
	unsigned long PlayerPos		= *(DWORD*)ResultBaseHealth2+0x14;	
	if(SetPlayerPos == false)
	{
		__try
		{
			BYTE SLot= *(BYTE*)(BasePlayer + ResultTeam);
			Px = *(DWORD*)(*(DWORD*)(BasePlayer+ResultPlayer+(SLot*4))+0x6C);
			Pz = *(DWORD*)(*(DWORD*)(BasePlayer+ResultPlayer+(SLot*4))+0x70);
			Py = *(DWORD*)(*(DWORD*)(BasePlayer+ResultPlayer+(SLot*4))+0x74);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
		}
	}
	if(CallTele==1)
	{
		SetPlayerPos=true;
		__try
		{
			*(DWORD*)(*(DWORD*)(*(DWORD*)(PlayerPos + (PlayerToCall * 4)) + PlayerBody) + CoordinateX)	= Px;
			*(DWORD*)(*(DWORD*)(*(DWORD*)(PlayerPos + (PlayerToCall * 4)) + PlayerBody) + CoordinateZ)	= Pz;
			*(DWORD*)(*(DWORD*)(*(DWORD*)(PlayerPos + (PlayerToCall * 4)) + PlayerBody) + CoordinateY)	= Py;
			
			*(DWORD*)(*(DWORD*)(*(DWORD*)(PlayerPos + (PlayerToCall * 4)) + PlayerBody) + CoordinateX2)	= Px;
			*(DWORD*)(*(DWORD*)(*(DWORD*)(PlayerPos + (PlayerToCall * 4)) + PlayerBody) + CoordinateZ2)	= Pz;
			*(DWORD*)(*(DWORD*)(*(DWORD*)(PlayerPos + (PlayerToCall * 4)) + PlayerBody) + CoordinateY2)	= Py;
			
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
		}
	}
	if(CallTele==0)
	{
		SetPlayerPos=false;
	}
}
bool IsAlive1(int Index)
{
	unsigned long dwBase2	= *(DWORD*)	 (ModulePB		+ ResultBaseHealth);
	CHealth		*Health		= (CHealth*) ((dwBase2		+ 0x264) + Index * 0x24);
	if(Health->CurHP > 0.1f)
	return true;
	return false;
}

void Fitured() {
if(bPiso == false){
PisoGila = TestPacth(ResultBaseAmmo2, ResultPTRAmmo, 0x24, 0xC9C);
}
if(BrustKnife==0){
bPiso = false;
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x24, ResultPTRCaclKnife, PisoGila);
}
if(BrustKnife == 1){
bPiso = true;
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x24, ResultPTRCaclKnife, PisoGila);
}
if(GetBattleState()){
		if(Planted==1)
		{
			Mem_ASM((void*)0x548118,(char*)"\x04",1);
			Mem_ASM((void*)0x548118,(char*)"\x44",1);
		}}

		if(GetBattleState()){
		if(Planted==0)
		{
			Mem_ASM((void*)0x548118,(char*)"\x14",1);
			Mem_ASM((void*)0x548118,(char*)"\x24",1);
		}}
if(Rspw == 1)
{
WritePtr(ResultBaseAmmo2, ResultPTRAmmo-0x31, 0x40);
}
if(Freeze==1) { 
Replay_12ddfx(ResultBaseAmmo2, 0x18, 0x18, 0xE8, 1069715291); 
}
if(Ammo == 1)
{
gEtWeapon_IndexA( ResultBaseAmmo2, ResultPTRAmmo, 0x1C, ResultPTRCaclAmmo, PisoGila);
}

if(Reload==1){
	c_WeaponIndex_B(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0x30, 0x64, 62);
			c_WeaponIndex_B(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0x30, 0x64, 62);
}


if(QuickChange == 1)
{

	//MemWrite((void*)0x5A0A0A,(void*)(PBYTE)"\xD9\x45\xFF", 3);
		}
		if(QuickChange==0){
	//		MemWrite((void*)0x5A0A0A,(void*)(PBYTE)"\xD9\x45\xF8", 3);
		}
/*if (Recoil == 1) 
{ 
MemWrite((void*)0x598FB9,(void*)(PBYTE)"\xD9\x45\xFF",3);
MemWrite((void*)0x59927D,(void*)(PBYTE)"\xD9\x45\xFF",3);
}
if(Recoil==0){
MemWrite((void*)0x598FB9,(void*)(PBYTE)"\xD9\x45\xF8",3);
MemWrite((void*)0x59927D,(void*)(PBYTE)"\xD9\x45\xF8",3);
}*/
if(AntiOut == 1)
{
LongPtr(ResultBasePlayer2 - 0x8, 0x18, PTR_Idle, 0x41);
LongPtr(ResultBasePlayer2 - 0x8, 0x18, PTR_Idle2, 0x42);
}
if(KniffKiller==1){
		PachtChara(ResultBaseAmmo2,0x53C,0x20,0x41);
		}
if(JumpHight==1){
	if (GetAsyncKeyState(VK_SPACE)&&0x8000){
	{
	LongPtr(ResultBaseAmmo2 ,ResultNorecoil-0x10,0x98,0x00000000);
LongPtr(ResultBaseAmmo2,ResultNorecoil-0x10,0x9C,0x00000000);
Sleep(50);
	}}}
if(JumpHight2==1){
	if (GetAsyncKeyState(VK_SPACE)&&0x8000){
	{
	LongPtr(ResultBaseAmmo2 ,ResultNorecoil-0x10,0x0A3,0x41);
Sleep(50);
	}}}

if(Atap ==1){
PrivateOnly((void *)(dwPBExe + ResultBugWeapon),(int*)(PBYTE)"\xA3",1);
}
if(Atap ==0){
PrivateOnly((void *)(dwPBExe + ResultBugWeapon),(int*)(PBYTE)"\xBE",1);
	}
if(UNYU ==1){
PrivateOnly((void *)(dwPBExe + ResultBugWeapon),(int*)(PBYTE)"\xC0",1);
}
if(UNYU ==0){
PrivateOnly((void *)(dwPBExe + ResultBugWeapon),(int*)(PBYTE)"\xBE",1);
	}
	}
DWORD RETNoReload	=0x594910+0x6;
float xFastReload1=1000;
float xFastReload2;
__declspec( naked ) void speedreload_on()
{
_asm
{	
fstp dword ptr [ebp-0x0C]
movss [xFastReload2],xmm0
movss xmm0,[xFastReload1]
movss [ebp-0x0C],xmm0
movss xmm0,[xFastReload2]
mov ecx,[ebp-0x14]
jmp [RETNoReload]
}
}
DWORD Func_NoReload()
{
if(Reload==1)
JMPE9((PBYTE)0x594910,(DWORD)speedreload_on,6);
if(Reload==0)
MemWrite((void*)0x594910,(PBYTE)"\xD9\x5D\xF4\x8B\x4D\xEC",6);
return 0;
}

DWORD RCHHack() {
while(1){
if(TelePortal==1)
			{	
				for (int i = 0; i < 15; i++)
				{
					bHooIsRedTeam	= true;
					int pMySlot		= IsRedTeam(pMySlots()); 
					if(IsRedTeam(i) == pMySlot) continue;
					if(IsAlive1(i))
					{
						CallTele=1;
						if(CallTele==1)
						{ 
							TeleMagnet(i);	
						}
					}
				}
					bHooIsRedTeam=false;
				}
			if(TelePortal==0)
			{
				CallTele=0;
			}
if(GetBattleState()){
		if ( R_AllMode2 == 1 )
		{ FakeReplace=1;
		int MyIndex = GetMyCharaIndex();
				MakePoint(ResultBasePlayer2, ResultSmoke + (MyIndex * 0x158), Lantern_Grenade);
			
		}
		}
		if(GetBattleState()){
		if ( R_AllMode2 == 2 )
		{ FakeReplace=1;
			int MyIndex = GetMyCharaIndex();
				MakePoint(ResultBasePlayer2, ResultSmoke + (MyIndex* 0x158), Candy_Granade);
			
		}
		}
		if(GetBattleState()){
		if ( R_AllMode2 == 3 )
		{ FakeReplace=1;
			int MyIndex = GetMyCharaIndex();
				MakePoint(ResultBasePlayer2, ResultSmoke + (MyIndex* 0x158), Lantern_Grenade);
			
		}
		}
		if(GetBattleState()){
		if ( R_AllMode2 == 4 )
		{ FakeReplace=1;
			int MyIndex = GetMyCharaIndex();
				MakePoint(ResultBasePlayer2, ResultSmoke + (MyIndex * 0x158), Bread_Grenade);
			
		}
		}
		if(GetBattleState()){
		if ( R_AllMode2 == 5 )
		{ FakeReplace=1;
			int MyIndex = GetMyCharaIndex();
				MakePoint(ResultBasePlayer2, ResultSmoke + (MyIndex* 0x158), OFS_Soccer);
		}
		}
		if(GetBattleState()){
		if ( R_AllMode2 == 6 )
		{ FakeReplace=1;
			int MyIndex = GetMyCharaIndex();
				MakePoint(ResultBasePlayer2, ResultSmoke + (MyIndex* 0x158), Decoy_Bomb);
			
		}
		}
if(GetBattleState()){
if(RPG==1){
{ 
	
	FakeReplace=1;
	RapitFire=1;
		unsigned long PtrAdrkla = *(LPBOOL)(ResultBasePlayer2); 
			CTeam* GetSlot = (CTeam*)(PtrAdrkla + ResultTeam);{
			MakePoint(ResultBasePlayer2, ResultPrimary + (GetSlot->iTeam* 0x158), 0x5F61F82);//RPG-7
			//MakePoint(ResultBasePlayer2, ResultMelee + (GetSlot->iTeam* 0x158), 0x5F61F82);// Piso lempar shurikehen
		}
}}
if(GetBattleState()){
if(HK==1){
FakeReplace=1;RapitFire=1;
			int MyIndex = GetMyCharaIndex();
				MakePoint(ResultBasePlayer2, ResultSecondary + (MyIndex* 0x158), 0x23D2902A);
			
		}
}
		if(GetBattleState()){
		if ( HK == 2 )
		{ 
FakeReplace=1;RapitFire=1;
			int MyIndex = GetMyCharaIndex();
				MakePoint(ResultBasePlayer2, ResultSecondary + (MyIndex* 0x158), 0x23D2902C);
		
		}}
if(GetBattleState()){
if ( R_AllMode == 1 )
{ 
FakeReplace=1;RapitFire=1;
int MyIndex = GetMyCharaIndex();			
				MakePoint(ResultBasePlayer2, ResultPrimary + (MyIndex* 0x158), 0x5F5ECEC);//K-201 Exit			
}}
if(GetBattleState()){
if ( R_AllMode == 2 )
{ 
FakeReplace=1;RapitFire=1;
int MyIndex = GetMyCharaIndex();
				MakePoint(ResultBasePlayer2, ResultPrimary + (MyIndex* 0x158), 0x5F5ECC3);//K-201 Exit			
}}
if(GetBattleState()){
if ( R_AllMode == 3 )
{ 
FakeReplace=1;RapitFire=1;
int MyIndex = GetMyCharaIndex();
				MakePoint(ResultBasePlayer2, ResultPrimary + (MyIndex* 0x158), 0x5F5ECF2);//AK 47 FC			
}}
if(GetBattleState()){
if ( R_AllMode == 4 )
{ 
FakeReplace=1;RapitFire=1;
			int MyIndex = GetMyCharaIndex();
				MakePoint(ResultBasePlayer2, ResultPrimary + (MyIndex* 0x158), 0x5F5ECFC);//AK Sopmod R
				}}
if(GetBattleState()){
if ( R_AllMode == 5 )
{ 
FakeReplace=1;RapitFire=1;
int MyIndex = GetMyCharaIndex();
				MakePoint(ResultBasePlayer2, ResultPrimary + (MyIndex* 0x158), 0x5F5ED18);//SCAR D
			
		}}
if(GetBattleState()){
if ( R_AllMode == 6 )
{ 
FakeReplace=1;RapitFire=1;
			int MyIndex = GetMyCharaIndex();
				MakePoint(ResultBasePlayer2, ResultPrimary + (MyIndex* 0x158), 0x5F5ECE5);//M4 SR-16 FC
}}
if(GetBattleState()){
			if(BugLuxivile ==1){ 
				
				PrivateOnly((void *)(Pointblank + ResultBugHover1),(int*)(PBYTE)"\x3C",1);
				PrivateOnly((void *)(Pointblank + ResultBugHover2),(int*)(PBYTE)"\x3C",1);}}
		if(GetBattleState()){
			if(BugLuxivile ==0){ 
				PrivateOnly((void *)(Pointblank + ResultBugHover1),(int*)(PBYTE)"\x1C",1);
				PrivateOnly((void *)(Pointblank + ResultBugHover2),(int*)(PBYTE)"\x1C",1);}}
if(PlayerSpeed ==1){
PrivateOnly((void *)(dwPBExe + ResultPlayerSpeed),(int*)(PBYTE)"\x00\x00\x00\x40\xE1\x7A\x8F\x3F",8);}
if(PlayerSpeed ==0){
PrivateOnly((void *)(dwPBExe + ResultPlayerSpeed),(int*)(PBYTE)"\x00\x00\x00\x40\xE1\x7A\x84\x3F",8);}
if(WallBug==1){
PrivateOnly((void *)(NxCharakter2 + WTF),(int*)(PBYTE)"\xFF",1);
}
if(WallBug==0){
PrivateOnly((void *)(NxCharakter2 + WTF),(int*)(PBYTE)"\x89\x8B\x34\x01\x00\x00\x89\x93\x38\x01\x00\x00\x89\x83\x3C\x01",16);
}
if(FreeMove == 1){
_WriteMEM(ResultBasePlayer2 - 0x28, 0x44, 0x18, 0xDC, 0x4);
}
if(SmokeCall ==1){ 
PrivateOnly((void *)(dwPBExe + ResultWallShot),(int*)(PBYTE)"\x90\x90",2);
}
if(SmokeCall ==0){ 
PrivateOnly((void *)(dwPBExe + ResultWallShot),(int*)(PBYTE)"\x75\x1F",2);
}
if(Invincible){
if(GetBattleState()){
DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
		DWORD GM = ModulePB + ResultInvincible;
		MemWrite((void *)(GM),(int*)(PBYTE)"\x6F\x12\x83\x40",4);}}
if(Invincible==0){
DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
		DWORD GM = ModulePB + ResultInvincible;
		MemWrite((void *)(GM),(int*)(PBYTE)"\x6F\x12\x83\x3C",4);}
}

}	
return 0;
	}

void ResCyRankHack(){
if(RankHack == 1)
{
unsigned long dwBase	= *(DWORD*)(ResultBasePlayer2);
CTeam *pTeam		= ((CTeam*)(dwBase + ResultTeam)); 
int MyTeam = GetTeam(pTeam->iTeam);
GM			*DualDinamic = (GM*)((dwBase + ResultSkill2)+ pTeam->iTeam * RANKSIZE);
CNames		*pFake		 = (CNames*)((dwBase + ResultName) + pTeam->iTeam  * NAMESIZE);
if(RankHack == 1)
{
DualDinamic->iRank = 0x35;
DualDinamic->iHack = 0xFFFF;
}
}
/*----------------------------------------------------------------------------------*/
if(RankHack == 2)
{
unsigned long dwBase	= *(DWORD*)(ResultBasePlayer2);
CTeam *pTeam		= ((CTeam*)(dwBase + ResultTeam)); 
int MyTeam = GetTeam(pTeam->iTeam);
GM			*DualDinamic = (GM*)((dwBase + ResultSkill2)+ pTeam->iTeam * RANKSIZE);
CNames		*pFake		 = (CNames*)((dwBase + ResultName) + pTeam->iTeam  * NAMESIZE);
if(RankHack == 2)
{
DualDinamic->iRank = 0x35;
DualDinamic->iHack = 0xFFFF;
}
}
if(GetBattleState()){
		if(BombEnywhere == 1)
		{
			cGameBases *GameBase = (cGameBases*) *(DWORD*)(ResultBasePlayer2);
			DWORD dwBase = *(DWORD*)(ResultBasePlayer2);
			CTeam *pTeam				= ((CTeam*)(dwBase + ResultTeam)); 
			DWORD pCalculate2 = *(DWORD*)(dwBase + 0x4 * pTeam->iTeam + ResultPlayer);
			CPlayers	*Me	= (CPlayers*)(pCalculate2 + 0x64 );
			if(BombEnywhere == 1)
			{
				GameBase->StageInfo->BombPositionA.x = Me->pos.x;
				GameBase->StageInfo->BombPositionA.y = Me->pos.y;
				GameBase->StageInfo->BombPositionA.z = Me->pos.z;
			}
		}}
		
		if(GetBattleState()){
		if(BombEnywhere == 2)
		{
			cGameBases *GameBase = (cGameBases*) *(DWORD*)(ResultBasePlayer2);
			DWORD dwBase = *(DWORD*)(ResultBasePlayer2);
			CTeam *pTeam				= ((CTeam*)(dwBase + ResultTeam)); 
			DWORD pCalculate2 = *(DWORD*)(dwBase + 0x4 * pTeam->iTeam + ResultPlayer);
			CPlayers	*Me	= (CPlayers*)(pCalculate2 + 0x64 );
			if(BombEnywhere == 2)
			{
				GameBase->StageInfo->BombPositionB.x = Me->pos.x;
				GameBase->StageInfo->BombPositionB.y = Me->pos.y;
				GameBase->StageInfo->BombPositionB.z = Me->pos.z;
			}
		}
		}

}
 //--------------------------------------------------------------------
typedef void (__thiscall * tCmd_Mati)(DWORD CGameCharaLocalBase, int HPDrain, int a2, int a3);
tCmd_Mati Cmd_Mati;
void BunuhDiri(){

Cmd_Mati = (tCmd_Mati)(dwPBExe + ResultSuicide);
DWORD CGameCharaLocalBase = *(DWORD*)(dwPBExe + ResultBaseAmmo);
Cmd_Mati(CGameCharaLocalBase,0xFF,0xFFFF,false);
}
typedef void (__thiscall * tCmd_Death)(DWORD CGameCharaLocalBase, int HPDrain, int a2, int a3);
tCmd_Death Cmd_Death;
void Bunuh(){
if(Sucide==1){
Cmd_Death = (tCmd_Death)(dwPBExe + ResultSuicide);
DWORD CGameCharaLocalBase = *(DWORD*)(dwPBExe + ResultBaseAmmo);
Cmd_Death(CGameCharaLocalBase,0xFF,0xFFFF,false);
}}
//--------------------------------------------------------------------
void GHOST_Hacks(){
//while(1){
unsigned long dwBase	= *(DWORD*)ResultBasePlayer2;
unsigned long dwBase2	= *(DWORD*)ResultBaseHealth2;	
CTeam		*GetSlot	= (CTeam*)(dwBase + ResultTeam);
CHealth		*GetHealth	= (CHealth*)((dwBase2 + ResultHealth) + GetSlot->iTeam * HPSIZE);

if(bGhost == false)		
Ghoster					= Read( ResultBaseHealth2, ResultGHOST + GetSlot->iTeam * HPSIZE);
if(GetHealth->CurHP > 0)bGhost = false;

if(Zombie==0){
bGhost = false;
MakePoint( ResultBaseHealth2, ResultGHOST + GetSlot->iTeam * HPSIZE, Ghoster);
}
if(Zombie==1){

//NoFallDamage = 1;
bGhost = true;
MakePoint( ResultBaseHealth2, ResultGHOST + GetSlot->iTeam * HPSIZE, Ghoster-1);
}
if(NoFallDamage == 1){
PactJumper(ResultBaseAmmo2, 0x513, 18);
PactJumper(ResultBaseAmmo2, 0x513, 172);
PactJumper(ResultBaseAmmo2, 0x513, 4);
PactJumper(ResultBaseAmmo2, 0x513, 64);
_patchPTR(ResultBaseAmmo2, 0x510, 18); 
_patchPTR(ResultBaseAmmo2, 0x510, 172); 
_patchPTR(ResultBaseAmmo2, 0x510, 4); 
_patchPTR(ResultBaseAmmo2, 0x510, 64);
}
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
unsigned long dwBase = *(DWORD*)(dwPBExe + ResultBasePlayer); 
CTeam *MyTeam = (CTeam*) ((dwBase + ResultTeam)); 
return MyTeam->iTeam; 
} 

void FakeEvolution() 
{ 

if (FakeReplace==1){ 
if (GetBattleState()){ 
DWORD BasePlayer_A = *(DWORD*)(dwPBExe + ResultBasePlayer); 
DWORD BasePlayer_B = *(DWORD*)(dwPBExe + ResultBaseHealth); 
int MyIndex = GetMyCharaIndex2(); DWORD CGameCharaManager = CGameCharaBaseShoot(); 
DWORD CGameCharaBase = *(DWORD*)(BasePlayer_B + 0x14 + (MyIndex*4)); 
DWORD pNetCharaInfo = BasePlayer_A + ((ResultRespawn2) + (MyIndex*0x158)); 
SetCharaWeaponSet = (tSetCharaWeaponSet)ResultSetNetChara; 
SetCharaWeaponSet(CGameCharaManager, CGameCharaBase, pNetCharaInfo); 
	}
	}
	}
void _Fitur_RapidFire(){
if(RapitFire==1){ 
if(GetAsyncKeyState(0x01)){
__try 
{ 
if (*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+ResultPTRAmmo)+0x38)==1)
{
*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30)+ResultRafid)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0; } 
if (*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+ResultPTRAmmo)+0x38)==0)
{ 
*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30)+ResultRafid)=0; 
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0; 
} 
}__except (EXCEPTION_EXECUTE_HANDLER ) {Sleep(100);}
} 
} 
Sleep(0*5); 
}
void mcdPlantOne_On() // Kaga Usah Di  Kasih If{PlantedX} Langsung Aja Di Panggil Void Nya If{PlantedX}{mcdPlantOne_On();}
{ 	
DWORD mcdPlantOne_On		=  0x6B6860; // + 0x290 Make Manual Aja Kalian :v AOB Nya Ntar Pas Puasa GW Share
DWORD g_pGameContext_On		= *(DWORD*)(ResultBaseAmmo2);
__asm { 
push 0x1 
mov ecx, [g_pGameContext_On] 
call [mcdPlantOne_On]
} 
}
/*---------------------------------------- Declaration CT Defuse ----------------------------------------------------*/
void dmcDefusTwo_On() 
{ 	
DWORD mdcDefusOne_On    = 0x4D2220; // Make Manual Aja Kalian :v AOB Nya Ntar Pas Puasa GW Share
DWORD dmcDefusTwo_On		= 0x548BA0; // + 0x300 Make Manual Aja Kalian :v AOB Nya Ntar Pas Puasa GW Share
DWORD g_pBasePlayer_On		= *(DWORD*)(ResultBasePlayer2);
__asm { 
push 0x1
mov ecx, [g_pBasePlayer_On]
call [mdcDefusOne_On]
mov ecx, eax
call [dmcDefusTwo_On] 
} 
}
float xDamage=10000;
 __declspec( naked ) void Damage_on()
{
	_asm
	{
	fld dword ptr [xDamage]
	pop esi
	mov esp,ebp
	jmp dword ptr [RETNeoDamage]
	}
}

/*---------------------------------------- Declaration Damage All Weapon ----------------------------------------------------*/
DWORD BounceKill()
{
	if(BounceKiller==1)
		JMPE9((PBYTE)i3Damage,(DWORD)Damage_on,6);
	if(BounceKiller==0)
		MemWrite((void*)i3Damage,(void*)(PBYTE)"\xD9\x45\xF0\x5E\x8B\xE5",6);
	return 0;
}
void Hotkeymenu(){
if(Hotkey==1){
if(GetAsyncKeyState(VK_F1)&1)
{
WallCrot=!WallCrot;
MessageBeep(0);
Beep(1000,100);
}
if(GetAsyncKeyState(VK_F3)&1)
{
ESPName=!ESPName;
MessageBeep(0);
Beep(1000,100);
}
if(GetAsyncKeyState(VK_F4)&1)
{
Ammo=!Ammo;
MessageBeep(0);
Beep(1000,100);
}
if(GetAsyncKeyState(VK_F5)&1)
{
PesoEdan=!PesoEdan;
MessageBeep(0);
Beep(1000,100);
}
if(GetAsyncKeyState(VK_F6)&1)
{
JumpHight=!JumpHight;
MessageBeep(0);
Beep(1000,100);
}
if(GetAsyncKeyState(VK_F7)&1)
{
BulletCall=!BulletCall;
MessageBeep(0);
Beep(1000,100);
}


if(GetAsyncKeyState(VK_F11)&1)
{
AmmoRPG=!AmmoRPG;
MessageBeep(0);
Beep(1000,100);
}

if(GetAsyncKeyState(VK_HOME)&1)
{
AutoHS=!AutoHS;
MessageBeep(0);
Beep(1000,100);
}
if(GetAsyncKeyState(VK_END)&1)
{
AutoHS2=!AutoHS2;
MessageBeep(0);
Beep(1000,100);
}
if(GetAsyncKeyState(VK_NEXT)&1)
{
AimBody=!AimBody;
MessageBeep(0);
Beep(1000,100);
}
if(GetAsyncKeyState(VK_RSHIFT)&1)
{
TelePortal=!TelePortal;
MessageBeep(0);
Beep(1000,100);
}
if(GetAsyncKeyState(VK_LSHIFT)&1)
{
UNYU=!UNYU;
MessageBeep(0);
Beep(1000,100);
}
if(GetAsyncKeyState(VK_DELETE)&1)
{
BunuhDiri();
MessageBeep(0);
Beep(1000,100);
}
if(GetAsyncKeyState(VK_LMENU)&1)// VK_LMENU ALt kiri
{
Zombie=!Zombie;BunuhDiri();
MessageBeep(0);
Beep(1000,100);
}
if(GetAsyncKeyState(VK_RMENU)&1)// VK_LMENU ALt kiri
{
VoteKick=!VoteKick;
MessageBeep(0);
Beep(1000,100);
}
if(GetAsyncKeyState(0x14)&1)// VK_LMENU ALt kiri
{
Invincible=!Invincible;
MessageBeep(0);
Beep(1000,100);
}
if(GetAsyncKeyState(VK_F2)){
FakeEvolution();
}
}
}