//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
LPTSTR PointBlankSTR11 = "PointBlank.exe";
//============================================================================//
int GetTeam4(int JONES)
{
for(int i = 0; i<=15; i+=2)
if( i == JONES ) return 1;
for(int i = 1; i<=15; i+=2)
if( i == JONES ) return 2;
return 0;
}
//============================================================================//
DWORD CrazyGANTENG1(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
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
DWORD CrazyGANTENG2(DWORD dwPtr, DWORD dwOfs){ 
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
DWORD CrazyGANTENG3(DWORD dwPtr){ 
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
DWORD CrazyGANTENG4(DWORD dwPtr){ 
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
int GetMyCharaIndexed3(unsigned int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR11);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + OFS_Player);
CTeam *MyTeam = (CTeam*) ((dwBase + OFS_TEAM));
Index=MyTeam->iTeam;
return Index;
}

//============================================================================//
DWORD getVCPos3(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
	dwBasettt = CrazyGANTENG2(OFS_Ammo2, resultpointer4baseALEXCallHitEvent);
	basegetVCPos = CrazyGANTENG4(resultbasegetVCPoss);
	if (!dwBasettt)return 0;
	DWORD getVCPosss;
	if (dwBasettt)
	{
		getVCPosss = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))basegetVCPos)(dwBasettt, Vect, Mat, iUnk);
	}
return getVCPosss;
}
//=========================MODE WP SMOKE===========================//
DWORD CrazyDoLineColly1(UINT i)
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
	dwBasett   = CrazyGANTENG1(OFS_Ammo2, 0x544 , resultArdiPointer1CallHitEvent);
	baseDoLineColly = CrazyGANTENG4 (resultbaseDoLineCollyy);
	getVCPos3(&vLocal,0,0);
	vBone = GetUserBonePos2(i,TargetBonex);
	if (dwBasett)
	{
		DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam4(i));
	}
	return DoLineCollyyy;
}
//=========================MODE WP SMOKE===========================//
DWORD CrazyCallHitEvent1(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD CrazyCallHitEventtt;
	dwBasett   = CrazyGANTENG1(OFS_Ammo2, 0x544, resultArdiPointer1CallHitEvent);
	dwBasetttt   = CrazyGANTENG3(OFS_Ammo2);
	baseALEXCallHitEvent = CrazyGANTENG4(resultbaseALEXCallHitEventt);
    getVCPos3(&vEnemy,0,0);
    if (dwBasett)
	{
		CrazyCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
	}
	return CrazyCallHitEventtt;
}

//=========================MODE WP SMOKE===========================//

void CrazyCallDoLineColly1()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed3 (i))continue;
		if(GetTeam4(GetMyCharaIndexed3 (i)) == GetTeam4(i))continue;
		if(IsAlive(i)){
		CrazyDoLineColly1(i);
		}
	}
}

//=========================MODE WP SMOKE===========================//
void CrazyHitEvent1()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed3 (i))continue;
		if(GetTeam4(GetMyCharaIndexed3 (i)) == GetTeam4(i))continue;
		CrazyCallHitEvent1(i);
		if(IsAlive(i)){				
		CrazyCallHitEvent1(i);
		}
	}

}
//=========================MODE WP SMOKE===========================//
void IamKillYou4()
{
if(GetBattleState1()){
if(GranadeCall){
CrazyCallDoLineColly1();
DamagePisoTeleKill1=1;
}
if(GranadeCall==0){
DamagePisoTeleKill1=0;
}
if(DamagePisoTeleKill1==1){
	CrazyHitEvent1();
}
}}
