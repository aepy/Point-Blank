//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
#include <TlHelp32.h>
PTSTR PointBlankNtDll = "ntdll.dll";
//===========================================================================================================
typedef enum __THREAD_INFORMATION_CLASS { 
    ThreadBasicInformation, 
    ThreadTimes, 
    ThreadPriority, 
    ThreadBasePriority, 
    ThreadAffinityMask, 
    ThreadImpersonationToken, 
    ThreadDescriptorTableEntry, 
    ThreadEnableAlignmentFaultFixup, 
    ThreadEventPair, 
    ThreadQuerySetWin32StartAddress, 
    ThreadZeroTlsCell, 
    ThreadPerformanceCount, 
    ThreadAmILastThread, 
    ThreadIdealProcessor, 
    ThreadPriorityBoost, 
    ThreadSetTlsArrayAddress, 
    ThreadIsIoPending, 
    ThreadHideFromDebugger 
} __THREAD_INFORMATION_CLASS, *PTHREAD_INFORMATION_CLASS; 
//===========================================================================================================
typedef DWORD(NTAPI *_ZwQueryInformationThread)(HANDLE ThreadHandle, __THREAD_INFORMATION_CLASS ThreadInformationClass, PVOID ThreadInformation, ULONG ThreadInformationLength, PULONG ReturnLength);  
//===========================================================================================================
DWORD GetEntryPoint(DWORD TID)
{
	_ZwQueryInformationThread ZwQueryInformationThread = (_ZwQueryInformationThread)GetProcAddress(GetModuleHandleA(PointBlankNtDll), "ZwQueryInformationThread"); 
	HANDLE hThread = OpenThread(THREAD_QUERY_INFORMATION, false, TID);
	DWORD Start;
	ZwQueryInformationThread(hThread, ThreadQuerySetWin32StartAddress, &Start, sizeof(Start), NULL); 
	CloseHandle(hThread);
	return Start;
}

HANDLE THandleFromEP()
{
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, GetCurrentThreadId());
	if (hSnap == INVALID_HANDLE_VALUE)
		return INVALID_HANDLE_VALUE;
	THREADENTRY32 TE = {0};
	TE.dwSize = sizeof(TE);
	Thread32First(hSnap, &TE);
	while (Thread32Next(hSnap, &TE))
	{
		if (GetEntryPoint(TE.th32ThreadID) == resultTHandleFromEP1)
			return OpenThread(THREAD_SET_CONTEXT, false, TE.th32ThreadID);
	}
	return INVALID_HANDLE_VALUE;
}