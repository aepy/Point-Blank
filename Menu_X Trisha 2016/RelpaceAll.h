typedef void (__thiscall * tCmd_Damage)(DWORD CGameCharaLocalBase, int HPDrain, int a2, int a3);
tCmd_Damage Cmd_Damage;
/*------------------------------------------- Declaration Suicide ------------------------------------------------------*/
typedef void (__thiscall * tCmd_Mati)(DWORD CGameCharaLocalBase, int HPDrain, int a2, int a3);
tCmd_Mati Cmd_Mati;

void BunuhDiri()
{
	Cmd_Mati = (tCmd_Mati)(dwPBExe + ResultSuicide);
	DWORD CGameCharaLocalBase = *(DWORD*)(dwPBExe + ResultBaseAmmo);
	Cmd_Mati(CGameCharaLocalBase,0xFF,0xFFFF,false);
}
typedef void (__thiscall * tCmd_Fast)(DWORD CGameCharaLocalBase, int HPDrain, int a2, int a3);
tCmd_Fast Cmd_Fast;

void FastKillerz()
{
if(FastKiller){
Cmd_Fast = (tCmd_Fast)(dwPBExe + ResultSuicide);
DWORD CGameCharaLocalBase = *(DWORD*)(dwPBExe + ResultBaseAmmo);
Cmd_Fast(CGameCharaLocalBase,0xFF,0xFFFF,false);
}}

void Suicide(){
if(SuicideCall){
DWORD ModuleHandle = (DWORD)GetModuleHandleA("PointBlank.exe");
Cmd_Damage = (tCmd_Damage)(ModuleHandle + ResultSuicide);
DWORD CGameCharaLocalBase = *(DWORD*)(ModuleHandle + ResultBaseAmmo);
Cmd_Damage(CGameCharaLocalBase,0xFF,0xFFFF,false);
}
}
DWORD WritePTR(DWORD Base,DWORD PTR1,DWORD Byte){ 
if (!IsBadReadPtr((PDWORD)Base,4)){DWORD RPTR1=*(PDWORD)((DWORD)(Base))+PTR1;
if (!IsBadReadPtr((PDWORD)RPTR1,4)){*(PDWORD)RPTR1=Byte;}}
return 0;}
/*---------------------------------------- Declaration HP Minus ----------------------------------------------------*/
bool bGhost=false;
DWORD GHOSTHacks()
{
while(1){
if(GetBattleState1())
			{
unsigned long dwBase	= *(DWORD*)ResultBasePlayer2;
unsigned long dwBase2	= *(DWORD*)ResultBaseHealth2;	
CTeam		*GetSlot	= (CTeam*)(dwBase + ResultTeam);
CHealth		*GetHealth	= (CHealth*)((dwBase2 + 0x264) + GetSlot->iTeam * ALIVESIZE);

if(bGhost == false)		
Ghoster					= ReadFunct( ResultBaseHealth2, 0x260 + GetSlot->iTeam * ALIVESIZE);

if(GetHealth->CurHP > 0)
{
if(ZombieCall==0){
bGhost = false;
MakePoint( ResultBaseHealth2, 0x260 + GetSlot->iTeam * ALIVESIZE, Ghoster);
}
if(ZombieCall==1){
BunuhDiri();
bGhost = true;
MakePoint( ResultBaseHealth2, 0x260 + GetSlot->iTeam * ALIVESIZE, Ghoster-1);
}
if(GetHealth->CurHP < 0){
bGhost = false;
MakePoint( ResultBaseHealth2, 0x260 + GetSlot->iTeam * ALIVESIZE, Ghoster);
}
}
}
Sleep(0.5);
}
return 0;
}
DWORD WINAPI NNCZReplace(LPVOID param){
NNCZReplaceON:
if(ReplaceRPG == 1){
int i;
for (i = 0 ; i <= 16 ; i++){
DWORD BasokaRep = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(BasokaRep + ResultBasePlayer, ResultPrimary + (i*0x158), 0x5F61F82); 
RafidFire=1;
}
}
if (ReplaceAsault == 1){

int i;
for (i = 0 ; i <= 16 ; i++){
DWORD BasokaRep = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(BasokaRep + ResultBasePlayer, ResultPrimary + (i*0x158),0x5F5ECE5); //M4 SR-16 FC
RafidFire=1;
}

}
if (ReplaceAsault == 2){

int i;
for (i = 0 ; i <= 16 ; i++){
DWORD BasokaRep = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(BasokaRep + ResultBasePlayer, ResultPrimary + (i*0x158),0x5F5ECF2); //AK.FC
RafidFire=1;
}

}
if (ReplaceAsault == 3){

int i;
for (i = 0 ; i <= 16 ; i++){
DWORD BasokaRep = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(BasokaRep + ResultBasePlayer, ResultPrimary + (i*0x158), 0x5F5ECFC); //AK.FC RED
RafidFire=1;
}

}
if (ReplaceAsault == 4){

int i;
for (i = 0 ; i <= 16 ; i++){
DWORD BasokaRep = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(BasokaRep + ResultBasePlayer, ResultPrimary + (i*0x158), /*0x23D2902A);*/0x5F5ED18); //SCAR-L F.C
RafidFire=1;
}
}
if (ReplaceAsault == 5){

int i; 
for (i = 0 ; i <= 16 ; i++){
DWORD BasokaRep = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(BasokaRep + ResultBasePlayer, ResultPrimary + (i*0x158), /*0x23D2902A);*/0x5F5ECEC); //Famas M203
RafidFire=1;
}

}
if (ReplaceAsault == 6){

int i;
for (i = 0 ; i <= 16 ; i++){
DWORD BasokaRep = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(BasokaRep + ResultBasePlayer, ResultPrimary + (i*0x158), /*0x23D2902A);*/0x5F5ECDC); //Aug A3G
RafidFire=1;
}

}
/*----------------------------------------------------------------------------------*/
if (HK == 1){

int i;
for (i = 0 ; i <= 16 ; i++){
DWORD BasokaRep = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(BasokaRep + ResultBasePlayer, 0x2817C + (i*0x158), /*0x23D2902A);*/0x23D2902A); 
RafidFire=1;
}
}
if (HK == 2){

int i;
for (i = 0 ; i <= 16 ; i++){
DWORD BasokaRep = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(BasokaRep + ResultBasePlayer, 0x2817C + (i*0x158), /*0x23D2902A);*/0x23D2902C); //MK-79
RafidFire=1;
}

}
/*----------------------------------------------------------------------------------*/
if ( ReplacePiso == 1 ) { 
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2); 
CTeam* GetSlot = (CTeam*)(PtrRB + ResultTeam);{
MakePoint(ResultBasePlayer2, ResultMelee + (GetSlot->iTeam * 0x158), 0x29D7AF6C); //AmokKukri
}}
if ( ReplacePiso == 2 ) { 
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2); 
CTeam* GetSlot = (CTeam*)(PtrRB + ResultTeam);{
MakePoint(ResultBasePlayer2, ResultMelee + (GetSlot->iTeam * 0x158), 0x29D7AF6E); //MiniAxe
}}
if ( ReplacePiso == 3 ) { 
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2); 
CTeam* GetSlot = (CTeam*)(PtrRB + ResultTeam);{
MakePoint(ResultBasePlayer2, ResultMelee + (GetSlot->iTeam * 0x158), 0x29D7AF79); //Fangblade
}}
if ( ReplacePiso == 4 ) { 
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2); 
CTeam* GetSlot = (CTeam*)(PtrRB + ResultTeam);{
MakePoint(ResultBasePlayer2, ResultMelee + (GetSlot->iTeam * 0x158), 0x29D7AF6A); //M9
}}
if ( ReplacePiso == 5 ) { 
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2); 
CTeam* GetSlot = (CTeam*)(PtrRB + ResultTeam);{
MakePoint(ResultBasePlayer2, ResultMelee + (GetSlot->iTeam * 0x158), 0x29D7AF76); //Combat Machete
}}
if ( ReplacePiso == 6 ) { 
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2); 
CTeam* GetSlot = (CTeam*)(PtrRB + ResultTeam);{
MakePoint(ResultBasePlayer2, ResultMelee + (GetSlot->iTeam * 0x158), 0x29D7AF7D); //Keris
}}
/*----------------------------------------------------------------------------------*/
if(SmokeKhusus==1){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + ResultTeam);{
MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), Candy_Granade);
}
}
if(ReplaceSmoke==1){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + ResultTeam);{
MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), Candy_Granade);
}
}
if(ReplaceSmoke==2){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + ResultTeam);{
MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), OFS_Soccer);
}
}
if(ReplaceSmoke==3){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + ResultTeam);{
MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), 0x35E20D6F);//Lentren
}
}
if(ReplaceSmoke==4){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + ResultTeam);{
MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), 0x35E20D72);//DecoyBomb
}
}
if(ReplaceSmoke==5){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + ResultTeam);{
MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), 0x35E20D70);//BreadGrenade
}
}
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
CTeam *MyTeam = (CTeam*) ((dwBase + ResultTeam)); 
return MyTeam->iTeam; 
}  
/*----------------------------------------------------------------------------------*/
void FakeAbal1() 
{ 
if (FakeReplace1==1){ 
if (GetBattleState1()){ 
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
/*----------------------------------------------------------------------------------*/
void FakeSmokeKhusus() 
{ 
SmokeKhusus=1;
if (GetBattleState1()){ 
DWORD BasePlayer_A = *(DWORD*)(dwPBExe + ResultBasePlayer); 
DWORD BasePlayer_B = *(DWORD*)(dwPBExe + ResultBaseHealth); 
int MyIndex = GetMyCharaIndex2(); DWORD CGameCharaManager = CGameCharaBaseShoot(); 
DWORD CGameCharaBase = *(DWORD*)(BasePlayer_B + 0x14 + (MyIndex*4)); 
DWORD pNetCharaInfo = BasePlayer_A + ((ResultRespawn2) + (MyIndex*0x158)); 
SetCharaWeaponSet = (tSetCharaWeaponSet)ResultSetNetChara; 
SetCharaWeaponSet(CGameCharaManager, CGameCharaBase, pNetCharaInfo); 
	}
	}