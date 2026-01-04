/*Main.cpp D3D9 PBHacks Last Edit By Angga Reviza*/
/*------------------------------------------- PB Hacks By Angga Reviza ----------------------------------------------------*/
/*------------------------------------------ Created Angga Reviza Copyright 2015 -------------------------------------------------*/
/*----------------------------------------- Thanks For Google & My Computer -------------------------------------------------*/
#include <windows.h>
#include <wininet.h>
#include <time.h>
#include "Stdafx.h"
#include "cMenu.h"
#include "cStride.h"
#include "Securitied.h"
#include "FileFunctionHeader.h"
/*------------------------------------------- Declaration DrawEndScene ------------------------------------------------------*/
HRESULT WINAPI hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	pDevice->GetViewport(&g_ViewPort);
	DrawMenuD3D(pDevice);

	if(RainbowTexts!=100) 
	{
		RainbowR-=2,RainbowG-=3,RainbowB-=3;
	}
	if(RainbowTexts!=255)
	{
		RainbowR+=2,RainbowG+=3,RainbowB+=4;
	}
	GenerateTexture(pDevice, &RainbowTextTestX,  RainbowTextTest);

	/*------------------------ Declarasi Auto Off ---------------------------------*/
	if(!GetBattleState())
	{
		FsSht = 0;
		frpid = 0;
		DAMAGESMOKE= 0;
		BulletEnable = false;
	}

	if(*(PBYTE)ResultBaseAmmo2 > NULL)
	{
		DrawESP(pDevice);
		DoAimBullet(pDevice);
			if(AutoShot==1)
			{
				DoAutoShot();
			}
		ThreadHaxAll();
		WPSMOKEFUNCTION();
		BULLETFUNCTION();
	}

	if(IsKeyPressed(VK_F12, 0)&1)
	{
		ExitProcess(0);
	}

	if(GetAsyncKeyState(VK_F2)&1)
	{
		FakeAbal();
	}

	if(GetAsyncKeyState(VK_HOME)&1)
	{
		Accuracy = !Accuracy;
		BulletEnable = false;
	}

	if(GetAsyncKeyState(VK_END)&1)
	{
		KillMySelf();
	}

	if(GetBattleState()){
	if(GetAsyncKeyState(VK_LMENU)&1){
	Zombie=!Zombie;
	}}

	if(GetBattleState()){
	if(GetAsyncKeyState(VK_LSHIFT)&1){
	Ghost=!Ghost;
	}}

	if(GetAsyncKeyState(VK_CAPITAL)&1)
	{
		AutoHS2=!AutoHS2;
	}

	DrawString(170,5,PINK,"","");

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

#include "HookX3.h"
/*--------------------------------------- Declaration Caller AllThread --------------------------------------------------*/
void CallerThread()
{
//	CekSerialHwid();
	SearchPatterns();
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
//	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ThreadHaxAll,NULL,NULL,NULL);
}
/*------------------------------------------- Declaration Attach Dll ------------------------------------------------------*/
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved)
{
	if(dwReason == DLL_PROCESS_ATTACH){
		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)CallerThread,NULL,NULL,NULL);
		Beep(1000, 100);
}
return TRUE;
}

/*-------------------------------------------------------------------------------------------------------------------*/
