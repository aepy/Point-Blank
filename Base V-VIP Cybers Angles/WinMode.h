
bool winmode= false;
int ok;

void _patchPTRW(unsigned long ulBase, int iOffset, int iValue)
{
if (!IsBadReadPtr((VOID*)ulBase, sizeof(unsigned long)))
{
if (!IsBadWritePtr((void*)(*(unsigned long*)ulBase + iOffset), sizeof(unsigned long)))
{
*(int*)(*(unsigned long*)ulBase + iOffset) = iValue;
}
}
}

int __stdcall WINYONGKIEMODE(BYTE a1, BYTE a2, BYTE a3)
{
  return 1;
}

VOID YONGKIEALX(BYTE *dwIATAddress, DWORD FunctionTarget) { 
DWORD dwOld;
VirtualProtect( (LPVOID)dwIATAddress, 4, PAGE_EXECUTE_READWRITE, &dwOld );
*((DWORD *)(dwIATAddress)) = FunctionTarget; 
VirtualProtect( (LPVOID)dwIATAddress, 4, dwOld, &dwOld );
}
void WinModefunctiont()
{
if ( winmode==false )
  {
	YONGKIEALX((PBYTE)resultwinmodefunct,(DWORD)WINYONGKIEMODE); 
    winmode = true;
  }
}
void __cdecl WinMode()
{
LPTSTR I3Viewer = "I3VIEWER";
LPTSTR PBWindow = "POINT BLANK";
LPTSTR judul="ZeRo-CyBeRz™ VIP | http://zero-cyberz-vip.com/";
	ok=1;
  while (1)
  {
  HWND hPB = FindWindowA(I3Viewer,PBWindow);
  SetWindowTextA(hPB, judul);	
    if (ok)
    {
      _patchPTRW(resultbasewinmode, 24, 0);
      _patchPTRW(resultbasewinmode, 28, 1024);
      _patchPTRW(resultbasewinmode, 32, 700);
    }
    Sleep(0);
  }
}

void CallWinMode()
{
	if(MessageBoxA(NULL, "Apakah Anda Akan Mengaktifkan Window Mode ?", "Konfirmasi", MB_YESNO) == IDYES)
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)WinMode, NULL, NULL, NULL);
}