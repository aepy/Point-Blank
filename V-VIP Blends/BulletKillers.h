bool IsAlive(int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR8);
unsigned long dwBase2	= *(DWORD*)(dwI3EXEC + OFS_Health);
CHealth		*Health		= (CHealth*) ((dwBase2 + 0x264) + Index * PTRSizeHealth);
if(Health->CurHP > 0.1f)
return true;
return false;
}

int GetTeam11(int ARDI)
{
for(int i = 0; i<=15; i+=2)
if( i == ARDI ) return 1;
for(int i = 1; i<=15; i+=2)
if( i == ARDI ) return 2;
return 0;
}
//============================================================================//
DWORD ARDISYAHPUTRAGANTENG1(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
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
DWORD ARDISYAHPUTRAGANTENG2(DWORD dwPtr, DWORD dwOfs){ 
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
DWORD ARDISYAHPUTRAGANTENG3(DWORD dwPtr){ 
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
DWORD ARDISYAHPUTRAGANTENG4(DWORD dwPtr){ 
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
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR8);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + ResultBasePlayer);
CTeam *MyTeam = (CTeam*) ((dwBase + OFS_Team));
Index=MyTeam->iTeam;
return Index;
}

//============================================================================//
#define basegetVCPoss resultbasegetVCPoss

DWORD getVCPos1(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
	dwBasettt = ARDISYAHPUTRAGANTENG2(OFS_Ammo2, 0x554);
	basegetVCPos = ARDISYAHPUTRAGANTENG4(getVirtualCamPosition);
	if (!dwBasettt)return 0;
	DWORD getVCPosss1;
	if (dwBasettt)
	{
		getVCPosss1 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))basegetVCPos)(dwBasettt, Vect, Mat, iUnk);
	}
return getVCPosss1;
}

#define baseDoLineCollyy resultbaseDoLineCollyy
//=========================MODE WP SMOKE===========================//
DWORD ArdiDoLineColly1(UINT i)
{
	D3DXVECTOR3	vBone, vLocal;
	DWORD DoLineCollyyy;
	int TargetBonex;
	switch(AimBodyf)
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
	dwBasett   = ARDISYAHPUTRAGANTENG1(OFS_Ammo2, 0x544 , 0x1C);
	baseDoLineColly = ARDISYAHPUTRAGANTENG4 (DoLineCollision);
	getVCPos1(&vLocal,0,0);
	vBone = GetUserBonePos2(i,TargetBonex);
	if (dwBasett)
	{
		DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam11(i));
	}
	return DoLineCollyyy;
}

#define baseALEXCallHitEventt resultbaseALEXCallHitEventt
//=========================MODE WP SMOKE===========================//
DWORD ArdiCallHitEvent1(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD ArdiCallHitEventtt;
	dwBasett   = ARDISYAHPUTRAGANTENG1(OFS_Ammo2, 0x544, 0x2C);
	dwBasetttt   = ARDISYAHPUTRAGANTENG3(OFS_Ammo2);
	baseALEXCallHitEvent = ARDISYAHPUTRAGANTENG4(WriteGameEvent_fire);
    getVCPos1(&vEnemy,0,0);
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
		if(GetTeam11(GetMyCharaIndexed1 (i)) == GetTeam11(i))continue;
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
		if(GetTeam11(GetMyCharaIndexed1 (i)) == GetTeam11(i))continue;
		ArdiCallHitEvent1(i);
		if(IsAlive(i)){				
		ArdiCallHitEvent1(i);
		}
	}

}
//=========================MODE WP SMOKE ===========================//
void aIamKillYou1a()
{
if(GetBattleState1()){
if(BulletKiller){
ArdiCallDoLineColly1();
DamagePisoTeleKill1=1;
}
if(BulletKiller==0){
DamagePisoTeleKill1=0;
}
if(DamagePisoTeleKill1==1){
	ArdiHitEvent1();
}}}