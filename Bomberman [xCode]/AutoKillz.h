
#define DoLineColl CALL_DOLINE 

DWORD DinanDoLineCollis(UINT i)
{
	D3DXVECTOR3	vBone, vLocal;
	DWORD RunDoLine;
	int BoneIndexSelector;
	switch(AimBody)
	{
	case 0:
		BoneIndexSelector = 7.7; // Head
		break;
	case 1:
		BoneIndexSelector = 5; // Body
		break;
	}
	Base_DoLine   = Define_1(ResultBaseAmmo2, PTR_BaseAmmo , 0x1C);
	CallDoLineColl = Define_4(DoLineCollision);
	GetCamVCPoss(&vLocal,0,0);
	vBone = GetUserBonePos_Scd(i, BoneIndexSelector);
	if(Base_DoLine)
	{
		RunDoLine = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, int))CallDoLineColl)(Base_DoLine, &vLocal, &vBone, GetIdxTeam(i));
	}
	return RunDoLine;
}
#define GameEventHit CALL_HITEVENT

DWORD DinanWriteGameEvent(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD RunHitEvent;

	Base_HitEvent   = Define_1(ResultBaseAmmo2, PTR_BaseAmmo, 0x1C);
	Base_HitEventt   = Define_3(ResultBaseAmmo2);
	CallHitEvent = Define_4(OFS_GameEventFire);
    GetCamVCPoss(&vEnemy,0,0);
    if(Base_HitEvent)
	{
		RunHitEvent = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))CallHitEvent)(Base_HitEvent, Base_HitEventt, &vEnemy, Base_HitEvent);// ikine bedo, podo ae
	}
	return RunHitEvent;
}
bool Killerz=false;
void AutoKillerzz() {
if(AutoKillerz==1){
if(AKillerz==1){
	for(int i=0; i<=16; i++)
	{
			int MySlot = GetIdxTeam(GetMyCharaIndexed(i)); 
				if(GetIdxTeam(i) == MySlot) continue;
				if(IsAlive1(i)){
					DinanDoLineCollis(i);
					AutoOn=true;
					if(Killerz==true){
						DinanWriteGameEvent(i);
					}
				}
			}
	}
}

	if(AutoKillerz==1){
	AKillerz=1;}
		else{
			AKillerz=0;
			Killerz=false;
		}
}