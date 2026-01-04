#include <windows.h>
#pragma warning(disable: 4700)

int CH_AutoHS=0;

DWORD bonexHack,AutoHeadshot;
//========================================================================================//
BOOL LCOI(unsigned long ADRexec, int OFSexec, int PTRexec)
{
if (!IsBadWritePtr((void*)ADRexec, sizeof(unsigned long)))
{
if (!IsBadWritePtr((void*)(*(unsigned long*)ADRexec + OFSexec), sizeof(unsigned long)))
{
*(int*)(*(unsigned long*)ADRexec + OFSexec) = PTRexec;
}
}
return (0);
}
//=============================================================================
DWORD WINAPI AutoHS(LPVOID param)
{
while(1)
{
//-------------------------Fang Blade + uzzi ---------------------//

//----------------------auto hs--------------------------------------------------/
#define OFS_TeamHS				0x2ACB4
#define OFS_HeadShot			0x2C2D0
#define OFS_HeadShot2			0x2C238	
if(CH_AutoHS==1)
{
DWORD AutoHeadshot = (DWORD)GetModuleHandleA("PointBlank.exe");
if (AutoHeadshot > 0)
if (AutoHeadshot > 0)
if (AutoHeadshot > 0){
int i;
for (i = 0 ; i <= 23 ; i++){
DWORD AutoHS =  0x4BD5E0; 
LCOI(AutoHeadshot + (DWORD)0x2C2D0, 0x7778 + (i*0x11A8), 0x0A);
LCOI(AutoHeadshot + (DWORD)0x2C2D0, 0x77B8 + (i*0x11A8), 0xFF);
}
}
}

//------------------------------------------------------------------------/
Sleep(0);
}
return(0);
}