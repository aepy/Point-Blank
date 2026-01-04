#include <windows.h>
#include <wininet.h>
#include "-Hwid.h"
#include <sstream>
#include <stdexcept>
#include <string>
#pragma warning(disable:4145 4700 4101)
using namespace std;
//============================================GET-HWID===================================================================
inline std::string trim_right(const std::string &source , const std::string& t = " ")
{
	std::string str = source;
	return str.erase( str.find_last_not_of(t) + 1);
}

inline std::string trim_left( const std::string& source, const std::string& t = " ")
{
	std::string str = source;
	return str.erase(0 , source.find_first_not_of(t) );
}

inline std::string trim(const std::string& source, const std::string& t = " ")
{
	std::string str = source;
	return trim_left( trim_right( str , t) , t );
} 

void trim2(string& str)
{
string::size_type pos = str.find_last_not_of(' ');
if(pos != string::npos) {
str.erase(pos + 1);
pos = str.find_first_not_of(' ');
if(pos != string::npos) str.erase(0, pos);
}
else str.erase(str.begin(), str.end());
}


#include "-ManualHwid.h"

void CeksecuritiedHWID(void) {// iki manual
	// deklarasi DiskInfo, parameter 0, adalah HDD 1
	DiskInfo *di;
	di = new DiskInfo(0);
	// ambil serial
	di->LoadDiskInfo();
/*
	// validasi make char*
	char* sn = di->SerialNumber();
	MessageBox(0, sn, "SERIAL", MB_OK | MB_ICONINFORMATION);
	// validasi hwid pake strcmp, cek kalo hwid = 5WS2B681
	if (strcmp(sn, "5WS2B681")==0) {
		MessageBox(0, "OK. Anda bukan PKL", "Cek HWID 1", MB_OK | MB_ICONINFORMATION);
	} else {
		MessageBox(0, "WOW. Anda PKL ya?", "Cek HWID 1", MB_OK | MB_ICONERROR);
	}
*/
	// validasi make std::string
	string strSerial1 = di->SerialNumber();
	string strSerial2 = trim(strSerial1);
//	char s[190];
//	sprintf(s, serialc, strSerial1.c_str(), strSerial2.c_str());//6RY4RF9B
//	sprintf(s, XStr( /*SERIAL ASLI: [%s]\nSERIAL TRIM: [%s]*/ 0x09, 0x24, 0x8C, 0xDFC8DCC6, 0xD1DDB2D2, 0xC7D9DFAD, 0xB8C2BFE8, 0xC1C1F0CC, 0xE5F3EBE2, 0xE885F2F5, 0xE1E4908B, 0xF788DDF2 ).c(), strSerial1.c_str(), strSerial2.c_str());//6RY4RF9B

	//-----------------------------wew------------------//
	if (strcmp(strSerial2.c_str(), "WD-WNBP95859601")==0//
	||strcmp(strSerial2.c_str(), "WD-WXEY08LRE084")==0
	||strcmp(strSerial2.c_str(), "WD-WMAV2DS25398")==0
	//-------------------------------------------------//
	){
	}else{
	ExitProcess (0);
	ExitProcess (1);
	}
}