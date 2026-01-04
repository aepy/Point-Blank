//==================================================================================================================================//
//											AUTHOR	: M. Hendy																		//											  
//											Me      : M. Hendy
//											RELEASE : Kreasi Sendiri ^_^																	//
//											WEB		: Palembang-Community.blogspot.com													//
//																																	//
//										    NO SHARE TO PUBLIC || BASE RESMI Muhammad Hendy											//
//==================================================================================================================================//
#include <fstream>
//============================== Replace AllWeapon ==========================================//
//void ThreadReplace(LPDIRECT3DDEVICE9 pDevice)
DWORD WINAPI ThreadReplace(LPVOID param)
{
int On = 0;
int SenjataOKE = 0;
int RWeapon = 0;
int replace1 = 0;
HendygantengON:
//--------------hotkey on-off replace----------------------//
if (GetAsyncKeyState(VK_HOME)& 1){//On
MessageBeep(MB_ICONINFORMATION);
On = 1;
}
if (GetAsyncKeyState(VK_END)& 1){//Off
On = 0;
MessageBeep(MB_ICONWARNING);
SenjataOKE = 0;
}
//---------------------------------------------------------//
if (On == 0){
Sleep(10);
goto HendygantengON;
}
RWeapon = 0x10;

//======================= Asault ==========================//
if(cItem.assaults)
{
if (cItem.assaults== 1){
int i;
w1:
for (i = 0 ; i <= 15 ; i++){

DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x5F5ECB9);//SG-550 Ext
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w1;
Sleep(1);
goto HendygantengON;
}

if (cItem.assaults== 2){
int i;
w2:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x5F5ECBA);//AK-47 Ext
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w2;
Sleep(1);
goto HendygantengON;
}

if (cItem.assaults== 3){
int i;
w3:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x5F5ECBB);//M4A1 Ext
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w3;
Sleep(1);
goto HendygantengON;
}

if (cItem.assaults== 4){
int i;
w4:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x5F5ECBC);// K-2
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w4;
Sleep(1);
goto HendygantengON;
}
if (cItem.assaults==5){
int i;
w5:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x5F5ECBD);//F2000 Ext
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w5;
Sleep(1);
goto HendygantengON;
}

if (cItem.assaults== 6){
int i;
w6:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x5F5ECC1);//AK-47 G
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w6;
Sleep(1);
goto HendygantengON;
}

if (cItem.assaults== 7){
int i;
w7:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x5F5ECC2);//M4A1 S
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w7;
Sleep(1);
goto HendygantengON;
}


if (cItem.assaults== 8){
int i;
w8:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x5F5ECC3);//K-201 Ext
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w8;
Sleep(1);
goto HendygantengON;
}


if (cItem.assaults== 9){
int i;
w9:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x5F5ECC5);//G36C Ext
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w9;
Sleep(1);
goto HendygantengON;
}


if (cItem.assaults== 10){
int i;
w10:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x5F5ECC6);//SG-550 S.
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w10;
Sleep(1);
goto HendygantengON;
}


if (cItem.assaults== 11){
int i;
w11:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x5F5ECC7);//AK SOPMOD
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w11;
Sleep(1);
goto HendygantengON;
}


if (cItem.assaults== 12){
int i;
w12:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x5F5ECD4);//AUG A3 
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w12;
Sleep(1);
goto HendygantengON;
}


if (cItem.assaults== 13){
int i;
w13:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x5F5ECDC);//AUG A3G
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w13;
Sleep(1);
goto HendygantengON;
}


if (cItem.assaults== 14){
int i;
w14:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x5F5ECDD);//AUG A3 D
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w14;
Sleep(1);
goto HendygantengON;
}
}

//======================= SMG ==========================//
if (cItem.smgs)
{
if (cItem.smgs== 1){
int i;
w15:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0xBEBD1BF);//kriss svd
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w15;
Sleep(1);
goto HendygantengON;
	}

if (cItem.smgs== 2){
int i;
w16:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0xBEBD1AA);//batik
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w16;
Sleep(1);
goto HendygantengON;
	}

if (cItem.smgs== 3){
int i;
w17:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0xBEBD1C0);// P90 MCD
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w17;
Sleep(1);
goto HendygantengON;
	}

if (cItem.smgs== 4){
int i;
w18:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0xBEBD1BD);// P90 D
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w18;
Sleep(1);
goto HendygantengON;
	}

if (cItem.smgs== 5){
int i;
w19:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0xBEC0857);//dua uzi
	}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w19;
Sleep(1);
goto HendygantengON;
}

if (cItem.smgs== 6){
int i;
w20:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0xBEBD1B6);//MP7 Sl
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w20;
Sleep(1);
goto HendygantengON;
	}}

//======================= SG ==========================//
if (cItem.sgs)
{
if (cItem.sgs== 1){
int i;
w21:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x17D79B79);//spass SI
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w21;
Sleep(1);
goto HendygantengON;
}

if (cItem.sgs== 2){
int i;
w22:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x17D79B7C);//SPASS . D
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w22;
Sleep(1);
goto HendygantengON;
}

if (cItem.sgs== 3){
int i;
w23:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x17D79B82);//spass MCS
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w23;
Sleep(1);
goto HendygantengON;
}

if (cItem.sgs== 4){
int i;
w24:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x17D79B75);//SG putar
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w24;
Sleep(1);
goto HendygantengON;
}

if (cItem.sgs== 5){
int i;
w25:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x17D79B85);//SG putar Silver
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w25;
Sleep(1);
goto HendygantengON;
}

if (cItem.sgs== 6){
int i;
w26:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x17D79B83);//jackhammer
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w26;
Sleep(1);
goto HendygantengON;
}
}

//======================= AWP ==========================//
if (cItem.awps){
if (cItem.awps== 1){
int i;
w27:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x11E1B699);//magnum
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w27;
Sleep(1);
goto HendygantengON;
}

if (cItem.awps== 2){
int i;
w28:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x11E1B6A6);// cytac 200m
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w28;
Sleep(1);
goto HendygantengON;
}

if (cItem.awps== 3){
int i;
w29:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x11E1B693);// dragunnov
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w29;
Sleep(1);
goto HendygantengON;
}

if (cItem.awps== 4){
int i;
w30:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x11E1B6A8);// barret
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w30;
Sleep(1);
goto HendygantengON;
}

if (cItem.awps== 5){
int i;
w31:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x11E1B69F);// range master stby
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w31;
Sleep(1);
goto HendygantengON;
}

if (cItem.awps== 6){
int i;
w32:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x11E1B6A2);//L115A1 Black
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w32;
Sleep(1);
goto HendygantengON;
}
}

//======================= SECONDARY ==========================//
if (cItem.Sec){
if (cItem.Sec== 1){
int i;
w33:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x23D29027);//UZZI
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w33;
Sleep(1);
goto HendygantengON;
}

if (cItem.Sec== 2){
int i;
w34:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x23D2901B);//Glock18
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w34;
Sleep(1);
goto HendygantengON;
}

if (cItem.Sec== 3){
int i;
w35:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x23D29020);// R.B 454 SS8M+S
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w35;
Sleep(1);
goto HendygantengON;
	}

if (cItem.Sec== 4){
int i;
w36:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x23D29017);// Piython
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w36;
Sleep(1);
goto HendygantengON;
	}

if (cItem.Sec== 5){
int i;
w37:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x23D2BEF6);// Dual Eagle
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w37;
Sleep(1);
goto HendygantengON;
	}
if (cItem.Sec== 6){
int i;
w38:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x23D2902A);// HK 69
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w38;
Sleep(1);
goto HendygantengON;
	}
}

//======================= MALE ==========================//
if (cItem.male){
if (cItem.male== 1){
int i;
w39:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x29D7AF79);//Fang Blade
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w39;
Sleep(1);
goto HendygantengON;
}

if (cItem.male== 2){
int i;
w40:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x29D7AF6C);//Amok Kukri
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w40;
Sleep(1);
goto HendygantengON;
}

if (cItem.male== 3){
int i;
w41:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x29D7AF74);//Mini Axe
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w41;
Sleep(1);
goto HendygantengON;
	}}
//======================= Barret ==========================//
if (cItem.beret){

if (cItem.beret== 1){
int i;
w42:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x41BE7D79);//Helmet Defense +++
}
RWeapon = RWeapon - 1;
//if (constant > 0) goto 42;
Sleep(1);
goto HendygantengON;
}

if (cItem.beret== 2){
int i;
w43:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x41BE7D7A);//Helmet GM +++
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w43;
Sleep(1);
goto HendygantengON;
}

if (cItem.beret== 3){
int i;
w44:
for (i = 0 ; i <= 15 ; i++){
DWORD Destroyerrr = (DWORD)GetModuleHandle("PointBlank.exe");
MakePoint(Destroyerrr + OFS_Player, 0x27574 + (i*0x158), 0x41BE7D7B);//Helm Track ++
}
RWeapon = RWeapon - 1;
if (RWeapon > 0) goto w44;
Sleep(1);
goto HendygantengON;
	}}
Sleep(50);
goto HendygantengON;
}
/*______________________________________________________*/
// BERET | BY Hendy
//if (cItem.PBXBerretXX)
//{
//if (cItem.PBXBerretXX== 1)
//{
//int i;
//w50:
//for (i = 0 ; i <= 15 ; i++)
//{
//DWORD PBXHendy = (DWORD)GetModuleHandle("PointBlank.exe");
//MakePoint(PBXHendy + OFS_Player, ALLWEAPSIZE + (i*WEAPSIZE), 0x41BE7D79); // Assault Rifle
//}
//PBXWeapon = PBXWeapon - 1;
//if (PBXWeapon > 0) goto w50;
//Sleep(1);
//goto PBXONHack;
//}
///*___________________________*/
//if (cItem.PBXBerretXX== 2)
//{
//int i;
//w51:
//for (i = 0 ; i <= 15 ; i++)
//{
//DWORD PBXHendy = (DWORD)GetModuleHandle("PointBlank.exe");
//MakePoint(PBXHendy + OFS_Player, ALLWEAPSIZE + (i*WEAPSIZE), 0x41BE7D7A); // Sub Manchine Gun
//}
//PBXWeapon = PBXWeapon - 1;
//if (PBXWeapon > 0) goto w51;
//Sleep(1);
//goto PBXONHack;
//}
///*___________________________*/
//if (cItem.PBXBerretXX== 3)
//{
//int i;
//w52:
//for (i = 0 ; i <= 15 ; i++)
//{
//DWORD PBXHendy = (DWORD)GetModuleHandle("PointBlank.exe");
//MakePoint(PBXHendy + OFS_Player, ALLWEAPSIZE + (i*WEAPSIZE), 0x41BE7D7B); // Sniper Rifle
//}
//PBXWeapon = PBXWeapon - 1;
//if (PBXWeapon > 0) goto w52;
//Sleep(1);
//goto PBXONHack;
//}
///*___________________________*/
//if (cItem.PBXBerretXX== 4)
//{
//int i;
//w53:
//for (i = 0 ; i <= 15 ; i++)
//{
//DWORD PBXHendy = (DWORD)GetModuleHandle("PointBlank.exe");
//MakePoint(PBXHendy + OFS_Player, ALLWEAPSIZE + (i*WEAPSIZE), 0x41BE7D7C); // Shotgun
//}
//PBXWeapon = PBXWeapon - 1;
//if (PBXWeapon > 0) goto w53;
//Sleep(1);
//goto PBXONHack;
//}
///*___________________________*/
//if (cItem.PBXBerretXX== 5)
//{
//int i;
//w54:
//for (i = 0 ; i <= 15 ; i++)
//{
//DWORD PBXHendy = (DWORD)GetModuleHandle("PointBlank.exe");
//MakePoint(PBXHendy + OFS_Player, ALLWEAPSIZE + (i*WEAPSIZE), 0x41BE7D7D); // Handgun
//}
//PBXWeapon = PBXWeapon - 1;
//if (PBXWeapon > 0) goto w54;
//Sleep(1);
//goto PBXONHack;
//}
//}