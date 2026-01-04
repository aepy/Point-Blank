//=============AutoShot===========
/*DWORD adr_autoshot_1 =FindPattern((DWORD)GetModuleHandleA("pointblank.exe"),0x630000,(PBYTE)"\x88\x81\x66\x01\x00\x00","xxxxxx");// i3Framework::GetViewer(void) +17A (FF 15 64 5C 8E 00)

DWORD adr_autoshot_2 = adr_autoshot_1 + 0x8;//5D0257
DWORD ret_autoshot = adr_autoshot_1 + 0x26;
DWORD ret_autoshot_2 = adr_autoshot_2 + 0x12;
*/
//========================================================================================
/*void adrautoshot2()
{
DWORD i3Inputnya = (DWORD)GetModuleHandleA ("PointBlank.exe"); 
PrivateOnly((void *)(i3Inputnya + 0x8),(void *)"\x88\x81\x66\x01\x00\x00",6);
}

void retautoshot()
{
DWORD i3Inputnya = (DWORD)GetModuleHandleA ("PointBlank.exe"); 
PrivateOnly((void *)(i3Inputnya + 0x26),(void *)"\x88\x81\x66\x01\x00\x00",6);
}

void retautoshot2()
{
DWORD i3Inputnya = (DWORD)GetModuleHandleA ("PointBlank.exe")+ 0x8; 
PrivateOnly((void *)(i3Inputnya + 0x12),(void *)"\x88\x81\x66\x01\x00\x00",6);
}

//========================================================================================
void Click2()
{
PrivateOnly((void *)((DWORD)GetModuleHandleA("i3inputDx.dll") + 0x22C0),(void *)"\x8B\x41\x01",3);
}
  void UNClick2()
{
PrivateOnly((void *)((DWORD)GetModuleHandleA("i3inputDx.dll") + 0x22C0),(void *)"\x8B\x41\x28",3);
}
void Click()
{
DWORD i3Inputnya = (DWORD)LoadLibrary ("i3inputDx.dll"); 
PrivateOnly((void *)(i3Inputnya + 0x22B0),(void *)"\x8B\x41\x01",3);
}
void UNClick()
{
DWORD i3Inputnya = (DWORD)LoadLibrary ("i3inputDx.dll"); 
PrivateOnly((void *)(i3Inputnya + 0x22B0),(void *)"\x8B\x41\x24",3);
}
//========================================================================================


__declspec(naked)void autoshot_1()
{ 
_asm
{
mov     [ecx+0x16E], al
call    [UNClick]
jmp [retautoshot]
}
}
__declspec(naked)void autoshot_2()	
{ 
_asm
{
mov     ecx, [ebp-0x20]
mov     byte ptr [ecx+0x16C], 255
    
call    [Click]
jmp  [retautoshot2]
}
}
__declspec(naked)void autoshot_1_off()
{ 
_asm
{
mov     [ecx+0x16E], al
jmp [retautoshot]
}
}
__declspec(naked)void autoshot_2_off()
{ 
_asm
{
mov     ecx, [ebp-0x20]
mov     byte ptr [ecx+0x16C], 255
jmp  [retautoshot2]
}
}

void DRJMP1( BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen )
{
    DWORD dwOldProtect, dwBkup, dwRelAddr;
    VirtualProtect(pAddress, dwLen, PAGE_EXECUTE_READWRITE, &dwOldProtect);
    dwRelAddr = (DWORD) (dwJumpTo - (DWORD) pAddress) - 5;
    *pAddress = 0xE9;
    *((DWORD *)(pAddress + 0x1)) = dwRelAddr;
    for(DWORD x = 0x5; x < dwLen; x++) *(pAddress + x) = 0x90;
    VirtualProtect(pAddress, dwLen, dwOldProtect, &dwBkup);
    return;
}


DWORD WINAPI AvtoShot()
{
while(1)
{
if(*(PBYTE)OFS_Player > 0x01){//base player
if(cItem.autoshot==0)
{
DRJMP1((PBYTE)retautoshot,(DWORD)autoshot_1_off,5); 
DRJMP1((PBYTE)retautoshot2,(DWORD)autoshot_2_off,5);
}}//*/
/*
if(cItem.autoshot==1)
{
DRJMP1((PBYTE)retautoshot,(DWORD)autoshot_1,5); 
DRJMP1((PBYTE)retautoshot2,(DWORD)autoshot_2,5);
}
       if (GetAsyncKeyState(VK_CAPITAL)&1){
	   Beep(1000,100);
	   autoshot =!autoshot;
	   }

Sleep(500);
}
return true;
}
*/



_declspec(naked)void MouseHook()
{
	_asm {
	cmp [Shot],0
	je Normal
	mov eax, 1;
	ret
Normal:
	mov eax, [ecx+0x1C]// 5 byte
	ret
}
}
void DRMakeJMP1( BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen )
{
    DWORD dwOldProtect, dwBkup, dwRelAddr;
    VirtualProtect(pAddress, dwLen, PAGE_EXECUTE_READWRITE, &dwOldProtect);
    dwRelAddr = (DWORD) (dwJumpTo - (DWORD) pAddress) - 5;
    *pAddress = 0xE9;
    *((DWORD *)(pAddress + 0x1)) = dwRelAddr;
    for(DWORD x = 0x5; x < dwLen; x++) *(pAddress + x) = 0x90;
    VirtualProtect(pAddress, dwLen, dwOldProtect, &dwBkup);
    return;
}
DWORD GetPlayerTarget(int myIDX)
{
//=== Show HUD Nick, deket is type of ================//
DWORD ModuleHandle = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD BasePlayer_B = *(DWORD*)(ModuleHandle + OFS_Health);//ResultBaseHealth
if(IsBadReadPtr((void*)BasePlayer_B,4))return 0;
DWORD PlayerIndexA = *(DWORD*)(BasePlayer_B + 0x14 + (myIDX * 4));
if(IsBadReadPtr((void*)PlayerIndexA,4))return 0;
DWORD PlayerIndexB = *(DWORD*)(PlayerIndexA + 0x160);//8b????8b88????????89????8b????528b????e8????????83f8??74		or		ffd0e8????????8b????8981????????8b????83ba??????????752a6a0068????????68
if(IsBadReadPtr((void*)PlayerIndexB,4))return 0;
DWORD IsTargetingEnemy = *(DWORD*)(PlayerIndexB + 0x94E8);//8b????c780????????000000008b????f30f1005????????f30f1141??
if(IsBadReadPtr((void*)IsTargetingEnemy,4))return 0;
return IsTargetingEnemy;
}

//=================================================================================================================================
//														VISUAL AUTOSHOOT
//=================================================================================================================================
bool HookedShot = false;
void DoAutoShot() //pasang di endscene
{
if(HookedShot == false){
DRMakeJMP1((PBYTE)GetProcAddress(LoadLibrary("i3inputdx.dll"),"?GetButtonState@i3InputMouse@@QAEIXZ"),(DWORD)MouseHook,5);
HookedShot = true;
}
if(cItem.AutoShot){
if(GetPlayerTarget(GetMyCharaIndex()) > NULL)Shot = true;
else Shot = false;
}
}