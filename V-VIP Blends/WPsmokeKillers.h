DWORD dwBasett,dwBasettt,dwBasetttt,baseALEXCallHitEvent,baseDoLineColly,basegetVCPos;
LPTSTR PointBlankSTR8 = "PointBlank.exe";
//============================================================================//
bool IsAlivedf(int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR8);
unsigned long dwBase2	= *(DWORD*)(dwI3EXEC + OFS_Health);
CHealth		*Health		= (CHealth*) ((dwBase2 + 0x264) + Index * PTRSizeHealth);
if(Health->CurHP > 0.1f)
return true;
return false;
}
//============================================================================//
int GetTeam1(int JONES)
{
for(int i = 0; i<=15; i+=2)
if( i == JONES ) return 1;
for(int i = 1; i<=15; i+=2)
if( i == JONES ) return 2;
return 0;
}
//============================================================================//
DWORD ALEXYONGKIGANTENG1xd(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
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
DWORD ALEXYONGKIGANTENG2xc(DWORD dwPtr, DWORD dwOfs){ 
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
DWORD ALEXYONGKIGANTENG3(DWORD dwPtr){ 
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
DWORD ALEXYONGKIGANTENG4(DWORD dwPtr){ 
	DWORD C; 
	if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
		C=((DWORD)dwPtr); 
		if(IsBadReadPtr((PDWORD)(C),4)==0){ 
			return C; 
		} 
	} 
	return C;
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
//============================================================================//
int GetMyCharaIndexed(unsigned int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR8);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + OFS_Player);
CTeam *MyTeam = (CTeam*) ((dwBase + P_BaseTEAM));
Index=MyTeam->iTeam;
return Index;
}

//============================================================================//
#define basegetVCPoss resultbasegetVCPoss

DWORD getVCPosa(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
	dwBasettt = ALEXYONGKIGANTENG2xc(OFS_Ammo2, 0x554);
	basegetVCPos = ALEXYONGKIGANTENG4(getVirtualCamPosition);
	if (!dwBasettt)return 0;
	DWORD getVCPosss;
	if (dwBasettt)
	{
		getVCPosss = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))basegetVCPos)(dwBasettt, Vect, Mat, iUnk);
	}
return getVCPosss;
}

#define baseDoLineCollyy resultbaseDoLineCollyy
//=========================MODE WP SMOKE ===========================//
DWORD ALEXDoLineColly1xc(UINT i)
{
	D3DXVECTOR3	vBone, vLocal;
	DWORD DoLineCollyyy;
	int TargetBonex;
	switch(AimBodyi)
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
	dwBasett   = ALEXYONGKIGANTENG1xd(OFS_Ammo2, 0x544 , 0x2C);
	baseDoLineColly = ALEXYONGKIGANTENG4 (DoLineCollision);
	getVCPosa(&vLocal,0,0);
	vBone = GetUserBonePos2(i,TargetBonex);
	if (dwBasett)
	{
		DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
	}
	return DoLineCollyyy;
}

#define baseALEXCallHitEventt resultbaseALEXCallHitEventt
//=========================MODE WP SMOKE ===========================//
DWORD ALEXCallHitEvent1xc(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD ALEXCallHitEventtt;
	dwBasett   = ALEXYONGKIGANTENG1xd(OFS_Ammo2, 0x544, 0x2C);
	dwBasetttt   = ALEXYONGKIGANTENG3(OFS_Ammo2);
	baseALEXCallHitEvent = ALEXYONGKIGANTENG4(WriteGameEvent_fire);
    getVCPosa(&vEnemy,0,0);
    if (dwBasett)
	{
		ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
	}
	return ALEXCallHitEventtt;
}


//=========================MODE WP SMOKE ===========================//

void ALEXCallDoLineColly1xc1()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed (i))continue;
		if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
		if(IsAlivedf(i)){
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXDoLineColly1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		}
	}
}


//=========================MODE WP SMOKE ===========================//
void ALEXHitEvent1()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed (i))continue;
		if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
		ALEXCallHitEvent1xc(i);
		if(IsAlivedf(i)){				
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		ALEXCallHitEvent1xc(i);
		_WriteMEM((DWORD)ResultBaseAmmo2,0x558,0x2C,0x00000000);
		}
	}

}

//=========================MODE WP SMOKE ===========================//
void WPSMOKE()
{
if(GetBattleState1()){
if(PisoTeleKill1){
ALEXCallDoLineColly1xc1();
DamagePisoTeleKill1=1;
}
if(PisoTeleKill1==0){
DamagePisoTeleKill1=0;
}
if(DamagePisoTeleKill1==1){
	ALEXHitEvent1();
}}}