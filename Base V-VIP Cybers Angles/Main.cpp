//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
#include "Stdafx.h"
#include "cPragma.h"
#include "cMain.h"
#include "cMenu.h"
#include "cOptions.h"
#include "Textures.h"
#include <wininet.h>
#include <time.h>
//========================================================================//
DWORD resultbaseALEXCallHitEventt,resultpointer1baseALEXCallHitEvent,resultArdiPointer1CallHitEvent,resultpointer2baseALEXCallHitEvent,resultpointer3baseALEXCallHitEvent,resultpointer4baseALEXCallHitEvent,resultbaseDoLineCollyy,resultbasegetVCPoss;
DWORD result_g_Render,resultMAXPLAYERS,resultHPSIZE,resultIDSIZE,resultNAMESIZE,resultRANKSIZE,resultOFS_NAMES,resultOFS_PLAYER,resultOFS_RANK,resultOFS_TEAM,resultOFS_HEALTH,resultOFS_RANK2,resultOFS_PING,resultOFS_KILL,resultOFS_TEAMSCORE,resultALLWEAPSIZE,resultALLWEAPSIZE2,resultALLWEAPSIZE3,resultALLWEAPSIZE4,resultALLWEAPSIZE5,resultWEAPSIZE,resultOFS_RELOAD;
DWORD resultOFS_Player,resultOFS_Player2,resultOFS_Weapon,resultOFS_Weapon2,resultOFS_Health,resultOFS_Health2,resultOFS_Ammo,resultOFS_Ammo2,resultOFS_Ammo3,resultBaseVK,resultBaseVK2,resultBaseGhost,resultBaseGhost2,resultPutMessageBuffer,resultSetEventOnce,resultBaseRespawn,resultSuicide,resultOFS_Unfreeze1,resultOFS_Unfreeze2;
DWORD resultOFS_GetButtonState,resultIATOFS_SetEnd,resultMSDeltaX,resultMSDeltaY,resultOFS_PJump,resultOFS_PFall,resultOFS_PIdle1,resultOFS_PIdle2,resultOFS_PQC,resultOFS_WPointer1,resultpointer5baseALEXCallHitEvent,resultOFS_WPointer2,resultOFS_WPointer3,resultOFS_WPointer4,resultOFS_WPointer5,resultOFS_WPointer6,resultOFS_WPointer7;
DWORD resultHook1,resultHook2,ptrghost1,ptrghost2,ptrghost3,ptrghost4,valueghost1,valueghost2,resultOFS_BugWS,resultOFS_BugDT1,resultOFS_BugDT2,resultOFS_ErroLog1,resultOFS_ErroLog2,resultOFS_ErroLog3,resultwinmodefunct,resultbasewinmode,resultTHandleFromEP1,resultTHandleFromEP2;
bool	switcher=false;
bool	Bulletf = false;
float	hoverv;
//========================================================================//
#include "Fitur.h"
#include "ProtectHWID.h"
#include "Esp+Aimbot.h"
#include "EspObserver.h"
#include "AutoHSNoSyarat.h"
#include "AutoShoot.h"
#include "FlodVote.h"
#include "HookHover.h"
#include "AllOffset.h"
#define StartRoutine(Function) CreateThread(0,0,(LPTHREAD_START_ROUTINE)Function,0,0,0);
//========================================================================//
using namespace std;
LPDIRECT3DDEVICE9 NewbieDevice;
LPTSTR PointBlankD3D9 = "d3d9.dll";
LPTSTR PointBlanki3Gfx2 = "i3GfxDx.dll";
LPTSTR PointBlanki3Scn = "i3SceneDx.dll";
LPTSTR PointBlanki3Bsd = "i3BaseDx_Cli.dll";
LPTSTR PointBlankEsvc = "EhSvc.dll";
LPTSTR PointBlanki3Ipt = "i3InputDx.dll";
LPTSTR PointBlankSTR7 = "PointBlank.exe";
//========================================================================//
D3D9Menu  *Heljunai_Syahputra = NULL;
//====================== Option Show Menu =====================//
int mx = 900; // Right Left
int my = 20; // Up Down
//====================== CALL HEADER FPS =====================//
time_t TimeValue;
int		Fps = 0;
char	FrameRate[50] = "";
char	TimeAndDate[MAX_PATH];
float	LastTickCount = 0.0f;
float	CurrentTickCount;
float	FPSfLastTickCount=0.0f;
float	FPSfCurrentTickCount;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
	void RebuildMenu(LPDIRECT3DDEVICE9 pDevice)
	{
	  Heljunai_Syahputra->AddText("VVIP Cyber Angels"	,	"@CopyRight 2015");
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
	Heljunai_Syahputra->AddFolder("Visual Hack"			, Moptfolder, &Direct_D3D		, 2);
	if(Direct_D3D)
	{
		Heljunai_Syahputra->AddItem("Waktu & Tanggal"			, Moptonoff, &fInfo				, 2);
		Heljunai_Syahputra->AddItem("Wallhack Clean"		    , Moptonoff, &WHClean			, 2);
		Heljunai_Syahputra->AddItem("Wallhack Robot"		    , Moptonoff, &WHRobot			, 2);
		Heljunai_Syahputra->AddItem("No Fog"					, Moptonoff, &NoFog				, 2);
		Heljunai_Syahputra->AddItem("No Smoke"					, Moptonoff, &NoSmoke			, 2);
		Heljunai_Syahputra->AddItem("Cross Hair"				, Moptcrozz, &Cross				, 2);
    }
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
	Heljunai_Syahputra->AddFolder("Weapon Hack"					, Moptfolder, &Direct_WEAPON	, 2);
	if(Direct_WEAPON)
	{ 
		Heljunai_Syahputra->AddItem("No Recoil"					, Moptonoff,  &antigyg			, 2);
		Heljunai_Syahputra->AddItem("Brust Knife"				, Moptonoff,  &Knife			, 2);
		Heljunai_Syahputra->AddItem("Knife Killer"				, Moptonoff,  &WeaponFire		, 2);
		Heljunai_Syahputra->AddItem("Quick Change"				, Moptonoff,  &qece				, 2);
		Heljunai_Syahputra->AddItem("Fast Reload"				, Moptonoff,  &Nrld				, 2);
		Heljunai_Syahputra->AddItem("Reload Major"				, Moptonoff,  &ReloadMayor		, 2);
		Heljunai_Syahputra->AddItem("Brutal AWP/SG"				, Moptonoff,  &BRUTAL			, 2);
		//Heljunai_Syahputra->AddItem("AWP/SG No Kokang"			, Moptonoff,  &sgnokokang		, 2);
		Heljunai_Syahputra->AddItem("Plant Boom"				, Moptplant,  &BombEnywhere		, 2);
		Heljunai_Syahputra->AddItem("Unimited Ammo"				, Moptonoff,  &wutmo			, 2);
		Heljunai_Syahputra->AddItem("Ammo Kiri"					, Moptonoff,  &AmmoKiri			, 2);
		Heljunai_Syahputra->AddItem("Rapid Fire"				, Moptonoff,  &RapitFire		, 2);
		//Heljunai_Syahputra->AddItem("Defuse & Pasang Bom 0 Detik"	, Moptonoff,  &PasangBom		, 2);
	}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
	Heljunai_Syahputra->AddFolder("ESP Hack"					, Moptfolder, &Direct_ESP		, 2);
    if(Direct_ESP)
	{
		Heljunai_Syahputra->AddItem("Name"						, Moptonoff, &ESPName			, 2);
		Heljunai_Syahputra->AddItem("Line"						, Moptonoff, &ESPLine			, 2);
		Heljunai_Syahputra->AddItem("Health"					, Moptonoff, &ESPHealth			, 2);
		Heljunai_Syahputra->AddItem("Box"						, Moptonoff, &ESPBox			, 2);
		Heljunai_Syahputra->AddItem("Head"						, Moptonoff, &ESPHead			, 2);
		Heljunai_Syahputra->AddItem("Bone"						, Moptonoff, &ESPBone			, 2);
		Heljunai_Syahputra->AddItem("Distance"					, Moptonoff, &ESPDistance		, 2);
		Heljunai_Syahputra->AddItem("Observer"					, Moptonoff, &ESPObserver		, 2);
	}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
	Heljunai_Syahputra->AddFolder("Player Hack"					, Moptfolder, &Direct_PLAYER	, 2);
	if(Direct_PLAYER)
	{ 
		Heljunai_Syahputra->AddItem("No Fall Damage"			, Moptonoff,  &FallDamage		, 2);
		Heljunai_Syahputra->AddItem("Anti Vote Kick"			, Moptonoff,  &ModeFloodVoteKick, 2);
		Heljunai_Syahputra->AddItem("Rank Skill"				, MoptRank,   &autoGM			, 2);
		Heljunai_Syahputra->AddItem("Free Move"					, Moptonoff,  &FreeMove			, 2);
		Heljunai_Syahputra->AddItem("Anti Idle"					, Moptonoff,  &AntiOut			, 2);
		Heljunai_Syahputra->AddItem("1/2 Hit Body"				, Moptonoff,  &AutoBody			, 2);
		//Heljunai_Syahputra->AddItem("Death Fly"					, Moptonoff,  &DeathFly			, 2);
        //Heljunai_Syahputra->AddItem("Jump Higt"					, Moptonoff,  &JumpHight		, 2);
		Heljunai_Syahputra->AddItem("No Respawn"				, Moptonoff,  &NoRespawn		, 2);
    }
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
	Heljunai_Syahputra->AddFolder("AIM Hack"					, Moptfolder, &Direct_AIM		, 2);
	if(Direct_AIM)
	{
		Heljunai_Syahputra->AddItem("AIM Bullet"				, Moptonoff,  &Accuracy			, 2);
		Heljunai_Syahputra->AddItem("AIM Lock"					, Moptonoff,  &AimHead			, 2);
		Heljunai_Syahputra->AddItem("Target Sasaran"			, MoptTarget, &AimBody			, 12);
	}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
	Heljunai_Syahputra->AddFolder("Bug Mode Hack"				, Moptfolder, &Direct_BUG	, 2);
	if(Direct_BUG)
	{ 
		Heljunai_Syahputra->AddItem("Wall Bug"					, Moptonoff,  &BugHvr			, 2);
		Heljunai_Syahputra->AddItem("Bug Unyu"					, Moptonoff,  &BugWS			, 2);
	}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
	Heljunai_Syahputra->AddFolder("Magnet Mode Hack"			, Moptfolder, &Direct_Magnet	, 2);
	if(Direct_Magnet)
	{ 
		Heljunai_Syahputra->AddItem("Magnet BurningHall"		, Moptonoff,  &Magnet			, 2);
		Heljunai_Syahputra->AddItem("Magnet RedRock"			, Moptonoff,  &MagnetAll		, 2);
		Heljunai_Syahputra->AddItem("Magnet Luxville"			, Moptonoff,  &MagnetLux		, 2);
	}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
	Heljunai_Syahputra->AddFolder("Replace Hack"				, Moptfolder, &Direct_REPLACE	, 2);
	if(Direct_REPLACE)
	{ 
	    Heljunai_Syahputra->AddItem("Special Item"				, MoptItem	, &WPSmoke		    , 6);
	    Heljunai_Syahputra->AddItem("Special Weapon"			, MoptHOT	, &HOT		    , 7);
	    Heljunai_Syahputra->AddItem("Special Secondary"			, MoptSec	, &Secondary	    , 8);
	    //Heljunai_Syahputra->AddItem("Special RPG"				, MoptRPG	, &RPG			, 8);
	    Heljunai_Syahputra->AddText("Perhatian : Jangan Onkan Berlebihan"	," ");
	}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
	Heljunai_Syahputra->AddFolder("Replace Launcher"			, Moptfolder, &Direct_Launcher	, 2);
	if(Direct_Launcher)
	{ 
	    Heljunai_Syahputra->AddItem("Launcher"					, MoptLC	, &FamasLC		    , 4);
	    Heljunai_Syahputra->AddItem("WP Smoke / Grenade"		, MopSmoke	, &R_Granad		    , 8);
	    Heljunai_Syahputra->AddItem("RPG-7"						, MoptRPG	, &RPG				, 2);
	    Heljunai_Syahputra->AddItem("Pistol"					, MoptPistol, &Pistol			, 3);
	    Heljunai_Syahputra->AddText("Perhatian : Jangan Onkan Berlebihan"	," ");
	}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
	Heljunai_Syahputra->AddFolder("Extreme Hack"				, Moptfolder, &Direct_HOT		, 2);
	if(Direct_HOT)
	{
		Heljunai_Syahputra->AddItem("Ghost Zombie No Syarat"	, Moptonoff,  &Zombie			, 2);
		//Heljunai_Syahputra->AddItem("Pistol Killer"				, Moptonoff,  &BommKiller		, 2);
		Heljunai_Syahputra->AddItem("Bullet Killer"				, Moptonoff,  &BulletKiller		, 2);
		Heljunai_Syahputra->AddItem("Smoke Killer"	, Moptonoff,  &WPSmokeKill  	, 2);
		//Heljunai_Syahputra->AddItem("Smoke Killer Boom Mission"	, Moptonoff,  &WPSmokeBOM	  	, 2);
		Heljunai_Syahputra->AddItem("Bom Killer"				, Moptonoff,  &GranadeCall		, 2);
		Heljunai_Syahputra->AddItem("Invisible Killer"			, Moptonoff,  &Invicible		, 2);
		Heljunai_Syahputra->AddItem("WallShot"					, Moptonoff,  &WSBrooK2			, 2);
		Heljunai_Syahputra->AddItem("Freeze Time Respawn"		, Moptonoff,  &RespawnTerus		, 2);
		Heljunai_Syahputra->AddItem("Bug Gravity"				, Moptonoff,  &CH_Terbang		, 2);
		Heljunai_Syahputra->AddText("Fast Killer"				,"-DETELE-");
		Heljunai_Syahputra->AddText("Tombol Cepat Off Fiture"	,"-CTRL Kanan-");
	}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
	Heljunai_Syahputra->AddFolder("Hot Key Fiture"				, Moptfolder, &Direct_HOTKEY	, 2);
	if(Direct_HOTKEY)
	{ 
		Heljunai_Syahputra->AddText("AIM Bullet"				,"-F4-");
		Heljunai_Syahputra->AddText("Zombie Killer"				,"-F5-");
		Heljunai_Syahputra->AddText("Bullet Killer"				,"-F6-");
		Heljunai_Syahputra->AddText("WP Smoke Killer"			,"-F7-");
		Heljunai_Syahputra->AddText("Invisible Killer"			,"-F9-");
		Heljunai_Syahputra->AddText("WallShot"					,"-F10-");
		Heljunai_Syahputra->AddText("Auto Suicide"				,"-END-");
		Heljunai_Syahputra->AddText("Fast Exit"					,"-F12-");
	}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
	Heljunai_Syahputra->AddFolder("Tutorial Cheat"				, Moptfolder, &Direct_TUTOR	, 2);
	if(Direct_TUTOR)
	{ 
		Heljunai_Syahputra->AddTutor("-----> WP Smoke Killer", Moptfolder, &Direct_WP	, 2);
		if(Direct_WP)
		{
		Heljunai_Syahputra->AddText("1. Aktifkan Menu Replace Item."				,"");
		Heljunai_Syahputra->AddText("2. Pilih Jenis Replace."				,"");
		Heljunai_Syahputra->AddText("3. Lalu Bunuh Diri Dengan Menekan Tombol -END- Pada Keyboard."				,"");
		Heljunai_Syahputra->AddText("4. Jika Replace Udah Berubah."				,"");
		Heljunai_Syahputra->AddText("5. Aktifkan Ghost Zombie No Syarat."				,"");
		Heljunai_Syahputra->AddText("6. Setelah Itu Aktifkan WP Smoke Killer dan Wallshot."				,"");
		Heljunai_Syahputra->AddText("7. Jika Ingin Fast Killers Pergi ke Markas Musuh Lalu Aktifkan Invicible."				,"");
		Heljunai_Syahputra->AddText("8. Ingat Jangan bergerak Bebas. Cukup Mouse Aja Di gerakin."				,"");
		Heljunai_Syahputra->AddText("9. PENTING : Offkan Fiture Extreme Hack Setelah game hampir Selesai. Langkah Cepat Tekan CTRL Kanan."				,"");
		Heljunai_Syahputra->AddText("~Selesai~"				,"");
		}
		Heljunai_Syahputra->AddTutor("-----> Bom Killer", Moptfolder, &Direct_BOM	, 2);
		if(Direct_BOM)
		{
		Heljunai_Syahputra->AddText("1. Harus Bom Beli Di Shop."				,"");
		Heljunai_Syahputra->AddText("2. Jika Sudah Punya. Aktifkan Ghost Zombie No Syarat."				,"");
		Heljunai_Syahputra->AddText("3. Lalu Aktifkan Bom Killer."				,"");
		Heljunai_Syahputra->AddText("4. PENTING : Offkan Fiture Extreme Hack Setelah game hampir Selesai. Langkah Cepat Tekan CTRL Kanan."				,"");
		Heljunai_Syahputra->AddText("~Selesai~"				,"");
		}
	}
//==============================================// Information  //============================================================//
	Heljunai_Syahputra->AddFolder("Information"				, Moptfolder, &Direct_INFO	, 2);
	if(Direct_INFO)
	{ 
		Heljunai_Syahputra->AddText("Admin :"						,	"1. Heljunai Syahputra");
		Heljunai_Syahputra->AddText(""								,	"2. Dedy Prasetyo");
		Heljunai_Syahputra->AddText("Baca : Gunakan Dengan Bijak !"			,	"");
		Heljunai_Syahputra->AddText("NB : Aktifkan Cheat Dalam Room !"		,	"");
	}
}
//====================== Crosshair =====================//
void DrawCrosshair(LPDIRECT3DDEVICE9 pDevice)
{
if(GetBattleState()){
if (Cross==1){
	int x = ( GetSystemMetrics( 0 ) / 2);
    int y = ( GetSystemMetrics( 1 ) / 2);
		D3DRECT RectA, RectB;
		RectA.x1 = (x)-10;
		RectA.x2 = (x)+ 10;
		RectA.y1 = (y);
		RectA.y2 = (y)+1;
		RectB.x1 = (x);
		RectB.x2 = (x)+ 1;
		RectB.y1 = (y)-10;
		RectB.y2 = (y)+10;
		pDevice->Clear(1, &RectA, D3DCLEAR_TARGET, SKYBLUE, 0,  0);
		pDevice->Clear(1, &RectB, D3DCLEAR_TARGET, SKYBLUE, 0,  0);
}}}

//====================== Hook Direct =====================//
HRESULT WINAPI hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{
while(!npDevice) {
npDevice = pDevice;                      
}

if( !Create )
{
Heljunai_Syahputra->FontCreate(pDevice);
Create = true;
}

if(Heljunai_Syahputra == NULL){
Heljunai_Syahputra = new D3D9Menu("");
}else{
if(Heljunai_Syahputra->Mmax==0) RebuildMenu(pDevice);
if(Heljunai_Syahputra->Mvisible){
}
Heljunai_Syahputra->MenuShow(mx,my,pDevice);
Heljunai_Syahputra->MenuNav();}
//=============================================================================================================================//

if(GetBattleState()){
if(fInfo==1)
	{
		float ScreenCenterX = (float)Viewport.Width / 2 + Viewport.X +1;
		float ScreenCenterY = (float)Viewport.Height / 10 + Viewport.Y;

		CurrentTickCount = clock() * 0.001f;
		Fps++;

		if((CurrentTickCount - LastTickCount) > 1.0f)
		{
			LastTickCount = CurrentTickCount;
			sprintf(FrameRate, " Speed = %d Fps ", Fps);
			Fps = 0;
		}
		Heljunai_Syahputra->DrawTextR(ScreenCenterX-428,ScreenCenterY-73, dYellow ,FrameRate);
}

if(fInfo==1)
	{
		float ScreenCenterX = (float)Viewport.Width / 2 + Viewport.X +1;
		float ScreenCenterY = (float)Viewport.Height / 10 + Viewport.Y;
		TimeValue = time(NULL);
		strftime(TimeAndDate, MAX_PATH, "Time & Date [ %a - %b %d - %I:%M %p ]", localtime(&TimeValue));
		Heljunai_Syahputra->DrawTextL(ScreenCenterX-300,ScreenCenterY-58, dRed ,TimeAndDate);
}}
BoneESP(pDevice);
ADDXESP(pDevice);
RadarBM(pDevice);
DoAimbot(pDevice);
DoAimBullet(pDevice);
if(AutoHS2){
DoAutoHSNoSyarat(pDevice);}
if(AutoBody){
DoAutoBody(pDevice);}
DrawCrosshair(pDevice);
WPSmokeMode();
WPSmokeBomMission();
IamKillYou4();
GhostHide();
PisoGile();
BulledKiller1();
BommKiller1();
//===============================//
if(GetBattleState()){
if(GetAsyncKeyState(VK_END)&1){
KillMySelf(); }}
pDevice->GetViewport(&g_ViewPort);
//======================================================= Draw Font & Color ========================================================//
if(!fName)  D3DXCreateFontA(pDevice, 14, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Sylfaen", &fName);//15
if(!fSmall) D3DXCreateFontA(pDevice, 28, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Monotype Corsiva", &fSmall);//18
if(!Title)	D3DXCreateFontA(pDevice, 14, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Sylfaen", &Title);//13
if(g_pFont == NULL) D3DXCreateFont(pDevice, 14, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Sylfaen", &g_pFont);
if(!pLine)	D3DXCreateLine( pDevice, &pLine );
//----------------------------------------------------------------------------------------------------------------------------||
int RenderText = 1;
D3DVIEWPORT9 pGViewPort;
if ( RenderText == 1 ) {
RenderText = 0;
}
//----------------------------------------------------------------------------------------------------------------------------||
	pDevice->GetViewport(&pGViewPort);
	int ScreenCenterX = (float)pGViewPort.Width / 2;
	int ScreenCenterY = (float)pGViewPort.Height / 2;
	int ScreenBottomX = (float)pGViewPort.Width;
	int ScreenBottomY = (float)pGViewPort.Height;
    {
	DxESP->DrawString(ScreenCenterX-210,670,RED,"              Welcome to VVIP Cyber Angels","");}
//======================================================= Draw D3D ========================================================//
	return oEndScene(pDevice);
}
//=============================================================================================================================//
HRESULT WINAPI hkDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount)
{

if(pDevice->GetStreamSource(0, &Stream_Data, &Offset, &Stride) == D3D_OK){
Stream_Data->Release();
}

//======================================================= Wallhack Clean ========================================================//
if(GetBattleState()){
if(WHClean==1)
{   
if(allp)   
{            
pDevice->SetRenderState(D3DRS_ZENABLE, false);
pDevice->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
pDevice->SetRenderState(D3DRS_ZENABLE, true);
pDevice->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
}}}
//======================================================= Wallhack Robot ========================================================//
if(WHRobot)
{   
if(allp)   
{            
pDevice->Clear(0, 0, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);	 
}}
//======================================================= Without Smoke ========================================================//
if(GetBattleState()){
if(NoSmoke==1)                                                  
{
if ((NumVertices == 192) || (NumVertices == 256))	  
{
return D3D_OK;
return 0;
}}}

//======================================================= Without FOG ========================================================//
if(GetBattleState()){
if(NoFog==1)                                                   
{
pDevice->SetRenderState(D3DRS_FOGENABLE, false);
}}
	return oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

//======================================================= PROCESS HOOK HACKSHEILD ========================================================//
BOOL NewbieMemoryX( DWORD dwAddress, const void* cpvPatch, DWORD dwSize )
{
DWORD dwProtect;
if( VirtualProtect( (void*)dwAddress, dwSize, PAGE_READWRITE, &dwProtect ) ) //Unprotect the memory
memcpy( (void*)dwAddress, cpvPatch, dwSize ); 
else
return false; //Failed to unprotect, so return false..
return VirtualProtect( (void*)dwAddress, dwSize, dwProtect, new DWORD ); //Reprotect the memory
}
int WriteHook(LPVOID Device , LPCVOID Addres , int Size)
{
			DWORD OldProtect;
			VirtualProtect((void*)(Addres), Size, PAGE_EXECUTE_READWRITE, &OldProtect);
			memcpy(Device, (void *)Addres, Size);
			VirtualProtect((void*)(Addres), Size, OldProtect, NULL);
			return true;
}
BOOL NewbieFuntionE9( DWORD From, DWORD To )
{
BYTE bpJump2[2] = { 0xEB, (BYTE)(0xFF - ((From - To) + 1)) }; 
BYTE bpJump[2] = { 0xEB, (BYTE)((To - From) - 2)};
BYTE bpJump1[5] = { 0xE9, 0x00, 0x00, 0x00, 0x00 };


if( To < From + 128 && To > From - 128 ) 
if(To > From)
return NewbieMemoryX( From, bpJump, 2 );
else  
return NewbieMemoryX( From, bpJump2, 2 );
else 
if(To > From)  
*(DWORD*)&bpJump1[1] = To - (From + 5); 
 else 
*(DWORD*)&bpJump1[1] = (0xFFFFFFFF - (From + 4)) + To; 
return NewbieMemoryX( From, bpJump1, 5 );
return false; 
}

DWORD newg2=0;
DWORD Readdevice (DWORD ALAY1,DWORD ALAY2)
{

if(IsBadReadPtr((PDWORD)(ALAY1),4)==0) 
newg2=*(PDWORD)((DWORD)(ALAY1))+ALAY2; 
if(IsBadReadPtr((PDWORD)newg2,4)==0) 
return *(PDWORD)newg2;

return newg2;
}

DWORD *NEBIEGANTENG;
DWORD OldProtect;
DWORD crotcepirit;

void BYPASS(){
crotcepirit = (DWORD)LoadLibraryA(PointBlankEsvc)+ resultHook2;
VirtualProtect((void*)(crotcepirit), 4, PAGE_EXECUTE_READWRITE, &OldProtect);
*(int*)(crotcepirit) =4;
VirtualProtect((void*)(crotcepirit), 4, OldProtect, NULL);}
//=================================CREATED HOOK ===================================================================//
bool LoopEngine = false;
DWORD WINAPI MyThread(){
HWND PointBlankWindow;
do {
PointBlankWindow = FindWindowA("I3Viewer","Point Blank");
}while (!PointBlankWindow);
Sleep(150);

DWORD newg1 = (DWORD)GetModuleHandleA(PointBlanki3Gfx2) + g_Render;
while(!NewbieDevice){
Readdevice(newg1,resultHook1);
WriteHook((LPVOID)&NewbieDevice,(LPCVOID)newg2,4);
}
NEBIEGANTENG = (DWORD*)NewbieDevice;
NEBIEGANTENG = (DWORD*)NEBIEGANTENG[0];
//======================================================================================================================//
while(!pDevice) {
pDevice = (LPDIRECT3DDEVICE9)(DWORD*)NEBIEGANTENG;
}
//======================================================================================================================//
*(PDWORD)&oDrawIndexedPrimitive = NEBIEGANTENG[82];
*(PDWORD)&oEndScene = NEBIEGANTENG[42];
//======================================================================================================================//
DWORD *NewbieFuckingFuntion_1 = ( PDWORD )( NEBIEGANTENG[1] - 5 );
DWORD *NewbieFuckingFuntion_2 = ( PDWORD )( NEBIEGANTENG[2] - 5 );
DWORD *NewbieFuckingFuntion_3 = ( PDWORD )( NEBIEGANTENG[3] - 5 );
DWORD *NewbieFuckingFuntion_4 = ( PDWORD )( NEBIEGANTENG[4] - 5 );
DWORD *NewbieFuckingFuntion_5 = ( PDWORD )( NEBIEGANTENG[5] - 5 );
DWORD *NewbieFuckingFuntion_6 = ( PDWORD )( NEBIEGANTENG[6] - 5 );

NewbieFuntionE9((DWORD)( NewbieFuckingFuntion_1 ), (DWORD)( NewbieFuckingFuntion_4 ));
NewbieFuntionE9((DWORD)( NewbieFuckingFuntion_2 ), (DWORD)( NewbieFuckingFuntion_5  ));
NewbieFuntionE9((DWORD)( NewbieFuckingFuntion_3 ), (DWORD)( NewbieFuckingFuntion_6  ));
NewbieFuntionE9((DWORD)( NewbieFuckingFuntion_4 ), (DWORD)hkEndScene);
NewbieFuntionE9((DWORD)( NewbieFuckingFuntion_5 ), (DWORD)hkDrawIndexedPrimitive);
BYPASS();
while(1)
{
NEBIEGANTENG[42] = (DWORD)NewbieFuckingFuntion_1;
NEBIEGANTENG[82] = (DWORD)NewbieFuckingFuntion_2;
Sleep(20);
}
return(0);
}
//===========================================================================================================================================//
#define  Addres_BgHover	(DWORD)(GetModuleHandleA("NxCharacter.2.8.1.dll"))+ 0x16510
DWORD RETURN_HOVERV = Addres_BgHover + 0x6;


__declspec( naked ) void Hover_On()
{
_asm
{
cmp [Bulletf],0
je Normall
mov [ebx+0000011Ch],eax
mov [hoverv],eax
jmp [RETURN_HOVERV]
Normall:
mov eax,[hoverv]
mov [ebx+0000011Ch],eax
jmp [RETURN_HOVERV]
}
}

unsigned long PNT = resultTHandleFromEP2;
LONG CALLBACK VectoredHandler(PEXCEPTION_POINTERS ExceptionInfo)
{
if (ExceptionInfo->ExceptionRecord->ExceptionAddress == (void*)(Addres_BgHover))
{
ExceptionInfo->ContextRecord->Eip =PNT= (DWORD)Hover_On;

return EXCEPTION_CONTINUE_EXECUTION;
}
return EXCEPTION_CONTINUE_SEARCH;
}
//==========================================================================================================================================//
#define PRCHOVER   (unsigned long)(GetModuleHandleA("NxCharacter.2.8.1.dll"))+ 0x16510

void DEHOBUG()
{
	AddVectoredExceptionHandler(1,VectoredHandler); 
	HANDLE hThread = THandleFromEP();
	CONTEXT Context = {CONTEXT_DEBUG_REGISTERS};
	Context.Dr0 = ((unsigned long)(PRCHOVER));
	Context.Dr6 = 0xFFFF0FF0;
	Context.Dr7 = 0x15;
	SetThreadContext(hThread,&Context);
}
//------------------------------------------------------------------------------------------------// [PEMASANGAN HWID]
#define Admin     (-933176865)  //<==HWID Pembuat/Penjual Cheat [Heljunai Syahputra]
#define Pembeli_1 (-972970626)  //<==HWID Mellodi Cell (1 Minggu) (Start 21 Januari 2015)
#define Pembeli_2 (-000000000)  //<==HWID Rafii Rhezzshult (3Hari) (Start 17 januari 2015)
#define Pembeli_3 (-000000000)  //<==HWID Billy Dot ID (3Hari) (Start 17 januari 2015)
#define Pembeli_4 (1080488267)  //<==HWID Muhammad Helmi Mulyadi (Permanent)
#define Pembeli_5 (-733343547)  //<==HWID Iko Surya Maliki (1 Minggu) (Start 19 januari 2015)
#define Pembeli_6 (-1473544934) //<==HWID PC 18 (HSNet Permanent)
#define Pembeli_7 (-1236331545) //<==HWID Lynys Slikers Devilred (2 Minggu) (Start 22 januari 2015)
//------------------------------------------------------------------------------------------------//
void CheckHWIDD()
{
GetVolumeInformation("C:\\",(LPTSTR)szVolNameBuff,255,&dwSerial, &dwMFL,&dwSysFlags,(LPTSTR)szFileSys,255);
if (dwSerial == Pembeli_1 || dwSerial == Admin || dwSerial == Pembeli_2 || dwSerial == Pembeli_3 || dwSerial == Pembeli_4 || dwSerial == Pembeli_5 || dwSerial == Pembeli_6  || dwSerial == Pembeli_7 ) 
{
}
else
{
ExitProcess(1);
}
}
//======================================================= SEND LOGGER TO HACKSHEILD ========================================================//
DWORD WINAPI ZRC_LOG1(LPVOID lpParam){
while (1){
Thread_Aimbot();
DoAutoShot();
Sleep(0);
}}

void XZRCHacks()
{
DWORD HackShield,i3GfxDx,I3InputDx,i3SceneDx,i3BaseDx;
DWORD dwStartAddress = 0x400000;
HMODULE i3GfxDx2 = LoadLibraryA(PointBlanki3Gfx2);
do {
dwStartAddress = (DWORD)GetModuleHandleA(PointBlankSTR7);
i3GfxDx = (DWORD)GetModuleHandleA(PointBlanki3Gfx2);
HackShield = (DWORD)GetModuleHandleA(PointBlankEsvc);
I3InputDx = (DWORD)GetModuleHandleA(PointBlanki3Ipt);
i3SceneDx = (DWORD)GetModuleHandleA(PointBlanki3Scn);
i3BaseDx = (DWORD)GetModuleHandleA(PointBlanki3Bsd);
}while(!HackShield);	//
DWORD dwSize = dwStartAddress + 0x6FFFFF;
DWORD dwSizei3GfxDx = i3GfxDx + 0x1FFFFF;
DWORD dwSizeHackShield = HackShield + 0x1FFFFF;
DWORD dwSizeI3InputDx_Hook = I3InputDx + 0x1FFFFF;
DWORD dwSizei3SceneDx = i3SceneDx + 0x1FFFFF;
//============================================================================//
result_g_Render=0x1AD2F0;
resultMAXPLAYERS=0x16;
resultHPSIZE=0x20;
resultIDSIZE=0x01;
resultNAMESIZE=0x21;
resultRANKSIZE=0x2B;
resultOFS_NAMES=0x2947C;
resultOFS_PLAYER=0x279CC;
resultOFS_RANK=0x27C38;
resultOFS_TEAM=0x2989C;
resultOFS_HEALTH=0x264;
resultOFS_RANK2=0x27C39;
resultOFS_PING=0x3B750;
resultOFS_KILL=0x3B7AC;
resultOFS_TEAMSCORE=0x3B7A4;
resultALLWEAPSIZE=0x28020;
resultALLWEAPSIZE2=0x27F9C;
resultALLWEAPSIZE3=0x27FA0;
resultALLWEAPSIZE4=0x27E70;
resultALLWEAPSIZE5=0x27E6C;
resultWEAPSIZE=0x158;
resultOFS_RELOAD=0x27A1C;
//============================================================================//
resultOFS_Player=0x7BEF80;
resultOFS_Player2=0xBBEF80;
resultOFS_Weapon=OFS_Player-0x1C;
resultOFS_Weapon2=OFS_Player2-0x1C;
resultOFS_Health=OFS_Player-0x34;
resultOFS_Health2=OFS_Player2-0x34;
resultOFS_Ammo=OFS_Player-0x38;
resultOFS_Ammo2=OFS_Player2-0x38;
resultOFS_Ammo3=0xBCAFC4; 
resultBaseVK=OFS_Player-0x8;
resultBaseVK2=OFS_Player2-0x8;
resultBaseGhost=OFS_Player-0x28;
resultBaseGhost2=OFS_Player2-0x28;
resultSetEventOnce=0x150160;
resultBaseRespawn=0x27622;
resultSuicide=0x29F6E0;
resultOFS_Unfreeze1=0x5F71D4;
resultOFS_Unfreeze2=0x67B01C;
resultOFS_BugWS=0x68876F; 
resultOFS_BugDT1=0x16510;
resultOFS_BugDT2=0x110A3;
resultTHandleFromEP1=0x97D2DB;
resultTHandleFromEP2=0x40A3A3;
//============================================================================//
resultbaseALEXCallHitEventt=0x8D2FC0;
resultpointer1baseALEXCallHitEvent=0x544;
resultpointer2baseALEXCallHitEvent=0x1C;
resultpointer3baseALEXCallHitEvent=0x2C;
resultpointer5baseALEXCallHitEvent=0x20;
resultpointer4baseALEXCallHitEvent=0x558;
resultArdiPointer1CallHitEvent=0x28;
resultbaseDoLineCollyy=0x588B30;
resultbasegetVCPoss=0x7152A0;
resultHook1=0x5368;
resultHook2=0x14B69C+0x7C;
//============================================================================//
resultOFS_PFall=0x514;
resultOFS_PIdle1=0x1B7;
resultOFS_PIdle2=0x1BB;
resultOFS_PJump=0x50C;
resultOFS_PQC=0x540;
resultOFS_WPointer1=0x544;
resultOFS_WPointer2=0x558;
resultOFS_WPointer3=0x584;
resultOFS_WPointer4=0xCA0;
resultOFS_WPointer5=0x5D4;
resultOFS_WPointer6=0x508;
//============================================================================//
ptrghost1=0x25;
ptrghost2=0x28;
ptrghost3=0x2F;
ptrghost4=0x32;
valueghost1=0xFFFFFF;
valueghost2=0xFFFFFFFF;
//============================================================================//
//if(switcher==true){
CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MyThread, NULL, NULL, NULL);
CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ZRCHack, NULL, NULL, NULL);
CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ReplaceHOT,NULL,NULL,NULL);
CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ReplaceSmoke,NULL,NULL,NULL);
CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ReplaceRPG,NULL,NULL,NULL);
CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ReplaceSecondary,NULL,NULL,NULL);
//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)REPLACE,NULL,NULL,NULL);
//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)CheckHWIDD,NULL,NULL,NULL);
CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)HookTelekill,NULL,NULL,NULL);
CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)DEHOBUG,NULL,NULL,NULL);
}/*}*/
//======================================================= PROCESS ATTACH DLL MAIN ========================================================//
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved)
{
if(dwReason == DLL_PROCESS_ATTACH){
//MessageBox (0, "1. Heljunai Syahputra \n2. Dedy Prasetyo","Info Admin", MB_OK|MB_ICONINFORMATION);
MessageBox (0, "Selamat menggunakan Cheat"," Sukses Inject ", MB_OK|MB_ICONINFORMATION);
MessageBox (0, "Gunakan Cheat Dengan Bijak..!!","Information", MB_OK|MB_ICONINFORMATION);
CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ThreadFloodVK,NULL,NULL,NULL);
CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)XZRCHacks,NULL,NULL,NULL);
StartRoutine(CyberAngelsHack);;
}
return TRUE;
}