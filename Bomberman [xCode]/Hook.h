
DWORD WINAPI NFCZHooked(LPVOID Param){

if (hGfxDx > 0){ 
DWORD tmp1 = (DWORD)GetModuleHandle("i3GfxDx.dll") + ResultBaseRender; 
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
while(!pDevice)pDevice = (LPDIRECT3DDEVICE9)(DWORD*)g_pDevice; 
*(PDWORD)&oEndScene = g_pDevice[42]; 
*(PDWORD)&oDrawIndexedPrimitive = g_pDevice[82]; 
Sleep(1); 
UknownScript((PDWORD)(g_pDevice[1] - 5), (PDWORD)(g_pDevice[4] - 5)); 
Sleep(1); 
UknownScript((PDWORD)(g_pDevice[2] - 5), (PDWORD)(g_pDevice[5] - 5)); 
Sleep(1); UknownScript((PDWORD)(g_pDevice[3] - 5), (PDWORD)(g_pDevice[6] - 5)); 
Sleep(1); UknownScript((PDWORD)(g_pDevice[4] - 5), (PDWORD)hkEndScene); Sleep(1); 
UknownScript((PDWORD)(g_pDevice[5] - 5), (PDWORD)hkDrawIndexedPrimitive); 
Sleep(1); 
while(1){ 
g_pDevice[42] = (DWORD)g_pDevice[1] - 5; 
g_pDevice[82] = (DWORD)g_pDevice[2] - 5; 
Sleep(1000); 
} 
} return 0; 
}