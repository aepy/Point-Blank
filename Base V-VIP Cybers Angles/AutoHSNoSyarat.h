//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
LPTSTR PointBlankSTR1 = "PointBlank.exe";
//====================== GET PLAYER SCREEN =====================//
DWORD GetPlayerTarget(int myIDX)
{
DWORD ModuleHandle = (DWORD)GetModuleHandleA(PointBlankSTR1);
DWORD BasePlayer_B = *(DWORD*)(ModuleHandle + OFS_Health);
if(IsBadReadPtr((void*)BasePlayer_B,4))return 0;
DWORD PlayerIndexA = *(DWORD*)(BasePlayer_B + 0x14 + (myIDX * 4));
if(IsBadReadPtr((void*)PlayerIndexA,4))return 0;
DWORD PlayerIndexB = *(DWORD*)(PlayerIndexA + 0x564);
if(IsBadReadPtr((void*)PlayerIndexB,4))return 0;
return *(DWORD*)(PlayerIndexB + 0x94E8);
}
//====================== GET PLAYER SCREEN =====================//
int GetTargetIndex(DWORD PlayerTarget)
{
DWORD ModuleHandle = (DWORD)GetModuleHandleA(PointBlankSTR1);
DWORD BasePlayer_B = *(DWORD*)(ModuleHandle + OFS_Health);
if(PlayerTarget > NULL){
if(IsBadReadPtr((void*)BasePlayer_B,4))return 0;
for(int i = 0; i<=16; i++){
DWORD PlayerIndexA = *(DWORD*)(BasePlayer_B + 0x14 + (i * 4));
if(PlayerIndexA == PlayerTarget)return i;
}
}
return -1;
}
//====================== AUTOHEADSHOT NO SYARAT =====================//
void DoAutoHSNoSyarat(LPDIRECT3DDEVICE9 pDevice){
if(GetBattleState1()){
if(AutoHS2 == 1)
{	
DWORD pMyTarget = GetPlayerTarget(GetMyCharaIndex());
if(pMyTarget > NULL)
{
DWORD TargetIndex = GetTargetIndex(pMyTarget);
D3DXVECTOR3 OnWorld,OnScreen;
GetUserBone(OnWorld,TargetIndex,7.7);
BulletEnable = true;
fX = OnWorld.x;
fY = OnWorld.y + 0.1f;
fZ = OnWorld.z;
}
else BulletEnable = false;
}
if(AutoHS2 == 0 && !AutoHS2)
{
BulletEnable = false;
}
}}

//====================== AUTOBODY =====================//
void DoAutoBody(LPDIRECT3DDEVICE9 pDevice){
if(GetBattleState1()){
if(AutoBody == 1)
{	
DWORD pMyTarget = GetPlayerTarget(GetMyCharaIndex());
if(pMyTarget > NULL)
{
DWORD TargetIndex = GetTargetIndex(pMyTarget);
D3DXVECTOR3 OnWorld,OnScreen;
GetUserBone(OnWorld,TargetIndex,5);
BulletEnable = true;
fX = OnWorld.x;
fY = OnWorld.y + 0.1f;
fZ = OnWorld.z;
}
else BulletEnable = false;
}
if(AutoBody == 0 && !AutoBody)
{
BulletEnable = false;
}
}}
