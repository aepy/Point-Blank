/*------------------------------------------- Declaration DrawReset ------------------------------------------------------*/
HRESULT WINAPI hkReset(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    if( g_pFont )	g_pFont->OnLostDevice();
	if( pFont	) 	pFont->OnLostDevice();
    if( pLine	)		pLine->OnLostDevice();
    if(oReset == D3D_OK)  {
	if( g_pFont )   g_pFont->OnResetDevice();
	if( pFont	) 	pFont->OnResetDevice();
    if( pLine	)		pLine->OnResetDevice();
	}
    return oReset(pDevice, pPresentationParameters);
}
/*------------------------------------------- Declaration HookEngine ------------------------------------------------------*/
DWORD WINAPI HookEngine(){
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
				VirtualProtect((void*)(tmp2), 4, OldProtect, NULL);}}
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
		for(;;) {
			g_pDevice[42] = (DWORD)g_pDevice[1] - 5;
			g_pDevice[82] = (DWORD)g_pDevice[2] - 5;
			g_pDevice[16] = (DWORD)g_pDevice[3] - 5;
		}
		Sleep(100); 
	}
	return (0);
}