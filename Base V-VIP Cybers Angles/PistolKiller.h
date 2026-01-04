//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
LPTSTR PointBlankSTR10 = "PointBlank.exe";
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
DWORD ILHAMYONGKIGANTENG1(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
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
DWORD ILHAMYONGKIGANTENG2(DWORD dwPtr, DWORD dwOfs){ 
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
DWORD ILHAMYONGKIGANTENG3(DWORD dwPtr){ 
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
DWORD ILHAMYONGKIGANTENG4(DWORD dwPtr){ 
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
int GetMyCharaIndexed22(unsigned int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR10);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + OFS_Player);
CTeam *MyTeam = (CTeam*) ((dwBase + OFS_TEAM));
Index=MyTeam->iTeam;
return Index;
}

//============================================================================//
#define basegetVCPoss resultbasegetVCPoss

DWORD getVCPos2(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
	dwBasettt = ILHAMYONGKIGANTENG2(OFS_Ammo2, resultpointer4baseALEXCallHitEvent);
	basegetVCPos = ILHAMYONGKIGANTENG4(basegetVCPoss);
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
DWORD ILHAMDoLineColly1(UINT i)
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
	dwBasett   = ILHAMYONGKIGANTENG1(OFS_Ammo2, 0x544 , 0x20);
	baseDoLineColly = ILHAMYONGKIGANTENG4 (baseDoLineCollyy);
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
DWORD ILHAMCallHitEvent1(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD ILHAMCallHitEventtt1;
	dwBasett   = ILHAMYONGKIGANTENG1(OFS_Ammo2, 0x544, 0x20);
	dwBasetttt   = ILHAMYONGKIGANTENG3(OFS_Ammo2);
	baseALEXCallHitEvent = ILHAMYONGKIGANTENG4(baseALEXCallHitEventt);
    getVCPos(&vEnemy,0,0);
    if (dwBasett)
	{
		ILHAMCallHitEventtt1 = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
	}
	return ILHAMCallHitEventtt1;
}

//=========================MODE WP SMOKE===========================//

void ILHAMCallDoLineColly1()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed22 (i))continue;
		if(GetTeam3(GetMyCharaIndexed22 (i)) == GetTeam3(i))continue;
		if(IsAlive(i)){
		ILHAMDoLineColly1(i);
		}
	}
}

//=========================MODE WP SMOKE===========================//
void ILHAMHitEvent1()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed22 (i))continue;
		if(GetTeam3(GetMyCharaIndexed22 (i)) == GetTeam3(i))continue;
		ILHAMCallHitEvent1(i);
		if(IsAlive(i)){				
		ILHAMCallHitEvent1(i);
		}
	}

}
//=========================MODE WP SMOKE===========================//
void BommKiller1()
{
if(GetBattleState1()){
if(BommKiller){
ILHAMCallDoLineColly1();
DamagePisoTeleKill1=1;
}
if(BommKiller==0){
DamagePisoTeleKill1=0;
}
if(DamagePisoTeleKill1==1){
	ILHAMHitEvent1();
}
}}
