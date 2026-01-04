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
#define OFS_Player		0x7C8480
#define OFS_Player2		0xBC8480
#define OFS_Weapon		0x7C8464
#define OFS_Weapon2		0xBC8464
#define OFS_Health		0x7C844C
#define OFS_Health2		0xBC844C
#define OFS_Ammo		0x7C8448
#define OFS_Ammo2		0xBC8448
//================ g-c ================//
#define g_pPlayerBase		0x7C8480
#define c_pPlayerBase		0xBC8480
#define g_pPelorReload		0x7C8448
#define c_pPelorReload		0xBC8448
#define g_pPlayerRespon		0x7C8478
#define c_pPlayerRespon		0xBC8478
#define g_pESP				0x7C844C
#define c_pESP				0xBC844C
#define OFS_AmmoRoll        0xBEA984  // 258C71 //EB 05 E9 ?? ?? ?? ?? 8B 55 FC 89
//--------------------------------------------------------------------
#define ResultBasePlayer	(OFS_Player)
#define ResultBasePlayer2	(OFS_Player2)
#define ResultBaseHealth	(OFS_Health)
#define ResultBaseHealth2	(OFS_Health2)
#define ResultBaseAmmo	    (OFS_Ammo)
#define ResultBaseAmmo2	    (OFS_Ammo2)
//--------------------------------------------------------------------
#define PTRQuick		   0x540
#define PTRWeaponSize1Ammo 0x1C
#define PTRWeaponSize2Ammo 0x544
#define SizeValAmmo		   0xCA8
#define PTRSizePlayer      0x260
#define PTRSizeVal2        0x264
#define PTRSizeHealth      0x24
#define PTRAmmoKiri        0xC98
//--------------------------------------------------------------------
#define PointBaseBullet           0x601A84 // 93 A7 00 68 32 00 00 + 400000
//--------------------------------------------------------------------
//--------------------------------------------------------------------
#define OFS_TEAM		              0x299F4 //Wes
#define P_BaseTEAM		              0x299F4 // OFS_Team Wes
#define P_BasePLAYER	              0x2C54C // OFS_Bone Wes
#define OFS_NAMES                     0x295D4 //Wes
#define OFS_RANK                      0x27D90 //Wes
#define OFS_RANK2	         (OFS_RANK + 0x1) //Wes
#define PTR_HEALTH		0x264
#define OFS_PlantBomb				  0x3B9A8
#define PTR_BombArea				  0x230
//--------------------------------------------------------------------
#define OFS_Suicide         0x2A31C0 // 55 8B EC 83 EC 74 89 4D AC 51 D9 E8 D9 1C 24 51 D9 EE D9 1C 24 51 D9 EE D9 1C 24 8D 45 F0 50 E8 6C 57 E2 FF 83 C4 10 8B 0D DC E3 BD 00
//--------------------------------------------------------------------
//--------------------------------------------------------------------
#define OFS_Primary         0x28178
#define OFS_Melee           0x28028
#define OFS_Secondary       0x2817C
#define OFS_Special         0x2802C
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