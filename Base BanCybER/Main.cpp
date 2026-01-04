/*Main.cpp D3D9 PBHacks Last Edit By BanCyberz Hacks*/
/*------------------------------------------- PB Hacks By BanCyberz™ Hacks ----------------------------------------------------*/
/*------------------------------------------ Created AzmiPr Copyright 2016 -------------------------------------------------*/
/*----------------------------------------- Thanks For Google & My Computer -------------------------------------------------*/
#include <windows.h>
#include <wininet.h>
#include <time.h>
#include "Stdafx.h"
#include "cMenu.h"
#include "cStride.h"

/*-------------------------------------------------------------------------------------------------------------------*/
typedef HRESULT (WINAPI* tEndScene)(LPDIRECT3DDEVICE9 pDevice);
tEndScene oEndScene = NULL;

typedef HRESULT (WINAPI* tDrawIndexedPrimitive)(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount);
tDrawIndexedPrimitive oDrawIndexedPrimitive = NULL;

typedef HRESULT(WINAPI* tReset)(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
tReset oReset = NULL;

/*------------------------------------------- Declaration DrawCross ------------------------------------------------------*/
void Crosshair(LPDIRECT3DDEVICE9 pDevice, D3DCOLOR Color)
{
	int x = ( GetSystemMetrics( 0 ) / 2);
	int y = ( GetSystemMetrics( 1 ) / 2);
	Circle (x,y,6,true,Color,pDevice);
	FillRGB(x-10, y, 7, 1,Color,pDevice);
	FillRGB(x+4, y, 7, 1,Color,pDevice);
	FillRGB(x, y-10, 1, 7,Color,pDevice);
	FillRGB(x, y+4, 1, 7,Color,pDevice);
}

void DrawCrosshair(LPDIRECT3DDEVICE9 pDevice)
{
	if(RainbowTexts!=100)
	{RainbowR-=2,RainbowG-=3,RainbowB-=3;}
	if(RainbowTexts!=255)
	{RainbowR+=2,RainbowG+=3,RainbowB+=4;}
	if(Cross == 1)
	{
		Crosshair(pDevice, RainbowTextTest);
	}
}

/*------------------------------------------- Declaration DrawMenuD3D ------------------------------------------------------*/
void DrawMenuD3D(LPDIRECT3DDEVICE9 pDevice)
{
	if (DrawFont == 1) 
	{
		D3DXCreateFontA(pDevice, 11, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Tahoma", &pFont);
		DrawFont = 0;
	}

	if (Drawing == 0)
	{
		if(Mmax==0) 
		RebuildMenu(pDevice);
		MenuShow(mx,my,pDevice);
		MenuNav();
	}

	if(!g_pFont)	D3DXCreateFontA(pDevice, 15, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Hud_Small_Font", &g_pFont);//15
	if(!pLine)		D3DXCreateLine( pDevice, &pLine );
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

/*------------------------------------------- Declaration DrawEndScene ------------------------------------------------------*/
HRESULT WINAPI hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	pDevice->GetViewport(&g_ViewPort);
	DrawMenuD3D(pDevice);

	if(RainbowTexts!=100)
	{RainbowR-=2,RainbowG-=3,RainbowB-=3;}
	if(RainbowTexts!=255)
	{RainbowR+=2,RainbowG+=3,RainbowB+=4;}
	GenerateTexture(pDevice, &RainbowTextTestX,  RainbowTextTest);

	if(*(PBYTE)ResultBaseAmmo2 > NULL)
	{
		DrawESP(pDevice);
		DrawCrosshair(pDevice);
		DrawTextColor(pDevice);
		DoAimBot(pDevice);
		DoAimBullet(pDevice);
		if(AutoHS2)
		{
			DoAutoHSNoSyarat(pDevice);
		}
		if(AutoBody)
		{
			DoAutoBody(pDevice);
		}
		DoAutoShot();
		GhostHide();
		ThreadHaxAll();
	}

	if(IsKeyPressed(VK_F12, 0)&1)
	{
		ExitProcess(0);
	}
	return oEndScene(pDevice);
}

/*------------------------------------------- Declaration DrawIndexPrim ------------------------------------------------------*/
HRESULT WINAPI hkDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount)
{

if(pDevice->GetStreamSource(0, &Stream_Data, &Offset, &Stride) == D3D_OK){
Stream_Data->Release();
}

/*--------------------------------- Declaration Wallhack Clean --------------------------------------------*/
if(GetBattleState()){
if(WHClean==1)
{   
	if(allp)   
	{            
		pDevice->SetRenderState(D3DRS_ZENABLE, false);
		pDevice->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
		pDevice->SetRenderState(D3DRS_ZENABLE, true);
		pDevice->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
	}
}}

/*--------------------------------- Declaration Wallhack Kaca --------------------------------------------*/
if(GetBattleState()){
if(WHRobot==1)
{   
	if(allp)   
	{            
		pDevice->Clear(0, 0, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
		oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
	}
}}

/*--------------------------------- Declaration Wallhack Champ --------------------------------------------*/
if(GetBattleState()){
if(Chams==1)
{
	if(cTeroH)
	{
		pDevice->SetRenderState(D3DRS_ZENABLE, false);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, RainbowTextTestX);
		oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount); 
		pDevice->SetRenderState(D3DRS_ZENABLE, true);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, RainbowTextTestX);
	}
	
	if(cPoliceH)
	{
		pDevice->SetRenderState(D3DRS_ZENABLE, false);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, RainbowTextTestX);
		oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount); 
		pDevice->SetRenderState(D3DRS_ZENABLE, true);
		pDevice->SetRenderState(D3DRS_LIGHTING, D3DLIGHT_DIRECTIONAL);
		pDevice->SetTexture(0, RainbowTextTestX);
	}
}}

/*--------------------------------- Declaration NoSmoke --------------------------------------------*/
if(GetBattleState()){
if(DontSmoke==1)
{
	if ((NumVertices == 192) || (NumVertices == 256))	  
	{
		return D3D_OK;
		return 0;
	}
}}

/*--------------------------------- Declaration NoFog --------------------------------------------*/
if(GetBattleState()){
if(DontSmoke==1)                                                   
{
	pDevice->SetRenderState(D3DRS_FOGENABLE, false);
}}

	return oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

/*------------------------------------------- Declaration DrawReset ------------------------------------------------------*/
HRESULT WINAPI hkReset(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    if( g_pFont )
        g_pFont->OnLostDevice();

	if( pFont )
		pFont->OnLostDevice();

    if( pLine )
        pLine->OnLostDevice();

    if(oReset == D3D_OK) 
	{
		if( g_pFont )
            g_pFont->OnResetDevice();
		
		if( pFont )
			pFont->OnResetDevice();

        if( pLine )
            pLine->OnResetDevice();
	}

    return oReset(pDevice, pPresentationParameters);
}

/*------------------------------------------- Declaration HookEngine ------------------------------------------------------*/
DWORD WINAPI HookEngine()
{
	if (hGfxDx > 0){
		DWORD tmp1 = g_pRenderContext;
		DWORD tmp2 = 0;
		Sleep(1);
		while(!pGDevice){
			if(IsBadReadPtr((PDWORD)tmp1,4)==NULL)tmp2 = *(PDWORD)((DWORD)(tmp1))+ResultEndRender;
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
		*(PDWORD)&oEndScene	= g_pDevice[42];
		*(PDWORD)&oDrawIndexedPrimitive	= g_pDevice[82];
		*(PDWORD)&oReset	= g_pDevice[16];
		Hooked((PDWORD)(g_pDevice[1] - 5), (PDWORD)(g_pDevice[4] - 5));
		Hooked((PDWORD)(g_pDevice[2] - 5), (PDWORD)(g_pDevice[5] - 5));
		Hooked((PDWORD)(g_pDevice[3] - 5), (PDWORD)(g_pDevice[6] - 5));
		Hooked((PDWORD)(g_pDevice[4] - 5), (PDWORD)hkEndScene);
		Hooked((PDWORD)(g_pDevice[5] - 5), (PDWORD)hkDrawIndexedPrimitive);
		Hooked((PDWORD)(g_pDevice[6] - 5), (PDWORD)hkReset);
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

/*------------------------------------------- Declaration Hacks ------------------------------------------------------*/
DWORD WINAPI XThreadHax()
{
	for(;;)
	{
		if(RldM == 1)
		{
			LongPtr(ResultBasePlayer2, ResultSkillGM, 0x8, 0x41AF3B3F);
			LongPtr(ResultBasePlayer2, ResultSkillGM, 0xC, 0x41BE7D7E);
		}
		
		if(GetBattleState()){
		if(antigyg == 1)
		{
			for( int iR = 32; iR <= 108; iR += 4 )
				LongPtr(ResultBaseAmmo2, ResultPTRRecoil, iR, 0);
		}}
	
	Sleep(10);
	}
	return (0);
}

/*--------------------------------------- Declaration Caller AllThread --------------------------------------------------*/
void ZrCCyBCallerThread()
{
	SearchPatterns();
	Thread_Aimbot();
	HookTelekill();
	DWORD i3GfxDx,I3InputDx,i3SceneDx;
	DWORD dwStartAddress = 0x400000;
	do {
		dwStartAddress = (DWORD)GetModuleHandleA(PBExe);
		i3GfxDx = (DWORD)GetModuleHandleA(PBi3Gfx);
		I3InputDx = (DWORD)GetModuleHandleA(PBi3Ipt);
		i3SceneDx = (DWORD)GetModuleHandleA(PBi3Scn);
	}while(!dwStartAddress);
	DWORD dwSize = dwStartAddress + 0x6FFFFF;
	DWORD dwSizei3GfxDx = i3GfxDx + 0x1FFFFF;
	DWORD dwSizeI3InputDx_Hook = I3InputDx + 0x1FFFFF;
	DWORD dwSizei3SceneDx = i3SceneDx + 0x1FFFFF;
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)HookEngine,NULL,NULL,NULL);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)XThreadHax,NULL,NULL,NULL);
}

/*------------------------------------------- Declaration Attach Dll ------------------------------------------------------*/
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved)
{
	if(dwReason == DLL_PROCESS_ATTACH){
		DisableThreadLibraryCalls(hModule);
//		HideModule(hModule);
//		EraseHeaders(hModule);
//		UnlinkModule("PB.dll");
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ZrCCyBCallerThread,NULL,NULL,NULL);
		Beep(1000, 100);
}
return TRUE;
}

/*-------------------------------------------------------------------------------------------------------------------*/