#include <Windows.h>


bool isFreeze = false;
bool Darah = false;
bool isFreeze2 = false;
bool zerohp = false;
bool Kebal = false;
bool MultiLeader = false;
bool Speed = false;
bool Token = false;
bool Botkill = false;
bool Gravitasi = false;
bool Magnet_Csd = false;
bool RefillHP = false;
bool RefillT = false;
bool B_TT = false;
bool TeleportDG = false;
bool New = false;
bool Quake = false;
bool NetCut = false;
bool RefillD = false;
bool No_Afk = false;
bool Freeze_dg = false;
bool Brust_Mafia = false;
bool Ghost = false;
bool Brust_ = false;
bool Moving = false;
bool Pasif_Hero = false;
bool Jumping = false;
bool Fast_Hit = false;
bool AutoHit2 = false;

//=========================================================//
// Author 	: Bagas Nughraha			   //
// Team   	: [S]ystem[G]uardian Copyright 2016	   //
// FB		: BagasNughrahaa / BagasNughraha@gmail.com //
//=========================================================//

//=========================================================================//
#define	BOUNCE_KILLER			    			0x1F9AA5C
#define	BASE_AFK			        		0x1FBBE6C 
#define	OFS_AFK1					    	0xA 
#define	OFS_AFK2					    	0x3A 
#define	OFS_AFK3					    	0x6A 
#define	OFS_AFK4					    	0x9A 
#define	OFS_AFK5					    	0xCA 
#define	OFS_AFK6					   	0xFA 
//=========================================================================//
#define OptionSide						0x1E375DC
#define	XP_PTR							0x1F5AC8
#define	WI7_PTR							0x1F5260
#define	WIN7_PTR						0x255260 
#define	WIN8_PTR						0x255AF8
#define	WIN8_PTR1                       			0x2B5AF8
//=========================================================================//
#define LOKASI1							0x1D0
#define LOKASI2							0x008
#define KANAN_KIRI						0x03C
#define ATAS_BAWAH						0x044
//=========================================================================//
#define CEK_SD							0x124
#define CEK_ASD							0x140
#define CEK_AD  						0x15C
#define CEK_AS							0x178
//=========================================================================//
#define BASE1							0x338
#define BASE2							0x5C
//=========================================================================//
#define BASE_STRING						0x1FB0B98
#define OFS_STRING_1						0x04C       
#define OFS_STRING_2						0x07E8         
#define OFS_STRING_3						0x08     
//=========================================================================//
#define NO_DELAY						-0x0x67AC   
#define PENALTY							-0x0509C 
//=========================================================================//
#define RM_1 							0x20061E8
#define RM_2 							0x110
#define RM_3 							0x4E4
#define RM_4							0x14
//=========================================================================//
#define XP1    0x1FBBE9C
#define XP2    0x128
#define OFS_1  0x0
#define OFS_2  0x4
#define OFS_3  0x8
#define OFS_4  0xC
#define OFS_5  0x10
#define OFS_6  0x14
#define OFS_7  0x18
#define OFS_8  0x1C
#define OFS_9  0x20
#define OFS_10 0x24
#define OFS_11 0x28
#define OFS_12 0x2C
#define OFS_13 0x30
#define OFS_14 0x34
#define OFS_15 0x38
#define OFS_16 0x3C
#define OFS_17 0x40
#define OFS_18 0x44
#define OFS_19 0x48
#define OFS_20 0x4C
#define OFS_21 0x50
#define OFS_22 0x54
#define OFS_23 0x58
#define OFS_24 0x5C
#define OFS_25 0x60
#define OFS_26 0x64
#define OFS_27 0x68
#define OFS_28 0x6C
#define OFS_29 0x70
#define OFS_30 0x74
#define OFS_31 0x78
#define OFS_32 0x7C
#define OFS_33 0x80
#define OFS_34 0x84
#define OFS_35 0x88
#define OFS_36 0x8C
#define OFS_37 0x90
#define OFS_38 0x94
#define OFS_39 0x98
#define OFS_40 0x9C
#define OFS_41 0xA0
#define OFS_42 0xA4
#define OFS_43 0xA8
#define OFS_44 0xAC
#define OFS_45 0xB0
#define OFS_46 0xB4
#define OFS_47 0xB8
#define OFS_48 0xBC
#define OFS_49 0xC0
#define OFS_50 0xC4
#define OFS_51 0xC8
#define OFS_52 0xCC
#define OFS_53 0xD0
#define OFS_54 0xD4
#define OFS_55 0xD8
#define OFS_56 0xDC
#define OFS_57 0xE0
#define OFS_58 0xE4
#define OFS_59 0xE8
#define OFS_60 0xEC
#define OFS_61 0xF0
#define OFS_62 0xF4
#define OFS_63 0xF8
#define OFS_64 0xFC
#define OFS_65 0x100
#define OFS_66 0x104
#define OFS_67 0x108
#define OFS_68 0x10C
//===============================================//
#define XP3    0x2C
#define XP4    0x05C
//===============================================
#define HERO   0x1FBC3EC
#define HERO1  0xC4
//===============================================
#define Nama   0x01C
#define Nama1  0x0
//===============================================
#define BASE_REPLACE  	  0x1FBBE9C
#define OFS_REPLACE_1 	  0x2E0
#define OFS_REPLACE_2 	  0x0C4
//======================================================================//
#define OFS_HERO_1	  0x34C
#define OFS_WEAPON_1      0x304
#define OFS_ARMOR_1       0x318
#define OFS_HELM_1        0x32C
#define OFS_CLOAK_1       0x340
#define OFS_BEYOND_1      0x2BC
#define OFS_BEYONDTIME_1  0x2C0
#define OFS_STAT_WEAPON_1 0x308
#define OFS_STAT_ARMOR_1  0x31C
#define OFS_STAT_HELM_1   0x330
#define OFS_STAT_CLOAK_1  0x344
#define OFS_GENDER_1      0x80
//======================================================================//
// FIX CODE SLOT HERO 2-6 = -4 CONTOH : 354 - 4 = 300 ^^
//======================================================================//
#define OFS_WEAPON_2      0x304 + 0x354
#define OFS_ARMOR_2       0x318 + 0x354
#define OFS_HELM_2        0x32C + 0x354
#define OFS_CLOAK_2       0x340 + 0x354
#define OFS_BEYOND_2      0x2BC + 0x354
#define OFS_BEYONDTIME_2  0x2C0 + 0x354
#define OFS_STAT_WEAPON_2 0x30C + 0x354
#define OFS_STAT_ARMOR_2  0x320 + 0x354
#define OFS_STAT_HELM_2   0x334 + 0x354
#define OFS_STAT_CLOAK_2  0x348 + 0x354
#define OFS_GENDER_2      0x80  + 0x354
//======================================================================//
#define OFS_WEAPON_3      0x304 + 0x354 + 0x354
#define OFS_ARMOR_3       0x318 + 0x354 + 0x354
#define OFS_HELM_3        0x32C + 0x354 + 0x354
#define OFS_CLOAK_3       0x340 + 0x354 + 0x354
#define OFS_BEYOND_3      0x2BC + 0x354 + 0x354
#define OFS_BEYONDTIME_3  0x2C0 + 0x354 + 0x354
#define OFS_STAT_WEAPON_3 0x30C + 0x354 + 0x354
#define OFS_STAT_ARMOR_3  0x320 + 0x354 + 0x354
#define OFS_STAT_HELM_3   0x334 + 0x354 + 0x354
#define OFS_STAT_CLOAK_3  0x348 + 0x354 + 0x354
#define OFS_GENDER_3      0x80  + 0x354 + 0x354
//======================================================================//
#define OFS_WEAPON_4      0x304 + 0x354 + 0x354 + 0x354
#define OFS_ARMOR_4       0x318 + 0x354 + 0x354 + 0x354
#define OFS_HELM_4        0x32C + 0x354 + 0x354 + 0x354
#define OFS_CLOAK_4       0x340 + 0x354 + 0x354 + 0x354
#define OFS_BEYOND_4      0x2BC + 0x354 + 0x354 + 0x354
#define OFS_BEYONDTIME_4  0x2C0 + 0x354 + 0x354 + 0x354
#define OFS_STAT_WEAPON_4 0x30C + 0x354 + 0x354 + 0x354
#define OFS_STAT_ARMOR_4  0x320 + 0x354 + 0x354 + 0x354
#define OFS_STAT_HELM_4   0x334 + 0x354 + 0x354 + 0x354
#define OFS_STAT_CLOAK_4  0x348 + 0x354 + 0x354 + 0x354
#define OFS_GENDER_4      0x80  + 0x354 + 0x354 + 0x354
//======================================================================//
#define OFS_WEAPON_5      0x304 + 0x354 + 0x354 + 0x354 + 0x354
#define OFS_ARMOR_5       0x318 + 0x354 + 0x354 + 0x354 + 0x354
#define OFS_HELM_5        0x32C + 0x354 + 0x354 + 0x354 + 0x354
#define OFS_CLOAK_5       0x340 + 0x354 + 0x354 + 0x354 + 0x354
#define OFS_BEYOND_5      0x2BC + 0x354 + 0x354 + 0x354 + 0x354
#define OFS_BEYONDTIME_5  0x2C0 + 0x354 + 0x354 + 0x354 + 0x354
#define OFS_STAT_WEAPON_5 0x30C + 0x354 + 0x354 + 0x354 + 0x354
#define OFS_STAT_ARMOR_5  0x320 + 0x354 + 0x354 + 0x354 + 0x354
#define OFS_STAT_HELM_5   0x334 + 0x354 + 0x354 + 0x354 + 0x354
#define OFS_STAT_CLOAK_5  0x348 + 0x354 + 0x354 + 0x354 + 0x354
#define OFS_GENDER_5      0x80  + 0x354 + 0x354 + 0x354 + 0x354
//======================================================================//
#define OFS_WEAPON_6      0x304 + 0x354 + 0x354 + 0x354 + 0x354  + 0x354 
#define OFS_ARMOR_6       0x318 + 0x354 + 0x354 + 0x354 + 0x354  + 0x354 
#define OFS_HELM_6        0x32C + 0x354 + 0x354 + 0x354 + 0x354  + 0x354 
#define OFS_CLOAK_6       0x340 + 0x354 + 0x354 + 0x354 + 0x354  + 0x354 
#define OFS_BEYOND_6      0x2BC + 0x354 + 0x354 + 0x354 + 0x354  + 0x354 
#define OFS_BEYONDTIME_6  0x2C0 + 0x354 + 0x354 + 0x354 + 0x354  + 0x354 
#define OFS_STAT_WEAPON_6 0x30C + 0x354 + 0x354 + 0x354 + 0x354  + 0x354 
#define OFS_STAT_ARMOR_6  0x320 + 0x354 + 0x354 + 0x354 + 0x354  + 0x354 
#define OFS_STAT_HELM_6   0x334 + 0x354 + 0x354 + 0x354 + 0x354  + 0x354 
#define OFS_STAT_CLOAK_6  0x348 + 0x354 + 0x354 + 0x354 + 0x354  + 0x354 
#define OFS_GENDER_6      0x80  + 0x354 + 0x354 + 0x354 + 0x354  + 0x354 
//======================================================================//
#define ptr1 0x1FBC3EC
#define ptr2 0x30
#define ptr3 0x44
#define ptr4 0x48
#define FC   0x60
//======================================================================//
#define OFS_MAP_1    0x304
#define OFS_MAP_2    0x1CC
#define TOKEN        0x1A40
#define TOKEN_CHECK  0x1A8C
#define SKILL1       0x338
#define SKILL2       0x410
#define PASIF        0x1080
#define TT           0x2544
#define TT1          0x1FB0
#define ROBINHOOD    0x18E0
#define MF           0x1964
#define MF1          0x1A84 
#define MF2          0x1A40
#define SD           0x0
#define ASD          0x4
#define AD           0x8
#define AS           0xC
#define P_ASD        0x1C
#define P_AD         0x20
#define P_AS         0x24
#define HP1          0xDC
#define UNHP         0xC34
#define NPC1         0xDC
#define KILL1        0x300
#define FAST_HIT     0xDC4
#define KB1          0x1090
#define CheckName    0x2C4
#define GRADE        0x26C
#define DESTRO       0x1F9C
#define BRUSTDESTRO  0x18F4
#define MECHA	     0x1E1C
#define SPEED        0x954
#define Mikail       0x1E98
#define CYBROG       0x1D60
#define HGD          0x1A00
#define COWBOY       0x1D48
#define ARTHUR       0x1988
#define DRAGON       0x1AC4
#define VALKRI       0x16F4
#define MSK          0x19EC
#define MSK1         0x1D48
#define TRP          0x19BC
#define TRP1         0x1C80
#define PANCING      0x1D20
#define PANCING1     0x1EBC
#define LUCIFER      0x1DB4
#define Chaos        0x1910
#define Nangin       0x16F4
#define Nangin1      0x199C
#define Nangin2      0x1A00
#define ThunderBird  0x16F4
#define DonQuito     0x18E0
#define Maid         0x1F84
#define Archanist    0x16F4
#define SForce       0x18E0
#define Strider	     0x12C4 + 0x12C3
#define Kali         0x18E0
//=========================================================//
int tarantulah 	= 110;
int mechanich 	= 66;
int cowboyh 	= 3;
int tropperh 	= 11;
int musketerh 	= 18;
int mafiah 	= 26;
int luciferh 	= 81;
int destroyerh 	= 85;
int mikailh 	= 86;
int hgdh 	= 64;
int robinh 	= 7;
int cyborgh 	= 92;
int chaosh 	= 35;
int nanginh	= 120;
int birdh 	= 124;
int maidh 	= 106;
int archah 	= 117;
int forceh	= 32;
int valkrih 	= 127;
int kali       = 98;
int Striderh	= 153;

int valkri1h 	= 10127;
int tarantula1h = 10110;
int mechanic1h 	= 10066;
int cowboy1h 	= 10003;
int tropper1h 	= 10011;
int musketer1h	= 10018;
int mafia1h     = 10026;
int lucifer1h 	= 10081;
int destroyer1h = 10085;
int mikail1h 	= 10086;
int hgd1h 	= 70064;
int robin1h 	= 10007;
int cyborg1h 	= 10092;
int chaos1h 	= 10035;
int nangin1h 	= 10120;
int bird1h 	= 10124;
int maid1h 	= 10106;
int archa1h 	= 10117;
int force1h 	= 10032;
int kali1h = 10098;
int strider1h 	= 10153;
//=======Pasiffe Helm (AD)==========//
int hadesh = 210141;
int artagnanh = 210073;
//=======Pasiffe Acc (AS)===========//
int timecontrolh = 310070;
int sayapmerahh = 311033;
int sealh = 311042; //210098kali
int seal1h = 300117;
int invisibleh = 311072;
int phoenix2014 = 311108;
//=======Pasiffe Armor (ASD)========//
int armorarchah = 111035;
int armorghosth = 111034;
int armorarcha1h = 100117;
//==================================//

bool PatchByte(DWORD dwAddress, void *pData, size_t Size) {
	DWORD oldProtect;

	if (!IsBadReadPtr((void*)dwAddress, 4)) {
		if (!VirtualProtect((void*)dwAddress, Size, 0x40, &oldProtect)) return false;
		memcpy((void*)dwAddress, pData, Size);
		if (!VirtualProtect((void*)dwAddress, Size, oldProtect, &oldProtect)) return false;
		return true;
	}
	return false;
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



DWORD Reading(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5)
{
	DWORD Temp = NULL;
	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
					}
				}
			}
		}
	}
	return (0);
}



void Writing(void *adr, void *ptr, int size)
{
	DWORD OldProtection;
	VirtualProtect(adr, size, PAGE_EXECUTE_READWRITE, &OldProtection);
	memcpy(adr, ptr, size);
	//memcpy(adr,ptr,size);
	VirtualProtect(adr, size, OldProtection, &OldProtection);
}


DWORD WriteCowboy(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == cowboyh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																							if (value == cowboy1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD WriteCyborg(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == cyborgh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																							if (value == cyborg1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD WriteDestroyer(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == destroyerh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																							if (value == destroyer1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD WriteDestroyerBrust(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == destroyerh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																							if (value == destroyer1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}



DWORD WriteHgd(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == hgdh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																							if (value == hgd1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}



DWORD WriteLucifer(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == luciferh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																							if (value == lucifer1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD WriteMechanic(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == mechanich)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																							if (value == mechanic1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD WriteMikael(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == mikailh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																							if (value == mikail1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}



DWORD WriteMusketer(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == musketerh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																							if (value == musketer1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}



DWORD WriteRobin(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == robinh )
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																							if (value == robin1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}



DWORD WriteTarantula(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == tarantulah)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																							if (value == tarantula1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}







DWORD Function_(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
										Writing((void*)(Temp), (void*)(PBYTE)Value, size);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD WritingAD(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)CEK_AD;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);




																							if (value == hadesh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == artagnanh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}



																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}

DWORD WritingASD(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)CEK_ASD;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);




																							if (value == armorarchah )
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == armorarcha1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == armorghosth)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}



																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD WritingACC(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)CEK_AS;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);



																							if (value == timecontrolh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == sayapmerahh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == sealh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == seal1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == invisibleh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																							if (value == phoenix2014)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}



																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD WriteTroper(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == tropperh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == tropper1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD WriteChaos(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == chaosh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == chaos1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}



DWORD WriteForce(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == forceh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == force1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD WriteMaid(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == maidh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == maid1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}

DWORD WriteNangin(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == nanginh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == nangin1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD Write3Hero(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == nanginh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == nangin1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == birdh)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == bird1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																							if (value == archah)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == archa1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}



																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD WriteValkri(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == valkrih)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == valkri1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}

DWORD WriteJumper(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == 10134)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == 134)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}

DWORD WriteStrider(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == 10153)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == 153)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD WriteAlice(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == 10125)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}

																							if (value == 125)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD Refill_Token(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, int code)
{
	DWORD Temp = NULL;
	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


					DWORD Replace1 = Base;
					if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
						DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)Ofs1;
						if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
							DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)Ofs2;
							if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
								DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)TOKEN_CHECK;
								if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {

									int Check = *reinterpret_cast<int *>(Replace4);

									if (Check == 300000)
									{
										CrazyX4Byte((int)(Temp), (int)(PBYTE)code);
									}
								}

							}
						}
					}
				}
			}
		}
	}
	return (0);
}
DWORD Func_Token(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


					DWORD Replace1 = Base;
					if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
						DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)Ofs1;
						if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
							DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)Ofs2;
							if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
								DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)TOKEN_CHECK;
								if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {

									int Check = *reinterpret_cast<int *>(Replace4);

									if (Check == 300000)
									{
										Patch((void*)(Temp), (void*)(PBYTE)Value, size);
									}
								}

							}
						}
					}
				}
			}
		}
	}
	return (0);
}
DWORD WriteQuakeSnow(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;


	DWORD MAP_CEK = XP1;
	DWORD MAP_CEK_1 = *(PDWORD)((DWORD)(MAP_CEK)) + (DWORD)OFS_MAP_1;
	DWORD MAP_CEK_2 = *(PDWORD)((DWORD)(MAP_CEK_1)) + (DWORD)OFS_MAP_2;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {

								DWORD Replace1 = XP1;
								if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
									DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
									if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
										DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
										if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
											DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
											if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
												DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
												if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
													DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
													DWORD Replace7 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x04;
													if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

														int Check = *reinterpret_cast<int *>(Replace6);
														int Check1 = *reinterpret_cast<int *>(v3);
														int Check2 = *reinterpret_cast<int *>(Replace7);

														if (Check != Check1)
														{
															DWORD Replace1 = XP1;
															if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																	DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																	if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																		DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																		if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																			DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																			if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																				DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																				if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																					int value = *reinterpret_cast<int *>(Replace6);
																					int MAP_VALUE = *reinterpret_cast<int *>(MAP_CEK_2);

																					if (MAP_VALUE == 18)
																					{
																						if (Check2 == 8237 || Check2 == 2108720 || Check2 == 2108721 || Check2 == 2108722 || Check2 == 2108723 || Check2 == 2108724 || Check2 == 2108725 || Check2 == 2108726 || Check2 == 2108727 || Check2 == 2108728 || Check2 == 2108729)
																						{
																							if (value != 3209)
																							{
																								Patch((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																						}
																					}

																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD WriteQuakeSecret(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	DWORD MAP_CEK = XP1;
	DWORD MAP_CEK_1 = *(PDWORD)((DWORD)(MAP_CEK)) + (DWORD)OFS_MAP_1;
	DWORD MAP_CEK_2 = *(PDWORD)((DWORD)(MAP_CEK_1)) + (DWORD)OFS_MAP_2;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {

								DWORD Replace1 = XP1;
								if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
									DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
									if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
										DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
										if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
											DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
											if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
												DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
												if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
													DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
													DWORD Replace7 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x04;
													if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

														int Check = *reinterpret_cast<int *>(Replace6);
														int Check1 = *reinterpret_cast<int *>(v3);
														int Check2 = *reinterpret_cast<int *>(Replace7);

														if (Check != Check1)
														{
															DWORD Replace1 = XP1;
															if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																	DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																	if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																		DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																		if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																			DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																			if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																				DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																				if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																					int value = *reinterpret_cast<int *>(Replace6);
																					int MAP_VALUE = *reinterpret_cast<int *>(MAP_CEK_2);

																					if (MAP_VALUE == 22)
																					{

																						if (Check2 == 8237 || Check2 == 2108720 || Check2 == 2108721 || Check2 == 2108722 || Check2 == 2108723 || Check2 == 2108724 || Check2 == 2108725 || Check2 == 2108726 || Check2 == 2108727 || Check2 == 2108728 || Check2 == 2108729)
																						{
																							if (value != 4240)
																							{

																								Patch((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																						}
																					}

																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}

DWORD WriteQuakeFire(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;


	DWORD MAP_CEK = XP1;
	DWORD MAP_CEK_1 = *(PDWORD)((DWORD)(MAP_CEK)) + (DWORD)OFS_MAP_1;
	DWORD MAP_CEK_2 = *(PDWORD)((DWORD)(MAP_CEK_1)) + (DWORD)OFS_MAP_2;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {

								DWORD Replace1 = XP1;
								if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
									DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
									if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
										DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
										if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
											DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
											if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
												DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
												if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
													DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
													DWORD Replace7 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x04;
													if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

														int Check = *reinterpret_cast<int *>(Replace6);
														int Check1 = *reinterpret_cast<int *>(v3);
														int Check2 = *reinterpret_cast<int *>(Replace7);

														if (Check != Check1)
														{
															DWORD Replace1 = XP1;
															if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																	DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																	if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																		DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																		if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																			DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																			if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																				DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																				if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																					int value = *reinterpret_cast<int *>(Replace6);
																					int MAP_VALUE = *reinterpret_cast<int *>(MAP_CEK_2);

																					if (MAP_VALUE == 19)
																					{
																						if (Check2 == 8237 || Check2 == 2108720 || Check2 == 2108721 || Check2 == 2108722 || Check2 == 2108723 || Check2 == 2108724 || Check2 == 2108725 || Check2 == 2108726 || Check2 == 2108727 || Check2 == 2108728 || Check2 == 2108729)
																						{
																							if (value != 3108)
																							{
																								Patch((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}



DWORD WriteQuakeDeep(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	DWORD MAP_CEK = XP1;
	DWORD MAP_CEK_1 = *(PDWORD)((DWORD)(MAP_CEK)) + (DWORD)OFS_MAP_1;
	DWORD MAP_CEK_2 = *(PDWORD)((DWORD)(MAP_CEK_1)) + (DWORD)OFS_MAP_2;


	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {

								DWORD Replace1 = XP1;
								if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
									DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
									if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
										DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
										if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
											DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
											if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
												DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
												if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
													DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
													DWORD Replace7 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x04;
													if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

														int Check = *reinterpret_cast<int *>(Replace6);
														int Check1 = *reinterpret_cast<int *>(v3);
														int Check2 = *reinterpret_cast<int *>(Replace7);

														if (Check != Check1)
														{
															DWORD Replace1 = XP1;
															if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																	DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																	if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																		DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																		if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																			DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																			if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																				DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																				if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																					int value = *reinterpret_cast<int *>(Replace6);
																					int MAP_VALUE = *reinterpret_cast<int *>(MAP_CEK_2);

																					if (MAP_VALUE == 17)
																					{
																						if (Check2 == 8237 || Check2 == 2108720 || Check2 == 2108721 || Check2 == 2108722 || Check2 == 2108723 || Check2 == 2108724 || Check2 == 2108725 || Check2 == 2108726 || Check2 == 2108727 || Check2 == 2108728 || Check2 == 2108729)
																						{
																							if (value != 3011)
																							{

																								Patch((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																						}
																					}

																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}

DWORD WriteKali(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == kali )
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																							if (value == kali1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}



DWORD WriteMafia(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	DWORD Replace1 = XP1;
																	if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																		DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																		if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																			DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																			if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																				DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																				if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																					DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																					if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																						DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																						if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																							int value = *reinterpret_cast<int *>(Replace6);

																							if (value == mafiah)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																							if (value == mafia1h)
																							{
																								Writing((void*)(Temp), (void*)(PBYTE)Value, size);
																							}


																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}









DWORD SnowTown(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;


	DWORD MAP_CEK = XP1;
	DWORD MAP_CEK_1 = *(PDWORD)((DWORD)(MAP_CEK)) + (DWORD)OFS_MAP_1;
	DWORD MAP_CEK_2 = *(PDWORD)((DWORD)(MAP_CEK_1)) + (DWORD)OFS_MAP_2;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {

								DWORD Replace1 = XP1;
								if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
									DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
									if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
										DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
										if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
											DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
											if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
												DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
												if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
													DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
													DWORD Replace7 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x04;
													if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

														int Check = *reinterpret_cast<int *>(Replace6);
														int Check1 = *reinterpret_cast<int *>(v3);
														int Check2 = *reinterpret_cast<int *>(Replace7);

														if (Check != Check1)
														{
															DWORD Replace1 = XP1;
															if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																	DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																	if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																		DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																		if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																			DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																			if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																				DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																				if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																					int value = *reinterpret_cast<int *>(Replace6);
																					int MAP_VALUE = *reinterpret_cast<int *>(MAP_CEK_2);

																					if (MAP_VALUE == 18)
																					{
																						if (Check2 == 8237 || Check2 == 2108720 || Check2 == 2108721 || Check2 == 2108722 || Check2 == 2108723 || Check2 == 2108724 || Check2 == 2108725 || Check2 == 2108726 || Check2 == 2108727 || Check2 == 2108728 || Check2 == 2108729)
																						{
																							if (value != 3209)
																							{
																								Patch((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																						}
																					}

																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD Secret(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	DWORD MAP_CEK = XP1;
	DWORD MAP_CEK_1 = *(PDWORD)((DWORD)(MAP_CEK)) + (DWORD)OFS_MAP_1;
	DWORD MAP_CEK_2 = *(PDWORD)((DWORD)(MAP_CEK_1)) + (DWORD)OFS_MAP_2;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {

								DWORD Replace1 = XP1;
								if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
									DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
									if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
										DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
										if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
											DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
											if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
												DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
												if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
													DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
													DWORD Replace7 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x04;
													if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

														int Check = *reinterpret_cast<int *>(Replace6);
														int Check1 = *reinterpret_cast<int *>(v3);
														int Check2 = *reinterpret_cast<int *>(Replace7);

														if (Check != Check1)
														{
															DWORD Replace1 = XP1;
															if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																	DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																	if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																		DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																		if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																			DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																			if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																				DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																				if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																					int value = *reinterpret_cast<int *>(Replace6);
																					int MAP_VALUE = *reinterpret_cast<int *>(MAP_CEK_2);

																					if (MAP_VALUE == 22)
																					{

																						if (Check2 == 8237 || Check2 == 2108720 || Check2 == 2108721 || Check2 == 2108722 || Check2 == 2108723 || Check2 == 2108724 || Check2 == 2108725 || Check2 == 2108726 || Check2 == 2108727 || Check2 == 2108728 || Check2 == 2108729)
																						{
																							if (value != 4240)
																							{

																								Patch((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																						}
																					}

																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}

DWORD FireTemple(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;


	DWORD MAP_CEK = XP1;
	DWORD MAP_CEK_1 = *(PDWORD)((DWORD)(MAP_CEK)) + (DWORD)OFS_MAP_1;
	DWORD MAP_CEK_2 = *(PDWORD)((DWORD)(MAP_CEK_1)) + (DWORD)OFS_MAP_2;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {

								DWORD Replace1 = XP1;
								if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
									DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
									if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
										DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
										if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
											DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
											if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
												DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
												if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
													DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
													DWORD Replace7 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x04;
													if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

														int Check = *reinterpret_cast<int *>(Replace6);
														int Check1 = *reinterpret_cast<int *>(v3);
														int Check2 = *reinterpret_cast<int *>(Replace7);

														if (Check != Check1)
														{
															DWORD Replace1 = XP1;
															if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																	DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																	if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																		DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																		if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																			DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																			if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																				DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																				if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																					int value = *reinterpret_cast<int *>(Replace6);
																					int MAP_VALUE = *reinterpret_cast<int *>(MAP_CEK_2);

																					if (MAP_VALUE == 19)
																					{
																						if (Check2 == 8237 || Check2 == 2108720 || Check2 == 2108721 || Check2 == 2108722 || Check2 == 2108723 || Check2 == 2108724 || Check2 == 2108725 || Check2 == 2108726 || Check2 == 2108727 || Check2 == 2108728 || Check2 == 2108729)
																						{
																							if (value != 3108)
																							{
																								Patch((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}



DWORD Deep(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	DWORD MAP_CEK = XP1;
	DWORD MAP_CEK_1 = *(PDWORD)((DWORD)(MAP_CEK)) + (DWORD)OFS_MAP_1;
	DWORD MAP_CEK_2 = *(PDWORD)((DWORD)(MAP_CEK_1)) + (DWORD)OFS_MAP_2;


	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {

								DWORD Replace1 = XP1;
								if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
									DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
									if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
										DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
										if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
											DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
											if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
												DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
												if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
													DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
													DWORD Replace7 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x04;
													if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

														int Check = *reinterpret_cast<int *>(Replace6);
														int Check1 = *reinterpret_cast<int *>(v3);
														int Check2 = *reinterpret_cast<int *>(Replace7);

														if (Check != Check1)
														{
															DWORD Replace1 = XP1;
															if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
																DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
																if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
																	DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
																	if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
																		DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
																		if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
																			DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)SKILL1;
																			if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
																				DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x124;
																				if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {
																					int value = *reinterpret_cast<int *>(Replace6);
																					int MAP_VALUE = *reinterpret_cast<int *>(MAP_CEK_2);

																					if (MAP_VALUE == 17)
																					{
																						if (Check2 == 8237 || Check2 == 2108720 || Check2 == 2108721 || Check2 == 2108722 || Check2 == 2108723 || Check2 == 2108724 || Check2 == 2108725 || Check2 == 2108726 || Check2 == 2108727 || Check2 == 2108728 || Check2 == 2108729)
																						{
																							if (value != 3011)
																							{

																								Patch((void*)(Temp), (void*)(PBYTE)Value, size);
																							}
																						}
																					}

																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}



DWORD TELEPORT_SECRET(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, int value)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	DWORD MAP_CEK = XP1;
	DWORD MAP_CEK_1 = *(PDWORD)((DWORD)(MAP_CEK)) + (DWORD)OFS_MAP_1;
	DWORD MAP_CEK_2 = *(PDWORD)((DWORD)(MAP_CEK_1)) + (DWORD)OFS_MAP_2;


	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = Base;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)Ofs1;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)Ofs2;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);
																int MAP_VALUE = *reinterpret_cast<int *>(MAP_CEK_2);

																if (MAP_VALUE == 22)
																{
																	if (Check == Check1)
																	{
																		CrazyX4Byte(Temp, value);
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}

DWORD TELEPORT_SNOW(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, int value)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	DWORD MAP_CEK = XP1;
	DWORD MAP_CEK_1 = *(PDWORD)((DWORD)(MAP_CEK)) + (DWORD)OFS_MAP_1;
	DWORD MAP_CEK_2 = *(PDWORD)((DWORD)(MAP_CEK_1)) + (DWORD)OFS_MAP_2;


	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = Base;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)Ofs1;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)Ofs2;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);
																int MAP_VALUE = *reinterpret_cast<int *>(MAP_CEK_2);

																if (MAP_VALUE == 18)
																{
																	if (Check == Check1)
																	{
																		CrazyX4Byte(Temp, value);
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}

DWORD TELEPORT_FIRE(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, int value)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	DWORD MAP_CEK = XP1;
	DWORD MAP_CEK_1 = *(PDWORD)((DWORD)(MAP_CEK)) + (DWORD)OFS_MAP_1;
	DWORD MAP_CEK_2 = *(PDWORD)((DWORD)(MAP_CEK_1)) + (DWORD)OFS_MAP_2;


	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = Base;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)Ofs1;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)Ofs2;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);
																int MAP_VALUE = *reinterpret_cast<int *>(MAP_CEK_2);

																if (MAP_VALUE == 19)
																{
																	if (Check == Check1)
																	{
																		CrazyX4Byte(Temp, value);
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}

DWORD TELEPORT_FOREST(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, int value)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	DWORD MAP_CEK = XP1;
	DWORD MAP_CEK_1 = *(PDWORD)((DWORD)(MAP_CEK)) + (DWORD)OFS_MAP_1;
	DWORD MAP_CEK_2 = *(PDWORD)((DWORD)(MAP_CEK_1)) + (DWORD)OFS_MAP_2;


	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = Base;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)Ofs1;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)Ofs2;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);
																int MAP_VALUE = *reinterpret_cast<int *>(MAP_CEK_2);

																if (MAP_VALUE == 17)
																{
																	if (Check == Check1)
																	{
																		CrazyX4Byte(Temp, value);
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}



DWORD MAGNETCSD(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, int value)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {

										DWORD Replace1 = XP1;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															DWORD Replace7 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x04;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);
																int Check2 = *reinterpret_cast<int *>(Replace7);

																if (Check != Check1)
																{
																	if (Check < 1000000000)
																	{
																		if (Check2 == 8237 || Check2 == 2108720 || Check2 == 2108721 || Check2 == 2108722 || Check2 == 2108723 || Check2 == 2108724 || Check2 == 2108725 || Check2 == 2108726 || Check2 == 2108727 || Check2 == 2108728 || Check2 == 2108729
																			|| Check2 == 539832368
																			|| Check2 == 539832624
																			|| Check2 == 539832880
																			|| Check2 == 539833136
																			|| Check2 == 539833392
																			|| Check2 == 539833648
																			|| Check2 == 539833904
																			|| Check2 == 539834160
																			|| Check2 == 539834416
																			|| Check2 == 539834672
																			|| Check2 == 539832369
																			|| Check2 == 539832625
																			|| Check2 == 539832881
																			|| Check2 == 539833137
																			|| Check2 == 539833393
																			|| Check2 == 539833649
																			|| Check2 == 539833905
																			|| Check2 == 539834161
																			|| Check2 == 539834417
																			|| Check2 == 539834673
																			|| Check2 == 539832370
																			|| Check2 == 539832626
																			|| Check2 == 539832882
																			|| Check2 == 539833138
																			|| Check2 == 539833394
																			|| Check2 == 539833650
																			|| Check2 == 539833906
																			|| Check2 == 539834162
																			|| Check2 == 539834418
																			|| Check2 == 539834674
																			|| Check2 == 539832371
																			|| Check2 == 539832627
																			|| Check2 == 539832883
																			|| Check2 == 539833139
																			|| Check2 == 539833395
																			|| Check2 == 539833651
																			|| Check2 == 539833907
																			|| Check2 == 539834163
																			|| Check2 == 539834419
																			|| Check2 == 539834675
																			|| Check2 == 539832372
																			|| Check2 == 539832628
																			|| Check2 == 539832884
																			|| Check2 == 539833140
																			|| Check2 == 539833396
																			|| Check2 == 539833652
																			|| Check2 == 539833908
																			|| Check2 == 539834164
																			|| Check2 == 539834420
																			|| Check2 == 539834676
																			|| Check2 == 539832373
																			|| Check2 == 539832629
																			|| Check2 == 539832885
																			|| Check2 == 539833141
																			|| Check2 == 539833397
																			|| Check2 == 539833653
																			|| Check2 == 539833909
																			|| Check2 == 539834165
																			|| Check2 == 539834421
																			|| Check2 == 539834677
																			|| Check2 == 539832374
																			|| Check2 == 539832630
																			|| Check2 == 539832886
																			|| Check2 == 539833142
																			|| Check2 == 539833398
																			|| Check2 == 539833654
																			|| Check2 == 539833910
																			|| Check2 == 539834166
																			|| Check2 == 539834422
																			|| Check2 == 539834678
																			|| Check2 == 539832375
																			|| Check2 == 539832631
																			|| Check2 == 539832887
																			|| Check2 == 539833143
																			|| Check2 == 539833399
																			|| Check2 == 539833655
																			|| Check2 == 539833911
																			|| Check2 == 539834167
																			|| Check2 == 539834423
																			|| Check2 == 539834679
																			|| Check2 == 539832376
																			|| Check2 == 539832632
																			|| Check2 == 539832888
																			|| Check2 == 539833144
																			|| Check2 == 539833400
																			|| Check2 == 539833656
																			|| Check2 == 539833912
																			|| Check2 == 539834168
																			|| Check2 == 539834424
																			|| Check2 == 539834680
																			|| Check2 == 539832377
																			|| Check2 == 539832633
																			|| Check2 == 539832889
																			|| Check2 == 539833145
																			|| Check2 == 539833401
																			|| Check2 == 539833657
																			|| Check2 == 539833913
																			|| Check2 == 539834169
																			|| Check2 == 539834425
																			|| Check2 == 539834681
																			)
																		{
																			CrazyX4Byte(Temp, value);
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}


DWORD One_hit(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {

								DWORD Replace1 = XP1;
								if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
									DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
									if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
										DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
										if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
											DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
											if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
												DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
												if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
													DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
													DWORD Replace7 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x04;
													if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

														int Check = *reinterpret_cast<int *>(Replace6);
														int Check1 = *reinterpret_cast<int *>(v3);
														int Check2 = *reinterpret_cast<int *>(Replace7);

														if (Check != Check1)
														{
															if (Check < 1000000000)
															{
																if (Check2 == 8237 || Check2 == 2108720 || Check2 == 2108721 || Check2 == 2108722 || Check2 == 2108723 || Check2 == 2108724 || Check2 == 2108725 || Check2 == 2108726 || Check2 == 2108727 || Check2 == 2108728 || Check2 == 2108729
																	|| Check2 == 539832368
																	|| Check2 == 539832624
																	|| Check2 == 539832880
																	|| Check2 == 539833136
																	|| Check2 == 539833392
																	|| Check2 == 539833648
																	|| Check2 == 539833904
																	|| Check2 == 539834160
																	|| Check2 == 539834416
																	|| Check2 == 539834672
																	|| Check2 == 539832369
																	|| Check2 == 539832625
																	|| Check2 == 539832881
																	|| Check2 == 539833137
																	|| Check2 == 539833393
																	|| Check2 == 539833649
																	|| Check2 == 539833905
																	|| Check2 == 539834161
																	|| Check2 == 539834417
																	|| Check2 == 539834673
																	|| Check2 == 539832370
																	|| Check2 == 539832626
																	|| Check2 == 539832882
																	|| Check2 == 539833138
																	|| Check2 == 539833394
																	|| Check2 == 539833650
																	|| Check2 == 539833906
																	|| Check2 == 539834162
																	|| Check2 == 539834418
																	|| Check2 == 539834674
																	|| Check2 == 539832371
																	|| Check2 == 539832627
																	|| Check2 == 539832883
																	|| Check2 == 539833139
																	|| Check2 == 539833395
																	|| Check2 == 539833651
																	|| Check2 == 539833907
																	|| Check2 == 539834163
																	|| Check2 == 539834419
																	|| Check2 == 539834675
																	|| Check2 == 539832372
																	|| Check2 == 539832628
																	|| Check2 == 539832884
																	|| Check2 == 539833140
																	|| Check2 == 539833396
																	|| Check2 == 539833652
																	|| Check2 == 539833908
																	|| Check2 == 539834164
																	|| Check2 == 539834420
																	|| Check2 == 539834676
																	|| Check2 == 539832373
																	|| Check2 == 539832629
																	|| Check2 == 539832885
																	|| Check2 == 539833141
																	|| Check2 == 539833397
																	|| Check2 == 539833653
																	|| Check2 == 539833909
																	|| Check2 == 539834165
																	|| Check2 == 539834421
																	|| Check2 == 539834677
																	|| Check2 == 539832374
																	|| Check2 == 539832630
																	|| Check2 == 539832886
																	|| Check2 == 539833142
																	|| Check2 == 539833398
																	|| Check2 == 539833654
																	|| Check2 == 539833910
																	|| Check2 == 539834166
																	|| Check2 == 539834422
																	|| Check2 == 539834678
																	|| Check2 == 539832375
																	|| Check2 == 539832631
																	|| Check2 == 539832887
																	|| Check2 == 539833143
																	|| Check2 == 539833399
																	|| Check2 == 539833655
																	|| Check2 == 539833911
																	|| Check2 == 539834167
																	|| Check2 == 539834423
																	|| Check2 == 539834679
																	|| Check2 == 539832376
																	|| Check2 == 539832632
																	|| Check2 == 539832888
																	|| Check2 == 539833144
																	|| Check2 == 539833400
																	|| Check2 == 539833656
																	|| Check2 == 539833912
																	|| Check2 == 539834168
																	|| Check2 == 539834424
																	|| Check2 == 539834680
																	|| Check2 == 539832377
																	|| Check2 == 539832633
																	|| Check2 == 539832889
																	|| Check2 == 539833145
																	|| Check2 == 539833401
																	|| Check2 == 539833657
																	|| Check2 == 539833913
																	|| Check2 == 539834169
																	|| Check2 == 539834425
																	|| Check2 == 539834681
																	)
																{
																	Patch((void*)(Temp), (void*)(PBYTE)Value, size);

																}
															}
														}
													}
												}
											}
										}
									}
								}

							}
						}
					}
				}
			}
		}
	}
	return (0);
}



DWORD Function_6(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


								DWORD Replace1 = Base;
								if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
									DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)Ofs1;
									if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
										DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)Ofs2;
										if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
											DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
											if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
												DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
												if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
													DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
													if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

														int Check = *reinterpret_cast<int *>(Replace6);
														int Check1 = *reinterpret_cast<int *>(v3);

														if (Check == Check1)
														{
															Patch((void*)(Temp), (void*)(PBYTE)Value, size);
														}
													}
												}
											}
										}
									}
								}

							}
						}
					}
				}
			}
		}
	}
	return (0);
}



DWORD WriteQuakeMain(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {

								DWORD Replace1 = XP1;
								if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
									DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)XP2;
									if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
										DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)XP3;
										if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
											DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
											if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
												DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
												if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
													DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
													DWORD Replace7 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x04;
													if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

														int Check = *reinterpret_cast<int *>(Replace6);
														int Check1 = *reinterpret_cast<int *>(v3);
														int Check2 = *reinterpret_cast<int *>(Replace7);

														if (Check != Check1)
														{
															if (Check < 1000000000)
															{
																if (Check2 == 8237 || Check2 == 2108720 || Check2 == 2108721 || Check2 == 2108722 || Check2 == 2108723 || Check2 == 2108724 || Check2 == 2108725 || Check2 == 2108726 || Check2 == 2108727 || Check2 == 2108728 || Check2 == 2108729
																	|| Check2 == 539832368
																	|| Check2 == 539832624
																	|| Check2 == 539832880
																	|| Check2 == 539833136
																	|| Check2 == 539833392
																	|| Check2 == 539833648
																	|| Check2 == 539833904
																	|| Check2 == 539834160
																	|| Check2 == 539834416
																	|| Check2 == 539834672
																	|| Check2 == 539832369
																	|| Check2 == 539832625
																	|| Check2 == 539832881
																	|| Check2 == 539833137
																	|| Check2 == 539833393
																	|| Check2 == 539833649
																	|| Check2 == 539833905
																	|| Check2 == 539834161
																	|| Check2 == 539834417
																	|| Check2 == 539834673
																	|| Check2 == 539832370
																	|| Check2 == 539832626
																	|| Check2 == 539832882
																	|| Check2 == 539833138
																	|| Check2 == 539833394
																	|| Check2 == 539833650
																	|| Check2 == 539833906
																	|| Check2 == 539834162
																	|| Check2 == 539834418
																	|| Check2 == 539834674
																	|| Check2 == 539832371
																	|| Check2 == 539832627
																	|| Check2 == 539832883
																	|| Check2 == 539833139
																	|| Check2 == 539833395
																	|| Check2 == 539833651
																	|| Check2 == 539833907
																	|| Check2 == 539834163
																	|| Check2 == 539834419
																	|| Check2 == 539834675
																	|| Check2 == 539832372
																	|| Check2 == 539832628
																	|| Check2 == 539832884
																	|| Check2 == 539833140
																	|| Check2 == 539833396
																	|| Check2 == 539833652
																	|| Check2 == 539833908
																	|| Check2 == 539834164
																	|| Check2 == 539834420
																	|| Check2 == 539834676
																	|| Check2 == 539832373
																	|| Check2 == 539832629
																	|| Check2 == 539832885
																	|| Check2 == 539833141
																	|| Check2 == 539833397
																	|| Check2 == 539833653
																	|| Check2 == 539833909
																	|| Check2 == 539834165
																	|| Check2 == 539834421
																	|| Check2 == 539834677
																	|| Check2 == 539832374
																	|| Check2 == 539832630
																	|| Check2 == 539832886
																	|| Check2 == 539833142
																	|| Check2 == 539833398
																	|| Check2 == 539833654
																	|| Check2 == 539833910
																	|| Check2 == 539834166
																	|| Check2 == 539834422
																	|| Check2 == 539834678
																	|| Check2 == 539832375
																	|| Check2 == 539832631
																	|| Check2 == 539832887
																	|| Check2 == 539833143
																	|| Check2 == 539833399
																	|| Check2 == 539833655
																	|| Check2 == 539833911
																	|| Check2 == 539834167
																	|| Check2 == 539834423
																	|| Check2 == 539834679
																	|| Check2 == 539832376
																	|| Check2 == 539832632
																	|| Check2 == 539832888
																	|| Check2 == 539833144
																	|| Check2 == 539833400
																	|| Check2 == 539833656
																	|| Check2 == 539833912
																	|| Check2 == 539834168
																	|| Check2 == 539834424
																	|| Check2 == 539834680
																	|| Check2 == 539832377
																	|| Check2 == 539832633
																	|| Check2 == 539832889
																	|| Check2 == 539833145
																	|| Check2 == 539833401
																	|| Check2 == 539833657
																	|| Check2 == 539833913
																	|| Check2 == 539834169
																	|| Check2 == 539834425
																	|| Check2 == 539834681
																	)
																{
																	Patch((void*)(Temp), (void*)(PBYTE)Value, size);

																}
															}
														}
													}
												}
											}
										}
									}
								}

							}
						}
					}
				}
			}
		}
	}
	return (0);
}

DWORD Writing8(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, DWORD Ofs5, DWORD Ofs6, DWORD Ofs7, DWORD Ofs8, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	DWORD v1 = HERO;
	DWORD v2 = *(PDWORD)((DWORD)(v1)) + (DWORD)Nama;
	DWORD v3 = *(PDWORD)((DWORD)(v2)) + (DWORD)Nama1;

	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Temp = *(PDWORD)((DWORD)(Temp)) + Ofs5;
						if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
							Temp = *(PDWORD)((DWORD)(Temp)) + Ofs6;
							if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
								Temp = *(PDWORD)((DWORD)(Temp)) + Ofs7;
								if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
									Temp = *(PDWORD)((DWORD)(Temp)) + Ofs8;
									if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {


										DWORD Replace1 = Base;
										if (IsBadReadPtr((PDWORD)Replace1, 4) == 0) {
											DWORD Replace2 = *(PDWORD)((DWORD)(Replace1)) + (DWORD)Ofs1;
											if (IsBadReadPtr((PDWORD)Replace2, 4) == 0) {
												DWORD Replace3 = *(PDWORD)((DWORD)(Replace2)) + (DWORD)Ofs2;
												if (IsBadReadPtr((PDWORD)Replace3, 4) == 0) {
													DWORD Replace4 = *(PDWORD)((DWORD)(Replace3)) + (DWORD)Ofs3;
													if (IsBadReadPtr((PDWORD)Replace4, 4) == 0) {
														DWORD Replace5 = *(PDWORD)((DWORD)(Replace4)) + (DWORD)CheckName;
														if (IsBadReadPtr((PDWORD)Replace5, 4) == 0) {
															DWORD Replace6 = *(PDWORD)((DWORD)(Replace5)) + (DWORD)0x0;
															if (IsBadReadPtr((PDWORD)Replace6, 4) == 0) {

																int Check = *reinterpret_cast<int *>(Replace6);
																int Check1 = *reinterpret_cast<int *>(v3);

																if (Check == Check1)
																{
																	Patch((void*)(Temp), (void*)(PBYTE)Value, size);
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}





DWORD Function_1(DWORD Base, DWORD Ofs1, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	if (IsBadReadPtr((PDWORD)Base, 4) == 0)
	{
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Patch((void*)(Temp), (void*)(PBYTE)Value, size);
		}
	}return (0);
}


DWORD ValueWrite3(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, int code)
{
	DWORD Temp = NULL;
	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					CrazyX4Byte((int)(Temp), (int)(PBYTE)code);
				}
			}
		}
	}
	return (0);
}

DWORD ValueWrite3(DWORD Base, DWORD Ofs1, DWORD Ofs2, int code)
{
	DWORD Temp = NULL;
	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				CrazyX4Byte((int)(Temp), (int)(PBYTE)code);
			}
		}
	}
	return (0);
}

DWORD Function_3(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Patch((void*)(Temp), (void*)(PBYTE)Value, size);
				}
			}
		}
	}
	return (0);
}

DWORD Function_3(DWORD Base, DWORD Ofs1, DWORD Ofs2, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Patch((void*)(Temp), (void*)(PBYTE)Value, size);
			}
		}
	}
	return (0);
}

DWORD Function_4(DWORD Base, DWORD Ofs1, DWORD Ofs2, DWORD Ofs3, DWORD Ofs4, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Temp = *(PDWORD)((DWORD)(Temp)) + Ofs4;
					if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
						Patch((void*)(Temp), (void*)(PBYTE)Value, size);
					}
				}
			}
		}
	}
	return (0);
}


DWORD FUCK_(LPVOID param)
{
while (1)
	{
		Sleep(20);
		
if (GetAsyncKeyState(VK_SEPARATOR) & 0x1) Token = !Token;
		if (Token)
		{
			Func_Token(XP1, XP2, RM_2, TOKEN, (PBYTE)"\xFF\xFF\xFF\xFF\xFF\xFF\xFB\x00", 8);
		}	
if (GetAsyncKeyState(VK_SUBTRACT) & 0x1) No_Afk = !No_Afk;
		if (No_Afk)
		{
			Function_1(BASE_AFK, OFS_AFK1, (PBYTE)"\x05", 1);
			Function_1(BASE_AFK, OFS_AFK2, (PBYTE)"\x05", 1);
			Function_1(BASE_AFK, OFS_AFK3, (PBYTE)"\x05", 1);
			Function_1(BASE_AFK, OFS_AFK4, (PBYTE)"\x05", 1);
			Function_1(BASE_AFK, OFS_AFK5, (PBYTE)"\x05", 1);
			Function_1(BASE_AFK, OFS_AFK6, (PBYTE)"\x05", 1);
		}
			
if (GetAsyncKeyState(VK_F13) & 0x1) isFreeze = !isFreeze;
		if (isFreeze)
		{
			Writing8(RM_1, RM_2, RM_3, RM_4, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(RM_1, RM_2, RM_3, RM_4, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(RM_1, RM_2, RM_3, RM_4, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(RM_1, RM_2, RM_3, RM_4, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, AS, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, ASD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			Writing8(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, AD, SKILL2, (PBYTE)"\xA9\x0A\x4F\x5F", 4);
			WritingACC(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, P_AS, PASIF, (PBYTE)"\x28\x1A\xBE\xE7", 4);//\x28\x1A\xBE\xE7
			WritingACC(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, P_AS, PASIF, (PBYTE)"\x28\x1A\xBE\xE7", 4);
			WritingACC(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, P_AS, PASIF, (PBYTE)"\x28\x1A\xBE\xE7", 4);
			WritingACC(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, P_AS, PASIF, (PBYTE)"\x28\x1A\xBE\xE7", 4);
			WritingACC(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, P_AS, PASIF, (PBYTE)"\x28\x1A\xBE\xE7", 4);
			WritingACC(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, P_AS, PASIF, (PBYTE)"\x28\x1A\xBE\xE7", 4);
			WritingACC(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, P_AS, PASIF, (PBYTE)"\x28\x1A\xBE\xE7", 4);
			WritingACC(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, P_AS, PASIF, (PBYTE)"\x28\x1A\xBE\xE7", 4);
			WritingACC(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, P_AS, PASIF, (PBYTE)"\x28\x1A\xBE\xE7", 4);
			WritingACC(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, P_AS, PASIF, (PBYTE)"\x28\x1A\xBE\xE7", 4);
			WritingACC(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, P_AS, PASIF, (PBYTE)"\x28\x1A\xBE\xE7", 4);
			WritingACC(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, P_AS, PASIF, (PBYTE)"\x28\x1A\xBE\xE7", 4);
			WritingACC(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, P_AS, PASIF, (PBYTE)"\x28\x1A\xBE\xE7", 4);
			WritingACC(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, P_AS, PASIF, (PBYTE)"\x28\x1A\xBE\xE7", 4);
			WritingACC(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, P_AS, PASIF, (PBYTE)"\x28\x1A\xBE\xE7", 4);
			WritingACC(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, P_AS, PASIF, (PBYTE)"\x28\x1A\xBE\xE7", 4);
			WritingASD(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, P_ASD, PASIF, (PBYTE)"\xA8\x9A\x23\x69", 4);
			WritingASD(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, P_ASD, PASIF, (PBYTE)"\xA8\x9A\x23\x69", 4);
			WritingASD(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, P_ASD, PASIF, (PBYTE)"\xA8\x9A\x23\x69", 4);
			WritingASD(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, P_ASD, PASIF, (PBYTE)"\xA8\x9A\x23\x69", 4);
			WritingASD(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, P_ASD, PASIF, (PBYTE)"\xA8\x9A\x23\x69", 4);
			WritingASD(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, P_ASD, PASIF, (PBYTE)"\xA8\x9A\x23\x69", 4);
			WritingASD(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, P_ASD, PASIF, (PBYTE)"\xA8\x9A\x23\x69", 4);
			WritingASD(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, P_ASD, PASIF, (PBYTE)"\xA8\x9A\x23\x69", 4);
			WritingASD(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, P_ASD, PASIF, (PBYTE)"\xA8\x9A\x23\x69", 4);
			WritingASD(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, P_ASD, PASIF, (PBYTE)"\xA8\x9A\x23\x69", 4);
			WritingASD(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, P_ASD, PASIF, (PBYTE)"\xA8\x9A\x23\x69", 4);
			WritingASD(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, P_ASD, PASIF, (PBYTE)"\xA8\x9A\x23\x69", 4);
			WritingASD(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, P_ASD, PASIF, (PBYTE)"\xA8\x9A\x23\x69", 4);
			WritingASD(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, P_ASD, PASIF, (PBYTE)"\xA8\x9A\x23\x69", 4);
			WritingASD(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, P_ASD, PASIF, (PBYTE)"\xA8\x9A\x23\x69", 4);
			WritingASD(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, P_ASD, PASIF, (PBYTE)"\xA8\x9A\x23\x69", 4);
		}
		if (GetAsyncKeyState(VK_F8) & 0x1) MultiLeader = !MultiLeader;
		if (MultiLeader)
		{
			ValueWrite3(BASE_REPLACE, 0x30C, 0x498, 0);//
			ValueWrite3(BASE_REPLACE, 0x30C, 0x4C9, 0);//
		}
if (GetAsyncKeyState(VK_F15) & 0x1) Darah = !Darah;
		if (Darah)
		{
			Function_6(RM_1, RM_2, RM_3, RM_4, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_1, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_2, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_3, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_4, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_5, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_6, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_7, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_8, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_9, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_10, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_11, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_12, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_13, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_14, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_15, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_16, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
		}
if (GetAsyncKeyState(VK_F16) & 0x1) zerohp = !zerohp;
		if (zerohp)
		{
			One_hit(XP1, XP2, XP3, OFS_1, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_2, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_3, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_4, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_5, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_6, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_7, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_8, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_9, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_10, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_11, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_12, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_13, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_14, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_15, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_16, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_17, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_18, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_19, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_20, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_21, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_22, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_23, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_24, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_25, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_26, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_27, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_28, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_29, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_30, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_31, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_32, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_33, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_34, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_35, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_36, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_37, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_38, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_39, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_40, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_41, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_42, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_43, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_44, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_45, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_46, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_47, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_48, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_49, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_50, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_51, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_52, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_53, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_54, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_55, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_56, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_57, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_58, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_59, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_60, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_61, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_62, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_63, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_64, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_65, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
			One_hit(XP1, XP2, XP3, OFS_66, BASE1, BASE2, HP1, (PBYTE)"\x00\x00\x00\x00", 4);
		}
if (GetAsyncKeyState(VK_F17) & 0x1) Botkill = !Botkill;
		if (Botkill)
		{
			Function_6(XP1, XP2, XP3, OFS_1, BASE1, BASE2, KILL1, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_2, BASE1, BASE2, KILL1, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_3, BASE1, BASE2, KILL1, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_4, BASE1, BASE2, KILL1, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_5, BASE1, BASE2, KILL1, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_6, BASE1, BASE2, KILL1, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_7, BASE1, BASE2, KILL1, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_8, BASE1, BASE2, KILL1, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_9, BASE1, BASE2, KILL1, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_10, BASE1, BASE2, KILL1, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_11, BASE1, BASE2, KILL1, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_12, BASE1, BASE2, KILL1, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_13, BASE1, BASE2, KILL1, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_14, BASE1, BASE2, KILL1, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_15, BASE1, BASE2, KILL1, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_16, BASE1, BASE2, KILL1, (PBYTE)"\x00", 1);
		}
		if (GetAsyncKeyState(VK_F18) & 0x1) Kebal = !Kebal;
		if (Kebal)
		{
			Function_6(RM_1, RM_2, RM_3, RM_4, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
			Function_6(XP1, XP2, XP3, OFS_1, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
			Function_6(XP1, XP2, XP3, OFS_2, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
			Function_6(XP1, XP2, XP3, OFS_3, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
			Function_6(XP1, XP2, XP3, OFS_4, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
			Function_6(XP1, XP2, XP3, OFS_5, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
			Function_6(XP1, XP2, XP3, OFS_6, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
			Function_6(XP1, XP2, XP3, OFS_7, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
			Function_6(XP1, XP2, XP3, OFS_8, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
			Function_6(XP1, XP2, XP3, OFS_9, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
			Function_6(XP1, XP2, XP3, OFS_10, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
			Function_6(XP1, XP2, XP3, OFS_11, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
			Function_6(XP1, XP2, XP3, OFS_12, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
			Function_6(XP1, XP2, XP3, OFS_13, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
			Function_6(XP1, XP2, XP3, OFS_14, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
			Function_6(XP1, XP2, XP3, OFS_15, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
			Function_6(XP1, XP2, XP3, OFS_16, BASE1, BASE2, KB1, (PBYTE)"\x99\x99\x99\x99", 4);
		}
		if (GetAsyncKeyState(VK_BROWSER_FAVORITES) & 0x1) Brust_ = !Brust_;
		if (Brust_)
		{
			//Chaos

			WriteChaos(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);

			// Musketer


			WriteMusketer(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);

			//Troper

			WriteTroper(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);


			WriteTroper(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);


			//Cowboy
			WriteCowboy(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);

			// Robin


			WriteRobin(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);


			// S force


			WriteForce(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);


			//Brust Destro


			WriteDestroyer(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);

			WriteDestroyerBrust(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);


			//Brust TT

			WriteTarantula(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);

			WriteTarantula(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);

			//Brust Kali
			WriteKali(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
		}
if (GetAsyncKeyState(VK_F19) & 0x1) Pasif_Hero = !Pasif_Hero;
		if (Pasif_Hero)
		{
			// Cyborg
			WriteCyborg(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, CYBROG, (PBYTE)"\xA9\xCA\x12", 3);
			WriteCyborg(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, CYBROG, (PBYTE)"\xA9\xCA\x12", 3);
			WriteCyborg(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, CYBROG, (PBYTE)"\xA9\xCA\x12", 3);
			WriteCyborg(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, CYBROG, (PBYTE)"\xA9\xCA\x12", 3);
			WriteCyborg(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, CYBROG, (PBYTE)"\xA9\xCA\x12", 3);
			WriteCyborg(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, CYBROG, (PBYTE)"\xA9\xCA\x12", 3);
			WriteCyborg(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, CYBROG, (PBYTE)"\xA9\xCA\x12", 3);
			WriteCyborg(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, CYBROG, (PBYTE)"\xA9\xCA\x12", 3);
			WriteCyborg(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, CYBROG, (PBYTE)"\xA9\xCA\x12", 3);
			WriteCyborg(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, CYBROG, (PBYTE)"\xA9\xCA\x12", 3);
			WriteCyborg(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, CYBROG, (PBYTE)"\xA9\xCA\x12", 3);
			WriteCyborg(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, CYBROG, (PBYTE)"\xA9\xCA\x12", 3);
			WriteCyborg(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, CYBROG, (PBYTE)"\xA9\xCA\x12", 3);
			WriteCyborg(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, CYBROG, (PBYTE)"\xA9\xCA\x12", 3);
			WriteCyborg(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, CYBROG, (PBYTE)"\xA9\xCA\x12", 3);
			WriteCyborg(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, CYBROG, (PBYTE)"\xA9\xCA\x12", 3);
			// Valkri & 3 Hero
			WriteValkri(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteValkri(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteValkri(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteValkri(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteValkri(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteValkri(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteValkri(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteValkri(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteValkri(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteValkri(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteValkri(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteValkri(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteValkri(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteValkri(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteValkri(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteValkri(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, Nangin, (PBYTE)"\xA9\x7A\x45\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, Nangin, (PBYTE)"\xA9\x7A\x45\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, Nangin, (PBYTE)"\xA9\x7A\x45\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, Nangin, (PBYTE)"\xA9\x7A\x45\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, Nangin, (PBYTE)"\xA9\x7A\x45\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, Nangin, (PBYTE)"\xA9\x7A\x45\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, Nangin, (PBYTE)"\xA9\x7A\x45\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, Nangin, (PBYTE)"\xA9\x7A\x45\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, Nangin, (PBYTE)"\xA9\x7A\x45\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, Nangin, (PBYTE)"\xA9\x7A\x45\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, Nangin, (PBYTE)"\xA9\x7A\x45\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, Nangin, (PBYTE)"\xA9\x7A\x45\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, Nangin, (PBYTE)"\xA9\x7A\x45\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, Nangin, (PBYTE)"\xA9\x7A\x45\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, Nangin, (PBYTE)"\xA9\x7A\x45\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, Nangin, (PBYTE)"\xA9\x7A\x45\xF5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, ThunderBird, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, ThunderBird, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, ThunderBird, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, ThunderBird, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, ThunderBird, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, ThunderBird, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, ThunderBird, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, ThunderBird, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, ThunderBird, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, ThunderBird, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, ThunderBird, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, ThunderBird, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, ThunderBird, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, ThunderBird, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, ThunderBird, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, ThunderBird, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			Write3Hero(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, Archanist, (PBYTE)"\xA9\x7A\x45\x5A", 4);
			Write3Hero(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, Archanist, (PBYTE)"\xA9\x7A\x45\x5A", 4);
			Write3Hero(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, Archanist, (PBYTE)"\xA9\x7A\x45\x5A", 4);
			Write3Hero(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, Archanist, (PBYTE)"\xA9\x7A\x45\x5A", 4);
			Write3Hero(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, Archanist, (PBYTE)"\xA9\x7A\x45\x5A", 4);
			Write3Hero(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, Archanist, (PBYTE)"\xA9\x7A\x45\x5A", 4);
			Write3Hero(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, Archanist, (PBYTE)"\xA9\x7A\x45\x5A", 4);
			Write3Hero(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, Archanist, (PBYTE)"\xA9\x7A\x45\x5A", 4);
			Write3Hero(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, Archanist, (PBYTE)"\xA9\x7A\x45\x5A", 4);
			Write3Hero(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, Archanist, (PBYTE)"\xA9\x7A\x45\x5A", 4);
			Write3Hero(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, Archanist, (PBYTE)"\xA9\x7A\x45\x5A", 4);
			Write3Hero(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, Archanist, (PBYTE)"\xA9\x7A\x45\x5A", 4);
			Write3Hero(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, Archanist, (PBYTE)"\xA9\x7A\x45\x5A", 4);
			Write3Hero(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, Archanist, (PBYTE)"\xA9\x7A\x45\x5A", 4);
			Write3Hero(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, Archanist, (PBYTE)"\xA9\x7A\x45\x5A", 4);
			Write3Hero(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, Archanist, (PBYTE)"\xA9\x7A\x45\x5A", 4);
			// Nangin
			WriteNangin(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, Nangin1, (PBYTE)"\x00\x00\x20\x40", 4);
			WriteNangin(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, Nangin1, (PBYTE)"\x00\x00\x20\x40", 4);
			WriteNangin(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, Nangin1, (PBYTE)"\x00\x00\x20\x40", 4);
			WriteNangin(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, Nangin1, (PBYTE)"\x00\x00\x20\x40", 4);
			WriteNangin(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, Nangin1, (PBYTE)"\x00\x00\x20\x40", 4);
			WriteNangin(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, Nangin1, (PBYTE)"\x00\x00\x20\x40", 4);
			WriteNangin(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, Nangin1, (PBYTE)"\x00\x00\x20\x40", 4);
			WriteNangin(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, Nangin1, (PBYTE)"\x00\x00\x20\x40", 4);
			WriteNangin(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, Nangin1, (PBYTE)"\x00\x00\x20\x40", 4);
			WriteNangin(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, Nangin1, (PBYTE)"\x00\x00\x20\x40", 4);
			WriteNangin(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, Nangin1, (PBYTE)"\x00\x00\x20\x40", 4);
			WriteNangin(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, Nangin1, (PBYTE)"\x00\x00\x20\x40", 4);
			WriteNangin(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, Nangin1, (PBYTE)"\x00\x00\x20\x40", 4);
			WriteNangin(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, Nangin1, (PBYTE)"\x00\x00\x20\x40", 4);
			WriteNangin(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, Nangin1, (PBYTE)"\x00\x00\x20\x40", 4);
			WriteNangin(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, Nangin1, (PBYTE)"\x00\x00\x20\x40", 4);
			WriteNangin(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, Nangin2, (PBYTE)"\x00\x00\xC8\x43", 4);
			WriteNangin(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, Nangin2, (PBYTE)"\x00\x00\xC8\x43", 4);
			WriteNangin(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, Nangin2, (PBYTE)"\x00\x00\xC8\x43", 4);
			WriteNangin(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, Nangin2, (PBYTE)"\x00\x00\xC8\x43", 4);
			WriteNangin(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, Nangin2, (PBYTE)"\x00\x00\xC8\x43", 4);
			WriteNangin(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, Nangin2, (PBYTE)"\x00\x00\xC8\x43", 4);
			WriteNangin(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, Nangin2, (PBYTE)"\x00\x00\xC8\x43", 4);
			WriteNangin(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, Nangin2, (PBYTE)"\x00\x00\xC8\x43", 4);
			WriteNangin(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, Nangin2, (PBYTE)"\x00\x00\xC8\x43", 4);
			WriteNangin(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, Nangin2, (PBYTE)"\x00\x00\xC8\x43", 4);
			WriteNangin(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, Nangin2, (PBYTE)"\x00\x00\xC8\x43", 4);
			WriteNangin(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, Nangin2, (PBYTE)"\x00\x00\xC8\x43", 4);
			WriteNangin(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, Nangin2, (PBYTE)"\x00\x00\xC8\x43", 4);
			WriteNangin(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, Nangin2, (PBYTE)"\x00\x00\xC8\x43", 4);
			WriteNangin(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, Nangin2, (PBYTE)"\x00\x00\xC8\x43", 4);
			WriteNangin(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, Nangin2, (PBYTE)"\x00\x00\xC8\x43", 4);
			// Jumper
			WriteJumper(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteJumper(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteJumper(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteJumper(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteJumper(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteJumper(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteJumper(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteJumper(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteJumper(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteJumper(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteJumper(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteJumper(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteJumper(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteJumper(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteJumper(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteJumper(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			// Alice
			WriteAlice(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteAlice(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteAlice(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteAlice(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteAlice(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteAlice(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteAlice(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteAlice(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteAlice(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteAlice(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteAlice(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteAlice(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteAlice(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteAlice(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteAlice(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			WriteAlice(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, VALKRI, (PBYTE)"\xA9\x4A\x00\xF5", 4);
			// Maid
			WriteMaid(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, Maid, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			WriteMaid(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, Maid, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			WriteMaid(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, Maid, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			WriteMaid(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, Maid, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			WriteMaid(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, Maid, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			WriteMaid(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, Maid, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			WriteMaid(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, Maid, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			WriteMaid(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, Maid, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			WriteMaid(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, Maid, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			WriteMaid(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, Maid, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			WriteMaid(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, Maid, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			WriteMaid(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, Maid, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			WriteMaid(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, Maid, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			WriteMaid(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, Maid, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			WriteMaid(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, Maid, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			WriteMaid(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, Maid, (PBYTE)"\xA9\x7A\x45\xB5", 4);
			// Mecha
			WriteMechanic(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, MECHA, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteMechanic(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, MECHA, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteMechanic(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, MECHA, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteMechanic(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, MECHA, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteMechanic(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, MECHA, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteMechanic(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, MECHA, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteMechanic(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, MECHA, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteMechanic(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, MECHA, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteMechanic(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, MECHA, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteMechanic(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, MECHA, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteMechanic(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, MECHA, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteMechanic(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, MECHA, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteMechanic(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, MECHA, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteMechanic(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, MECHA, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteMechanic(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, MECHA, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteMechanic(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, MECHA, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			// Lucifer
			WriteLucifer(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, LUCIFER, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteLucifer(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, LUCIFER, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteLucifer(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, LUCIFER, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteLucifer(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, LUCIFER, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteLucifer(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, LUCIFER, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteLucifer(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, LUCIFER, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteLucifer(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, LUCIFER, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteLucifer(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, LUCIFER, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteLucifer(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, LUCIFER, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteLucifer(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, LUCIFER, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteLucifer(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, LUCIFER, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteLucifer(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, LUCIFER, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteLucifer(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, LUCIFER, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteLucifer(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, LUCIFER, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteLucifer(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, LUCIFER, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteLucifer(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, LUCIFER, (PBYTE)"\xA9\x7A\x28\xF5", 4);
		    // Destro
			WriteDestroyer(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			// Ammo HGD
			WriteHgd(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, HGD, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteHgd(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, HGD, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteHgd(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, HGD, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteHgd(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, HGD, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteHgd(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, HGD, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteHgd(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, HGD, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteHgd(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, HGD, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteHgd(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, HGD, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteHgd(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, HGD, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteHgd(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, HGD, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteHgd(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, HGD, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteHgd(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, HGD, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteHgd(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, HGD, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteHgd(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, HGD, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteHgd(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, HGD, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteHgd(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, HGD, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			// Ammo Mikael
			WriteMikael(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, Mikail, (PBYTE)"\xA8\x3A\x77\x19", 4);
			WriteMikael(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, Mikail, (PBYTE)"\xA8\x3A\x77\x19", 4);
			WriteMikael(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, Mikail, (PBYTE)"\xA8\x3A\x77\x19", 4);
			WriteMikael(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, Mikail, (PBYTE)"\xA8\x3A\x77\x19", 4);
			WriteMikael(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, Mikail, (PBYTE)"\xA8\x3A\x77\x19", 4);
			WriteMikael(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, Mikail, (PBYTE)"\xA8\x3A\x77\x19", 4);
			WriteMikael(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, Mikail, (PBYTE)"\xA8\x3A\x77\x19", 4);
			WriteMikael(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, Mikail, (PBYTE)"\xA8\x3A\x77\x19", 4);
			WriteMikael(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, Mikail, (PBYTE)"\xA8\x3A\x77\x19", 4);
			WriteMikael(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, Mikail, (PBYTE)"\xA8\x3A\x77\x19", 4);
			WriteMikael(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, Mikail, (PBYTE)"\xA8\x3A\x77\x19", 4);
			WriteMikael(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, Mikail, (PBYTE)"\xA8\x3A\x77\x19", 4);
			WriteMikael(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, Mikail, (PBYTE)"\xA8\x3A\x77\x19", 4);
			WriteMikael(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, Mikail, (PBYTE)"\xA8\x3A\x77\x19", 4);
			WriteMikael(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, Mikail, (PBYTE)"\xA8\x3A\x77\x19", 4);
			WriteMikael(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, Mikail, (PBYTE)"\xA8\x3A\x77\x19", 4);
			//Ammo TT
			WriteTarantula(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			//Strider Parameter
			WriteStrider(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, Strider, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteStrider(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, Strider, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteStrider(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, Strider, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteStrider(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, Strider, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteStrider(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, Strider, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteStrider(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, Strider, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteStrider(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, Strider, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteStrider(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, Strider, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteStrider(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, Strider, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteStrider(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, Strider, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteStrider(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, Strider, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteStrider(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, Strider, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteStrider(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, Strider, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
		    WriteStrider(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, Strider, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteStrider(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, Strider, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
			WriteStrider(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, Strider, (PBYTE)"\xA8\x3A\x1E\xB1", 4);
		}
if (GetAsyncKeyState(VK_F20) & 1)Speed = !Speed;
		{
			if(Speed == true)
			{
			Function_6(XP1, XP2, XP3, OFS_1, BASE1, BASE2, SPEED, (PBYTE)"\x2A\x97\x0C\x13", 4);
			Function_6(XP1, XP2, XP3, OFS_2, BASE1, BASE2, SPEED, (PBYTE)"\x2A\x97\x0C\x13", 4);
			Function_6(XP1, XP2, XP3, OFS_3, BASE1, BASE2, SPEED, (PBYTE)"\x2A\x97\x0C\x13", 4);
			Function_6(XP1, XP2, XP3, OFS_4, BASE1, BASE2, SPEED, (PBYTE)"\x2A\x97\x0C\x13", 4);
			Function_6(XP1, XP2, XP3, OFS_5, BASE1, BASE2, SPEED, (PBYTE)"\x2A\x97\x0C\x13", 4);
			Function_6(XP1, XP2, XP3, OFS_6, BASE1, BASE2, SPEED, (PBYTE)"\x2A\x97\x0C\x13", 4);
			Function_6(XP1, XP2, XP3, OFS_7, BASE1, BASE2, SPEED, (PBYTE)"\x2A\x97\x0C\x13", 4);
			Function_6(XP1, XP2, XP3, OFS_8, BASE1, BASE2, SPEED, (PBYTE)"\x2A\x97\x0C\x13", 4);
			Function_6(XP1, XP2, XP3, OFS_9, BASE1, BASE2, SPEED, (PBYTE)"\x2A\x97\x0C\x13", 4);
			Function_6(XP1, XP2, XP3, OFS_10, BASE1, BASE2, SPEED, (PBYTE)"\x2A\x97\x0C\x13", 4);
			Function_6(XP1, XP2, XP3, OFS_11, BASE1, BASE2, SPEED, (PBYTE)"\x2A\x97\x0C\x13", 4);
			Function_6(XP1, XP2, XP3, OFS_12, BASE1, BASE2, SPEED, (PBYTE)"\x2A\x97\x0C\x13", 4);
			Function_6(XP1, XP2, XP3, OFS_13, BASE1, BASE2, SPEED, (PBYTE)"\x2A\x97\x0C\x13", 4);
			Function_6(XP1, XP2, XP3, OFS_14, BASE1, BASE2, SPEED, (PBYTE)"\x2A\x97\x0C\x13", 4);
			Function_6(XP1, XP2, XP3, OFS_15, BASE1, BASE2, SPEED, (PBYTE)"\x2A\x97\x0C\x13", 4);
			Function_6(XP1, XP2, XP3, OFS_16, BASE1, BASE2, SPEED, (PBYTE)"\x2A\x97\x0C\x13", 4);
		}
		}
if (GetAsyncKeyState(VK_F21) & 0x1) Fast_Hit = !Fast_Hit;
		if (Fast_Hit)
		{
			Function_6(XP1, XP2, XP3, OFS_1, BASE1, BASE2, FAST_HIT, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_2, BASE1, BASE2, FAST_HIT, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_3, BASE1, BASE2, FAST_HIT, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_4, BASE1, BASE2, FAST_HIT, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_5, BASE1, BASE2, FAST_HIT, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_6, BASE1, BASE2, FAST_HIT, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_7, BASE1, BASE2, FAST_HIT, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_8, BASE1, BASE2, FAST_HIT, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_9, BASE1, BASE2, FAST_HIT, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_10, BASE1, BASE2, FAST_HIT, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_11, BASE1, BASE2, FAST_HIT, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_12, BASE1, BASE2, FAST_HIT, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_13, BASE1, BASE2, FAST_HIT, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_14, BASE1, BASE2, FAST_HIT, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_15, BASE1, BASE2, FAST_HIT, (PBYTE)"\x00", 1);
			Function_6(XP1, XP2, XP3, OFS_16, BASE1, BASE2, FAST_HIT, (PBYTE)"\x00", 1);
		}
		if (GetAsyncKeyState(VK_F22)&1)TeleportDG = !TeleportDG;
		{
		if(TeleportDG == true)
		{
		TELEPORT_SNOW (RM_1,RM_2,RM_3,RM_4,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,1175149482 );
		TELEPORT_SNOW (RM_1,RM_2,RM_3,RM_4,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,3298003180);
		TELEPORT_SNOW (XP1,XP2,XP3,OFS_1,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,1175149482 );
		TELEPORT_SNOW (XP1,XP2,XP3,OFS_1,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,3298003180);
		TELEPORT_SNOW (XP1,XP2,XP3,OFS_2,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,1175149482 );
		TELEPORT_SNOW (XP1,XP2,XP3,OFS_2,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,3298003180);
		TELEPORT_SNOW (XP1,XP2,XP3,OFS_3,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,1175149482 );
		TELEPORT_SNOW (XP1,XP2,XP3,OFS_3,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,3298003180);
		TELEPORT_SNOW (XP1,XP2,XP3,OFS_4,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,1175149482 );
		TELEPORT_SNOW (XP1,XP2,XP3,OFS_4,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,3298003180);
		TELEPORT_SECRET (RM_1,RM_2,RM_3,RM_4,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,1154843928   );
		TELEPORT_SECRET (RM_1,RM_2,RM_3,RM_4,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,1162523128);
		TELEPORT_SECRET (XP1,XP2,XP3,OFS_1,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,1154843928   );
		TELEPORT_SECRET (XP1,XP2,XP3,OFS_1,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,1162523128);
		TELEPORT_SECRET (XP1,XP2,XP3,OFS_2,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,1154843928   );
		TELEPORT_SECRET (XP1,XP2,XP3,OFS_2,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,1162523128);
		TELEPORT_SECRET (XP1,XP2,XP3,OFS_3,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,1154843928   );
		TELEPORT_SECRET (XP1,XP2,XP3,OFS_3,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,1162523128);
		TELEPORT_SECRET (XP1,XP2,XP3,OFS_4,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,1154843928   );
		TELEPORT_SECRET (XP1,XP2,XP3,OFS_4,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,1162523128);
		TELEPORT_FIRE (RM_1,RM_2,RM_3,RM_4,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,1167178355     );
		TELEPORT_FIRE (RM_1,RM_2,RM_3,RM_4,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,1135822016);
		TELEPORT_FIRE (XP1,XP2,XP3,OFS_1,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,1167178355     );
		TELEPORT_FIRE (XP1,XP2,XP3,OFS_1,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,1135822016);
		TELEPORT_FIRE (XP1,XP2,XP3,OFS_2,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,1167178355     );
		TELEPORT_FIRE (XP1,XP2,XP3,OFS_2,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,1135822016);
		TELEPORT_FIRE (XP1,XP2,XP3,OFS_3,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,1167178355     );
		TELEPORT_FIRE (XP1,XP2,XP3,OFS_3,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,1135822016);
		TELEPORT_FIRE (XP1,XP2,XP3,OFS_4,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,1167178355     );
		TELEPORT_FIRE (XP1,XP2,XP3,OFS_4,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,1135822016);
		TELEPORT_FOREST (RM_1,RM_2,RM_3,RM_4,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI, 1173053115     );
		TELEPORT_FOREST (RM_1,RM_2,RM_3,RM_4,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,3264348638);
		TELEPORT_FOREST (XP1,XP2,XP3,OFS_1,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI, 1173053115     );
		TELEPORT_FOREST (XP1,XP2,XP3,OFS_1,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,3264348638);
		TELEPORT_FOREST (XP1,XP2,XP3,OFS_2,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI, 1173053115     );
		TELEPORT_FOREST (XP1,XP2,XP3,OFS_2,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,3264348638);
		TELEPORT_FOREST (XP1,XP2,XP3,OFS_3,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI, 1173053115     );
		TELEPORT_FOREST (XP1,XP2,XP3,OFS_3,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,3264348638);
		TELEPORT_FOREST (XP1,XP2,XP3,OFS_4,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI, 1173053115     );
		TELEPORT_FOREST (XP1,XP2,XP3,OFS_4,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,3264348638);
		}
		}
		if (GetAsyncKeyState(VK_F23) & 0x1) Freeze_dg = !Freeze_dg;
		if (Freeze_dg)
		{
			Sleep(999999); // Berikan jeda
	        
			Deep(XP1, XP2, XP3, OFS_1, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_2, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_3, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_4, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_5, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_6, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_7, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_8, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_9, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_10, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_11, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_12, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_13, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_14, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_15, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_16, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_17, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_18, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_19, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_20, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_21, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_22, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_23, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_24, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_25, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_26, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_27, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_28, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_29, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_30, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_31, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_32, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_33, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_34, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_35, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_36, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_37, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_38, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_39, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_40, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_41, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_42, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_43, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_44, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_45, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_46, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_47, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_48, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_49, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_50, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_51, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_52, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_53, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_54, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_55, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_56, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_57, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_58, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_59, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_60, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_61, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_62, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_63, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_64, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_65, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_66, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_67, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Deep(XP1, XP2, XP3, OFS_68, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_1, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_2, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_3, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_4, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_5, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_6, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_7, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_8, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_9, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_10, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_11, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_12, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_13, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_14, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_15, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_16, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_17, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_18, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_19, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_20, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_21, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_22, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_23, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_24, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_25, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_26, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_27, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_28, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_29, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_30, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_31, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_32, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_33, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_34, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_35, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_36, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_37, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_38, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_39, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_40, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_41, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_42, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_43, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_44, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_45, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_46, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_47, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_48, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_49, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_50, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_51, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_52, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_53, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_54, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_55, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_56, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_57, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_58, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_59, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_60, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_61, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_62, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_63, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_64, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_65, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_66, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_67, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			SnowTown(XP1, XP2, XP3, OFS_68, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_1, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_2, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_3, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_4, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_5, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_6, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_7, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_8, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_9, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_10, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_11, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_12, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_13, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_14, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_15, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_16, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_17, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_18, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_19, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_20, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_21, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_22, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_23, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_24, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_25, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_26, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_27, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_28, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_29, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_30, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_31, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_32, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_33, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_34, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_35, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_36, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_37, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_38, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_39, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_40, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_41, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_42, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_43, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_44, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_45, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_46, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_47, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_48, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_49, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_50, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_51, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_52, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_53, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_54, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_55, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_56, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_57, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_58, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_59, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_60, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_61, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_62, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_63, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_64, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_65, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_66, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_67, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			Secret(XP1, XP2, XP3, OFS_68, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_1, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_2, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_3, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_4, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_5, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_6, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_7, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_8, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_9, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_10, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_11, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_12, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_13, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_14, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_15, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_16, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_17, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_18, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_19, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_20, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_21, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_22, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_23, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_24, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_25, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_26, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_27, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_28, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_29, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_30, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_31, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_32, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_33, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_34, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_35, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_36, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_37, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_38, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_39, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_40, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_41, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_42, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_43, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_44, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_45, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_46, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_47, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_48, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_49, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_50, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_51, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_52, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_53, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_54, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_55, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_56, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_57, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_58, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_59, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_60, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_61, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_62, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_63, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_64, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_65, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_66, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_67, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
			FireTemple(XP1, XP2, XP3, OFS_68, BASE1, BASE2, KILL1, (PBYTE)"\x24", 1);
		}
if(GetAsyncKeyState(VK_F24)&0x1) Magnet_Csd = !Magnet_Csd;
		if (Magnet_Csd)
		{
		MAGNETCSD (XP1,XP2,XP3,OFS_1,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_1,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_2,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_2,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_3,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_3,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_4,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_4,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_5,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_5,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_6,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_6,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_7,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_7,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_8,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_8,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_9,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_9,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_10,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_10,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_11,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_11,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_12,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_12,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_13,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_13,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_14,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_14,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_15,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_15,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_16,BASE1,BASE2,LOKASI1,LOKASI2,KANAN_KIRI,0);
		MAGNETCSD (XP1,XP2,XP3,OFS_16,BASE1,BASE2,LOKASI1,LOKASI2,ATAS_BAWAH,0);
		}
if (GetAsyncKeyState(VK_EREOF) & 0x1) RefillHP = !RefillHP;
		if (RefillHP)
		{
		if (GetAsyncKeyState(VK_TAB))
		{
			Function_6(RM_1, RM_2, RM_3, RM_4, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_1, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_2, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_3, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_4, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_5, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_6, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_7, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_8, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_9, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_10, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_11, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_12, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_13, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_14, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_15, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
			Function_6(XP1, XP2, XP3, OFS_16, BASE1, BASE2, HP1, (PBYTE)"\x29\xB9\x80\x2C", 4);
		}
		}
if (GetAsyncKeyState(VK_OEM_BACKTAB) & 0x1) NetCut = !NetCut;
		if (NetCut)
		{
			if(GetAsyncKeyState(VK_F9) & 0x1)
			{
			Function_6(XP1, XP2, XP3, OFS_1, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			Function_6(XP1, XP2, XP3, OFS_2, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			Function_6(XP1, XP2, XP3, OFS_3, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			Function_6(XP1, XP2, XP3, OFS_4, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			Function_6(XP1, XP2, XP3, OFS_5, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			Function_6(XP1, XP2, XP3, OFS_6, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			Function_6(XP1, XP2, XP3, OFS_7, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			Function_6(XP1, XP2, XP3, OFS_8, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			Function_6(XP1, XP2, XP3, OFS_9, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			Function_6(XP1, XP2, XP3, OFS_10, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			Function_6(XP1, XP2, XP3, OFS_11, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			Function_6(XP1, XP2, XP3, OFS_12, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			Function_6(XP1, XP2, XP3, OFS_13, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			Function_6(XP1, XP2, XP3, OFS_14, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			Function_6(XP1, XP2, XP3, OFS_15, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			Function_6(XP1, XP2, XP3, OFS_16, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			}
		}
if (GetAsyncKeyState(VK_OEM_WSCTRL) & 0x1) Quake = !Quake;
		if (Quake)
		{
			WriteQuakeMain(XP1, XP2, XP3, OFS_1, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_2, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_3, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_4, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_5, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_6, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_7, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_8, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_9, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_10, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_11, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_12, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_13, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_14, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_15, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_16, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_17, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_18, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_19, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_20, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_21, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_22, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_23, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_24, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_25, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_26, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_27, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_28, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_29, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_30, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_31, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_32, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_33, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_34, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_35, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_36, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_37, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_38, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_39, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_40, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_41, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_42, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_43, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_44, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_45, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_46, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_47, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_48, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_49, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_50, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_51, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_52, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_53, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_54, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_55, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_56, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_57, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_58, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_59, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_60, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_61, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_62, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_63, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_64, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_65, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_66, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_67, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeMain(XP1, XP2, XP3, OFS_68, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_1, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_2, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_3, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_4, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_5, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_6, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_7, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_8, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_9, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_10, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_11, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_12, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_13, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_14, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_15, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_16, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_17, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_18, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_19, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_20, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_21, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_22, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_23, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_24, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_25, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_26, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_27, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_28, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_29, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_30, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_31, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_32, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_33, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_34, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_35, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_36, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_37, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_38, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_39, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_40, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_41, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_42, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_43, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_44, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_45, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_46, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_47, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_48, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_49, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_50, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_51, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_52, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_53, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_54, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_55, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_56, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_57, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_58, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_59, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_60, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_61, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_62, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_63, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_64, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_65, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_66, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_67, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeDeep(XP1, XP2, XP3, OFS_68, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_1, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_2, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_3, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_4, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_5, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_6, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_7, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_8, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_9, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_10, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_11, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_12, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_13, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_14, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_15, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_16, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_17, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_18, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_19, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_20, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_21, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_22, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_23, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_24, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_25, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_26, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_27, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_28, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_29, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_30, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_31, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_32, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_33, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_34, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_35, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_36, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_37, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_38, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_39, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_40, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_41, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_42, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_43, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_44, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_45, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_46, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_47, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_48, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_49, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_50, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_51, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_52, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_53, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_54, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_55, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_56, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_57, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_58, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_59, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_60, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_61, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_62, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_63, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_64, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_65, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_66, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_67, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSnow(XP1, XP2, XP3, OFS_68, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_1, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_2, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_3, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_4, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_5, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_6, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_7, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_8, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_9, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_10, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_11, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_12, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_13, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_14, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_15, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_16, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_17, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_18, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_19, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_20, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_21, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_22, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_23, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_24, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_25, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_26, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_27, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_28, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_29, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_30, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_31, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_32, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_33, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_34, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_35, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_36, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_37, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_38, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_39, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_40, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_41, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_42, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_43, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_44, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_45, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_46, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_47, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_48, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_49, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_50, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_51, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_52, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_53, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_54, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_55, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_56, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_57, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_58, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_59, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_60, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_61, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_62, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_63, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_64, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_65, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_66, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_67, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeSecret(XP1, XP2, XP3, OFS_68, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_1, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_2, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_3, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_4, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_5, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_6, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_7, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_8, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_9, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_10, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_11, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_12, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_13, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_14, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_15, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_16, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_17, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_18, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_19, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_20, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_21, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_22, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_23, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_24, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_25, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_26, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_27, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_28, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_29, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_30, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_31, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_32, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_33, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_34, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_35, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_36, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_37, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_38, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_39, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_40, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_41, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_42, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_43, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_44, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_45, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_46, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_47, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_48, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_49, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_50, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_51, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_52, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_53, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_54, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_55, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_56, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_57, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_58, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_59, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_60, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_61, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_62, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_63, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_64, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_65, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_66, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_67, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
			WriteQuakeFire(XP1, XP2, XP3, OFS_68, BASE1, BASE2, KILL1, (PBYTE)"\x25", 1);
		}
if (GetAsyncKeyState(VK_OEM_FJ_JISHO) & 0x1) RefillT = !RefillT;
		if (RefillT)
		{
			Refill_Token(XP1, XP2, RM_2, TOKEN, -100);
		}
if (GetAsyncKeyState(VK_F2) & 0x1) RefillT = !RefillT;
		if (RefillT)
		{
			Refill_Token(XP1, XP2, RM_2, TOKEN, 100);
		}
		Sleep(10); // Berikan jeda
	}
	return (0); // unhook
}
DWORD FUCK(LPVOID param)
{
while (1)
	{
		Sleep(20);
	if(GetAsyncKeyState(VK_BROWSER_FAVORITES) & 0x1) Brust_Mafia = !Brust_Mafia;
		if (Brust_Mafia)
		{
	//	Sleep(10);
			//Brust Mafia
			WriteMafia(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, MF, (PBYTE)"\x93\x93", 2);
			WriteMafia(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, MF, (PBYTE)"\x93\x93", 2);
			WriteMafia(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, MF, (PBYTE)"\x93\x93", 2);
			WriteMafia(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, MF, (PBYTE)"\x93\x93", 2);
			WriteMafia(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, MF, (PBYTE)"\x93\x93", 2);
			WriteMafia(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, MF, (PBYTE)"\x93\x93", 2);
			WriteMafia(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, MF, (PBYTE)"\x93\x93", 2);
			WriteMafia(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, MF, (PBYTE)"\x93\x93", 2);
			WriteMafia(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, MF, (PBYTE)"\x93\x93", 2);
			WriteMafia(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, MF, (PBYTE)"\x93\x93", 2);
			WriteMafia(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, MF, (PBYTE)"\x93\x93", 2);
			WriteMafia(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, MF, (PBYTE)"\x93\x93", 2);
			WriteMafia(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, MF, (PBYTE)"\x93\x93", 2);
			WriteMafia(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, MF, (PBYTE)"\x93\x93", 2);
			WriteMafia(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, MF, (PBYTE)"\x93\x93", 2);
			WriteMafia(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, MF, (PBYTE)"\x93\x93", 2);
			WriteMafia(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, MF1, (PBYTE)"\x00", 1);
			WriteMafia(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, MF1, (PBYTE)"\x00", 1);
			WriteMafia(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, MF1, (PBYTE)"\x00", 1);
			WriteMafia(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, MF1, (PBYTE)"\x00", 1);
			WriteMafia(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, MF1, (PBYTE)"\x00", 1);
			WriteMafia(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, MF1, (PBYTE)"\x00", 1);
			WriteMafia(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, MF1, (PBYTE)"\x00", 1);
			WriteMafia(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, MF1, (PBYTE)"\x00", 1);
			WriteMafia(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, MF1, (PBYTE)"\x00", 1);
			WriteMafia(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, MF1, (PBYTE)"\x00", 1);
			WriteMafia(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, MF1, (PBYTE)"\x00", 1);
			WriteMafia(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, MF1, (PBYTE)"\x00", 1);
			WriteMafia(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, MF1, (PBYTE)"\x00", 1);
			WriteMafia(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, MF1, (PBYTE)"\x00", 1);
			WriteMafia(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, MF1, (PBYTE)"\x00", 1);
			WriteMafia(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, MF1, (PBYTE)"\x00", 1);
			WriteMafia(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, MF2, (PBYTE)"\x00\x00\x00", 3);
			WriteMafia(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, MF2, (PBYTE)"\x00\x00\x00", 3);
			WriteMafia(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, MF2, (PBYTE)"\x00\x00\x00", 3);
			WriteMafia(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, MF2, (PBYTE)"\x00\x00\x00", 3);
			WriteMafia(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, MF2, (PBYTE)"\x00\x00\x00", 3);
			WriteMafia(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, MF2, (PBYTE)"\x00\x00\x00", 3);
			WriteMafia(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, MF2, (PBYTE)"\x00\x00\x00", 3);
			WriteMafia(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, MF2, (PBYTE)"\x00\x00\x00", 3);
			WriteMafia(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, MF2, (PBYTE)"\x00\x00\x00", 3);
			WriteMafia(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, MF2, (PBYTE)"\x00\x00\x00", 3);
			WriteMafia(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, MF2, (PBYTE)"\x00\x00\x00", 3);
			WriteMafia(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, MF2, (PBYTE)"\x00\x00\x00", 3);
			WriteMafia(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, MF2, (PBYTE)"\x00\x00\x00", 3);
			WriteMafia(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, MF2, (PBYTE)"\x00\x00\x00", 3);
			WriteMafia(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, MF2, (PBYTE)"\x00\x00\x00", 3);

			//Chaos

			WriteChaos(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);
			WriteChaos(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, Chaos, (PBYTE)"\x02", 1);

			// Musketer


			WriteMusketer(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);
			WriteMusketer(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, MSK1, (PBYTE)"\x03", 1);

			//Troper

			WriteTroper(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);
			WriteTroper(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, TRP1, (PBYTE)"\x03", 1);


			WriteTroper(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);
			WriteTroper(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, TRP, (PBYTE)"\x88\x7B\x1D\x91", 4);


			//Cowboy
			WriteCowboy(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);
			WriteCowboy(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, COWBOY, (PBYTE)"\x03", 1);

			// Robin


			WriteRobin(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);
			WriteRobin(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, ROBINHOOD, (PBYTE)"\x02", 1);


			// S force


			WriteForce(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);
			WriteForce(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, SForce, (PBYTE)"\x03", 1);


			//Brust Destro


			WriteDestroyer(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);
			WriteDestroyer(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, DESTRO, (PBYTE)"\xA9\x7A\x28\xF5", 4);

			WriteDestroyerBrust(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);
			WriteDestroyerBrust(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, BRUSTDESTRO, (PBYTE)"\x06", 1);


			//Brust TT

			WriteTarantula(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);
			WriteTarantula(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, TT, (PBYTE)"\x33\x33", 2);

			WriteTarantula(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);
			WriteTarantula(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, TT1, (PBYTE)"\x01", 1);

			//Brust Kali
			WriteKali(XP1, XP2, XP3, OFS_1, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_2, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_3, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_4, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_5, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_6, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_7, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_8, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_9, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_10, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_11, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_12, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_13, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_14, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_15, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
			WriteKali(XP1, XP2, XP3, OFS_16, SKILL1, BASE2, SKILL1, SD, Kali, (PBYTE)"\x02", 1);
		


			
		}
		Sleep(10); // Berikan jeda
	}
	return (0); // unhook
}