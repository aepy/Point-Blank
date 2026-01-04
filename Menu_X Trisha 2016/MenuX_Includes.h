#include <Windows.h>
#include <stdio.h>
#include <d3dx9.h>
#include <d3d9.h>
#include <time.h>


//Pragmas
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "Winmm.lib")

//Texture
LPDIRECT3DVERTEXBUFFER9 iStreamData;
UINT iOffset = 0;
UINT iStride = 0;
LPDIRECT3DVERTEXBUFFER9 Stream_Data;
UINT Offset = 0;
UINT Stride = 0;
UINT texnum = 0;
LPDIRECT3DDEVICE9 i3Device;
LPDIRECT3DDEVICE9 pDevice;
D3DVIEWPORT9 NhViewport;

//Fonts
LPD3DXFONT NHT3XT	= NULL;

//Line
ID3DXLine *NHLine;

//Font Create
bool FontCreate = true;

//Text settings
char * mTitle		= ".:: Vip Cyber Crekerz ::.";
char * mFitTitle	= ".::Fiture::.";
char * mDecTitle	= "";
char * mExtra		= "\n\n\n\n";
char * mCredits		= "Muhammad Sadam S";
char Text[80];

//Mediaplay
int Play;
int Song;
int Browse;
int Next;
int Previous;

//Scroll bar
bool Scroll = false;


//==================================================================
// This file is part of Masmen D3D Private part 2
// Creadit Masmen
//==================================================================

#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <d3dx9.h>
#include <time.h>
//==========pragma comment========
#pragma comment(lib, "d3dx9.lib")
#pragma warning(disable:4996 4244)
#pragma warning(disable:4700 4293 4554)

using namespace std;
int PILIHAN1=0;
int PILIHAN2=0;
int PILIHAN3=0;
int PILIHAN4=0;
int PILIHAN5=0;
int PILIHAN6=0;
int PILIHAN7=0;
int GameFastExit;
int Nh_Teknology;
//-----ESP-----//
int Nh_Teknology1;
int Nh_Teknology2;
int Nh_Teknology3;
int Nh_Teknology4;
int Nh_Teknology26;
int Nh_Teknology27;
//-Deklarsi AIM-//
int Nh_Teknology5;
int Nh_Teknology6;
//---Call_AIM---//
int Nh_Teknology7;  //AIMTARGET
int Nh_Teknology8;  //AIMBULLET
int Nh_Teknology9;	//AIM SHOOT
int Nh_Teknology10; //AIM LOCKTARGET
int Nh_NEWAIM;
//---CallHack---//
int BrussKnife;
int SmartAmmoX;
int QuickChange;
int Recoil;
int Reload;
int WeaponBug_;
int xFirex, RefitFire;
int PisoTeleKill1;
int BulletKiller;
int DamageBulletKill;
int DamagePisoTeleKill1;
int Accuracy;
int AimBody;
int ESPVolume,ESPHealth,FileLine,ESPName,ESPBone;
//---VISUALWH---//
int Nh_Teknology29;
int Nh_Teknology30;
int Nh_Teknology31;
int Nh_Teknology32;
int Nh_Teknology33;
int Nh_Teknology34;
int Wireframe;
int MagnetTele;
int MagnetTele1;
int FlyCacadMode;
int JumpHight;
int flash;
int R_AllMode;
int FloodVk;
int WallCrot;
int NoFog;
int AmmoLC,AmmoBomb,AmmoSmoke,AmmoHK69A,AmmoRPG;
int ESPHealth2;
int ESPHealth3;
int ESPLine;
int ESPObserver;
int ESPDistance;
int ESPKD;
int ESPBoox;
int ESPRank;
int AutoShot;
int AutoHS;
int AutoHS2;
int BoneIndexSelector;
int UNYU;
int CROSS;
int BulletCall;
int AntiOut;
int RafidFire;
int HK;
int WallBug;
int SmokeCall;
int Invincible;
int FakeReplace1;
int BomKiller;
int ReplaceSmoke;
int ReplacePiso;
int Freeze;
int BrustKnife;
int SuicideCall;
int ReplaceAsault;
int ReplaceRPG;
int ZombieCall;
int FreeMove;
int Magnet;
int HiddenWeapon;
int NoFallDamage;
int WallShotHero;
int DamageBulletCall;
int DamageCall;
int DAMAGESMOKE;
int BomberMane;
int BomberKiller;
int DamagePisoTeleKill;
int UnHP;
int PlayerSpeed;
int SmokeKhusus;
int FastKiller;
int FastKelar;
int FastKelar1;
int autoGM;
int VoteKick;
//==========settingColor==========//
int ColorMenu;

bool bReload	= false;
bool bPiso		= false;
bool ReadAmmoo	= false;
bool Keprok,Keprox = false;
DWORD PisoGila,Ghoster;

#pragma message("BY : Muhammad Sadam S")
#define HTSN(Function) CreateThread(0,0,(LPTHREAD_START_ROUTINE)Function,0,0,0);
