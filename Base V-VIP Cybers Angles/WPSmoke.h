//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
DWORD dwBasett,dwBasettt,dwBasetttt,baseALEXCallHitEvent,baseDoLineColly,basegetVCPos;
LPTSTR PointBlankSTR8 = "PointBlank.exe";
//============================================================================//
int GetTeam1(int JONES)
{
for(int i = 0; i<=15; i+=2)
if( i == JONES ) return 1;
for(int i = 1; i<=15; i+=2)
if( i == JONES ) return 2;
return 0;
}
//============================================================================//
DWORD HELJUNAI_SYAHPUTRA1(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
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
//============================================================================//
DWORD HELJUNAI_SYAHPUTRA2(DWORD dwPtr, DWORD dwOfs){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return *(PDWORD)C; 
} 
} 
return C;
}
//============================================================================//
DWORD HELJUNAI_SYAHPUTRA3(DWORD dwPtr){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=(*(DWORD*)(dwPtr)); 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return C; 
} 
} 
return C;
}
//============================================================================//
DWORD HELJUNAI_SYAHPUTRA4(DWORD dwPtr){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=((DWORD)dwPtr); 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return C; 
} 
} 
return C;
}
//============================================================================//
int GetMyCharaIndexed(unsigned int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR8);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + OFS_Player);
CTeam *MyTeam = (CTeam*) ((dwBase + OFS_TEAM));
Index=MyTeam->iTeam;
return Index;
}

//============================================================================//
DWORD getVCPos(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
dwBasettt = HELJUNAI_SYAHPUTRA2(OFS_Ammo2, resultpointer4baseALEXCallHitEvent);
basegetVCPos = HELJUNAI_SYAHPUTRA4(resultbasegetVCPoss);
if (!dwBasettt)return 0;
DWORD getVCPosss;
if (dwBasettt)
{
getVCPosss = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))basegetVCPos)(dwBasettt, Vect, Mat, iUnk);
}
return getVCPosss;
}
//=========================MODE WP SMOKE===========================//
DWORD Jhunay_DoLineColly1(UINT i)
{
D3DXVECTOR3	vBone, vLocal;
DWORD DoLineCollyyy;
int TargetBonex;
switch(AimBody)
{
case 0:
TargetBonex = 7.7; // Kepala
break;
case 1:
TargetBonex = 5; // Badan
break;
case 2:
TargetBonex = 2; // Perut
break;
case 3:
TargetBonex = 0; // Vital
break;
case 4:
TargetBonex = 12; // Pinggang Kiri
break;
case 5:
TargetBonex = 13; // Pinggang Kanan
break;
case 6:
TargetBonex = 14; // Lutut Kiri
break;
case 7:
TargetBonex = 15; // Lutut Kanan
break;
case 8:
TargetBonex = 8; // Kaki Kiri
break;
case 9:
TargetBonex = 9; // Kaki Kanan
break;
case 10:
TargetBonex = 10; // Tangan Kiri
break;
case 11:
TargetBonex = 11; // Tangan Kanan
break;
}
dwBasett   = HELJUNAI_SYAHPUTRA1(OFS_Ammo2, 0x544 , 0x2C); 
baseDoLineColly = HELJUNAI_SYAHPUTRA4 (resultbaseDoLineCollyy);
getVCPos(&vLocal,0,0);
vBone = GetUserBonePos2(i,TargetBonex);
if (dwBasett)
{
DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
}
return DoLineCollyyy;
}
//=========================MODE WP SMOKE===========================//
DWORD Jhunay_DoLineColly2(UINT i)
{
D3DXVECTOR3	vBone, vLocal;
DWORD DoLineCollyyy;
int TargetBonex;
switch(AimBody)
{
case 0:
TargetBonex = 7.7; // Kepala
break;
case 1:
TargetBonex = 5; // Badan
break;
case 2:
TargetBonex = 2; // Perut
break;
case 3:
TargetBonex = 0; // Vital
break;
case 4:
TargetBonex = 12; // Pinggang Kiri
break;
case 5:
TargetBonex = 13; // Pinggang Kanan
break;
case 6:
TargetBonex = 14; // Lutut Kiri
break;
case 7:
TargetBonex = 15; // Lutut Kanan
break;
case 8:
TargetBonex = 8; // Kaki Kiri
break;
case 9:
TargetBonex = 9; // Kaki Kanan
break;
case 10:
TargetBonex = 10; // Tangan Kiri
break;
case 11:
TargetBonex = 11; // Tangan Kanan
break;
}
dwBasett   = HELJUNAI_SYAHPUTRA1(OFS_Ammo2, 0x544 , 0x2C); 
baseDoLineColly = HELJUNAI_SYAHPUTRA4 (resultbaseDoLineCollyy);
getVCPos(&vLocal,0,0);
vBone = GetUserBonePos2(i,TargetBonex);
if (dwBasett)
{
DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
}
return DoLineCollyyy;
}
//=========================MODE WP SMOKE===========================//
DWORD Jhunay_DoLineColly3(UINT i)
{
D3DXVECTOR3	vBone, vLocal;
DWORD DoLineCollyyy;
int TargetBonex;
switch(AimBody)
{
case 0:
TargetBonex = 7.7; // Kepala
break;
case 1:
TargetBonex = 5; // Badan
break;
case 2:
TargetBonex = 2; // Perut
break;
case 3:
TargetBonex = 0; // Vital
break;
case 4:
TargetBonex = 12; // Pinggang Kiri
break;
case 5:
TargetBonex = 13; // Pinggang Kanan
break;
case 6:
TargetBonex = 14; // Lutut Kiri
break;
case 7:
TargetBonex = 15; // Lutut Kanan
break;
case 8:
TargetBonex = 8; // Kaki Kiri
break;
case 9:
TargetBonex = 9; // Kaki Kanan
break;
case 10:
TargetBonex = 10; // Tangan Kiri
break;
case 11:
TargetBonex = 11; // Tangan Kanan
break;
}
dwBasett   = HELJUNAI_SYAHPUTRA1(OFS_Ammo2, 0x544 , 0x2C); 
baseDoLineColly = HELJUNAI_SYAHPUTRA4 (resultbaseDoLineCollyy);
getVCPos(&vLocal,0,0);
vBone = GetUserBonePos2(i,TargetBonex);
if (dwBasett)
{
DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
}
return DoLineCollyyy;
}
//=========================MODE WP SMOKE===========================//
DWORD Jhunay_CallHitEvent1(UINT i)
{
D3DXVECTOR3	vEnemy;
DWORD ALEXCallHitEventtt;
dwBasett   = HELJUNAI_SYAHPUTRA1(OFS_Ammo2, 0x544, 0x2C);
dwBasetttt   = HELJUNAI_SYAHPUTRA3(OFS_Ammo2);
baseALEXCallHitEvent = HELJUNAI_SYAHPUTRA4(resultbaseALEXCallHitEventt);
getVCPos(&vEnemy,0,0);
if (dwBasett)
{
ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
}
return ALEXCallHitEventtt;
}
//=========================MODE WP SMOKE===========================//
DWORD Jhunay_CallHitEvent2(UINT i)
{
D3DXVECTOR3	vEnemy;
DWORD ALEXCallHitEventtt;
dwBasett   = HELJUNAI_SYAHPUTRA1(OFS_Ammo2, 0x544, 0x2C);
dwBasetttt   = HELJUNAI_SYAHPUTRA3(OFS_Ammo2);
baseALEXCallHitEvent = HELJUNAI_SYAHPUTRA4(resultbaseALEXCallHitEventt);
getVCPos(&vEnemy,0,0);
if (dwBasett)
{
ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
}
return ALEXCallHitEventtt;
}
//=========================MODE WP SMOKE===========================//
DWORD Jhunay_CallHitEvent3(UINT i)
{
D3DXVECTOR3	vEnemy;
DWORD ALEXCallHitEventtt;
dwBasett   = HELJUNAI_SYAHPUTRA1(OFS_Ammo2, 0x544, 0x2C);
dwBasetttt   = HELJUNAI_SYAHPUTRA3(OFS_Ammo2);
baseALEXCallHitEvent = HELJUNAI_SYAHPUTRA4(resultbaseALEXCallHitEventt);
getVCPos(&vEnemy,0,0);
if (dwBasett)
{
ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
}
return ALEXCallHitEventtt;
}
//=========================MODE WP SMOKE===========================//
void Jhunay_CallDoLineColly1()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(IsAlive(i)){
Jhunay_DoLineColly1(i);
Jhunay_DoLineColly2(i);
Jhunay_DoLineColly3(i);
}
}
}
//=========================MODE WP SMOKE===========================//
void Jhunay_CallDoLineColly2()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(IsAlive(i)){
Jhunay_DoLineColly1(i);
Jhunay_DoLineColly2(i);
Jhunay_DoLineColly3(i);
}
}
}
//=========================MODE WP SMOKE===========================//
void Jhunay_CallDoLineColly3()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(IsAlive(i)){
Jhunay_DoLineColly1(i);
Jhunay_DoLineColly2(i);
Jhunay_DoLineColly3(i);
}
}
}
//=========================MODE WP SMOKE===========================//
void Jhunay_CallDoLineColly4()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(IsAlive(i)){
Jhunay_DoLineColly1(i);
Jhunay_DoLineColly2(i);
Jhunay_DoLineColly3(i);
}
}
}
//=========================MODE WP SMOKE===========================//
void Jhunay_CallDoLineColly5()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(IsAlive(i)){
Jhunay_DoLineColly1(i);
Jhunay_DoLineColly2(i);
Jhunay_DoLineColly3(i);
}
}
}
//=========================MODE WP SMOKE===========================//
void Jhunay_HitEvent1()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
Jhunay_CallHitEvent1(i);
Jhunay_CallHitEvent2(i);
Jhunay_CallHitEvent3(i);
if(IsAlive(i)){				
Jhunay_CallHitEvent1(i);
Jhunay_CallHitEvent2(i);
Jhunay_CallHitEvent3(i);
}
}
}
//=========================MODE WP SMOKE===========================//
void WPSmokeMode()
{
if(GetBattleState1()){
if(WPSmokeKill){
Jhunay_CallDoLineColly1();
Jhunay_CallDoLineColly2();
Jhunay_CallDoLineColly3();
Jhunay_CallDoLineColly4();
Jhunay_CallDoLineColly5();
DamagePisoTeleKill1=1;
}
if(WPSmokeKill==0){
DamagePisoTeleKill1=0;
}
if(DamagePisoTeleKill1==1){
Jhunay_HitEvent1();
}
	}}
