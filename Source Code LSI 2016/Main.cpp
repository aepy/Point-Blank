#include <windows.h>
#include "Hack.h"
bool Hiting = false;
extern void Main(void);
#define CT(th,pr) CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(th), (LPVOID)pr, NULL, NULL)




::BOOL WINAPI DllWork(__in::HMODULE hModule)
{
	CT(FUCK, 0);	
	CT(FUCK_, 0);
	Main();
	return true;
}


BOOL WINAPI DllMain(HMODULE hDll, ULONG ulReason, LPVOID lpReserved)
{
	switch (ulReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hDll);
		MessageBoxA(0 ,"Created By : Fahmi Andrian","Information!",MB_OK );
	//	MessageBoxB(0 ,"Created By : Fahmi Andrian","Information!",MB_OK );
		CT(DllWork, 0);
		break;
	}
	return TRUE;
}