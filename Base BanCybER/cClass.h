/*cClass.h PBHacks Last Edit By BanCyberz Hacks*/

/*-------------------------------------------------------------------------------------------------------------------*/
#include <windows.h>
#include "AutoLogger.h"

LPD3DXLINE pLine    = NULL;
LPD3DXFONT fName	= NULL;
LPD3DXFONT fSmall	= NULL;
LPD3DXFONT Title    = NULL;
LPD3DXFONT      g_pFont = NULL;
LPD3DXFONT      g_pFont2 = NULL;
LPD3DXLINE      g_Line = NULL;
D3DVIEWPORT9    g_ViewPort;
LPDIRECT3DDEVICE9 pDevice;
D3DVIEWPORT9 Viewport;
/*-------------------------------------------------------------------------------------------------------------------*/
class GM;
class PlayerInfo;
class RenderContext;
class RenderData;
class CGameBase;
class CBonesContext;
class CBone;
class cGameStageInfo;

DWORD g_pRenderContextx = (DWORD)GetProcAddress(GetModuleHandleA(PBi3Gfxx), g_pRender);
RenderContext *pRC	= (RenderContext*)(g_pRenderContextx);
/*-------------------------------------------------------------------------------------------------------------------*/
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

struct CRank
{
	BYTE iRank;
};

struct CNames
{
    char szNames[33];
};

class GM
{
public:
	BYTE iRank;
	char _0x0001[15];
	WORD iHack;
};

/*-------------------------------------------------------------------------------------------------------------------*/
class cGameStageInfo
{
public:
	char _pad1[0x230]; //ResultBombArea // Gunakan ZrC-CyB-Logger.txt
	D3DXVECTOR3 BombPositionA; 
	D3DXVECTOR3 BombPositionB;
};

class cGameBases
{
public:
	char _pad1[0x3B9A8]; //ResultStageInfo // Gunakan ZrC-CyB-Logger.txt
	cGameStageInfo* StageInfo;
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
	char unknown4[912];
	D3DXVECTOR3 bone;
	D3DXVECTOR3 bone1;
	D3DXVECTOR3 bone2;
};

class RenderData
{
public:
	char _0x0000[32]; //ResultGetViewMatrix // Gunakan ZrC-CyB-Logger.txt
	D3DXMATRIX ViewMatrix;
	D3DXMATRIX ProjMatrix;
	char _0xA0[4736];
	D3DXMATRIX World;
	D3DXMATRIX WorldView[80];
};

class Bone
{
public:
	D3DXMATRIX m_Bone;
};

class CGameCharaBoneContext
{
public:
	char nop[0xD8]; //ResultmBone // Gunakan ZrC-CyB-Logger.txt
	Bone* m_Bone;
};

class CGameCharaBase
{
public:
	char nop[0x558]; //ResultPTRRecoil // Gunakan ZrC-CyB-Logger.txt
	CGameCharaBoneContext* m_BoneContext;
};

extern RenderContext *pRC;
/*-------------------------------------------------------------------------------------------------------------------*/