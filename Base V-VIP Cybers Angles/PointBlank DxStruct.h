//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
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

#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma once using namespace std;


class PlayerInfo;
class RenderContext;
class RenderData;
class CGameBase;
class CBonesContext;
class CBone;
class cGameStageInfo;

struct CPlayers
{
    float yaw;
    float pitch;
    D3DXVECTOR3 pos;
    char unkno8[2304];
};

struct CTeam
{
	BYTE iTeam;
};
struct CHealth
{
 float CurHP;
};

//=========================================================================//

struct CRank
{
	BYTE iRank;
};

struct CNames
{
    char szNames[33];
};

//=========================================================================//

class cGameStageInfo
{
public:
char _pad1[0x230];
D3DXVECTOR3 BombPositionA; 
D3DXVECTOR3 BombPositionB;
};
class cGameBases
{
public:
char _pad1[0x3B7C4];
cGameStageInfo* StageInfo;
};

//=========================================================================//

class PlayerInfo
{
public:
D3DXVECTOR3 origin;
};

//=========================================================================//

class RenderContext
{
public:
	RenderData* pRenderData; 
	char unknown4[912];
	D3DXVECTOR3 bone;
	D3DXVECTOR3 bone1;
	D3DXVECTOR3 bone2;
};

//=========================================================================//

class RenderData
{
public:
	char unknown0[32]; 
	D3DXMATRIX ViewMatrix;
	D3DXMATRIX ProjMatrix;
	char _0x00A0[4736];
	D3DXMATRIX World; 
	D3DXMATRIX WorldView[80];
};
//=========================================================================//

class Bone
{
public:
D3DXMATRIX m_Bone;
};

//=========================================================================//
class CGameCharaBoneContext
{
public:
char nop[0xC8];
Bone* m_Bone;
};

//=========================================================================//
class CGameCharaBase
{
public:
char nop[0x558];
CGameCharaBoneContext* m_BoneContext;
};

//=========================================================================//

class CBone
{
public:
D3DXMATRIX BoneMatrix;
};

//=========================================================================//

class CBonesContext
{
public:
char Unk[0xC8];
CBone* BoneData;
};

extern RenderContext *pRC;
