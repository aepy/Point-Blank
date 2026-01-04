/*hModule D3D9 PBHacks Last Edit By ZrC-CyB Hacks*/
#include <windows.h>

LPTSTR PBExe = "PointBlank.exe";
LPTSTR PBi3Gfx = "i3GfxDx.dll";
HMODULE hGfxDx = LoadLibrary("i3GfxDx.dll");
LPTSTR PBi3Ipt = "i3InputDx.dll";
LPTSTR PBi3Scn = "i3SceneDx.dll";
DWORD    NxCha = (DWORD)GetModuleHandleA("NxCharacter.2.8.1.dll");