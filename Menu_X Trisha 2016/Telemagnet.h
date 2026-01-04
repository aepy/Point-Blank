int CallTele,PortalPenghancur,TelePortal =0;
DWORD Px,Py,Pz;
bool SetPlayerPos	= false;
bool bHooIsRedTeam	= false;
/*bool IsAlive(int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR8);
unsigned long dwBase2	= *(DWORD*)(dwI3EXEC + OFS_Health);
CHealth		*Health		= (CHealth*) ((dwBase2 + 0x264) + Index * PTRSizeHealth);
if(Health->CurHP > 0.1f)
return true;
return false;
}*/
int pMySlots()
{
	unsigned long dwBase	= *(DWORD*) ResultBasePlayer2;//ResultPlayerBase;
	CTeam *MyTeam			=  (CTeam*)((dwBase + ResultTeam));
	return MyTeam->iTeam;
}
//------------------------------------------------------------------------------------
int IsRedTeam(int iSlot)
{
	if(bHooIsRedTeam == true)
	{
		if (iSlot == 0 ||iSlot == 2||iSlot == 4||iSlot == 6||iSlot == 8||iSlot == 10||iSlot == 12||iSlot == 14)return 1;
		else
		if (iSlot == 1 ||iSlot == 3||iSlot == 5||iSlot == 7||iSlot == 9||iSlot == 11||iSlot == 13||iSlot == 15)return 2;
		bHooIsRedTeam = false;
	}
	return 0;
}
//------------------------------------------------------------------------------------
void TeleMagnet(int PlayerToCall )
{
	unsigned long BasePlayer	= *(DWORD*)ResultBasePlayer2;
	unsigned long PlayerPos		= *(DWORD*)ResultBaseHealth2+0x14;	
	if(SetPlayerPos == false)
	{
		__try
		{
			BYTE SLot= *(BYTE*)(BasePlayer + ResultTeam);
			Px = *(DWORD*)(*(DWORD*)(BasePlayer+ResultPlayer+(SLot*4))+0x6C);
			Pz = *(DWORD*)(*(DWORD*)(BasePlayer+ResultPlayer+(SLot*4))+0x70);
			Py = *(DWORD*)(*(DWORD*)(BasePlayer+ResultPlayer+(SLot*4))+0x74);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
		}
	}
	if(CallTele==1)
	{
		SetPlayerPos=true;
		__try
		{
			*(DWORD*)(*(DWORD*)(*(DWORD*)(PlayerPos + (PlayerToCall * 4)) + PlayerBody) + CoordinateX)	= Px;
			*(DWORD*)(*(DWORD*)(*(DWORD*)(PlayerPos + (PlayerToCall * 4)) + PlayerBody) + CoordinateZ)	= Pz;
			*(DWORD*)(*(DWORD*)(*(DWORD*)(PlayerPos + (PlayerToCall * 4)) + PlayerBody) + CoordinateY)	= Py;
			
			*(DWORD*)(*(DWORD*)(*(DWORD*)(PlayerPos + (PlayerToCall * 4)) + PlayerBody) + CoordinateX2)	= Px;
			*(DWORD*)(*(DWORD*)(*(DWORD*)(PlayerPos + (PlayerToCall * 4)) + PlayerBody) + CoordinateZ2)	= Pz;
			*(DWORD*)(*(DWORD*)(*(DWORD*)(PlayerPos + (PlayerToCall * 4)) + PlayerBody) + CoordinateY2)	= Py;
			
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
		}
	}
	if(CallTele==0)
	{
		SetPlayerPos=false;
	}
}
void Telemagnet(){
if(MagnetTele==1){	
		for (int i = 0; i < 15; i++){
		bHooIsRedTeam	= true;
		int pMySlot		= IsRedTeam(pMySlots()); 
		if(IsRedTeam(i) == pMySlot) continue;
		if(IsAlive(i)){
		CallTele=1;
		if(CallTele==1){ 
		TeleMagnet(i);}}}
		bHooIsRedTeam=false;}
		if(TelePortal==0){
		CallTele=0;
		}
}