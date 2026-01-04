DWORD dwBasett,dwBasettt,dwBasetttt,baseALEXCallHitEvent,baseDoLineColly,basegetVCPos;
DWORD DoLineCollyyy1,DoLineCollyyy2,DoLineCollyyy3,DoLineCollyyy4,DoLineCollyyy5,DoLineCollyyy6,DoLineCollyyy7;
DWORD DoLineCollyyy8,DoLineCollyyy9,DoLineCollyyy0,DoLineCollyyy11,DoLineCollyyy12,DoLineCollyyy13,DoLineCollyyy14,DoLineCollyyy15;

LPTSTR PointBlankSTR8 = "PointBlank.exe";
//----------------------------------------------------------------------------------
D3DXVECTOR3 GetUserBonePos2(int Idx ,int BoneIdx)
{
D3DXVECTOR3 Out;
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA("PointBlank.exe");
unsigned long dwGameBase = *(DWORD*)(dwI3EXEC + ResultBaseHealth);
if ( dwGameBase )
{
CGameCharaBase* GameBase = (CGameCharaBase*)( *(DWORD*)(dwGameBase + 0x14 + ( 0x4 * Idx ) ) );
if ( GameBase && GameBase->m_BoneContext )
{
Out.x = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._41;
Out.y = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._42;
Out.z = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._43;
}}
return Out;
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
int GetTeam1(int JONES)
{
for(int i = 0; i<=15; i+=2)
if( i == JONES ) return 1;
for(int i = 1; i<=15; i+=2)
if( i == JONES ) return 2;
return 0;
}
//----------------------------------------------------------------------------------
DWORD IRCHcek1(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
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
DWORD IRCHcek2(DWORD dwPtr, DWORD dwOfs){ 
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
DWORD IRCHcek3(DWORD dwPtr){ 
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
DWORD IRCHcek4(DWORD dwPtr){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=((DWORD)dwPtr); 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return C; 
} 
} 
return C;
}
//----------------------------------------------------------------------------------
int GetMyCharaIndexed(unsigned int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR8);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + ResultBasePlayer);
CTeam *MyTeam = (CTeam*) ((dwBase + ResultTeam));
Index=MyTeam->iTeam;
return Index;
}
//----------------------------------------------------------------------------------
#define basegetVCPoss resultbasegetVCPoss
DWORD getVCPosa(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
dwBasettt = IRCHcek2(ResultBaseAmmo2, 0x554);
basegetVCPos = IRCHcek4(ResultCamPos);
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
dwBasett   = IRCHcek1(ResultBaseAmmo2, ResultPTRAmmo , 0x1C);
baseDoLineColly = IRCHcek4 (ResultDoLine);
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
dwBasett   = IRCHcek1(ResultBaseAmmo2, ResultPTRAmmo, 0x24);
dwBasetttt   = IRCHcek3(ResultBaseAmmo2);
baseALEXCallHitEvent = IRCHcek4(ResultEventFire);
getVCPosa(&vEnemy,0,0);
if (dwBasett)
{
ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
}
return ALEXCallHitEventtt;
}

//----------------------------------------------------------------------------------
void RCHzLine1st()
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
void RCHzHitEvent1st()
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
//----------------------------------------------------------------------------------
#define Slot 0x2C
DWORD NayzCyber2st0(UINT i)
{
D3DXVECTOR3	vBone, vLocal;
DWORD DoLineCollyyy[100];
int BoneIndexSelector;
switch(Target){
case 0:
BoneIndexSelector = 7.7;
break;

}
dwBasett   = IRCHcek1(ResultBaseAmmo2, ResultPTRAmmo , Slot);
baseDoLineColly = IRCHcek4 (ResultDoLine);
getVCPosa(&vLocal,0,0);
vBone = GetUserBonePos2(i,BoneIndexSelector);
if (dwBasett)
{
DoLineCollyyy[1] = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy[2] = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy[3] = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy[4] = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy[5] = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy[6] = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy[7] = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy[8] = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy[9] = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy[0] = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy[11] = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy[12] = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy[13] = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy[14] = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy[15] = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
}
return DoLineCollyyy[100];
}
//----------------------------------------------------------------------------------
DWORD RCHHit2st(UINT i)
{
D3DXVECTOR3	vEnemy;
DWORD ALEXCallHitEventtt;
dwBasett   = IRCHcek1(ResultBaseAmmo2, ResultPTRAmmo, Slot);
dwBasetttt   = IRCHcek3(ResultBaseAmmo2);
baseALEXCallHitEvent = IRCHcek4(ResultEventFire);
getVCPosa(&vEnemy,0,0);
if (dwBasett)
{
ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
}
return ALEXCallHitEventtt;
}
//----------------------------------------------------------------------------------
void RCHLine2st()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(IsAlivedf(i)){
NayzCyber2st0(i);
}
}
}
void _WriteMEM(DWORD Adr, DWORD Ptr1, DWORD Ptr2, DWORD WriteValue)
{
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)Adr, 4) == 0)
	{ 
		Temp = *(PDWORD)((DWORD)(Adr)) + Ptr1;
		if (IsBadReadPtr((PDWORD)Temp,4) == 0)
		{ 
			Temp = *(PDWORD)((DWORD)(Temp)) + Ptr2;
			if (IsBadReadPtr((PDWORD)Temp,4) == 0)
			{ 
				*(PDWORD)Temp = WriteValue;
			}
		}
	}
}

#define basegetVCPoss resultbasegetVCPoss
//----------------------------------------BOM K400---------------------------------------------//
DWORD BombDoLineColly1(UINT i)
{
	D3DXVECTOR3	vBone, vLocal;
	DWORD DoLineCollyyy[100];
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
	dwBasett   = IRCHcek1(ResultBaseAmmo2, 0x544 , 0x2C-0x4);//0x34 Bullet Killer //0x2c Smoke //0x28 Bom
	baseDoLineColly = IRCHcek4(ResultDoLine);
	getVCPosa(&vLocal,0,0);
	vBone = GetUserBonePos2(i,TargetBonex);
if (dwBasett){
DoLineCollyyy1 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
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
	}
return DoLineCollyyy[100];
}
#define baseALEXCallHitEventt resultbaseALEXCallHitEventt
//-------------------------------------------------------------------------------------//
DWORD ALEXCallHitEvent1(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD ALEXCallHitEventtt;
	dwBasett   = IRCHcek1(ResultBaseAmmo2, 0x544, 0x28-0);//Damagenya :)//0x2C Smoke //0x28 Bom
	dwBasetttt   = IRCHcek3(ResultBaseAmmo2);
	baseALEXCallHitEvent = IRCHcek4(ResultEventFire);
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
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x28,0x00000000);
		BombDoLineColly1(i);
	
		}
	}

}
//-------------------------------------------------------------------------------------//
void RCHHitEvent2()
{
	for (int i = 0; i < 18; i++)
	{
		if (!GetMyCharaIndexed(i))continue;
		if(GetTeam1(GetMyCharaIndexed(i)) == GetTeam1(i))continue;
		ALEXCallHitEvent1(i);
		if(IsAlivedf(i)){				
		BombDoLineColly1(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x55C,0x28,0x00000000);
		BombDoLineColly1(i);		
		}
	}

}
//----------------------------------------------------------------------------------
void RCHHitEvent2st()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
RCHHit2st(i);
if(IsAlivedf(i)){				
RCHHit2st(i);
}
}
}
//----------------------------------------------------------------------------------
void BulletKillers()
{
if(GetBattleState()){
if(BulletCall){
AutoHS=0;
AutoHS2=0;
DamageBulletCall=1;
	}
if(BulletCall==0){
DamageBulletCall=0;
}
if(DamageBulletCall==1){
if(GetAsyncKeyState(VK_MBUTTON)&1){
RCHzLine1st();
RCHzHitEvent1st();
	}}}}

void WPSmokeKiller()
{
if(GetBattleState()){
if(SmokeCall){
DamageCall=1;
}
if(SmokeCall==0){
DamageCall=0;

}
if(DamageCall==1){
RCHHitEvent2st();
RCHLine2st();
}}}

//-------------------------------------------------------------------------------------//
void BOMKiller()
{
if(GetBattleState()){
if(BomKiller==1){
ALEXCallDoLineColly1();
PrivateOnly((void *)(dwPBExe + ResultWallShot),(int*)(PBYTE)"\x90\x90",2);
//Bom_Kill();
//QuickBom=1;
DamagePisoTeleKill=1;
}
if(BomKiller==0){
DamagePisoTeleKill=0;
PrivateOnly((void *)(dwPBExe + ResultWallShot),(int*)(PBYTE)"\x75\x1F",2);
//Bom_Kill();
}
if(DamagePisoTeleKill==1){
	RCHHitEvent2();
}
}}

