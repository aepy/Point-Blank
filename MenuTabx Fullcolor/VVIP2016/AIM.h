bool BulletEnable = false;
bool HookedShot = false;
bool HookedFire = false;
bool Shot = false;
bool Fire = false;
bool WhileShot = false;
float fX,fY,fZ = 0;  
//D3DVIEWPORT9 g_ViewPort;
DWORD BackupEDXTele = 0;
float CalcDistance( D3DXVECTOR3 VecA, D3DXVECTOR3 VecB )
{
        return sqrt( ( ( VecA.x - VecB.x ) * ( VecA.x - VecB.x ) ) +
                 ( ( VecA.y - VecB.y ) * ( VecA.y - VecB.y ) ) +
                 ( ( VecA.z - VecB.z ) * ( VecA.z - VecB.z ) ) );
}

int GetPriorityTarget()
{
	int Result = -1;
	float fMaxDistance = 180.0f;
	D3DXVECTOR3 PlayerEnd, LocPlayer;
	for (int index = 0; index < 16; index++)
	{
		if (!GetUserLife(index) && GetMyCharaIndex() != index)
		{
			if (GetMyCharaIndex() %2 != index % 2)
			{
				GetUserBone(LocPlayer, 7 , GetMyCharaIndex());
				GetUserBone(PlayerEnd, 7 , index);
				if(CalcDistance(LocPlayer, PlayerEnd) < fMaxDistance)
				{
					fMaxDistance = CalcDistance(PlayerEnd, LocPlayer);
					Result = index;
				}
			}
		}
	}
	return Result;
}
/*---------------------------------------- Declaration PlayerTarget ----------------------------------------------------*/
DWORD GetPlayerTarget(int MyIdx)
{
	DWORD BasePlayer_B = *(DWORD*)(ResultBaseHealth2);
	if(IsBadReadPtr((void*)BasePlayer_B,4))return 0;
	DWORD PlayerIndexA = *(DWORD*)(BasePlayer_B + 0x14 + (MyIdx * 4));
	if(IsBadReadPtr((void*)PlayerIndexA,4))return 0;
	DWORD PlayerIndexB = *(DWORD*)(PlayerIndexA + ResultPTRpTarget);
	if(IsBadReadPtr((void*)PlayerIndexB,4))return 0;
	DWORD IsTargetingEnemy = *(DWORD*)(PlayerIndexB + ResultPTRpTarget2);
	if(IsBadReadPtr((void*)IsTargetingEnemy,4))return 0;
	return IsTargetingEnemy;
}
/*---------------------------------------- Declaration TargetIndex ----------------------------------------------------*/
int GetTargetIndex(DWORD PlayerTarget)
{
	DWORD BasePlayer_B = *(DWORD*)(ResultBaseHealth2);
	if(PlayerTarget && BasePlayer_B){
		for(int i = 0; i<=15; i++){
			DWORD PlayerIndexA = *(DWORD*)(BasePlayer_B + 0x14 + (i * 4));
			if(PlayerIndexA == PlayerTarget)return i;
		}
	}
	return -1;
}
/*-------------------------------------------------------------------------------------------------------------------*/
DWORD MakePTR(BYTE *MemoryTarget, DWORD FunctionTarget)
{
	DWORD dwOldProtect,dwBkup;
	DWORD dwRetn = *(DWORD*)(MemoryTarget);

	VirtualProtect(MemoryTarget, 4, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	*((DWORD *)(MemoryTarget)) = FunctionTarget;
	VirtualProtect(MemoryTarget, 4, dwOldProtect, &dwBkup);
	return dwRetn;
}
/*---------------------------------------- Declaration AutoShoot ----------------------------------------------------*/
_declspec(naked)void MouseHook()
{
	_asm {
		cmp [Shot],0
			je Normal
			mov eax, 1;
		ret
Normal:
		mov eax, [ecx+0x24]
		ret
	}
}

/*---------------------------------------- Declaration AutoFire ----------------------------------------------------*/
_declspec(naked)void UpdateNickOnTarget_Hook()
{
	_asm
	{
		cmp opt.ModAim.AutoFire,1
			je StartShot
			cmp dword ptr[eax+0x94E8],0
			jmp RETURN
StartShot:
		cmp dword ptr[eax+0x94E8],0
			je Disable
			mov WhileShot,1
			jmp RETURN
Disable:
		mov WhileShot,0
RETURN:
		jmp RETNeoUpdateNickOnTarget;
	}
}

/*---------------------------------------- Declaration AsmAimBullet ----------------------------------------------------*/
_declspec(naked)void i3CollideeLine_SetEnd()
{
	_asm
	{
		cmp [BulletEnable],0
		je Skip
		mov eax,dword ptr ss:[esp+0x4]
		mov [BackupEDXTele],edx
		mov edx,[fX]
		mov [eax+0x0],edx
		mov edx,[fY]
		mov [eax+0x4],edx
		mov edx,[fZ]
		mov [eax+0x8],edx
		mov edx,[BackupEDXTele]
Skip:
		MOV EAX,DWORD PTR SS:[ESP+0x4]
		FLD DWORD PTR DS:[EAX]
		FSTP DWORD PTR DS:[ECX+0x18]
		FLD DWORD PTR DS:[EAX+0x4]
		FSTP DWORD PTR DS:[ECX+0x1C]
		FLD DWORD PTR DS:[EAX+0x8]
		FSTP DWORD PTR DS:[ECX+0x20]
		FLD DWORD PTR DS:[ECX+0x18]
		FSUB DWORD PTR DS:[ECX+0xC]
		FSTP DWORD PTR DS:[ECX+0x24]
		FLD DWORD PTR DS:[ECX+0x1C]
		FSUB DWORD PTR DS:[ECX+0x10]
		FSTP DWORD PTR DS:[ECX+0x28]
		FLD DWORD PTR DS:[ECX+0x20]
		FSUB DWORD PTR DS:[ECX+0x14]
		FSTP DWORD PTR DS:[ECX+0x2C]
		RETN 0x4
	}
}

/*---------------------------------------- Declaration CallAimBullet ----------------------------------------------------*/
void HookTelekill()
{
	if(bHookedTele)return;
	MakePTR((PBYTE)ResultBullet,(DWORD)i3CollideeLine_SetEnd);
	bHookedTele = true;
}
void DoAimBullet(LPDIRECT3DDEVICE9 pDevice){
	if(opt.ModAim.Accuracy){
		if(*(PBYTE)ResultBaseAmmo2 > NULL){
			int AimSlot = GetPriorityTarget();
			if(AimSlot != -1){
				D3DXVECTOR3 OnWorld,OnScreen;
				int BoneIndexSelector = 0;
				switch(opt.ModAim.AimBody)
				{
					case 0: BoneIndexSelector = 7; break;
					case 1: BoneIndexSelector = 5; break;
				}
				float ScreenCenterX = (Viewport.Width /2.0f);
				float ScreenCenterY = (Viewport.Height /2.0f);
				float ScreenBottomY = (Viewport.Height);
				if(GetUserBone(OnWorld,BoneIndexSelector,AimSlot)){
					BulletEnable = true;
					fX = OnWorld.x;
					fY = OnWorld.y + 0.1f;
					fZ = OnWorld.z;
					if(YoWorlToScreenGa(pDevice,OnWorld,OnScreen)){
						PrintText("TARGET", OnScreen.x,OnScreen.y,BLUE, pFonts);
						int x = ( GetSystemMetrics( 0 ) / 2);
						int y = ( GetSystemMetrics( 1 ) / 2);
						//Circle (OnScreen.x, OnScreen.y,6,true,SKYBLUE,pDevice); // < pake aja lingkaran ea ?
						Tools.DrawCircle(D3DXVECTOR2(OnScreen.x, OnScreen.y),8,40,GREEN);//Circle
						Tools.FillRGB(OnScreen.x-10, OnScreen.y, 7, 1,SKYBLUE,pDevice);
						Tools.FillRGB(OnScreen.x+4, OnScreen.y, 7, 1,SKYBLUE,pDevice);
						Tools.FillRGB(OnScreen.x, OnScreen.y-10, 1, 7,SKYBLUE,pDevice);
						Tools.FillRGB(OnScreen.x, OnScreen.y+4, 1, 7,SKYBLUE,pDevice);
					}
				}
			}
			else
			{
				BulletEnable = false;
			}
		}
		else
		{
			BulletEnable = false;
		}
	}
}
//ini gk deteck kan ? ea auto log
/*---------------------------------------- Declaration AutoShoot ----------------------------------------------------*/
void DoAutoShot()
{
	if(HookedShot == false){
		MakePTR((PBYTE)ResultGetButton,(DWORD)MouseHook);
		HookedShot = true;
	}
	if(opt.ModAim.AutoShot==1){
		if(GetPlayerTarget(GetMyCharaIndex()) > NULL)Shot = true;
		else Shot = false;
	}
}

/*---------------------------------------- Declaration AutoFire ----------------------------------------------------*/
void AimFire()
{
	if(HookedFire == false){
		MakePTR((PBYTE)NeoUpdateNickOnTarget,(DWORD)UpdateNickOnTarget_Hook);
		HookedFire = true;
	}
	if(opt.ModAim.AutoFire==1){
		if(GetPlayerTarget(GetMyCharaIndex()) > NULL)Fire = true;
		else Fire = false;
	}
}

/*---------------------------------------- Declaration AutoHeadShoot ----------------------------------------------------*/
void DoAutoHSNoSyarat(LPDIRECT3DDEVICE9 pDevice)
{
	if(opt.ModAim.AutoHS2 == 1)
	{
		DWORD pMyTarget = GetPlayerTarget(GetMyCharaIndex());
		if(pMyTarget > NULL)
		{
			DWORD TargetIndex = GetTargetIndex(pMyTarget);
			D3DXVECTOR3 OnWorld,OnScreen;
			GetUserBone(OnWorld,TargetIndex,7.0);
			BulletEnable = true;
			fX = OnWorld.x;
			fY = OnWorld.y + 0.1f;
			fZ = OnWorld.z;
		}
		else BulletEnable = false;
	}
	if(opt.ModAim.AutoHS2 == 0 && !opt.ModAim.AutoHS2)
	{
		BulletEnable = false;
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/