bool AimOff,AimOff2= false;
bool AimStart = false;
float DeltaX = 0;
float DeltaY = 0;

DWORD CallerOnInput1, CallerOnInput2, CallerOnInput3, CallerOnInput4, CallerOnInput5, CallerOnInput6, CallerOnInput7, CallerOnInput8, CallerOnInput9, CallerOnInput10, CallerOnInput11, CallerOnInput12 = 0;
bool AimEnable = false;
__declspec(naked)void MyDeltaX(){
_asm{
cmp AimCrotMode,1
je StartAim
NORMAL:
fld dword ptr [ecx+0x20]
ret
StartAim:
cmp AimOff,1
je NORMAL
fld dword ptr[DeltaX]
ret
}
}

__declspec(naked)void MyDeltaY(){
_asm{
cmp AimCrotMode,1
je StartAim
NORMAL:
fld dword ptr [ecx+0x28]
ret
StartAim:
cmp AimOff,1
je NORMAL
fld dword ptr[DeltaY]
ret
}}


bool ReadyHook = false;
BYTE FakeFrameworkInput[0x5000];
BYTE MyOnInput[0xE65]; //Size Function OnInput di PointBlank.exe + 0x5B550
DWORD pFUNC = (DWORD)MyOnInput;

void CallPeler (PDWORD target, PDWORD newfunc, int dwLen)
{
DWORD dwOldProtect, dwBkup;
VirtualProtect(target, dwLen, PAGE_EXECUTE_READWRITE, &dwOldProtect);
DWORD Callto=(DWORD)(newfunc)-(DWORD)target-5;
*(PBYTE)((DWORD)(target))=0xE8;
*(PDWORD)((DWORD)(target)+1)=Callto;
for(int i = 5; i<dwLen; i++)*(PBYTE)((DWORD)(target)+i)=0x90;
VirtualProtect(target, dwLen, dwOldProtect, &dwBkup);
}

DWORD MakePeler(BYTE *MemoryTarget, DWORD FunctionTarget)
{
Sleep(5);
*((DWORD *)(MemoryTarget)) = FunctionTarget;
Sleep(5);
return 0;
}

DWORD WINAPI FuckOnInput()
{
while(1)
{
DWORD BaseCelup = *(DWORD*)(c_pPlayerBase-0x40);
if(BaseCelup > NULL){
DWORD BaseCallCelup = *(DWORD*)(BaseCelup + 0x38);//70 FA ?? 10 ?? ?? ?? ?? 01 00 00 00 ?? 18 00 00
if(BaseCallCelup > NULL){
DWORD BeforeCelup = *(DWORD*)(BaseCallCelup);
if(ReadyHook == false)
{
if(BeforeCelup > NULL){
DWORD OffsetCGameFrameworkOnInput = *(DWORD*)(BeforeCelup + 0x34);
for(int i = 0; i<=0xE65; i++)
{
if(i == 0x221)
{
DWORD CallDifference = *(DWORD*)(OffsetCGameFrameworkOnInput + i + 1);
CallerOnInput1 = CallDifference + OffsetCGameFrameworkOnInput + i + 5;
}
if(i == 0x27E)
{
DWORD CallDifference = *(DWORD*)(OffsetCGameFrameworkOnInput + i + 1);
CallerOnInput2 = CallDifference + OffsetCGameFrameworkOnInput + i + 5;
}
if(i == 0x28E)
{
DWORD CallDifference = *(DWORD*)(OffsetCGameFrameworkOnInput + i + 1);
CallerOnInput3 = CallDifference + OffsetCGameFrameworkOnInput + i + 5;
}
if(i == 0x2E4)
{
DWORD CallDifference = *(DWORD*)(OffsetCGameFrameworkOnInput + i + 1);
CallerOnInput4 = CallDifference + OffsetCGameFrameworkOnInput + i + 5;
}
if(i == 0x46D)
{
DWORD CallDifference = *(DWORD*)(OffsetCGameFrameworkOnInput + i + 1);
CallerOnInput5 = CallDifference + OffsetCGameFrameworkOnInput + i + 5;
}
if(i == 0x493)
{
DWORD CallDifference = *(DWORD*)(OffsetCGameFrameworkOnInput + i + 1);
CallerOnInput6 = CallDifference + OffsetCGameFrameworkOnInput + i + 5;
}
if(i == 0x526)
{
DWORD CallDifference = *(DWORD*)(OffsetCGameFrameworkOnInput + i + 1);
CallerOnInput7 = CallDifference + OffsetCGameFrameworkOnInput + i + 5;
}
if(i == 0x5FB)
{
DWORD CallDifference = *(DWORD*)(OffsetCGameFrameworkOnInput + i + 1);
CallerOnInput8 = CallDifference + OffsetCGameFrameworkOnInput + i + 5;
}
if(i == 0x6EE)
{
DWORD CallDifference = *(DWORD*)(OffsetCGameFrameworkOnInput + i + 1);
CallerOnInput9 = CallDifference + OffsetCGameFrameworkOnInput + i + 5;
}
if(i == 0xD90)
{
DWORD CallDifference = *(DWORD*)(OffsetCGameFrameworkOnInput + i + 1);
CallerOnInput10 = CallDifference + OffsetCGameFrameworkOnInput + i + 5;
}
if(i == 0xE45)
{
DWORD CallDifference = *(DWORD*)(OffsetCGameFrameworkOnInput + i + 1);
CallerOnInput11 = CallDifference + OffsetCGameFrameworkOnInput + i + 5;
}

*(BYTE*)( MyOnInput + i ) = *(BYTE*)(OffsetCGameFrameworkOnInput + i );
DWORD OldProtect; 
VirtualProtect ( (LPVOID)(BeforeCelup + i ), sizeof (BeforeCelup + i ), PAGE_EXECUTE_READWRITE, &OldProtect ); 
*(BYTE*)( FakeFrameworkInput + i ) = *(BYTE*)(BeforeCelup + i );
VirtualProtect ( (LPVOID)(BeforeCelup + i ), sizeof (BeforeCelup + i ), OldProtect, &OldProtect ); 
}
CallPeler((PDWORD)(MyOnInput + 0x221),(PDWORD)CallerOnInput1	,5);//
CallPeler((PDWORD)(MyOnInput + 0x2A7),(PDWORD)CallerOnInput1	,5);
CallPeler((PDWORD)(MyOnInput + 0x27E),(PDWORD)CallerOnInput2	,5);//
CallPeler((PDWORD)(MyOnInput + 0x28E),(PDWORD)CallerOnInput3	,5);//
CallPeler((PDWORD)(MyOnInput + 0x2E4),(PDWORD)CallerOnInput4	,5);//
CallPeler((PDWORD)(MyOnInput + 0x46D),(PDWORD)CallerOnInput5	,5);//
CallPeler((PDWORD)(MyOnInput + 0x493),(PDWORD)CallerOnInput6	,5);//
CallPeler((PDWORD)(MyOnInput + 0x4A7),(PDWORD)CallerOnInput6	,5);
CallPeler((PDWORD)(MyOnInput + 0x4BB),(PDWORD)CallerOnInput6	,5);
CallPeler((PDWORD)(MyOnInput + 0x4CC),(PDWORD)CallerOnInput6	,5);
CallPeler((PDWORD)(MyOnInput + 0x4E0),(PDWORD)CallerOnInput6	,5);
CallPeler((PDWORD)(MyOnInput + 0x623),(PDWORD)CallerOnInput6	,5);
CallPeler((PDWORD)(MyOnInput + 0x7F6),(PDWORD)CallerOnInput6	,5);
CallPeler((PDWORD)(MyOnInput + 0x823),(PDWORD)CallerOnInput6	,5);
CallPeler((PDWORD)(MyOnInput + 0x526),(PDWORD)CallerOnInput7	,5);//
CallPeler((PDWORD)(MyOnInput + 0x5D5),(PDWORD)CallerOnInput7	,5);
CallPeler((PDWORD)(MyOnInput + 0x67E),(PDWORD)CallerOnInput7	,5);
CallPeler((PDWORD)(MyOnInput + 0x5FB),(PDWORD)CallerOnInput8	,5);//
CallPeler((PDWORD)(MyOnInput + 0x60F),(PDWORD)CallerOnInput8	,5);
CallPeler((PDWORD)(MyOnInput + 0x634),(PDWORD)CallerOnInput8	,5);
CallPeler((PDWORD)(MyOnInput + 0x7D8),(PDWORD)CallerOnInput8	,5);
CallPeler((PDWORD)(MyOnInput + 0x844),(PDWORD)CallerOnInput8	,5);
CallPeler((PDWORD)(MyOnInput + 0x865),(PDWORD)CallerOnInput8	,5);
CallPeler((PDWORD)(MyOnInput + 0x886),(PDWORD)CallerOnInput8	,5);
CallPeler((PDWORD)(MyOnInput + 0x8A7),(PDWORD)CallerOnInput8	,5);
CallPeler((PDWORD)(MyOnInput + 0x6EE),(PDWORD)CallerOnInput9	,5);//
CallPeler((PDWORD)(MyOnInput + 0x720),(PDWORD)CallerOnInput9	,5);
CallPeler((PDWORD)(MyOnInput + 0x781),(PDWORD)CallerOnInput9	,5);
CallPeler((PDWORD)(MyOnInput + 0x7B5),(PDWORD)CallerOnInput9	,5);
CallPeler((PDWORD)(MyOnInput + 0xD90),(PDWORD)CallerOnInput10	,5);//
CallPeler((PDWORD)(MyOnInput + 0xE45),(PDWORD)CallerOnInput11	,5);//
CallPeler((PDWORD)(pFUNC + 0xA32),(PDWORD)MyDeltaX	,6);
CallPeler((PDWORD)(pFUNC + 0xA3E),(PDWORD)MyDeltaY	,6);
}
}
DWORD OldProtect;
VirtualProtect ( (LPVOID)(FakeFrameworkInput), sizeof (FakeFrameworkInput), PAGE_EXECUTE_READWRITE, &OldProtect ); 
VirtualProtect ( (LPVOID)(MyOnInput), sizeof (MyOnInput), PAGE_EXECUTE_READWRITE, &OldProtect ); 
VirtualProtect ( (LPVOID)(BaseCallCelup), sizeof (BaseCallCelup), PAGE_EXECUTE_READWRITE, &OldProtect ); 
MakePeler((PBYTE)(FakeFrameworkInput + 0x34),(DWORD)MyOnInput);
MakePeler((PBYTE)(BaseCallCelup),(DWORD)(FakeFrameworkInput));
VirtualProtect ( (LPVOID)(FakeFrameworkInput), sizeof (FakeFrameworkInput), OldProtect, &OldProtect ); 
VirtualProtect ( (LPVOID)(MyOnInput), sizeof (MyOnInput), OldProtect, &OldProtect ); 
VirtualProtect ( (LPVOID)(BaseCallCelup), sizeof (BaseCallCelup), OldProtect, &OldProtect ); 
TerminateThread(GetCurrentThread(),0);
}
}
Sleep(10);
}
return 0;
}