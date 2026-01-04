#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "AutoLog.h"
#include "XStr.h"

D3DVIEWPORT9 Viewport;
D3DVIEWPORT9 g_ViewPort;
LPD3DXLINE pLine    = NULL;
LPDIRECT3DDEVICE9 npDevice; 
LPDIRECT3DDEVICE9 oDevice = NULL;
LPD3DXFONT fName	= NULL;
LPD3DXFONT fSmall	= NULL;
LPD3DXFONT Title    = NULL;
LPD3DXFONT fBig	= NULL;
LPD3DXSPRITE Sprite;
LPDIRECT3DTEXTURE9 MenuTexture;
DWORD TeamColor;
D3DVECTOR Player;
D3DVECTOR HeadPos;
D3DVECTOR PlayerScaled;
D3DVECTOR HeadScaled;
D3DVECTOR BonePos;
BOOL Create;
char *Moptfolder        []  = {"Open", "Close"}; 
#define PINK			D3DCOLOR_XRGB(255 , 0 , 255)
#define RED				D3DCOLOR_ARGB(255, 245, 000, 000)
#define WHITE			D3DCOLOR_ARGB(255, 255, 255, 255)
#define YELLOW			D3DCOLOR_ARGB(255, 255, 255, 000) 
#define GREEN			D3DCOLOR_ARGB(255, 000, 255, 000)
#define ORANGE			D3DCOLOR_ARGB(255, 255, 125, 000)
#define BLACK			D3DCOLOR_ARGB(150, 000, 000, 000)
#define BLUE			D3DCOLOR_ARGB(255, 19, 84, 199) 
#define PURPLE			D3DCOLOR_ARGB(255, 125, 000, 255)
#define DEEPSKYBLUE     D3DCOLOR_ARGB(255, 30, 144, 255) //
#define CHOCOLATE2      D3DCOLOR_ARGB(255, 238, 118, 33) //
#define GOLD2			D3DCOLOR_ARGB(255, 238, 201, 0)  //
#define SQUA			D3DCOLOR_ARGB(255, 0, 255, 255)  //
#define DARKGREY        D3DCOLOR_ARGB(255,62,62,62)      //
#define Functions       D3DCOLOR_ARGB(255,26,115,145)//
#define MenuGreen       D3DCOLOR_ARGB(255,43,119,64) //
#define MenuGREY        D3DCOLOR_ARGB(255,30,30,30)  //
#define FUCK_ON			D3DCOLOR_ARGB(255,14,159,47) //
#define FUCK_OFF		D3DCOLOR_ARGB(255,62,120,167)//
#define dBlue	D3DCOLOR_RGBA(000, 000, 255, 255)
#define dRed	D3DCOLOR_RGBA(255, 000, 000, 255)



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
BYTE Byte [40];
class PlayerInfo;
class RenderContext;
class RenderData;
class CInMouse;
class CGameBase;
class CBonesContext;
class CBone;

LPD3DXFONT pFonts;
DWORD dwGFX			= (DWORD)GetModuleHandle("i3GfxDx.dll");
RenderContext *pRC	= (RenderContext*)(dwGFX + 0x1B22B0);// ini dah bner 0x1AD2F0

class RenderData {
public:
char unknown0[0x20];
D3DXMATRIX ViewMatrix;
D3DXMATRIX ProjMatrix;
char _0x00A0[4736];
D3DXMATRIX World;
};

class RenderContext
{
public:
RenderData* pRenderData;
};

class CBone
{
public:
	D3DXMATRIX BoneMatrix;
};


class CBonesContext
{
public:
	char   Unk[0xD8];
	CBone* BoneData;
};

struct D3DTLVERTEX
{
	float fX;
	float fY;
	float fZ;
	float fRHW;
	D3DCOLOR Color;
	float fU;
	float fV;
};

class CGameBase
{
public:
	char           Unk[0x558];// ini udah 1372
	CBonesContext* Bones;
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
char szNames[33]; /// taroh di File.h
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

class CGameCharaBoneContext
{
public:
char nop[0xD8];
Bone* m_Bone;
};// pas aktifin itu langsung dc -_- 


class CGameCharaBase
{
public:
char nop[0x558];
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

class CHSBypass
{
public:
char _0x0000[168];
DWORD dwES;
char _0x00AC[156];
DWORD dwDIP;
};

class ClassGfx;
class ClassGfx
{
public:
char Fix[168];
DWORD cES;
char Mix[156];
DWORD cDip;
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
//====================================
extern RenderContext *pRC;
// ============================
class CSlotz;
class CSlotz
{
public:
DWORD Host;
DWORD Slot;
};
class cHIT
{
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

class Semprul;
class Semprul
{
public:
int GetTeam(char MyT);
VOID WriteJMP ( PVOID bSource, PVOID bAddress, int Lenght );
bool YoWorlToScreenGa(LPDIRECT3DDEVICE9 pDevice, D3DVECTOR Player,D3DVECTOR &PlayerScaled);
PBYTE HookVTableFunction( PDWORD* dwVTable, PBYTE dwHook, INT Index );
void DrawCircle(int X, int Y, int radius, int numSides, DWORD Color);
void Healthbarnew(LPDIRECT3DDEVICE9 pDevice,float x, float y, float Health);
//char Mem_ASM(void* address, void* val, char bytes);
DWORD MyDetour(DWORD bSource, DWORD iAddress);
DWORD Semprul::GetAmmoIndex(DWORD dwPtr,DWORD A1,DWORD B1,DWORD C1);
void Semprul::c_WeaponIndex_B(unsigned long adr, unsigned long Ofset1, unsigned long Ofset2, unsigned long Ofset3, unsigned long Ofset4, DWORD dwValue);
void Semprul::gEtWeapon_IndexA(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, DWORD Value);
void DrawItem4 ( int Shell , char iText[], int x, int y );
void DrawItem5 ( int Shell , char iText[], int x, int y );
void DrawItem6 ( int Shell , char iText[], int x, int y );
void _patchPTR(unsigned long adr, unsigned long Ofset, DWORD dwValue);
int GetMyCharaIndex();
void PacthWeapon(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, DWORD Value);
void DRC(PDWORD target, PDWORD newfunc);
void patchPTR(unsigned long adr, unsigned long Ofset1, DWORD dwValue);
bool IsInScreen(int Index);
void DrawItem2 ( int Shell , char iText[], int x, int y );
void DrawBox( int x, int y, int w, int h, D3DCOLOR BoxColor, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice );
void Crosshair(LPDIRECT3DDEVICE9 pDevice, D3DCOLOR Color);
void MakeJMP( BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen );
DWORD CGameContextPointer(void);
void PrivateOnly(void *adr, void *ptr, int size);
void PrintText(char pString[], int x, int y, D3DCOLOR col, ID3DXFont *font);
void PachtChara(DWORD B,DWORD A1,DWORD B1, DWORD ISI);
void* DetourFunc(BYTE *src, const BYTE *dst, const int len);
DWORD HSTmpPointer(void);
DWORD B8Detours( DWORD  SrcVA, DWORD  DstVA, DWORD  Size );
void MoveMemo(void *adr, void *ptr, int size);
void WriteHack (DWORD B,DWORD A1,DWORD B1, DWORD ISI);
bool GetUserBone( D3DXVECTOR3 &Out,  int BoneIdx ,int Idx);
void DrawItem ( int Shell , char iText[], int x, int y );
bool _ByteScr (DWORD ads, DWORD a, DWORD b, DWORD c) ;
DWORD ReadFunct(DWORD dwPtr, DWORD dwOfs);
bool GetBattleState();
bool IsAlive(int Index);
void DrawTextL(int x,int y,DWORD color,char *text);
int GetTargetIndex(DWORD PlayerTarget);
DWORD GetPlayerTarget(int myIDX);
void CopyMemo(void *adr, void *ptr, int size);
void Circle( float x, float y, float rad, bool center, DWORD color ,LPDIRECT3DDEVICE9 pDevice);
bool _ByteSet (DWORD ads, DWORD a, DWORD b, DWORD c) ;
void DrawString(int x, int y, DWORD color, const char *fmt, ...);
void DrawItem3 ( int Shell , char iText[], int x, int y );
void DrawLine ( long Xa, long Ya, long Xb, long Yb, DWORD dwWidth, D3DCOLOR Color );
void FillRGB( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice );
DWORD JumpDetour(PBYTE Target,DWORD DetourDest,int OpsLeft);
D3DXVECTOR3 GetUserVector( int Index );
float CalcDistance( D3DXVECTOR3 VecA, D3DXVECTOR3 VecB );
void GetWeaponHack(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3);
bool WriteSimpleOther(unsigned long ADRexec, int OFSexec, int PTRexec);
void FourWriteHack (DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, BYTE Value);
bool MyWorld2Screen (D3DXVECTOR3 inpos, D3DXVECTOR3 &outpos);
void DrawBorder( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice );
};

bool Semprul::WriteSimpleOther(unsigned long ADRexec, int OFSexec, int PTRexec)
{
if (!IsBadReadPtr((void*)ADRexec, sizeof(unsigned long)))
{
if (!IsBadReadPtr((void*)(*(unsigned long*)ADRexec + OFSexec), sizeof(unsigned long)))
{
*(int*)(*(unsigned long*)ADRexec + OFSexec) = PTRexec;
}
}
return 0;
}
void Semprul::DrawTextL(int x,int y,DWORD color,char *text)
{
    RECT rect, rect1, rect2, rect3, rect4, rect5;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect1, x-1, y, x-1, y );
	SetRect( &rect2, x+1, y, x+1, y );
	SetRect( &rect3, x, y-1, x, y-1 );
	SetRect( &rect4, x, y+1, x, y+1 );
	SetRect( &rect5, x - 0.1, y + 0.2, x - 0.1, y + 0. );
	fName->DrawTextA(NULL,text,-1,&rect5, DT_LEFT|DT_NOCLIP, color );// menunya arah ke tengah
}
DWORD Semprul::GetAmmoIndex(DWORD dwPtr,DWORD A1,DWORD B1,DWORD C1)
{
	DWORD C=0;
	if (IsBadReadPtr((PDWORD)dwPtr,4)==0){
	C=*(PDWORD)((DWORD)(dwPtr))+A1;
	if (IsBadReadPtr((PDWORD )C,4)==0){
	C=*(PDWORD)((DWORD)(C ))+ B1;
	if (IsBadReadPtr((PDWORD)C,4)==0) {
	C=*(PDWORD)((DWORD)(C ))+ C1;
	if (IsBadReadPtr((PDWORD)C,4)==0) {
	return *(PDWORD)C; } } }
	}
	return C;
}

void Semprul::gEtWeapon_IndexA(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, DWORD Value)
{ 
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)Base,4)==0){
	Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
	if (IsBadReadPtr((PDWORD)Temp,4)==0){
	Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
	if (IsBadReadPtr((PDWORD)Temp,4)==0){
	Temp=*(PDWORD)((DWORD)(Temp))+Ofs3;
	if (IsBadReadPtr((PDWORD)Temp,4)==0){
	*(PDWORD)Temp=Value;}}}}
}
//----------------------------------------------------------------------------------
int Semprul::GetTeam(char MyTeam)
{
for(int i = 0; i < 16; i+=2)
if(i == MyTeam)return 2;
for(int i = 1; i< 16; i+=2)
if(i == MyTeam)return 1;
return -1;
}
DWORD ReadFunct(DWORD dwPtr, DWORD dwOfs){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return *(PDWORD)C; 
}
}
return C;
}


void PatchSkill(DWORD adr, DWORD Ofset, DWORD dwValue)
{
	DWORD A=0;
	if (IsBadReadPtr((PDWORD)adr,4)==0)
	{ A=*(PDWORD)((DWORD)(adr))+Ofset;
	if (IsBadReadPtr((PDWORD)A,4)==0)
	{*(PDWORD)A=dwValue;}}
}

void PactJumper (DWORD Base,DWORD Ofs1, BYTE Value)
{ 
DWORD Temp=NULL;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
*(PBYTE)Temp=Value;
}
}
}

bool GetBattleState1() { 
	DWORD BaseG = (DWORD)GetModuleHandleA("PointBlank.exe");
	unsigned long xBase = *(DWORD*)(BaseG + OFS_Ammo); //
	if(xBase > NULL)
	{ 
		return true; 
	} return false; 
}

//--------------------------------------------------------------------
void patchPTR(unsigned long adr, unsigned long Ofset1, DWORD dwValue){ 
DWORD A=0;
if(IsBadReadPtr((PDWORD)adr,4))return;
A=*(PDWORD)((DWORD)(adr))+Ofset1;
if(IsBadReadPtr((PDWORD)A,4))return;
if(*(PDWORD)A!=dwValue)*(PDWORD)A=dwValue;
}
D3DXVECTOR3 GetUserBonePos2(int Idx ,int BoneIdx)
{
D3DXVECTOR3 Out;
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA("PointBlank.exe");
unsigned long dwGameBase = *(DWORD*)(dwI3EXEC + OFS_Health);
if ( dwGameBase )
{
CGameCharaBase* GameBase = (CGameCharaBase*)( *(DWORD*)(dwGameBase + 0x14 + ( 0x4 * Idx ) ) );
if ( GameBase && GameBase->m_BoneContext )
{
Out.x = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._41;
Out.y = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._42;
Out.z = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._43;
}}
return Out;
}

void Semprul::c_WeaponIndex_B(unsigned long adr, unsigned long Ofset1, unsigned long Ofset2, unsigned long Ofset3, unsigned long Ofset4, DWORD dwValue)
{ 
	DWORD A=0;
	if(IsBadReadPtr((PDWORD)adr,4))return;
	A=*(PDWORD)((DWORD)(adr))+Ofset1;
	if(IsBadReadPtr((PDWORD)A,4))return;
	A=*(PDWORD)((DWORD)(A))+Ofset2;
	if(IsBadReadPtr((PDWORD)A,4))return;
	A=*(PDWORD)((DWORD)(A))+Ofset3;
	if(IsBadReadPtr((PDWORD)A,4))return;
	A=*(PDWORD)((DWORD)(A))+Ofset4;
	if(IsBadReadPtr((PDWORD)A,4))return;
	if(*(PDWORD)A!=dwValue)*(PDWORD)A=dwValue;
}
BYTE wepon,piso,pistol,bom,asep,dual;
void Semprul::GetWeaponHack(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3)
{
DWORD Temp =0;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
Temp=*(PDWORD)((DWORD)(Temp))+Ofs3;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
wepon = *(PBYTE)Temp;
}
}
}
}
}

DWORD Function_Two (DWORD Base,DWORD Ofs1,DWORD Ofs2, BYTE Value)
{
DWORD Temp=NULL;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
*(PBYTE)Temp=Value;
}
}
}
return (0);
}

//----------
void WeaponHack2(DWORD B,DWORD A1,DWORD B1, DWORD ISI)
    { DWORD A=0;
    if (IsBadReadPtr((PDWORD)B,1)==0)
    { A=*(PDWORD)((DWORD)(B))+A1;
    if (IsBadReadPtr((PDWORD)A,1)==0)
    { A=*(PDWORD)((DWORD)(A))+B1;
	if (IsBadReadPtr((PDWORD)A,1)==0)
    {*(PDWORD)A=ISI;
    }
    }
    }
    }
//-----------
void PacthWeapone(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, DWORD Value)
{ 
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)Base,4)==0){
	Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
	if (IsBadReadPtr((PDWORD)Temp,4)==0){
	Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
	if (IsBadReadPtr((PDWORD)Temp,4)==0){
	Temp=*(PDWORD)((DWORD)(Temp))+Ofs3;
	if (IsBadReadPtr((PDWORD)Temp,4)==0){
	*(PDWORD)Temp=Value;}}}}
}

void DRC(PDWORD target, PDWORD newfunc)
{
	DWORD Jmpto=(DWORD)(newfunc)-(DWORD)target-5;
	DWORD a;
    VirtualProtect(target, 8, PAGE_EXECUTE_READWRITE, &a);
    *(PBYTE)(target)=0xE9;
    *(PDWORD)((DWORD)(target)+1)=Jmpto;
	VirtualProtect(target, 8, a, &a);
}

DWORD BokongKill,ReloadBullet,PisoGila = 0;
DWORD TestPacth(DWORD dwPtr,DWORD A1,DWORD B1,DWORD C1)
{
	DWORD C=0;
	if (IsBadReadPtr((PDWORD)dwPtr,4)==0){
	C=*(PDWORD)((DWORD)(dwPtr))+A1;
	if (IsBadReadPtr((PDWORD )C,4)==0){
	C=*(PDWORD)((DWORD)(C ))+ B1;
	if (IsBadReadPtr((PDWORD)C,4)==0) {
	C=*(PDWORD)((DWORD)(C ))+ C1;
	if (IsBadReadPtr((PDWORD)C,4)==0) {
	return *(PDWORD)C; } } }
	}
	return C;
}

void Function_One (DWORD Base,DWORD Ofs1, BYTE Value)
{ 
DWORD Temp=NULL;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
*(PBYTE)Temp=Value;
}
}
}

//---------------------------------Hook Engine------------------------------------------------------------------------------------------------
 void MakeJMP( BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen )
{
    DWORD dwOldProtect, dwBkup, dwRelAddr;
    VirtualProtect(pAddress, dwLen, PAGE_EXECUTE_READWRITE, &dwOldProtect);
    dwRelAddr = (DWORD) (dwJumpTo - (DWORD) pAddress) - 5;
    *pAddress = 0xE9;
    *((DWORD *)(pAddress + 0x1)) = dwRelAddr;
    for(DWORD x = 0x5; x < dwLen; x++) *(pAddress + x) = 0x90;
    VirtualProtect(pAddress, dwLen, dwOldProtect, &dwBkup);
    return;
}

void c_WeaponIndex_B(unsigned long adr, unsigned long Ofset1, unsigned long Ofset2, unsigned long Ofset3, unsigned long Ofset4, DWORD dwValue)
{ 
	DWORD A=0;
	if(IsBadReadPtr((PDWORD)adr,4))return;
	A=*(PDWORD)((DWORD)(adr))+Ofset1;
	if(IsBadReadPtr((PDWORD)A,4))return;
	A=*(PDWORD)((DWORD)(A))+Ofset2;
	if(IsBadReadPtr((PDWORD)A,4))return;
	A=*(PDWORD)((DWORD)(A))+Ofset3;
	if(IsBadReadPtr((PDWORD)A,4))return;
	A=*(PDWORD)((DWORD)(A))+Ofset4;
	if(IsBadReadPtr((PDWORD)A,4))return;
	if(*(PDWORD)A!=dwValue)*(PDWORD)A=dwValue;
}
//--------------------------------------------------------------------
void PacthWeapon(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, DWORD Value){ 
DWORD Temp=0;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
Temp=*(PDWORD)((DWORD)(Temp))+Ofs3;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
*(PDWORD)Temp=Value;}}}}
}

void Semprul::WriteHack (DWORD B,DWORD A1,DWORD B1, DWORD ISI){
DWORD A=0;
if (IsBadReadPtr((PDWORD)B,4)==0){
A=*(PDWORD)((DWORD)(B))+A1;
if (IsBadReadPtr((PDWORD )A,4)==0){
A=*(PDWORD)((DWORD)(A ))+ B1;
if (IsBadReadPtr((PDWORD)A,4)==0) {
{*(PDWORD)A=ISI;}}}}}

WORD pKey, pBase, pValue, pSoul;
void GetValue(DWORD BaseOfs, DWORD Offset1, DWORD Offset2, DWORD Offset3)
{
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)BaseOfs, 4) == 0){ 
		Temp = *(PDWORD)((DWORD)(BaseOfs)) + Offset1;
		if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
			Temp = *(PDWORD)((DWORD)(Temp)) + Offset2;
			if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
				Temp = *(PDWORD)((DWORD)(Temp)) + Offset3;
				if (IsBadReadPtr((PDWORD)Temp,4) == 0){
					switch (Offset3){
						case 0x898:
							pKey = *(PWORD)Temp;
						case 0x879:
							pBase = *(PWORD)Temp;
						case 0x894:
							pValue = *(PWORD)Temp;
						case 0x8A0:
							pSoul = *(PWORD)Temp;
					}
				}
			}
		}
	}
}
void PatchValue(DWORD BaseOfs, DWORD Offset1, DWORD Offset2, DWORD Offset3, DWORD Value)
{
DWORD Temp=0;
if (IsBadReadPtr((PDWORD)BaseOfs, 4) == 0){ 
Temp = *(PDWORD)((DWORD)(BaseOfs)) + Offset1;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
Temp = *(PDWORD)((DWORD)(Temp)) + Offset2;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
Temp = *(PDWORD)((DWORD)(Temp)) + Offset3;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){
*(PDWORD)Temp = Value;
}}}}}
void Semprul::FourWriteHack (DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, BYTE Value)
{
DWORD Temp=0;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
Temp=*(PDWORD)((DWORD)(Temp))+Ofs3;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
*(PBYTE)Temp=Value;
}
}
}
}
}

DWORD Semprul::ReadFunct(DWORD dwPtr, DWORD dwOfs){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return *(PDWORD)C; 
}
}
return C;
}

float Semprul::CalcDistance( D3DXVECTOR3 VecA, D3DXVECTOR3 VecB )
{
        return sqrt( ( ( VecA.x - VecB.x ) * ( VecA.x - VecB.x ) ) +
                 ( ( VecA.y - VecB.y ) * ( VecA.y - VecB.y ) ) +
                 ( ( VecA.z - VecB.z ) * ( VecA.z - VecB.z ) ) );
}
bool MakePoint(unsigned long ADRexec, int OFSexec, int PTRexec)
{
if (!IsBadReadPtr((void*)ADRexec, sizeof(unsigned long)))
{
if (!IsBadReadPtr((void*)(*(unsigned long*)ADRexec + OFSexec), sizeof(unsigned long)))
{
*(int*)(*(unsigned long*)ADRexec + OFSexec) = PTRexec;
}
}
return 0;
}

bool Semprul::MyWorld2Screen (D3DXVECTOR3 inpos, D3DXVECTOR3 &outpos)
{
DWORD dwRenderData = (DWORD)GetModuleHandleA("i3GfxDx.dll") + 0x1B2270;
RenderContext* Pesong = (RenderContext*)(dwRenderData);

D3DXMATRIX identity;
D3DXVECTOR3 vScreen;

D3DVIEWPORT9 g_ViewPort;
npDevice->GetViewport(&g_ViewPort);
g_ViewPort.X = g_ViewPort.Y = 0;
g_ViewPort.MinZ = 0;
g_ViewPort.MaxZ = 1;
D3DXVec3Project(&vScreen, &inpos, &g_ViewPort,&Pesong->pRenderData->ProjMatrix,&Pesong->pRenderData->ViewMatrix,&Pesong->pRenderData->World);
if (vScreen.z < 1.0f && vScreen.x > 0.0f && vScreen.y > 0.0f && vScreen.x < g_ViewPort.Width && vScreen.y < g_ViewPort.Height)
{
outpos.x = vScreen.x;
outpos.y = vScreen.y;
outpos.z = vScreen.z;
return true;
}
return false;
}

bool KyuubiW2S(LPDIRECT3DDEVICE9 pDevice, D3DVECTOR Player,D3DVECTOR &PlayerScaled)
{
   D3DXVECTOR3 PlayerPos(Player.x,Player.y,Player.z);
	D3DXMATRIX identity;
    D3DXVECTOR3 vScreen;
	pDevice->GetViewport(&Viewport);
	Viewport.X = Viewport.Y = 0;
    Viewport.MinZ     = 0;
    Viewport.MaxZ     = 1;
	D3DXVec3Project(&vScreen, &PlayerPos, &Viewport, &pRC->pRenderData->ProjMatrix, &pRC->pRenderData->ViewMatrix, &pRC->pRenderData->World);
  
 if (vScreen.z < 1.0f && vScreen.x > 0.0f && vScreen.y > 0.0f && vScreen.x < Viewport.Width && vScreen.y < Viewport.Height)
 {
     PlayerScaled.x = vScreen.x;
     PlayerScaled.y = vScreen.y ;
     PlayerScaled.z = vScreen.z;

  return true; 
 }
 return false;
}

D3DXVECTOR3 Semprul::GetUserVector( int Index )
{
DWORD ADR_PLAYER = *(DWORD*)(ResultBasePlayer2); 
DWORD OldProtect; 
DWORD pCalculate = *(DWORD*)(ADR_PLAYER + 4 * Index + 0x2733C); 
VirtualProtect ( (LPVOID)(pCalculate), sizeof (pCalculate), PAGE_EXECUTE_READWRITE, &OldProtect ); 
CPlayers *Players = (CPlayers*)(pCalculate + 0x64 ); 
VirtualProtect ( (LPVOID)(pCalculate), sizeof (pCalculate), OldProtect, &OldProtect ); 
return Players->pos; 
}
void Semprul::DrawString(int x, int y, DWORD color, const char *fmt, ...)
{
	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	
	fName->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}
bool REPALCE(unsigned long ADRexec, int OFSexec, int PTRexec)
{
if (!IsBadReadPtr((void*)ADRexec, sizeof(unsigned long)))
{
if (!IsBadReadPtr((void*)(*(unsigned long*)ADRexec + OFSexec), sizeof(unsigned long)))
{
*(int*)(*(unsigned long*)ADRexec + OFSexec) = PTRexec;
}
}
return 0;
}
//=========================================================================//
DWORD Read(DWORD dwPtr, DWORD dwOfs){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return *(PDWORD)C; 
} } 
return C;
}
//=========================================================================//

void _patchPTRZ(unsigned long adr, unsigned long Ofset1, DWORD dwValue)
{ 
	DWORD A=0;
	if(IsBadReadPtr((PDWORD)adr,4))return;
	A=*(PDWORD)((DWORD)(adr))+Ofset1;
	if(IsBadReadPtr((PDWORD)A,4))return;
	if(*(PDWORD)A!=dwValue)*(PDWORD)A=dwValue;
}
void PrintTextC(LPD3DXFONT pFont, long x, long y, D3DCOLOR fontColor, char *text, ...)
{
    RECT rct;
    rct.left     = x - 1;
    rct.right    = x + 1;
    rct.top      = y - 1 ;
    rct.bottom    = y + 1;

    if(!text) { return; }
    va_list va_alist;
    char logbuf[256] = {0};
    va_start (va_alist, text);
    _vsnprintf(logbuf+strlen(logbuf), sizeof(logbuf) - strlen(logbuf), text, va_alist);
    va_end (va_alist);
    RECT FontRect = { x, y, x, y };
    pFont->DrawTextA(NULL, logbuf, -1, &rct, DT_NOCLIP + DT_CENTER, fontColor);
	
}
DWORD Semprul::B8Detours( DWORD  SrcVA, DWORD  DstVA, DWORD  Size )
{
#define SIZEOF_MOVEAX_JMPEAXX 7
DWORD DetourVA, dwProtect, i;
MEMORY_BASIC_INFORMATION mbi;
DWORD Keler=((DWORD)(DstVA)-(DWORD)SrcVA)-7;
if ( SrcVA && DstVA && Size >= SIZEOF_MOVEAX_JMPEAXX ){
DetourVA = (DWORD) VirtualAlloc(NULL, Size + SIZEOF_MOVEAX_JMPEAXX, MEM_COMMIT, PAGE_EXECUTE_READWRITE );
if ( DetourVA && VirtualProtect( (VOID*)SrcVA, Size, PAGE_EXECUTE_READWRITE, &dwProtect ) )
{
for ( i=0; i < Size; i++ ) {
*(BYTE*)( DetourVA + i ) = *(BYTE*)( SrcVA + i );
}
*(BYTE*)( DetourVA + Size + 0 ) = 0xF8;
*(BYTE*)( DetourVA + Size + 1 ) = 0x0F;
*(BYTE*)( DetourVA + Size + 2 ) = 0x83;
*(DWORD*)( DetourVA + Size + 3 ) = ( SrcVA + Size );

*(BYTE*)( SrcVA + 0 ) = 0xF8;
*(DWORD*)( SrcVA + 1 ) = 0x0F;
*(DWORD*)( SrcVA + 2 ) = 0x83;
*(DWORD*)( SrcVA + 3 ) = Keler;
VirtualProtect( mbi.BaseAddress, mbi.RegionSize, mbi.Protect, &mbi.Protect );
FlushInstructionCache( GetCurrentProcess( ), (LPVOID)SrcVA, 10 );
return DetourVA;
}}
return(0);
}

DWORD CreateDetour(PBYTE Target,DWORD DetourDest,int OpsLeft, int Constant)
{
DWORD Old;
VirtualProtect(Target,0xE+OpsLeft,PAGE_READWRITE,&Old);
*Target = 0x33;
*(BYTE*)(Target+1) = 0xC0;
*(BYTE*)(Target+2) = 0xB8;
*(DWORD*)(Target+3) = DetourDest-Constant;
*(BYTE*)(Target+7) = 0x05;
*(BYTE*)(Target+8) = Constant;
*(BYTE*)(Target+0xC) = 0xFF;
*(BYTE*)(Target+0xD) = 0xE0;
for(int lftover = 0xE; lftover < 0xE+OpsLeft; lftover++)
{
*(BYTE*)(Target+lftover)=0x90;
}
VirtualProtect(Target,0xE+OpsLeft,Old,0);
return (DWORD)(Target+0xE+OpsLeft);
}

DWORD Semprul::JumpDetour(PBYTE Target,DWORD DetourDest,int OpsLeft)
{
DWORD Old;
VirtualProtect(Target,9+OpsLeft,PAGE_READWRITE,&Old);
Sleep(1);
*Target = 0x33;
Sleep(1);
*(BYTE*)(Target+1) = 0xC0;
Sleep(1);
*(BYTE*)(Target+2) = 0x05;
Sleep(1);
*(DWORD*)(Target+3) = DetourDest;
Sleep(1);
*(BYTE*)(Target+7) = 0xFF;
Sleep(1);
*(BYTE*)(Target+8) = 0xE0;
Sleep(1);
for(int lftover = 9; lftover < 9+OpsLeft; lftover++)
{
*(BYTE*)(Target+lftover)=0x90;
Sleep(1);
}
VirtualProtect(Target,9+OpsLeft,Old,0);
Sleep(1);
return (DWORD)(Target+9+OpsLeft);
}

void *Semprul::DetourFunc(BYTE *src, const BYTE *dst, const int len)
{
BYTE *jmp = (BYTE*)malloc(len+5);
DWORD dwBack;
VirtualProtect(src, len, PAGE_READWRITE, &dwBack);
memcpy(jmp, src, len);
Sleep(1);
jmp += len;
Sleep(1);
jmp[0] = 0xE9;
Sleep(1);
*(DWORD*)(jmp+1) = (DWORD)(src+len - jmp) - 5;
Sleep(1);
src[0] = 0x90;
Sleep(1);
src[1] = 0x90;
Sleep(1);
src[2] = 0xE9;
Sleep(1);
*(DWORD*)(&src[3]) = (DWORD)(dst - src) - 7;
Sleep(1);
for (int i=7; i<len; i++) src[i] = 0x90;
Sleep(1);
VirtualProtect(src, len, dwBack, &dwBack);
return (jmp-len);
}

int Semprul::GetTargetIndex(DWORD PlayerTarget)
{
DWORD ModuleHandle = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD BasePlayer_B = *(DWORD*)(ModuleHandle + ResultBaseHealth);
if(PlayerTarget > NULL){
if(IsBadReadPtr((void*)BasePlayer_B,4))return 0;
for(int i = 0; i<=16; i++){
DWORD PlayerIndexA = *(DWORD*)(BasePlayer_B + 0x14 + (4 * i));
if(PlayerIndexA == PlayerTarget)return i;
}
}
return -1;
}

DWORD Semprul::GetPlayerTarget(int myIDX)
{
DWORD ModuleHandle = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD BasePlayer_B = *(DWORD*)(ModuleHandle + ResultBaseHealth);
if(IsBadReadPtr((void*)BasePlayer_B,4))return 0;
DWORD PlayerIndexA = *(DWORD*)(BasePlayer_B + 0x14 + (myIDX * 4));
if(IsBadReadPtr((void*)PlayerIndexA,4))return 0;
DWORD PlayerIndexB = *(DWORD*)(PlayerIndexA + 0x53C);
if(IsBadReadPtr((void*)PlayerIndexB,4))return 0;
DWORD IsTargetingEnemy = *(DWORD*)(PlayerIndexB + 0x1E08);
if(IsBadReadPtr((void*)IsTargetingEnemy,4))return 0;
return IsTargetingEnemy;
}

bool Semprul::IsAlive(int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandle("Pointblank.exe");
unsigned long dwBase2	= *(DWORD*)(dwI3EXEC + ResultBaseHealth);
CHealth		*Health		= (CHealth*) ((dwBase2 + 0x264) + Index * PTRSizeHealth);
if(Health->CurHP > 0.1f)
return true;
return false;
}

bool Semprul::GetBattleState()
{
DWORD ModuleHandle				= (DWORD)GetModuleHandle("PointBlank.exe");
unsigned long xBase				= *(DWORD*)(ModuleHandle + ResultBaseAmmo);
if(xBase > NULL){
return true;
}
return false;
}

bool Semprul::_ByteScr (DWORD ads, DWORD a, DWORD b, DWORD c) 
{
__try {
DWORD StartRayer = 0;
StartRayer = *(DWORD*)((DWORD)(ads))+a;
StartRayer = *(DWORD*)((DWORD)(StartRayer))+b;
StartRayer = *(DWORD*)((DWORD)(StartRayer))+c;
ReadProcessMemory (GetCurrentProcess (), (LPVOID)(StartRayer), Byte, 40, 0);
return 1;
}__except ( EXCEPTION_EXECUTE_HANDLER ) {
return 0;
}
}
//---------------------------------------------------------------------------------------------------------------------------------
bool Semprul::_ByteSet (DWORD ads, DWORD a, DWORD b, DWORD c) 
{
__try {
DWORD SetDyChron = 0;
SetDyChron = *(DWORD*)((DWORD)(ads))+a;
SetDyChron = *(DWORD*)((DWORD)(SetDyChron))+b;
SetDyChron = *(DWORD*)((DWORD)(SetDyChron))+c;
WriteProcessMemory (GetCurrentProcess (), (LPVOID)(SetDyChron), Byte, 40, 0);
return 1;
}__except ( EXCEPTION_EXECUTE_HANDLER ) {
return 0;
}
}

bool Semprul::YoWorlToScreenGa(LPDIRECT3DDEVICE9 pDevice, D3DVECTOR Player,D3DVECTOR &PlayerScaled)
{
   D3DXVECTOR3 PlayerPos(Player.x,Player.y,Player.z);
	D3DXMATRIX identity;
    D3DXVECTOR3 vScreen;
	pDevice->GetViewport(&Viewport);
	Viewport.X = Viewport.Y = 0;
    Viewport.MinZ     = 0;
    Viewport.MaxZ     = 1;
	D3DXVec3Project(&vScreen, &PlayerPos, &Viewport, &pRC->pRenderData->ProjMatrix, &pRC->pRenderData->ViewMatrix, &pRC->pRenderData->World);
  
 if (vScreen.z < 1.0f && vScreen.x > 0.0f && vScreen.y > 0.0f && vScreen.x < Viewport.Width && vScreen.y < Viewport.Height)
 {
     PlayerScaled.x = vScreen.x;
     PlayerScaled.y = vScreen.y ;
     PlayerScaled.z = vScreen.z;

  return true; 
 }
 return false;
}

#define PI 3.14159265//Defining what PI is. PI is a Circle 
int CenterX = GetSystemMetrics( 0 ) / 2-1;//Gets screen X resolution then cutting it in half to get the center.
int CenterY = GetSystemMetrics( 1 ) / 2-1;//Gets screen Y resolution then cutting it in half to get the center.
LPDIRECT3DDEVICE9 pDevice;
void Semprul::FillRGB( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice )
{
if( w < 0 )w = 1;
if( h < 0 )h = 1;
if( x < 0 )x = 1;
if( y < 0 )y = 1;
 
D3DRECT rec = { x, y, x + w, y + h };
pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}

void Semprul::DrawBox( int x, int y, int w, int h, D3DCOLOR BoxColor, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
//FillRGB( x, y, w, h, BoxColor, pDevice );
DrawBorder( x, y, w, h, 1, BorderColor, pDevice );
} 

void Semprul::DrawBorder( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
FillRGB( x, (y + h - px), w, px, BorderColor, pDevice );
FillRGB( x, y, px, h, BorderColor, pDevice );
FillRGB( x, y, w, px, BorderColor, pDevice );
FillRGB( (x + w - px), y, px, h, BorderColor, pDevice );
}
 
void Semprul::Healthbarnew(LPDIRECT3DDEVICE9 pDevice,float x, float y, float Health)
{
	DWORD HPcol = GREEN;
	if (Health < 90)HPcol = YELLOW;
	if (Health < 80) HPcol = ORANGE;
	if (Health < 40) HPcol = RED;
	if (Health < 10) HPcol = BLACK;
	DrawBorder(x-1,y-1,52,5,1,BLACK,pDevice );
	FillRGB(x,y,Health/2,3,HPcol,pDevice );
}

void FillRGBhh( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice )
{
    if( w < 0 )w = 1;
    if( h < 0 )h = 1;
    if( x < 0 )x = 1;
    if( y < 0 )y = 1;

    D3DRECT rec = { x, y, x + w, y + h };
    pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}
void HealthEqui(LPDIRECT3DDEVICE9 pDevice, int x, int y, float Health)
{
const int SizeY[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
const D3DCOLOR colours[] = { D3DCOLOR_ARGB(255,255,000,000), D3DCOLOR_ARGB(255,255,000,000), D3DCOLOR_ARGB(255,255,000,000), D3DCOLOR_ARGB(255,255,000,000), ORANGE, ORANGE, ORANGE, ORANGE, YELLOW, YELLOW, YELLOW, YELLOW,  D3DCOLOR_ARGB(255,000,255,000),   D3DCOLOR_ARGB(255,000,255,000),   D3DCOLOR_ARGB(255,000,255,000),   D3DCOLOR_ARGB(255,000,255,000),   D3DCOLOR_ARGB(255,000,255,000),   D3DCOLOR_ARGB(255,000,255,000), BLUE, BLUE };	// this is our order
int boxSizeX = 2;	
	int boxSizeY = 6;
	int boxGap = 1;
for ( int i = 0 ; i < 20; i++ )
	{
		if ( Health > ( 5 * i ) )
			FillRGBhh(x,y, boxSizeX, SizeY[i],colours[i],pDevice);
		else
            FillRGBhh(x,y, boxSizeX, SizeY[i],D3DCOLOR_ARGB(255,128,128,128),pDevice);
		x = x + boxSizeX+ boxGap;	
	}
}


void Semprul::DrawCircle(int X, int Y, int radius, int numSides, DWORD Color) 
{ 

    D3DXVECTOR2 Line[128]; 
    float Step = PI * 2.0 / numSides; 
    int Count = 0; 
    for (float a=0; a < PI*2.0; a += Step) 
    { 
        float X1 = radius * cos(a) + X; 
        float Y1 = radius * sin(a) + Y; 
        float X2 = radius * cos(a+Step) + X; 
        float Y2 = radius * sin(a+Step) + Y; 
        Line[Count].x = X1; 
        Line[Count].y = Y1; 
        Line[Count+1].x = X2; 
        Line[Count+1].y = Y2; 
        Count += 2; 
    } 
    pLine->Begin(); 
    pLine->Draw(Line,Count,Color); 
    pLine->End(); 
}


void Semprul::DrawLine ( long Xa, long Ya, long Xb, long Yb, DWORD dwWidth, D3DCOLOR Color )
{
	D3DXVECTOR2 vLine[ 2 ];
	pLine->SetAntialias( 0 );

	pLine->SetWidth( (float)dwWidth );
	pLine->Begin();

	vLine[ 0 ][ 0 ] = (float)Xa;
	vLine[ 0 ][ 1 ] = (float)Ya;
	vLine[ 1 ][ 0 ] = (float)Xb;
	vLine[ 1 ][ 1 ] = (float)Yb;

	pLine->Draw( vLine, 2, Color );
	pLine->End();
}

bool Semprul::GetUserBone( D3DXVECTOR3 &Out,  int BoneIdx ,int Idx)
{
DWORD dwGameBase = *(DWORD*)ResultBaseHealth2;
if ( dwGameBase )
{
CGameBase* GameBase = (CGameBase*)( *(DWORD*)(dwGameBase + 0x14 + ( 0x4 * Idx ) ) );
if ( GameBase && GameBase->Bones)
{
Out.x = GameBase->Bones->BoneData[ BoneIdx ].BoneMatrix._41;
Out.y = GameBase->Bones->BoneData[ BoneIdx ].BoneMatrix._42;
Out.z = GameBase->Bones->BoneData[ BoneIdx ].BoneMatrix._43;
return true;
}
}
return false;
}

void Semprul::_patchPTR(unsigned long adr, unsigned long Ofset, DWORD dwValue)
{ DWORD A=0;
 if (IsBadReadPtr((PDWORD)adr,4)==0)
{ A=*(PDWORD)((DWORD)(adr))+Ofset;
if (IsBadReadPtr((PDWORD)A,4)==0)
{*(PDWORD)A=dwValue;
}
}
} 

int Semprul::GetMyCharaIndex()
{
unsigned long dwBase	= *(DWORD*)ResultBaseAmmo2;
CTeam *MyTeam = (CTeam*) ((dwBase + OFS_Team));
return MyTeam->iTeam;
}

void Semprul::PrivateOnly(void *adr, void *ptr, int size)
{ 
DWORD NextProtection;
VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &NextProtection);
Sleep(1);
Sleep(1);
RtlCopyMemory(adr,ptr,size);
Sleep(1);
Sleep(1);
VirtualProtect(adr,size,NextProtection, &NextProtection);
}

void Semprul::MoveMemo(void *adr, void *ptr, int size)
{ 
DWORD NextProtection;
VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &NextProtection);
Sleep(1);
Sleep(1);
MoveMemory(adr,ptr,size);
//SecureZeroMemory(ptr,size);
Sleep(1);
Sleep(1);
VirtualProtect(adr,size,NextProtection, &NextProtection);
}

void Semprul::CopyMemo(void *adr, void *ptr, int size)
{ 
DWORD NextProtection;
VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &NextProtection);
Sleep(1);
Sleep(1);
CopyMemory(adr,ptr,size);
//SecureZeroMemory(ptr,size);
Sleep(1);
Sleep(1);
VirtualProtect(adr,size,NextProtection, &NextProtection);
}

DWORD Semprul::CGameContextPointer(void) {

unsigned long dwBase = *(DWORD*)ResultBaseAmmo2;
return dwBase;
}

DWORD Semprul::HSTmpPointer(void) {

unsigned long dwBase = *(DWORD*)0xAE689C;
return dwBase;
}

void PrintText(LPD3DXFONT Font, long x, long y, D3DCOLOR fontColor, char *text, ...)
{
RECT rct;
rct.left = x - 1;
rct.right = x + 1;
rct.top = y - 1 ;
rct.bottom = y + 1;

if(!text) { return; }
va_list va_alist;
char logbuf[256] = {0};
va_start (va_alist, text);
_vsnprintf (logbuf+strlen(logbuf), sizeof(logbuf) - strlen(logbuf), text, va_alist);
va_end (va_alist);
RECT FontRect = { x, y, x, y };
Font->DrawText(0, logbuf, -1, &rct, DT_NOCLIP, fontColor);
}

void Semprul::PrintText(char pString[], int x, int y, D3DCOLOR col, ID3DXFont *font)
{
RECT FontRect = { x, y, x+500, y+30 };
font->DrawText( NULL, pString, -1, &FontRect, DT_LEFT | DT_WORDBREAK, col);
}

void Semprul::DrawItem ( int Shell , char iText[], int x, int y )
{
PrintText ( iText, x, y, WHITE, pFonts );
if ( Shell == 1 )
{
PrintText ( ": ON" , x+140, y, RED, pFonts );
}
if ( Shell == 0 )
{
PrintText ( ": OFF" , x+140, y, WHITE, pFonts );
}	
}

void Semprul::DrawItem2 ( int Shell , char iText[], int x, int y )
{
PrintText ( iText, x, y, WHITE, pFonts );
if ( Shell == 1 )
{
PrintText ( ": Body" , x+140, y, RED, pFonts );
}
if ( Shell == 0 )
{
PrintText ( ": Head" , x+140, y, WHITE, pFonts );
}	
}

void Semprul::DrawItem4 ( int Shell , char iText[], int x, int y )
{
PrintText ( iText, x, y, WHITE, pFonts );
if ( Shell == 1 )
{
PrintText ( ": M1887 D ", x+140, y, RED, pFonts );
}
if ( Shell == 0 )
{
PrintText ( ": OFF" , x+140, y, WHITE, pFonts );
}	
}
void Semprul::DrawItem5 ( int Shell , char iText[], int x, int y )
{
PrintText ( iText, x, y, WHITE, pFonts );
if ( Shell == 1 )
{
PrintText ( ": P90 Ext D" , x+140, y, RED, pFonts );
}
if ( Shell == 0 )
{
PrintText ( ": OFF" , x+140, y, WHITE, pFonts );
}	
}
void Semprul::DrawItem6 ( int Shell , char iText[], int x, int y )
{
PrintText ( iText, x, y, WHITE, pFonts );
if ( Shell == 1 )
{
PrintText ( ": AUG A3 G" , x+140, y, RED, pFonts );
}
if ( Shell == 0 )
{
PrintText ( ": OFF" , x+140, y, WHITE, pFonts );
}	
}
void Semprul::DrawItem3 ( int Shell , char iText[], int x, int y )
{
PrintText ( iText, x, y, WHITE, pFonts );
if ( Shell == 1 )
{
PrintText ( ": Tahan SHIFT" , x+140, y, RED, pFonts );
}
if ( Shell == 0 )
{
PrintText ( ": OFF" , x+140, y, WHITE, pFonts );
}	
}

void Semprul::MakeJMP( BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen )
{
DWORD dwOldProtect, dwBkup, dwRelAddr;
VirtualProtect(pAddress, dwLen, PAGE_EXECUTE_READWRITE, &dwOldProtect);
dwRelAddr = (DWORD) (dwJumpTo - (DWORD) pAddress) - 5;
*pAddress = 0xE9;
*((DWORD *)(pAddress + 0x1)) = dwRelAddr;
for(DWORD x = 0x5; x < dwLen; x++) *(pAddress + x) = 0x90;
VirtualProtect(pAddress, dwLen, dwOldProtect, &dwBkup);
return;
}

void Semprul::WriteJMP ( PVOID bSource, PVOID bAddress, int Lenght )
{
	DWORD Protection, OldProtection;
	VirtualProtect ( bSource, Lenght, PAGE_EXECUTE_READWRITE, &Protection );
	memcpy ( bSource, bAddress, Lenght );
	VirtualProtect ( bSource, Lenght, Protection, &OldProtection );
}

BYTE OrginalByte[7];
DWORD Semprul::MyDetour(DWORD bSource, DWORD iAddress)
{
	ReadProcessMemory ( GetCurrentProcess (), (LPVOID)(iAddress -0x5), (PBYTE)(OrginalByte),
		sizeof (OrginalByte), 0 );
	BYTE TypeJMP[7] = {0xE9,0x00,0x00,0x00,0x00,0xEB,0xF9};
	*(DWORD*)(&TypeJMP[1]) = (bSource - ( iAddress - 5 ))-5;
	WriteJMP( ( PVOID )( iAddress - 5 ),( PVOID )TypeJMP, sizeof( TypeJMP ) );
	return (( iAddress - 5 )+7);
}

PBYTE Semprul::HookVTableFunction( PDWORD* dwVTable, PBYTE dwHook, INT Index )
{
    DWORD dwOld = 0;
    VirtualProtect((void*)((*dwVTable) + (Index*4) ), 4, PAGE_EXECUTE_READWRITE, &dwOld);
    PBYTE pOrig = ((PBYTE)(*dwVTable)[Index]);
    (*dwVTable)[Index] = (DWORD)dwHook;
    VirtualProtect((void*)((*dwVTable) + (Index*4)), 4, dwOld, &dwOld);
    return pOrig;
}



D3DTLVERTEX CreateD3DTLVERTEX (float X, float Y, float Z, float RHW, D3DCOLOR color, float U, float V)
{
	D3DTLVERTEX v;

	v.fX = X;
	v.fY = Y;
	v.fZ = Z;
	v.fRHW = RHW;
	v.Color = color;
	v.fU = U;
	v.fV = V;

	return v;
}

#define PISSS 3.14159265
void Semprul::Circle( float x, float y, float rad, bool center, DWORD color ,LPDIRECT3DDEVICE9 pDevice)
{
	const int NUMPOINTS = 34;

	if(!center)
	{
		x -= rad;
		y -= rad;
	}

	D3DTLVERTEX Circle[NUMPOINTS + 1];
	int i;
	float X;
	float Y;
	float Theta;
	float WedgeAngle;
	WedgeAngle = (float)( (2*PISSS) / NUMPOINTS );
	for( i=0; i<=NUMPOINTS; i++ )
	{
		Theta = i * WedgeAngle;
		X = (float)( x + rad * cos(Theta) );
		Y = (float)( y - rad * sin(Theta) );
		Circle[i] = CreateD3DTLVERTEX( X, Y, 0.0f, 1.0f, color, 0.0f, 0.0f );
	}
	pDevice	->	SetFVF			( D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1 );
	pDevice	->	SetTexture		( 0, NULL );
	pDevice	->	DrawPrimitiveUP	( D3DPT_LINESTRIP, NUMPOINTS, &Circle[0], sizeof(Circle[0]) );
}

void Semprul::Crosshair(LPDIRECT3DDEVICE9 pDevice, D3DCOLOR Color)
{
		int size = 8, strong = 1;

		int iCenterX = GetSystemMetrics( 0 ) / 2;
		int iCenterY = GetSystemMetrics( 1 ) / 2;

		if( iCenterX < 20 && iCenterY < 20 )
		{
			iCenterX = ( GetSystemMetrics( 0 ) / 2 );
			iCenterY = ( GetSystemMetrics( 1 ) / 2 );
		}

		D3DRECT rec_a = { iCenterX - size, iCenterY, iCenterX + size, iCenterY + strong};
		D3DRECT rec_b = { iCenterX, iCenterY - size, iCenterX + strong,iCenterY + size};
		pDevice->Clear(1, &rec_a, D3DCLEAR_TARGET, Color, 0,  0);
		pDevice->Clear(1, &rec_b, D3DCLEAR_TARGET, Color, 0,  0);
}



bool Semprul::IsInScreen(int Index)
{
DWORD ModuleHandle = (DWORD)GetModuleHandleA("Pointblank.exe");
D3DXVECTOR3 PlayerPos;
D3DXVECTOR3 RetPos;
GetUserBone(PlayerPos,0,Index);
return YoWorlToScreenGa(npDevice,PlayerPos,RetPos);
}

#define Detour_Type_0xE9 1 
#define Detour_Type_0xB8 2 
#define Detour_Type_0x68 3 
#define Detour_Type_0xE8 4 
DWORD KentotDetour(DWORD dwThread, DWORD dwAdress, DWORD dwType, DWORD dwSize)
{
	DWORD dwDetour, dwProtect, i;
	if (dwAdress&&dwThread&&dwSize >= dwSize)
	{
		dwDetour = (DWORD)VirtualAlloc(0, dwSize + dwSize, 0x1000, 0x40);
		if (dwDetour&&VirtualProtect((VOID*)dwAdress, dwSize, 0x40, &dwProtect))
		{
			for (i = 0; i<dwSize; i++)
			{
				*(BYTE*)(dwDetour + i) = *(BYTE*)(dwAdress + i);
			}
			switch (dwType)
			{
			case Detour_Type_0xE9:
			{
									 *(BYTE*)(dwDetour + dwSize + 0) = 0xE9;
									 *(DWORD*)(dwDetour + dwSize + 1) = (dwAdress - dwDetour - dwSize);
									 *(BYTE*)(dwAdress + 0) = 0xE9;
									 *(DWORD*)(dwAdress + 1) = (dwThread - dwAdress - dwSize);
			}
				break;
			case Detour_Type_0xE8:
				*(BYTE*)(dwDetour + dwSize + 0) = 0xE8;
				*(DWORD*)(dwDetour + dwSize + 1) = (dwAdress - dwDetour - dwSize);
				*(BYTE*)(dwAdress + 0) = 0xE8;
				*(DWORD*)(dwAdress + 1) = (dwThread - dwAdress - dwSize);
				break;
			case Detour_Type_0xB8:
			{
									 *(BYTE*)(dwDetour + dwSize + 0) = 0xB8;
									 *(DWORD*)(dwDetour + dwSize + 1) = (dwAdress + dwSize);
									 *(WORD*)(dwDetour + dwSize + 5) = 0xE0FF;
									 *(BYTE*)(dwAdress + 0) = 0xB8;
									 *(DWORD*)(dwAdress + 1) = (dwThread);
									 *(WORD*)(dwAdress + 5) = 0xE0FF;
			}
				break;
			case Detour_Type_0x68:
			{
									 *(BYTE*)(dwDetour + dwSize + 0) = 0x68;
									 *(DWORD*)(dwDetour + dwSize + 1) = (dwAdress + dwSize);
									 *(WORD*)(dwDetour + dwSize + 5) = 0xC3;
									 *(BYTE*)(dwAdress + 0) = 0x68;
									 *(DWORD*)(dwAdress + 1) = (dwThread);
									 *(WORD*)(dwAdress + 5) = 0xC3;
			}
				break;
			}
			VirtualProtect((VOID*)dwAdress, dwSize, dwProtect, &dwProtect);
			VirtualProtect((VOID*)dwDetour, dwSize + dwSize, 0x20, &dwProtect);
			return dwDetour;
		}
	}
	return (0);
}

void Func6(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3,DWORD Ofs4,BYTE Value) {
DWORD Temp=0; 
if (IsBadReadPtr((PDWORD)Base,4)==0){ 
Temp=*(PDWORD)((DWORD)(Base))+Ofs1; 
if (IsBadReadPtr((PDWORD)Temp,4)==0){ 
Temp=*(PDWORD)((DWORD)(Temp))+Ofs2; 
if (IsBadReadPtr((PDWORD)Temp,4)==0){ 
Temp=*(PDWORD)((DWORD)(Temp))+Ofs3; 
if (IsBadReadPtr((PDWORD)Temp,4)==0){ 
Temp=*(PDWORD)((DWORD)(Temp))+Ofs4; 
if (IsBadReadPtr((PDWORD)Temp,4)==0){ 
*(PBYTE)Temp=Value; } } } } } }

DWORD DetourB8( DWORD  SrcVA, DWORD  DstVA, DWORD  Size )
{
DWORD DetourVA, dwProtect, i;

#define SIZEOF_MOVEAX_JMPEAX 7

	if ( SrcVA && DstVA && Size >= SIZEOF_MOVEAX_JMPEAX )
	{
		DetourVA = (DWORD) VirtualAlloc( 
			NULL, Size + SIZEOF_MOVEAX_JMPEAX, 
			MEM_COMMIT, PAGE_EXECUTE_READWRITE );

		if ( DetourVA && VirtualProtect( (VOID*)SrcVA, Size, PAGE_EXECUTE_READWRITE, &dwProtect ) )
		{
			for ( i=0; i < Size; i++ ) {
				*(BYTE*)( DetourVA + i ) = *(BYTE*)( SrcVA + i );
			}
			
			*(BYTE*)( DetourVA + Size + 0 ) = 0xB8;
			*(DWORD*)( DetourVA + Size + 1 ) = ( SrcVA + Size );
			*(WORD*)( DetourVA + Size + 5 ) = 0xE0FF;

			*(BYTE*)( SrcVA + 0 ) = 0xB8;
			*(DWORD*)( SrcVA + 1 ) = ( DstVA );
			*(WORD*)( SrcVA + 5 ) = 0xE0FF;

			VirtualProtect( (VOID*)SrcVA, Size, dwProtect, &dwProtect );

			VirtualProtect( (VOID*)DetourVA, Size + 
				SIZEOF_MOVEAX_JMPEAX, PAGE_EXECUTE_READ, &dwProtect );

	    	return DetourVA;
		}
	}
	return (0);
}