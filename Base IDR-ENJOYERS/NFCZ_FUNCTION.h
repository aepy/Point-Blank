
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "NFCZ_LOGGGER.h"
#include "XStr.h"
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
//----------------------------------------------------------------------------------------------------------------
DWORD TeamColor;

D3DVIEWPORT9 viewP;
D3DVIEWPORT9 Viewport;
D3DXVECTOR3 vStart,vEnd;
D3DXVECTOR3 vvStart,vvEnd;
D3DXVECTOR3 vStart2,vEnd2;
D3DXVECTOR3 vvStart2,vvEnd2;
D3DXVECTOR3 vStart10,vEnd10;
D3DXVECTOR3 vvStart10,vvEnd10;
#define MAROON			     D3DCOLOR_ARGB(255, 142, 30, 0)
#define LGRAY		         D3DCOLOR_ARGB(255, 174, 174, 174)
#define AQUA                 D3DCOLOR_ARGB(255, 000, 255, 255)
#define GOLD		   		 D3DCOLOR_ARGB(255, 255, 215, 000)
#define GREY			     D3DCOLOR_ARGB(255, 128, 128, 128) 
#define SKYBLUE			     D3DCOLOR_ARGB(255, 0,   180, 255)
#define PURPLE			     D3DCOLOR_ARGB(255, 125, 000, 255) 
#define RED				     D3DCOLOR_ARGB(255, 245, 000, 000)
#define WHITE			     D3DCOLOR_ARGB(255, 255, 255, 255)
#define YELLOW			     D3DCOLOR_ARGB(255, 255, 255, 000) 
#define GREEN			     D3DCOLOR_ARGB(255, 000, 255, 000)
#define ORANGE			     D3DCOLOR_ARGB(255, 255, 125, 000)
#define BLACK			     D3DCOLOR_ARGB(150, 000, 000, 000)
#define BLUE			     D3DCOLOR_ARGB(255, 19, 84, 199) 
#define DEEPSKYBLUE          D3DCOLOR_ARGB(255, 30, 144, 255)
#define CHOCOLATE2           D3DCOLOR_ARGB(255, 238, 118, 33)
#define GOLD2			     D3DCOLOR_ARGB(255, 238, 201, 0)
#define SQUA			     D3DCOLOR_ARGB(255, 0, 255, 255)
LPD3DXFONT pFont	= NULL;
//LPD3DXFONT fName	= NULL;
//LPD3DXFONT Title    = NULL;
LPD3DXLINE pLine    = NULL;
////--------------------------------------------------------------------
class RenderContext;
class RenderData;
//--------------------------------------------------------------------
DWORD dwGFX			= (DWORD)GetModuleHandle("i3GfxDx.dll");
RenderContext *pRC	= (RenderContext*)(dwGFX + 0x1B22B0);
//RenderContext *pRC	= (RenderContext*)(dwGFX + ResultBaseRender);//kalo pake ini esp nya gk gerak
//--------------------------------------------------------------------

//--------------------------------------------------------------------
class RenderData{
public:
char unknown0[32];
D3DXMATRIX ViewMatrix;
D3DXMATRIX ProjMatrix; 
char _0x00A0[4736];
D3DXMATRIX World;
D3DXMATRIX WorldView[80];
};
//--------------------------------------------------------------------
class RenderContext{
public:
RenderData* pRenderData;
};
//--------------------------------------------------------------------
class CBone{
public:
D3DXMATRIX BoneMatrix;
};
//--------------------------------------------------------------------
class CBonesContext{
public:
char nop[0xD8];
CBone* BoneData;
};
//--------------------------------------------------------------------
class CGameBase{
public:
char nop[0x558];
CBonesContext* Bones;
};
//--------------------------------------------------------------------
class Bone{
public:
D3DXMATRIX m_Bone;
};
//--------------------------------------------------------------------
class CGameCharaBoneContext{
public:
char nop[0xD8];
Bone* m_Bone;
};
//--------------------------------------------------------------------
class CGameCharaBase{
public:
char nop[0x558];
CGameCharaBoneContext* m_BoneContext;
};
//--------------------------------------------------------------------
struct D3DTLVERTEX{
float fX;
float fY;
float fZ;
float fRHW;
D3DCOLOR Color;
float fU;
float fV;
};
//--------------------------------------------------------------------
struct CNames{
char szNames[33];
};
//--------------------------------------------------------------------
struct CHealth{
float CurHP;
};
//--------------------------------------------------------------------
struct CRank{
BYTE iRank;
};
//--------------------------------------------------------------------
struct CTeam{
BYTE iTeam;
};
//--------------------------------------------------------------------
class GM;
class GM{
public:
BYTE iRank;
char _0x0001[15];
DWORD iHack;
};
//--------------------------------------------------------------------
struct CPlayers{
float yaw;
float pitch;
D3DXVECTOR3 pos;
char unkno8[2304];
};
//--------------------------------------------------------------------
class cCharaMainInfo{
public:
char _pad1 [0x94E8];
DWORD PlayerTarget;
};
//--------------------------------------------------------------------
class CDeathPlayer{
public:
BYTE Death[16];
};
//--------------------------------------------------------------------
class CLocalPlayerID{
public:
BYTE ID;
};
DWORD d;
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
//--------------------------------------------------------------------
class cGameStageInfo{
public:
char _pad1[0x230];
D3DXVECTOR3 BombPositionA; 
D3DXVECTOR3 BombPositionB;
};
//--------------------------------------------------------------------
class cGameBases{
public:
char _pad1[0x3B84C];
cGameStageInfo* StageInfo;
};

//--------------------------------------------------------------------
class CLog; 
class CLog{
public:
BYTE iLog;
};
//--------------------------------------------------------------------
class CKill;
class CKill{
public:
BYTE bKill;
char _0001[1];
BYTE bDead;
char _0003[1];
};
//--------------------------------------------------------------------
struct TeamScore{
public:
WORD  TScoreRed;
WORD  TScoreBlue;
};
//--------------------------------------------------------------------
extern RenderContext *pRC;
//--------------------------------------------------------------------

//--------------------------------------------------------------------
DWORD CGameContextPointer(void) {
unsigned long dwBase = *(DWORD*)ResultBasePlayer2;
return dwBase;
}
//--------------------------------------------------------------------
DWORD GetBasePlayerHealth(void) {
unsigned long dwBase2 = *(DWORD*)ResultBaseHealth2;
return dwBase2;
}
//--------------------------------------------------------------------
CLog		*pPing(UINT i)	{
return (CLog*)((CGameContextPointer() + ResultPing) + i * 1);
}
//--------------------------------------------------------------------
CKill		*pKill(UINT i)	{
return (CKill*)((CGameContextPointer() + ResultKill) + i * 4);
}
//--------------------------------------------------------------------
CNames		*oNames(UINT i)	{
return (CNames*)((CGameContextPointer() + 0x295D4) + i * NAMESIZE);
}
//--------------------------------------------------------------------
CHealth		*oHealth(UINT i)	{
return (CHealth*)((GetBasePlayerHealth() + PTR_HEALTH) + i * ALIVESIZE);
}
//--------------------------------------------------------------------
void UknownScript(PDWORD target, PDWORD newfunc){
DWORD Jmpto=(DWORD)(newfunc)-(DWORD)target-5;
DWORD a;
VirtualProtect(target, 8, PAGE_EXECUTE_READWRITE, &a);
*(PBYTE)(target)=0xE9;
*(PDWORD)((DWORD)(target)+1)=Jmpto;
VirtualProtect(target, 8, a, &a);
}

//--------------------------------------------------------------------
DWORD MakePTR(BYTE *MemoryTarget, DWORD FunctionTarget){
DWORD dwOldProtect,dwBkup;
DWORD dwRetn = *(DWORD*)(MemoryTarget);
VirtualProtect(MemoryTarget, 4, PAGE_EXECUTE_READWRITE, &dwOldProtect);
*((DWORD *)(MemoryTarget)) = FunctionTarget;
VirtualProtect(MemoryTarget, 4, dwOldProtect, &dwBkup);
return dwRetn;
}
//--------------------------------------------------------------------
DWORD NNCZPeler(BYTE *MemoryTarget, DWORD FunctionTarget){
Sleep(5);
*((DWORD *)(MemoryTarget)) = FunctionTarget;
Sleep(5);
return 0;
}
//--------------------------------------------------------------------
DWORD GetPlayerTarget(int myIDX){
DWORD ModuleHandle = (DWORD)GetModuleHandleA("PointBlank.exe");
DWORD BasePlayer_B = *(DWORD*)(ModuleHandle + ResultBaseHealth);
if(IsBadReadPtr((void*)BasePlayer_B,4))return 0;
DWORD PlayerIndexA = *(DWORD*)(BasePlayer_B + 0x14 + (myIDX * 4));
if(IsBadReadPtr((void*)PlayerIndexA,4))return 0;
DWORD PlayerIndexB = *(DWORD*)(PlayerIndexA + PTR_GHOST);
if(IsBadReadPtr((void*)PlayerIndexB,4))return 0;
DWORD IsTargetingEnemy = *(DWORD*)(PlayerIndexB + 0x94E8);
if(IsBadReadPtr((void*)IsTargetingEnemy,4))return 0;
return IsTargetingEnemy;
}
//--------------------------------------------------------------------
DWORD GetAmmoIndex(DWORD dwPtr,DWORD A1,DWORD B1,DWORD C1){
DWORD C=0;
if (IsBadReadPtr((PDWORD)dwPtr,4)==0){
C=*(PDWORD)((DWORD)(dwPtr))+A1;
if (IsBadReadPtr((PDWORD )C,4)==0){
C=*(PDWORD)((DWORD)(C ))+ B1;
if (IsBadReadPtr((PDWORD)C,4)==0) {
C=*(PDWORD)((DWORD)(C ))+ C1;
if (IsBadReadPtr((PDWORD)C,4)==0) {
return *(PDWORD)C;
}
}
}
}
return C;
}
//--------------------------------------------------------------------
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
//--------------------------------------------------------------------
void GetWeapon_IndexA(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, DWORD Value){ 
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
//--------------------------------------------------------------------
DWORD TestPacth(DWORD dwPtr,DWORD A1,DWORD B1,DWORD C1){
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
//--------------------------------------------------------------------
void c_WeaponIndex_B(unsigned long adr, unsigned long Ofset1, unsigned long Ofset2, unsigned long Ofset3, unsigned long Ofset4, DWORD dwValue){ 
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
void FourWriteHack (DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, BYTE Value){
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
//--------------------------------------------------------------------
void GoWeaponHack(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, BYTE Value){ 
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
//--------------------------------------------------------------------
void PatchValue(DWORD BaseOfs, DWORD Offset1, DWORD Offset2, DWORD Offset3, DWORD Value){
DWORD Temp=0;
if (IsBadReadPtr((PDWORD)BaseOfs, 4) == 0){ 
Temp = *(PDWORD)((DWORD)(BaseOfs)) + Offset1;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
Temp = *(PDWORD)((DWORD)(Temp)) + Offset2;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
Temp = *(PDWORD)((DWORD)(Temp)) + Offset3;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){
*(PDWORD)Temp = Value;
}
}
}
}
}
//--------------------------------------------------------------------
void Function_One(DWORD Base,DWORD Ofs1, BYTE Value){ 
DWORD Temp=NULL;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
*(PBYTE)Temp=Value;
}
}
}
//--------------------------------------------------------------------
void PactJumper(DWORD Base,DWORD Ofs1, BYTE Value){
DWORD Temp=NULL;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
*(PBYTE)Temp=Value;
}
}
}
//--------------------------------------------------------------------
void WM_Pos1(void *adr, void *ptr, int size){{
DWORD dwElla;
VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &dwElla);
Sleep(1);
Sleep(1);
memcpy(adr,ptr,size);
Sleep(1);
Sleep(1);
VirtualProtect(adr,size,dwElla, &dwElla);
}
}
//--------------------------------------------------------------------
void PrivateOnly(void *adr, void *ptr, int size){ 
DWORD NextProtection;
VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &NextProtection);
Sleep(1);
Sleep(1);
RtlCopyMemory(adr,ptr,size);
Sleep(1);
Sleep(1);
VirtualProtect(adr,size,NextProtection, &NextProtection);
}
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
//--------------------------------------------------------------------
bool MakePoint(unsigned long ADRexec, int OFSexec, int PTRexec){
if (!IsBadReadPtr((void*)ADRexec, sizeof(unsigned long))){
if (!IsBadReadPtr((void*)(*(unsigned long*)ADRexec + OFSexec), sizeof(unsigned long))){
*(int*)(*(unsigned long*)ADRexec + OFSexec) = PTRexec;
}
}
return 0;
}
//--------------------------------------------------------------------
int WritePointer2 (unsigned long ads, unsigned long ptr, unsigned long ptr2,int value){
__try{
unsigned long WrtPointer = false;
WrtPointer = *(unsigned long*)((ads))+ptr;
WrtPointer = *(unsigned long*)((WrtPointer))+ptr2;
*(int*)(WrtPointer) = value;
return true;
}
__except (EXCEPTION_EXECUTE_HANDLER){
return false;
}
}
//--------------------------------------------------------------------
void DrawStringESP(int x, int y, DWORD color, const char *fmt, ...){
RECT FontPos = { x, y, x + 200, y + 16 };
char buf[1024] = {'\0'};
va_list va_alist;
va_start(va_alist, fmt);
vsprintf_s(buf, fmt, va_alist);
va_end(va_alist);
fName->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
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
//--------------------------------------------------------------------

bool ADDXW2S(LPDIRECT3DDEVICE9 pDevice, D3DVECTOR Player,D3DVECTOR &PlayerScaled)
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
//--------------------------------------------------------------------
void PachtChara(DWORD B,DWORD A1,DWORD B1, DWORD ISI){
DWORD A=0;
if (IsBadReadPtr((PDWORD)B,4)==0){
A=*(PDWORD)((DWORD)(B))+A1;
if (IsBadReadPtr((PDWORD )A,4)==0){
A=*(PDWORD)((DWORD)(A ))+ B1;
if (IsBadReadPtr((PDWORD)A,4)==0) {
{*(PDWORD)A=ISI;}}}}}
//--------------------------------------------------------------------
void PatchRecoil(DWORD B,DWORD A1,DWORD B1, DWORD ISI)
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
//--------------------------------------------------------------------
bool GetBattleState1() { 
DWORD BaseG = (DWORD)GetModuleHandleA("PointBlank.exe");
unsigned long xBase = *(DWORD*)(BaseG + ResultBaseAmmo); 
if(xBase > NULL){ 
return true; 
}
return false; 
}
//--------------------------------------------------------------------
void patchPTR(unsigned long adr, unsigned long Ofset1, DWORD dwValue){ 
DWORD A=0;
if(IsBadReadPtr((PDWORD)adr,4))return;
A=*(PDWORD)((DWORD)(adr))+Ofset1;
if(IsBadReadPtr((PDWORD)A,4))return;
if(*(PDWORD)A!=dwValue)*(PDWORD)A=dwValue;
}
//--------------------------------------------------------------------
DWORD Read(DWORD dwPtr, DWORD dwOfs){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return *(PDWORD)C; 
} } 
return C;
}
//--------------------------------------------------------------------
bool IsAlive(int Index){
DWORD dwI3EXEC	 = (DWORD)GetModuleHandle("PointBlank.exe");
unsigned long dwBase2	= *(DWORD*)(dwI3EXEC + ResultBaseHealth);
CHealth		*Health		= (CHealth*) ((dwBase2 + PTR_HEALTH) + Index * ALIVESIZE);
if(Health->CurHP > 0.1f)
return true;
return false;
}
//--------------------------------------------------------------------
bool GetUserBone( D3DXVECTOR3 &Out,  int BoneIdx ,int Idx){
DWORD dwGameBase = *(DWORD*)ResultBaseHealth2;
if ( dwGameBase ){
CGameBase* GameBase = (CGameBase*)( *(DWORD*)(dwGameBase + 0x14 + ( 0x4 * Idx ) ) );
if ( GameBase && GameBase->Bones){
Out.x = GameBase->Bones->BoneData[ BoneIdx ].BoneMatrix._41;
Out.y = GameBase->Bones->BoneData[ BoneIdx ].BoneMatrix._42;
Out.z = GameBase->Bones->BoneData[ BoneIdx ].BoneMatrix._43;
return true;
}
}
return false;
}
//--------------------------------------------------------------------
D3DXVECTOR3 GetUserBone2(int Idx ,int BoneIndex){
D3DXVECTOR3 Out;
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA("PointBlank.exe");
unsigned long dwGameBase = *(DWORD*)(dwI3EXEC + ResultBaseHealth);
if ( dwGameBase ){
CGameCharaBase* GameBase = (CGameCharaBase*)( *(DWORD*)(dwGameBase + 0x14 + ( 0x4 * Idx ) ) );
if ( GameBase && GameBase->m_BoneContext ){
Out.x = GameBase->m_BoneContext->m_Bone[ BoneIndex ].m_Bone._41;
Out.y = GameBase->m_BoneContext->m_Bone[ BoneIndex ].m_Bone._42;
Out.z = GameBase->m_BoneContext->m_Bone[ BoneIndex ].m_Bone._43;
}
}
return Out;
}
//--------------------------------------------------------------------
D3DXVECTOR3 GetUserVector(int Index){
DWORD ADR_PLAYER = *(DWORD*)(ResultBasePlayer2);
DWORD OldProtect;
DWORD pCalculate = *(DWORD*)(ADR_PLAYER + 4 * Index + PTR_Player);
VirtualProtect ( (LPVOID)(pCalculate), sizeof (pCalculate), PAGE_EXECUTE_READWRITE, &OldProtect );
CPlayers	*Players	= (CPlayers*)(pCalculate + 0x64 );
VirtualProtect ( (LPVOID)(pCalculate), sizeof (pCalculate), OldProtect, &OldProtect );
return Players->pos;
}
//--------------------------------------------------------------------
float CalcDistance( D3DXVECTOR3 VecA, D3DXVECTOR3 VecB ){
return sqrt( ( ( VecA.x - VecB.x ) * ( VecA.x - VecB.x ) ) +
( ( VecA.y - VecB.y ) * ( VecA.y - VecB.y ) ) +
( ( VecA.z - VecB.z ) * ( VecA.z - VecB.z ) ) );
}
//--------------------------------------------------------------------
void PrintText(char pString[], int x, int y, D3DCOLOR col, ID3DXFont *font){
RECT FontRect = { x, y, x+500, y+50 };
font->DrawText( NULL, pString, -1, &FontRect, DT_LEFT | DT_WORDBREAK, col);
}
//--------------------------------------------------------------------
int GetMyCharaIndex(){
unsigned long dwBase	= *(DWORD*)ResultBasePlayer2;
CTeam *MyTeam = (CTeam*) ((dwBase + OFS_Team));
return MyTeam->iTeam;
}
int GetTargetIndex(DWORD PlayerTarget)
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
void FillRGB( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice )
{
if( w < 0 )w = 1;
if( h < 0 )h = 1;
if( x < 0 )x = 1;
if( y < 0 )y = 1;
 
D3DRECT rec = { x, y, x + w, y + h };
pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}
void DrawBorderz( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
FillRGB( x, (y + h - px), w, px, BorderColor, pDevice );
FillRGB( x, y, px, h, BorderColor, pDevice );
FillRGB( x, y, w, px, BorderColor, pDevice );
FillRGB( (x + w - px), y, px, h, BorderColor, pDevice );
}
void HealthEqui(LPDIRECT3DDEVICE9 pDevice, int x, int y, float Health)
{
	const D3DCOLOR colours[] = { RED, RED, RED, RED, ORANGE, ORANGE, ORANGE, ORANGE, YELLOW, YELLOW, YELLOW, YELLOW, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLUE, BLUE }; // this is our order
	int boxSizeX = 2;	// you can fiddle with the box size and gap between them
	int boxSizeY = 7;
	int boxGap = 1;

for ( int i = 0 ; i < 20; i++ )
	{
		if ( Health > ( 5 * i ) )
	DrawBorderz(x-1,y-1,62,9,1,colours[i],pDevice );		
	}

for ( int i = 0 ; i < 20; i++ )
	{
		if ( Health > ( 5 * i ) )
			FillRGBhh(x,y, boxSizeX, boxSizeY,colours[i],pDevice);
		else
            FillRGBhh(x,y, boxSizeX, boxSizeY,GREY,pDevice);
	//DrawBorder(x-1,y-1,50,6,1,BLACK,npDevice);
		x = x + boxSizeX+ boxGap;	// will move to next tile 1 unit to the right
	}
}
void DrawBorder(int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice){
FillRGB( x, (y + h - px), w, px, BorderColor, pDevice );
FillRGB( x, y, px, h, BorderColor, pDevice );
FillRGB( x, y, w, px, BorderColor, pDevice );
FillRGB( (x + w - px), y, px, h, BorderColor, pDevice );
}
void DrawBoxESP( int x, int y, int w, int h, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
DrawBorder( x, y, w, h, 1, BorderColor, pDevice );
} 
//--------------------------------------------------------------------
void HealthbarServer(IDirect3DDevice9* pDevice, int x, int y, float CurHP){
if( !pDevice )
return;
float Long = (CurHP);
FillRGB(x,y,CurHP*1.2,14,TeamColor,pDevice );
}
//--------------------------------------------------------------------
void DrawBoxz(int x, int y, int w, int h, D3DCOLOR BoxColor, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice){
FillRGB( x, y, w, h, BoxColor, pDevice );
DrawBorder( x, y, w, h, 1, BorderColor, pDevice );
}
//--------------------------------------------------------------------
void DrawPoint(int x, int y, int w, int h, D3DCOLOR color, LPDIRECT3DDEVICE9 pDevice){
FillRGB((int)x, (int)y, (int)w, (int)h, color,pDevice);
}
//--------------------------------------------------------------------

void DrawBox(int x, int y, int w, int h, D3DCOLOR Color, D3DCOLOR BorderColor, LPDIRECT3DDEVICE9 pDevice) 
{

	DrawBorder(x, y, w, h, 2, BorderColor, pDevice);
	
	const DWORD D3D_FVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE;
	struct Vertex {
		float x, y, w, h;
		D3DCOLOR Color;
	}
	V[4] = {{(float) x, (float)(y + h), 0.0f, 0.0f, Color}, 
			{(float) x, (float)y, 0.0f, 0.0f, Color}, 
			{(float)(x + w), (float)(y + h), 0.0f, 0.0f, Color}, 
			{(float)(x + w), (float)y, 0.0f, 0.0f, Color}
	};
	pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, D3DZB_TRUE);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
	pDevice->SetRenderState(D3DRS_FOGENABLE, D3DZB_FALSE);

	pDevice->SetFVF(D3D_FVF);
	pDevice->SetTexture(0, NULL);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, V, sizeof(Vertex));
}
VOID FillGradients(int x, int y, int h, int w, DWORD color1, DWORD color2, LPDIRECT3DDEVICE9 pDevice)
{
float alpha = 5;
     float step;
	DWORD r1 = (color1>>16)&0xff;
	DWORD g1 = (color1>>8)&0xff;
	DWORD b1 = (color1)&0xff;
	DWORD r2 = (color2>>16)&0xff;
	DWORD g2 = (color2>>8)&0xff;
	DWORD b2 = (color2)&0xff;
	float /*aDif,*/rDif,gDif,bDif;
	rDif = ((float)r2-(float)r1)/h;
	gDif = ((float)g2-(int)g1)/h;
	bDif = ((float)b2-(float)b1)/h;
	DWORD DrawCol;
	 step  = ((255 - alpha) / h);
	for(int i = 0;i<h;i++)
	{
	alpha = alpha + step;
		DrawCol = (r1+(int)(rDif * i) << 16) | (g1+(int)(gDif * i) << 8) | (b1+(int)(bDif*i));
		FillRGB(x,y+i,w,1,DrawCol, pDevice);
	}
}

//--------------------------------------------------------------------
void HealthBarNew(LPDIRECT3DDEVICE9 pDevice,float x, float y, float Health){
DWORD HPcol = GREEN;
if (Health < 90)HPcol = YELLOW;
if (Health < 80) HPcol = ORANGE;
if (Health < 40) HPcol = RED;
if (Health < 10) HPcol = BLACK;
DrawBorder(x-1,y-1,52,5,1,BLACK,pDevice );
FillRGB(x,y,Health/2,3,HPcol,pDevice );
}

//--------------------------------------------------------------------
void PingServer(int x, int y, float Health, IDirect3DDevice9* pDevice){
if(!pDevice )
return;
for (int index = 0; index <= (Health-1); index++){
D3DCOLOR HPcol = GREEN;
if (Health == 3 )HPcol = ORANGE;
if (Health == 2 )HPcol = ORANGE;
if (Health == 1) HPcol = RED;
FillRGB(x + (index*4),y,3,14,HPcol,pDevice);
}
}

//--------------------------------------------------------------------
void DrawBoxServer(int x, int y, IDirect3DDevice9* pDevice){
if(!pDevice )
return;
DrawBoxz( x, y, 167, 18,BLACK, TeamColor, pDevice );
}
//--------------------------------------------------------------------
void DrawBoxTeam(int x, int y, IDirect3DDevice9* pDevice){
if(!pDevice )
return;
DrawBoxz( x, y,120, 15,TeamColor, BLACK, pDevice );
}
//--------------------------------------------------------------------
void DrawString(int x, int y, DWORD color, const char *fmt, ...){
RECT FontPos = { x, y, x + 120, y + 16 };
char buf[1024] = {'\0'};
va_list va_alist;
va_start(va_alist, fmt);
vsprintf_s(buf, fmt, va_alist);
va_end(va_alist);
fName->DrawText(NULL, buf, -1, &FontPos, DT_LEFT | DT_WORDBREAK, color);
}
//--------------------------------------------------------------------
void DrawString2(int x, int y, DWORD color, const char *fmt, ...){
RECT FontPos = { x, y, x + 120, y + 16 };
char buf[1024] = {'\0'};
va_list va_alist;
va_start(va_alist, fmt);
vsprintf_s(buf, fmt, va_alist);
va_end(va_alist);
Title->DrawText(NULL, buf, -1, &FontPos,  DT_LEFT | DT_WORDBREAK, color);
}
//--------------------------------------------------------------------
float FindDistance(D3DXVECTOR3 my,D3DXVECTOR3 other,CPlayers* pPlayer,CPlayers* pLocal){
return sqrt((pLocal->pos.x-pPlayer->pos.x)*(pLocal->pos.x-pPlayer->pos.x) + (pLocal->pos.y-pPlayer->pos.y)*(pLocal->pos.y-pPlayer->pos.y) + (pLocal->pos.z-pPlayer->pos.z)*(pLocal->pos.z-pPlayer->pos.z));
}
//--------------------------------------------------------------------
void DrawLine(long Xa, long Ya, long Xb, long Yb, DWORD dwWidth, D3DCOLOR Color){
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
//--------------------------------------------------------------------
bool YoWorlToScreenGa(LPDIRECT3DDEVICE9 pDevice, D3DVECTOR Player,D3DVECTOR &PlayerScaled){
D3DXVECTOR3 PlayerPos(Player.x,Player.y,Player.z);
D3DXMATRIX identity;
D3DXVECTOR3 vScreen;
pDevice->GetViewport(&Viewport);
Viewport.X = Viewport.Y = 0;
Viewport.MinZ     = 0;
Viewport.MaxZ     = 1;
D3DXVec3Project(&vScreen, &PlayerPos, &Viewport, &pRC->pRenderData->ProjMatrix, &pRC->pRenderData->ViewMatrix, &pRC->pRenderData->World);
if(vScreen.z < 1.0f && vScreen.x > 0.0f && vScreen.y > 0.0f && vScreen.x < Viewport.Width && vScreen.y < Viewport.Height){
PlayerScaled.x = vScreen.x;
PlayerScaled.y = vScreen.y ;
PlayerScaled.z = vScreen.z;
return true; 
}
return false;
}
//--------------------------------------------------------------------
bool GetBonePos(CGameCharaBase*m_CharaBase,D3DXVECTOR3 &outpos,int BoneIndex){
outpos.x = m_CharaBase->m_BoneContext->m_Bone[BoneIndex].m_Bone._41;
outpos.y = m_CharaBase->m_BoneContext->m_Bone[BoneIndex].m_Bone._42;
outpos.z = m_CharaBase->m_BoneContext->m_Bone[BoneIndex].m_Bone._43;
return true;
}
//--------------------------------------------------------------------
void DrawBone(CGameCharaBase* m_CharaBase,int Start,int End,DWORD Color,LPDIRECT3DDEVICE9 pDevice){
D3DXVECTOR3 vStartBone,vEndBone;
D3DXVECTOR3 vvStartBone,vvEndBone;
if(GetBonePos(m_CharaBase,vStartBone,Start)){
if(GetBonePos(m_CharaBase,vEndBone,End)){
if(YoWorlToScreenGa(pDevice,vStartBone,vvStartBone)){
if(YoWorlToScreenGa(pDevice,vEndBone,vvEndBone)){
DrawLine(vvStartBone.x,vvStartBone.y,vvEndBone.x,vvEndBone.y,1,Color);
}
}
}
}
}
//--------------------------------------------------------------------
void DrawSkeleton(CGameCharaBase* m_CharaBase,DWORD Color,LPDIRECT3DDEVICE9 pDevice){
float wraw = 2;
DrawBone(m_CharaBase,0,6,Color,pDevice);
DrawBone(m_CharaBase,6,10,Color,pDevice);
DrawBone(m_CharaBase,6,11,Color,pDevice);
DrawBone(m_CharaBase,0,12,Color,pDevice);
DrawBone(m_CharaBase,0,13,Color,pDevice);
DrawBone(m_CharaBase,12,14,Color,pDevice);
DrawBone(m_CharaBase,13,15,Color,pDevice);
DrawBone(m_CharaBase,14,8,Color,pDevice);
DrawBone(m_CharaBase,15,9,Color,pDevice);
}