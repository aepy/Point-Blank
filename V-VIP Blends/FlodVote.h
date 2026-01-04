//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
LPTSTR PointBlankSTR3 = "PointBlank.exe";
//========================================================================//
class PlayerKickData
{
public:
	int Index;
	int Reason;
};
//========================================================================//
bool IsAlive1(int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR3);
unsigned long dwBase2	= *(DWORD*)(dwI3EXEC + OFS_Health);
CHealth		*Health		= (CHealth*) ((dwBase2 + OFS_HEALTH) + Index * 0x20);
if(Health->CurHP > NULL)
return true;
return false;
}
//========================================================================//
int GetMyCharaIndex1()
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR3);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + OFS_Player);
unsigned long dwBase2	= *(DWORD*)(dwI3EXEC + OFS_Player-0x34);
CTeam *MyTeam = (CTeam*) ((dwBase + OFS_TEAM));
return MyTeam->iTeam;
}
//========================================================================//
bool GetBattleState() { 
	DWORD BaseG = (DWORD)GetModuleHandleA(PointBlankSTR3);
	unsigned long xBase = *(DWORD*)(BaseG + OFS_Ammo); 
	if(xBase > NULL)
	{ 
		return true; 
	} return false; 
}
//---------------------------Flod Kick Flayer---------------------//
DWORD PTR_Caller,BaseECX,CallBasePB,Definition,ReDefinition,ReadProcASM, StartRouneAmmo= NULL;
void FloodKickPlayer(int IndexPlayer) {
Sleep(100);
if(Keprox == false){
CallBasePB = (DWORD)GetModuleHandle("Pointblank.exe");
PTR_Caller = (DWORD)(CallBasePB + 0x150160);
BaseECX = *(DWORD*)(CallBasePB + 0x7BEF80);
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
DWORD WINAPI ThreadFloodVK()
{
while(1)
{
if(ModeFloodVoteKick == 1)
{
Sleep(100);
Keprox = false;
if(*(PBYTE)0xBBEF48 > NULL){
Sleep(5);
for (int i = 0; i<=15; i++){
int MySlot = GetMyCharaIndex(); 
if( i == MySlot)continue; 
FloodKickPlayer(i);
}}}
Sleep(100);
}
return 0;
}
//========================================================================//