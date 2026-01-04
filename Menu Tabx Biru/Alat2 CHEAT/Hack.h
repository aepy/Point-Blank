#include "KeyPresent.h"
#include "DirectKiller.h"

/*-------------------------------------------------------------------------------------------------------------------*/
void SetEvent(int param1, int param2, int param3)
{
	DWORD BaseECX = *(DWORD*)(ResultBasePlayer2);
	__asm
	{
		push 0
		push 0
		push 0
		push param3
		push param2
		push param1
		mov ecx, [BaseECX]
		call ResultSetEvent
	}
}

/*---------------------------------------- Declaration Vote Kick ----------------------------------------------------*/
void VKick()
{
	if (GetBattleState())
	{
		for(int i = 0; i<=15; i++) 
		{
		int iSlot = GetMyCharaIndex();
		if(iSlot == i)continue;
		int P1=iSlot+1;
		int P2=iSlot+1;
		SetEvent(0xA0,(int)&P1,(int)&P2);//const class CCharaInfo *__thiscall CharaInfoDataBase::getCharaInfo(int) <-- GhostExit Packet
		Sleep(500);
		}
	}
}

/*---------------------------------------- Declaration FireSpeed ----------------------------------------------------*/
//FireSpeed
float xFireSpeed=0.01;
__declspec(naked)void FireSpeed_on()
{
	_asm
	{
	fld dword ptr[xFireSpeed]
	mov esp,ebp
	jmp dword ptr[RETNeoFireSpeed]
	}
}
/*---------------------------------------- Declaration Vote Kick ----------------------------------------------------*/
DWORD Func_VKick()
{
	if(opt.cPlayer.VoteKick==1)
		VKick();
	return 0;
}
/*---------------------------------------- Declaration BombEnywhere ----------------------------------------------------*/
DWORD Func_BombEnywhere()
{
	if(GetBattleState()){
	if(opt.cPlayer.BombEnywhere == 1)
	{
		cGameBases *GameBase = (cGameBases*) *(DWORD*)(ResultBasePlayer2);
		DWORD dwBase = *(DWORD*)(ResultBasePlayer2);
		CTeam *pTeam				= ((CTeam*)(dwBase + ResultTeam)); 
		DWORD pCalculate2 = *(DWORD*)(dwBase + 0x4 * pTeam->iTeam + ResultPLAYER);
		CPlayers	*Me	= (CPlayers*)(pCalculate2 + 0x64 );
		if(opt.cPlayer.BombEnywhere == 1)
		{
			GameBase->StageInfo->BombPositionA.x = Me->pos.x;
			GameBase->StageInfo->BombPositionA.y = Me->pos.y;
			GameBase->StageInfo->BombPositionA.z = Me->pos.z;
		}
	}}
	
	if(GetBattleState()){
	if(opt.cPlayer.BombEnywhere == 2)
	{
		cGameBases *GameBase = (cGameBases*) *(DWORD*)(ResultBasePlayer2);
		DWORD dwBase = *(DWORD*)(ResultBasePlayer2);
		CTeam *pTeam				= ((CTeam*)(dwBase + ResultTeam)); 
		DWORD pCalculate2 = *(DWORD*)(dwBase + 0x4 * pTeam->iTeam + ResultPLAYER);
		CPlayers	*Me	= (CPlayers*)(pCalculate2 + 0x64 );
		if(opt.cPlayer.BombEnywhere == 2)
		{
			GameBase->StageInfo->BombPositionB.x = Me->pos.x;
			GameBase->StageInfo->BombPositionB.y = Me->pos.y;
			GameBase->StageInfo->BombPositionB.z = Me->pos.z;
		}
	}}
	return 0;
}

/*---------------------------------------- Declaration Fire Speed ----------------------------------------------------*/
DWORD Func_FireSpeed()
{
	if(opt.cWeapon.frspd==1)
		JMPE9((PBYTE)ResultFireSpeed,(DWORD)FireSpeed_on,5);
	if(opt.cWeapon.frspd==0)
		MemWrite((void*)ResultFireSpeed,(void*)(PBYTE)"\xD9\x45\xF8\x8B\xE5",5);
	return 0;
}
/*---------------------------------------- Declaration HP Minus ----------------------------------------------------*/
DWORD Func_HPMinus()
{
	if(opt.cPlayer.UnHP==1)
		WritePTR( ResultBaseHealth2,ResultPTRAddCharaHealth + GetMyCharaIndex() * 0x24, 0xFFFFFFFF);
	return 0;
}
/*---------------------------------------- Declaration Replace ----------------------------------------------------*/
DWORD Func_Replace()
{
/*----------------------------------------------------------------------------------*/
		if(opt.cSpesial.smk)
		{
			for (int i = 0; i <=16;i++)
				switch(opt.cSpesial.smk)
			{
				case 1: MakePoint(dwPBExe + ResultBasePlayer ,ResultSmoke + (i * 0x158),0x35E20D79); break;
				case 2: MakePoint(dwPBExe + ResultBasePlayer ,ResultSmoke + (i * 0x158),0x35E20D6C); break;
				case 3: MakePoint(dwPBExe + ResultBasePlayer ,ResultSmoke + (i * 0x158),0x35E20D6F); break;
				case 4: MakePoint(dwPBExe + ResultBasePlayer ,ResultSmoke + (i * 0x158),0x35E20D72); break;
				case 5: MakePoint(dwPBExe + ResultBasePlayer ,ResultSmoke + (i * 0x158),0x35E20D70); break;
				case 6: MakePoint(dwPBExe + ResultBasePlayer ,ResultSmoke + (i * 0x158),0x35E20D64); break;
				case 7: MakePoint(dwPBExe + ResultBasePlayer ,ResultSmoke + (i * 0x158),0x35E20D5D); break;
			}
		}
		if(opt.cSpesial.Beret)
		{
			for (int i = 0; i <=16;i++)
				switch(opt.cSpesial.Beret)
			{
				case 1: MakePoint(dwPBExe + ResultBasePlayer ,0x281A8 + (i * 0x158),0x1103003001); break; //Assault Beret
				case 2: MakePoint(dwPBExe + ResultBasePlayer ,0x281A8 + (i * 0x158),0x1103003002); break; //SMG Beret 
				case 3: MakePoint(dwPBExe + ResultBasePlayer ,0x281A8 + (i * 0x158),0x1103003003); break; //Sniper Beret 
				case 4: MakePoint(dwPBExe + ResultBasePlayer ,0x281A8 + (i * 0x158),0x1103003004); break; //Shotgun Beret 
				case 5: MakePoint(dwPBExe + ResultBasePlayer ,0x281A8 + (i * 0x158),0x1103003005); break; //Handgun Beret
				case 6: MakePoint(dwPBExe + ResultBasePlayer ,0x281A8 + (i * 0x158),0x1103003006); break; //Best Clan Beret
				case 7: MakePoint(dwPBExe + ResultBasePlayer ,0x281A8 + (i * 0x158),0x1103003007); break; //Baret with a red star 
				case 8: MakePoint(dwPBExe + ResultBasePlayer ,0x281A8 + (i * 0x158),0x1103003008); break; //Baret with yellow star 
				case 9: MakePoint(dwPBExe + ResultBasePlayer ,0x281A8 + (i * 0x158),0x1103003009); break; //Beret with crossed knives
			   case 10: MakePoint(dwPBExe + ResultBasePlayer ,0x281A8 + (i * 0x158),0x1103003010); break; //Beret Champion PBTN 
			}
		}

		/*----------------------------------------------------------------------------------*/
		if(opt.cSpesial.lchr)
		{
			for (int i = 0; i <=16;i++)
				switch(opt.cSpesial.lchr)
			{
				case 1: MakePoint(dwPBExe + ResultBasePlayer ,ResultPrimary + (i * 0x158),0x5F5ECEC); break;
				case 2: MakePoint(dwPBExe + ResultBasePlayer ,ResultPrimary + (i * 0x158),0x5F5ECC3); break;
				case 3: MakePoint(dwPBExe + ResultBasePlayer ,ResultPrimary + (i * 0x158),0x5F5ECF2); break;
				case 4: MakePoint(dwPBExe + ResultBasePlayer ,ResultPrimary + (i * 0x158),0x5F5ECFC); break;
				case 5: MakePoint(dwPBExe + ResultBasePlayer ,ResultPrimary + (i * 0x158),0x5F5ED18); break;
				case 6: MakePoint(dwPBExe + ResultBasePlayer ,ResultPrimary + (i * 0x158),0x5F5ECE5); break;
				case 7: MakePoint(dwPBExe + ResultBasePlayer ,ResultPrimary + (i * 0x158),0x5F61F82); break;
				case 8: MakePoint(dwPBExe + ResultBasePlayer ,ResultSecondary + (i * 0x158),0x23D2902A); break;
				case 9: MakePoint(dwPBExe + ResultBasePlayer ,ResultSecondary + (i * 0x158),601002028); break;
			}
		}
return 0;
}
		/*---------------------------------------- Declaration Replace All Mode ----------------------------------------------------*/
DWORD Func_ReplaceAllMode()
{
	/*----------------------------------------------------------------------------------*/
		if(GetBattleState()){
		if(opt.cSpesial.ram == 1){ 
			unsigned long PtrAdrkla = *(LPBOOL)(ResultBasePlayer2); 
			CTeam* GetSlot = (CTeam*)(PtrAdrkla + ResultTeam);{
				MakePoint(ResultBasePlayer2, ResultPrimary + (GetSlot->iTeam * 0x158), 0x5F5ECEC);//Famas Launcher
				MakePoint(ResultBasePlayer2, ResultSecondary + (GetSlot->iTeam * 0x158), 0x5F5ECEC);
				MakePoint(ResultBasePlayer2, ResultMelee + (GetSlot->iTeam * 0x158), 0x5F5ECEC);
				MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), 0x5F5ECEC);}}}
		if(GetBattleState()){
		if(opt.cSpesial.ram == 2){ 
			unsigned long PtrAdrkla = *(LPBOOL)(ResultBasePlayer2); 
			CTeam* GetSlot = (CTeam*)(PtrAdrkla + ResultTeam);{
				MakePoint(ResultBasePlayer2, ResultPrimary + (GetSlot->iTeam * 0x158), 0x5F5ECC3);//K-201 Exit
				MakePoint(ResultBasePlayer2, ResultSecondary + (GetSlot->iTeam * 0x158), 0x5F5ECC3);
				MakePoint(ResultBasePlayer2, ResultMelee + (GetSlot->iTeam * 0x158), 0x5F5ECC3);
				MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), 0x5F5ECC3);}}}
		if(GetBattleState()){
		if(opt.cSpesial.ram == 3){ 
			unsigned long PtrAdrkla = *(LPBOOL)(ResultBasePlayer2); 
			CTeam* GetSlot = (CTeam*)(PtrAdrkla + ResultTeam);{
				MakePoint(ResultBasePlayer2, ResultPrimary + (GetSlot->iTeam * 0x158), 0x5F5ECF2);//AK 47 FC
				MakePoint(ResultBasePlayer2, ResultSecondary + (GetSlot->iTeam * 0x158), 0x5F5ECF2);
				MakePoint(ResultBasePlayer2, ResultMelee + (GetSlot->iTeam * 0x158), 0x5F5ECF2);
				MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), 0x5F5ECF2);}}}
		if(GetBattleState()){
		if(opt.cSpesial.ram == 4){
			unsigned long PtrAdrkla = *(LPBOOL)(ResultBasePlayer2); 
			CTeam* GetSlot = (CTeam*)(PtrAdrkla + ResultTeam);{
				MakePoint(ResultBasePlayer2, ResultPrimary + (GetSlot->iTeam * 0x158), 0x5F5ECFC);//AK Sopmod R
				MakePoint(ResultBasePlayer2, ResultSecondary + (GetSlot->iTeam * 0x158), 0x5F5ECFC);
				MakePoint(ResultBasePlayer2, ResultMelee + (GetSlot->iTeam * 0x158), 0x5F5ECFC);
				MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), 0x5F5ECFC);}}}
		if(GetBattleState()){
		if(opt.cSpesial.ram == 5){ 
			unsigned long PtrAdrkla = *(LPBOOL)(ResultBasePlayer2); 
			CTeam* GetSlot = (CTeam*)(PtrAdrkla + ResultTeam);{
				MakePoint(ResultBasePlayer2, ResultPrimary + (GetSlot->iTeam * 0x158), 0x5F5ED18);//SCAR D
				MakePoint(ResultBasePlayer2, ResultSecondary + (GetSlot->iTeam * 0x158), 0x5F5ED18);
				MakePoint(ResultBasePlayer2, ResultMelee + (GetSlot->iTeam * 0x158), 0x5F5ED18);
				MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), 0x5F5ED18);}}}
		if(GetBattleState()){
		if(opt.cSpesial.ram == 6){
			unsigned long PtrAdrkla = *(LPBOOL)(ResultBasePlayer2); 
			CTeam* GetSlot = (CTeam*)(PtrAdrkla + ResultTeam);{
				MakePoint(ResultBasePlayer2, ResultPrimary + (GetSlot->iTeam * 0x158), 0x5F5ECE5);//M4 SR-16 FC
				MakePoint(ResultBasePlayer2, ResultSecondary + (GetSlot->iTeam * 0x158), 0x5F5ECE5);
				MakePoint(ResultBasePlayer2, ResultMelee + (GetSlot->iTeam * 0x158), 0x5F5ECE5);
				MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), 0x5F5ECE5);}}}
		if(GetBattleState()){
		if(opt.cSpesial.ram == 7)
		{
			unsigned long PtrAdrkla = *(LPBOOL)(ResultBasePlayer2); 
			CTeam* GetSlot = (CTeam*)(PtrAdrkla + ResultTeam);{
				MakePoint(ResultBasePlayer2, ResultPrimary + (GetSlot->iTeam * 0x158), 0x5F61F82);//RPG-7
				MakePoint(ResultBasePlayer2, ResultSecondary + (GetSlot->iTeam * 0x158), 0x5F61F82);
				MakePoint(ResultBasePlayer2, ResultMelee + (GetSlot->iTeam * 0x158), 0x5F61F82);
				MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), 0x5F61F82);}}}
		if(GetBattleState()){
		if(opt.cSpesial.ram == 8){
			unsigned long PtrAdrkla = *(LPBOOL)(ResultBasePlayer2); 
			CTeam* GetSlot = (CTeam*)(PtrAdrkla + ResultTeam);{
				MakePoint(ResultBasePlayer2, ResultPrimary + (GetSlot->iTeam * 0x158), 0x23D2902A);//HK-69
				MakePoint(ResultBasePlayer2, ResultSecondary + (GetSlot->iTeam * 0x158), 0x23D2902A);
				MakePoint(ResultBasePlayer2, ResultMelee + (GetSlot->iTeam * 0x158), 0x23D2902A);
				MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), 0x23D2902A);}}}
		if(GetBattleState()){
		if(opt.cSpesial.ram == 9){
			unsigned long PtrAdrkla = *(LPBOOL)(ResultBasePlayer2); 
			CTeam* GetSlot = (CTeam*)(PtrAdrkla + ResultTeam);{
				MakePoint(ResultBasePlayer2, ResultPrimary + (GetSlot->iTeam * 0x158), 601002028);//M79
				MakePoint(ResultBasePlayer2, ResultSecondary + (GetSlot->iTeam * 0x158), 601002028);
				MakePoint(ResultBasePlayer2, ResultMelee + (GetSlot->iTeam * 0x158), 601002028);
				MakePoint(ResultBasePlayer2, ResultSmoke + (GetSlot->iTeam * 0x158), 601002028);}}}
		return 0;
}
/*----------------------------------------------------------------------------------*/
void BrustKnife()
{
if(bPiso == false){
			PisoGila = TestPacth(ResultBaseAmmo2, ResultPTRAmmo, ResultMALESIZE, ResultPTRCaclKnife);}
		if(opt.cWeapon.BrustKnife==0){
			bPiso = false;
			PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, ResultMALESIZE, ResultPTRCaclKnife, PisoGila);}
		if(opt.cWeapon.BrustKnife == 1){
			bPiso = true;
			PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, ResultMALESIZE, ResultPTRCaclKnife, PisoGila);}
//----------------------------------------------------------- [[Super Jump]]
			if(opt.cPlayer.CallFlyHack==1)
			{
				{
			if(IsBadReadPtr((void*)ResultBaseAmmo2,4)==0)
				 {
			DWORD TheRead = *(PDWORD)((DWORD)(ResultBaseAmmo2))+ResultNorecoil-0x10;
			if(IsBadReadPtr((void*)TheRead,4)==0)
			 {
			DWORD ReadKe1 = *(PDWORD)((DWORD)(TheRead))+0x98;
			DWORD ReadKe2 = *(PDWORD)((DWORD)(TheRead))+0x9C;
			if(IsBadReadPtr((void*)ReadKe1,4)==0)
				 {
			*(PDWORD)ReadKe1=0x00000000;}
			if(IsBadReadPtr((void*)ReadKe2,4)==0)
			  {
			*(PDWORD)ReadKe2=0x00000000;
				  }
			  Sleep(50);
			}}}}}
/*----------------------------------Ammo------------------------------------------------*/
void AmmoReload(){
if(GetBattleState()){
			if(opt.cWeapon.Ammo == 1)
			{
				if(bAmmo == false)
				{
					__ReadMem(ResultBaseAmmo2, ResultPTRWeapon, ResultPRIMARYSIZE, ResultPTRCaclAmmo, 1);
					__ReadMem(ResultBaseAmmo2, ResultPTRWeapon, ResultBOMBSIZE, ResultPTRCaclAmmo, 2);
					bAmmo = true;
				}
				if(bAmmo == true)
				{
					_WriteMEM(ResultBaseAmmo2, ResultPTRWeapon, ResultPRIMARYSIZE, ResultPTRCaclAmmo, Weapon);
					_WriteMEM(ResultBaseAmmo2, ResultPTRWeapon, ResultSECONDARYSIZE, ResultPTRCaclAmmo, Pistol);
				}
			}}
/*----------------------------------------------------------------------------------*/
		if(GetBattleState()){
		if(opt.cWeapon.HiddenWeapon == 1){
		Function_One(ResultBaseAmmo2, 0x50C, 0xFF);
		}
		}
/*----------------------------------------------------------------------------------*/
		if(GetBattleState()){
		if(opt.cWeapon.QuickChange == 1){
			_WriteMEM(ResultBaseAmmo2, ResultQuick, 0x3C, 0x64, 0x3FC28F5B);}}
/*----------------------------------------------------------------------------------*/
		if(opt.cPlayer.AntiOut == 1){
			LongPtr1(ResultBasePlayer2 - 0x8, 0x18, PTR_Idle, 0x41);
			LongPtr1(ResultBasePlayer2 - 0x8, 0x18, PTR_Idle2, 0x42);}}
/*------------------------------------------- Declaration FastReload ------------------------------------------------------*/
void FastReload()
{
if(opt.cWeapon.Reload){
c_WeaponIndex_B(dwPBExe + ResultBaseAmmo,ResultPTRAmmo,ResultPRIMARYSIZE, 0x30,0x67,0x41);
c_WeaponIndex_B(dwPBExe + ResultBaseAmmo,ResultPTRAmmo,ResultSMOKESIZE, 0x30,0x67,0x41); }

/*----------------------------------------------------------------------------------*/
		if(GetBattleState()){
		if(opt.cWeapon.Recoil == 1){{
		for( int iR = 32; iR <= 108; iR += 4 )
		LongPtr1(ResultBaseAmmo2, ResultNorecoil, iR, 0);}}}
/*----------------------------------------------------------------------------------*/
		if(opt.cPlayer.FreeMove == 1){
		_WriteMEM(ResultBasePlayer2 - ResultBOMBSIZE, 0x44, 0x18, 0xDC, 0x4);}
/*----------------------------------------------------------------------------------*/
		if(opt.cPlayer.Freeze==1){ 
			Replay_12ddfx(ResultBaseAmmo2, 0x18, 0x18, 0xE8, 1069715291);}
/*----------------------------------------------------------------------------------*/
		if(opt.cPlayer.Rspw == 1){
			WritePtr(ResultBaseAmmo2, ResultPTRAmmo-0x31, 0x40);}
/*----------------------------------------------------------------------------------*/
		if(opt.cPlayer.JumpHight==1){
			if (GetAsyncKeyState(VK_SPACE)&&0x8000){{
				if(IsBadReadPtr((void*)ResultBaseAmmo2,4)==0){
					DWORD TheRead = *(PDWORD)((DWORD)(ResultBaseAmmo2))+ResultNorecoil-0x10;//0x548;
					if(IsBadReadPtr((void*)TheRead,4)==0){
						DWORD ReadKe1 = *(PDWORD)((DWORD)(TheRead))+0x98;
						DWORD ReadKe2 = *(PDWORD)((DWORD)(TheRead))+0x9C;
						if(IsBadReadPtr((void*)ReadKe1,4)==0){
							*(PDWORD)ReadKe1=0x00000000;}
						if(IsBadReadPtr((void*)ReadKe2,4)==0){
							*(PDWORD)ReadKe2=0x00000000;}}}}}}}
/*---------------------------------------- Declaration Tele Player ----------------------------------------------------*/
void TelePlayer(int PlayerToCall )
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
	if(opt.cKiller.CallTele==1)
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
	if(opt.cKiller.CallTele==0)
	{
		SetPlayerPos=false;
	}
}
//--------------------------------------------------------------------
void FakeEvolution() ;
/*------------------------------------------- Declaration Hacks ------------------------------------------------------*/
DWORD RankGMM()
{
	while(1)
	{
		/*----------------------------------------------------------------------------------*/
		if(opt.cPlayer.autoGM == 1)
		{
			unsigned long dwBase	= *(DWORD*)(ResultBasePlayer2);
			CTeam *pTeam		= ((CTeam*)(dwBase + ResultTeam)); 
			int MyTeam = GetTeam(pTeam->iTeam);
				GM			*DualDinamic = (GM*)((dwBase + ResultSkill2)+ pTeam->iTeam * RANKSIZE);
				CNames		*pFake	     = (CNames*)((dwBase + ResultNames) + pTeam->iTeam  * NAMESIZE);
				if(opt.cPlayer.autoGM == 1)
				{
					DualDinamic->iRank = 0x36;
					DualDinamic->iHack = 0xFFFFFF;
					strcpy(pFake->szNames,"{/COL}"); // max 16 angka/huruf
				}
		}
		
		if(opt.cPlayer.autoGM == 2)
		{
			unsigned long dwBase	= *(DWORD*)(ResultBasePlayer2);
			CTeam *pTeam		= ((CTeam*)(dwBase + ResultTeam)); 
			int MyTeam = GetTeam(pTeam->iTeam);
				GM			*DualDinamic = (GM*)((dwBase + ResultSkill2)+ pTeam->iTeam * RANKSIZE);
				CNames		*pFake		 = (CNames*)((dwBase + ResultNames) + pTeam->iTeam  * NAMESIZE);
				if(opt.cPlayer.autoGM == 2)
				{
					DualDinamic->iRank = 0x35;
					DualDinamic->iHack = 0xFFFFFF;
					strcpy(pFake->szNames,"GuardiansGalaxy"); // max 16 angka/huruf
				}
		}
		/*----------------------------------------------------------------------------------*/
		if(opt.cPlayer.WallBug==1){
			PrivateOnly((void *)(NxCharakter2 + WTF),(int*)(PBYTE)"\xFF",1);}
		if(opt.cPlayer.WallBug==0){
			PrivateOnly((void *)(NxCharakter2 + WTF),(int*)(PBYTE)"\x89\x8B\x34\x01\x00\x00\x89\x93\x38\x01\x00\x00\x89\x83\x3C\x01",16);}
/*----------------------------------------------------------------------------------*/
		if(GetBattleState()){
			if(opt.cPlayer.BugLuxivile ==1){ 
				DWORD Pointblank = (DWORD)LoadLibraryA("NxCharacter.2.8.1.dll"); 
				PrivateOnly((void *)(Pointblank + ResultBugHover1),(int*)(PBYTE)"\x3C",1);
				PrivateOnly((void *)(Pointblank + ResultBugHover2),(int*)(PBYTE)"\x3C",1);}}
		if(GetBattleState()){
			if(opt.cPlayer.BugLuxivile ==0){ 
				DWORD Pointblank = (DWORD)LoadLibraryA("NxCharacter.2.8.1.dll"); 
				PrivateOnly((void *)(Pointblank + ResultBugHover1),(int*)(PBYTE)"\x1C",1);
				PrivateOnly((void *)(Pointblank + ResultBugHover2),(int*)(PBYTE)"\x1C",1);}}
		/*----------------------------------------------------------------------------------*/
		if(opt.cKiller.TellePlayer==1)
		{	
			for (int i = 0; i < 15; i++)
			{
				bHooIsRedTeam	= true;
				int pMySlot		= IsRedTeam(GetMyCharaIndex()); 
				if(IsRedTeam(i) == pMySlot) continue;
				if(IsAlive(i))
				{
					opt.cKiller.CallTele=1;
					if(opt.cKiller.CallTele==1)
					{ 
						TelePlayer(i);
					}
				}
			}
			bHooIsRedTeam=false;
		}
		if(opt.cKiller.TellePlayer==0)
		{
			opt.cKiller.CallTele=0;
		}
		/*----------------------------------------------------------------------------------*/
		if(GetBattleState()){
		if(opt.cWeapon.FastShot == 1)
	    {
		LongPtr1(ResultBaseAmmo2, ResultPTRAmmo, 0x38, 1);
		LongPtr1(ResultBaseAmmo2, ResultPTRAmmo, 0x38, 0);
		LongPtr1(ResultBaseAmmo2, 0x30, 0x5F4, 0);
		WritePtr(ResultBaseAmmo2, 0x504, 0);
	    }}
		/*----------------------------------------------------------------------------------*/
		if(opt.cPlayer.UNYU ==1){
			PrivateOnly((void *)(dwPBExe + ResultBugWeapon),(int*)(PBYTE)"\xC0",1);}
		if(opt.cPlayer.UNYU ==0){
			PrivateOnly((void *)(dwPBExe + ResultBugWeapon),(int*)(PBYTE)"\xBE",1);}
		/*----------------------------------------------------------------------------------*/
		if(opt.cPlayer.PlayerSpeed ==1){
			PrivateOnly((void *)(dwPBExe + ResultPlayerSpeed),(int*)(PBYTE)"\x00\x00\x00\x40\xE1\x7A\x8F\x3F",8);}
		if(opt.cPlayer.PlayerSpeed ==0){
			PrivateOnly((void *)(dwPBExe + ResultPlayerSpeed),(int*)(PBYTE)"\x00\x00\x00\x40\xE1\x7A\x84\x3F",8);}
		/*----------------------------------------------------------------------------------*/
		if(GetBattleState()){
			if(opt.cWeapon.KnifeKill ==1){
				PachtChara(ResultBaseAmmo2,ResultPTRChara,ResultBOMBSIZE,0x41);}}
		/*----------------------------------------------------------------------------------*/
		if(opt.cKiller.WsHt ==1){ 
			PrivateOnly((void *)(dwPBExe + ResultWallShot),(int*)(PBYTE)"\x90\x90",2);}
		if(opt.cKiller.WsHt ==0){ 
			PrivateOnly((void *)(dwPBExe + ResultWallShot),(int*)(PBYTE)"\x75\x1F",2);}
		/*----------------------------------------------------------------------------------*/
		if(opt.cKiller.Invincible ==1){
		if(GetBattleState()){
		DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
		DWORD GM = ModulePB + ResultInvincible;
		MemWrite((void *)(GM),(int*)(PBYTE)"\x6F\x12\x83\x40",4);
		}
		if(opt.cKiller.Invincible ==0){
		DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
		DWORD GM = ModulePB + ResultInvincible;
		MemWrite((void *)(GM),(int*)(PBYTE)"\x6F\x12\x83\x3C",4);
		}}
        //--------------------------------------------------------------------
Sleep(10);
}
		return 0;
}
/*------------------------------------------- Declaration Suicide ------------------------------------------------------*/
typedef void (__thiscall * tCmd_Mati)(DWORD CGameCharaLocalBase, int HPDrain, int a2, int a3);
tCmd_Mati Cmd_Mati;

void KillMySelf()
{
	Cmd_Mati = (tCmd_Mati)(dwPBExe + ResultSuicide);
	DWORD CGameCharaLocalBase = *(DWORD*)(dwPBExe + ResultBaseAmmo);
	Cmd_Mati(CGameCharaLocalBase,0xFF,0xFFFF,false);
}

/*------------------------------------------- Declaration Ghost Zombie ------------------------------------------------------*/
void GhostHacks(){
	unsigned long dwBase	= *(DWORD*)ResultBasePlayer2;
	unsigned long dwBase2	= *(DWORD*)ResultBaseHealth2;	
	CTeam		*GetSlot	= (CTeam*)(dwBase + ResultTeam);
	CHealth		*GetHealth	= (CHealth*)((dwBase2 + ResultHealth) + GetSlot->iTeam * HPSIZE);

	if(bGhost == false)		
		Ghoster	= Read( ResultBaseHealth2, ResultGHOST + GetSlot->iTeam * HPSIZE);
	if(GetHealth->CurHP > 0)bGhost = false;

	if(opt.cKiller.Zombie==0){
		bGhost = false;
		MakePoint( ResultBaseHealth2, ResultGHOST + GetSlot->iTeam * HPSIZE, Ghoster);
	}
	if(opt.cKiller.Zombie==1){
		KillMySelf();
		bGhost = true;
		MakePoint( ResultBaseHealth2, ResultGHOST + GetSlot->iTeam * HPSIZE, Ghoster-1);
	}
}
/*---------------------------------------- Declaration Bypass Protect ----------------------------------------------------*/
void BypassProtect1()
{
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, NeoPTRProtectA, 0x00); // NeoPTRProtectA
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, NeoPTRProtectB, 0x00); // NeoPTRProtectB
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, NeoPTRProtectC, 0x00); // NeoPTRProtectC
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, NeoPTRProtectA-0x10, 0x00); // NeoPTRProtectA
}

void BypassProtect1_A()
{
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, NeoPTRProtectA, 0x00); // NeoPTRProtectA
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, NeoPTRProtectB, 0x00); // NeoPTRProtectB
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, NeoPTRProtectA-0x10, 0x00); // NeoPTRProtectA
}

void BypassProtect2()
{
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, NeoPTRProtectA, 0x00); // NeoPTRProtectA
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, NeoPTRProtectB, 0x00); // NeoPTRProtectB
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, NeoPTRProtectB+0x4, 0x00); // NeoPTRProtectB
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, NeoPTRProtectC, 0x00); // NeoPTRProtectC
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, NeoPTRProtectD, 0x00); // NeoPTRProtectD
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, NeoPTRProtectA-0x10, 0x00); // NeoPTRProtectA
}

void BypassProtect3()
{
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultMALESIZE, NeoPTRProtectA, 0x00); // NeoPTRProtectA
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultMALESIZE, NeoPTRProtectB, 0x00); // NeoPTRProtectB
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultMALESIZE, NeoPTRProtectC, 0x00); // NeoPTRProtectC
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultMALESIZE, NeoPTRProtectA-0x10, 0x00); // NeoPTRProtectA
}

void BypassProtect4()
{
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultBOMBSIZE, NeoPTRProtectA, 0x00); // NeoPTRProtectA
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultBOMBSIZE, NeoPTRProtectB, 0x00); // NeoPTRProtectB
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultBOMBSIZE, NeoPTRProtectC, 0x00); // NeoPTRProtectC
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultBOMBSIZE, NeoPTRProtectD, 0x00); // NeoPTRProtectD
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultBOMBSIZE, NeoPTRProtectA-0x10, 0x00); // NeoPTRProtectA
}

void BypassProtect5()
{
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSMOKESIZE, NeoPTRProtectA, 0x00); // NeoPTRProtectA
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSMOKESIZE, NeoPTRProtectB, 0x00); // NeoPTRProtectB
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSMOKESIZE, NeoPTRProtectC, 0x00); // NeoPTRProtectC
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSMOKESIZE, NeoPTRProtectD, 0x00); // NeoPTRProtectD
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSMOKESIZE, NeoPTRProtectA-0x10, 0x00); // NeoPTRProtectA
}

/*------------------------------------------- Declaration LimitedAllSlotAmmo ------------------------------------------------------*/ 
#define NeoGetAmmo				0xBF4084
bool amoo = false;
#define true 1
#define false 0
void __fastcall LimitedAllSlotAmmo()
{
	DWORD AmmoRollBackUp = (DWORD)GetModuleHandleA("PointBlank.exe");
	DWORD BaseOfs = AmmoRollBackUp + ResultBaseAmmo;
	if(pKey == false)
	{
		GetValue(BaseOfs, ResultPTRAmmo, ResultPRIMARYSIZE, 0xC9C);
		GetValue(BaseOfs, ResultPTRAmmo, ResultPRIMARYSIZE, 0xCA0);
		GetValue(BaseOfs, ResultPTRAmmo, ResultPRIMARYSIZE, 0xCA4);
		GetValue(BaseOfs, ResultPTRAmmo, ResultPRIMARYSIZE, 0xCA8);
		GetValue(BaseOfs, ResultPTRAmmo, ResultBOMBSIZE, 0xC9C);
		GetValue(BaseOfs, ResultPTRAmmo, ResultBOMBSIZE, 0xCA0);
		GetValue(BaseOfs, ResultPTRAmmo, ResultBOMBSIZE, 0xCA4);
		GetValue(BaseOfs, ResultPTRAmmo, ResultBOMBSIZE, 0xCA8);
		GetValue(BaseOfs, ResultPTRAmmo, ResultBOMBSIZE, 0xC9C);
		GetValue(BaseOfs, ResultPTRAmmo, ResultBOMBSIZE, 0xCA0);
		GetValue(BaseOfs, ResultPTRAmmo, ResultBOMBSIZE, 0xCA4);
		GetValue(BaseOfs, ResultPTRAmmo, ResultBOMBSIZE, 0xCA8);
		GetValue(BaseOfs, ResultPTRAmmo, ResultSMOKESIZE, 0xC9C);
		GetValue(BaseOfs, ResultPTRAmmo, ResultSMOKESIZE, 0xCA0);
		GetValue(BaseOfs, ResultPTRAmmo, ResultSMOKESIZE, 0xCA4);
		GetValue(BaseOfs, ResultPTRAmmo, ResultSMOKESIZE, 0xCA8);
	}
	if(opt.cAmmo.ammoroll==true)
	{
		if(*(PBYTE)NeoGetAmmo==false) amoo = true;
	}
	if(amoo == true)
	{
		BypassProtect1_A();
		BypassProtect1();
		PatchValue(BaseOfs, ResultPTRAmmo, ResultPRIMARYSIZE, 0xC9C, pKey);
		PatchValue(BaseOfs, ResultPTRAmmo, ResultPRIMARYSIZE, 0xCA0, pBase);
		PatchValue(BaseOfs, ResultPTRAmmo, ResultPRIMARYSIZE, 0xCA4, pValue);
		PatchValue(BaseOfs, ResultPTRAmmo, ResultPRIMARYSIZE, 0xCA8, pSoul);
		BypassProtect1();
		BypassProtect1_A();
		BypassProtect2();
		PatchValue(BaseOfs, ResultPTRAmmo, ResultBOMBSIZE, 0xC9C, pKey);
		PatchValue(BaseOfs, ResultPTRAmmo, ResultBOMBSIZE, 0xCA0, pBase);
		PatchValue(BaseOfs, ResultPTRAmmo, ResultBOMBSIZE, 0xCA4, pValue);
		PatchValue(BaseOfs, ResultPTRAmmo, ResultBOMBSIZE, 0xCA8, pSoul);
		BypassProtect2();
		BypassProtect4();
		PatchValue(BaseOfs, ResultPTRAmmo, ResultBOMBSIZE, 0xC9C, pKey);
		PatchValue(BaseOfs, ResultPTRAmmo, ResultBOMBSIZE, 0xCA0, pBase);
		PatchValue(BaseOfs, ResultPTRAmmo, ResultBOMBSIZE, 0xCA4, pValue);
		PatchValue(BaseOfs, ResultPTRAmmo, ResultBOMBSIZE, 0xCA8, pSoul);
		BypassProtect4();
		BypassProtect5();
		PatchValue(BaseOfs, ResultPTRAmmo, ResultSMOKESIZE, 0xC9C, pKey);
		PatchValue(BaseOfs, ResultPTRAmmo, ResultSMOKESIZE, 0xCA0, pBase);
		PatchValue(BaseOfs, ResultPTRAmmo, ResultSMOKESIZE, 0xCA4, pValue);
		PatchValue(BaseOfs, ResultPTRAmmo, ResultSMOKESIZE, 0xCA8, pSoul);
		BypassProtect5();
		amoo = false;
	}
	Sleep(10);
}

/*---------------------------------------- Declaration Ammo HK-69 ----------------------------------------------------*/
void AmmoHK69()
{
	if(opt.cAmmo.AmmoHK69A==1)
	{
		if(XHK69==false)
		{
			AmmoHK691  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, 0xC81);
			AmmoHK692  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, 0xC98);
			AmmoHK693  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, 0xC9C);
			AmmoHK694  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, 0xCA0);
			AmmoHK695  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, 0xCA4);
			AmmoHK696  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, 0xCA8); // NeoPTRAmmoB
			XHK69=true;
		}
		else 
			if(XHK69==true)
			{
				BypassProtect2();
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, 0xC81, AmmoHK691);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, 0xC98, AmmoHK692);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, 0xC9C, AmmoHK693);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, 0xCA0, AmmoHK694);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, 0xCA4, AmmoHK695);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSECONDARYSIZE, 0xCA8, AmmoHK696); // NeoPTRAmmoB
				BypassProtect2();
				Sleep(200);
		}
	}
	else
		XHK69=false;
}

/*---------------------------------------- Declaration Ammo Rocket ----------------------------------------------------*/
void AmmoRocket()
{
	if(opt.cAmmo.AmmoRPG==1)
	{
		if(XRPG==false)
		{
			AmmoRPG1  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, 0xC81);
			AmmoRPG2  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, 0xC98);
			AmmoRPG3  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, 0xC9C);
			AmmoRPG4  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, 0xCA0);
			AmmoRPG5  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, 0xCA4);
			AmmoRPG6  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, 0xCA8); // NeoPTRAmmoB
			XRPG=true;
		}
		else 
			if(XRPG==true)
			{
				BypassProtect1_A();
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, 0xC81, AmmoRPG1);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, 0xC98, AmmoRPG2);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, 0xC9C, AmmoRPG3);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, 0xCA0, AmmoRPG4);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, 0xCA4, AmmoRPG5);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, 0xCA8, AmmoRPG6); // NeoPTRAmmoB
				BypassProtect1_A();
				Sleep(100);
			}
	}
	else
		XRPG=false;
}

/*---------------------------------------- Declaration Ammo Launcher ----------------------------------------------------*/
void AmmoLauncher()
{
	if(opt.cAmmo.AmmoLC==1)
	{
		if(XFC == false)
		{
			AmmoPrymariFC = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, NeoPTRAmmoC); // NeoPTRAmmoC
			XFC = true;
		}
		else 
			if(XFC==true)
			{
				BypassProtect1();
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultPRIMARYSIZE, NeoPTRAmmoC, AmmoPrymariFC); // NeoPTRAmmoC
				BypassProtect1();	
				Sleep(25);
			}
	}
	else
		XFC=false;
}

/*---------------------------------------- Declaration Ammo Smoke ----------------------------------------------------*/
void UnlimitedSmoke()
{
	if(opt.cAmmo.AmmoSmoke==1)
	{
		if(XSMOKE==false)
		{
			AmmoSMOKE = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSMOKESIZE, NeoPTRAmmoA); // NeoPTRAmmoA
			XSMOKE=true;
		}
		else 
			if(XSMOKE==true)
			{
				BypassProtect5();
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultSMOKESIZE, NeoPTRAmmoA, AmmoSMOKE); // NeoPTRAmmoA
				BypassProtect5();
				Sleep(100);
			}
	}
	else
		XSMOKE=false;
}

/*---------------------------------------- Declaration Ammo Test ----------------------------------------------------*/
void AmmoGrenade()
{
	if(opt.cAmmo.AmmoBomb==1)
	{
		if(XBOMB==false)
		{
			AmmoBOMB = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, ResultBOMBSIZE, NeoPTRAmmoA); // NeoPTRAmmoA
			XBOMB=true;
		}
		else 
			if(XBOMB==true)
			{
				BypassProtect4();
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, ResultBOMBSIZE, NeoPTRAmmoA, AmmoBOMB); // NeoPTRAmmoA
				BypassProtect4();
				Sleep(100);
			}
	}
	else
		XBOMB=false;
}
/*------------------------------------------- Declaration Weapon Control ------------------------------------------------------*/
typedef void (__thiscall * tSetCharaWeaponSet)(DWORD CGameCharaManager,DWORD CGameCharaBase, DWORD pNetCharaInfo); 
tSetCharaWeaponSet SetCharaWeaponSet; 

DWORD CGameCharaBaseShoot(void) 
{ 
unsigned long dwBase = *(DWORD*)ResultBaseHealth2;//2
return dwBase;
} 
int GetMyCharaIndex2() 
{ 
DWORD dwI3EXEC = (DWORD)GetModuleHandleA("PointBlank.exe"); 
unsigned long dwBase = *(DWORD*)(dwI3EXEC + ResultBasePlayer); 
unsigned long dwBase2 = *(DWORD*)(dwI3EXEC + ResultBaseHealth2); 
CTeam *MyTeam = (CTeam*) ((dwBase + ResultTeam)); 
return MyTeam->iTeam; 
} 
void FakeEvolution() 
{ 
	if (opt.cSpesial.FakeReplace==1)
	{ 
		if (GetBattleState())
		{ 
			DWORD BasePlayer_A = *(DWORD*)(dwPBExe + ResultBasePlayer); 
			DWORD BasePlayer_B = *(DWORD*)(dwPBExe + ResultBaseHealth); 
			int MyIndex = GetMyCharaIndex2(); 
			DWORD CGameCharaManager = CGameCharaBaseShoot(); 
			DWORD CGameCharaBase = *(DWORD*)(BasePlayer_B + 0x14 + (MyIndex*4)); 
			DWORD pNetCharaInfo = BasePlayer_A + ((ResultRespawn2) + (MyIndex*0x158)); 
			SetCharaWeaponSet = (tSetCharaWeaponSet)ResultSetNetChara; 
			SetCharaWeaponSet(CGameCharaManager, CGameCharaBase, pNetCharaInfo); 
		}
	}
}
/*------------------------------------------- Declaration RapidFire ------------------------------------------------------*/
void RapidFireWeapon(){

	if(GetBattleState()){
			if(opt.cWeapon.RapidFire==1)
			{
			__try
			{
				if (*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+ResultPTRAmmo)+0x38)==1){
					*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30)+0x5D4)=0;
					*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
				}
				if (*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+ResultPTRAmmo)+0x38)==0){
					*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30)+0x5D4)=0;
					*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
				}
			} __except ( EXCEPTION_EXECUTE_HANDLER )
			{
				
			}
	}
	}}
/*---------------------------------------- Declaration Protocol System ----------------------------------------------------*/
DWORD WINAPI Protocol_Portal(LPVOID param)
{
while(true)
	{

		if(GetBattleState())
		{
			Func_VKick();
			Func_BombEnywhere();
			Func_FireSpeed();
			Func_HPMinus();
			Func_ReplaceAllMode();
			Func_Replace();
		}
	Sleep(1);
	}
return 0;
}