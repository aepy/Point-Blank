#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "Logger.h"
#include "XStr.h"
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib,"d3dx9.lib")

D3DVIEWPORT9 Viewport;
D3DVIEWPORT9 g_ViewPort;
LPD3DXLINE pLine    = NULL;
LPDIRECT3DDEVICE9 npDevice; 
LPDIRECT3DDEVICE9 oDevice = NULL;
LPD3DXFONT fName	= NULL;
LPD3DXFONT fSmall	= NULL;
LPD3DXFONT Title    = NULL;
DWORD TeamColor;
D3DVECTOR Player;
D3DVECTOR HeadPos;
D3DVECTOR PlayerScaled;
D3DVECTOR HeadScaled;
D3DVECTOR BonePos;
BOOL Create;
char *Moptfolder        []  = {"Open", "Close"}; // Buat on Off nya
//char *Moptonoff         []  = {"OFF", "ON"};
char *MoptGExit         []  = {"OFF", "END"};
char *MoptGhost         []  = {"OFF", "L-ALT"};
char *MoptReplace       []  = {"OFF", "Barett M82A1", "Kriss SVD", "Famas G2 M203", "SPASS-15 MSC", "Cheytac M200", "P90 Ext D", "M1887 D", "Dual UZI Sil.SL", "P90 MCS", "AK47 FC", "AUG A3 G"};
char *MoptBiar          []  = {"OFF", "HOME"};
char *MoptColor         []  = {"OFF", "Merah", "Kuning", "Hijau", "Orange", "Biru", "Hitam"};
char *Mopttarget        []  = {"Head", "Body"};
#define RED				D3DCOLOR_ARGB(255, 245, 000, 000)
#define WHITE			D3DCOLOR_ARGB(255, 255, 255, 255)
#define YELLOW			D3DCOLOR_ARGB(255, 255, 255, 000) 
#define GREEN			D3DCOLOR_ARGB(255, 000, 255, 000)
#define ORANGE			D3DCOLOR_ARGB(255, 255, 125, 000)
#define BLACK			D3DCOLOR_ARGB(150, 000, 000, 000)
#define BLUE			D3DCOLOR_ARGB(255, 19, 84, 199) 
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
RenderContext *pRC	= (RenderContext*)(dwGFX + 0x1AD2F0);

class RenderData
{
public:
	char unknown0[2240];
	D3DXMATRIX ViewMatrix;
	D3DXMATRIX ProjMatrix;
	D3DXMATRIX World; 
	D3DXMATRIX WorldView[80];
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


class CBone
{
public:
	D3DXMATRIX BoneMatrix;
};


class CBonesContext
{
public:
	char   Unk[0xC8];
	CBone* BoneData;
};

// Pasang Bom Sembarang//

class cGameStageInfo
{
public: 
char _pad1[0x4CF58];//0x0 
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
class cGameBases
{
public:
char _pad1[0x4CF58];
cGameStageInfo* StageInfo;
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
	char           Unk[0x55C];
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
WORD iHack; //0x0010
};//Size=0x0012

struct CNames
{
    char szNames[33];
};

class CGameCharaBoneContext
{
public:
char nop[0xC8];
Bone* m_Bone;
};


class CGameCharaBase
{
public:
char nop[0x55C];
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
VOID WriteJMP ( PVOID bSource, PVOID bAddress, int Lenght );
bool YoWorlToScreenGa(LPDIRECT3DDEVICE9 pDevice, D3DVECTOR Player,D3DVECTOR &PlayerScaled);
PBYTE HookVTableFunction( PDWORD* dwVTable, PBYTE dwHook, INT Index );
void DrawCircle(int X, int Y, int radius, int numSides, DWORD Color);
void Healthbarnew(LPDIRECT3DDEVICE9 pDevice,float x, float y, float Health);
DWORD MyDetour(DWORD bSource, DWORD iAddress);
DWORD Semprul::GetAmmoIndex(DWORD dwPtr,DWORD A1,DWORD B1,DWORD C1);
void Semprul::c_WeaponIndex_B(unsigned long adr, unsigned long Ofset1, unsigned long Ofset2, unsigned long Ofset3, unsigned long Ofset4, DWORD dwValue);
void Semprul::gEtWeapon_IndexA(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, DWORD Value);
void DrawItem4 ( int Shell , char iText[], int x, int y );
void DrawItem5 ( int Shell , char iText[], int x, int y );
void DrawItem6 ( int Shell , char iText[], int x, int y );
void _patchPTR(unsigned long adr, unsigned long Ofset, DWORD dwValue);
int GetMyCharaIndex();
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
void DrawBoxESP( int x, int y, int w, int h, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice );
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
case 0xC79:
pKey = *(PWORD)Temp;
case 0xCC0:
pBase = *(PWORD)Temp;
case 0xC94:
pValue = *(PWORD)Temp;
case 0xC98:
pSoul = *(PWORD)Temp;
}}}}}}
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

DWORD Function_Two (DWORD Base,DWORD Ofs1,DWORD Ofs2, BYTE Value)
{
DWORD Temp=NULL;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
*(PBYTE)Temp=Value;
}}}
return (0);
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
bool Semprul::MyWorld2Screen (D3DXVECTOR3 inpos, D3DXVECTOR3 &outpos)
{
DWORD dwRenderData = (DWORD)GetModuleHandleA("i3GfxDx.dll") + 0x1AD2F0;
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

D3DXVECTOR3 Semprul::GetUserVector( int Index )
{
DWORD ADR_PLAYER = *(DWORD*)(c_pPlayerBase); 
DWORD OldProtect; 
DWORD pCalculate = *(DWORD*)(ADR_PLAYER + 4 * Index + 0x272E4); // ptr
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
DWORD BasePlayer_B = *(DWORD*)(ModuleHandle + g_pESP);
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
DWORD BasePlayer_B = *(DWORD*)(ModuleHandle + g_pESP);
if(IsBadReadPtr((void*)BasePlayer_B,4))return 0;
DWORD PlayerIndexA = *(DWORD*)(BasePlayer_B + 0x14 + (myIDX * 4));
if(IsBadReadPtr((void*)PlayerIndexA,4))return 0;
DWORD PlayerIndexB = *(DWORD*)(PlayerIndexA + 0x260);
if(IsBadReadPtr((void*)PlayerIndexB,4))return 0;
DWORD IsTargetingEnemy = *(DWORD*)(PlayerIndexB + 0x94E8);
if(IsBadReadPtr((void*)IsTargetingEnemy,4))return 0;
return IsTargetingEnemy;
}

bool Semprul::IsAlive(int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandle("Pointblank.exe");
unsigned long dwBase2	= *(DWORD*)(dwI3EXEC + g_pESP);
CHealth		*Health		= (CHealth*) ((dwBase2 + 0x264) + Index * 0x20);
if(Health->CurHP > 0.1f)
return true;
return false;
}

bool Semprul::GetBattleState()
{
DWORD ModuleHandle				= (DWORD)GetModuleHandle("PointBlank.exe");
unsigned long xBase				= *(DWORD*)(ModuleHandle + g_pPelorReload);
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
DWORD dwGameBase = *(DWORD*)c_pESP;
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
unsigned long dwBase	= *(DWORD*)c_pPlayerBase;
CTeam *MyTeam = (CTeam*) ((dwBase + P_BaseTEAM));
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

unsigned long dwBase = *(DWORD*)c_pPlayerBase;
return dwBase;
}

DWORD Semprul::HSTmpPointer(void) {

unsigned long dwBase = *(DWORD*)0xAE689C;
return dwBase;
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
int x = ( GetSystemMetrics( 0 ) / 2);
int y = ( GetSystemMetrics( 1 ) / 2);
Circle (x,y,6,true,Color,pDevice);
FillRGB(x-10, y, 7, 1,Color,pDevice);//Left line
FillRGB(x+4, y, 7, 1,Color,pDevice);//Right line
FillRGB(x, y-10, 1, 7,Color,pDevice);//Top line
FillRGB(x, y+4, 1, 7,Color,pDevice);//Bottom line
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

void PachtChara(DWORD B,DWORD A1,DWORD B1, DWORD ISI){
DWORD A=0;
if (IsBadReadPtr((PDWORD)B,4)==0){
A=*(PDWORD)((DWORD)(B))+A1;
if (IsBadReadPtr((PDWORD )A,4)==0){
A=*(PDWORD)((DWORD)(A ))+ B1;
if (IsBadReadPtr((PDWORD)A,4)==0) {
{*(PDWORD)A=ISI;}}}}}

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