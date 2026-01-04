
/*---------------------------------------- Declaration Bullet Killer ----------------------------------------------------*/
DWORD Base_DoLine,Base_CamPos,Base_HitEvent,Base_HitEventt,CallHitEvent,CallDoLineColl,CallGetCamVPoss;
/*-------------------------------------------------------------------------------------------------------------------*/


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

/*-------------------------------------------------------------------------------------------------------------------*/
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

/*-------------------------------------------------------------------------------------------------------------------*/
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

/*-------------------------------------------------------------------------------------------------------------------*/
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
#define GetCamVPoss getVirtualCamPosition

DWORD GetCamVCPoss(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
	Base_CamPos = Define_2(ResultBaseAmmo2, PTR_CAMPOS);
	CallGetCamVPoss = Define_4(OFS_CamPosition);
	if (!Base_CamPos)return 0;
	DWORD RunVCPoss;
	if(Base_CamPos)
	{
		RunVCPoss = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))CallGetCamVPoss)(Base_CamPos, Vect, Mat, iUnk);
	}
return RunVCPoss;
}
int Switch=0;
#define DoLineColl CALL_DOLINE 

DWORD DoLineCollis(UINT i)
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
	DWORD Change;
	if ( Switch == 0 ) {Change=0x1C;} // Primary
	if ( Switch == 1 ) {Change=0x20;} // Pistol
	if ( Switch == 2 ) {Change=0x24;} // Melee
	if ( Switch == 3 ) {Change=0x28;} // Bomb
	if ( Switch == 4 ) {Change=0x2C;} // Smoke
	
	Base_DoLine   = Define_1(ResultBaseAmmo2, PTR_BaseAmmo , Change);
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

DWORD WriteGameEvent(UINT i)
{
	D3DXVECTOR3	vEnemy;
	DWORD RunHitEvent;
	DWORD Change;
	if ( Switch == 0 ) {Change=0x1C;} // Primary
	if ( Switch == 1 ) {Change=0x20;} // Pistol
	if ( Switch == 2 ) {Change=0x24;} // Melee
	if ( Switch == 3 ) {Change=0x28;} // Bomb
	if ( Switch == 4 ) {Change=0x2C;} // Smoke

	Base_HitEvent   = Define_1(ResultBaseAmmo2, PTR_BaseAmmo, Change);
	Base_HitEventt   = Define_3(ResultBaseAmmo2);
	CallHitEvent = Define_4(OFS_GameEventFire);
    GetCamVCPoss(&vEnemy,0,0);
    if(Base_HitEvent)
	{
		RunHitEvent = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))CallHitEvent)(Base_HitEvent, Base_HitEventt, &vEnemy, Base_HitEvent);// ikine bedo, podo ae
	}
	return RunHitEvent;
}
bool AutoOn=false;
bool AutoOn2=false;
void CallLineHit() {
if(KillerKey==1){
if(Killer==1){
	for(int i=0; i<=16; i++)
	{
			int MySlot = GetIdxTeam(GetMyCharaIndexed(i)); 
				if(GetIdxTeam(i) == MySlot) continue;
				if(IsAlive1(i)){
					DoLineCollis(i);
					AutoOn=true;
					if(AutoOn==true){
						WriteGameEvent(i);
					}
				}
			}
	}
}

	if(KillerKey==1){
		if(IsKeyPressed(VK_CAPITAL,0))
		{
	Killer=1;}
		else{
			Killer=0;
			AutoOn=false;}
	}
}
void AutoKill() {
if(OnAutoKiller==1){
if(AutoKiller==1){
	for(int i=0; i<=16; i++)
	{
			int MySlot = GetIdxTeam(GetMyCharaIndexed(i)); 
				if(GetIdxTeam(i) == MySlot) continue;
				if(IsAlive1(i)){
					DoLineCollis(i);
					AutoOn2=true;
					if(AutoOn2==true){
						WriteGameEvent(i);
					}
				}
			}
	}
}

	if(OnAutoKiller==1){
	AutoKiller=1;
	}
		else{
			AutoKiller=0;
			AutoOn2=false;
	}
}
