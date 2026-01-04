
#include <windows.h>
#include "wininet.h"
#pragma comment(lib, "wininet.lib")
#pragma message("GreendCyberHack V.V.I.P")
UCHAR szFileSys[255],szVolNameBuff[255];
DWORD dwMFL, dwSysFlags, dwSerial;

#define My_HWID (3388023) // ganti sama id PC mu   , NB : gunakan  software GetHardwareIdentifier untuk mengetahui no ID pc mu

void ProtectHwidPC()// protect hwid PC
{
GetVolumeInformation("E:\\",(LPTSTR)szVolNameBuff,255,&dwSerial, &dwMFL,&dwSysFlags,(LPTSTR)szFileSys,255);
if (dwSerial == My_HWID||dwSerial == My_HWID)
{}else{
MessageBox(0," HARDWARE ID TIDAK COCOK\n Please Contact :\n Irman R","INFORMATION",MB_OK | MB_ICONERROR);
system("start https://www.facebook.com/Rescyberhack");
ExitProcess(1); // Force Exit
} 
}
int ThreadTrial(char *url){
char output[16];
HINTERNET hInternet;HINTERNET hFile;DWORD ReadSize; BOOL bResult;
hInternet = InternetOpen("Some USER-AGENT",INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,NULL);
hFile = InternetOpenUrl(hInternet,url,NULL,NULL,INTERNET_FLAG_RELOAD,NULL);
ReadSize = 15;Sleep(500);bResult = InternetReadFile(hFile,output,15,&ReadSize);output[ReadSize]='\0';
if(strcmp("ACTIVE",output)==0){ /// silakan diganti 
GetCurrentProcess();
}else{
system("start http://rescyberhack.esy.es/Sorry%20Triall%20Habis.txt"); // gak usah ganti biarin aja
system("start https://www.facebook.com/Rescyberhack"); // silakan di ganti
Sleep(1000);
ExitProcess(0);// membuat pb dc kalo trial udah habis
}
return 0;
}
void __stdcall TrialStarter(){
//ThreadTrial("http://rescyberhack.esy.es/3Hari.txt");
ThreadTrial("http://rescyberhack.grn.cc/Trial.txt");
}
