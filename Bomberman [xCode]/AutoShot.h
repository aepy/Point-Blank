//====================== AndyXCode Team =====================//
LPTSTR PointBlankSTR = "PointBlank.exe";
bool DinanShot = false;
bool WhileShot = false;
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
_declspec(naked)void UpdateNickOnTarget_Hook()
{
	_asm
	{
		cmp AutoFire,1
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
if(GetPlayerTarget(GetMyCharaIndex()) > NULL)DinanShot = true;
else DinanShot = false;
}
}}
//====================== Admin Alosius Andy haryanto =====================//