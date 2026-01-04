#include "wininet.h"
#include "XStr.h"
#pragma comment(lib, "wininet.lib")
/******************* HWID ********************/
UCHAR
szFileSys[255],
szVolNameBuff[255];

DWORD dwMFL, dwSysFlags, dwSerial,dwSerial1,dwSerial2,dwSerial3,dwSerial4,dwSerial5,dwSerial6,dwSerial7,
dwSerial8,dwSerial9;
/*********************************************** HWID FD + PC ************************************************/
#define HWIDFD  (-222997411)// Febri angga 1 minggu abis tanggal 15 november
#define HWIDFD1 (-1225005243)// RESELLER HMR HOURCE
#define HWIDFD2 (-355669203)//1 Minggu Amar Satrya 9 november abis tanggal 16 november
#define HWIDFD3 (348969981) // punya Yuda ( laptop )
#define HWIDFD4 (2129222648) // Anes 30 oktober 2014 1 bulan
#define HWIDFD5 (-1808392169) // Punya Laptop Gua Mas wira
#define HWIDFD6 (1622943846) // RESELLER ZerOne
#define HWIDFD7 (1682092765) // HERU
#define HWIDFD8 (123456) // KOSONG
#define HWIDFD9 (1961654075)
#define HWIDFD10 (-1534130115)
#define HWIDFD11 (2121980623)
#define HWIDFD12 (678315918)
#define HWIDFD13 (877279965)
#define HWIDFD14 (275091050)
#define HWIDFD15 (-1875764480)
#define HWIDFD16 (720242688)
#define HWIDFD17 (-253646066)
#define HWIDFD18 (-1675743646)
#define HWIDFD19 (-1472641792)
#define HWIDFD20 (-1472641792)
#define HWIDFD21 (-1472641792)
#define HWIDFD22 (-1472641792)
#define HWIDFD23 (-1472641792)
#define HWIDFD24 (-1472641792)
#define HWIDFD25 (-1472641792)
#define HWIDFD26 (-1472641792)
#define HWIDFD27 (-1472641792)
#define HWIDFD28 (-1472641792)
#define HWIDFD29 (-1472641792)
#define HWIDFD30 (-1472641792)
void SerialCheck()
{
GetVolumeInformation("C:\\",(LPTSTR)szVolNameBuff,255,&dwSerial , &dwMFL,&dwSysFlags,(LPTSTR)szFileSys,255);
	GetVolumeInformation("D:\\",(LPTSTR)szVolNameBuff,255,&dwSerial9, &dwMFL,&dwSysFlags,(LPTSTR)szFileSys,255);
	GetVolumeInformation("E:\\",(LPTSTR)szVolNameBuff,255,&dwSerial1, &dwMFL,&dwSysFlags,(LPTSTR)szFileSys,255);
	GetVolumeInformation("F:\\",(LPTSTR)szVolNameBuff,255,&dwSerial2, &dwMFL,&dwSysFlags,(LPTSTR)szFileSys,255);
	GetVolumeInformation("G:\\",(LPTSTR)szVolNameBuff,255,&dwSerial3, &dwMFL,&dwSysFlags,(LPTSTR)szFileSys,255);
	GetVolumeInformation("H:\\",(LPTSTR)szVolNameBuff,255,&dwSerial4, &dwMFL,&dwSysFlags,(LPTSTR)szFileSys,255);
	GetVolumeInformation("I:\\",(LPTSTR)szVolNameBuff,255,&dwSerial5, &dwMFL,&dwSysFlags,(LPTSTR)szFileSys,255);
	GetVolumeInformation("J:\\",(LPTSTR)szVolNameBuff,255,&dwSerial6, &dwMFL,&dwSysFlags,(LPTSTR)szFileSys,255);
	GetVolumeInformation("K:\\",(LPTSTR)szVolNameBuff,255,&dwSerial7, &dwMFL,&dwSysFlags,(LPTSTR)szFileSys,255);
	GetVolumeInformation("L:\\",(LPTSTR)szVolNameBuff,255,&dwSerial8, &dwMFL,&dwSysFlags,(LPTSTR)szFileSys,255);
/*********************************************** ========= ********************************************************/	
	 if (dwSerial == HWIDFD||dwSerial == HWIDFD1||dwSerial == HWIDFD2||dwSerial == HWIDFD3||dwSerial == HWIDFD4||dwSerial == HWIDFD5||dwSerial == HWIDFD6||dwSerial == HWIDFD7||dwSerial == HWIDFD8||dwSerial == HWIDFD9||dwSerial == HWIDFD10||dwSerial == HWIDFD11||dwSerial == HWIDFD12||dwSerial == HWIDFD13||dwSerial == HWIDFD14||dwSerial == HWIDFD15||dwSerial == HWIDFD16||dwSerial == HWIDFD17||dwSerial == HWIDFD18||dwSerial == HWIDFD19||dwSerial == HWIDFD20||dwSerial == HWIDFD21||dwSerial == HWIDFD22||dwSerial == HWIDFD23||dwSerial == HWIDFD24||dwSerial == HWIDFD25||dwSerial == HWIDFD26||dwSerial == HWIDFD27||dwSerial == HWIDFD28||dwSerial == HWIDFD29||dwSerial == HWIDFD30){}
else if (dwSerial1== HWIDFD||dwSerial1== HWIDFD1||dwSerial1== HWIDFD2||dwSerial1== HWIDFD3||dwSerial1== HWIDFD4||dwSerial1== HWIDFD5||dwSerial1== HWIDFD6||dwSerial1== HWIDFD7||dwSerial1== HWIDFD8||dwSerial1== HWIDFD9||dwSerial1== HWIDFD10||dwSerial1== HWIDFD11||dwSerial1== HWIDFD12||dwSerial1== HWIDFD13||dwSerial1== HWIDFD14||dwSerial1== HWIDFD15||dwSerial1== HWIDFD16||dwSerial1== HWIDFD17||dwSerial1== HWIDFD18||dwSerial1== HWIDFD19||dwSerial1== HWIDFD20||dwSerial1== HWIDFD21||dwSerial1== HWIDFD22||dwSerial1== HWIDFD23||dwSerial1== HWIDFD24||dwSerial1== HWIDFD25||dwSerial1== HWIDFD26||dwSerial1== HWIDFD27||dwSerial1== HWIDFD28||dwSerial1== HWIDFD29||dwSerial1== HWIDFD30){}
else if (dwSerial2== HWIDFD||dwSerial2== HWIDFD1||dwSerial2== HWIDFD2||dwSerial2== HWIDFD3||dwSerial2== HWIDFD4||dwSerial2== HWIDFD5||dwSerial2== HWIDFD6||dwSerial2== HWIDFD7||dwSerial2== HWIDFD8||dwSerial2== HWIDFD9||dwSerial2== HWIDFD10||dwSerial2== HWIDFD11||dwSerial2== HWIDFD12||dwSerial2== HWIDFD13||dwSerial2== HWIDFD14||dwSerial2== HWIDFD15||dwSerial2== HWIDFD16||dwSerial2== HWIDFD17||dwSerial2== HWIDFD18||dwSerial2== HWIDFD19||dwSerial2== HWIDFD20||dwSerial2== HWIDFD21||dwSerial2== HWIDFD22||dwSerial2== HWIDFD23||dwSerial2== HWIDFD24||dwSerial2== HWIDFD25||dwSerial2== HWIDFD26||dwSerial2== HWIDFD27||dwSerial2== HWIDFD28||dwSerial2== HWIDFD29||dwSerial2== HWIDFD30){}
else if (dwSerial3== HWIDFD||dwSerial3== HWIDFD1||dwSerial3== HWIDFD2||dwSerial3== HWIDFD3||dwSerial3== HWIDFD4||dwSerial3== HWIDFD5||dwSerial3== HWIDFD6||dwSerial3== HWIDFD7||dwSerial3== HWIDFD8||dwSerial3== HWIDFD9||dwSerial3== HWIDFD10||dwSerial3== HWIDFD11||dwSerial3== HWIDFD12||dwSerial3== HWIDFD13||dwSerial3== HWIDFD14||dwSerial3== HWIDFD15||dwSerial3== HWIDFD16||dwSerial3== HWIDFD17||dwSerial3== HWIDFD18||dwSerial3== HWIDFD19||dwSerial3== HWIDFD20||dwSerial3== HWIDFD21||dwSerial3== HWIDFD22||dwSerial3== HWIDFD23||dwSerial3== HWIDFD24||dwSerial3== HWIDFD25||dwSerial3== HWIDFD26||dwSerial3== HWIDFD27||dwSerial3== HWIDFD28||dwSerial3== HWIDFD29||dwSerial3== HWIDFD30){}
else if (dwSerial4== HWIDFD||dwSerial4== HWIDFD1||dwSerial4== HWIDFD2||dwSerial4== HWIDFD3||dwSerial4== HWIDFD4||dwSerial4== HWIDFD5||dwSerial4== HWIDFD6||dwSerial4== HWIDFD7||dwSerial4== HWIDFD8||dwSerial4== HWIDFD9||dwSerial4== HWIDFD10||dwSerial4== HWIDFD11||dwSerial4== HWIDFD12||dwSerial4== HWIDFD13||dwSerial4== HWIDFD14||dwSerial4== HWIDFD15||dwSerial4== HWIDFD16||dwSerial4== HWIDFD17||dwSerial4== HWIDFD18||dwSerial4== HWIDFD19||dwSerial4== HWIDFD20||dwSerial4== HWIDFD21||dwSerial4== HWIDFD22||dwSerial4== HWIDFD23||dwSerial4== HWIDFD24||dwSerial4== HWIDFD25||dwSerial4== HWIDFD26||dwSerial4== HWIDFD27||dwSerial4== HWIDFD28||dwSerial4== HWIDFD29||dwSerial4== HWIDFD30){}
else if (dwSerial5== HWIDFD||dwSerial5== HWIDFD1||dwSerial5== HWIDFD2||dwSerial5== HWIDFD3||dwSerial5== HWIDFD4||dwSerial5== HWIDFD5||dwSerial5== HWIDFD6||dwSerial5== HWIDFD7||dwSerial5== HWIDFD8||dwSerial5== HWIDFD9||dwSerial5== HWIDFD10||dwSerial5== HWIDFD11||dwSerial5== HWIDFD12||dwSerial5== HWIDFD13||dwSerial5== HWIDFD14||dwSerial5== HWIDFD15||dwSerial5== HWIDFD16||dwSerial5== HWIDFD17||dwSerial5== HWIDFD18||dwSerial5== HWIDFD19||dwSerial5== HWIDFD20||dwSerial5== HWIDFD21||dwSerial5== HWIDFD22||dwSerial5== HWIDFD23||dwSerial5== HWIDFD24||dwSerial5== HWIDFD25||dwSerial5== HWIDFD26||dwSerial5== HWIDFD27||dwSerial5== HWIDFD28||dwSerial5== HWIDFD29||dwSerial5== HWIDFD30){}
else if (dwSerial6== HWIDFD||dwSerial6== HWIDFD1||dwSerial6== HWIDFD2||dwSerial6== HWIDFD3||dwSerial6== HWIDFD4||dwSerial6== HWIDFD5||dwSerial6== HWIDFD6||dwSerial6== HWIDFD7||dwSerial6== HWIDFD8||dwSerial6== HWIDFD9||dwSerial6== HWIDFD10||dwSerial6== HWIDFD11||dwSerial6== HWIDFD12||dwSerial6== HWIDFD13||dwSerial6== HWIDFD14||dwSerial6== HWIDFD15||dwSerial6== HWIDFD16||dwSerial6== HWIDFD17||dwSerial6== HWIDFD18||dwSerial6== HWIDFD19||dwSerial6== HWIDFD20||dwSerial6== HWIDFD21||dwSerial6== HWIDFD22||dwSerial6== HWIDFD23||dwSerial6== HWIDFD24||dwSerial6== HWIDFD25||dwSerial6== HWIDFD26||dwSerial6== HWIDFD27||dwSerial6== HWIDFD28||dwSerial6== HWIDFD29||dwSerial6== HWIDFD30){}
else if (dwSerial7== HWIDFD||dwSerial7== HWIDFD1||dwSerial7== HWIDFD2||dwSerial7== HWIDFD3||dwSerial7== HWIDFD4||dwSerial7== HWIDFD5||dwSerial7== HWIDFD6||dwSerial7== HWIDFD7||dwSerial7== HWIDFD8||dwSerial7== HWIDFD9||dwSerial7== HWIDFD10||dwSerial7== HWIDFD11||dwSerial7== HWIDFD12||dwSerial7== HWIDFD13||dwSerial7== HWIDFD14||dwSerial7== HWIDFD15||dwSerial7== HWIDFD16||dwSerial7== HWIDFD17||dwSerial7== HWIDFD18||dwSerial7== HWIDFD19||dwSerial7== HWIDFD20||dwSerial7== HWIDFD21||dwSerial7== HWIDFD22||dwSerial7== HWIDFD23||dwSerial7== HWIDFD24||dwSerial7== HWIDFD25||dwSerial7== HWIDFD26||dwSerial7== HWIDFD27||dwSerial7== HWIDFD28||dwSerial7== HWIDFD29||dwSerial7== HWIDFD30){}
else if (dwSerial8== HWIDFD||dwSerial8== HWIDFD1||dwSerial8== HWIDFD2||dwSerial8== HWIDFD3||dwSerial8== HWIDFD4||dwSerial8== HWIDFD5||dwSerial8== HWIDFD6||dwSerial8== HWIDFD7||dwSerial8== HWIDFD8||dwSerial8== HWIDFD9||dwSerial8== HWIDFD10||dwSerial8== HWIDFD11||dwSerial8== HWIDFD12||dwSerial8== HWIDFD13||dwSerial8== HWIDFD14||dwSerial8== HWIDFD15||dwSerial8== HWIDFD16||dwSerial8== HWIDFD17||dwSerial8== HWIDFD18||dwSerial8== HWIDFD19||dwSerial8== HWIDFD20||dwSerial8== HWIDFD21||dwSerial8== HWIDFD22||dwSerial8== HWIDFD23||dwSerial8== HWIDFD24||dwSerial8== HWIDFD25||dwSerial8== HWIDFD26||dwSerial8== HWIDFD27||dwSerial8== HWIDFD28||dwSerial8== HWIDFD29||dwSerial8== HWIDFD30){}
else if (dwSerial9== HWIDFD||dwSerial9== HWIDFD1||dwSerial9== HWIDFD2||dwSerial9== HWIDFD3||dwSerial9== HWIDFD4||dwSerial9== HWIDFD5||dwSerial9== HWIDFD6||dwSerial9== HWIDFD7||dwSerial9== HWIDFD8||dwSerial9== HWIDFD9||dwSerial9== HWIDFD10||dwSerial8== HWIDFD11||dwSerial9== HWIDFD12||dwSerial9== HWIDFD13||dwSerial9== HWIDFD14||dwSerial9== HWIDFD15||dwSerial9== HWIDFD16||dwSerial9== HWIDFD17||dwSerial9== HWIDFD18||dwSerial9== HWIDFD19||dwSerial9== HWIDFD20||dwSerial9== HWIDFD21||dwSerial9== HWIDFD22||dwSerial9== HWIDFD23||dwSerial9== HWIDFD24||dwSerial9== HWIDFD25||dwSerial9== HWIDFD26||dwSerial9== HWIDFD27||dwSerial9== HWIDFD28||dwSerial9== HWIDFD29||dwSerial9== HWIDFD30){}
else{ExitProcess(1);}}

//====================HWID Member SAYA Hardware ID===================================================
#define PCNO1_HWID (711517922)//--------------HWid Pc No 1.
#define Begawan_HWID (-1666433192)// Azzuar Kristiady
#define GameMaster_HWID (2128549178)//------------>homo
//----------------------------------------------------------------//
// WARNET SAYA YANG DI JL.PAHLAWAN
#define My_HWID1 (203904286)// Room 1
#define My_HWID2 (1755203378)// Room 2
#define My_HWID3 (1150710216)// Room 3
#define My_HWID4 (545362747)// Room 4
#define My_HWID5 (210626359)
#define My_HWID6 (7541020)
#define My_HWID7 (618695839)
#define My_HWIDOP (-931398925)// operator


// Warnet Apong
#define Eno_Server (-97538506)
#define Eno_HWID1 (1278022072)
#define Eno_HWID2 (-326530643)
#define Eno_HWID3 (-319293860)
#define Eno_HWID4 (2019230663)
#define Eno_HWID5 (1078667287)
#define Eno_HWID6 (1352922994)
#define Eno_HWID7 (1818391557)
#define Eno_HWID8 (-1140172769)
#define Eno_HWID9 (615705693)
#define Eno_HWID10 (405037299)
#define Eno_HWID11 (-119536562)//*/

//Warnet Rizky
#define Dian_Operator (838111728)
#define Dian_HWID1 (-1681147984)
#define Dian_HWID2 (2122180384)
#define Dian_HWID3 (-1009792624)
#define Dian_HWID4 (-691389056)
#define Dian_HWID5 (-1939359056)
#define Dian_HWID6 (-1650530128)
#define Dian_HWID7 (-97532320)
#define Dian_HWID8 (-392303392)
#define Dian_HWID9 (111367680)
#define Dian_HWID10 (1958316608)
#define Dian_HWID11 (-484730944)
#define Dian_HWID12 (-664734464)
#define Dian_HWID13 (-1153915712)
#define Dian_HWID14 (176172832)
#define Dian_HWID15 (171400384)
#define Dian_HWID16 (-2053598240)
#define Dian_HWID17 (-606878240)
#define Dian_HWID18 (-1474999616)
#define Dian_HWID19 (-456900176)
#define Dian_HWID20 (353476608)
#define Dian_HWID21 (-727672960)
#define Dian_HWID22 (-193178624)
#define Dian_HWID23 (-365903216)
#define Dian_HWID24 (2019100304)
#define Dian_HWID25 (-513255360)
#define Dian_HWID26 (1765935456)
#define Dian_HWID27 (-973608064)
#define Dian_HWID28 (1735840864)
#define Dian_HWID29 (743941680)


//HWID DATAVIN//= DLL 
#define Datavin_HWIDOperator (-38462224)
#define Datavin_HWID1 (571864688)
#define Datavin_HWID2 (243045552)
#define Datavin_HWID3 (-1377670416)
#define Datavin_HWID4 (-2020215264)
#define Datavin_HWID5 (1144417952)
#define Datavin_HWID6 (-330492560)
#define Datavin_HWID7 (1119123408)
#define Datavin_HWID8 (-1609065520)
#define Datavin_HWID9 (556420144)
#define Datavin_HWID10 (2069181776)//rusak
#define Datavin_HWID11 (298503408)//rusak
#define Datavin_HWID12 (-829507408)
#define Datavin_HWID13 (-2114032816)
#define Datavin_HWID14 (382849856)
#define Datavin_HWID15 (-1848755520)
#define Datavin_HWID16 (285411216)
#define Datavin_HWID17 (1652191520)
#define Datavin_HWID18 (934002720)
#define Datavin_HWID19 (1230326544)
#define Datavin_HWID20 (-299709680)
#define Datavin_HWID21 (-1573540752)
#define Datavin_HWID22 (312048256)
#define Datavin_HWID23 (-653433776)
#define Datavin_HWID24 (1736786288)


#define Vania_HWIDOP (-1201777130)
#define Vania_HWID1 (1548403232)
#define Vania_HWID2 (-1331927520)
#define Vania_HWID3 (-1455395136)
#define Vania_HWID4 (-622597280)
#define Vania_HWID5 (1815756752)
#define Vania_HWID6 (-1451331616)
#define Vania_HWID7 (-1490730800)
#define Vania_HWID8 (135421088)
#define Vania_HWID9 (-11674320)
#define Vania_HWID10 (-51497280)
#define Vania_HWID11 (2052824352)
#define Vania_HWID12 (-1867889072)
#define Vania_HWID13 (2062336848)

#define Wijaya_HWIDOP (1548403232)
#define Wijaya_HWID1 (1103551472)
#define Wijaya_HWID2 (487577808)
#define Wijaya_HWID3 (-921580512)
#define Wijaya_HWID4 (1428769440)
#define Wijaya_HWID5 (1696307040)
#define Wijaya_HWID6 (-900575088)
#define Wijaya_HWID7 (470239952)
#define Wijaya_HWID8 (755356288)
#define Wijaya_HWID9 (-2048711808)
#define Wijaya_HWID10 (-841870144)
#define Wijaya_HWID11 (-912539888)
#define Wijaya_HWID12 (-1892796624)
#define Wijaya_HWID13 (478558736)
#define Wijaya_HWID14 (1548403232)
#define Wijaya_HWID15 (1548403232)

#define Green_HWID1 (-386423840)
#define Green_HWID2 (1717247232)
#define Green_HWID3 (-1316551136)
#define Green_HWID4 (-622429248)
#define Green_HWID5 (-1639474912)
#define Green_HWID6 (554486976)
#define Green_HWID7 (-2110089248)
#define Green_HWID8 (1191303552)
#define Green_HWID9 (-668128176)

VOID CheckValidHardwareID()
{
GetVolumeInformation("C:\\",(LPTSTR)szVolNameBuff,255,&dwSerial, &dwMFL,&dwSysFlags,(LPTSTR)szFileSys,255);
if (
	
	dwSerial == PCNO1_HWID	
	||dwSerial == Begawan_HWID
    ||dwSerial == GameMaster_HWID

// WARNET SAYA YANG DI Kec.Kelara
	||dwSerial == My_HWIDOP
	||dwSerial == My_HWID1
	||dwSerial == My_HWID2
	||dwSerial == My_HWID3
	||dwSerial == My_HWID4
	||dwSerial == My_HWID5
	||dwSerial == My_HWID6
	||dwSerial == My_HWID7

//HWID Wijaya
	||dwSerial == Wijaya_HWID1
	||dwSerial == Wijaya_HWID2
	||dwSerial == Wijaya_HWID3
	||dwSerial == Wijaya_HWID4
	||dwSerial == Wijaya_HWID5
	||dwSerial == Wijaya_HWID6
	||dwSerial == Wijaya_HWID7
	||dwSerial == Wijaya_HWID8
	||dwSerial == Wijaya_HWID9
	||dwSerial == Wijaya_HWID10
	||dwSerial == Wijaya_HWID11
	||dwSerial == Wijaya_HWID12
	||dwSerial == Wijaya_HWID13
	||dwSerial == Wijaya_HWID14
	||dwSerial == Wijaya_HWID15//*/

//HWID ENO
	||dwSerial == Eno_Server
	||dwSerial == Eno_HWID1
	||dwSerial == Eno_HWID2
	||dwSerial == Eno_HWID3
	||dwSerial == Eno_HWID4
	||dwSerial == Eno_HWID5
	||dwSerial == Eno_HWID6
	||dwSerial == Eno_HWID7
	||dwSerial == Eno_HWID8
	||dwSerial == Eno_HWID9
	||dwSerial == Eno_HWID10
	||dwSerial == Eno_HWID11//*/

//HWID Vania
	||dwSerial == Vania_HWIDOP
	||dwSerial == Vania_HWID1
	||dwSerial == Vania_HWID2
	||dwSerial == Vania_HWID3
	||dwSerial == Vania_HWID4
	||dwSerial == Vania_HWID5
	||dwSerial == Vania_HWID6
	||dwSerial == Vania_HWID7
	||dwSerial == Vania_HWID8
	||dwSerial == Vania_HWID9
	||dwSerial == Vania_HWID10
	||dwSerial == Vania_HWID11
	||dwSerial == Vania_HWID12
	||dwSerial == Vania_HWID13
	//||dwSerial == Vania_HWID14
	//||dwSerial == Vania_HWID15
	//||dwSerial == Vania_HWID16

//HWID DIAN CYBER
	||dwSerial == Dian_Operator
	||dwSerial == Dian_HWID1
	||dwSerial == Dian_HWID2
	||dwSerial == Dian_HWID3
	||dwSerial == Dian_HWID4
	||dwSerial == Dian_HWID5
	||dwSerial == Dian_HWID6
	||dwSerial == Dian_HWID7
	||dwSerial == Dian_HWID8
	||dwSerial == Dian_HWID9
	||dwSerial == Dian_HWID10
	||dwSerial == Dian_HWID11
	||dwSerial == Dian_HWID12
	||dwSerial == Dian_HWID13
	||dwSerial == Dian_HWID14
	||dwSerial == Dian_HWID15
	||dwSerial == Dian_HWID16
	||dwSerial == Dian_HWID17
	||dwSerial == Dian_HWID18
	||dwSerial == Dian_HWID19
	||dwSerial == Dian_HWID20
	||dwSerial == Dian_HWID21
	||dwSerial == Dian_HWID22
	||dwSerial == Dian_HWID23
	||dwSerial == Dian_HWID24
	||dwSerial == Dian_HWID25
	||dwSerial == Dian_HWID26
	||dwSerial == Dian_HWID27
	||dwSerial == Dian_HWID28
	||dwSerial == Dian_HWID29

//HWID DATAVIN
	||dwSerial == Datavin_HWIDOperator
	||dwSerial == Datavin_HWID1
	||dwSerial == Datavin_HWID2
	||dwSerial == Datavin_HWID3
	||dwSerial == Datavin_HWID4
	||dwSerial == Datavin_HWID5
	||dwSerial == Datavin_HWID6
	||dwSerial == Datavin_HWID7
	||dwSerial == Datavin_HWID8
	||dwSerial == Datavin_HWID9
	||dwSerial == Datavin_HWID10
	||dwSerial == Datavin_HWID11
	||dwSerial == Datavin_HWID12
	||dwSerial == Datavin_HWID13
	||dwSerial == Datavin_HWID14
	||dwSerial == Datavin_HWID15
	||dwSerial == Datavin_HWID16
	||dwSerial == Datavin_HWID17
	||dwSerial == Datavin_HWID18
	||dwSerial == Datavin_HWID19
	||dwSerial == Datavin_HWID20
	||dwSerial == Datavin_HWID21
	||dwSerial == Datavin_HWID22
	||dwSerial == Datavin_HWID23
	||dwSerial == Datavin_HWID24


	/*||dwSerial == Green_HWID1
	||dwSerial == Green_HWID2
	||dwSerial == Green_HWID3
	||dwSerial == Green_HWID4
	||dwSerial == Green_HWID5
	||dwSerial == Green_HWID6
	||dwSerial == Green_HWID7
	||dwSerial == Green_HWID8
	||dwSerial == Green_HWID9//*/
	)
{}else{
SerialCheck();
} 
}


int dltCheckTrial(char *url)
{
char output[16];
HINTERNET hInternet;
HINTERNET hFile;
DWORD ReadSize;
BOOL bResult;

hInternet = InternetOpenA("Some USER-AGENT", INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL, NULL);
hFile = InternetOpenUrlA(hInternet, url, NULL,NULL, INTERNET_FLAG_RELOAD,NULL);

ReadSize = 15;
bResult = InternetReadFile( hFile, output, 15, &ReadSize);

output[ReadSize] = '\0';
if(strcmp("ooff",output)== 0){ // ooff nya di ganti sama punya lu // di sini lu tulis ON // ooff ganti jadi ON
Beep(1000,100);
}
else {
ExitProcess(0);
}
InternetCloseHandle(hFile);
InternetCloseHandle(hInternet);
return 0;
}
//------------------------------------------------------------------------------------------------------------------------------------

void __stdcall Remote()
{
dltCheckTrial("http://y-gentvip.uk.ht/PointBlank/Trial.txt"); // ganti sama hosting punya lu http://y-gentvip.uk.ht/PointBlank/Trial.txt
}
