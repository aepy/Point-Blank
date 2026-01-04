#include <windows.h>
#include "wininet.h"
#pragma comment(lib, "wininet.lib")
UCHAR szFileSys[255],szVolNameBuff[255];
DWORD dwMFL, dwSysFlags, dwSerial;

#define My_HWID (00000000) // ganti sama id PC mu   , NB : gunakan  software GetHardwareIdentifier untuk mengetahui no ID pc mu

void ProtectHwidPC()// protect hwid PC
{
GetVolumeInformation("C:\\",(LPTSTR)szVolNameBuff,255,&dwSerial, &dwMFL,&dwSysFlags,(LPTSTR)szFileSys,255);
if (dwSerial == My_HWID||dwSerial == My_HWID)
{}else{
Beep(1000, 500);
Sleep(250);
Beep(1000, 750);
Sleep(250);
Beep(1000, 1000);
MessageBox(0,"Maaf HWID Tidak Cocok !\nSilahkan Tanyakan Pada Admin Jika Ini Sebuah Kesalahan","Invalid HWID",MB_OK );
ExitProcess(1); // Force Exit
} 
}
int ThreadTrial(char *url){
char output[16];
HINTERNET hInternet;HINTERNET hFile;DWORD ReadSize; BOOL bResult;
hInternet = InternetOpen("Some USER-AGENT",INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,NULL);
hFile = InternetOpenUrl(hInternet,url,NULL,NULL,INTERNET_FLAG_RELOAD,NULL);
ReadSize = 15;Sleep(500);bResult = InternetReadFile(hFile,output,15,&ReadSize);output[ReadSize]='\0';
if(strcmp("ACTIVE",output)==0){
GetCurrentProcess();
}else{
Beep(1000, 500);
Sleep(250);
Beep(1000, 750);
Sleep(250);
Beep(1000, 1000);
MessageBox(0,"Maaf Trial Habis !\nSilahkan Tanyakan Pada Admin Jika Ingin Tambah Trial ","Trial Telah Habis!",MB_OK );
system("start https://www.facebook.com/aimar.dhity"); // silakan di ganti
Sleep(1000);
ExitProcess(0);
}
return 0;
}
void __stdcall TrialStarter(){
ThreadTrial("https://sites.google.com/site/cyber3volution/Trial.txt");
}