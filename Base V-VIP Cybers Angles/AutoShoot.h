//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
#include "PointBlank DxStruct.h"
LPTSTR PointBlankSTR = "PointBlank.exe";
bool Shot = false;
//====================== ASM INPUT MOUSE HOOK =====================//
_declspec(naked)void MouseHook()
{
	_asm {
	cmp [Shot],0
	je Normal
	mov eax, 1;
	ret
Normal:
	mov eax, [ecx+0x14]
	ret
}
}

//=========================================================================//
#define OFS_GetButtonState	0x60096C // i3InputMouse::GetButtonState
bool HookedShot = false;
//=========================================================================//
void DoAutoShot()
{
if(HookedShot == false){
DWORD OFS_Shoots = (DWORD)GetModuleHandleA(PointBlankSTR) + OFS_GetButtonState;
MakePTR((PBYTE)OFS_Shoots,(DWORD)MouseHook);
HookedShot = true;
}
if(GetBattleState1()){
if(AutoShot){
if(GetPlayerTarget(GetMyCharaIndex()) > NULL)Shot = true;
else Shot = false;
}
}}
