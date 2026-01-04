#include <Windows.h>

//=======================================//
//Source Code By : Bagas Nughraha
//Team Hack By   : [S]ystem[G]uardian
//Date Time      : 04-04-2016
//=======================================//
#define AutoHit1 0x98F
#define Hit1 0x911
#define Hit2 0x922
#define Hit3 0x933
//=======================================//
#define SC1 0x00
#define SC2 0x99
#define SC3 0xFF
#define SC4 0xAA
//=======================================//
DWORD dwLSI = (DWORD)GetModuleHandleA("lostsaga.exe");

DWORD Hit = dwLSI + 0x98F;
DWORD Ptr = Hit + 0x5;
DWORD Dev1 = 0x911 + 0x5;
DWORD Dev2 = 0x922 + 0x5;
DWORD Dev3 = 0x933 + 0x5;
DWORD Jamu = Dev1 + Dev2 + Dev3 + 0x98F;
int Loop = 50;
{

void Patch( void *adr, void *ptr, int size)
{
unsigned long CheckProtection;
VirtualProtect((void*)adr,size,PAGE_READWRITE, &CheckProtection);

RtlMoveMemory((void*)adr,(const void*)ptr,size);

VirtualProtect((void*)adr,size,CheckProtection,0);

void WritePtr(int Hit, int Ptr);
}
}
void AsmHook(DWORD Function, DWORD Hook, int Size)
{
__asm
{
add [eax],al
add [eax],al
jmp addy2;
add [mov+0x98F] , eax
mov [eax+0x911] , jmp
jmp [jmp+0x922] , eax
add [edx+0x933] , al
CheckProtection();
}
}
__declspec(naked) void CodeCave2() // Off Keys
{
__asm
{
dec
ebp
inc
ecx
pop
eax
pop
edi
dec
eax
push
eax
pop
edi
jmp addy2
}
DWORD WINAPI AutoHit(LPVOID param)
{
while (1)
}
WriteAddres(DWORD Function, DWORD Function, DWORD Function, DWORD Jamu, int PBYTE ,int&Value);
WritePtr(98F, 00);
WritePtr(98F, 99);
WritePtr(98F, FF);
WritePtr(98F, AA);
{


if (GetAsyncKeyState(VK_F1)& 0x1) AutoHit2 = !AutoHit2;
   if (AutoHit2)

WriteAddress(SC1, SC2, SC2, SC3, Dev1, "\xA1\xA1" ,2);
WriteAddress(SC1, SC2, SC2, SC3, Dev2, "\xA1\xA1" ,2);
WriteAddress(SC1, SC2, SC2, SC3, Dev3, "\xA1\xA1" ,2);
}
Sleep(300);
}//return
return(0);
}