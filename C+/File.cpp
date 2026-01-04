//-------------------------------------------------------------------------------------------------------------||
//------------------------------------|| DISUSUN OLEH HELJUNAI SYAHPUTRA ||------------------------------------||
//-------------------------------------------------------------------------------------------------------------||
#include <windows.h>
#include "Hack.h"
#include "Texture.h"
#include "xMenu.h"
#include "colorByte.h"
#include "Background.h"
#include "BulletMode.h"
#include "cMenuCC.h"
#include "ZombieKillers.h"
#include "ReplaceAngels.h"
//----------------------------------------------------------------------------------
D3D9Menu	*_GyC = NULL;
LPDIRECT3DDEVICE9 pGDevice = NULL;
LPDIRECT3DTEXTURE9 txHeader;
D3DXVECTOR3 pHeader; 
LPD3DXSPRITE bbSprite;
//----------------------------------------------------------------------------------
LPD3DXFONT      g_pFont = NULL; 
LPD3DXFONT      g_pFont2 = NULL; 
LPD3DXFONT      g_pFont4 = NULL; 
LPD3DXFONT		Menu_Font = NULL;
LPD3DXFONT		BlackFont = NULL;
LPD3DXFONT      DebugFont = NULL; 
//----------------------------------------------------------------------------------
#define HOOK(func,addy) o##func = (t##func)DetourB8((DWORD)addy,(DWORD)hk##func,	12) 
#define UNHOOK(func,addy) o##func = (t##func)DetourB8((DWORD)addy,(DWORD)o##func,	12)
//----------------------------------------------------------------------------------
int mx = 50; 
int my = 50; 
int AimSlot,AimHead,AimBody,AimHeadCrot = 0;
extern char	Mtitle[81];
//----------------------------------------------------------------------------------
#define hD3D "i3GfxDx.dll"
HMODULE hGfxDx  = LoadLibrary("i3GfxDx.dll");
DWORD AdressAndByte,GetEngine,Calculate = NULL;
#define StartRoutine(Function) CreateThread(0,0,(LPTHREAD_START_ROUTINE)Function,0,0,0);
typedef HRESULT (WINAPI* tEndScene)(LPDIRECT3DDEVICE9 pDevice);
tEndScene oEndScene;
typedef HRESULT (WINAPI* tDrawIndexedPrimitive)(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount);
tDrawIndexedPrimitive oDrawIndexedPrimitive = NULL;
//---------------------------------------------------------------------------------- AIM Bullet
bool BulletEnable = false;
float fX,fY,fZ = 0;
_declspec(naked)void i3CollideeLine_SetEnd()
{
_asm{
cmp [BulletEnable],0
je Skip
mov eax,dword ptr ss:[esp+0x4]
mov [BackupEDXTele],edx
mov edx,[fX]
mov [eax+0x0],edx
mov edx,[fY]
mov [eax+0x4],edx
mov edx,[fZ]
mov [eax+0x8],edx
mov edx,[BackupEDXTele]
Skip:
MOV EAX,DWORD PTR SS:[ESP+0x4]
FLD DWORD PTR DS:[EAX]
FSTP DWORD PTR DS:[ECX+0x18]
FLD DWORD PTR DS:[EAX+0x4]
FSTP DWORD PTR DS:[ECX+0x1C]
FLD DWORD PTR DS:[EAX+0x8]
FSTP DWORD PTR DS:[ECX+0x20]
FLD DWORD PTR DS:[ECX+0x18]
FSUB DWORD PTR DS:[ECX+0xC]
FSTP DWORD PTR DS:[ECX+0x24]
FLD DWORD PTR DS:[ECX+0x1C]
FSUB DWORD PTR DS:[ECX+0x10]
FSTP DWORD PTR DS:[ECX+0x28]
FLD DWORD PTR DS:[ECX+0x20]
FSUB DWORD PTR DS:[ECX+0x14]
FSTP DWORD PTR DS:[ECX+0x2C]
RETN 0x4
}
}
//----------------------------------------------------------------------------------
class CDeathPlayer
{
public:
BYTE Death[16];
};
//----------------------------------------------------------------------------------
class CLocalPlayerID
{
public:
BYTE ID;
};
//----------------------------------------------------------------------------------
BYTE GetUserLife(int iSlot)
{
DWORD g_pGameContext   = *(DWORD*)c_pPlayerBase;
CDeathPlayer *Life = (CDeathPlayer *) (g_pGameContext + P_BasePLAYER);
return Life->Death[iSlot];
}
//----------------------------------------------------------------------------------
int GetCharaIndex()
{
DWORD g_pGameContext   = *(DWORD*)c_pPlayerBase;
CLocalPlayerID *LocID = (CLocalPlayerID *) (g_pGameContext + P_BaseTEAM);
return LocID->ID;
}
//----------------------------------------------------------------------------------
int GetPriorityTarget()
{
int Result = -1;
float fMaxDistance = 180.0f;
D3DXVECTOR3 PlayerEnd, LocPlayer;
for (int index = 0; index < 16; index++)
{
if (!GetUserLife(index) && GetCharaIndex() != index)
{
if (GetCharaIndex() %2 != index % 2)
{
_My->GetUserBone(LocPlayer, 7 , GetCharaIndex());
_My->GetUserBone(PlayerEnd, 7 , index);
if (_My->CalcDistance(LocPlayer, PlayerEnd) < fMaxDistance)
{
fMaxDistance = _My->CalcDistance(PlayerEnd, LocPlayer);
Result = index;
}
}
}
}
return Result;
}
//----------------------------------------------------------------------------------
void DoAutoHS()
{
if(AimHead  == 1)
{
//----------------------------------------------------------------------------------
DWORD pMyTarget = _My->GetPlayerTarget(_My->GetMyCharaIndex());
if(pMyTarget > NULL)
{
DWORD TargetIndex = _My->GetTargetIndex(pMyTarget);
D3DXVECTOR3 OnWorld;
if(_My->GetUserBone(OnWorld,7,TargetIndex)){
BulletEnable = true;
fX = OnWorld.x;
fY = OnWorld.y + 0.1f;
fZ = OnWorld.z;
}
}
else
{
BulletEnable = false;
}
}
}
//----------------------------------------------------------------------------------
bool WorldToScreenAim(D3DVECTOR Player,D3DVECTOR &PlayerScaled)
{	
D3DXVECTOR3 PlayerPos(Player.x,Player.y,Player.z);
D3DXMATRIX identity;
D3DXVECTOR3 vScreen;
npDevice->GetViewport(&Viewport);
g_ViewPort.X = g_ViewPort.Y = 0;
g_ViewPort.MinZ = 0;
g_ViewPort.MaxZ = 1;
D3DXVec3Project(&vScreen, &PlayerPos, &Viewport, &pRC->pRenderData->ProjMatrix, &pRC->pRenderData->ViewMatrix, &pRC->pRenderData->World);
if (vScreen.z < 1.0f && vScreen.x > 0.0f && vScreen.y > 0.0f && vScreen.x < Viewport.Width && vScreen.y < Viewport.Height)
{
PlayerScaled.x = vScreen.x;
PlayerScaled.y = vScreen.y;
PlayerScaled.z = vScreen.z;
AimOff = false;
return true; 
}
AimOff = true;
return false;
}
void AimLockSC(LPDIRECT3DDEVICE9 pDevice){
//----------------------------------------------------------------------------------
int ScreenCenterX = (g_ViewPort.Width /2.0f); 
int ScreenCenterY = (g_ViewPort.Height /2.0f);
if(xAccuracy)
{
AimCrotMode = 1;
AimOff = 1;
//----------------------------------------------------------------------------------
int AimSlot = GetPriorityTarget();
if(AimSlot != -1)
{
D3DXVECTOR3 OnWorld,OnScreen;
int BoneIndexSelector = 0;
switch(AimBody)
{
case 0:
BoneIndexSelector = 7;
break;
case 1:
BoneIndexSelector = 5;
break;
}
if(_My->GetUserBone(OnWorld,BoneIndexSelector,AimSlot)){
OnWorld.y = OnWorld.y + 0.1f;
if(WorldToScreenAim(OnWorld,OnScreen))
{
int LocalX = OnScreen.x;
int LocalY = OnScreen.y;
if(LocalX == ScreenCenterX && LocalY == ScreenCenterY )
{ 
DeltaX = 0;
DeltaY = 0;
}
else
{
DeltaX = LocalX - ScreenCenterX; 
DeltaY = LocalY - ScreenCenterY;
}
}
else
{
AimOff = false;
AimCrotMode =0;
}
}
else
{
AimOff = false;
AimCrotMode =0;
}
}
else
{
AimOff = false;
AimCrotMode =0;
}
}
else
{
AimOff = false;
AimCrotMode =0;
}
}
//----------------------------------------------------------------------------------
void DrawLine(float x, float y, float x2, float y2, float width, DWORD color)
{
D3DXVECTOR2 vLine[2];
pLine->SetWidth( width );
pLine->SetAntialias( false );
pLine->SetGLLines( true );
vLine[0].x = x;
vLine[0].y = y;
vLine[1].x = x2;
vLine[1].y = y2;
pLine->Begin();
pLine->Draw( vLine, 2, color );
pLine->End();
}
//----------------------------------------------------------------------------------
#define PISSS 3.14159265
void DrawSumer(int X, int Y, int radius, int numSides, DWORD Color) 
{ 
D3DXVECTOR2 Line[130]; 
float Step = PISSS * 2.0 / numSides; 
int Count = 0; 
for (float a=0; a < PISSS*2.0; a += Step) 
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
//----------------------------------------------------------------------------------
float FindDistance(D3DXVECTOR3 my,D3DXVECTOR3 other,CPlayers* pPlayer,CPlayers* pLocal)
{
return sqrt((pLocal->pos.x-pPlayer->pos.x)*(pLocal->pos.x-pPlayer->pos.x) + (pLocal->pos.y-pPlayer->pos.y)*(pLocal->pos.y-pPlayer->pos.y) + (pLocal->pos.z-pPlayer->pos.z)*(pLocal->pos.z-pPlayer->pos.z));
}
void  FillRGB( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice )
{
if( w < 0 )w = 1;
if( h < 0 )h = 1;
if( x < 0 )x = 1;
if( y < 0 )y = 1;
D3DRECT rec = { x, y, x + w, y + h };
pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}
//----------------------------------------------------------------------------------
void DrawBorder(int x, int y, int w, int h, int px, D3DCOLOR BorderColor, LPDIRECT3DDEVICE9 pDevice)
{
FillRGB(x,(y + h - px), w, px, BorderColor, pDevice);
FillRGB(x, y, px, h, BorderColor, pDevice);
FillRGB(x, y, w, px, BorderColor, pDevice);
FillRGB(x + w - px, y, px, h, BorderColor, pDevice);
}
//----------------------------------------------------------------------------------
void DrawBoxESP( int x, int y, int w, int h, float Health, IDirect3DDevice9* pDevice )
{
DWORD HPcol = YELLOW;
if (Health < 90)HPcol = GREEN;
if (Health < 80) HPcol = GREEN;
if (Health < 40) HPcol = GREEN;
if (Health < 10) HPcol = GREEN;
DrawBorder( x, y, w, h, 1, HPcol, pDevice );
}
//----------------------------------------------------------------------------------
void DrawXTarget(float x, float y, float x2, float y2, float width, DWORD color)
{
D3DXVECTOR2 vLine[2];
pLine->SetWidth( width );
pLine->SetAntialias( false );
pLine->SetGLLines( true );
vLine[0].x = x;
vLine[0].y = y;
vLine[1].x = x2;
vLine[1].y = y2;
pLine->Begin();
pLine->Draw( vLine, 2, color );
pLine->End();
}
//----------------------------------------------------------------------------------
void DoQontolMode(LPDIRECT3DDEVICE9 pDevice)
{
if(Accuracy == 1)
{
if(*(PBYTE)c_pPelorReload > NULL){
//----------------------------------------------------------------------------------
int AimSlot = GetPriorityTarget();
if(AimSlot != -1)
{
D3DXVECTOR3 OnWorld,OnScreen;
int BoneIndexSelector = 0;
switch(AimBody)
{
case 0:
BoneIndexSelector = 7;
break;
case 1:
BoneIndexSelector = 5;
break;
}
float ScreenCenterX = (Viewport.Width /2.0f);
float ScreenCenterY = (Viewport.Height /2.0f);
float ScreenBottomY = (Viewport.Height);
if(_My->GetUserBone(OnWorld,BoneIndexSelector,AimSlot)){
BulletEnable = true;
fX = OnWorld.x;
fY = OnWorld.y + 0.1f;
fZ = OnWorld.z;
if(_My->YoWorlToScreenGa(pDevice,OnWorld,OnScreen))
{
FillRGB(OnScreen.x-14, OnScreen.y, 10, 2,D3DCOLOR_ARGB(255, 0,   180, 255),pDevice);
FillRGB(OnScreen.x+4, OnScreen.y, 10, 2,D3DCOLOR_ARGB(255, 0,   180, 255),pDevice);
FillRGB(OnScreen.x, OnScreen.y-14, 2, 10,D3DCOLOR_ARGB(255, 0,   180, 255),pDevice);
FillRGB(OnScreen.x, OnScreen.y+5, 2, 10,D3DCOLOR_ARGB(255, 0,   180, 255),pDevice);
FillRGB(OnScreen.x-1,OnScreen.y-1, 3, 3,D3DCOLOR_ARGB(255, 255, 000, 000), pDevice );
}
}
else
{
BulletEnable = false;
}
}
else
{
BulletEnable = false;
}
}
}
}
//----------------------------------------------------------------------------------
bool xHookedTele,cHookedShot = false;
DWORD OldProtect;
//----------------------------------------------------------------------------------
void HOOKAIM() { 
if(xHookedTele)return;
DWORD OFS_Telekill = (DWORD)GetModuleHandleA(XStr(0x04, 0x0E, 0xEE, 0xBE80999F, 0x86B19894, 0x989CD69C, 0x829E0000 ).c()) + PointBaseBullet; 
VirtualProtect ( (LPVOID)(OFS_Telekill), sizeof (OFS_Telekill), PAGE_EXECUTE_READWRITE, &OldProtect ); 
MakePeler((PBYTE)OFS_Telekill,(DWORD)i3CollideeLine_SetEnd);
VirtualProtect ( (LPVOID)(OFS_Telekill), sizeof (OFS_Telekill), OldProtect, &OldProtect ); 
xHookedTele = true; 
}
//----------------------------------------------------------------------------------
//void HOOKAUTOSHOT() { 
//if(HookedShot == false){
//DWORD OFS_AutoShot = (DWORD)GetModuleHandleA(XStr(0x04, 0x0E, 0xEE, 0xBE80999F, 0x86B19894, 0x989CD69C, 0x829E0000 ).c()) + PointBaseAutoShot;
//VirtualProtect ( (LPVOID)(OFS_AutoShot), sizeof (OFS_AutoShot), PAGE_EXECUTE_READWRITE, &OldProtect ); 
//MakePeler((PBYTE)OFS_AutoShot,(DWORD)MouseHook); 
//VirtualProtect ( (LPVOID)(OFS_AutoShot), sizeof (OFS_AutoShot), OldProtect, &OldProtect ); 
//HookedShot = true;
//}}
//----------------------------------------------------------------------------------
//void HOOKAIMLOCK() { 
//if(cHookedShot == false){
//DWORD OFS_Deltax = (DWORD)GetModuleHandleA(XStr(0x04, 0x0E, 0xEE, 0xBE80999F, 0x86B19894, 0x989CD69C, 0x829E0000 ).c()) + PointBaseAimLockX;
//DWORD OFS_Deltay = (DWORD)GetModuleHandleA(XStr(0x04, 0x0E, 0xEE, 0xBE80999F, 0x86B19894, 0x989CD69C, 0x829E0000 ).c()) + PointBaseAimLockY;
//VirtualProtect ( (LPVOID)(OFS_Deltax), sizeof (OFS_Deltax), PAGE_EXECUTE_READWRITE, &OldProtect ); 
//VirtualProtect ( (LPVOID)(OFS_Deltay), sizeof (OFS_Deltay), PAGE_EXECUTE_READWRITE, &OldProtect ); 
//MakePeler((PBYTE)OFS_Deltax,(DWORD)MyDeltaX); 
//MakePeler((PBYTE)OFS_Deltay,(DWORD)MyDeltaY); 
//VirtualProtect ( (LPVOID)(OFS_Deltax), sizeof (OFS_Deltax), OldProtect, &OldProtect ); 
//VirtualProtect ( (LPVOID)(OFS_Deltay), sizeof (OFS_Deltay), OldProtect, &OldProtect ); 
//cHookedShot = true;
//}}
//----------------------------------------------------------------------------------
void DoAutoShot()
{
if(AutoShoot == 1){
if(_My->GetPlayerTarget(_My->GetMyCharaIndex()) > NULL)Shot = true;
else Shot = false;
}}
//---------------------------------------------------------------------------------- ESP Mode
void EspMode (LPDIRECT3DDEVICE9 pDevice)
{
unsigned long dwBase	= *(DWORD*)c_pPlayerBase;
unsigned long dwBase2	= *(DWORD*)c_pESP;	
CTeam		*pTeam		= ((CTeam*)(dwBase + P_BaseTEAM));
D3DXVECTOR3 ScreenPos;
D3DXVECTOR3 HeadPos;
D3DXVECTOR3 HeadPoSS;
float ScreenCenterX = (Viewport.Width /2.0f);
float ScreenCenterY = (Viewport.Height /2.0f);
float ScreenBottomY = (Viewport.Height);
for (int i = 0; i<=15; i++)
{
if (dwBase !=0)
{
CHealth		*pHealth	= (CHealth*)((dwBase2 + PTR_HEALTH) + i * PTRSizeHealth);
CRank		*pRank		= (CRank*)((dwBase + OFS_RANK) + i * 0x2B);
CNames		*pNames		= (CNames*)((dwBase + OFS_NAMES) + i * 0x21);
CNick *pHacker  = (CNick*) ((dwBase + 0xF1A9D) + i * 0x01);
CNick *pHacker2 = (CNick*) ((dwBase + 0xF1B20) + i * 0x01);
DWORD ADR_PLAYER		= *(DWORD*)(ResultBasePlayer2);
DWORD pCalculate		= *(DWORD*)(ADR_PLAYER + 0x4 * i + 0x27B24 );
DWORD pCalculate2		= *(DWORD*)(ADR_PLAYER + 0x4 * pTeam->iTeam + 0x27B24 );
CPlayers	*pPlayer	= (CPlayers*)(pCalculate + 0x64 );
CPlayers	*pLocal		= (CPlayers*)(pCalculate2 + 0x64 );
D3DXVECTOR3 MyDistance	=	pLocal->pos - pPlayer->pos;
float MyaDistance = D3DXVec3Length(&MyDistance );
bHookedTele = true;
char *dis = new char[33];
int MySlot = GetTeam(_My->GetMyCharaIndex()); 
if(GetTeam(i) == MySlot) continue; 
//----------------------------------------------------------------------------------
if(_My->GetUserBone(vStart10,15,i))
{
if(_My->GetUserBone(vEnd10,9,i))
{
if(_My->YoWorlToScreenGa(pDevice,vStart10,vvStart10))
{
if(_My->YoWorlToScreenGa(pDevice,vEnd10,vvEnd10))
{
if (pHealth->CurHP > 1)
{
//----------------------------------------------------------------------------------
if (PlayerNameV2)
{
PrintText(fSmall,(float)vvStart10.x-1.5,(float)vvStart10.y - 30.0,RED," %s ",pHealth->CurHP,pNames->szNames);
}
//----------------------------------------------------------------------------------
if (ESPHealth == 1){
_My->Healthbarnew(pDevice,(float)PlayerScaled.x-25,(float)PlayerScaled.y+5,pHealth->CurHP);
}
//----------------------------------------------------------------------------------
//if (ESPRank){
//PrintText(fSmall,(float)vvStart10.x-15,(float)vvStart10.y - 40.0,YELLOW," %s ",NewFor2015[pRank->iRank]);
//}
//----------------------------------------------------------------------------------
if (ESPHead){
_My->FillRGB((float)vvStart10.x-1.5, (float)vvStart10.y, 3, 3,YELLOW, pDevice );
}
//----------------------------------------------------------------------------------
if (ESPDistance){
//DrawLine((float)ScreenCenterX,(float)ScreenBottomY +450,(float)vvStart10.x,(float)vvEnd10.y+20,1,BLUE);
sprintf(dis,"[%0.1f Meter]",(FindDistance(pLocal->pos,pPlayer->pos,pPlayer,pLocal))/4);
_My->PrintText(dis,(float)vvStart10.x-1.5,(float)vvStart10.y + 35,BLUE,fSmall);
}
//----------------------------------------------------------------------------------
if(ESPBox == 1){
DrawBoxESP((float)vvStart10.x-(5000/MyaDistance)/30,(float)vvEnd10.y-(35000/MyaDistance)/45, 50000/MyaDistance/6*2/40,50000/MyaDistance/3*2/40, TeamColor, pDevice);
}
//----------------------------------------------------------------------------------
if (FileLine){
_My->DrawLine((int)ScreenCenterX,(int)ScreenCenterY,(int)vvStart10.x,(int)vvEnd10.y,1,YELLOW);  
}
//----------------------------------------------------------------------------------
}}}}}
if (pHealth->CurHP > 1)
{
if (ShowName == 1){
pHacker->bVal=0x01;
pHacker2->bVal=0x01;
}else{
pHacker->bVal=0x00;
pHacker2->bVal=0x00;
}
//----------------------------------------------------------------------------------
if(ESPBone == 1){
if(_My->GetUserBone(vStart,6,i))
{
if(_My->GetUserBone(vEnd,7,i))
{
if(_My->YoWorlToScreenGa(pDevice,vStart,vvStart))
{
if(_My->YoWorlToScreenGa(pDevice,vEnd,vvEnd))
{
if(_My->GetUserBone(vStart2,6,i))
{
if(_My->GetUserBone(vEnd2,0,i))
{
if(_My->YoWorlToScreenGa(pDevice,vStart2,vvStart2))
{
if(_My->YoWorlToScreenGa(pDevice,vEnd2,vvEnd2))
{
if(_My->GetUserBone(vStart3,6,i))
{
if(_My->GetUserBone(vEnd3,10,i))
{
if(_My->YoWorlToScreenGa(pDevice,vStart3,vvStart3))
{
if(_My->YoWorlToScreenGa(pDevice,vEnd3,vvEnd3))
{
if(_My->GetUserBone(vStart4,6,i))
{
if(_My->GetUserBone(vEnd4,11,i))
{
if(_My->YoWorlToScreenGa(pDevice,vStart4,vvStart4))
{
if(_My->YoWorlToScreenGa(pDevice,vEnd4,vvEnd4))
{
if(_My->GetUserBone(vStart5,0,i))
{
if(_My->GetUserBone(vEnd5,12,i))
{
if(_My->YoWorlToScreenGa(pDevice,vStart5,vvStart5))
{
if(_My->YoWorlToScreenGa(pDevice,vEnd5,vvEnd5))
{
if(_My->GetUserBone(vStart6,0,i))
{
if(_My->GetUserBone(vEnd6,13,i))
{
if(_My->YoWorlToScreenGa(pDevice,vStart6,vvStart6))
{
if(_My->YoWorlToScreenGa(pDevice,vEnd6,vvEnd6))
{
if(_My->GetUserBone(vStart7,12,i))
{
if(_My->GetUserBone(vEnd7,14,i))
{
if(_My->YoWorlToScreenGa(pDevice,vStart7,vvStart7))
{
if(_My->YoWorlToScreenGa(pDevice,vEnd7,vvEnd7))
{
if(_My->GetUserBone(vStart8,13,i))
{
if(_My->GetUserBone(vEnd8,15,i))
{
if(_My->YoWorlToScreenGa(pDevice,vStart8,vvStart8))
{
if(_My->YoWorlToScreenGa(pDevice,vEnd8,vvEnd8))
{
if(_My->GetUserBone(vStart9,14,i))
{
if(_My->GetUserBone(vEnd9,8,i))
{
if(_My->YoWorlToScreenGa(pDevice,vStart9,vvStart9))
{
if(_My->YoWorlToScreenGa(pDevice,vEnd9,vvEnd9))
{
if(_My->GetUserBone(vStart10,15,i))
{
if(_My->GetUserBone(vEnd10,9,i))
{
if(_My->YoWorlToScreenGa(pDevice,vStart10,vvStart10))
{
if(_My->YoWorlToScreenGa(pDevice,vEnd10,vvEnd10))
{
_My->DrawLine(vvStart.x,vvStart.y,vvEnd.x,vvEnd.y,1,RED);
_My->DrawLine(vvStart2.x,vvStart2.y,vvEnd2.x,vvEnd2.y,1,RED);
_My->DrawLine(vvStart3.x,vvStart3.y,vvEnd3.x,vvEnd3.y,1,RED);
_My->DrawLine(vvStart4.x,vvStart4.y,vvEnd4.x,vvEnd4.y,1,RED);
_My->DrawLine(vvStart5.x,vvStart5.y,vvEnd5.x,vvEnd5.y,1,RED);
_My->DrawLine(vvStart6.x,vvStart6.y,vvEnd6.x,vvEnd6.y,1,RED);
_My->DrawLine(vvStart7.x,vvStart7.y,vvEnd7.x,vvEnd7.y,1,RED);
_My->DrawLine(vvStart8.x,vvStart8.y,vvEnd8.x,vvEnd8.y,1,RED);
_My->DrawLine(vvStart9.x,vvStart9.y,vvEnd9.x,vvEnd9.y,1,RED);
_My->DrawLine(vvStart10.x,vvStart10.y,vvEnd10.x,vvEnd10.y,1,RED);
}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
}
}
}	
bHookedTele = false;
}
//----------------------------------------------------------------------------------
#define 	            MENUMAXINDEX	100
#define 	            MENUFOLDER		1
#define 	            MENUTEXT		2
#define 	            MENUBASE		10
int Mpos=0;	
int Active=0;
int Mxofs =210.0f;
int Mysize=15.0f;
int ShowMenu = 1;
char Mtitle[81]= "";
//----------------------------------------------------------------------------------
RECT rect,rect2,rect3;
struct{
int  *var;
int  maxvalue;
int  typ;
char *txt;
char **opt;
}
//----------------------------------------------------------------------------------
#define 	            MENUMAXINDEX	100
#define 	            MENUFOLDER		1
#define 	            MENUTEXT		2
#define 	            MENUITEM		3
#define 	            MENUBASE		10
//----------------------------------------------------------------------------------
#define PINK			D3DCOLOR_XRGB(255 , 0 , 255)
#define TEAL			D3DCOLOR_ARGB(255, 0,	255, 255)
#define LIME			D3DCOLOR_ARGB(255, 198, 255,   0)
#define YELLOW			D3DCOLOR_ARGB(255, 255, 255, 000) 
#define SQUA			D3DCOLOR_ARGB(255, 0, 255, 255)
#define SKYBLUE			D3DCOLOR_ARGB(255, 0,   180, 255)
#define GOLD2			D3DCOLOR_ARGB(255, 238, 201, 0)
#define ORANGE			D3DCOLOR_ARGB(255, 255, 125, 000)
#define GREY			D3DCOLOR_ARGB(255, 128, 128, 128)
#define DARKGREY        D3DCOLOR_ARGB(255,62,62,62)
#define BIRU			D3DCOLOR_ARGB(000, 000, 255, 255)
#define MAROON			D3DCOLOR_ARGB(255, 142, 30,    0)
#define MenuGreen       D3DCOLOR_ARGB(255,43,119,64)
#define MenuGREY        D3DCOLOR_ARGB(255,30,30,30)
#define LGRAY			D3DCOLOR_ARGB(255, 174, 174, 174) 
#define DGRAY			D3DCOLOR_ARGB(255, 71,  65,   64) 
#define BROWN2			D3DCOLOR_ARGB(255, 77,  46,   38)
#define SHIT			D3DCOLOR_ARGB(255, 74,  38,   38) 
#define WHITE			D3DCOLOR_ARGB(255, 255, 255, 255) 
//----------------------------------------------------------------------------------
#define     MCOLOR_TITLE	(SQUA) //BLACK
#define     MCOLOR_CURRENT	(PINK)
#define     MCOLOR_FOLDER	(BLUE)
#define     MCOLOR_TEXT		(WHITE)
#define     MCOLOR_INACTIVE	(WHITE)
#define     MCOLOR_ACTIVE	(RED)
//----------------------------------------------------------------------------------
D3MENU[MENUMAXINDEX];
void CyberAngels(char *txt, char **opt, int *var, int maxvalue, int typ){
D3MENU[Active].typ=typ;
D3MENU[Active].txt=txt;
D3MENU[Active].opt=opt;
D3MENU[Active].var=var;
D3MENU[Active].maxvalue=maxvalue;
Active++;
}
//----------------------------------------------------------------------------------
void CyberAngels(char *txt, char *opt){
D3MENU[Active].typ=MENUTEXT;
D3MENU[Active].txt=txt;
D3MENU[Active].opt=(char **)opt;
D3MENU[Active].var=0;
D3MENU[Active].maxvalue=0;
Active++;
}
//----------------------------------------------------------------------------------
void DrawMenuShow(LPDIRECT3DDEVICE9 pDevice,int x, int y,	ID3DXFont *pFont)
{
int i, val;
DWORD color;
SetRect( &rect, x+Mxofs/2, y, x+Mxofs /2 , y );
if (!ShowMenu) return;
if (Mtitle[0]) {
pFont->DrawText(NULL,Mtitle,-1,&rect,DT_NOCLIP | DT_CENTER, MCOLOR_TITLE);
y+=Mysize;
}
for (i=0; i<Active; i++) {
val=(D3MENU[i].var)?(*D3MENU[i].var):0;
if (i==Mpos)
color=MCOLOR_CURRENT;
else if (D3MENU[i].typ==MENUFOLDER)
color=MCOLOR_FOLDER;
else if (D3MENU[i].typ==MENUTEXT)
color=MCOLOR_TEXT;
else
color=(val)?MCOLOR_ACTIVE:MCOLOR_INACTIVE;
SetRect( &rect3, x, y, x , y );
SetRect( &rect2, x+Mxofs, y, x+Mxofs , y );
pFont->DrawText(NULL,D3MENU[i].txt,-1,&rect3, DT_NOCLIP,color);
if (D3MENU[i].opt) {
if (D3MENU[i].typ==MENUTEXT)
pFont->DrawText(NULL,(char *)D3MENU[i].opt,-1,&rect2, DT_NOCLIP | DT_RIGHT, color);
else
pFont->DrawText(NULL,(char *)D3MENU[i].opt[val],-1,&rect2, DT_NOCLIP | DT_RIGHT, color);
}
y+=Mysize;
}}
//----------------------------------------------------------------------------------
void DrawMenuNav(LPDIRECT3DDEVICE9 pDevice)
{
if (GetAsyncKeyState(VK_INSERT)&1) ShowMenu=(!ShowMenu);
if (!ShowMenu) return;
if (GetAsyncKeyState(VK_UP)&1) {
do {
Mpos--;
if (Mpos<0)  Mpos=Active-1;
} while (D3MENU[Mpos].typ==MENUTEXT);
} else if (GetAsyncKeyState(VK_DOWN)&1) {
do {
Mpos++;
if (Mpos==Active) Mpos=0;
} while (D3MENU[Mpos].typ==MENUTEXT);
} else if (D3MENU[Mpos].var) {
int dir=0;
if (GetAsyncKeyState(VK_LEFT )&1 && *D3MENU[Mpos].var > 0                      ) dir=-1;
if (GetAsyncKeyState(VK_RIGHT)&1 && *D3MENU[Mpos].var < (D3MENU[Mpos].maxvalue-1)) dir=1;
if (dir) {
*D3MENU[Mpos].var += dir;
if (D3MENU[Mpos].typ==MENUFOLDER) Active=0;
}}}
//----------------------------------------------------------------------------------
char *optColor1    [12] = {"Off","RED","BLUE","GREEN","AQUA","PURPLE","WHITE","YELLOW","PINK","TURQUOISE","ORANGE","BLACK"};
char *Crosshair    [10] = {"Off","RED","BLUE","GREEN","WHITE","YELLOW","SQUA","ORANGE","LIME","On"};
char *Moptfolder1  [2]  = {"Open" , "Close"};
char *MoptReaplace [11]  = {"Off", "Socer Granade Bomb", "Lentern Bomb", "Bread Bomb", "Candy Bomb", "Chocolate Bomb", "Kriss SVD", "K-201 Ext", "AK Sopmod", "AK47 FC", "HK 69"};
char *MoptRpg      [3]  = {"Off", "RPG1", "RPG2"};
char *Moptonoff    [2]  = {"Off", "On"};
char *MoptoShow    [2]  = {"Show", "Close"};
char *MoptAimlock   []  = {"Off", "On"};
char *MoptAutohs    []  = {"Off", "On"};
char *MoptTarget    []  = {"Head", "Boddy"};
char *MoptGM       [7]  = {"Off", "MOPB [3]","MOPB [4]","MOPB [5]","MOPB [5 Gold]","BOM","GM Hack"};
char *MoptAimbullet []  = {"Off", "On"};
char *MoptAa       [2]  = {"Off", "On"};
char *MoptAa2      [2]  = {"Off", "On"};
char *MoptAa3      [2]  = {"F5", "F5"};
//----------------------------------------------------------------------------------
int Box1 = 0;
int Box2 = 0;
int Box3 = 0;
int Box5 = 0;
int Box6 = 0;
int uyeh = 0;
int Box7 ,Box4= 0;
int BoxAem=0;
//---------------------------------------------------------------------------------- D3D Menu Cyber Angels
void DrawRebuildMenu(LPDIRECT3DDEVICE9 pDevice)
{
CyberAngels("","");
CyberAngels("","");
CyberAngels("[+] Menu Visual"			,        Moptfolder    , &FR1              , 2	, MENUFOLDER);
if (FR1)
{ 
CyberAngels("[-V-] Wallhack Clean"		,        Moptonoff     , &WallCrot         , 2	, MENUBASE);
CyberAngels("[-V-] Wallhack Leopard"	,        Moptonoff     , &Phantom          , 2	, MENUBASE);
CyberAngels("[-V-] Crosshair"			,        Crosshair     , &CrossEnds        , 10 , MENUBASE);
CyberAngels("[-V-] No Smoke"			,        Moptonoff     , &UnSmoke          , 2	, MENUBASE);
CyberAngels("[-V-] No Fog"				,        Moptonoff     , &NoFog            , 2	, MENUBASE);
}
//----------------------------------------------------------------------------------
CyberAngels("[+] Menu Weapon"			,        Moptfolder    , &FR2			   , 2	, MENUFOLDER);
if (FR2)
{	    
CyberAngels("[-W-] No Recoil"			,        Moptonoff    , &NoRecoil		   , 2	, MENUITEM);
CyberAngels("[-W-] Fast Reload"			,        Moptonoff    , &Reload			   , 2	, MENUBASE);
CyberAngels("[-W-] Quick Change"		,        Moptonoff    , &qece			   , 2	, MENUITEM);
CyberAngels("[-W-] Unlimited Ammo"		,        Moptonoff    , &xDepositAmmo      , 2	, MENUITEM);
}
//----------------------------------------------------------------------------------
CyberAngels("[+] Menu Player"			,        Moptfolder   , &FR3               , 2	, MENUFOLDER);
if (FR3) 
{	
CyberAngels("[-P-] Hack Pangkat"		,        MoptGM       , &Norespawn         , 7	, MENUBASE);
CyberAngels("[-P-] Auto Suicide"		,                                                  "-END-");
}
//----------------------------------------------------------------------------------
CyberAngels("[+] Menu ESP"				,        Moptfolder   , &FR4               , 2 , MENUFOLDER);
if (FR4)
{
CyberAngels("[-E-] Distance"			,        Moptonoff    , &ESPDistance      , 2 , MENUBASE);
CyberAngels("[-E-] Rank"				,        Moptonoff    , &ESPRank          , 2 , MENUBASE);
CyberAngels("[-E-] Head"				,        Moptonoff    , &ESPHead          , 2 , MENUBASE);
CyberAngels("[-E-] Box"					,        Moptonoff    , &ESPBox           , 2 , MENUBASE);
CyberAngels("[-E-] Bone"				,        Moptonoff    , &ESPBone          , 2 , MENUBASE);
CyberAngels("[-E-] Line"				,        Moptonoff    , &FileLine         , 2 , MENUBASE);
CyberAngels("[-E-] Health"				,        Moptonoff    , &ESPHealth        , 2 , MENUBASE);
}
//----------------------------------------------------------------------------------
CyberAngels("[+] Menu Hard"				,        Moptfolder   , &FR5              , 2 , MENUFOLDER);
if (FR5)
{
CyberAngels("[-H-] AIM Pelor"			,		 MoptAimbullet, &Accuracy         , 2 , MENUITEM);
CyberAngels("[-H-] Target Killer"		,        MoptTarget   , &AimBody          , 2 , MENUBASE);
CyberAngels("[-H-] AIM Datar"			,        Moptonoff    , &AimDatar         , 2 , MENUBASE);
}
//----------------------------------------------------------------------------------
CyberAngels("[+] Menu Replace"			,        Moptfolder   , &FR6              , 2 , MENUFOLDER);
if (FR6)
{	
CyberAngels("[-R-] Fake Replace"		,        MoptFake	  , &FakeReplace      , 2 , MENUBASE);
CyberAngels("[-R-] Launcher Item"		,        MoptReplace  , &R_Launcher	      , 7 , MENUBASE);
}
//----------------------------------------------------------------------------------
CyberAngels("[+] Menu Extreme"			,        Moptfolder   , &FR7               , 2 , MENUFOLDER);
if (FR7)
{
CyberAngels("[-E-] Ghost Zombie"		,        Moptonoff    , &Zombiekillersz	   , 2 , MENUBASE);
}
}
//----------------------------------------------------------------------------------
void DrawCrosshair(LPDIRECT3DDEVICE9 pDevice)
{
switch(CrossEnds)
{
case 1:
_My->Crosshair(pDevice, RED);
break;
case 2:
_My->Crosshair(pDevice, BLUE);
break;
case 3:
_My->Crosshair(pDevice, GREEN);
break;
case 4:
_My->Crosshair(pDevice, WHITE);
break;
case 5:
_My->Crosshair(pDevice, YELLOW);
break;
case 6:
_My->Crosshair(pDevice, SQUA);
break;
case 7:
_My->Crosshair(pDevice, ORANGE);
break;
case 8:
_My->Crosshair(pDevice, LIME);
break;
}
}

//---------------------------------------------------------------------------------- Gambar
//void BackGround(LPDIRECT3DDEVICE9 pDevice)
//{
//pHeader.x=32.0f; pHeader.y=+25.0f; pHeader.z=0.0f;
//if(txHeader == NULL)D3DXCreateTextureFromFileInMemoryEx(pDevice,&_IMG_CyberAngels,sizeof(_IMG_CyberAngels),206/*Lebar*/,67/*tinggi*/,D3DX_DEFAULT,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,0,NULL,NULL,&txHeader);
//if(bbSprite == NULL)D3DXCreateSprite(pDevice, &bbSprite);
//bbSprite->Begin(D3DXSPRITE_SORT_DEPTH_BACKTOFRONT);
//bbSprite->Draw(txHeader, 0, 0, &pHeader, 0xFFFFFFFF);
//bbSprite->End();
//}
//----------------------------------------------------------------------------------
HRESULT WINAPI hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{
while(!npDevice) {
npDevice = pDevice;                      
}
if(texRed == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bRed, sizeof(bRed), &texRed);
if(texBlue == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bBlue, sizeof(bBlue), &texBlue);
if(texGreen == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bGreen, sizeof(bGreen), &texGreen);
if(texAqua == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bAqua, sizeof(bAqua), &texAqua);
if(texPurple == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bPurple, sizeof(bPurple), &texPurple);
if(texWhite == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bWhite, sizeof(bWhite), &texWhite);
if(texYellow == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bYellow, sizeof(bYellow), &texYellow);
if(texPink == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bPink, sizeof(bPink), &texPink);
if(texTurquoise == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bTurquoise, sizeof(bTurquoise), &texTurquoise);
if(texOrange == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bOrange, sizeof(bOrange), &texOrange);
if(texBlack == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bBlack, sizeof(bBlack), &texBlack);
//----------------------------------------------------------------------------------
if ( RenderText == 1 ) {
D3DXCreateFontA(pDevice, 18, 0, FW_BOLD, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Trebuchet MS", &pFonts );//SHOWCARD GOTHIC <= contoh : BUAT FONT MENU D3D
RenderText = 0;
}
//----------------------------------------------------------------------------------
if(GetAsyncKeyState(VK_F12)&1){
Beep(1000,100);
ExitProcess(0);
}
//----------------------------------------------------------------------------------> Auto Off
if(!_My->GetBattleState()){
Accuracy = 0;
xAccuracy = 0;
Rep_Item = 0;
R_Launcher =0;
AimHead = 0;
//AutoShoot = 0;
PisoTeleKill1=0;
BulletEnable = false;
//BackGround(pDevice);
}
//----------------------------------------------------------------------------------
if(GetAsyncKeyState(VK_F1)&1){
Accuracy = !Accuracy;
BulletEnable = false;
}
//----------------------------------------------------------------------------------
pDevice->GetViewport(&g_ViewPort);
if(!fName)  D3DXCreateFont(pDevice, 18, 0, FW_BOLD, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Sylfaen", &fName);//15
if(!fSmall) D3DXCreateFont(pDevice, 18, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Sylfaen", &fSmall);//18
if(!Title)	D3DXCreateFont(pDevice, 18, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Sylfaen", &Title);//13
if(g_pFont == NULL) D3DXCreateFont(pDevice, 11, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Sylfaen", &g_pFont); //Create fonts
if(Menu_Font == NULL)D3DXCreateFont(pDevice, 18, 0, FW_EXTRALIGHT, 9, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE, (LPCSTR)"Trebuchet MS", &Menu_Font);
//----------------------------------------------------------------------------------
if(!pLine)	D3DXCreateLine( pDevice, &pLine );
if(uyeh == 0)
{
DrawCrosshair(pDevice);
if (Active==0) 
DrawRebuildMenu(pDevice);
DrawMenuShow(pDevice,30,70,pFonts);
DrawMenuNav(pDevice);
}
//----------------------------------------------------------------------------------
if(*(PBYTE)c_pPelorReload > NULL){
AimLockSC(pDevice);
DoQontolMode(pDevice);
//BackGround(pDevice);
EspMode(pDevice);
}
//AmmoReloads();
Reload0DetikCACAD();
ZombieHack();
//WPSmokeKiller();
//Bullet_Killer();
//----------------------------------------------------------------------------------
if(GetAsyncKeyState(VK_END)&1)
{
CallSuicide();
}
//----------------------------------------------------------------------------------
if(GetAsyncKeyState(VK_F2)&1)
{
FakeCyberAngels();
}
//----------------------------------------------------------------------------------
D3DVIEWPORT9 viewP;
////----------------------------------------------------------------------------------
pDevice->GetViewport(&viewP);
int ScreenCenterX = (float)viewP.Width / 2;
int ScreenCenterY = (float)viewP.Height / 2;
int ScreenBottomX = (float)viewP.Width;
int ScreenBottomY = (float)viewP.Height;
{
_My->DrawString(215,5,GREEN,  "Welcome To VIP Evolution X-Hack Leopard | ©CopyRight 2015 | Point Blank Garena Indonesia","");}
//----------------------------------------------------------------------------------
return oEndScene(pDevice);
}
//----------------------------------------------------------------------------------
DWORD CallpDevice;
HRESULT WINAPI hkDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount)
{
if(pDevice->GetStreamSource(0, &Stream_Data, &Offset, &Stride) == D3D_OK)
Stream_Data->Release();
//----------------------------------------------------------------------------------
if(WallCrot){
if(Stride == 44) // Tembok (hasil pencarin texture tadi "Stride")
{
DWORD dwOldZEnable;
pDevice-> GetRenderState (D3DRS_ZENABLE, & dwOldZEnable);
pDevice-> SetRenderState (D3DRS_ZENABLE, D3DZB_FALSE);// membuat tembok transparan
oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}
}
//----------------------------------------------------------------------------------
if(Phantom)
{   
if(allp)   
{            
pDevice->Clear(0, 0, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);	 
}}
//----------------------------------------------------------------------------------
if(UnSmoke){
if ((NumVertices == 192) || (NumVertices == 256))	  
{
return D3D_OK;
return 0;
}
}
//----------------------------------------------------------------------------------
if(NoFog)
{
pDevice->SetRenderState(D3DRS_FOGENABLE, false);
}
return oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}
//----------------------------------------------------------------------------------
DWORD WINAPI JhunayHook(LPVOID Param){
if (hGfxDx > 0){
DWORD tmp1 = (DWORD)GetModuleHandle("i3GfxDx.dll") + 0x1B2270;
DWORD tmp2 = 0;
Sleep(1);
while(!pGDevice){
if(IsBadReadPtr((PDWORD)tmp1,4)==NULL)tmp2 = *(PDWORD)((DWORD)(tmp1))+ 0x5368;
Sleep(1);
if(IsBadReadPtr((PDWORD)tmp2,4)==NULL){
Sleep(1);
DWORD OldProtect;
VirtualProtect((void*)(tmp2), 4, PAGE_EXECUTE_READWRITE, &OldProtect);
memcpy(&pGDevice, (void *)tmp2, 4);
VirtualProtect((void*)(tmp2), 4, OldProtect, NULL);
}
}
Sleep(1);
DWORD *g_pDevice = (DWORD*)pGDevice;
g_pDevice = (DWORD*)g_pDevice[0];
while(!pDevice)pDevice = (LPDIRECT3DDEVICE9)(DWORD*)g_pDevice;
*(PDWORD)&oEndScene					=		g_pDevice[42];
*(PDWORD)&oDrawIndexedPrimitive		=		g_pDevice[82];
Sleep(1);
DRC((PDWORD)(g_pDevice[1] - 5), (PDWORD)(g_pDevice[4] - 5));
Sleep(1);
DRC((PDWORD)(g_pDevice[2] - 5), (PDWORD)(g_pDevice[5] - 5));
Sleep(1);
DRC((PDWORD)(g_pDevice[3] - 5), (PDWORD)(g_pDevice[6] - 5));
Sleep(1);
DRC((PDWORD)(g_pDevice[4] - 5), (PDWORD)hkEndScene);
Sleep(1);
DRC((PDWORD)(g_pDevice[5] - 5), (PDWORD)hkDrawIndexedPrimitive);
Sleep(1);
while(1){
g_pDevice[42] = (DWORD)g_pDevice[1] - 5;
g_pDevice[82] = (DWORD)g_pDevice[2] - 5;
Sleep(1000); 
}
}
return 0;
}
//----------------------------------------------------------------------------------
int _stdcall Pemanggil_Hook(void)
{
CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)JhunayHook, NULL, NULL, NULL);
return TRUE;
}
//----------------------------------------------------------------------------------
BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
DisableThreadLibraryCalls(hDll);
if (dwReason == DLL_PROCESS_ATTACH)
{
StartRoutine(Pemanggil_Hook);
StartRoutine(Pemanggil_Fiture);
StartRoutine(NayzReplace);
StartRoutine(HOOKAIM);
Beep(1000,100);
}
return TRUE;
}
//----------------------------------------------------------------------------------