//============================================================================//
int GetTeam3(int JONES)
{
for(int i = 0; i<=15; i+=2)
if( i == JONES ) return 1;
for(int i = 1; i<=15; i+=2)
if( i == JONES ) return 2;
return 0;
}
//============================================================================//
DWORD ALEXYONGKIGANTENG1(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
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
DWORD ALEXYONGKIGANTENG2(DWORD dwPtr, DWORD dwOfs){ 
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
DWORD ALEXYONGKIGANTENG3xc(DWORD dwPtr){ 
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
DWORD ALEXYONGKIGANTENG4xc(DWORD dwPtr){ 
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
int GetMyCharaIndexed1x(unsigned int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR8);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + OFS_Player);
CTeam *MyTeam = (CTeam*) ((dwBase + OFS_TEAM));
Index=MyTeam->iTeam;
return Index;
}

//============================================================================//
#define basegetVCPoss resultbasegetVCPoss

DWORD getVCPos(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
	dwBasettt = ALEXYONGKIGANTENG2(OFS_Ammo2, 0x554);
	basegetVCPos = ALEXYONGKIGANTENG4xc(getVirtualCamPosition);
	if (!dwBasettt)return 0;
	DWORD getVCPosss;
	if (dwBasettt)
	{
		getVCPosss = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))basegetVCPos)(dwBasettt, Vect, Mat, iUnk);
	}
return getVCPosss;
}

#define baseDoLineCollyy resultbaseDoLineCollyy
//=========================MODE WP SMOKE===========================//
DWORD ALEXDoLineColly1(UINT i)
{
	D3DXVECTOR3	vBone, vLocal;
	DWORD DoLineCollyyy;
	int TargetBonex;
	switch(AimBodyc)
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
	dwBasett   = ALEXYONGKIGANTENG1(OFS_Ammo2, 0x544 , 0x20);
	baseDoLineColly = ALEXYONGKIGANTENG4xc (DoLineCollision);
	getVCPos(&vLocal,0,0);
	vBone = GetUserBonePos2(i,TargetBonex);
	if (dwBasett)
	{
		DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam3(i));
	}
	return DoLineCollyyy;
}

#define baseALEXCallHitEventt resultbaseALEXCallHitEventt
//=========================MODE WP SMOKE===========================//
DWORD ALEXCallHitEvent1(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD ALEXCallHitEventtt;
	dwBasett   = ALEXYONGKIGANTENG1(OFS_Ammo2, 0x544, 0x1C);
	dwBasetttt   = ALEXYONGKIGANTENG3xc(OFS_Ammo2);
	baseALEXCallHitEvent = ALEXYONGKIGANTENG4xc(WriteGameEvent_fire);
    getVCPos(&vEnemy,0,0);
    if (dwBasett)
	{
		ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
	}
	return ALEXCallHitEventtt;
}

//=========================MODE WP SMOKE===========================//

void ALEXCallDoLineColly1()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed1x (i))continue;
		if(GetTeam3(GetMyCharaIndexed1x (i)) == GetTeam3(i))continue;
		if(IsAlive(i)){
		ALEXDoLineColly1(i);
		}
	}
}
//=========================MODE WP SMOKE===========================//
void ArdiHitEvent2()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed1x (i))continue;
		if(GetTeam3(GetMyCharaIndexed1x (i)) == GetTeam3(i))continue;
		ALEXCallHitEvent1(i);
		if(IsAlive(i)){				
		ALEXCallHitEvent1(i);
		}
	}

}
//=========================MODE WP SMOKE===========================//
void IamKillYouBomb()
{
if(GetBattleState1()){
if(BOMKILLER){
ALEXCallDoLineColly1();
DamagePisoTeleKill=1;
}
if(BOMKILLER==0){
DamagePisoTeleKill=0;
}
if(DamagePisoTeleKill==1){
	ArdiHitEvent2();
}
}}

//====================== Admin Y.L.A.S =====================//