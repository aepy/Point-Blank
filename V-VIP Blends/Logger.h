#include <windows.h>
#include <windows.h>
#include <string>
#include <d3d9.h>
#include <d3dx9.h>
#include <tchar.h>
#include <iostream>
#include <d3dx9math.h>
#include <fstream>
#include <time.h>
#include <vector>
#include <math.h>
#include <fstream>
#include <cmath>
#pragma warning(disable:4244)
#pragma warning(disable:4700)
#pragma warning(disable:4996)
using namespace std;ofstream infile;
char *GetDirectoryFile(char *filename);
char dlldir[320];
DWORD g_PlayerBase,I3PTRPrim,I3PTRSec,GetPTRBarret,g_Team,g_Player,ResultTeam,g_ESP,g_WinMode,ResultNET,GetCalculateAmmo,OffsetDeltaX,OffButtonState,OffsetDeltaY,OffsetSetEnd,g_PTRNameTag,g_SuicideCCD,g_FloodVk,SkillDamage,SkillShot,ResultPlayerDamage,ResultNameTag,g_STRHACKER,ResultPlayerHit,
ResultPlayerShot,ResultClac,SkillHit,g_EXIT,c_ESP,g_PelorReload,ResultPlayerSize,g_PTRSkill,c_PlayerRespon,c_PelorReload,c_PlayerBase,dwStartAddress,dwSize,dwSize2,ResultBase;

//============== Addres ===============//
#define OFS_HEALTH  resultOFS_HEALTH // - 34 = bombposition
#define OFS_Player			0x7D1800
#define OFS_Player2		0xBD1800
#define OFS_Weapon		0x7D17E4
#define OFS_Weapon2		0xBD17E4
#define OFS_Health			0x7D17CC
#define OFS_Health2		0xBD17CC
#define OFS_Ammo			0x7D17C8
#define OFS_Ammo2		0xBD17C8
//================ g-c ================//
#define g_pPlayerBase		(OFS_Player)
#define c_pPlayerBase		(OFS_Player2)
#define g_pPelorReload		(OFS_Ammo)
#define c_pPelorReload		(OFS_Ammo2)
#define g_pPlayerRespon		0x7D17F8
#define c_pPlayerRespon		0xBD17F8
#define g_pESP				(OFS_Health)
#define c_pESP				(OFS_Health2)
#define OFS_AmmoRoll            0xBEA984  // 258C71 //EB 05 E9 ?? ?? ?? ?? 8B 55 FC 89

//============== Result===============//
#define ResultBasePlayer	(OFS_Player)
#define ResultBasePlayer2	(OFS_Player2)
#define ResultBaseHealth	(OFS_Health)
#define ResultBaseHealth2	(OFS_Health2)
#define ResultBaseAmmo	    (OFS_Ammo)
#define ResultBaseAmmo2	    (OFS_Ammo2)

//=========== PTR ============//
#define PTRQuick		   0x540
#define PTRWeaponSize1Ammo 0x1C
#define PTRWeaponSize2Ammo 0x544
#define SizeValAmmo		   0xCA8
#define PTRSizePlayer      0x260
#define PTRSizeVal2        0x264
#define PTRSizeHealth      0x24
#define PTRAmmoKiri        0xC98
//================ AIM =================//
#define PointBaseBullet           0x608A74 
//====================WP SMOKE====================//
#define WriteGameEvent_fire				0x8F0AD0
#define getVirtualCamPosition			0x727A30
#define DoLineCollision					0x58DD10
//================= Player =================//
#define OFS_TEAM		              0x299F4
#define P_BaseTEAM		              0x299F4 // OFS_Team
#define P_BasePLAYER	              0x27B24 // OFS_Bone
#define OFS_BONE					  0x2C54C
#define OFS_NAMES                     0x295D4
#define OFS_RANK                      0x27D90
#define OFS_RANK2	         (OFS_RANK + 0x1)

//================= Other ==================//
#define OFS_WTW1                      0x110A3 // Aob = 89 41 68 C3 CC CC
#define OFS_WTW2                      0x16512
#define OFS_WTW3                      0x16510 // Aob = 89 8B 34 01 00 00
//#define OFS_Gravity         0x62B28D
#define OFS_Wallshot        0x188087
#define OFS_Unyu            0x695BCF // BE 43 47
#define OFS_Suicide         0x2A72C0 // 55 8B EC 83 EC 74 89 4D AC 51 D9 E8 D9 1C 24 51 D9 EE D9 1C 24 51 D9 EE D9 1C 24 8D 45 F0 50 E8 6C 57 E2 FF 83 C4 10 8B 0D DC E3 BD 00
#define OFS_AimDatar        0x6384E0 // Aob = 00 00 00 20 6C C1 76 3F

//====================== Reaplace Weapon ===============================//
#define OFS_Primary			0x28178
#define OFS_Secondary		0x2817C
#define OFS_Melee			0x28180
#define OFS_Explosive		0x28184
#define OFS_Special			0x28188
//--------------------------------------------------------------------
#define Aug_A3_G            0x5F5ECDC
#define AK_Sopmod           0x5F5ECC7
#define Famas_M203          0x5F5ECEC
#define AK47_FC             0x5F5ECF2
#define AUG_A3_GSL          0x5F5ED20
//--------------------------------------------------------------------
#define Kriss_SVD           0xBEBD1BF
#define P90_Ext_D           0xBEBD1BD
#define Dual_Uzzi           0xBEC0857
#define KrissBatik_D        0xBEBD1CF
#define MP7_D               0xBEBD1CD
//--------------------------------------------------------------------
#define RangeMaster_STBY    0x11E1B69F
#define CheyTac_M200        0x11E1B6A6
#define Barrett_M82A1       0x11E1B6A8
#define L115A1              0x11E1B699
#define Winchester          0x11E1B6A7
//--------------------------------------------------------------------
#define M1887               0x6451BC //
#define SPASS_SI            0x17D79B79
#define SG_Silver           0x17D79B85
#define SPASS_MCS           0x17D79B82
#define Jack_Hammer         0x17D79B83
//--------------------------------------------------------------------
#define BaseVK		resultBaseVK
#define BaseVK2     resultBaseVK2 // - 20 = BGhost2



//------------------------------------ PTR . Weapon Size 544 --------------------------------------------------
/*
00517533  |. 83B8 44050000 >CMP DWORD PTR DS:[EAX+544],0
0051753A  |. 75 2A          JNZ SHORT Dumped.00517566
0051753C  |. 6A 00          PUSH 0
0051753E  |. 68 E8F8A200    PUSH 00A2F8E8                     ;  ASCII "void __thiscall CGameCharaBase::Create(class i3GameResChara *,struct _tagCharaInfo *,const class CCharaInfo *)"
00517543  |. 68 5D010000    PUSH 15D
00517548  |. 6A 00          PUSH 0
*/

//------------------------------------ PTR . Weapon Size 554 --------------------------------------------------
/*
005177F6  |. 83BA 54050000 >CMP DWORD PTR DS:[EDX+554],0
005177FD  |. 75 2A          JNZ SHORT Dumped.00517829
005177FF  |. 6A 00          PUSH 0
00517801  |. 68 08FDA200    PUSH 00A2FD08                     ;  ASCII "void __thiscall CGameCharaBase::Create(class i3GameResChara *,struct _tagCharaInfo *,const class CCharaInfo *)"
00517806  |. 68 7A010000    PUSH 17A
0051780B  |. 6A 00          PUSH 0
*/

//------------------------------- PTR . ESP Size Game Chara Base 558 ------------------------------------------
/*
0051785B  |. 83BA 58050000 >CMP DWORD PTR DS:[EDX+558],0
00517862  |. 75 2A          JNZ SHORT Dumped.0051788E
00517864  |. 6A 00          PUSH 0
00517866  |. 68 A8FDA200    PUSH 00A2FDA8                     ;  ASCII "void __thiscall CGameCharaBase::Create(class i3GameResChara *,struct _tagCharaInfo *,const class CCharaInfo *)"
0051786B  |. 68 7E010000    PUSH 17E
00517870  |. 6A 00          PUSH 0
*/

//------------------------------------ PTR . PLAYER 560 -------------------------------------------------------
/*
00517925  |. 83BA 60050000 >CMP DWORD PTR DS:[EDX+560],0
0051792C  |. 75 2A          JNZ SHORT Dumped.00517958
0051792E  |. 6A 00          PUSH 0
00517930  |. 68 D8FEA200    PUSH 00A2FED8                     ;  ASCII "void __thiscall CGameCharaBase::Create(class i3GameResChara *,struct _tagCharaInfo *,const class CCharaInfo *)"
00517935  |. 68 86010000    PUSH 186
0051793A  |. 6A 00          PUSH 0
*/