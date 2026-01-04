/*DirectKiller.h D3D9 PBHacks Last Edit By Fatur Rezo*/

/*---------------------------------------- Declaration Bomb Kill ----------------------------------------------------*/
DWORD dwBasett2,dwBasettt2,dwBasetttt2,baseALEXCallHitEvent2,baseDoLineColly2,basegetVCPos2;
LPTSTR PointBlankSTR8 = "PointBlank.exe";

/*-------------------------------------------------------------------------------------------------------------------*/
D3DXVECTOR3 GetUserBonePos2(int Idx ,int BoneIdx){
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
		}
	}
	return Out;
}

/*-------------------------------------------------------------------------------------------------------------------*/
D3DXVECTOR3 GetUserBonePos_Scd(int Idx ,int BoneIdx)
{
	D3DXVECTOR3 Out;
	unsigned long dwGameBase = *(DWORD*)(ResultBaseHealth2);
	if ( dwGameBase )
	{
		CGameCharaBase* GameBase = (CGameCharaBase*)( *(DWORD*)(dwGameBase + 0x14 + ( 0x4 * Idx ) ) );
		if ( GameBase && GameBase->m_BoneContext )
		{
			Out.x = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._41;
			Out.y = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._42;
			Out.z = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._43;
		}
	}
	return Out;
}

/*-------------------------------------------------------------------------------------------------------------------*/
bool IsAlivedf(int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR8);
unsigned long dwBase2	= *(DWORD*)(dwI3EXEC + ResultBaseHealth);
CHealth		*Health		= (CHealth*) ((dwBase2 + 0x264) + Index * 0x24);
if(Health->CurHP > 0.1f)
return true;
return false;
}

/*-------------------------------------------------------------------------------------------------------------------*/
int GetTeam2(int JONES)
{
for(int i = 0; i<=15; i+=2)
if( i == JONES ) return 1;
for(int i = 1; i<=15; i+=2)
if( i == JONES ) return 2;
return 0;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD BOMB1(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
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

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD BOMB2(DWORD dwPtr, DWORD dwOfs){ 
	DWORD C; 
	if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
		C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
		if(IsBadReadPtr((PDWORD)(C),4)==0){ 
			return *(PDWORD)C; 
		} 
	} 
	return C;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD BOMB3(DWORD dwPtr){ 
	DWORD C; 
	if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
		C=(*(DWORD*)(dwPtr)); 
		if(IsBadReadPtr((PDWORD)(C),4)==0){ 
			return C; 
		} 
	} 
	return C;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD BOMB4(DWORD dwPtr){ 
	DWORD C; 
	if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
		C=((DWORD)dwPtr); 
		if(IsBadReadPtr((PDWORD)(C),4)==0){ 
			return C; 
		} 
	} 
	return C;
}

/*-------------------------------------------------------------------------------------------------------------------*/
int GetMyCharaIndexed2(unsigned int Index)
{
unsigned long dwBase	= *(DWORD*)ResultBasePlayer2;
CTeam *MyTeam = (CTeam*) ((dwBase + ResultTeam));
Index=MyTeam->iTeam;
return Index;
}

/*-------------------------------------------------------------------------------------------------------------------*/
#define basegetVCPoss resultbasegetVCPoss
DWORD getVCPosBomb(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
	dwBasettt2 = BOMB2(ResultBaseAmmo2, 0x544);
	basegetVCPos2 = BOMB4(ResultCamPos);
	if (!dwBasettt2)return 0;
	DWORD getVCPosss;
	if (dwBasettt2)
	{
		getVCPosss = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))basegetVCPos2)(dwBasettt2, Vect, Mat, iUnk);
	}
return getVCPosss;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD BombDoLineColly1(UINT i)
{
	D3DXVECTOR3	vBone, vLocal;
	DWORD DoLineCollyyy;
	int TargetBonex;
	switch(opt.ModAim.AimBody)
	{
	case 0:
		TargetBonex = 7; // Kepala
		break;
	case 1:
		TargetBonex = 5; // Badan
		break;
	}
	dwBasett2   = BOMB1(ResultBaseAmmo2, 0x544 , 0x28);
	baseDoLineColly2 = BOMB4(ResultDoLine);
	getVCPosBomb(&vLocal,0,0);
	vBone = GetUserBonePos2(i,TargetBonex);
	if (dwBasett2)
	{
		DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly2)(dwBasett2, &vLocal, &vBone, GetTeam2(i));
	}
	return DoLineCollyyy;
}

#define baseALEXCallHitEventt resultbaseALEXCallHitEventt
/*-------------------------------------------------------------------------------------------------------------------*/
DWORD BombCallHitEvent1(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD ALEXCallHitEventtt;
	dwBasett2   = BOMB1(ResultBaseAmmo2, 0x544, 0x28);
	dwBasetttt2   = BOMB3(ResultBaseAmmo2);
	baseALEXCallHitEvent2 = BOMB4(ResultEventFire);
    getVCPosBomb(&vEnemy,0,0);
    if (dwBasett2)
	{
		ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent2)(dwBasett2, dwBasetttt2, &vEnemy, dwBasett2);
	}
	return ALEXCallHitEventtt;
}

/*-------------------------------------------------------------------------------------------------------------------*/
void BombCallDoLineColly1()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed2 (i))continue;
		if(GetTeam2(GetMyCharaIndexed2 (i)) == GetTeam2(i))continue;
		if(IsAlivedf(i)){
		BombDoLineColly1(i);
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
void BombHitEvent1()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed2 (i))continue;
		if(GetTeam2(GetMyCharaIndexed2 (i)) == GetTeam2(i))continue;
		BombCallHitEvent1(i);
		if(IsAlivedf(i)){				
		BombCallHitEvent1(i);
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
void GrenadeKill()
{
	if(GetBattleState())
	{
		if(opt.cKiller.BombKill==1)
		{
			BombCallDoLineColly1();
			opt.cKiller.DamageBombKill=1;
		}
		if(opt.cKiller.BombKill==0)
		{
			opt.cKiller.DamageBombKill=0;
		}
		if(opt.cKiller.DamageBombKill==1){
			/*BombHitEvent1();*/
		}
	}
}

/*---------------------------------------- Declaration Wp Smoke Kill ----------------------------------------------------*/
DWORD AnggaReviza1(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
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

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD AnggaReviza2(DWORD dwPtr, DWORD dwOfs){ 
	DWORD C; 
	if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
		C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
		if(IsBadReadPtr((PDWORD)(C),4)==0){ 
			return *(PDWORD)C; 
		} 
	} 
	return C;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD AnggaReviza3(DWORD dwPtr){ 
	DWORD C; 
	if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
		C=(*(DWORD*)(dwPtr)); 
		if(IsBadReadPtr((PDWORD)(C),4)==0){ 
			return C; 
		} 
	} 
	return C;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD AnggaReviza4(DWORD dwPtr){ 
	DWORD C; 
	if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
		C=((DWORD)dwPtr); 
		if(IsBadReadPtr((PDWORD)(C),4)==0){ 
			return C; 
		} 
	} 
	return C;
}

/*-------------------------------------------------------------------------------------------------------------------*/
int GetMyCharaIndexed23(unsigned int Index)
{
	unsigned long dwBase	= *(DWORD*)dwPBExe + ResultBasePlayer;
	CTeam *MyTeam = (CTeam*) ((dwBase + ResultTeam));
	Index=MyTeam->iTeam;
	return Index;
}

/*-------------------------------------------------------------------------------------------------------------------*/
#define basegetVCPoss resultbasegetVCPoss

DWORD getVCPosSmoke(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
	dwBasettt2 = AnggaReviza2(ResultBaseAmmo2, 0x544);
	basegetVCPos2 = AnggaReviza4(ResultCamPos);
	if (!dwBasettt2)return 0;
	DWORD getVCPosss;
	if (dwBasettt2)
	{
		getVCPosss = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))basegetVCPos2)(dwBasettt2, Vect, Mat, iUnk);
	}
return getVCPosss;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD SmokeDoLineColly1(UINT i)
{
	D3DXVECTOR3	vBone, vLocal;
	DWORD DoLineCollyyy;
	int TargetBonex;
	switch(opt.ModAim.AimBody)
	{
	case 0:
		TargetBonex = 7; // Kepala
		break;
	case 1:
		TargetBonex = 5; // Badan
		break;
	}
	dwBasett2   = AnggaReviza1(ResultBaseAmmo2, 0x544 , 0x2C);
	baseDoLineColly2 = AnggaReviza4(ResultDoLine);
	getVCPosSmoke(&vLocal,0,0);
	vBone = GetUserBonePos2(i,TargetBonex);
	if (dwBasett2)
	{
		DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly2)(dwBasett2, &vLocal, &vBone, GetTeam2(i));
	}
	return DoLineCollyyy;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD SmokeDoLineColly2(UINT i)
{
	D3DXVECTOR3	vBone, vLocal;
	DWORD DoLineCollyyy;
	int TargetBonex;
	switch(opt.ModAim.AimBody)
	{
	case 0:
		TargetBonex = 7; // Kepala
		break;
	case 1:
		TargetBonex = 5; // Badan
		break;
	}
	dwBasett2   = AnggaReviza1(ResultBaseAmmo2, 0x544 , 0x2C);
	baseDoLineColly2 = AnggaReviza4(ResultDoLine);
	getVCPosSmoke(&vLocal,0,0);
	vBone = GetUserBonePos2(i,TargetBonex);
	if (dwBasett2)
	{
		DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly2)(dwBasett2, &vLocal, &vBone, GetTeam2(i));
	}
	return DoLineCollyyy;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD SmokeDoLineColly3(UINT i)
{
	D3DXVECTOR3	vBone, vLocal;
	DWORD DoLineCollyyy;
	int TargetBonex;
	switch(opt.ModAim.AimBody)
	{
	case 0:
		TargetBonex = 7; // Kepala
		break;
	case 1:
		TargetBonex = 5; // Badan
		break;
	}
	dwBasett2   = AnggaReviza1(ResultBaseAmmo2, 0x544 , 0x2C);
	baseDoLineColly2 = AnggaReviza4(ResultDoLine);
	getVCPosSmoke(&vLocal,0,0);
	vBone = GetUserBonePos2(i,TargetBonex);
	if (dwBasett2)
	{
		DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly2)(dwBasett2, &vLocal, &vBone, GetTeam2(i));
	}
	return DoLineCollyyy;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD SmokeDoLineColly4(UINT i)
{
	D3DXVECTOR3	vBone, vLocal;
	DWORD DoLineCollyyy;
	int TargetBonex;
	switch(opt.ModAim.AimBody)
	{
	case 0:
		TargetBonex = 7; // Kepala
		break;
	case 1:
		TargetBonex = 5; // Badan
		break;
	}
	dwBasett2   = AnggaReviza1(ResultBaseAmmo2, 0x544 , 0x2C);
	baseDoLineColly2 = AnggaReviza4(ResultDoLine);
	getVCPosSmoke(&vLocal,0,0);
	vBone = GetUserBonePos2(i,TargetBonex);
	if (dwBasett2)
	{
		DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly2)(dwBasett2, &vLocal, &vBone, GetTeam2(i));
	}
	return DoLineCollyyy;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD SmokeDoLineColly5(UINT i)
{
	D3DXVECTOR3	vBone, vLocal;
	DWORD DoLineCollyyy;
	int TargetBonex;
	switch(opt.ModAim.AimBody)
	{
	case 0:
		TargetBonex = 7; // Kepala
		break;
	case 1:
		TargetBonex = 5; // Badan
		break;
	}
	dwBasett2   = AnggaReviza1(ResultBaseAmmo2, 0x544 , 0x2C);
	baseDoLineColly2 = AnggaReviza4(ResultDoLine);
	getVCPosSmoke(&vLocal,0,0);
	vBone = GetUserBonePos2(i,TargetBonex);
	if (dwBasett2)
	{
		DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly2)(dwBasett2, &vLocal, &vBone, GetTeam2(i));
	}
	return DoLineCollyyy;
}

#define baseALEXCallHitEventt resultbaseALEXCallHitEventt
/*-------------------------------------------------------------------------------------------------------------------*/
DWORD SmokeCallHitEvent1(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD ALEXCallHitEventtt;
	dwBasett2   = AnggaReviza1(ResultBaseAmmo2, 0x544, 0x2C);
	dwBasetttt2   = AnggaReviza3(ResultBaseAmmo2);
	baseALEXCallHitEvent2 = AnggaReviza4(ResultEventFire);
    getVCPosSmoke(&vEnemy,0,0);
    if (dwBasett2)
	{
		ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent2)(dwBasett2, dwBasetttt2, &vEnemy, dwBasett2);
	}
	return ALEXCallHitEventtt;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD SmokeCallHitEvent2(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD ALEXCallHitEventtt;
	dwBasett2   = AnggaReviza1(ResultBaseAmmo2, 0x544, 0x2C);
	dwBasetttt2   = AnggaReviza3(ResultBaseAmmo2);
	baseALEXCallHitEvent2 = AnggaReviza4(ResultEventFire);
    getVCPosSmoke(&vEnemy,0,0);
    if (dwBasett2)
	{
		ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent2)(dwBasett2, dwBasetttt2, &vEnemy, dwBasett2);
	}
	return ALEXCallHitEventtt;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD SmokeCallHitEvent3(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD ALEXCallHitEventtt;
	dwBasett2   = AnggaReviza1(ResultBaseAmmo2, 0x544, 0x2C);
	dwBasetttt2   = AnggaReviza3(ResultBaseAmmo2);
	baseALEXCallHitEvent2 = AnggaReviza4(ResultEventFire);
    getVCPosSmoke(&vEnemy,0,0);
    if (dwBasett2)
	{
		ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent2)(dwBasett2, dwBasetttt2, &vEnemy, dwBasett2);
	}
	return ALEXCallHitEventtt;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD SmokeCallHitEvent4(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD ALEXCallHitEventtt;
	dwBasett2   = AnggaReviza1(ResultBaseAmmo2, 0x544, 0x2C);
	dwBasetttt2   = AnggaReviza3(ResultBaseAmmo2);
	baseALEXCallHitEvent2 = AnggaReviza4(ResultEventFire);
    getVCPosSmoke(&vEnemy,0,0);
    if (dwBasett2)
	{
		ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent2)(dwBasett2, dwBasetttt2, &vEnemy, dwBasett2);
	}
	return ALEXCallHitEventtt;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD SmokeCallHitEvent5(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD ALEXCallHitEventtt;
	dwBasett2   = AnggaReviza1(ResultBaseAmmo2, 0x544, 0x2C);
	dwBasetttt2   = AnggaReviza3(ResultBaseAmmo2);
	baseALEXCallHitEvent2 = AnggaReviza4(ResultEventFire);
    getVCPosSmoke(&vEnemy,0,0);
    if (dwBasett2)
	{
		ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent2)(dwBasett2, dwBasetttt2, &vEnemy, dwBasett2);
	}
	return ALEXCallHitEventtt;
}

/*-------------------------------------------------------------------------------------------------------------------*/
void SmokeCallDoLineColly1()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed23 (i))continue;
		if(GetTeam2(GetMyCharaIndexed23 (i)) == GetTeam2(i))continue;
		if(IsAlivedf(i)){
		SmokeDoLineColly1(i);
		SmokeDoLineColly2(i);
		SmokeDoLineColly3(i);
		SmokeDoLineColly4(i);
		SmokeDoLineColly5(i);
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
void SmokeCallDoLineColly2()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed23 (i))continue;
		if(GetTeam2(GetMyCharaIndexed23 (i)) == GetTeam2(i))continue;
		if(IsAlivedf(i)){
		SmokeDoLineColly1(i);
		SmokeDoLineColly2(i);
		SmokeDoLineColly3(i);
		SmokeDoLineColly4(i);
		SmokeDoLineColly5(i);
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
void SmokeCallDoLineColly3()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed23 (i))continue;
		if(GetTeam2(GetMyCharaIndexed23 (i)) == GetTeam2(i))continue;
		if(IsAlivedf(i)){
		SmokeDoLineColly1(i);
		SmokeDoLineColly2(i);
		SmokeDoLineColly3(i);
		SmokeDoLineColly4(i);
		SmokeDoLineColly5(i);
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
void SmokeHitEvent1()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed23 (i))continue;
		if(GetTeam2(GetMyCharaIndexed23 (i)) == GetTeam2(i))continue;
		SmokeCallHitEvent1(i);
		SmokeCallHitEvent2(i);
		SmokeCallHitEvent3(i);
		SmokeCallHitEvent4(i);
		SmokeCallHitEvent5(i);
		if(IsAlivedf(i)){				
		SmokeCallHitEvent1(i);
		SmokeCallHitEvent2(i);
		SmokeCallHitEvent3(i);
		SmokeCallHitEvent4(i);
		SmokeCallHitEvent5(i);
		}
	}

}

/*-------------------------------------------------------------------------------------------------------------------*/
void SmokeHitEvent2()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed23 (i))continue;
		if(GetTeam2(GetMyCharaIndexed23 (i)) == GetTeam2(i))continue;
		SmokeCallHitEvent1(i);
		SmokeCallHitEvent2(i);
		SmokeCallHitEvent3(i);
		SmokeCallHitEvent4(i);
		SmokeCallHitEvent5(i);
		if(IsAlivedf(i)){				
		SmokeCallHitEvent1(i);
		SmokeCallHitEvent2(i);
		SmokeCallHitEvent3(i);
		SmokeCallHitEvent4(i);
		SmokeCallHitEvent5(i);
		}
	}

}

/*-------------------------------------------------------------------------------------------------------------------*/
void SmokeHitEvent3()
{
	for (int i = 0; i < 16; i++)
	{
		if (!GetMyCharaIndexed23 (i))continue;
		if(GetTeam2(GetMyCharaIndexed23 (i)) == GetTeam2(i))continue;
		SmokeCallHitEvent1(i);
		SmokeCallHitEvent2(i);
		SmokeCallHitEvent3(i);
		SmokeCallHitEvent4(i);
		SmokeCallHitEvent5(i);
		if(IsAlivedf(i)){				
		SmokeCallHitEvent1(i);
		SmokeCallHitEvent2(i);
		SmokeCallHitEvent3(i);
		SmokeCallHitEvent4(i);
		SmokeCallHitEvent5(i);
		}
	}

}

/*-------------------------------------------------------------------------------------------------------------------*/
void SmokeKill()
{
	if(GetBattleState())
	{
		if(opt.cKiller.PisoTeleKill==1)
		{
			SmokeCallDoLineColly1();
			SmokeCallDoLineColly2();
			SmokeCallDoLineColly3();
			opt.cKiller.DamagePisoTeleKill=1;
		}
		if(opt.cKiller.PisoTeleKill==0)
		{
			opt.cKiller.DamagePisoTeleKill=0;
		}
		if(opt.cKiller.DamagePisoTeleKill==1)
		{
			SmokeHitEvent1();
			SmokeHitEvent2();
			SmokeHitEvent3();
		}
	}
}

/*---------------------------------------- Declaration Bullet Killer ----------------------------------------------------*/
DWORD Base_DoLine,Base_CamPos,Base_HitEvent,Base_HitEventt,CallHitEvent,CallDoLineColl,CallGetCamVPoss;

/*----------------------------------------------------------------------------------*/
int GetIdxTeam(int Team)
{
for(int i = 0; i<=15; i+=2)
if( i == Team ) return 1;
for(int i = 1; i<=15; i+=2)
if( i == Team ) return 2;
return 0;
}

/*----------------------------------------------------------------------------------*/
DWORD Define_1(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
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

/*----------------------------------------------------------------------------------*/
DWORD Define_2(DWORD dwPtr, DWORD dwOfs){ 
	DWORD C; 
	if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
		C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
		if(IsBadReadPtr((PDWORD)(C),4)==0){ 
			return *(PDWORD)C; 
		} 
	} 
	return C;
}

/*----------------------------------------------------------------------------------*/
DWORD Define_3(DWORD dwPtr){ 
	DWORD C; 
	if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
		C=(*(DWORD*)(dwPtr)); 
		if(IsBadReadPtr((PDWORD)(C),4)==0){ 
			return C; 
		} 
	} 
	return C;
}

/*----------------------------------------------------------------------------------*/
DWORD Define_4(DWORD dwPtr){ 
	DWORD C; 
	if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
		C=((DWORD)dwPtr); 
		if(IsBadReadPtr((PDWORD)(C),4)==0){ 
			return C; 
		} 
	} 
	return C;
}

/*-------------------------------------------------------------------------------------------------------------------*/
int GetMyCharaIndexed(unsigned int Index)
{
	unsigned long dwBase	= *(DWORD*)dwPBExe + ResultBasePlayer;
	CTeam *MyTeam = (CTeam*) ((dwBase + ResultTeam));
	Index=MyTeam->iTeam;
	return Index;
}

/*----------------------------------------------------------------------------------*/
#define GetCamVPoss getVirtualCamPosition
DWORD GetCamVCPoss(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
	Base_CamPos = Define_2(ResultBaseAmmo2, ResultPTRWeapon);
	CallGetCamVPoss = Define_4(ResultCamPos);
	if (!Base_CamPos)return 0;
	DWORD RunVCPoss;
	if(Base_CamPos)
	{
		RunVCPoss = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))CallGetCamVPoss)(Base_CamPos, Vect, Mat, iUnk);
	}
return RunVCPoss;
}

/*----------------------------------------------------------------------------------*/
#define DoLineColl CALL_DOLINE 
DWORD DoLineCollis(UINT i)
{
	D3DXVECTOR3	vBone, vLocal;
	DWORD RunDoLine;
	int BoneIndexSelector;
	switch(opt.ModAim.AimBody)
	{
	case 0:
		BoneIndexSelector = 7.7; // Head
		break;
	case 1:
		BoneIndexSelector = 5; // Body
		break;
	}
	DWORD Change;
	if ( opt.cKiller.Switch == 0 ) {Change=0x1C;} // Primary
	if ( opt.cKiller.Switch == 1 ) {Change=0x20;} // Pistol
	Base_DoLine   = Define_1(ResultBaseAmmo2, ResultPTRAmmo , Change);
	CallDoLineColl = Define_4(ResultDoLine);
	GetCamVCPoss(&vLocal,0,0);
	vBone = GetUserBonePos_Scd(i, BoneIndexSelector);
	if(Base_DoLine)
	{
		RunDoLine = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, int))CallDoLineColl)(Base_DoLine, &vLocal, &vBone, GetIdxTeam(i));
	}
	return RunDoLine;
}

/*----------------------------------------------------------------------------------*/
#define GameEventHit CALL_HITEVENT
DWORD WriteGameEvent(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD RunHitEvent;
	DWORD Change;
	if ( opt.cKiller.Switch == 0 ) {Change=0x1C;} // Primary
	if ( opt.cKiller.Switch == 1 ) {Change=0x20;} // Pistol
	Base_HitEvent   = Define_1(ResultBaseAmmo2, ResultPTRAmmo, Change);
	Base_HitEventt   = Define_3(ResultBaseAmmo2);
	CallHitEvent = Define_4(ResultEventFire);
    GetCamVCPoss(&vEnemy,0,0);
    if(Base_HitEvent)
	{
		RunHitEvent = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))CallHitEvent)(Base_HitEvent, Base_HitEventt, &vEnemy, Base_HitEvent);// ikine bedo, podo ae
	}
	return RunHitEvent;
}

/*----------------------------------------------------------------------------------*/
bool AutoOn=false;
void BulletKiller()
{
	if(opt.cKiller.BulletCall==1)
	{
		if(opt.cKiller.PisoTeleKill1==1)
		{
			for(int i=0; i<=16; i++)
			{
				int MySlot = GetIdxTeam(GetMyCharaIndexed(i)); 
				if(GetIdxTeam(i) == MySlot) continue;
				if(IsAlive(i)){
					DoLineCollis(i);
					AutoOn = true;
					if(AutoOn == true)
					{
						WriteGameEvent(i);
					}
				}
			}
		}
	}
	if(opt.cKiller.BulletCall==1)
	{
		if(IsKeyPressed(VK_RBUTTON,0)&1)
		{
			opt.cKiller.PisoTeleKill1=1;
		}
		else
		{
			opt.cKiller.PisoTeleKill1=0;
			AutoOn = false;
		}
	}
}
