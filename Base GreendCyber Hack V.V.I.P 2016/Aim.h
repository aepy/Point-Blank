bool Shot = false;
bool AimReal = false;
bool HookReal = false;
bool ShootReal = false;
float fX,fY,fZ = 0;  
DWORD BackUpReal = 0;
/*---------------------------------------- Declaration AutoShoot ----------------------------------------------------*/
_declspec(naked)void MouseHook()
{
	_asm {
		cmp [Shot],0
			je Normal
			mov eax, 1;
		ret
Normal:
		mov eax, [ecx+0x20]
		ret
	}
}

/*---------------------------------------- Declaration AsmAimBullet ----------------------------------------------------*/
_declspec(naked)void SetReal_End()
{
	_asm
	{
		cmp [AimReal],0
			je Skip
			mov eax,dword ptr ss:[esp+0x4]
		mov [BackUpReal],edx
			mov edx,[fX]
		mov [eax+0],edx
			mov edx,[fY]
		mov [eax+4],edx
			mov edx,[fZ]
		mov [eax+8],edx
			mov edx,[BackUpReal]
Skip:
		mov eax,dword ptr ss:[esp+0x4]
		fld dword ptr ds:[eax]
		fstp dword ptr ds:[ecx+0x18]
		fld dword ptr ds:[eax+0x4]
        fstp dword ptr ds:[ecx+0x1C]
        fld dword ptr ds:[eax+0x8]
        fstp dword ptr ds:[ecx+0x20]
        fld dword ptr ds:[ecx+0x18]
        fsub dword ptr ds:[ecx+0x0C]
        fstp dword ptr ds:[ecx+0x24]
        fld dword ptr ds:[ecx+0x1C]
        fsub dword ptr ds:[ecx+0x10]
		fstp dword ptr ds:[ecx+0x28]
        fld dword ptr ds:[ecx+0x20]
        fsub dword ptr ds:[ecx+0x14]
        fstp dword ptr ds:[ecx+0x2C]
        retn 0x4                             
	}
}


/*---------------------------------------- Declaration CallAimBullet ----------------------------------------------------*/
void HookAim()
{
	if(HookReal)return;
	MakePTR((PBYTE)ResultBullet,(DWORD)SetReal_End);
	HookReal = true;
}

/*---------------------------------------- Declaration AutoShoot ----------------------------------------------------*/
void DoAutoShot()
{
	if(ShootReal == false){
		MakePTR((PBYTE)ResultGetButton,(DWORD)MouseHook);
		ShootReal = true;
	}
	if(AutoShot==1){
		if(GetPlayer(MyCharaIndex()) > NULL)Shot = true;
		else Shot = false;
	}
}
/*---------------------------------------- Declaration AutoHeadShoot ----------------------------------------------------*/
void AutoHsReal(LPDIRECT3DDEVICE9 pDevice)
{
HookAim();
	if(AutoHS2 == 1)
	{
	AutoHS=0;
	BulletCall=0;
		DWORD pMyTarget = GetPlayer(MyCharaIndex());
		if(pMyTarget > NULL)
		{
			DWORD TargetIndex = TargetPlayer(pMyTarget);
			D3DXVECTOR3 OnWorld,OnScreen;
			
			switch(AimBody)
			{
			case 0:
				BoneIndexSelector = 7.0;
				break;
			case 1:
				BoneIndexSelector = 5;
				break;
			}
			UserBone(OnWorld,TargetIndex,BoneIndexSelector);
			AimReal = true;
			fX = OnWorld.x;
			fY = OnWorld.y + 0.1f;
			fZ = OnWorld.z;
		}
		else AimReal = false;
	}
	if(AutoHS2 == 0 && !AutoHS2)
	{
		AimReal = false;
	}
}
/*---------------------------------------- Declaration AutoHeadShoot ----------------------------------------------------*/
float CalcDistance( D3DXVECTOR3 VecA, D3DXVECTOR3 VecB ){
return sqrt( ( ( VecA.x - VecB.x ) * ( VecA.x - VecB.x ) ) +
( ( VecA.y - VecB.y ) * ( VecA.y - VecB.y ) ) +
( ( VecA.z - VecB.z ) * ( VecA.z - VecB.z ) ) );
}
BYTE GetUserLife(int iSlot){
DWORD g_pGameContext   = *(DWORD*)ResultBasePlayer2;
CDeathPlayer *Life = (CDeathPlayer *) (g_pGameContext + ResultUserDeath);
return Life->Death[iSlot];
VirtualProtect((PVOID*)(g_pGameContext + ResultUserDeath), 10, PAGE_EXECUTE_READWRITE, &d);
}
//--------------------------------------------------------------------
int GetCharaIndex(){
DWORD g_pGameContext   = *(DWORD*)ResultBasePlayer2;
CLocalPlayerID *LocID = (CLocalPlayerID *) (g_pGameContext + ResultTeam);
return LocID->ID;
VirtualProtect((PVOID*)(g_pGameContext + ResultTeam), 10, PAGE_EXECUTE_READWRITE, &d);
}
int GetPriorityTarget(){
int Result = -1;
float fMaxDistance = 180.0f;
D3DXVECTOR3 PlayerEnd, LocPlayer;
for(int index = 0; index < 16; index++){
if(!GetUserLife(index) && GetCharaIndex() != index){
if(GetCharaIndex() %2 != index % 2){
GetUserBone(LocPlayer, 7 , GetCharaIndex());
GetUserBone(PlayerEnd, 7 , index);
if (CalcDistance(LocPlayer, PlayerEnd) < fMaxDistance){
fMaxDistance = CalcDistance(PlayerEnd, LocPlayer);
Result = index;
}
}
}
}
return Result;
}
void AutoBulletTarget(LPDIRECT3DDEVICE9 pDevice){
	HookAim();
if(AutoHS){
AutoHS2=0;
BulletCall=0;
if(*(PBYTE)ResultBaseAmmo2 > NULL){
int AimSlot = GetPriorityTarget();
if(AimSlot != -1){
D3DXVECTOR3 OnWorld,OnScreen;
switch(AimBody){
case 0:
BoneIndexSelector = 7.0;
break;
case 1:
BoneIndexSelector = 5;
break;
}
float ScreenCenterX = (Viewport.Width /2.0f);
float ScreenCenterY = (Viewport.Height /2.0f);
float ScreenBottomY = (Viewport.Height);
if(GetUserBone(OnWorld,BoneIndexSelector,AimSlot)){
AimReal = true;
fX = OnWorld.x;
fY = OnWorld.y + 0.1f;
fZ = OnWorld.z;
if(YoWorlToScreenGa(pDevice,OnWorld,OnScreen)){
//DrawLine(ScreenCenterX,ScreenCenterY,OnScreen.x,OnScreen.y,1,RED);
	 {
int x = ( OnScreen.x);
int y = ( OnScreen.y);

//if(g_TexTest == NULL)D3DXCreateTextureFromFileInMemoryEx(pDevice,&Troll,sizeof(Troll),20,20,D3DX_DEFAULT,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,0,NULL,NULL,&g_TexTest);
        if(g_pSprite == NULL)D3DXCreateSprite(pDevice, &g_pSprite);
g_pSprite->Begin( D3DXSPRITE_ALPHABLEND );
	g_pSprite->Draw( g_TexTest, 0, 0, &D3DXVECTOR3( (int)OnScreen.x-10, (int)OnScreen.y-10, 0 ), RainbowTextTest );
	g_pSprite->End();
}
}}
else{
AimReal = false;
}
}else{
AimReal = false;
}
}
}
}