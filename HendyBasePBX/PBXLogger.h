


#include <winbase.h>
#include "PBXOption .h"
#include "PointBlank dxStruct.h"
#include "PointBlank DxESP.h"
#include "PBXXStr.h"
#include "PBXAOF.h"

//---------------------------------------------------------------------------------------------------
#define true  1
#define false 0
dxESP	*DxESP;
DWORD adrOTB;
//---------------------------------------------------------------------------------------------------


//------------------------------------- LOG FINDDER BY Xstr -------------------------------------------//
DWORD BASEPLAYERXStr = OFS_Player;
DWORD BASEPLAYERXStr2 = BASEPLAYERXStr + OFS_Player2;
DWORD BASEWEAPONXStr = BASEPLAYERXStr - 0x1C;
DWORD BASEWEAPONXStr2 = BASEPLAYERXStr + 0x3FFFE4;
DWORD BASEAMMOXStr = BASEPLAYERXStr - 0x38;
DWORD BASEAMMOXStr2 = BASEPLAYERXStr + 0x3FFFC8;
DWORD BASEHEALTHXStr = BASEPLAYERXStr - 0x34;
DWORD BASEHEALTHXStr2 = BASEPLAYERXStr + 0x3FFFCC;
//----------------------------------------------------------------------//
bool ReadKnife = false;//CLear
void __fastcall DRPisau()
{
DWORD BaseOfs = (DWORD) GetModuleHandleA("PointBlank.exe") + OFS_Player-0x38;
if(*(PBYTE)BaseOfs > 0x01)
{
if(cItem.FastKnife==1)
{
if(ReadKnife == false)
{
GetWeaponHack(BaseOfs, 0x144, 0x24, 0x894, 3);
ReadKnife=true;
}
if(ReadKnife == true)
{
GoWeaponHack(BaseOfs, 0x144, 0x24, 0x894, piso);
}
}
}
}
//======================================= GHOST ===================================================================================
#define AdrBaseHealth OFS_Player -0x34 + 0x400000
void Ghost()//(LPDIRECT3DDEVICE9 pDevice)
{
	DWORD AdrBaseAmoo = OFS_Player-0x38 + (DWORD)GetModuleHandle("PointBlank.exe");
	DWORD pBase = (DWORD)GetModuleHandleA("PointBlank.exe");
	DWORD PtrAdr = *(PDWORD)(pBase + OFS_Player );
	DWORD PtrHP  = *(PDWORD)(pBase + OFS_Player-0x34);
	CTeam* GetSlot	= (CTeam*)(PtrAdr + OFS_TEAM);
	CHealth* GetHealth = (CHealth*)((PtrHP + 0x264) + GetSlot->iTeam * 0x20);
	if(*(PBYTE)(OFS_Health +0x400000)> 0x01){
		if(bGhost == false){
			Ghoster = Read( AdrBaseHealth, 0x260 + GetSlot->iTeam * 0x20);
		}
	}
	if(cItem.BokongKill == 0){
		bGhost = false;
		_patchPTR( AdrBaseHealth, 0x260 + GetSlot->iTeam * 0x20, Ghoster);
    }
	if(*(PBYTE)AdrBaseAmoo > 0x01)
	{
    if(GetHealth->CurHP > 0)
	{
	if(cItem.BokongKill == 1){
		bGhost = true;
		_patchPTR( AdrBaseHealth, 0x260 + GetSlot->iTeam * 0x20, Ghoster-1);
    }
	}
	if(GetHealth->CurHP < 0){
		_patchPTR( AdrBaseHealth, 0x260 + GetSlot->iTeam * 0x20, Ghoster);
	}
  }
	if(GetAsyncKeyState(VK_LMENU)&1)// VK_LMENU ALt kiri
    {
		cItem.BokongKill=!cItem.BokongKill;
		MessageBeep(0);
		Beep(1000,100);
	}
    }


bool ReadAmmo = false; 
void _fastcall AMMOX() { //Clear
DWORD pBase = (DWORD)GetModuleHandleA("PointBlank.exe"); 
DWORD AdrBaseAmoo = pBase + OFS_Player-0x38;// 
if(*(PBYTE)AdrBaseAmoo > 0x01) { 
if(cItem.ammo==1) { 
if(ReadAmmo == false){ 
GetWeaponHack(OFS_Player2-0x38, 0x144, 0x1C, 0x8A0, 1); 
GetWeaponHack(OFS_Player2-0x38, 0x144, HPSIZE, 0x8A0, 2); 
ReadAmmo=true; } 
if(ReadAmmo == true){ 
GoWeaponHack(OFS_Player2-0x38, 0x144, 0x1C, 0x8A0, wepon); 
GoWeaponHack(OFS_Player2-0x38, 0x144, HPSIZE, 0x8A0, pistol); 
}}}}
DWORD WINAPI _AmmoHack (){//1CE8
while(1){
AMMOX();
DRPisau();
Sleep(5);
}
return 0;
}
//=========================================== No Respawn + Holvest (AUTO ON) =======================================================================
DWORD WINAPI Respawn(LPVOID param)
{
		while(1)
{
DWORD dwI3EXEC = (DWORD)GetModuleHandle(XStr( /*PointBlank.exe*/ 0x04, 0x0E, 0x6C, 0x3C020701, 0x04331E12, 0x1A1E5812, 0x001C0000 ).c());
//}
if (dwI3EXEC > 0) { 
OnlyMe((void *)(dwI3EXEC+OFS_AntiPI1),(int*)(PBYTE)"\x00\x00",2); 
OnlyMe((void *)(dwI3EXEC+OFS_AntiPI2),(int*)(PBYTE)"\x00",1); }
}
}
//==================================
int SGBRUST = 0;
int WMJZ = 0;
int BypassWH=true;

//---------------------------------------------------------------------------------------------------------------------------------
DWORD WINAPI ThreadHack(LPVOID param)
{
//---------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------
while(1){	

if(cItem.FallDamage == 1){ 
Function_One(OFS_Player2-0x38, 0x118, 14); 
Function_One(OFS_Player2-0x38, 0x119, 172); 
Function_One(OFS_Player2-0x38, 0x11A, 4); 
Function_One(OFS_Player2-0x38, 0x11B, 64); 
}
//==========================================BRUTAL=====================================================
if(cItem.FSpeed==1){
if(GetAsyncKeyState(0x01)&&0x8000){
if(IsBadReadPtr((void*)OFS_Ammo2,4)==0)
{
DWORD TheRead = *(PDWORD)((DWORD)(OFS_Ammo2))+0x144;
if(IsBadReadPtr((void*)TheRead,4)==0)
{
DWORD ReadKe1 = *(PDWORD)((DWORD)(TheRead))+0x38;
if(IsBadReadPtr((void*)ReadKe1,4)==0)
{
*(PDWORD)ReadKe1=0x02;
Sleep(250);
}}}}}
//--------------------- double jump------------------
if(cItem.JumpHight==1){ 
        if (GetAsyncKeyState (VK_SPACE)&&0x8000) { 
             Function_One(OFS_Ammo2, 0x108, 0xFF); }}
DWORD Module = (DWORD)GetModuleHandleA	("PointBlank.exe");
//-------------------------------------------------------------------------------------------------------------------------------
Sleep(5);
//---------------------------------------------------------------------------------------------------------------------------------
}
return 0;
}
DWORD WINAPI GoGoGo(LPVOID lpParam)
{
while(1){

/*-------------------------------------------------*/
// FREE MOVE | BY Hendy
if (cItem.FreeMove)
{
PatchValue(OFS_Ammo2,0x148,0x11C,0x1E0,0x04);
}
/*-------------------------------------------------*/

// ANTI IDLE | BY Hendy
if(cItem.AntiIdle)
{
Function_Two(OFS_Ammo2 , 0x11C, 0x2BB , 0x41);
Function_Two(OFS_Ammo2 , 0x11C, 0x2BF , 0x42);
}
if(cItem.Quick){
	GoWeaponHack( OFS_Ammo2, 0x140, 0xEC, 0x67, 0x41);
}

/*-------------------------------------------------*/

// AUTO OUT | BY Hendy
if (cItem.OutGBHack)
{
if(*(PBYTE)OFS_Player-0x38 > 0x01)
{
Sleep(11000);
{
Sleep(500);
}
}
}
/*-------------------------------------------------*/
if(cItem.QuickChanger==1)
{
PatchValue(OFS_Player2-0x38, 0x240,  0x240, 0x168, 0x3FC28F5B);
}
//
if(cItem.Damage1)
{
PachtChara(ResultBasePlayer-0x38, 0x158, 0x108,0xFFFFFFFF);
PachtChara(ResultBasePlayer-0x38, 0x158, 0x110,0xFFFFFFFF);
PachtChara(ResultBasePlayer-0x38, 0x158, 0x100,0xFFFFFFFF);
PachtChara(ResultBasePlayer-0x38, 0x158, 0x104,0xFFFFFFFF);
PachtChara(ResultBasePlayer-0x38, 0x158, 0x10C,0xFFFFFFFF);
PachtChara(ResultBasePlayer-0x38, 0x158, 0x114,0xFFFFFFFF);
PachtChara(ResultBasePlayer-0x38, 0x158, 0x118,0xFFFFFFFF);
PachtChara(ResultBasePlayer-0x38, 0x158, 0x11C,0xFFFFFFFF);
PachtChara(ResultBasePlayer-0x38, 0x180, 0x30,0xFFFFFFFF);
PachtChara(ResultBasePlayer-0x38, 0x180, 0x28,0xFFFFFFFF);
PachtChara(ResultBasePlayer-0x38, 0x180, 0x20,0xFFFFFFFF);
PachtChara(ResultBasePlayer-0x38, 0x180, 0x1C,0xFFFFFFFF);
PachtChara(ResultBasePlayer-0x38, 0x180, 0x18,0xFFFFFFFF);
PachtChara(ResultBasePlayer-0x38, 0x180, 0x14,0xFFFFFFFF);
PachtChara(ResultBasePlayer-0x38, 0x180, 0x10,0xFFFFFFFF);
PachtChara(ResultBasePlayer-0x38, 0x180, 0x0C,0xFFFFFFFF);
PachtChara(ResultBasePlayer-0x38, 0x180, 0x08,0xFFFFFFFF);
	}

/*-------------------------------------------------*/
if(cItem.Hollow)
{
DWORD Module = (DWORD)GetModuleHandleA	("PointBlank.exe");
PachtChara(Module + BASEAMMOXStr2,0x280,0x38,0xFF);
PachtChara(Module + BASEAMMOXStr2,0x280,0x30,0xFF);
PachtChara(Module + BASEAMMOXStr2,0x280,0x28,0xFF);
PachtChara(Module + BASEAMMOXStr2,0x280,0x24,0xFF);
PachtChara(Module + BASEAMMOXStr2,0x280,0x20,0xFF);
PachtChara(Module + BASEAMMOXStr2,0x280,0x1C,0xFF);
PachtChara(Module + BASEAMMOXStr2,0x280,0x18,0xFF);
PachtChara(Module + BASEAMMOXStr2,0x280,0x14,0xFF);
PachtChara(Module + BASEAMMOXStr2,0x280,0x10,0xFF);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x118,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x110,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x108,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x102,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x100,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0xA8,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0xA4,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0xA0,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x9C,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x98,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x94,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x90,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x88,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x80,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x7C,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x78,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x74,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x70,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x6C,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x68,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x40,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x3C,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x38,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x34,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x30,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x2C,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x25,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x24,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x20,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x1C,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x18,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x14,0x00000000);
PachtChara(Module + BASEAMMOXStr2,0x2D4,0x10,0x00000000);
}
//======================================== No Recoil =============================================//
//==============================================
//----> Kesebar tanggung sendiri akibatnya ^^ :)
//==============================================
if(cItem.Clip==1){
PachtChara(OFS_Ammo2, 0x158, 0x0C, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x10, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x14, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x48, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x4C, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x50, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x38, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x3C, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x40, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x28, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x2C, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x30, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x34, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x58, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x5C, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x60, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x64, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x68, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x6C, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x78, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x7C, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x80, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0xB8, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0xBC, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0xC0, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x18, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x1C, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x20, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x24, 0x00000000);
PachtChara(OFS_Ammo2, 0x158, 0x108,0xFFFFFFFF);
PachtChara(OFS_Ammo2, 0x158, 0x110,0xFFFFFFFF);
PachtChara(OFS_Ammo2, 0x158, 0x100,0xFFFFFFFF);
PachtChara(OFS_Ammo2, 0x158, 0x104,0xFFFFFFFF);
PachtChara(OFS_Ammo2, 0x158, 0x10C,0xFFFFFFFF);
PachtChara(OFS_Ammo2, 0x158, 0x114,0xFFFFFFFF);
PachtChara(OFS_Ammo2, 0x158, 0x118,0xFFFFFFFF);
PachtChara(OFS_Ammo2, 0x158, 0x11C,0xFFFFFFFF);
PachtChara(OFS_Ammo2, 0x180, 0x30,0xFFFFFFFF);
PachtChara(OFS_Ammo2, 0x180, 0x20,0xFFFFFFFF);
PachtChara(OFS_Ammo2, 0x180, 0x1C,0xFFFFFFFF);
PachtChara(OFS_Ammo2, 0x180, 0x18,0xFFFFFFFF);
PachtChara(OFS_Ammo2, 0x180, 0x14,0xFFFFFFFF);
PachtChara(OFS_Ammo2, 0x180, 0x10,0xFFFFFFFF);
PachtChara(OFS_Ammo2, 0x180, 0x0C,0xFFFFFFFF);
PachtChara(OFS_Ammo2, 0x180, 0x08,0xFFFFFFFF);
}
//=================================================================================================================================//
//										                                                          //
//										~=**Name Fiture:: NO RESPOWN**=~                                                            //
//=================================================================================================================================//
	

//=================================================================================================================================//
//										                                                           //
//										~=**Name Fiture:: AUTO PANGKAT SKILL**=~                                                            //
//=================================================================================================================================//


Sleep(0.5);
	}
	return 0;
}