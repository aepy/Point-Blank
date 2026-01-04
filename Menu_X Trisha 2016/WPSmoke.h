//void _WriteMEM(DWORD Adr, DWORD Ptr1, DWORD Ptr2, DWORD WriteValue) { DWORD Temp=0; if (IsBadReadPtr((PDWORD)Adr, 4) == 0) { Temp = *(PDWORD)((DWORD)(Adr)) + Ptr1; if (IsBadReadPtr((PDWORD)Temp,4) == 0) { Temp = *(PDWORD)((DWORD)(Temp)) + Ptr2; if (IsBadReadPtr((PDWORD)Temp,4) == 0) { *(PDWORD)Temp = WriteValue; } } } }
DWORD dwBasett,dwBasettt,dwBasetttt,baseALEXCallHitEvent,baseDoLineColly,basegetVCPos;
//----------------------------------------------------------------------------------
DWORD NayzAngels1st(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
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
//----------------------------------------------------------------------------------
DWORD NayzAngels2st(DWORD dwPtr, DWORD dwOfs){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return *(PDWORD)C; 
} 
} 
return C;
}
//----------------------------------------------------------------------------------
DWORD NayzAngels3st(DWORD dwPtr){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=(*(DWORD*)(dwPtr)); 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return C; 
} 
} 
return C;
}
//----------------------------------------------------------------------------------
DWORD NayzAngels4st(DWORD dwPtr){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=((DWORD)dwPtr); 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return C; 
} 
} 
return C;
}
bool IsAlivedf(int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR8);
unsigned long dwBase2	= *(DWORD*)(dwI3EXEC + ResultBaseHealth);
CHealth		*Health		= (CHealth*) ((dwBase2 + 0x264) + Index * 0x24);
if(Health->CurHP > 0.1f)
return true;
return false;
}
//----------------------------------------------------------------------------------
#define basegetVCPoss resultbasegetVCPoss
DWORD getVCPosa(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
dwBasettt = NayzAngels2st(ResultBaseAmmo2, 0x554);
basegetVCPos = NayzAngels4st(OFS_CamPosition);
if (!dwBasettt)return 0;
DWORD getVCPosss;
if (dwBasettt)
{
getVCPosss = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))basegetVCPos)(dwBasettt, Vect, Mat, iUnk);
}
return getVCPosss;
}

#define baseDoLineCollyy resultbaseDoLineCollyy
int Target;
DWORD BombDoLineColly1(UINT i)
{
	D3DXVECTOR3	vBone, vLocal;
	DWORD DoLineCollyyy;
	int TargetBonex;
	switch(Nh_Teknology7)
	{
	case 0:
		TargetBonex = 7; // Kepala
		break;
	case 1:
		TargetBonex = 5; // Badan
		break;
	}
	dwBasett   = NayzAngels1st(ResultBaseAmmo2, 0x544 , 0x28-0);//0x34 Bullet Killer //0x2c Smoke //0x28 Bom
	baseDoLineColly = NayzAngels4st(DoLineCollision);
	getVCPosa(&vLocal,0,0);
	vBone = GetUserBonePos2(i,TargetBonex);
	if (dwBasett)
	{
		DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
	}
	return DoLineCollyyy;
}
#define baseALEXCallHitEventt resultbaseALEXCallHitEventt
//-------------------------------------------------------------------------------------//
DWORD ALEXCallHitEvent1(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD ALEXCallHitEventtt;
	dwBasett   = NayzAngels1st(ResultBaseAmmo2, 0x544, 0x28-0);//Damagenya :)//0x2C Smoke //0x28 Bom
	dwBasetttt   = NayzAngels3st(ResultBaseAmmo2);
	baseALEXCallHitEvent = NayzAngels4st(ResultEventFire);
    getVCPosa(&vEnemy,0,0);
    if (dwBasett)
	{
		ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
	}
	return ALEXCallHitEventtt;
}
//-------------------------------------------------------------------------------------//
void ALEXCallDoLineColly1()
{
	for (int i = 0; i < 18; i++)
	{
		if (!GetMyCharaIndexed(i))continue;
		if(GetTeam1(GetMyCharaIndexed(i)) == GetTeam1(i))continue;
		ALEXCallHitEvent1(i);
		if(IsAlivedf(i)){				
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
	
		}
	}

}
//-------------------------------------------------------------------------------------//
void ALEXHitEvent2()
{
	for (int i = 0; i < 18; i++)
	{
		if (!GetMyCharaIndexed(i))continue;
		if(GetTeam1(GetMyCharaIndexed(i)) == GetTeam1(i))continue;
		ALEXCallHitEvent1(i);
		if(IsAlivedf(i)){				
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x2C,0x00000000);
		}
	}

}
void BOMKiller()
{
if(GetBattleState1()){
if(BomKiller==1){
ALEXCallDoLineColly1();
DamagePisoTeleKill=1;
BomberKiller=1;
BomberMane=1;
}
if(BomKiller==0){
DamagePisoTeleKill=0;
BomberKiller=0;
BomberMane=0;
}
if(DamagePisoTeleKill==1){
	ALEXHitEvent2();
}
}}
bool XBOMB       = false;
void BypassBOMB()
{
WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectA, 0x00); // NeoPTRProtectA
WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectB, 0x00); // NeoPTRProtectB
WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectC, 0x00); // NeoPTRProtectC
WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectD-0x10, 0x00); // NeoPTRProtectA
}
/*----------------------------------------------------------------------------------*/
void FastBom() {
DWORD mBase = (DWORD)GetModuleHandleA	("PointBlank.exe");
c_WeaponIndex_B(mBase + ResultBaseAmmo,0x544,0x28, 0x30,0x67,0x41); 
} 
/*----------------------------------------------------------------------------------*/
void BomberKill()
{
if(BomberKiller==1)
{
FastBom();
if(XBOMB==false)
{
AmmoBOMB1  = RecordPTR(ResultBaseAmmo2, 0x544, ResultBOMBSIZE, 0xC81);
AmmoBOMB2  = RecordPTR(ResultBaseAmmo2, 0x544, ResultBOMBSIZE, 0xC98);
AmmoBOMB3  = RecordPTR(ResultBaseAmmo2, 0x544, ResultBOMBSIZE, 0xC9C);
AmmoBOMB4  = RecordPTR(ResultBaseAmmo2, 0x544, ResultBOMBSIZE, 0xCA0);
AmmoBOMB5  = RecordPTR(ResultBaseAmmo2, 0x544, ResultBOMBSIZE, 0xCA4);
AmmoBOMB6  = RecordPTR(ResultBaseAmmo2, 0x544, ResultBOMBSIZE, 0xCA8); // NeoPTRAmmoB
XBOMB=true;
}
else 
if(XBOMB==true)
{
BypassBOMB();
WritePTR(ResultBaseAmmo2, 0x544, ResultBOMBSIZE, 0xC81, AmmoBOMB1);
WritePTR(ResultBaseAmmo2, 0x544, ResultBOMBSIZE, 0xC98, AmmoBOMB2);
WritePTR(ResultBaseAmmo2, 0x544, ResultBOMBSIZE, 0xC9C, AmmoBOMB3);
WritePTR(ResultBaseAmmo2, 0x544, ResultBOMBSIZE, 0xCA0, AmmoBOMB4);
WritePTR(ResultBaseAmmo2, 0x544, ResultBOMBSIZE, 0xCA4, AmmoBOMB5);
WritePTR(ResultBaseAmmo2, 0x544, ResultBOMBSIZE, 0xCA8, AmmoBOMB6); // NeoPTRAmmoB
BypassBOMB();
Sleep(25);
}
}
else
XBOMB=false;
}
/*----------------------------------------------------------------------------------*/
void BomberMan()
{
if(BomberMane==1)
{
if (*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x544) + 0x40) == 3)
{
*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30) + 0x30) + 0x58) = 0;
}
if (*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x544) + 0x40) == 4) 
{
*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30) + 0x30) + 0x58) = 0;
}
}}
//----------------------------------------------------------------------------------
D3DXVECTOR3 OnWorld,OnScreen;
DWORD NayzCyber1st(UINT i)
{
D3DXVECTOR3	vBone, vLocal;
DWORD DoLineCollyyy;
int BoneIndexSelector;
switch(Target){
case 0:
BoneIndexSelector = 7.7;
break;
case 1:
BoneIndexSelector = 5;
break;
}
dwBasett   = NayzAngels1st(ResultBaseAmmo2, ResultPTRAmmo , 0x34);
baseDoLineColly = NayzAngels4st (OFS_DoLineCollision);
getVCPosa(&vLocal,0,0);
vBone = GetUserBonePos2(i,BoneIndexSelector);
if (dwBasett)
{
DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
}
return DoLineCollyyy;
}
//----------------------------------------------------------------------------------
DWORD NayHit1st(UINT i)
{
D3DXVECTOR3	vEnemy;
DWORD ALEXCallHitEventtt;
dwBasett   = NayzAngels1st(ResultBaseAmmo2, ResultPTRAmmo, 0x1C);
dwBasetttt   = NayzAngels3st(ResultBaseAmmo2);
baseALEXCallHitEvent = NayzAngels4st(ResultEventFire);
getVCPosa(&vEnemy,0,0);
if (dwBasett)
{
ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
}
return ALEXCallHitEventtt;
}

//----------------------------------------------------------------------------------
void NayzLine1st()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(IsAlivedf(i)){
NayzCyber1st(i);
}
}
}
//----------------------------------------------------------------------------------
void NayzHitEvent1st()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
NayHit1st(i);
if(IsAlivedf(i)){				
NayHit1st(i);
}
}
}
DWORD NayzCyber2st(UINT i)
{
D3DXVECTOR3	vBone, vLocal;
DWORD DoLineCollyyy,DoLineCollyyy2,DoLineCollyyy3,DoLineCollyyy4,DoLineCollyyy5,DoLineCollyyy6,DoLineCollyyy7;
DWORD DoLineCollyyy8,DoLineCollyyy9,DoLineCollyyy0,DoLineCollyyy11,DoLineCollyyy12,DoLineCollyyy13,DoLineCollyyy14,DoLineCollyyy15;
int BoneIndexSelector;
switch(Target){
case 0:
BoneIndexSelector = 7.7;
break;

}
dwBasett   = NayzAngels1st(ResultBaseAmmo2, ResultPTRAmmo , 0x2C);
baseDoLineColly = NayzAngels4st (OFS_DoLineCollision);
getVCPosa(&vLocal,0,0);
vBone = GetUserBonePos2(i,BoneIndexSelector);
if(DAMAGESMOKE){
if (dwBasett){
DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy2 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy3 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy4 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy5 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy6 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy7 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy8 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy9 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy0 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy11 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy12 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy13 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy14 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy15 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));


	}}
return DoLineCollyyy;
return DoLineCollyyy2;
return DoLineCollyyy3;
return DoLineCollyyy4;
return DoLineCollyyy5;
return DoLineCollyyy6;
return DoLineCollyyy7;
return DoLineCollyyy8;
return DoLineCollyyy9;
return DoLineCollyyy0;
return DoLineCollyyy11;
return DoLineCollyyy12;
return DoLineCollyyy13;
return DoLineCollyyy14;
return DoLineCollyyy15;
}

//----------------------------------------------------------------------------------
DWORD NayHit2st(UINT i)
{
D3DXVECTOR3	vEnemy;
DWORD ALEXCallHitEventtt;
dwBasett   = NayzAngels1st(ResultBaseAmmo2, ResultPTRAmmo, 0x2C);
dwBasetttt   = NayzAngels3st(ResultBaseAmmo2);
baseALEXCallHitEvent = NayzAngels4st(ResultEventFire);
getVCPosa(&vEnemy,0,0);
if (dwBasett)
{
ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
}
return ALEXCallHitEventtt;
}
//----------------------------------------------------------------------------------
void NayzLine2st()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(IsAlivedf(i)){
NayzCyber2st(i);
}
}
}
//----------------------------------------------------------------------------------
void NayzHitEvent2st()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
NayHit2st(i);
if(IsAlivedf(i)){				
NayHit2st(i);
}
}
}
void WPSMOKEFUNCTION()
{
if(GetBattleState1()){
if(SmokeCall){
NayzLine2st();
DamageCall=1;
DAMAGESMOKE=1;
}
if(SmokeCall==0){
DamageCall=0;
DAMAGESMOKE=0;
}
if(DamageCall==1){
NayzHitEvent2st();
}}}

//----------------------------------------------------------------------------------
DWORD NayHit1ste(UINT i)
{
D3DXVECTOR3	vEnemy;
DWORD ALEXCallHitEventtt;
dwBasett   = NayzAngels1st(ResultBaseAmmo2, ResultPTRAmmo, 0x1C);
dwBasetttt   = NayzAngels3st(ResultBaseAmmo2);
baseALEXCallHitEvent = NayzAngels4st(ResultEventFire);
getVCPosa(&vEnemy,0,0);
if (dwBasett)
{
ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
}
return ALEXCallHitEventtt;
}
void NayzHitEvent1ste()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
NayHit1ste(i);
if(IsAlivedf(i)){				
NayHit1ste(i);
}
}
}
//----------------------------------------------------------------------------------
DWORD BulletKiller1(UINT i)
{
D3DXVECTOR3	vBone, vLocal;
DWORD DoLineCollyyy;
int BoneIndexSelector;
switch(Target){
case 0:
BoneIndexSelector = 7.7;
break;
case 1:
BoneIndexSelector = 5;
break;
}
dwBasett   = NayzAngels1st(ResultBaseAmmo2, ResultPTRAmmo , 0x34);
baseDoLineColly = NayzAngels4st (OFS_DoLineCollision);
getVCPosa(&vLocal,0,0);
vBone = GetUserBonePos2(i,BoneIndexSelector);
if (dwBasett)
{
DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
}
return DoLineCollyyy;
}
//----------------------------------------------------------------------------------
void BulletKiller2()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(IsAlivedf(i)){
BulletKiller1(i);
}
}
}
void BULLETFUNCTION()
{
if(GetBattleState1()){
if(BulletCall){
BulletKiller2();
DrawStringESP(800, 25, White,"Bullet Killer ( Key 1 )");
DrawStringESP(1000,25, Green,  "( ON )");
DamageBulletCall=1;
}
if(BulletCall==0){
DrawStringESP(800, 25, White,"Bullet Killer ( Key 1 )");
DrawStringESP(1000,25, Red,   "( OFF )");
DamageBulletCall=0;
}
if(DamageBulletCall==1){
NayzHitEvent1ste();
}}}