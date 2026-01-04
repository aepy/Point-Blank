
D3DXVECTOR3 vStart,vEnd;
D3DXVECTOR3 vvStart,vvEnd;
D3DXVECTOR3 vStart2,vEnd2;
D3DXVECTOR3 vvStart2,vvEnd2;
D3DXVECTOR3 vStart3,vEnd3;
D3DXVECTOR3 vvStart3,vvEnd3;
D3DXVECTOR3 vStart4,vEnd4;
D3DXVECTOR3 vvStart4,vvEnd4;
D3DXVECTOR3 vStart5,vEnd5;
D3DXVECTOR3 vvStart5,vvEnd5;
D3DXVECTOR3 vStart6,vEnd6;
D3DXVECTOR3 vvStart6,vvEnd6;
D3DXVECTOR3 vStart7,vEnd7;
D3DXVECTOR3 vvStart7,vvEnd7;
D3DXVECTOR3 vStart8,vEnd8;
D3DXVECTOR3 vvStart8,vvEnd8;
D3DXVECTOR3 vStart9,vEnd9;
D3DXVECTOR3 vvStart9,vvEnd9;
D3DXVECTOR3 vStart10,vEnd10;
D3DXVECTOR3 vvStart10,vvEnd10;
D3DVIEWPORT9 Viewport;
LPD3DXFONT fName	= NULL;

class RenderContext;
DWORD dwGFX			= (DWORD)GetModuleHandle("i3GfxDx.dll");
RenderContext *pRC	= (RenderContext*)(dwGFX + 0x1B22B0);
//RenderContext *pRC	= (RenderContext*)(BaseRender);

class RenderData
{
	public:
char _0x0000[8];
DWORD IsWindowed; //0x0008
DWORD IsReady; //0x000C
char _0x0010[16];
D3DXMATRIX ViewMatrix; //0x0020
D3DXMATRIX ProjMatrix; //0x0060
char _0x00A0[2160];
DWORD WindowWidth; //0x0910
DWORD WindowHeight; //0x0914
char _0x0918[2568];
D3DXMATRIX World; //0x1320
char _0x1360[16388];
IDirect3D9* D3D9; //0x5364
LPDIRECT3DDEVICE9 pDevice; //0x5368
char _0x536C[20];
HWND hWindow; //0x5380
char _0x5384[284];
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
struct CNames
{
    char szNames[33];
};
extern RenderContext *pRC;


class CBone
{
public:
	D3DXMATRIX BoneMatrix;
};


class CBonesContext
{
public:
	char   Unk[216];
	CBone* BoneData;
};



class CGameBase
{
public:
	char Unk[1368];
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


class CGameCharaBoneContext
{
public:
char nop[216];
Bone* m_Bone;
};


class CGameCharaBase
{
public:
char nop[1368];
CGameCharaBoneContext* m_BoneContext;
};


struct CTeam
{
	BYTE iTeam;
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
class GM;

class GM
{
public:
BYTE iRank; //0x0000
char _0x0001[15];
DWORD iHack; //0x0010
};//Size=0x0012

//--------------------------------------------------------------------
class HackName{
public:
DWORD iName1;
};
//--------------------------------------------------------------------
class HackName2{
public:
DWORD iName2;
};
//--------------------------------------------------------------------
class HackName3{
public:
DWORD iName3;
};
//--------------------------------------------------------------------
class HackName4{
public:
DWORD iName4;
};