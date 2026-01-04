#include "Xstr.h"
#include "Updater_Main.h"
#include "MenuX_Source.h"
#include "TextureD3d.h"
//---MenuX Fitur---//
#include "MenuX_ESP.h"
#include "MenuX_AIM.h"
#include "MenuX_Ammo.h"
#include "MenuX_Hack.h"
#include "AutoKick.h"
//---MenuX---//
#include "MenuX_Standar.h"
#include "MenuX_Mouse.h"
#include "WPSmoke.h"
#include "Telemagnet.h"
#include "RelpaceAll.h"
LPD3DXFONT      g_pFont = NULL; 
D3DVIEWPORT9 g_ViewPort;
LPD3DXLINE pLine    = NULL;
bool ShowX			= true;
int MenuX_Minisize	= 1;
int MenuX_Maling	= 0;
		
void InstallPresent(LPDIRECT3DDEVICE9 pDevice)
{
	if(IsKeyPressed(VK_INSERT,0)) ShowX = !ShowX;
	if (ShowX == true)
	{
		if (FontCreate == true)
		{
			D3DXCreateFontA(pDevice, 15, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &NHT3XT);
			D3DXCreateLine(pDevice, &NHLine);
			FontCreate = false;
		}
		if (MenuX_Minisize == 1)
		{
			pMenu.BoardersMinimize(pDevice);
			pMenu.SelectionButtonMinimize(MenuX_MouseShow,457,19,pDevice);
			MenuX_MouseShow	= (int)pMenu.SelectionMinimizeReturn(457,19,MenuX_MouseShow);
		}
		if (MenuX_MouseShow == 1)
		{
			if(Menu && NHT3XT)
			{
				MenuX_Minisize	= 1;
				MenuX_sShow		= 0;
				pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
				RenderMenu_M(pDevice);
			}
		}
		if(MenuX_sShow == 1)
		{
			if(Menu && NHT3XT)
			{  
				MenuX_Minisize	= 0;
				MenuX_MouseShow = 0;
				pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
				RenderMenu_S(pDevice);
			}
		}
		if(MenuX_Maling == 1)
		{
			DrawStringESP(1, 1, Green,"Wahh Wahh Kenapa Di Rename Dll.nya ?...Mau Maling yaa ?...Atau Mau Mengaku-Ngaku kalau ini Cheat Lu Bang ?...");
			DrawStringESP(1, 20, Red,"Bagi yang Kepingin Memakai cheat Hubungi fecebook di bawah ini");
			DrawStringESP(1, 40, Yellow,"https://www.facebook.com/Sadamjamming");
		}
	}
	return;
}

//-------------------------------------GenerateTexture-----------------------------------------------------------------------------------------
bool Color			= true;
LPDIRECT3DTEXTURE9 WhiteX,RedX,GreenX,BlueX,BlackX,PurpleX,GreyX,YellowX,OrangeX;
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

HRESULT WINAPI pGEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	
	InstallPresent(pDevice);

	if(Nh_Teknology34)
	{
		D3DVIEWPORT9 viewP;
		pDevice->GetViewport( &viewP );
		DWORD ScreenCenterX = viewP.Width / 2; 
		DWORD ScreenCenterY = viewP.Height / 2; 

		D3DRECT rec1 = {ScreenCenterX-35, ScreenCenterY, ScreenCenterX+ 35, ScreenCenterY+1};
		D3DRECT rec2 =	{ScreenCenterX, ScreenCenterY-35, ScreenCenterX+ 1,ScreenCenterY+35};  

		if(Nh_Teknology34==1)
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
		if(Nh_Teknology34==2)
		{	
			D3DRECT rec16 = {ScreenCenterX-2, ScreenCenterY-2, ScreenCenterX+ 2, ScreenCenterY+2};
			D3DRECT rec17 = {ScreenCenterX-2, ScreenCenterY-2, ScreenCenterX+ 2,ScreenCenterY+2};  
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), 0,  0 );//red
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), 0,  0 );
		}
		
	}
	if(GetAsyncKeyState(0x5A)){FastKelar  = !FastKelar ;Beep(2000,200);}//Abjad ('Z')
	if(GetAsyncKeyState(0x58)){FastKelar1 = !FastKelar1;Beep(2000,200);}//Abjad ('X')

	if(GetAsyncKeyState(VK_F12)){GameFastExit = !GameFastExit;Beep(2000,200);}
	if (GameFastExit) { ExitProcess(0);}
if(!GetBattleState1()){
Nh_Teknology9      = 0;
Accuracy           = 0;
AimBody            = 0;
BulletEnable = false;
}
if(FastKelar1 == 1)
{
		FastKiller=0;
		SmokeCall=0;
		WallShotHero=0;
		Invincible=0;
		MagnetTele=0;
DrawStringESP(800,  10, White,"Fast Killer ( Abjad X )");
DrawStringESP(1000, 10, Red  ,"Fast Killer ( OFF )");
}
if(FastKelar == 1)
{
		FastKiller=1;
		SmokeCall=1;
		WallShotHero=1;
		Invincible=1;
		MagnetTele=1;
DrawStringESP(800,  10, Green,"Fast Killer ( Abjad Z )");
DrawStringESP(1000, 10, Red  ,"Fast Killer ( ON )");
}
	if(GetAsyncKeyState(VK_LSHIFT)&1){UNYU=!UNYU;}
	if(GetAsyncKeyState(0x31)&1){BULLETFUNCTION();}
	if(GetAsyncKeyState(VK_F2)&1){FakeAbal1();}
	if(GetAsyncKeyState(0x35)&1){FakeSmokeKhusus();}

pDevice->GetViewport(&g_ViewPort);
if(!fName)  D3DXCreateFont(pDevice, 14, 0, FW_NORMAL, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Hud_Small_Font", &fName);//15
if(!fSmall) D3DXCreateFont(pDevice, 14, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Hud_Small_Font", &fSmall);//18
if(g_pFont == NULL) D3DXCreateFont(pDevice, 11, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Sylfaen", &g_pFont); //Create fonts
//----------------------------------------------------------------------------------
if(!pLine)	D3DXCreateLine( pDevice, &pLine );
	if(*(PBYTE)ResultBaseAmmo2 > NULL)
	{
		MenuX_Esp(pDevice);	
		MenuX_DrawObserver(pDevice);
		MenuX_SmartAmmoX(pDevice);
		MenuX_DoBulletMode(pDevice);
		Telemagnet();
        FastReaload();
		WPSMOKEFUNCTION();
		BOMKiller();
        Suicide();
		DoAutoShot();
		AmmoRocket();
		AmmoLauncher();
        BomberKill();
		BomberMan();
		AmmoHK69();
		FastKillerz();
		KickPlayer(pDevice);
	}
	return oEndScene(pDevice);
}

//---------------------------------------------DrawIndexedPrimitive---------------------------------------------------------------------------------------

DWORD CallpDevice;
HRESULT WINAPI pGDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount)
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
	if(Nh_Teknology30)
	{	
		if(playersterror)
		{
			pDevice->SetRenderState(D3DRS_ZENABLE, 0);
			oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE, 1);
			if(Nh_Teknology30==1) pDevice->SetTexture(0, WhiteX);
			if(Nh_Teknology30==2) pDevice->SetTexture(0, RedX);
			if(Nh_Teknology30==3) pDevice->SetTexture(0, GreenX);
			if(Nh_Teknology30==4) pDevice->SetTexture(0, BlueX);
			if(Nh_Teknology30==5) pDevice->SetTexture(0, BlackX);
			if(Nh_Teknology30==6) pDevice->SetTexture(0, PurpleX);
			if(Nh_Teknology30==7) pDevice->SetTexture(0, GreyX);
			if(Nh_Teknology30==8) pDevice->SetTexture(0, YellowX);		
			if(Nh_Teknology30==9) pDevice->SetTexture(0, OrangeX);
		}
		if (allp)
		{	
			CallpDevice = 0;
			pDevice->SetRenderState(D3DRS_ZENABLE,CallpDevice);
		}
	}
	if(Nh_Teknology31)
	{
		if(playersswat)
		{
			pDevice->SetRenderState(D3DRS_ZENABLE, 0);
			oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE, 1);
			if(Nh_Teknology31==1) pDevice->SetTexture(0, WhiteX);
			if(Nh_Teknology31==2) pDevice->SetTexture(0, RedX);
			if(Nh_Teknology31==3) pDevice->SetTexture(0, GreenX);
			if(Nh_Teknology31==4) pDevice->SetTexture(0, BlueX);
			if(Nh_Teknology31==5) pDevice->SetTexture(0, BlackX);
			if(Nh_Teknology31==6) pDevice->SetTexture(0, PurpleX);
			if(Nh_Teknology31==7) pDevice->SetTexture(0, GreyX);
			if(Nh_Teknology31==8) pDevice->SetTexture(0, YellowX);		
			if(Nh_Teknology31==9) pDevice->SetTexture(0, OrangeX);
		}
		if (allp)
		{	
			CallpDevice = 0;
			pDevice->SetRenderState(D3DRS_ZENABLE,CallpDevice);
		}
	}
if(Wireframe)
	{
		if((iStride == 52 || iStride == 44 || iStride == 48))
		{
			pDevice->SetRenderState( D3DRS_FILLMODE, D3DFILL_WIREFRAME );
			if(Wireframe ==1) pDevice->SetTexture(0, WhiteX);
			if(Wireframe ==2) pDevice->SetTexture(0, RedX);
			if(Wireframe ==3) pDevice->SetTexture(0, GreenX);
			if(Wireframe ==4) pDevice->SetTexture(0, BlueX);
			if(Wireframe ==5) pDevice->SetTexture(0, BlackX);
			if(Wireframe ==6) pDevice->SetTexture(0, PurpleX);
			if(Wireframe ==7) pDevice->SetTexture(0, GreyX);
			if(Wireframe ==8) pDevice->SetTexture(0, YellowX);		
			if(Wireframe ==9) pDevice->SetTexture(0, OrangeX);
				 } 
		 else{         
			pDevice->SetRenderState( D3DRS_FILLMODE, D3DFILL_SOLID );
		}
	}
if(Nh_Teknology32)
{
	if(playersterror)
		{
			pDevice->SetRenderState(D3DRS_ZENABLE, 0);
			oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE, 1);
		}
	if(playersswat)
		{
			pDevice->SetRenderState(D3DRS_ZENABLE, 0);
			oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE, 1);
		}
	if (allp)
		{	
			pDevice->SetRenderState(D3DRS_ZENABLE, 0);
			oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE, 1);
		}
	
}
if(Nh_Teknology33)
	{
		if ((NumVertices == 192) || (NumVertices == 256))	  
		{
			return D3D_OK;
			return 0;
		}
	}
	return oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

#include "MenuX_Hook.h"


BOOL WINAPI DllMain ( HMODULE hDll, DWORD dwReason, LPVOID lpReserved )
{
	char strDLLName [_MAX_PATH];
	GetModuleFileName(hDll, strDLLName , _MAX_PATH);
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hDll);
		//GetModuleFileName(hDll, dlldir, 512);
//for(int i = strlen(dlldir); i > 0; i--) { if(dlldir[i] == '\\') { dlldir[i+1] = 0; break;}}
//infile.open(GetDirectoryFile("SearchOFSbase.txt"), ios::out);
		MenuX_Updater();;
		HTSN(MenuX_Hooking);;
		HTSN(MenuX_BuletHooK);;
		HTSN(MenuX_Hack);;
		HTSN(ThreadFloodVK);;
		HTSN(NNCZReplace);;
		HTSN(VKPilih);;
		HTSN(GHOSTHacks);;

		if (strstr(strDLLName, "Trisha-Marley.dll") <= 0)
		{
			MenuX_Maling	= 1;
			MenuX_Minisize	= 0;
			MenuX_MouseShow = 0;
			MenuX_sShow		= 0;
		}
	}
	return TRUE;
}
