#include <windows.h>
#include <stdio.h>

#define ITEM_HERO 0xBCFF
#define ITEM_GEAR 0xA1C
#define ITEM_STYLE 0xDFD99
#define ITEM_SPECIAL 0x97DA
// Past
#define I_TEM1 0xFA1
#define I_TEM2 0xDC9
#define I_TEM3 0xAB199
#define I_TEM4 0x9888FF
// Define
#define SC1 0x00
#define SC2 0x99
#define SC3 0xFF
#define SC4 0xAA
// Dev
#define IndexPowerShop 0x9F
#define ShopBypass 0x78F
#define ItemPtr 0x000000FFF

DWORD dwLSI = (DWORD)GetModuleHandleA("lostsaga.exe");
{
DWORD IndexShop = dwLSI + 0x9F;
DWORD IndexBypass = dwLSI + 0x78F;
DWORD ItemHero = IndexShop + 0xBCFF;
DWORD ItemGear = ItemGear + 0xA1C;
DWORD ItemStyle = ItemGear + 0xDFD99;
DWORD ItemSpecial = ItemStyle + 0x97DA;
// Past
DWORD BypassItemHero = IndexBypass + 0xFA1;
DWORD BypassItemGear = BypassItemHero + 0xDC9;
DWORD BypassItemStyle = BypassItemGear + 0xAB199;
DWORD BypassItemSpecial = BypassItemStyle + 0x9888FF;
// Define
DWORD SC1 = dwLSI + 0x00;
DWORD SC2 = SC1 + 0x99;
DWORD SC3 = SC2 + 0xFF;
DWORD SC4 = SC3 + 0xAA;
//Setting
DWORD ItemBypass = dwLSI + 000000FFF;
DWORD JumpItemBypass = ItemBypass + 0x45;
}

void Patch(void *adr, void *ptr, int size)
{
	DWORD OldProtection;
	VirtualProtect(adr, size, PAGE_EXECUTE_READWRITE, &OldProtection);
	memcpy(adr, ptr, size);
	VirtualProtect(adr, size, OldProtection, &OldProtection);
}

void CrazyX4Byte(int adr, int x)
{
	unsigned long size;
	VirtualProtect((void*)adr, sizeof(x), PAGE_READWRITE, &size);
	//WriteProcessMemory ( GetCurrentProcess(), (PVOID)adr, (PVOID)x, size, 0 );
	memcpy((void*)adr, &x, sizeof(x));
	VirtualProtect((void*)adr, sizeof(x), size, 0);
}
//
{
VOID PageMemory();


DWORD HackShop;

ShopId(0xBCFF, 0x45, EXTENDEDKEY| 1, 1 )
ShopId(0xA1C, 0x45, EXTENDEDKEY| 1, 1 )
ShopId(0xDFD99, 0x45, EXTENDEDKEY| 1, 1 )
ShopId(0x97DA, 0x45, EXTENDEDKEY| 1, 1 )
}

if(Shop)
{
InitialShop(ShopId, HackShop, 0x5, EVENTKEY_EXTENDED| 1, 1 )
DeclarationHackShop();
}

DWORD WriteShop(DWORD Function1, DWORD Function2, DWORD Function3, DWORD Function4, DWORD Function5, DWORD Function6, DWORD Function7, DWORD Function8, PBYTE, int size)
{
InitialShop(SC1, SC2, SC3, SC4, I_TEM1);
InitialShop(SC1, SC2, SC3, SC4, I_TEM2);
InitialShop(SC1, SC2, SC3, SC4, I_TEM3);
InitialShop(SC1, SC2, SC3, SC4, I_TEM4);
}
JobShop(IndexPowerShop, ShopBypass, ItemPtr);
{
IndexPowerShop(EXTENDEDKEY| 1, 1 );
ShopBypass(EXTENDEDKEY| 1, 1);
ItemPtr(EXTENDEDKEY| 1, 1 );
}
DWORD WriteHack( DWORD Function1, DWORD Function2, DWORD Function3, DWORD Function4, DWORD Function5, int size)
{

DWORD HackShop;

ShopPower(0x9F, 0x45, EXTENDEDKEY| 1, 1 )
ShopPower(0x78F, 0x45, EXTENDEDKEY| 1, 1 )
ShopPower(0x000000FFF , 0x45, EXTENDEDKEY| 1, 1 )
{

if(Shop)
{
InitialShop(ShopId, HackShop, 0x5, EVENTKEY_EXTENDED| 1, 1 )
DeclarationHackShop();
}

DWORD WINAPI_HackShop(LPVOID param) // ganti
{
while (1)
{
Protection();
Protection();
Protection();
Protection();
Protection();
Protection();
Protection();
Protection();
}
bool HackShop = false;
VOID CallShop();
{
CallShop(VALIDSHOP| 1, 1)
}
while(1);
{
Sleep(10);
if (GetAsyncKeyState(VK_F1)&1) {;
{
AutoHit = !AutoHit;
{
if(AutoHit)
{

WriteShop(SC1, SC2, SC3, SC4, ItemHero, "\x1",1);
WriteShop(SC1, SC2, SC3, SC4, ItemGear, "\x1",1);
WriteShop(SC1, SC2, SC3, SC4, ItemStyle, "\x1",1);
WriteShop(SC1, SC2, SC3, SC4, ItemSpecial, "\x1",1);

WriteShop(SC1, SC2, SC3, SC4, IndexShop, "\xEB\xEB",2);
WriteShop(SC1, SC2, SC3, SC4, IndexBypass, "\xE9",1);

WriteShop(SC1, SC2, SC3, SC4, BypassItemHero, "\x99\x99\x99\x0F",4);
WriteShop(SC1, SC2, SC3, SC4, BypassItemGear, "\x99",1);
WriteShop(SC1, SC2, SC3, SC4, BypassItemStyle, "\x3F",1);
WriteShop(SC1, SC2, SC3, SC4, BypassItemStyle, "\xFF",1);
}
void CallShop1();
{
WriteHack(SC1, SC2, SC3, SC4, ItemHero,97FCFFS);
WriteHack(SC1, SC2, SC3, SC4, ItemGear,8486DD);
WriteHack(SC1, SC2, SC3, SC4, ItemStyle,F1A966);
WriteHack(SC1, SC2, SC3, SC4, ItemSpecial,C3426FF);
WriteHack(SC1, SC2, SC3, SC4, IndexBypass,836255627);
WriteHack(SC1, SC2, SC3, SC4, IndexPowerShop,92057773);
{
Sleep(9999);
{
return(0);
}
#define OFS_HackShop1 0x18B4098
#define OFS_HackShop2 0x18B27CC
#define OFS_HackShop3 0x18B738C