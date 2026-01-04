/*Class.h D3D9 PBHacks Last Edit By Fatur Rezo*/

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "AutoLogger.h"

/*-------------------------------------------------------------------------------------------------------------------*/
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib,"d3dx9.lib")

/*-------------------------------------------------------------------------------------------------------------------*/
class PlayerInfo;
class RenderContext;
class RenderData;
class CInMouse;
class CGameBase;
class CBonesContext;
class CBone;

/*-------------------------------------------------------------------------------------------------------------------*/
LPD3DXFONT pFonts;
DWORD dwGFX			= (DWORD)GetModuleHandle("i3GfxDx.dll");
RenderContext *pRC	= (RenderContext*)(dwGFX + HookBaseRender);

/*-------------------------------------------------------------------------------------------------------------------*/
class RenderData
{
public:
		char _0x0000[32];
		D3DXMATRIX ViewMatrix;
		D3DXMATRIX ProjMatrix;
		char N00AF3B76[4736];
		D3DXMATRIX World;
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

extern RenderContext *pRC;

/*-------------------------------------------------------------------------------------------------------------------*/
class CBone
{
public:
	D3DXMATRIX BoneMatrix;
};

class CBonesContext
{
public:
	char Unk[0xD8];
	CBone* BoneData;
};

class CGameBase
{
public:
	char Unk[0x558];
	CBonesContext* Bones;
};

struct CHealth
{
 float CurHP;
};

struct CPlayers
{
    float yaw;
    float pitch;
    D3DXVECTOR3 pos;
	char unkno8[2304];
};

class Bone
{
public:
	D3DXMATRIX m_Bone;
};

class GM;
class GM
{
public:
	BYTE iRank; //0x0000
	char _0x0001[15];
	DWORD iHack; //0x0010
};//Size=0x0012

class HackName
{
public:
	DWORD iName1;
};

class HackName2
{
public:
	DWORD iName2;
};

class HackName3
{
public:
	DWORD iName3;
};

class HackName4
{
public:
	DWORD iName4;
};

struct CNames
{
    char szNames[33];
};

class CGameCharaBoneContext
{
public:
	char nop[0xD8];
	Bone* m_Bone;
};

class CGameCharaBase
{
public:
	char nop[0x558];
	CGameCharaBoneContext* m_BoneContext;
};

class cGameStageInfo
{
public:
	char _pad1[0x230]; //ResultBombArea
	D3DXVECTOR3 BombPositionA; 
	D3DXVECTOR3 BombPositionB;
};

class cGameBases
{
public:
	char _pad1[0x3B9A8]; //ResultStageInfo
	cGameStageInfo* StageInfo;
};

struct CTeam
{
	BYTE iTeam;
};

class CLog;
class CLog
{
public:
	BYTE iLog;
};

class CKill;
class CKill
{
public:
	BYTE bKill;
	char _0001[1];
	BYTE bDead;
	char _0003[1];
};

struct TeamScore
{
public:
	WORD  TScoreRed;
	WORD  TScoreBlue;
};

class CNick
{
public:
	BYTE bVal;
};

class Gendeng
{
public:
	DWORD Module;
};

class CDWORD
{
public:
	DWORD dwRes;
};

class CWORD
{
public:
	WORD wRes;
};

class CBYTE
{
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

class CDeathPlayer{
public:
	BYTE Death[16];
};

class CLocalPlayerID{
public:
	BYTE ID;
};

DWORD d;

/*-------------------------------------------------------------------------------------------------------------------*/