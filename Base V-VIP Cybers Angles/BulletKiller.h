//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
LPTSTR PointBlankSTR90 = "PointBlank.exe";
//============================================================================//
int GetTeam22(int JONES)
{
for(int i = 0; i<=15; i+=2)
if( i == JONES ) return 1;
for(int i = 1; i<=15; i+=2)
if( i == JONES ) return 2;
return 0;
}
//============================================================================//
DWORD ARDIYONGKIGANTENG1(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
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
DWORD ARDIYONGKIGANTENG2(DWORD dwPtr, DWORD dwOfs){ 
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
DWORD ARDIYONGKIGANTENG3(DWORD dwPtr){ 
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
DWORD ARDIYONGKIGANTENG4(DWORD dwPtr){ 
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
int GetMyCharaIndexed1(unsigned int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR90);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + OFS_Player);
CTeam *MyTeam = (CTeam*) ((dwBase + OFS_TEAM));
Index=MyTeam->iTeam;
return Index;
}

//============================================================================//
DWORD getVCPos1(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
	dwBasettt = ARDIYONGKIGANTENG2(OFS_Ammo2, resultpointer4baseALEXCallHitEvent);
	basegetVCPos = ARDIYONGKIGANTENG4(resultbasegetVCPoss);
	if (!dwBasettt)return 0;
	DWORD getVCPosss;
	if (dwBasettt)
	{
		getVCPosss = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))basegetVCPos)(dwBasettt, Vect, Mat, iUnk);
	}
return getVCPosss;
}


//=========================MODE WP SMOKE===========================//
DWORD ARDIDoLineColly1(UINT i)
{
	D3DXVECTOR3	vBone, vLocal;
	DWORD DoLineCollyyy;
	int TargetBonex;
	switch(AimBody)
	{
	case 0:
		TargetBonex = 7.1; // Kepala
		break;
	}
	dwBasett   = ARDIYONGKIGANTENG1(OFS_Ammo2, 0x544 , 0x34-0);
	baseDoLineColly = ARDIYONGKIGANTENG4 (resultbaseDoLineCollyy);
	getVCPos1(&vLocal,0,0);
	vBone = GetUserBonePos2(i,TargetBonex);
	if (dwBasett)
	{
		DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
	}
	return DoLineCollyyy;
}
//------------------------------- BULLET KILLER -------------------------------------||
DWORD ARDICallHitEvent1(UINT i)
{
D3DXVECTOR3	vEnemy;
DWORD ARDICallHitEventtt;
dwBasett   = ARDIYONGKIGANTENG1(OFS_Ammo2, 0x544, 0x2C);
dwBasetttt   = ARDIYONGKIGANTENG3(OFS_Ammo2);
baseALEXCallHitEvent = ARDIYONGKIGANTENG4(resultbaseALEXCallHitEventt);
getVCPos1(&vEnemy,0,0);
if (dwBasett)
{
ARDICallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
}
return ARDICallHitEventtt;
}
//------------------------------- BULLET KILLER -------------------------------------||
void ARDICallDoLineColly1()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed1 (i))continue;
if(GetTeam22(GetMyCharaIndexed1 (i)) == GetTeam22(i))continue;
if(IsAlive(i)){
ARDIDoLineColly1(i);
}
}
}
//------------------------------- BULLET KILLER -------------------------------------||
void ARDIHitEvent1()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed1 (i))continue;
if(GetTeam22(GetMyCharaIndexed1 (i)) == GetTeam22(i))continue;
ARDICallHitEvent1(i);
if(IsAlive(i)){				
ARDICallHitEvent1(i);
}
}
}
//------------------------------- BULLET KILLER -------------------------------------||
void BulledKiller1()
{
if(GetBattleState1()){
if(BulletKiller){
ARDICallDoLineColly1();
DamagePisoTeleKill1=1;
}
if(BulletKiller==0){
DamagePisoTeleKill1=0;
}
if(DamagePisoTeleKill1==1){
ARDIHitEvent1();
}
}}
