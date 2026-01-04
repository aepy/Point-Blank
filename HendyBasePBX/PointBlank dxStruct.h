//==================================================================================================================================//
//											AUTHOR	: M. Hendy																		//											  
//											Me      : M. Hendy
//											RELEASE : Kreasi Sendiri ^_^																	//
//											WEB		: Palembang-Community.blogspot.com													//
//																																	//
//										    NO SHARE TO PUBLIC || BASE RESMI Muhammad Hendy											//
//==================================================================================================================================//

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

#define _CRT_SECURE_NO_WARNINGS

#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma once using namespace std;


class PlayerInfo;
class RenderContext;
class RenderData;
class CInMouse;
class CGameBase;
class CBonesContext;
class CBone;

struct CPlayers
{
    float yaw;
    float pitch;
    D3DXVECTOR3 pos;
    char unkno8[2544];//
};
int AutoShoot;
struct CTeam
{
	BYTE iTeam;
};
struct CHealth
{
 float CurHP;
};
bool Shot = false;
class CSlot
{
public:
BYTE iSlot;
};
class CDWORD; 
class CDWORD 
{ 
public: 
	DWORD dwRes; 
}; 
class CWORD; 
class CWORD 
{ 
public: 
WORD wRes; 
}; 
class CBYTE; 
class CBYTE { 
public: 
	BYTE bRes; 
}; 
class CSlotz; 
class CSlotz 
{ 
public: 
	DWORD Host; 
	DWORD Slot; 
};

DWORD CGameContextPointer(void) {	
	
	unsigned long dwBase = *(DWORD*)0xAFFFC0;//0xAE6878;
		return dwBase;
}
DWORD GetBasePlayerHealth(void) {	
	
	unsigned long dwBase2 = *(DWORD*)0xAFFF8C;//0xAE6844;
		return dwBase2;
}

class cHIT { 
public: 
	char _0x0000[116]; 
	DWORD Index; 
	CDWORD setHitType[64]; 
	char _0x0178[256]; 
	CWORD setHitWho[64]; 
	CBYTE setHitPart[64]; 
	CWORD setHitDamage[64]; 
	CBYTE setCriticalFlag[64]; 
	CBYTE setHelmetFlag[64]; 
	CDWORD setNetSlotInex[64]; 
	CDWORD setWeaponClass[64]; 
	CBYTE setWeaponNumber[64]; 
	CDWORD setWeaponUsage[64]; 
	char _0x0778[768]; 
	CDWORD setDeathType[64]; 
	CBYTE setByObjectState[64]; 
	CWORD setByObjectIndex[64]; 
	char _0x0C38[1577]; 
};
struct CRank
{
	BYTE iRank;
};

struct CNames
{
    char szNames[33];
};

class CAimbot
{
public:
float yaw;
float pitch;
D3DXVECTOR3 pos;
char unkno8[2304];
};

class CNick
{
public:
BYTE bVal;
};

struct CAlive
{
	BYTE isAlive;
};


struct CSlotEquip	
{
	BYTE sloteq;
};
struct CStatus
{
	BYTE StatusPlayerr;
};
struct CisAlive
{
	int Isalive;
};

struct CWeapon
{
 int WpData;
};

class cGameStageInfo
{
public:
char _pad1[0x238];//0x0
D3DXVECTOR3 BombPositionA;//0x238
D3DXVECTOR3 BombPositionB;//0x244
char _pad2[0xF4];//0x250
float BombFloorOnMiniMap_A;
float BombFloorOnMiniMap_B;
float RespawnTime;//0x344
float RespawnTime4vs4;//0x348
float InvicibleTime;//0x34C
float InvicibleTime4vs4;//0x350
};

class PlayerInfo
{
public:
D3DXVECTOR3 origin;
};

class RenderContext
{
public:
	RenderData* pRenderData; 
	char unknown4[916];
	D3DXVECTOR3 bone;
	D3DXVECTOR3 bone1;
	D3DXVECTOR3 bone2;
};

class RenderData
{
public:
	char unknown0[2240];
	D3DXMATRIX ViewMatrix;
	D3DXMATRIX ProjMatrix;
	D3DXMATRIX World; 
	D3DXMATRIX WorldView[80];
};

class CChara
{
public:
BYTE Number;
};
class Bone
{
public:
D3DXMATRIX m_Bone;
};

class CGameCharaBoneContext
{
public:
char nop[0xE8];
Bone* m_Bone;
};

class CGameCharaBase
{
public:
char nop[0x158];
CGameCharaBoneContext* m_BoneContext;
};

class CBone
{
public:
D3DXMATRIX BoneMatrix;
};

class CBonesContext
{
public:
char Unk[0xE8];
CBone* BoneData;
};

class CVisible
{
public:
char Unk[0x158];
bool Visible;
};



extern RenderContext *pRC;
