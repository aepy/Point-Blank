#include "CMenu.h"
#include "Texture.h"
#include "AimEsp.h"
#include "SmokeKiller.h"
#include "ProtectHWID.h"
#include "BombKiller.h"
#include "AutoShot.h"
#include "Ammo.h"

#define NFCZ(Function) CreateThread(0,0,(LPTHREAD_START_ROUTINE)Function,0,0,0);

typedef HRESULT (WINAPI* tEndScene)(LPDIRECT3DDEVICE9 pDevice);
tEndScene oEndScene;

typedef HRESULT (WINAPI* tDrawIndexedPrimitive)(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount);
tDrawIndexedPrimitive oDrawIndexedPrimitive = NULL;

CHAR Timestruct[ MAX_PATH ] = { "hh':'mm':'ss tt" }; //Estrutura do relógio.
CHAR TimeString[ MAX_PATH ];

void InstallPresent(LPDIRECT3DDEVICE9 pDevice){

if(IsKeyPressed(VK_INSERT,0)) ShowX = !ShowX;

if (ShowX == true){

if (FontCreate == true){
D3DXCreateFontA(pDevice, 13, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Comic Sans MS", &NHT3XT);
D3DXCreateFontA(pDevice, 13, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Comic Sans MS", &pFont);
D3DXCreateFontA(pDevice, 13, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Comic Sans MS", &fName);
D3DXCreateFontA(pDevice, 13, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Comic Sans MS", &Title);
if(!pLine)D3DXCreateLine(pDevice, &pLine);
FontCreate = false;
}

if(MenuX_sShow == 1){
if(Menu && NHT3XT){

GetTimeFormat( 0, 0, 0, 0, Timestruct, 15 );//Estrutura do relógio.
sprintf_s( TimeString, "%s", Timestruct );//Buffer do relógio

pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
RenderMenu_S(pDevice);
}}

	}
	return;
}

//-------------------------------------GenerateTexture-----------------------------------------------------------------------------------------
bool Color			= true;
LPDIRECT3DTEXTURE9 WhiteX,RedX,GreenX,BlueX,BlackX,PurpleX,GreyX,YellowX,OrangeX,RainbowTextTestX;
HRESULT GenerateTexture(IDirect3DDevice9 *pD3Ddev, IDirect3DTexture9 **ppD3Dtex, DWORD colour32)
{
    if(FAILED(pD3Ddev->CreateTexture(8, 8, 1, 0, D3DFMT_A4R4G4B4, D3DPOOL_MANAGED, ppD3Dtex, NULL)))
        return E_FAIL;
    
    WORD colour16 = ((WORD)((colour32>>28)&0xF)<<12)
	            	|(WORD)(((colour32>>20)&0xF)<<8)
	             	|(WORD)(((colour32>>12)&0xF)<<4)
                 	|(WORD)(((colour32>>4)&0xF)<<0);

    D3DLOCKED_RECT d3dlr;    
    (*ppD3Dtex)->LockRect(0, &d3dlr, 0, 0);
    WORD *pDst16 = (WORD*)d3dlr.pBits;

    for(int xy=0; xy < 8*8; xy++)
        *pDst16++ = colour16;

    (*ppD3Dtex)->UnlockRect(0);

    return S_OK;
}

HRESULT WINAPI hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	if(RainbowTexts!=100)
	{RainbowR-=2,RainbowG-=3,RainbowB-=3;}
	if(RainbowTexts!=255)
	{RainbowR+=2,RainbowG+=3,RainbowB+=4;}
	GenerateTexture(pDevice, &RainbowTextTestX,  RainbowTextTest);


	
	InstallPresent(pDevice);

	if(CROSS)
	{
		D3DVIEWPORT9 viewP;
		pDevice->GetViewport( &viewP );
		DWORD ScreenCenterX = viewP.Width / 2; 
		DWORD ScreenCenterY = viewP.Height / 2; 

		D3DRECT rec1 = {ScreenCenterX-35, ScreenCenterY, ScreenCenterX+ 35, ScreenCenterY+1};
		D3DRECT rec2 =	{ScreenCenterX, ScreenCenterY-35, ScreenCenterX+ 1,ScreenCenterY+35};  

		if(CROSS==1)
		{	
			D3DRECT rec10 = {ScreenCenterX-6, ScreenCenterY, ScreenCenterX+ 6, ScreenCenterY+1};
			D3DRECT rec11 = {ScreenCenterX, ScreenCenterY-6, ScreenCenterX+ 1,ScreenCenterY+6};  
			pDevice->Clear( 1, &rec10, D3DCLEAR_TARGET, D3DXCOLOR(0.0, 1.0, 0.0, 1.0), 0,  0 );// green
			pDevice->Clear( 1, &rec11, D3DCLEAR_TARGET, D3DXCOLOR(0.0, 1.0, 0.0, 1.0), 0,  0 );

			D3DRECT rec12 = {ScreenCenterX-4, ScreenCenterY, ScreenCenterX+ 4, ScreenCenterY+1};
			D3DRECT rec13 = {ScreenCenterX, ScreenCenterY-4, ScreenCenterX+ 1,ScreenCenterY+4};  
			pDevice->Clear( 1, &rec12, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 1.0, 0.0, 1.0), 0,  0 );// yellow
			pDevice->Clear( 1, &rec13, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 1.0, 0.0, 1.0), 0,  0 );

			D3DRECT rec16 = {ScreenCenterX-1, ScreenCenterY, ScreenCenterX+ 1, ScreenCenterY+1};
			D3DRECT rec17 = {ScreenCenterX, ScreenCenterY-1, ScreenCenterX+ 1,ScreenCenterY+1};  
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), 0,  0 );//red
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), 0,  0 );
		}
		if(CROSS==2)
		{	
			D3DRECT rec16 = {ScreenCenterX-2, ScreenCenterY-2, ScreenCenterX+ 2, ScreenCenterY+2};
			D3DRECT rec17 = {ScreenCenterX-2, ScreenCenterY-2, ScreenCenterX+ 2,ScreenCenterY+2};  
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), 0,  0 );//red
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), 0,  0 );
		}
		
	}
		
if(GetAsyncKeyState(VK_END))
{
	GameFastExit = !GameFastExit;Beep(1000,200);}
	if (GameFastExit) { ExitProcess(0);}

if (SyechrulBrutal)
	if(GetAsyncKeyState(0x01)){
		RapidFire=1;
		FakeSyechrul=!FakeSyechrul;
		FakeSyechrulAnjay();
	}
if (DinanBrutal)
	if(GetAsyncKeyState(0x01)){
		RapidFire=1;
		FakeDinan=!FakeDinan;
		FakeDinanAnjay();
	}
if(Bomberman==1){
	AmmoBomb=!AmmoBomb;
	RapidFire=!RapidFire;
}
//--------------------------------------------------------------------
DWORD CallFunction = *(DWORD*)ResultBaseAmmo2;
if(CallFunction != 0x000000){
AIMBulletMode(pDevice);
DrawObserver(pDevice);
NNCZESPMode(pDevice);
NNCZBone(pDevice);
WPSMOKEFUNCTION();
BULLETFUNCTION();
DinanKillYou1();
BrustKnifeXX();
AmmoReload();
DoAutoShot();
Suicide();
AmmoLauncher();
AmmoSecondary();
AmmoGrenade();
_Fitur_RapidFire();
FastReloadWeapon();
if(KillerKey==1){CallLineHit(); }
if(OnAutoKiller==1){AutoKill();}
if(AutoKillerz==1){AutoKillerzz();}


}
//--------------------------------------------------------------------
if(!GetBattleState1()){
BulletCall = NULL;
Invincible = NULL;
SmokeCall = NULL;
BombKiller = NULL;
BulletDinan = NULL;
AntiOut = 0;
Rep_Item = 0;
ReplaceRPG = 0;
R_Secondary = 0;
R_Mele = 0;
R_Launcher = 0;
ReplaceRPG2 = 0;
WallShot = NULL;
BombCall = NULL;
RapidFire = NULL;
DAMAGESMOKE=0;
DamageBomb=0;
AimBullet=0;
AutoShot=0;
FakeReplace=0;
FakeAbal=0;
Wallbug=0;
JumpHight=0;
BugUnyu=0;
BugLuxivile=0;
ZombieCall=0;
VoteKick=0;
Ammo=0;
AmmoLC=0;
AmmoSmoke=0;
AmmoBomb=0;
}
PrintTextv2("Blog Unknown Hack : www.ghr-vip.blogspot.com",250, 10, Orange, NHT3XT);

	return oEndScene(pDevice);
}

//---------------------------------------------DrawIndexedPrimitive---------------------------------------------------------------------------------------

DWORD CallpDevice;
HRESULT WINAPI hkDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount)
{
	if(pDevice->GetStreamSource(0, &iStreamData, &iOffset, &iStride) == D3D_OK)
		iStreamData->Release();
if(Color)
	{
		GenerateTexture(pDevice, &WhiteX,  White);
		GenerateTexture(pDevice, &RedX,    Red);
		GenerateTexture(pDevice, &GreenX,  Green);
		GenerateTexture(pDevice, &BlueX,   Blue);
		GenerateTexture(pDevice, &BlackX,  Black);
		GenerateTexture(pDevice, &PurpleX, Purple);
		GenerateTexture(pDevice, &GreyX,   Grey);
		GenerateTexture(pDevice, &YellowX, Yellow);
		GenerateTexture(pDevice, &OrangeX, Orange);
		Color = false;
	}

if(WallHack)
{
if(playersterror){
pDevice->SetRenderState(D3DRS_ZENABLE, 0);
oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
pDevice->SetRenderState(D3DRS_ZENABLE, 1);
}
if(playersswat){
pDevice->SetRenderState(D3DRS_ZENABLE, 0);
oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
pDevice->SetRenderState(D3DRS_ZENABLE, 1);
}
if (allp){	
pDevice->SetRenderState(D3DRS_ZENABLE, 0);
oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
pDevice->SetRenderState(D3DRS_ZENABLE, 1);
}
	
}
if(Leopard){
pDevice->SetRenderState(D3DRS_ZENABLE, false);
oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
pDevice->SetRenderState(D3DRS_ZENABLE, true);
}
if(WHRobot)
{   
	if(allp)   
	{            
		pDevice->Clear(0, 0, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
		oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
	}
}
if(ChamsTR)
{
	if(playersterror){
		pDevice->SetRenderState(D3DRS_ZENABLE, false);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, RedX);
		oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount); 
		pDevice->SetRenderState(D3DRS_ZENABLE, true);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, RedX);
	}
}

if(ChamsCT)
{
	if(playersswat){

		pDevice->SetRenderState(D3DRS_ZENABLE, false);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, BlueX);
		oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount); 
		pDevice->SetRenderState(D3DRS_ZENABLE, true);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, BlueX);
	}}
if(ChamsWeapon)
{
	if(Weaponz){

		pDevice->SetRenderState(D3DRS_ZENABLE, false);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, YellowX);
		oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount); 
		pDevice->SetRenderState(D3DRS_ZENABLE, true);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, YellowX);
	}}
if(ChamsRainbow)
{
	if(playersterror)
	{
		pDevice->SetRenderState(D3DRS_ZENABLE, false);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, RainbowTextTestX);
		oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount); 
		pDevice->SetRenderState(D3DRS_ZENABLE, true);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, RainbowTextTestX);
	}
	
	if(playersswat)
	{
		pDevice->SetRenderState(D3DRS_ZENABLE, false);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, RainbowTextTestX);
		oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount); 
		pDevice->SetRenderState(D3DRS_ZENABLE, true);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, RainbowTextTestX);
	}
}
if(NOSMOKE){
if ((NumVertices == 192) || (NumVertices == 256))	  {
return D3D_OK;
return 0;
}}
	
return oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

#include "Hook.h"
int _stdcall NNCZCallThread (void){
	NFCZ(NNCZHack);
NFCZ(NNCZReplace);
return TRUE;
}
BOOL WINAPI DllMain ( HMODULE hNFCZ, DWORD dwReason, LPVOID lpReserved ){
DisableThreadLibraryCalls(hNFCZ);

if (dwReason == DLL_PROCESS_ATTACH){
MessageBox(0,"Status Cheat :\n AKTIF !","Information",MB_OK );
NNCZUpdater();
CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)NFCZHooked, NULL, NULL, NULL);
CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)GHOST_Hacks, NULL, NULL, NULL);
CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)NNCZCallThread, NULL, NULL, NULL);
}
	return TRUE;
}
