#include "CMenu.h"
#include "File.h"
#include "Hack.h"
#include "ESP.h"
#include "AIM.h"
#include "CSound.h"
#include "Textures.h"
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

cMenu Menu;
copt opt;
cSound Sound;

float ScreenCenterX = 0.0f;
float ScreenCenterY = 0.0f;
#define StartRoutine(Function) CreateThread(0,0,(LPTHREAD_START_ROUTINE)Function,0,0,0);
typedef HRESULT (WINAPI* tDrawIndexedPrimitive)(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount);
tDrawIndexedPrimitive oDrawIndexedPrimitive = NULL;

void PreReset( LPDIRECT3DDEVICE9 pDevice )
{ 
	Menu.PreReset();
	return;
}

void PostReset( LPDIRECT3DDEVICE9 pDevice )
{ 
	Menu.PostReset(pDevice);
	return;
}
/*------------------------------------------- Declaration GenerateTexture ------------------------------------------------------*/
LPDIRECT3DTEXTURE9 RainbowTextTestX;
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
/*------------------------------------------- Declaration DrawReset ------------------------------------------------------*/
typedef HRESULT ( WINAPI* oReset )( LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters );
oReset pReset;
HRESULT APIENTRY myReset( LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters )
{
	_asm pushad;

	if( Tools.pLine )
        Tools.pLine->OnLostDevice();

	HRESULT hRet = pReset( pDevice, pPresentationParameters );
	
	if( SUCCEEDED( hRet ) )
	{
		if( Tools.pLine )
			Tools.pLine->OnResetDevice();
	}
	_asm popad;

	return hRet;
}

typedef HRESULT	( WINAPI* oEndScene )( LPDIRECT3DDEVICE9 pDevice );
oEndScene pEndScene;

HRESULT APIENTRY myEndScene( LPDIRECT3DDEVICE9 pDevice )
{
	_asm pushad;

	if(!fName)  D3DXCreateFont(pDevice, 11, 0, FW_BOLD  , 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Tahoma"			 , &fName);//15
   if(!GetBattleState()){
			opt.cWeapon.FastShot=0;
			opt.cWeapon.RapidFire=0;
			opt.cSpesial.FakeReplace=0;
			opt.cPlayer.UNYU=0;
			opt.ModAim.Accuracy=0;
			opt.cKiller.Zombie=0;
			opt.cSpesial.AutoAja=0;
			opt.cPlayer.WallBug=0;
			opt.cPlayer.FreeMove=0;
			opt.cWeapon.BrustKnife=0;
			opt.cKiller.Invincible=0;
			opt.cSpesial.smk=0;
			opt.cSpesial.lchr=0;
			opt.cSpesial.ram=0;
			opt.cPlayer.Freeze=0;
			opt.cKiller.BombKill=0;
		    opt.cKiller.PisoTeleKill=0;
			opt.cKiller.PisoTeleKill1=0;
   }
   
   if(GetBattleState()){
	if(IsKeyPressed(VK_END, 0)&1){
		KillMySelf();
	}}
   if(GetBattleState()){
	       if(IsKeyPressed(VK_HOME, 0)&1){
		   opt.ModAim.Accuracy = !opt.ModAim.Accuracy;
		     BulletEnable = false;
	           }}
		if(GetBattleState()){
			if(IsKeyPressed(VK_F2, 0)&1){
				FakeEvolution();
			}}
		if(opt.cSpesial.AutoAja == 1)
	{
		if(IsKeyPressed(VK_LBUTTON, 1)&1){
		FakeEvolution();}
	}
		
	if(GetBattleState()){
if(opt.cKiller.FastDM == 1)
{
		KillMySelf();
		opt.cKiller.PisoTeleKill=!opt.cKiller.PisoTeleKill;
		opt.cKiller.WsHt=!opt.cKiller.WsHt;
		opt.cKiller.Invincible=!opt.cKiller.Invincible;
		opt.cKiller.TellePlayer=!opt.cKiller.TellePlayer;
		opt.cPlayer.Freeze=!opt.cPlayer.Freeze;}}
	if(GetBattleState()){
if(opt.cKiller.FastBM == 1)
{
		KillMySelf();
		opt.cKiller.PisoTeleKill=!opt.cKiller.PisoTeleKill;
		opt.cKiller.WsHt=!opt.cKiller.WsHt;
		opt.cKiller.Invincible=!opt.cKiller.Invincible;
		opt.cKiller.TellePlayer=!opt.cKiller.TellePlayer;
		}}
	if(IsKeyPressed(VK_F12, 0)&1)
	{
		ExitProcess(0);
	}
	if(!Tools.Init)
	{
			D3DXCreateLine(pDevice,&Tools.pLine);
			Tools.Init = TRUE;
	}
		PostReset(pDevice);
		Menu.ShowMenu(pDevice);
		PreReset(pDevice);
		

		pDevice->GetViewport(&Tools.g_ViewPort);
		ScreenCenterX = (float)Tools.g_ViewPort.Width / 2;
		ScreenCenterY = (float)Tools.g_ViewPort.Height / 2;
		if(*(PBYTE)ResultBaseAmmo2 > NULL)
		{
			EspMode(pDevice);
			DoAimBullet(pDevice);
			if(opt.ModAim.AutoHS2)
			{
			DoAutoHSNoSyarat(pDevice);
			}
			DoAutoShot();
			RapidFireWeapon();
			GhostHacks();
			BulletKiller();
		    SmokeKill();
		    GrenadeKill();
			LimitedAllSlotAmmo();
			AmmoRocket();
		    AmmoHK69();
		    AmmoLauncher();
			FastReload();
			BrustKnife();
			AmmoReload();
			AmmoGrenade();
			UnlimitedSmoke();
			
		}

	if(opt.d3d.cross)
	{
		Tools.FillRGB(ScreenCenterX-14, ScreenCenterY, 10, 1,D3DXCOLOR(1.0, 0.0, 0.0, 1.0),pDevice);//Left line
		Tools.FillRGB(ScreenCenterX+5, ScreenCenterY, 10, 1,D3DXCOLOR(1.0, 0.0, 0.0, 1.0),pDevice);//Right line
		Tools.FillRGB(ScreenCenterX, ScreenCenterY-14, 1, 10,D3DXCOLOR(1.0, 0.0, 0.0, 1.0),pDevice);//Top line
		Tools.FillRGB(ScreenCenterX, ScreenCenterY+5, 1, 10,D3DXCOLOR(1.0, 0.0, 0.0, 1.0),pDevice);//Bottom line
		Tools.DrawCircle(D3DXVECTOR2(ScreenCenterX,ScreenCenterY),8,60,D3DXCOLOR(1.0, 0.0, 0.0, 1.0));//Circle
		Tools.DrawPoint(ScreenCenterX,ScreenCenterY,1,1,D3DXCOLOR(0.0, 1.0, 0.0, 1.0),pDevice);//Point
	}
	_asm popad;

	return pEndScene( pDevice );
}
/*------------------------------------------- Declaration DrawIndexPrim ------------------------------------------------------*/
typedef HRESULT (WINAPI* tDrawIndexedPrimitive)(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount);
tDrawIndexedPrimitive pDrawIndexedPrimitive;

HRESULT WINAPI myDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount)
{

if(pDevice->GetStreamSource(0, &Stream_Data, &Offset, &Stride) == D3D_OK){
Stream_Data->Release();
}/*--------------------------------- Declaration Wallhack Clean --------------------------------------------*/
if(GetBattleState()){
if(opt.d3d.WHClean==1)
{   
	if(allp)   
	{            
		pDevice->SetRenderState(D3DRS_ZENABLE, false);
		pDevice->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
		pDevice->SetRenderState(D3DRS_ZENABLE, true);
		pDevice->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
	}
}}
if(opt.d3d.chamsWeapon)
{
	if(Weaponz){
pDevice->SetRenderState( D3DRS_ZENABLE, false ); 
pDevice->SetTexture(0, RainbowTextTestX );
oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount); 
pDevice->SetRenderState( D3DRS_ZENABLE, true ); 
pDevice->SetTexture(0, RainbowTextTestX ); 
	}}
/*--------------------------------- Declaration Wallhack Kaca --------------------------------------------*/
if(GetBattleState()){
if(opt.d3d.WHRobot==1)
{   
	if(allp)   
	{            
		pDevice->Clear(0, 0, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
		pDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
	}
}}

/*--------------------------------- Declaration Wallhack Champ --------------------------------------------*/
if(GetBattleState()){
if(opt.d3d.Chams==1)
{
	if(cTeroH)
	{
		pDevice->SetRenderState(D3DRS_ZENABLE, false);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, RainbowTextTestX);
		pDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount); 
		pDevice->SetRenderState(D3DRS_ZENABLE, true);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, RainbowTextTestX);
	}
	
	if(cPoliceH)
	{
		pDevice->SetRenderState(D3DRS_ZENABLE, false);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, RainbowTextTestX);
		pDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount); 
		pDevice->SetRenderState(D3DRS_ZENABLE, true);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, RainbowTextTestX);
	}
}}

/*--------------------------------- Declaration NoSmoke --------------------------------------------*/
if(GetBattleState()){
if(opt.d3d.DontSmoke==1)
{
	if ((NumVertices == 192) || (NumVertices == 256))	  
	{
		return D3D_OK;
		return 0;
	}
}}



	return pDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}
/*-------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------- Declaration HookEngine ------------------------------------------------------*/
DWORD WINAPI HookEngine()
{
	if (hGfxDx > 0){
		DWORD tmp1 = (DWORD)GetProcAddress(GetModuleHandleA("i3GfxDx.dll"), "?g_pRenderContext@@3PAVi3RenderContext@@A");
		DWORD tmp2 = 0;
		Sleep(1);
		while(!pGDevice){
			if(IsBadReadPtr((PDWORD)tmp1,4)==NULL)tmp2 = *(PDWORD)((DWORD)(tmp1))+0x5368;
			Sleep(1);
			if(IsBadReadPtr((PDWORD)tmp2,4)==NULL){
				DWORD OldProtect;
				VirtualProtect((void*)(tmp2), 4, PAGE_EXECUTE_READWRITE, &OldProtect);
				memcpy(&pGDevice, (void *)tmp2, 4);
				VirtualProtect((void*)(tmp2), 4, OldProtect, NULL);}
		}
		DWORD *g_pDevice = (DWORD*)pGDevice;
		g_pDevice = (DWORD*)g_pDevice[0];
		while(!npDevice)npDevice = (LPDIRECT3DDEVICE9)(DWORD*)g_pDevice;
		*(PDWORD)&pEndScene	= g_pDevice[42];
		*(PDWORD)&pDrawIndexedPrimitive	= g_pDevice[82];
		*(PDWORD)&pReset	= g_pDevice[16];
		Hooked((PDWORD)(g_pDevice[1] - 5), (PDWORD)(g_pDevice[4] - 5));
		Hooked((PDWORD)(g_pDevice[2] - 5), (PDWORD)(g_pDevice[5] - 5));
		Hooked((PDWORD)(g_pDevice[3] - 5), (PDWORD)(g_pDevice[6] - 5));
		Hooked((PDWORD)(g_pDevice[4] - 5), (PDWORD)myEndScene);
		Hooked((PDWORD)(g_pDevice[5] - 5), (PDWORD)myDrawIndexedPrimitive);
		Hooked((PDWORD)(g_pDevice[6] - 5), (PDWORD)myReset);
		for(;;)
		{
			g_pDevice[42] = (DWORD)g_pDevice[1] - 5;
			g_pDevice[82] = (DWORD)g_pDevice[2] - 5;
			g_pDevice[16] = (DWORD)g_pDevice[3] - 5;
		}
		Sleep(100); 
	}
	return (0);
}
VOID WINAPI DIRECT3D()
{
	PDWORD D3DVTable;
	do
	{
		*(DWORD*)&D3DVTable = *(DWORD*)Tools.D3D9VTable();
	}
	while ( !D3DVTable );
	
	pReset		=	(oReset)	Tools.DetourCreate((PBYTE)D3DVTable[16],(PBYTE)myReset,5);
	pEndScene	=	(oEndScene)	Tools.DetourCreate((PBYTE)D3DVTable[42],(PBYTE)myEndScene,5);
}
int _stdcall EricPedra(void)
{
	StartRoutine(RankGMM);
	StartRoutine(Protocol_Portal);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)HookEngine, NULL, NULL, NULL);
return TRUE;
}
BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
	switch(dwReason)
	{
		case DLL_PROCESS_ATTACH:
			StartRoutine(SearchLogger);//1
			StartRoutine(HookTelekill);//2
			StartRoutine(EricPedra);//2
			GetModuleFileNameA( hDll, dlldir, 512 );
			for(int i = ( int )strlen( dlldir ); i > 0; i--)
			{
				if(dlldir[i] == '\\')
				{ 
					dlldir[i+1] = 0;
					break; 
				}
			}
		break;

		case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}	