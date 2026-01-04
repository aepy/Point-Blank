DWORD dwBasett,dwBasettt,dwBasetttt,baseALEXCallHitEvent,baseDoLineColly,basegetVCPos;
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
//----------------------------------------------------------------------------------
int GetMyCharaIndexed(unsigned int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR8);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + ResultBasePlayer);
CTeam *MyTeam = (CTeam*) ((dwBase + OFS_Team));
Index=MyTeam->iTeam;
return Index;
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
baseALEXCallHitEvent = NayzAngels4st(OFS_GameEventFire);
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
baseALEXCallHitEvent = NayzAngels4st(OFS_GameEventFire);
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
//----------------------------------------------------------------------------------
void BULLETFUNCTION()
{
if(GetBattleState1()){
if(BulletCall){
NayzLine1st();
DamageBulletCall=1;
}
if(BulletCall==0){
DamageBulletCall=0;
}
if(DamageBulletCall==1){
NayzHitEvent1st();
}}}

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