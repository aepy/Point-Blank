#include "Trial.h"
bool Color			= true;
#define CT(th,pr) CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(th), (LPVOID)pr, NULL, NULL)
DWORD CallpDevice;
HRESULT WINAPI hkDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount)
{  
if(pDevice->GetStreamSource(0, &Stream_Data, &Offset, &Stride) == D3D_OK)
Stream_Data->Release();
if(Color)
	{
		GenerateTexture(pDevice, &WhiteX,  WHITE);
		GenerateTexture(pDevice, &RedX,    RED);
		GenerateTexture(pDevice, &GreenX,  GREEN);
		GenerateTexture(pDevice, &BlueX,   BLUE);
		GenerateTexture(pDevice, &BlackX,  BLACK);
		GenerateTexture(pDevice, &PurpleX, PURPLE);
		GenerateTexture(pDevice, &GreyX,   GREY);
		GenerateTexture(pDevice, &YellowX, YELLOW);
		GenerateTexture(pDevice, &OrangeX, ORANGE);
		Color = false;
	}
//------------------------------------------//
if(WallCrot){
if(allp)   
{            
pDevice->SetRenderState(D3DRS_ZENABLE, false);
pDevice->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
pDevice->SetRenderState(D3DRS_ZENABLE, true);
pDevice->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
}}
if(Weapon)
	{
		if(allp)   
	 {            
		pDevice->Clear(0, 0, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
        oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
		 
		}}
if(chamsWeapon)
	{	
		if(playersterror)
		{
			pDevice->SetRenderState(D3DRS_ZENABLE, 0);
			oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE, 1);
			if(chamsWeapon==1) pDevice->SetTexture(0, WhiteX);
			if(chamsWeapon==2) pDevice->SetTexture(0, RedX);
			if(chamsWeapon==3) pDevice->SetTexture(0, GreenX);
			if(chamsWeapon==4) pDevice->SetTexture(0, BlueX);
			if(chamsWeapon==5) pDevice->SetTexture(0, BlackX);
			if(chamsWeapon==6) pDevice->SetTexture(0, PurpleX);
			if(chamsWeapon==7) pDevice->SetTexture(0, GreyX);
			if(chamsWeapon==8) pDevice->SetTexture(0, YellowX);		
			if(chamsWeapon==9) pDevice->SetTexture(0, OrangeX);
		}
		if (allp)
		{	
			CallpDevice = 0;
			pDevice->SetRenderState(D3DRS_ZENABLE,CallpDevice);
		}
	}
	if(chamsWeapon1)
	{
		if(playersswat)
		{
			pDevice->SetRenderState(D3DRS_ZENABLE, 0);
			oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE, 1);
			if(chamsWeapon1==1) pDevice->SetTexture(0, WhiteX);
			if(chamsWeapon1==2) pDevice->SetTexture(0, RedX);
			if(chamsWeapon1==3) pDevice->SetTexture(0, GreenX);
			if(chamsWeapon1==4) pDevice->SetTexture(0, BlueX);
			if(chamsWeapon1==5) pDevice->SetTexture(0, BlackX);
			if(chamsWeapon1==6) pDevice->SetTexture(0, PurpleX);
			if(chamsWeapon1==7) pDevice->SetTexture(0, GreyX);
			if(chamsWeapon1==8) pDevice->SetTexture(0, YellowX);		
			if(chamsWeapon1==9) pDevice->SetTexture(0, OrangeX);
		}
if (allp)
		{	
			CallpDevice = 0;
			pDevice->SetRenderState(D3DRS_ZENABLE,CallpDevice);
		}
	}
if(WallCrot){
if ((NumVertices == 192) || (NumVertices == 256))	  
{
return D3D_OK;
return 0;
}
}

if(WallCrot)
{
pDevice->SetRenderState(D3DRS_FOGENABLE, false);
}
return oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}
/*------------------------------------------- Declaration DrawReset ------------------------------------------------------*/
typedef HRESULT(WINAPI* oReset)(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
oReset pReset;
HRESULT APIENTRY myReset(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{

	/*LPDIRECT3DTEXTURE9	g_TexTest;
	LPD3DXSPRITE		g_pSprite;*/

	_asm pushad;

	if (g_pSprite)g_pSprite->OnLostDevice();
	
	if (Title)Title->OnLostDevice();
	if (fTime)fTime->OnLostDevice();
	if (fSmall)fSmall->OnLostDevice();
	if (fName)fName->OnLostDevice();
	if (pFont)pFont->OnLostDevice();
	if (g_pFont2)g_pFont2->OnLostDevice();
	if (pLine)pLine->OnLostDevice();

	HRESULT hRet = pReset(pDevice, pPresentationParameters);

	if (SUCCEEDED(hRet))
	{
		if (g_pSprite)g_pSprite->OnResetDevice();
		
		if (Title)Title->OnResetDevice();
		if (fTime)fTime->OnResetDevice();
		if (fSmall)fSmall->OnResetDevice();
		if (fName)fName->OnResetDevice();
		if (pFont)pFont->OnResetDevice();
		if (g_pFont2)g_pFont2->OnResetDevice();
		if (pLine)pLine->OnResetDevice();
	}
	_asm popad;

	return hRet;
}
//========================================================================================
void ProtectHook(PDWORD target, PDWORD newfunc){
DWORD Jmpto=(DWORD)(newfunc)-(DWORD)target-5;
DWORD RCH;
VirtualProtect(target, 8, PAGE_EXECUTE_READWRITE, &RCH);
*(PBYTE)(target)=0xE9;
*(PDWORD)((DWORD)(target)+1)=Jmpto;
VirtualProtect(target, 8, RCH, &RCH);
}

DWORD WINAPI Hooked(LPVOID Param){
if (hGfxDx > 0){ 
DWORD tmp1 = (DWORD)GetModuleHandle("i3GfxDx.dll") + HookBaseRender; 
DWORD tmp2 = 0; 
Sleep(1); 
while(!pGDevice){ 
if(IsBadReadPtr((PDWORD)tmp1,4)==NULL)tmp2 = *(PDWORD)((DWORD)(tmp1))+ ResultHook; Sleep(1); 
if(IsBadReadPtr((PDWORD)tmp2,4)==NULL){ Sleep(1); 
DWORD OldProtect; 
VirtualProtect((void*)(tmp2), 4, PAGE_EXECUTE_READWRITE, &OldProtect); 
memcpy(&pGDevice, (void *)tmp2, 4); 
VirtualProtect((void*)(tmp2), 4, OldProtect, NULL); 
} 
} 
Sleep(1); 
DWORD *g_pDevice = (DWORD*)pGDevice; 
g_pDevice = (DWORD*)g_pDevice[0]; 
while(!pDevice)
pDevice = (LPDIRECT3DDEVICE9)(DWORD*)g_pDevice; 
*(PDWORD)&oEndScene = g_pDevice[42]; 
//*(PDWORD)&oDrawIndexedPrimitive = g_pDevice[82]; 
*(PDWORD)&pReset = g_pDevice[16];
Sleep(1); 
ProtectHook((PDWORD)(g_pDevice[1] - 5), (PDWORD)(g_pDevice[4] - 5)); 
Sleep(1); 
ProtectHook((PDWORD)(g_pDevice[2] - 5), (PDWORD)(g_pDevice[5] - 5)); 
Sleep(1); 
ProtectHook((PDWORD)(g_pDevice[3] - 5), (PDWORD)(g_pDevice[6] - 5)); 
Sleep(1); 
ProtectHook((PDWORD)(g_pDevice[4] - 5), (PDWORD)hkEndScene); 
Sleep(1); 
//ProtectHook((PDWORD)(g_pDevice[5] - 5), (PDWORD)hkDrawIndexedPrimitive); 
Sleep(1); 
ProtectHook((PDWORD)(g_pDevice[6] - 5), (PDWORD)myReset);
while(1){ 
g_pDevice[42] = (DWORD)g_pDevice[1] - 5; 
//g_pDevice[82] = (DWORD)g_pDevice[2] - 5; 
g_pDevice[16] = (DWORD)g_pDevice[3] - 5;
Sleep(500); 
} 
} return 0; 
}



//====================================================================================
BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
if (dwReason == DLL_PROCESS_ATTACH){
DisableThreadLibraryCalls(hDll);
//GetModuleFileName(hDll, dlldir, 512);
//for(int i = strlen(dlldir); i > 0; i--) { if(dlldir[i] == '\\') { dlldir[i+1] = 0; break;}}
//infile.open(GetDirectoryFile("Logger.txt"), ios::out);//ini buat tes logger kita (yg di hide smua)
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwBaseAddress + 0x2), &ResultBaseAddress, sizeof(ResultBaseAddress), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwBullet + 0xC ), &ResultBullet, sizeof(ResultBaseBullet), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwSkill + 0x4), &OFSSkill, sizeof(OFSSkill), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwKill + 0x3), &ResultKill, sizeof(ResultKill), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwPing + 0x2), &ResultPing, sizeof(ResultPing), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwScore + 0x3), &ResultScore, sizeof(ResultScore), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwQuick + 0x2), &ResultQuick, sizeof(ResultQuick), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwHook + 0x2), &ResultHook, sizeof(ResultHook), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwUser+0x2), &ResultUserDeath, sizeof(ResultUserDeath), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwTeam+0xC), &ResultTeam, sizeof(ResultTeam), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwPTRpTarget2+0xE), &ResultPTRTarget, sizeof(ResultPTRTarget), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwPlayer+0xC)	,&ResultPlayer,sizeof(ResultPlayer)		,NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwName+0xC),&ResultName,sizeof(ResultName)		,NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwGhost+0x9),&ResultGHOST	,sizeof(ResultGHOST)		,NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwGetButton+0x12), &ResultGetButton, sizeof(ResultGetButton), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwPrimary + 0x2), &OFSReplace, sizeof(OFSReplace), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwPTRIdle+0x18), &ResultPTRIdle, sizeof(ResultPTRIdle), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwPTRCaclAmmo+0xF), &ResultPTRCaclAmmo, sizeof(ResultPTRCaclAmmo), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwAmmo1+0x11),&ResultPTRAmmoA, sizeof(ResultPTRAmmoA), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwAmmo2+0x11),&ResultPTRAmmoB, sizeof(ResultPTRAmmoB), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (DwAmmo2+0x11),&ResultPTRAmmoC, sizeof(ResultPTRAmmoC), NULL);
ReadProcessMemory(GetCurrentProcess(), (LPCVOID) (dwPTRRecoil+0x2), &ResultPTR, sizeof(ResultPTR), NULL);

//--------------------------------------------------------------------
ResultBasePlayer      = ResultBaseAddress - dwPBExe;
ResultBasePlayer2     = ResultBaseAddress;
ResultBaseHealth      = ResultBaseAddress - dwPBExe - 0x34;
ResultBaseHealth2     = ResultBaseAddress - 0x34;
ResultBaseAmmo        = ResultBaseAddress - dwPBExe - 0x38;
ResultBaseAmmo2       = ResultBaseAddress - 0x38;
ResultUserDeath       = ResultUserDeath;
ResultSetEvent			= DwSetEvent - 0x16;
ResultBaseBullet      = ResultBullet -dwPBExe;
ResultPTRCaclKnife	    = ResultPTRCaclAmmo -0x10;
ResultPTRAmmo         = ResultQuick + 0x4;
ResultNorecoil        = ResultQuick + 0x18;
PTR_Target            = ResultQuick + 0x20;
ResultRespawn2        = ResultTeam - 0x19B0;
ResultSkill2          = OFSSkill;
ResultSkill           = ResultSkill2 - 0x1;//
PTR_Idle		      = ResultPTRIdle - 0x1;
PTR_Idle2		      = ResultPTRIdle + 0x4;
ResultRespawn         = ResultSkill2 + 0x1;
ResultPrimary         = OFSReplace + 0x5A0;
ResultMelee           = ResultPrimary + 0x8;
ResultRafid           = ResultNorecoil - 0x7C;
ResultRafid2          = ResultNorecoil - 0x54;
ResultSecondary           = ResultPrimary + 0x4;
ResultSmoke           = ResultPrimary + 0x10;
ResultInvincible      = dwInvincible - dwPBExe;
ResultWallShot        = dwWallShot - dwPBExe;
ResultSuicide         = dwSuicide - dwPBExe;
ResultSetNetChara      = FakeReplac;
ResultGHOST            = 0x260;//ResultGHOST;
ResultHealth           = 0x264;
ResultBugWeapon       = dwUnyuk - dwPBExe;
ResultDoLine           = DwDoLine;
ResultCamPos           = DwCamPos;
ResultEventFire        = DwEventFire;
HookBaseRender        = HookBaseRender;
ResultHook            = ResultHook;
WTF                   = dwWTF - dwNxChara - 0x1000;
ResultBOMBSIZE			= 0x28;
PTRAmmoA				= ResultPTRAmmoA;
PTRAmmoB				= ResultPTRAmmoB;
PTRAmmoC				= ResultPTRAmmoC - 0x4;
PTRAmmoD				= ResultPTRAmmoC;
PTRProtectA			= PTRAmmoC + 0x8;
PTRProtectB			= PTRAmmoC + 0x10;
PTRProtectC			= PTRAmmoC + 0x24;
PTRProtectD			= PTRAmmoC + 0x68;
ResultPlayerSpeed		= DwPlayerSpeed - dwPBExe;
ResultBugHover1			= BugHover1	- dwNxChara;
ResultBugHover2			= BugHover2 - dwNxChara;
PlantRID1         = FastPlantRID1;
PlantRID2         = FastPlantRID2;
PTR_NoRecoil			=ResultPTR;
PTR_BaseAmmo			=ResultPTR - 0x14;
RETNeoDamage		  = i3Damage + 0x6;
ResultRANKSIZE			= 0x2B;
ResultNAMESIZE			= 0x21;
ResultQuickconge			= i3QuickChange+0x5A; 
Resultpesoedan			= ResultDoLine + 0x6B5D;

/*
Writelog("#define ResultDoLine			0x%X", ResultDoLine);
Writelog("#define ResultCamPos			0x%X", ResultCamPos);
Writelog("#define ResultEventFire			0x%X", ResultEventFire);
Writelog("#define ResultPTR			0x%X", ResultPTR);
Writelog("#define ResultRafid			0x%X", ResultRafid);
Writelog("#define ResultRafid2			0x%X", ResultRafid2);
ExitProcess(0);*/

Beep(500, 500);
CT(Hooked,0);
CT(RCHHack,0);
//CT(granat,0);

}
return TRUE;
}