//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
#include <windows.h>
#include <winbase.h>
#include "PointBlank DxStruct.h"										
#include "PointBlank DxESP.h"
#include "Options.h"
#include "AllOffset.h"

dxESP	*DxESP;
LPTSTR PointBlankSTR4 = "PointBlank.exe";
BYTE WS_ON [2]       = {0x90, 0x90};
BYTE WS_OF [2]       = {0x75, 0x1F};
BYTE IV_ON [4]       = {0x00, 0x00, 0x00, 0x00};//"\x00\x00\x00\x00",4);
BYTE IV_OF [4]       = {0x6F, 0x12, 0x83, 0x3C};
//=========================================================================//
bool GetBattleState1() { 
	DWORD BaseG = (DWORD)GetModuleHandleA(PointBlankSTR4);
	unsigned long xBase = *(DWORD*)(BaseG + OFS_Ammo); 
	if(xBase > NULL)
	{ 
		return true; 
	} return false; 
}
//=========================================================================//
void dxESP::DrawPoint(int x, int y, int w, int h, D3DCOLOR color, LPDIRECT3DDEVICE9 pDevice )
{
    FillRGB((int)x, (int)y, (int)w, (int)h, color,pDevice);
}

//=========================================================================//

void dxESP::DrawCircle(D3DXVECTOR2 Pos,float Radius,int Sides,D3DCOLOR Color,IDirect3DDevice9* pDevice) 
{
	D3DXVECTOR2 Line[128];
	float Step = D3DX_PI * 2.0 / Sides;
	int Count = 0;
	for (float a=0; a < D3DX_PI*2.0; a += Step) {
		float X1 = Radius * cos(a) + Pos.x;
		float Y1 = Radius * sin(a) + Pos.y;
		float X2 = Radius * cos(a+Step) + Pos.x;
		float Y2 = Radius * sin(a+Step) + Pos.y;
		Line[Count].x = X1;
		Line[Count].y = Y1;
		Line[Count+1].x = X2;
		Line[Count+1].y = Y2;
		Count += 2;
	}
	float antianalias = pLine->GetAntialias();
	float gllines = pLine->GetGLLines();
	float width = pLine->GetWidth();
	pLine->Begin();
	pLine->Draw(Line,Count,Color);
	pLine->End();
	pLine->SetAntialias(antianalias);
	pLine->SetGLLines(gllines);
	pLine->SetWidth(width);
	return;
	}
//====================== Self Suicide  =====================//
typedef void (__thiscall * tCmd_Damage)(DWORD CGameCharaLocalBase, int HPDrain, int a2, int a3);
tCmd_Damage Cmd_Damage;

void KillMySelf()
{
	if(GetBattleState1()){
	DWORD ModuleHandle = (DWORD)GetModuleHandleA(PointBlankSTR4);
	Cmd_Damage = (tCmd_Damage)(ModuleHandle + Suicide);//SelfSuicide @ CMD_DAMAGE
	DWORD CGameCharaLocalBase = *(DWORD*)(ModuleHandle + OFS_Ammo);
	Cmd_Damage(CGameCharaLocalBase,0xFF,0xFFFF,false);
	}}
////----------------SC Extreme Knife-------------------//
DWORD TestPacth(DWORD dwPtr,DWORD A1,DWORD B1,DWORD C1)
{
	DWORD C=0;
	if (IsBadReadPtr((PDWORD)dwPtr,4)==0){
	C=*(PDWORD)((DWORD)(dwPtr))+A1;
	if (IsBadReadPtr((PDWORD )C,4)==0){
	C=*(PDWORD)((DWORD)(C ))+ B1;
	if (IsBadReadPtr((PDWORD)C,4)==0) {
	C=*(PDWORD)((DWORD)(C ))+ C1;
	if (IsBadReadPtr((PDWORD)C,4)==0) {
	return *(PDWORD)C; } } }
	}
	return C;
}
//-----------------------------------------------------//
bool bPiso = false;
DWORD PisoGila = 0;
void PisoGile(void)
{
if(bPiso == false){
PisoGila = TestPacth( OFS_Ammo2	, 0x544, 0x24, 0xC94);
}
if(Knife == 0){
bPiso = false;
PacthWeapone( OFS_Ammo2, 0x544, 0x24, 0xC94, PisoGila);
}
if(Knife == 1){
bPiso = true;
PacthWeapone( OFS_Ammo2, 0x544, 0x24, 0xC94, PisoGila);
}
}
//====================== Ghost Hide  =====================//
DWORD Ghoster;
bool bGhost = false;
void GhostHide()
{
DWORD AdrBaseAmoo = OFS_Ammo + (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD pBase = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD PtrAdr = *(PDWORD)(pBase + OFS_Player);
DWORD PtrHP  = *(PDWORD)(pBase + OFS_Health);
CTeam* GetSlot	= (CTeam*)(PtrAdr + OFS_TEAM);
CHealth* GetHealth = (CHealth*)((PtrHP + 0x264) + GetSlot->iTeam * 0x20);
if(*(PBYTE)(OFS_Player + 0x400000)> 0x01){
if(bGhost == false){
Ghoster = Read( OFS_Health + 0x400000, 0x260 + GetSlot->iTeam * 0x20);
}}
if(Zombie==0){
bGhost = false;
_patchPTRZ( OFS_Health + 0x400000, 0x260 + GetSlot->iTeam * 0x20, Ghoster);
}
if(*(PBYTE)AdrBaseAmoo > 0x01)
{
if(GetHealth->CurHP > 0)
{
if(GetBattleState1()){
if(Zombie==1){
KillMySelf();
bGhost = true;
_patchPTRZ( OFS_Health + 0x400000, 0x260 + GetSlot->iTeam * 0x20, Ghoster-1);
}}
if(GetHealth->CurHP < 0){
_patchPTRZ( OFS_Health + 0x400000, 0x260 + GetSlot->iTeam * 0x20, Ghoster);
}}
}}
//-------------------------------------------------------------------------------------------------------------------------------------|| FAKE REPLACE
//DWORD WINAPI REPLACE(LPVOID param)
//{
//while(1)
//{
//if(GetAsyncKeyState(VK_F2)&1)
//{
//HACK = !HACK;MessageBeep(MB_ICONINFORMATION);
//}
//if(HACK)
//{
//if(HACK>0)// <------- Ini yg Gx work..............!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
//{
//int i;
//for (i = 0 ; i <= 43 ; i++)
//{
//DWORD pBase = (DWORD)GetModuleHandleA("PointBlank.exe");
//MakePoint(pBase+(DWORD)0x64D998,0x6D8 + (i*0x150),0x5F61F82);//RPG
//}
//}
//}
//Sleep(100);
//}
//return 0;
//}

//-------------------------------------------------------------------------------------------------------------------------------------|| REPLACE HACK
DWORD WINAPI ReplaceHOT(LPVOID param)
{
ZRCReplaceON:
//--------------------------------------------------------------->
if(WPSmoke)
{
if(WPSmoke == 1){
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM);{
MakePoint(OFS_Player2, 0x28020 + 0x10 + (GetSlot->iTeam * 0x158), 0x35E20D64);// WPSmoke D
}}
//--------------------------------------------------------------->
if(WPSmoke == 2){
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM);{
MakePoint(OFS_Player2, 0x28020 + 0x10 + (GetSlot->iTeam * 0x158), 0x35E20D61);//Bread Granade
}}
//--------------------------------------------------------------->
if(WPSmoke == 3){
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM);{
MakePoint(OFS_Player2, 0x28020 + 0x10 + (GetSlot->iTeam * 0x158), 0x35E20D6C);//Candy Granade
}}
//--------------------------------------------------------------->
if(WPSmoke == 4){
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM);{
MakePoint(OFS_Player2, 0x28020 + 0x10 + (GetSlot->iTeam * 0x158), 0x35E20D6F);//Lantern Granade
}}
//--------------------------------------------------------------->
if(WPSmoke == 5){
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM);{
MakePoint(OFS_Player2, 0x28020 + 0x10 + (GetSlot->iTeam * 0x158), 0x35E20D72);//Decoy Bomb
}}
}
Sleep(0);
goto ZRCReplaceON;
}
//---------------------------------------------------------------> Fake Replace
DWORD WINAPI CyberAngelsHack(LPVOID param)
{
Queen:
{
if(GetAsyncKeyState(VK_F2)&1)
{
R_Granad = !R_Granad;;
FamasLC = !FamasLC;;
Pistol = !Pistol;;
RPG = !RPG;;
}
//=============== Replace Granad Mamoul ===========================================================//
if (R_Granad==1) { 
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM); { 
WriteSimpleOther(OFS_Player2,  0x28030 + (GetSlot->iTeam * 0x158), 0x35E20D5D);////WP Smoke
}}
if (R_Granad==2) { 
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM); { 
WriteSimpleOther(OFS_Player2,  0x28030 + (GetSlot->iTeam * 0x158), 0x35E20D64);////WP Smoke ++
}}
if (R_Granad==3) { 
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM); { 
WriteSimpleOther(OFS_Player2, 0x28030 + (GetSlot->iTeam * 0x158), 0x35E20D61);//Chocolate Grenade
}}
if (R_Granad==4) { 
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM); { 
WriteSimpleOther(OFS_Player2, 0x28030 + (GetSlot->iTeam * 0x158), 0x35E20D6C);//Candy Grenade
}}
if (R_Granad==5) { 
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM); { 
WriteSimpleOther(OFS_Player2, 0x28030 + (GetSlot->iTeam * 0x158), 0x35E20D6F);//Lantern Grenade
}}
if (R_Granad==6) { 
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM); { 
WriteSimpleOther(OFS_Player2, 0x28030 + (GetSlot->iTeam * 0x158), 0x35E20D70);//Bread Grenade
}}
if (R_Granad==7) { 
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM); { 
WriteSimpleOther(OFS_Player2, 0x28030 + (GetSlot->iTeam * 0x158), 0x35E20D72);//Decoy bom 
}}
//=============== Replace Launcher ===========================================================// 
if (FamasLC==1) { unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM); { 
WriteSimpleOther(OFS_Player2, 0x28020 + (GetSlot->iTeam * 0x158), 0x5F5ECEC);//Famas Launcher 
}}
if (FamasLC==2) { unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM); { 
WriteSimpleOther(OFS_Player2, 0x28020 + (GetSlot->iTeam * 0x158), 0x5F5ECC3);//K-201 Exit
}}
if (FamasLC==3) { unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM); { 
WriteSimpleOther(OFS_Player2, 0x28020 + (GetSlot->iTeam * 0x158), 0x5F5ECF2);//AK 47 FC
}}
if (RPG==1) { unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM); { 
WriteSimpleOther(OFS_Player2, 0x28020 + (GetSlot->iTeam * 0x158), 0x5F61F83);//Bazoka
}}
if (Pistol==1) { unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM); { 
WriteSimpleOther(OFS_Player2, 0x28024 + (GetSlot->iTeam * 0x158), 0x23D2BEF6);//Dual Handgun
}}
if (Pistol==2) { unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM); { 
WriteSimpleOther(OFS_Player2, 0x28024 + (GetSlot->iTeam * 0x158), 0x23D2902A);//HK-64
}}
Sleep(100);
goto Queen;
}
}
//=========================================================================//
DWORD WINAPI ZRCHack(LPVOID param){
while(1){
//====================== Rank Skill  =====================//
if(autoGM==1){
DWORD dwI3EXEC			= (DWORD)GetModuleHandleA(PointBlankSTR4);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + OFS_Player);
CTeam *pTeam		= ((CTeam*)(dwBase + OFS_TEAM)); 
int MyTeam = DxESP->GetTeam(pTeam->iTeam);
for (int i = 0; i <= 15 ; i++){
GM	  *DualDinamic = (GM*)((dwBase + OFS_RANK2)+ pTeam->iTeam * RANKSIZE);
CHANGENICK1	  *NICK1 = (CHANGENICK1*)((dwBase + OFS_NAMES)+ pTeam->iTeam * NAMESIZE);
CHANGENICK2	  *NICK2 = (CHANGENICK2*)((dwBase + OFS_NAMES+0x4)+ pTeam->iTeam * NAMESIZE);
CHANGENICK3	  *NICK3 = (CHANGENICK3*)((dwBase + OFS_NAMES+0x8)+ pTeam->iTeam * NAMESIZE);
CHANGENICK4	  *NICK4 = (CHANGENICK4*)((dwBase + OFS_NAMES+0xC)+ pTeam->iTeam * NAMESIZE);
if(autoGM==1){
MakePoint(OFS_Player2, ALLWEAPSIZE4 + (pTeam->iTeam*WEAPSIZE), 0x41BE7D7E);// 
MakePoint(OFS_Player2, ALLWEAPSIZE5 + (pTeam->iTeam*WEAPSIZE), 0x41AF3B3F);// 
DualDinamic->iRank = 0x35; // B4
DualDinamic->iHack = 0xFFFFFF;
//NICK1->iName1=0x42504D47;
//NICK2->iName2=0x6279435F;
//NICK3->iName3=0x6E417265;
//NICK4->iName4=0x736C6567;
NICK1->iName1=0x2405D474;
NICK2->iName2=0x765625F5;
NICK3->iName3=0xF6462716;
NICK4->iName4=0x4756E4;
}}}
//====================== Protec Program Ilegal  =====================//
DWORD dwExe = (DWORD)GetModuleHandleA(PointBlankSTR4);
if(dwExe > 0)
{
DWORD AntiPI = dwExe + resultOFS_Unfreeze1;
DWORD AntiPI1 = dwExe + resultOFS_Unfreeze2;
Error_Log((void *)(AntiPI),(void*)(PBYTE)"\x00\x00\x00\x00",4);
Error_Log((void *)(AntiPI1),(void*)(PBYTE)"\x00\x00\x00\x00",4);
}
//==========================================BRUTAL=====================================================
if(BRUTAL==1){
if(GetAsyncKeyState(0x01)&&0x8000){
if(IsBadReadPtr((void*)OFS_Ammo2,4)==0)
{
DWORD TheRead = *(PDWORD)((DWORD)(OFS_Ammo2))+0x544;
if(IsBadReadPtr((void*)TheRead,4)==0)
{
DWORD ReadKe1 = *(PDWORD)((DWORD)(TheRead))+0x38;
if(IsBadReadPtr((void*)ReadKe1,4)==0)
{
*(PDWORD)ReadKe1=0x02;
Sleep(250);
}}}}}
//------------------------------------------------------------------------------------------------// [RAPID FIRE]
if ( RapitFire ){
Function_Two(OFS_Ammo2, 0x544, 0x38,0x02);
Sleep(120);}
//-------------------- Freeze Respawn --------------------||
if(RespawnTerus) { 
PatchValue(OFS_Ammo2, 0x18, 0x18, 0xE8, 1069715291);
}
//------------------------------------------------------------------------------------------------//[KNIFE KILLER]
if(WeaponFire){
WeaponHack2(OFS_Ammo2,0x53C,0x20,0x41);
}
//----------------- No Respawn -----------------------//
//#define g_pGameFramework			0x49D854 
//#define g_pGameControl 				(g_pGameFramework+0x3C) 
//---------------------------------------------------------
//if(NoRespawn)
//{
//__try
//{
//*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(g_pGameControl)+0x24)+0x24)+0x7C)=1084227584;
//}__except(EXCEPTION_EXECUTE_HANDLER){}
//} 
//====================== Magnet Burning Hall =====================//
if(Magnet ==1){
DWORD Frameon= (DWORD)LoadLibraryA("i3FrameWorkDx.dll");
PrivateOnly((void *)(Frameon + 0xADC5D),(int*)(PBYTE)"\xC0\x20",2);
Sleep(4);
}
if(Magnet ==0){
DWORD Frameoff= (DWORD)LoadLibraryA("i3FrameWorkDx.dll");
PrivateOnly((void *)(Frameoff + 0xADC5D),(int*)(PBYTE)"\xC0\x30",2);
Sleep(4);
}
//====================== Magnet Red Rock =====================//
if(MagnetAll==1){ DWORD Frameon= (DWORD)LoadLibraryA("i3FrameWorkDx.dll"); 
PrivateOnly((void *)(Frameon + 0xADC5D),(int*)(PBYTE)"\x30",1); 
Sleep(2); 
} 
if(MagnetAll==0){ DWORD Frameoff= (DWORD)LoadLibraryA("i3FrameWorkDx.dll"); 
PrivateOnly((void *)(Frameoff + 0xADC5D),(int*)(PBYTE)"\xC0",1); 
Sleep(2); 
}
//====================== Magnet Luxville =====================//
if(MagnetLux==1){
DWORD Frameon= (DWORD)LoadLibraryA("i3FrameWorkDx.dll");
PrivateOnly((void *)(Frameon + 0xADC5D),(int*)(PBYTE)"\x30",1);
Sleep(2);
}
if(MagnetLux==0){
DWORD Frameoff= (DWORD)LoadLibraryA("i3FrameWorkDx.dll");
PrivateOnly((void *)(Frameoff + 0xADC5D),(int*)(PBYTE)"\xC0",1);
Sleep(2);
}
//==================================Pasang bom 0 Detik Or Pasang===================================//Not Fix
//if ( PasangBom==1 ) { 
//DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
//DWORD adrPlant = ModulePB + 0x49B040;
//DWORD adrDefuse = ModulePB + 0x49B649;
//PrivateOnly((void *)(adrPlant),(int*)(PBYTE)"\x00\x00\xA0\x00",4);
//PrivateOnly((void *)(adrDefuse),(int*)(PBYTE)"\x00\x00\xE0\x00",4);
//Sleep(4);
//}
//==============================Kick Enemy==========================================//DC
//DWORD  AdrX3,AdrX4;
////--------------
//if(Kick_Enemy==1) {//on
//DWORD Enemy = (DWORD)GetModuleHandleA("PointBlank.Exe");
//if (Enemy > 0)
//if (Enemy > 0)
//if (Enemy > 0){
//AdrX3 = Enemy + 0x4C3BD6;
//PrivateOnly((void*)AdrX3, (void*)(PBYTE)"\x84\x41",2);
//}}
//
//if(Kick_Enemy==0) {//oFF
//DWORD Enemy = (DWORD)GetModuleHandleA("PointBlank.Exe");
//if (Enemy > 0)
//if (Enemy > 0)
//if (Enemy > 0){
//AdrX4 = Enemy + 0x4C3BD6;
//PrivateOnly((void*)AdrX4, (void*)(PBYTE)"\x84\x3F",2);
//}}
//=========================================== Gravity ================================================//
if(CH_Terbang==1) // Terbang ON
{
DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD GM = ModulePB + 0x60A04D;
PrivateOnly((void *)(GM),(int*)(PBYTE)"\x00\xCC\x3C", 3);//ON
Sleep(4);
}
if(CH_Terbang==0) // Terbang Off
{
DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD GM = ModulePB + 0x60A04D;
PrivateOnly((void *)(GM),(int*)(PBYTE)"\00\xE0\x3F",3);//OFF
Sleep(4);
}
//==============================Invicible==========================================//
if(Invicible==1){//on
DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD GM = ModulePB + 0x625A94;
PrivateOnly((void *)(GM),(int*)(PBYTE)"\x6F\x12\x83\x40",4);
}
if(Invicible==0){//off
DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD GM = ModulePB + 0x625A94;
PrivateOnly((void *)(GM),(int*)(PBYTE)"\x6F\x12\x83\x3C",4);
}
//---------------------- Death Fly --------------------------------
//if(DeathFly ==1){
//DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
//PrivateOnly((void*)(ModulePB  + 0x64CA48),(void*)(PBYTE)"\xA0",1);
//Sleep(4);
//}
//if(DeathFly ==0){
//DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
//PrivateOnly((void*)(ModulePB  + 0x64CA48),(void*)(PBYTE)"\x47",1);
//Sleep(4);
//}
//====================== WallShot  =====================//
if(GetBattleState1()){
if(WSBrooK2 ==1){
DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
PrivateOnly((void*)(ModulePB + 0x182F97),(void*)WS_ON,2);
}
if(WSBrooK2 ==0){
DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
PrivateOnly((void*)(ModulePB + 0x182F97),(void*)WS_OF,2);
}}
//====================== Without Recoil  =====================//
if(GetBattleState1()){
if (antigyg == 1) { 
for (int i6 = 0x20; i6 <= 0x50; i6 += 4 ) 
WeaponHack2(OFS_Ammo2, resultOFS_WPointer2, i6, 0x00000000); }}

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
//====================== Rafid Fire  =====================//
if(frpid==1){
__try
{
if (*(DWORD*)(*(DWORD*)(*(DWORD*)(OFS_Ammo2)+resultOFS_WPointer1)+0x38)==1){
*(DWORD*)(*(DWORD*)(*(DWORD*)(OFS_Ammo2)+0x30)+resultOFS_WPointer5)=0;
*(DWORD*)(*(DWORD*)(OFS_Ammo2)+resultOFS_WPointer6)=0;
}
if (*(DWORD*)(*(DWORD*)(*(DWORD*)(OFS_Ammo2)+resultOFS_WPointer1)+0x38)==0){
*(DWORD*)(*(DWORD*)(*(DWORD*)(OFS_Ammo2)+0x30)+resultOFS_WPointer5)=0;
*(DWORD*)(*(DWORD*)(OFS_Ammo2)+resultOFS_WPointer6)=0;
}
} __except ( EXCEPTION_EXECUTE_HANDLER ) {}
}
//====================== BUG WS  =====================//
if(BugWS ==1){
DWORD pBaseX = (DWORD)GetModuleHandleA("Pointblank.exe");
PrivateOnly((void *)(pBaseX + 0x68876F),(int*)(PBYTE)"\xC0",4);
}

if(BugWS ==0){
DWORD pBaseX = (DWORD)GetModuleHandleA("Pointblank.exe");
PrivateOnly((void *)(pBaseX + 0x68876F),(int*)(PBYTE)"\xBE",4);
}
//==============================================================================//
if(BugHvr==1){
DWORD NxCharakter1 = (DWORD)LoadLibraryA("NxCharacter.2.8.1.dll")+ 0x110A3; //89 41 68 C3 CC CC
DWORD NxCharakter2 = (DWORD)LoadLibraryA("NxCharacter.2.8.1.dll")+ 0x16510; //89 8B 34 01 00 00
PrivateOnly((void *)(NxCharakter1),(int*)(PBYTE)"\x89\x41\x64",3);
PrivateOnly((void *)(NxCharakter2),(int*)(PBYTE)"\x89\x8B\x38",3);
}
if(BugHvr==0){
DWORD NxCharakter1 = (DWORD)LoadLibraryA("NxCharacter.2.8.1.dll")+ 0x110A3;
DWORD NxCharakter2 = (DWORD)LoadLibraryA("NxCharacter.2.8.1.dll")+ 0x16510;
PrivateOnly((void *)(NxCharakter1),(int*)(PBYTE)"\x89\x41\x68",3);
PrivateOnly((void *)(NxCharakter2),(int*)(PBYTE)"\x89\x8B\x34",3);
}
//====================== Without Fall Damage  =====================//
DWORD fBase = (DWORD)GetModuleHandleA(PointBlankSTR4);
if(GetBattleState1()){
if(FallDamage==1)
{
_patchPTRZ(OFS_Ammo2, 0x513, 14);
_patchPTRZ(OFS_Ammo2, 0x513, 172);
_patchPTRZ(OFS_Ammo2, 0x513, 4);
_patchPTRZ(OFS_Ammo2, 0x513, 64);
}}

//====================== Anti Idle  =====================//
if(GetBattleState1()){
if(AntiOut==1)
{
WeaponHack2(BaseVK2 , 0x18, resultOFS_PIdle1, 0x41); // Mengikuti ESP
WeaponHack2(BaseVK2 , 0x18, resultOFS_PIdle2, 0x42);
}}
//====================== Quick Change  =====================//
if(GetBattleState1()){
if(qece==1){
WeaponHack1(OFS_Ammo2, resultOFS_PQC, 0xEC, 0x64, 1069715291);
}}
//---------------- Ammo Kiri ------------------------//
if(AmmoKiri==1) 
{ 
PacthWeapone( OFS_Ammo2, 0x544, 0x1C, 0xC98, 0x5F61F82); 
}
//====================== Free Move =================================//
if(FreeMove== 1){
PatchValue(resultOFS_Ammo2,0x544,0x11C,0x1E0,0x04);
}
//====================== Speed Hack  =====================//
if(GetBattleState1()){
if(Speed==1){ 
DWORD NxCharakter1111 = (DWORD)LoadLibraryA("PointBlank.exe");
PrivateOnly((int*)(NxCharakter1111 + 0x604CD0),(int*)(PBYTE)"\x00\x00\x00\x40\xE1\x7A\x8c\x3F", 8);
}}
//====================== Brutal Shootgun & Sniper  =====================//
if (fsspd==1){
Function_Two(OFS_Ammo2, 0x544, 0x38,0x02);
Sleep(38);}
//====================== Shootgun & Sniper No Kokang  =====================//
if(sgnokokang == 1)
{
__try{
*(BYTE*)(*(DWORD*)(OFS_Ammo2)+ 0x544)=00;
}__except ( true ) {}
}
//-------------------------------------------------------------------------------// [RELOAD MAJOR]
if(ReloadMayor == 1)
{
__try
{
*(DWORD*)(*(DWORD*)(*(DWORD*)(OFS_Player2)+0x2738C)+0x08)=0x41AF3B3E;
*(DWORD*)(*(DWORD*)(*(DWORD*)(OFS_Player2)+0x2738C)+0x0C)=0x41BE7D7E;
}__except(EXCEPTION_EXECUTE_HANDLER){
}
}
//====================== Fast Reload =====================//
if(GetBattleState1()){
if(Nrld==1){
			__try
			{
			*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(OFS_Ammo2) + resultOFS_WPointer1) + 0x1C) + 0x30) + 0x67)= 65;
			}__except (EXCEPTION_EXECUTE_HANDLER){
}}}
//====================== Unlimited Ammo  =====================//
if(GetBattleState1()){
if(wutmo==1){
__try
{
*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(OFS_Ammo2) + resultOFS_WPointer1) + 0x1C) + resultOFS_WPointer4)= 1;
}__except (EXCEPTION_EXECUTE_HANDLER){
}}}
//====================== Unlimited Ammo Pistol =====================//
if(GetBattleState1()){
if(wutmo==1){
			__try
			{
			*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(OFS_Ammo2) + resultOFS_WPointer1) + 0x20) + resultOFS_WPointer4)= 2;
			}__except (EXCEPTION_EXECUTE_HANDLER){
}}}
//====================== Unlimited Ammo Pistol =====================//
if(GetBattleState1()){
if(wutmo==1){
			__try
			{
			*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(OFS_Ammo2) + resultOFS_WPointer1) + 0x30) + resultOFS_WPointer4)= 6;
			}__except (EXCEPTION_EXECUTE_HANDLER){
}}}

//====================== Plant Bomb Everywhere  =====================//
if(GetBattleState1()){
if(BombEnywhere == 1){
cGameBases *GameBase = (cGameBases*) *(DWORD*)(OFS_Player);
DWORD dwbase = *(DWORD*)(OFS_Player2);
CTeam *pTeam = ((CTeam*)(dwbase + OFS_TEAM));
DWORD pCalculate2 = *(DWORD*)(dwbase + 0x4 * pTeam->iTeam + OFS_Player);
CPlayers *Me = (CPlayers*)(pCalculate2 + 0x64);
GameBase->StageInfo->BombPositionA.x = Me->pos.x;
GameBase->StageInfo->BombPositionA.y = Me->pos.y;
GameBase->StageInfo->BombPositionA.z = Me->pos.z;
GameBase->StageInfo->BombPositionB.x = Me->pos.x;
GameBase->StageInfo->BombPositionB.y = Me->pos.y;
GameBase->StageInfo->BombPositionB.z = Me->pos.z;
}}
//===============================//
if(GetAsyncKeyState(VK_F12)&1){
MessageBeep(0);
Beep(1000,100);
ExitProcess(0);
}
//===============================//
if(GetBattleState1()){
if(GetAsyncKeyState(VK_F4)&1){
Accuracy=!Accuracy;
MessageBeep(0);
Beep(1000,100);
}}
//===============================//
//if(GetBattleState1()){
//if(GetAsyncKeyState(VK_NUMPAD4)&1){
//	FloodVK=!FloodVK;
//}}
//===============================//
if(GetBattleState1()){
if(GetAsyncKeyState(VK_F5)&1){
Zombie=!Zombie;
MessageBeep(0);
Beep(1000,100);
}}
//===============================//
if(GetBattleState1()){
if(GetAsyncKeyState(VK_F6)&1){
BulletKiller=!BulletKiller;
MessageBeep(0);
Beep(1000,100);
}}
//===============================//
if(GetBattleState1()){
if(GetAsyncKeyState(VK_F7)&1){
WPSmokeKill=!WPSmokeKill;
MessageBeep(0);
Beep(1000,100);
}}
//===============================//
if(GetBattleState1()){
if(GetAsyncKeyState(VK_F9)&1){
Invicible=!Invicible;
MessageBeep(0);
Beep(1000,100);
}}
//===============================//
if(GetBattleState1()){
if(GetAsyncKeyState(VK_F10)&1){
WSBrooK2=!WSBrooK2;
MessageBeep(0);
Beep(1000,100);
}}
//===============================//
if(GetBattleState1()){
if(GetAsyncKeyState(VK_NUMPAD1)&1)
{
KillMySelf();
WPSmokeBOM = 1;
MagnetLux = 1;
Invicible = 1;
WSBrooK2 = 1;
MessageBeep(0);
Beep(1000,100);
}}
//===============================//
if(GetBattleState1()){
if(GetAsyncKeyState(VK_NUMPAD2)&1)
{
KillMySelf();
WPSmokeBOM = 0;
MagnetLux = 0;
Invicible = 0;
WSBrooK2 = 0;
MessageBeep(0);
Beep(1000,100);
}}
//=========Untuk Auto OFF Fiture===========//
if(GetAsyncKeyState(VK_RCONTROL)&1){
Zombie = 0;
HOT = 0;
Invicible = 0;
WSBrooK2 = 0;
Magnet = 0;
BulletKiller = 0;
ModeFloodVoteKick = 0;
BommKiller = 0;
WPSmokeKill = 0;
RespawnTerus = 0;
CH_Terbang = 0;
GranadeCall = 0;
MessageBeep(0);
Beep(1000,100);
}
//=========Untuk Auto ON Fiture===========//
if(GetAsyncKeyState(VK_DELETE)&1){
Invicible = 1;
WSBrooK2 = 1;
WPSmokeKill = 1;
MessageBeep(0);
Beep(1000,100);
}
//===============================//
Sleep(10);
}
return 0;
}
