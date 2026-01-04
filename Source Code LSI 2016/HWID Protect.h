/*
#include <windows.h>


UCHAR
szFileSys[255],
szVolNameBuff[255];

DWORD
dwMFL,
dwSysFlags,
dwSerial;

#define My_HWID (-000)
#define My_HWID (-000)
#define My_HWID (-000)
#define My_HWID (-000)
#define My_HWID (-000)
#define My_HWID (-000)
#define My_HWID (-000)
#define My_HWID (-000)
#define My_HWID (-000)
#define My_HWID (-000)

VOID CheckValidHardwareID()
{
GetVolumeInformation("C:\\",(LPTSTR)szVolNameBuff,255,&dwSerial, &dwMFL,&dwSysFlags,(LPTSTR)szFileSys,255);
if (dwSerial == My_HWID)
{
MessageBox(0,"HWID Tidak Terdaftar","Information",MB_OK | MB_ICONINFORMATION);
}
else 
{
MessageBox(0,"HWID Tidak Terdaftar","Information",MB_OK | MB_ICONERROR);
ExitProcess(1);

}

}
BOOL WINAPI DllMain ( HMODULE hDll, DWORD dwReason, LPVOID lpReserved )
{
if (dwReason == DLL_PROCESS_ATTACH)
{
DisableThreadLibraryCalls(hDll);
CheckValidHardwareID();
}
return TRUE;
}*/