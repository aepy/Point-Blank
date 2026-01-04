//--------------------------------------------------------------------
//--------------------------------------------------------------------
float DeltaX = 0;
float DeltaY = 0;
//--------------------------------------------------------------------
int AimCrotMode = NULL;
//--------------------------------------------------------------------
bool AimOff = false;
bool BHookedTele = false;
bool SHookedShot = false;
bool LHookedTele = false;

//--------------------------------------------------------------------
__declspec(naked)void MyDeltaX(){
_asm{
cmp AimCrotMode,1
je StartAim
NORMAL:
fld dword ptr [ecx+0x14]//GetDeltaX
ret
StartAim:
cmp AimOff,1
je NORMAL
fld dword ptr[DeltaX]
ret
}
}
//--------------------------------------------------------------------
__declspec(naked)void MyDeltaY(){
_asm{
cmp AimCrotMode,1
je StartAim
NORMAL:
fld dword ptr [ecx+0x18]//GetDeltaY
ret
StartAim:
cmp AimOff,1
je NORMAL
fld dword ptr[DeltaY]
ret
}
}

DWORD MakePeler(BYTE *MemoryTarget, DWORD FunctionTarget)
{
Sleep(5);
*((DWORD *)(MemoryTarget)) = FunctionTarget;
Sleep(5);
return 0;
}