//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
DWORD dwBaset,dwBaset1,dwBaset2,baseALEXCallHitEvent1,baseDoLineColly1,basegetVCPos1;
LPTSTR PointBlankSTR9 = "PointBlank.exe";
//============================================================================//
int GetTeam5(int JONES)
{
for(int i = 0; i<=15; i+=2)
if( i == JONES ) return 1;
for(int i = 1; i<=15; i+=2)
if( i == JONES ) return 2;
return 0;
}
//============================================================================//
DWORD ArdiYONGKIGANTENG1(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
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
DWORD ArdiYONGKIGANTENG2(DWORD dwPtr, DWORD dwOfs){ 
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
DWORD ArdiYONGKIGANTENG3(DWORD dwPtr){ 
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
DWORD ArdiYONGKIGANTENG4(DWORD dwPtr){ 
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
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR9);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + OFS_Player);
CTeam *MyTeam = (CTeam*) ((dwBase + OFS_TEAM));
Index=MyTeam->iTeam;
return Index;
}

//============================================================================//
#define basegetVCPoss resultbasegetVCPoss

DWORD getVCPos1(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
	dwBasettt = ArdiYONGKIGANTENG2(OFS_Ammo2, resultpointer4baseALEXCallHitEvent);
	basegetVCPos = ArdiYONGKIGANTENG4(basegetVCPoss);
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
DWORD ArdiDoLineColly1(UINT i)
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
	dwBasett   = ArdiYONGKIGANTENG1(OFS_Ammo2, resultpointer1baseALEXCallHitEvent , resultpointer2baseALEXCallHitEvent);
	baseDoLineColly = ArdiYONGKIGANTENG4 (baseDoLineCollyy);
	getVCPos(&vLocal,0,0);
	vBone = GetUserBonePos2(i,TargetBonex);
	if (dwBasett)
	{
		DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
	}
	return DoLineCollyyy;
}

#define baseALEXCallHitEventt resultbaseALEXCallHitEventt
//=========================MODE WP SMOKE===========================//
DWORD ArdiCallHitEvent1(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD ArdiCallHitEventtt;
	dwBasett   = ArdiYONGKIGANTENG1(OFS_Ammo2, resultpointer1baseALEXCallHitEvent, resultpointer3baseALEXCallHitEvent);
	dwBasetttt   = ArdiYONGKIGANTENG3(OFS_Ammo2);
	baseALEXCallHitEvent = ArdiYONGKIGANTENG4(baseALEXCallHitEventt);
    getVCPos(&vEnemy,0,0);
    if (dwBasett)
	{
		ArdiCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
	}
	return ArdiCallHitEventtt;
}

//=========================MODE WP SMOKE===========================//

void ArdiCallDoLineColly1()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed1 (i))continue;
		if(GetTeam5(GetMyCharaIndexed1 (i)) == GetTeam5(i))continue;
		if(IsAlive(i)){
		ArdiDoLineColly1(i);
		}
	}
}

//=========================MODE WP SMOKE===========================//
void ArdiHitEvent1()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed1 (i))continue;
		if(GetTeam5(GetMyCharaIndexed1 (i)) == GetTeam5(i))continue;
		ArdiCallHitEvent1(i);
		if(IsAlive(i)){				
		ArdiCallHitEvent1(i);
		}
	}

}
//=========================MODE WP SMOKE===========================//
void BulledKiller1()
{
if(GetBattleState1()){
if(BulledKiller){
ArdiCallDoLineColly1();
DamagePisoTeleKill1=1;
}
if(BulledKiller==0){
DamagePisoTeleKill1=0;
}
if(DamagePisoTeleKill1==1){
	ArdiHitEvent1();
}
}}
