//====================== AndyXCode Team =====================//
DWORD dwBaseA,dwBaseB,dwBaseC,TONYCallHitEvent,tonyDoLineColly,tonygetVCPos;
LPTSTR PointBlankSTR100 = "PointBlank.exe";
//============================================================================//
int GetTeam2(int JONES)
{
for(int i = 0; i<=15; i+=2)
if( i == JONES ) return 1;
for(int i = 1; i<=15; i+=2)
if( i == JONES ) return 2;
return 0;
}
//============================================================================//
DWORD Dinan1(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
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
DWORD Dinan2(DWORD dwPtr, DWORD dwOfs){ 
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
DWORD Dinan3(DWORD dwPtr){ 
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
DWORD Dinan4(DWORD dwPtr){ 
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
int GetMyCharaIndexeD1(unsigned int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR100);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + ResultBasePlayer);
CTeam *MyTeam = (CTeam*) ((dwBase + OFS_Team));
Index=MyTeam->iTeam;
return Index;
}

//============================================================================//
#define basegetVCPoss resultbasegetVCPoss

DWORD getVCPosA(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
	dwBaseB = Dinan2(ResultBaseAmmo2, PTR_CAMPOS);
	tonygetVCPos = Dinan4(OFS_CamPosition);
	if (!dwBaseB)return 0;
	DWORD getVCPosss;
	if (dwBaseB)
	{
		getVCPosss = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))tonygetVCPos)(dwBaseB, Vect, Mat, iUnk);
	}
return getVCPosss;
}

#define baseDoLineCollyy resultbaseDoLineCollyy
//=========================MODE WP SMOKE===========================//
DWORD DinanDoLineColly1(UINT i)
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
	dwBaseA   = Dinan1(ResultBaseAmmo2, 0x544 , 0x28);
	tonyDoLineColly = Dinan4 (DoLineCollision);
	getVCPosA(&vLocal,0,0);
	vBone = GetUserBonePos2(i,TargetBonex);
	if(DamageBomb){
	if (dwBaseA)
	{
		DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))tonyDoLineColly)(dwBaseA, &vLocal, &vBone, GetTeam2(i));
	}}
	return DoLineCollyyy;
}

#define baseALEXCallHitEventt resultbaseALEXCallHitEventt
//=========================MODE WP SMOKE===========================//
DWORD DinanCallHitEvent1(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD ALEXCallHitEventtt;
	dwBaseA   = Dinan1(ResultBaseAmmo2, 0x544, 0x28);
	dwBaseC   = Dinan3(ResultBaseAmmo2);
	TONYCallHitEvent = Dinan4(OFS_GameEventFire);
    getVCPosA(&vEnemy,0,0);
    if (dwBaseA)
	{
		ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))TONYCallHitEvent)(dwBaseA, dwBaseC, &vEnemy, dwBaseA);
	}
	return ALEXCallHitEventtt;
}

//=========================MODE WP SMOKE===========================//

void DinanCallDoLineColly1()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexeD1 (i))continue;
		if(GetTeam2(GetMyCharaIndexeD1 (i)) == GetTeam2(i))continue;
		if(IsAlive(i)){
		DinanDoLineColly1(i);
		}
	}
}

//=========================MODE WP SMOKE===========================//
void DinanHitEvent1()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexeD1 (i))continue;
		if(GetTeam2(GetMyCharaIndexeD1 (i)) == GetTeam2(i))continue;
		DinanCallHitEvent1(i);
		if(IsAlive(i)){				
		DinanCallHitEvent1(i);
		}
	}

}
//=========================MODE WP SMOKE===========================//
void DinanKillYou1()
{
if(GetBattleState1()){
if(BombKiller){
NayzLine2st();
DamageCall=1;
DAMAGESMOKE=1;
}
if(BombKiller==0){
DamageCall=0;
DAMAGESMOKE=0;
}
if(DamageBomb==1){
	NayzHitEvent2st();
}
}}


//====================== Admin Alosius Andy haryanto =====================//