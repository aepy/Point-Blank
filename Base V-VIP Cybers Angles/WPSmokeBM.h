//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
int DamageBombKill;
DWORD dwBasett2,dwBasettt2,dwBasetttt2,baseALEXCallHitEvent2,baseDoLineColly2,basegetVCPos2;
//=========================MODE WP SMOKE===========================//
#define OFS_GameEvent       0x8D2FC0
#define OFS_CamPosition     0x7152A0
#define OFS_DoLineCollision 0x588B30
//=========================MODE WP SMOKE===========================//
int GetTeam2(int JONES)
{
for(int i = 0; i<=15; i+=2)
if( i == JONES ) return 1;
for(int i = 1; i<=15; i+=2)
if( i == JONES ) return 2;
return 0;
}
//=========================MODE WP SMOKE===========================//
DWORD BOMB1(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
C=*(PDWORD)((DWORD)(C))+dwOfs2;
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return *(PDWORD)C; 
} }
} 
return C;
}
//=========================MODE WP SMOKE===========================//
DWORD BOMB2(DWORD dwPtr, DWORD dwOfs){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return *(PDWORD)C; 
} 
} 
return C;
}
//=========================MODE WP SMOKE===========================//
DWORD BOMB3(DWORD dwPtr){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=(*(DWORD*)(dwPtr)); 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return C; 
} 
} 
return C;
}
//=========================MODE WP SMOKE===========================//
DWORD BOMB4(DWORD dwPtr){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=((DWORD)dwPtr); 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return C; 
} 
} 
return C;
}
//=========================MODE WP SMOKE===========================//
int GetMyCharaIndexed2(unsigned int Index)
{
unsigned long dwBase	= *(DWORD*)OFS_Player2;
CTeam *MyTeam = (CTeam*) ((dwBase + OFS_TEAM));
Index=MyTeam->iTeam;
return Index;
}

//=========================MODE WP SMOKE===========================//
#define basegetVCPoss resultbasegetVCPoss

DWORD getVCPosBomb(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
dwBasettt2 = BOMB2(OFS_Ammo2, 0x544);
basegetVCPos2 = BOMB4(OFS_CamPosition);
if (!dwBasettt2)return 0;
DWORD getVCPosss;
if (dwBasettt2)
{
getVCPosss = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))basegetVCPos2)(dwBasettt2, Vect, Mat, iUnk);
}
return getVCPosss;
}
//=========================MODE WP SMOKE===========================//
DWORD BombDoLineColly1(UINT i)
{
D3DXVECTOR3	vBone, vLocal;
DWORD DoLineCollyyy;
int TargetBonex;
switch(AimBody)
{
case 0:
TargetBonex = 7; // Kepala
break;
case 1:
TargetBonex = 5; // Badan
break;
}
dwBasett2   = BOMB1(OFS_Ammo2, 0x544 , 0x2C);//0x34 Bullet Killer //0x2c Smoke //0x28 Bom
baseDoLineColly2 = BOMB4(OFS_DoLineCollision);
getVCPosBomb(&vLocal,0,0);
vBone = GetUserBonePos2(i,TargetBonex);
if (dwBasett2)
{
DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly2)(dwBasett2, &vLocal, &vBone, GetTeam2(i));
}
return DoLineCollyyy;
}

#define baseALEXCallHitEventt resultbaseALEXCallHitEventt
//=========================MODE WP SMOKE===========================//
DWORD BombCallHitEvent1(UINT i)
{
D3DXVECTOR3	vEnemy;
DWORD ALEXCallHitEventtt;
dwBasett2   = BOMB1(OFS_Ammo2, 0x544, 0x2C);//Damagenya :)//0x2C Smoke //0x28 Bom
dwBasetttt2   = BOMB3(OFS_Ammo2);
baseALEXCallHitEvent2 = BOMB4(OFS_GameEvent);
getVCPosBomb(&vEnemy,0,0);
if (dwBasett2)
{
ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent2)(dwBasett2, dwBasetttt2, &vEnemy, dwBasett2);
}
return ALEXCallHitEventtt;
}
//=========================MODE WP SMOKE===========================//
void BombCallDoLineColly1()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed2 (i))continue;
if(GetTeam2(GetMyCharaIndexed2 (i)) == GetTeam2(i))continue;
if(IsAlive(i)){
BombDoLineColly1(i);
}
}
}
//=========================MODE WP SMOKE===========================//
void BombHitEvent1()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed2 (i))continue;
if(GetTeam2(GetMyCharaIndexed2 (i)) == GetTeam2(i))continue;
BombCallHitEvent1(i);
if(IsAlive(i)){				
BombCallHitEvent1(i);
}
}
}
//=========================MODE WP SMOKE===========================//
void WPSmokeBomMission()
{
if(GetBattleState1()){
if(WPSmokeBOM==1){
BombCallDoLineColly1();
DamageBombKill=1;
}
if(WPSmokeBOM==0){
DamageBombKill=0;
}
if(DamageBombKill==1){
BombHitEvent1();
}
	}}