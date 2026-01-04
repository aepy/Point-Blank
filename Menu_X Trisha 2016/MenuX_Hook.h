#include <windows.h>
//--------------------------------define HOOK & UNHOOK--------------------------------------------------------------------------------------------------




void UknownScript(PDWORD target, PDWORD newfunc){
DWORD Jmpto=(DWORD)(newfunc)-(DWORD)target-5;
DWORD a;
VirtualProtect(target, 8, PAGE_EXECUTE_READWRITE, &a);
*(PBYTE)(target)=0xE9;
*(PDWORD)((DWORD)(target)+1)=Jmpto;
VirtualProtect(target, 8, a, &a);

}
int _stdcall Call_Theard_New(void)
{
DWORD ByPass = (DWORD)LoadLibraryA("i3BaseDx_Cli.dll");
PrivateOnly((void *)(ByPass+0xEFF2),(void*)(PBYTE)"\xEB",1);
PrivateOnly((void *)(ByPass+0xF01A),(void*)(PBYTE)"\xEB",1);
PrivateOnly((void *)(ByPass+0xF025),(void*)(PBYTE)"\xEB",1);
PrivateOnly((void *)(ByPass+0xF115),(void*)(PBYTE)"\xEB",1);
return 0;
	}
DWORD WINAPI MenuX_Hooking(LPVOID Param){

if (hGfxDx > 0){ 
DWORD tmp1 = (DWORD)GetModuleHandle("i3GfxDx.dll") + HookBaseRender; 
DWORD tmp2 = 0; 
Sleep(1); 
while(!i3Device){ 
if(IsBadReadPtr((PDWORD)tmp1,4)==NULL)tmp2 = *(PDWORD)((DWORD)(tmp1))+ 0x5368; Sleep(1); 
if(IsBadReadPtr((PDWORD)tmp2,4)==NULL){ Sleep(1); 
DWORD OldProtect; 
VirtualProtect((void*)(tmp2), 4, PAGE_EXECUTE_READWRITE, &OldProtect); 
memcpy(&i3Device, (void *)tmp2, 4); 
VirtualProtect((void*)(tmp2), 4, OldProtect, NULL); 
} 
} 
Sleep(1); 
DWORD *g_pDevice = (DWORD*)i3Device; 
g_pDevice = (DWORD*)g_pDevice[0]; 
while(!pDevice)pDevice = (LPDIRECT3DDEVICE9)(DWORD*)g_pDevice; 
*(PDWORD)&oEndScene = g_pDevice[42]; 
*(PDWORD)&oDrawIndexedPrimitive = g_pDevice[82]; 
Sleep(1); 
UknownScript((PDWORD)(g_pDevice[1] - 5), (PDWORD)(g_pDevice[4] - 5)); 
Sleep(1); 
UknownScript((PDWORD)(g_pDevice[2] - 5), (PDWORD)(g_pDevice[5] - 5)); 
Sleep(1); UknownScript((PDWORD)(g_pDevice[3] - 5), (PDWORD)(g_pDevice[6] - 5)); 
Sleep(1); UknownScript((PDWORD)(g_pDevice[4] - 5), (PDWORD)pGEndScene); Sleep(1); 
UknownScript((PDWORD)(g_pDevice[5] - 5), (PDWORD)pGDrawIndexedPrimitive); 
Sleep(1); 
while(1){ 
g_pDevice[42] = (DWORD)g_pDevice[1] - 5; 
g_pDevice[82] = (DWORD)g_pDevice[2] - 5; 
Sleep(1000); 
} 
} return 0; 
}
