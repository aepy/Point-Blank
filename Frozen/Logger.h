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
//yg cukup diedit dari sini. dari sini
#define g_pPlayerBase			0x7B6C40//Player	       
#define c_pPlayerBase			0xBB6C40//Player2		        
#define g_pESP					0x7B6C0C//Healt		       <== waktu itu pernah di ganti , tapi cuman yang ada aja
#define c_pESP					0xBB6C0C//Healt2		        
#define pGetCalculateAmmo		0xBB81AC//Peler  jadi yang di rubah
#define g_pPelorReload			0x7B6C08//Ammo		       
#define c_pPelorReload			0xBB6C08//Ammo2		
#define BaseRizkyAmmoSemvax2  0xBB6C08    //OFS_Ammo2
#define c_pPlayerRespon			0xBB6C08 //*/nih ane gak tau Ini offset apaan/ammo2 
#define OFS_NAMES 0x296BC
//sampai sini. sampai sini
//--------------------------------//
#define P_BasePLAYER	   0x7B6C40 //Ini base Player? <<= sama ini ini base player? iya
#define PTRWeaponSize1Ammo 0x1C// gausah .. Bang misalnya saya nemuin base SCnye belom di edit , ata
#define PTRWeaponSize2Ammo 0x548//gausah
#define SizeValAmmo		   0xCA0//gausah
#define NAMESIZE   0x21//gausah?
//dari sini.ini ga usah.
#define PointBaseBullet 0x57FFAC//gausah
#define PointBaseAutoShot 0x57FA08// ini offset dari aim biar aim work., kan di base ini ga ada aim
#define PointBaseAimLockX 0x57FA28//gausah
#define PointBaseAimLockY 0x57FA2C// ini? kalau di rubah ini apaan?base Off_AIMLock// gaada , emang itu hrs di rbh jg?
//sMpai sini
#define PTRSizePlayer	  0x260//gausah
#define PTRSizeVal2       0x264//gausah
#define PTRSizeHealth     0x20//gausah
#define P_BaseTEAM		0x29AE0 //dan ini, klobPTR sistem ny permanen, kbah. Off_TEAM . dan ini.
