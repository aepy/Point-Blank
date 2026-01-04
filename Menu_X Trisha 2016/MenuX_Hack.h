DWORD MenuX_Hack()
{
	while(1)
	{
		if(bPiso == false)
		{
			BurstPiso	= _ReadMEM( (DWORD)ResultBaseAmmo2, PTR_BaseAmmo, 0x24, 0xC9C);
		}
		if(BrussKnife == 0)
		{
			bPiso = false;
			_WriteMEM( (DWORD)ResultBaseAmmo2, PTR_BaseAmmo, 0x24, 0xC9C, BurstPiso);
		}
		if(BrussKnife == 1)
		{
			bPiso = true;
			_WriteMEM( (DWORD)ResultBaseAmmo2, PTR_BaseAmmo, 0x24, 0xC9C, BurstPiso);
		}
if(Invincible ==1){
DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD GM = ModulePB + ResultInvincible;
PrivateOnly((void *)(GM),(int*)(PBYTE)"\x6F\x12\x83\x40",4);
}
if(Invincible ==0){
DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD GM = ModulePB + ResultInvincible;
PrivateOnly((void *)(GM),(int*)(PBYTE)"\x6F\x12\x83\x3C",4);
}
if(Invicible1 ==1){PrivateOnly((void *)(ModulePB + ResultInvincible),(int*)(PBYTE)"\x6F\x12\x83\x40",4);}
if(Invicible1 ==0){PrivateOnly((void *)(ModulePB + ResultInvincible),(int*)(PBYTE)"\x6F\x12\x83\x3C",4);}
/*----------------------------------------------------------------------------------*/
		if(QuickChange==1)
		{
			if(IsBadReadPtr((void*)ResultBaseAmmo2,4)==0)
			{
				DWORD TheRead = *(PDWORD)((DWORD)ResultBaseAmmo2)+PTR_BaseAmmo-4;
				if(IsBadReadPtr((void*)TheRead,4)==0)
				{
					DWORD ReadKe1 = *(PDWORD)((DWORD)(TheRead))+0x3C;
					if(IsBadReadPtr((void*)ReadKe1,4)==0)
					{
						DWORD ReadKe2 = *(PDWORD)((DWORD)(ReadKe1))+0x67;
						if(IsBadReadPtr((void*)ReadKe2,4)==0)
						{
						*(PDWORD)ReadKe2=0x3FC28F5B;
						Sleep(50*2);
						}
					}
				}
			}
		}
if(Recoil==1)
{
for(int d=0x20;d<=0x50;d+=4)
{
_WriteMEM((DWORD)ResultBaseAmmo2,PTR_NoRecoil,d,0x00000000);
}
}
/*----------------------------------------------------------------------------------*/
if(PlayerSpeed ==1){
PrivateOnly((void *)(dwPBExe + ResultPlayerSpeed),(int*)(PBYTE)"\x00\x00\x00\x40\xE1\x7A\x8F\x3F",8);}
if(PlayerSpeed ==0){
PrivateOnly((void *)(dwPBExe + ResultPlayerSpeed),(int*)(PBYTE)"\x00\x00\x00\x40\xE1\x7A\x84\x3F",8);}
/*----------------------------------------------------------------------------------*/
if(Reload==1)
{
for(int Kudet=0x1C;Kudet<=0x20;Kudet+=4)
{
if(IsBadReadPtr((void*)ResultBaseAmmo2,4)==0)
{
DWORD TheRead = *(PDWORD)((DWORD)ResultBaseAmmo2)+PTR_BaseAmmo;
if(IsBadReadPtr((void*)TheRead,4)==0)
{
DWORD ReadKe1 = *(PDWORD)((DWORD)(TheRead))+Kudet;
if(IsBadReadPtr((void*)ReadKe1,4)==0)
{
DWORD ReadKe2 = *(PDWORD)((DWORD)(ReadKe1))+0x30;
if(IsBadReadPtr((void*)ReadKe2,4)==0)
{
DWORD ReadKe3 = *(PDWORD)((DWORD)(ReadKe2))+0x67;
if(IsBadReadPtr((void*)ReadKe3,4)==0)
{
*(PDWORD)ReadKe3=0x41;
Sleep(25*2);
}
}
}
}
}
}
}
/*------------------------------------------- Declaration Hacks ------------------------------------------------------*/
		if(autoGM == 1)
		{
			unsigned long dwBase	= *(DWORD*)(ResultBasePlayer2);
			CTeam *pTeam		= ((CTeam*)(dwBase + ResultTeam)); 
			int MyTeam = GetTeam(pTeam->iTeam);
				GM			*DualDinamic = (GM*)((dwBase + ResultSkill2)+ pTeam->iTeam * RANKSIZE);
				CNames		*pFake	     = (CNames*)((dwBase + ResultNames) + pTeam->iTeam  * NAMESIZE);
				if(autoGM == 1)
				{
					DualDinamic->iRank = 0x36;
					DualDinamic->iHack = 0xFFFFFF;
					strcpy(pFake->szNames,"{/COL}"); // max 16 angka/huruf
				}
		}
		
		if(autoGM == 2)
		{
			unsigned long dwBase	= *(DWORD*)(ResultBasePlayer2);
			CTeam *pTeam		= ((CTeam*)(dwBase + ResultTeam)); 
			int MyTeam = GetTeam(pTeam->iTeam);
				GM			*DualDinamic = (GM*)((dwBase + ResultSkill2)+ pTeam->iTeam * RANKSIZE);
				CNames		*pFake		 = (CNames*)((dwBase + ResultNames) + pTeam->iTeam  * NAMESIZE);
				if(autoGM == 2)
				{
					DualDinamic->iRank = 0x35;
					DualDinamic->iHack = 0xFFFFFF;
					strcpy(pFake->szNames,"GuardiansGalaxy"); // max 16 angka/huruf
				}
		}
/*----------------------------------------------------------------------------------*/
if(HiddenWeapon == 1){
Function_One(ResultBaseAmmo2, 0x50C, 0xFF);
}
/*----------------------------------------------------------------------------------*/
if(NoFallDamage == 1){
patchPTR(ResultBaseAmmo2, 0x513, 14);
patchPTR(ResultBaseAmmo2, 0x513, 172);
patchPTR(ResultBaseAmmo2, 0x513, 4);
patchPTR(ResultBaseAmmo2, 0x513, 64);
}
/*----------------------------------------------------------------------------------*/
if(WallShotHero ==1){
DWORD Pointblank = (DWORD)LoadLibraryA("Pointblank.exe"); 
PrivateOnly((void *)(Pointblank + ResultWallShot),(int*)(PBYTE)"\x90\x90",2);
}
if(WallShotHero ==0){ DWORD Pointblank = (DWORD)LoadLibraryA("Pointblank.exe"); 
PrivateOnly((void *)(Pointblank + ResultWallShot),(int*)(PBYTE)"\x75\x1F",2);
}
/*----------------------------------------------------------------------------------*/
if(Magnet==1){PrivateOnly((void *)(FrameDX+ 0xADD8D),(void*)(PBYTE)"\xC0\x20", 2);Sleep(20); }
if(Magnet==0){PrivateOnly((void *)(FrameDX+ 0xADD8D),(void*)(PBYTE)"\xC0\x30", 2);Sleep(20);  }
/*----------------------------------------------------------------------------------*/
if(UNYU ==1){
PrivateOnly((void *)(dwPBExe + ResultBugWeapon),(int*)(PBYTE)"\xC0",1);}
if(UNYU ==0){
PrivateOnly((void *)(dwPBExe + ResultBugWeapon),(int*)(PBYTE)"\xBE",1);}
/*----------------------------------------------------------------------------------*/
if (FlyCacadMode == 1){
if (GetAsyncKeyState(VK_SPACE)&&0x8000){
		if(IsBadReadPtr((void*)ResultBaseAmmo2,4)==0){
		DWORD TheRead = *(PDWORD)((DWORD)(ResultBaseAmmo2))+0x558-0x10;
		if(IsBadReadPtr((void*)TheRead,4)==0){
		DWORD ReadKe1 = *(PDWORD)((DWORD)(TheRead))+0x98;
		DWORD ReadKe2 = *(PDWORD)((DWORD)(TheRead))+0x9C;
		if(IsBadReadPtr((void*)ReadKe1,4)==0){
		*(PDWORD)ReadKe1=0x00000000;}
		if(IsBadReadPtr((void*)ReadKe2,4)==0){
		*(PDWORD)ReadKe2=0x00000000;}
		Sleep(20);
		}}}}		
if(JumpHight==1){
			if (GetAsyncKeyState(VK_SPACE)&&0x8000){{
				if(IsBadReadPtr((void*)ResultBaseAmmo2,4)==0){
					DWORD TheRead = *(PDWORD)((DWORD)(ResultBaseAmmo2))+ResultNorecoil-0x10;//0x548;
					if(IsBadReadPtr((void*)TheRead,4)==0){
						DWORD ReadKe1 = *(PDWORD)((DWORD)(TheRead))+0x98;
						DWORD ReadKe2 = *(PDWORD)((DWORD)(TheRead))+0x9C;
						if(IsBadReadPtr((void*)ReadKe1,4)==0){
							*(PDWORD)ReadKe1=0x00000000;}
						if(IsBadReadPtr((void*)ReadKe2,4)==0){
							*(PDWORD)ReadKe2=0x00000000;}}}}}}
///*----------------------------------------------------------------------------------*/
if(Freeze==1){ 
PatchValue(ResultBaseAmmo2, 0x18, 0x18, 0xE8, 1069715291);}
/*----------------------------------------------------------------------------------*/
if(FreeMove==1){
__try { 
GetWeapon_IndexA(ResultBaseAmmo2 + 0x10,0x44,0x18,0xDC,0x4);
}__except(EXCEPTION_EXECUTE_HANDLER){ 
}}
/*----------------------------------------------------------------------------------*/
if(AntiOut == 1)
{LongPtr(OFS_Idle, 0x18, 0x1C3, 0x41);
LongPtr(OFS_Idle, 0x18, 0x1C7, 0x42);}
		if(WallBug==1)
		{
			NHMemFuction((void *)((DWORD)LoadLibraryA("NxCharacter.2.8.1.dll")+0x16510),(int*)(PBYTE)"\x89\x8B\x38",3);
		}

		if(WallBug==0)
		{	
			NHMemFuction((void *)((DWORD)LoadLibraryA("NxCharacter.2.8.1.dll")+0x16510),(int*)(PBYTE)"\x89\x8B\x34",3);
		}		
if (RafidFire==1)
		{
__try 
		{ 
if (*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x544)+0x38)==1){
*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30)+0x5D4)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
}
if (*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x544)+0x38)==0){
*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30)+0x5D4)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
}
}__except (EXCEPTION_EXECUTE_HANDLER ) 
{
	Sleep(100);
}
}
Sleep(0*5); 
	}
	return 0;
}
