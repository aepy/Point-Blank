#include "Pragrama.h"
#include "stdafx.h"
#include "Texture.h"
#include "Hack.h"
#include "ESP.h"
#include "Aim.h"
#include "Exstremkiller.h"
#include "VK-Kick.h"
#include "U_Ammo.h"
#include "Menu.h"
#include "Long Knife.h"
//---------------------------------------------------------------------------------
int mx = 150; 
int my = 60; 
INT menux = 200; 
INT menuy = 40; 
D3D9Menu	*RCH = NULL;
//-------------------------------------------------------------------------------
void RebuildMenu(void){
RCH->AddFolder("D3 Fiture"			         , Moptfolder, &MenuFolder[1] , 2);
	  if(MenuFolder[1]){
RCH->AddItem("WallHack"                     ,Moptonoff , &WallCrot      , 2 );
RCH->AddItem("WallGlass"                    ,Moptonoff , &Weapon        , 2 );
RCH->AddItem("WallCampTerro"                ,Moptonoff , &chamsWeapon   , 2 );
RCH->AddItem("WallCampSwatt"                ,Moptonoff , &chamsWeapon1  , 2 );
RCH->AddItem("CrossHair"                    ,Moptonoff, &CROSS          , 2 );
RCH->AddItem("HotkeyMenu"                   ,Moptonoff, &Hotkey         , 2 );	  
	  }
RCH->AddFolder("ESP Fiture"			         , Moptfolder, &MenuFolder[2] , 2);
	  if(MenuFolder[2]){
RCH->AddItem("ESP Bone"                     ,Moptonoff , &ESPBone       , 2 );
RCH->AddItem("ESP Boxe"                     ,Moptonoff , &ESPBox        , 2 );
RCH->AddItem("ESP Line"                     ,Moptonoff , &ESPLine       , 2 );
RCH->AddItem("ESP Name"                     ,Moptonoff , &ESPName       , 2 );
RCH->AddItem("ESP Health1"                  ,Moptonoff , &ESPHealth     , 2 );
RCH->AddItem("ESP Health2"                  ,Moptonoff , &ESPHealth2    , 2 );
RCH->AddItem("ESP Health3"                  ,Moptonoff , &ESPHealth3    , 2 );
RCH->AddItem("ESP Observer"                 ,Moptonoff , &ESPObserver   , 2 );
RCH->AddItem("ESP Distance"                 ,Moptonoff , &ESPDistance   , 2 );
RCH->AddItem("ESP Kill/Death"               ,Moptonoff , &ESPKD         , 2 );
	  
	  }
RCH->AddFolder("Aim Fiture"			         , Moptfolder, &MenuFolder[3]	, 2);
	  if(MenuFolder[3]){
RCH->AddItem("Aim Bullet"                   ,Moptonoff , &AutoHS        , 2 );
RCH->AddItem("AutoHs Real"                  ,Moptonoff , &AutoHS2       , 2 );
RCH->AddItem("Auto Shot"                    ,Moptonoff , &AutoShot      , 2 );
RCH->AddItem("Target Aim"                   ,Moptonoff3, &AimBody       , 2 );
RCH->AddItem("Bullet Kill"                  ,Moptonoff , &BulletCall    , 2 );
RCH->AddItem("Auto-Pisau"                   ,Moptonoff , &PesoEdan      , 2 );
RCH->AddItem("Auto Kill"                    ,Moptonoff , &AutoFire      , 2 );
RCH->AddItem("Wallshot"                     ,Moptonoff , &Walllshoot    , 2 );
		  }
RCH->AddFolder("Weapon Fiture"			     , Moptfolder, &MenuFolder[4]	, 2);
	  if(MenuFolder[4]){
RCH->AddItem("Ammo Right"                   ,Moptonoff , &Ammo          , 2 );
RCH->AddItem("Fast Reload"                  ,Moptonoff , &Reload        , 2 );
RCH->AddItem("Norecoil"                     ,Moptonoff , &Recoil        , 2 );
RCH->AddItem("RafitFire"                    ,Moptonoff , &RapitFire     , 2 );
RCH->AddItem("Brust Knife"                  ,Moptonoff , &BrustKnife    , 2 );
RCH->AddItem("Quick Change"                 ,Moptonoff , &QuickChange   , 2 );
	  }
RCH->AddFolder("Player Fiture"			     , Moptfolder, &MenuFolder[5]	, 2);	  	  
if(MenuFolder[5]){
RCH->AddItem("RankingHack"                  ,Moptonoff , &RankHack      , 2 );
 RCH->AddItem("Anti Out"                    ,Moptonoff , &AntiOut       , 2 );
RCH->AddItem("JumpHack"                     ,Moptonoff , &JumpHight     , 2 );
RCH->AddItem("JumpHack2"                    ,Moptonoff , &JumpHight2    , 2 );
RCH->AddItem("Bug Atas"                     ,Moptonoff , &Atap          , 2 );
RCH->AddItem("Bug Unyu"                     ,Moptonoff , &UNYU          , 2 );
RCH->AddItem("Bug Wall"                     ,Moptonoff , &WallBug       , 2 );
RCH->AddItem("Bug Luxivile"                 ,Moptonoff , &BugLuxivile   , 2 );
RCH->AddItem("Player Speed"                 ,Moptonoff , &PlayerSpeed   , 2 );
RCH->AddItem("FreeMove"                     ,Moptonoff , &FreeMove      , 2 );
RCH->AddItem("Vote Kick"                    ,Moptonoff , &VoteKick      , 2 );
RCH->AddItem("FreezRespawn"                 ,Moptonoff , &Freeze        , 2 );
	  } 
RCH->AddFolder("Extrems Fiture"			     , Moptfolder, &MenuFolder[6]	, 2);
	  if(MenuFolder[6]){
RCH->AddItem("Planted"                      ,Moptonoff , &PlantedX       , 2 );
RCH->AddItem("Defuse"                       ,Moptonoff , &DefuseX        , 2 );

	  }
RCH->AddFolder("Extrems Fiture"			     , Moptfolder, &MenuFolder[7]	, 2);
	  if(MenuFolder[7]){
RCH->AddItem("Zombie"                       ,Moptonoff , &Zombie        , 2 );
RCH->AddItem("Replace RPG-7"                ,Moptonoff , &RPG           , 2 );
RCH->AddItem("Replace HK-MK"                ,MoptReplaceHK , &HK           , 3 );
RCH->AddItem("Replace Weapon"               ,MoptReplace , &R_AllMode           , 7 );
RCH->AddItem("Replace Granat"               ,MoptRep_Item , &R_AllMode2         , 7 );
RCH->AddItem("GranatKill"                   ,Moptonoff , &SmokeCall     , 2 );
RCH->AddItem("K400Granat"                   ,Moptonoff , &BomKiller     , 2 );
RCH->AddItem("Ammo RPG"                     ,Moptonoff , &AmmoRPG     , 2 );
RCH->AddItem("Ammo LC"                      ,Moptonoff , &AmmoLC     , 2 );
RCH->AddItem("TeleMagnet"                   ,Moptonoff , &TelePortal     , 2 );
RCH->AddItem("InvicbleTime"                 ,Moptonoff , &Invincible    , 2 );
		  }
RCH->AddItem("Tutorial Fiture"              ,Moptonof , &INFO      , 2 );


}

void DrawCrosshair(LPDIRECT3DDEVICE9 pDevice){
	switch(CROSS){
	case 1:
		Crosshair(pDevice, GREEN);
		break;
	
	}
}

//-------------------------------------------------------------------------------
void ShowMenu(LPDIRECT3DDEVICE9 pDevice)
{
if ( RenderText == 1 ) {
D3DXCreateFont(pDevice, 15, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype", &pFont1);
D3DXCreateFontA(pDevice, 11, 0, FW_BOLD, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Tahoma", &pFont );
RenderText = 0;
}
//-------------------------------------------------------------------------------

if(RCH == NULL)
		{
			RCH = new D3D9Menu("Menu Sprited");
		}else{
			if(RCH->Mmax==0) 
				RebuildMenu();
        if(RCH->Mvisible)
		{}
		RCH->MenuShow(mx,my,pDevice); //init for pb
		RCH->MenuNav();
}
}
LPDIRECT3DTEXTURE9 RainbowTextTestX,White,Red,Green,Blue,Black,Purple,Grey,Yellow,Orange,WhiteX,RedX,GreenX,BlueX,BlackX,PurpleX,GreyX,YellowX,OrangeX;;
HRESULT GenerateTexture(IDirect3DDevice9 *pD3Ddev, IDirect3DTexture9 **ppD3Dtex, DWORD colour32)
{
    if(FAILED(pD3Ddev->CreateTexture(8, 8, 1, 0, D3DFMT_A4R4G4B4, D3DPOOL_MANAGED, ppD3Dtex, NULL)))
        return E_FAIL;
    
    WORD colour16 = ((WORD)((colour32>>28)&0xF)<<12)
	            	|(WORD)(((colour32>>20)&0xF)<<8)
	             	|(WORD)(((colour32>>12)&0xF)<<4)
                 	|(WORD)(((colour32>>4)&0xF)<<0);

    D3DLOCKED_RECT d3dlr;    
    (*ppD3Dtex)->LockRect(0, &d3dlr, 0, 0);
    WORD *pDst16 = (WORD*)d3dlr.pBits;

    for(int xy=0; xy < 8*8; xy++)
        *pDst16++ = colour16;

    (*ppD3Dtex)->UnlockRect(0);

    return S_OK;
}

//-------------------------------------------------------------------------------
HRESULT WINAPI hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{
while(!npDevice) {
npDevice = pDevice;                      
}
DrawCrosshair(pDevice);
ShowMenu(pDevice);
RCH->PrintTextv2("GreendCyberHack V.V.I.P",150, 40, RainbowTextTest,pFont,pDevice);
	if (INFO){

RCH->PrintTextv2("Tutorial Fiture | GreendCyberHack |Copyright Point Blank Garena ©2016",RH,  600, RainbowTextTest, pFont,pDevice);
RCH->PrintTextv1("Zombie [LMENU]: Aktifkan Zombie Jika Darah 00 Offkan Zombie Atau Tekan Alt Kiri 2x ",RH,  615, RHC, pFont,pDevice);
RCH->PrintTextv1("Smoke kill : [1]Aktifkan Zombie [2]Smoke [3]Smoke Kill",RH,  630, RHC, pFont,pDevice);
RCH->PrintTextv1("RPG Dan HK [F2]: [1]Aktifkan Zombie [2]RPG ATAU HK",RH,  645, RHC, pFont,pDevice);
RCH->PrintTextv1("BugWall: [1]Aktifkan BugWall [2]Dekati Tangga jika Tidak Bisa Jalan Tekan [SPACE]",RH,  660, RHC, pFont,pDevice);
RCH->PrintTextv1("BugUNYU: [1]Aktifkan BugUNYU [2]Tekan [SHIFT]Untuk On Off",RH,  675, RHC, pFont,pDevice);
RCH->PrintTextv1("FreezeRespawn Untuk Proses Respawn , Menghindari Smoke killer",RH,  690, RHC, pFont,pDevice);
RCH->PrintTextv1("HotkeyManu Aktifkan di dalam Room [HOME]AimBullet [LSHIFT]BugUnyu [DELETE]Sucide [F2]Replace",RH,  705, RHC, pFont,pDevice);
RCH->PrintTextv1("Fast Exit [F12] ",RH,  720, RHC, pFont,pDevice);
	}
//-------------------------------------------------------------------------------
if(GetAsyncKeyState(VK_F12)&1){Exite=!Exite;}
if (Exite){ExitProcess(0);}
//-------------------------------------------------------------------------------
 float ScreenCenterX = (float)Viewport.Width / 2 + Viewport.X +1;
		float ScreenCenterY = (float)Viewport.Height / 10 + Viewport.Y;

		CurrentTickCount = clock() * 0.001f;
		Fps++;

		if((CurrentTickCount - LastTickCount) > 1.0f)
		{
			LastTickCount = CurrentTickCount;
			sprintf(FrameRate, "      Speed = %d Fps ", Fps);
			Fps = 0;
		}
		RCH->DrawTextR(ScreenCenterX-400,ScreenCenterY-60, RED ,FrameRate);

		TimeValue = time(NULL);
		strftime(TimeAndDate, MAX_PATH, "Time & Date [ %a - %b %d - %I:%M %p ]", localtime(&TimeValue));
		RCH->DrawTextL(ScreenCenterX-300,ScreenCenterY-60, RED ,TimeAndDate);

pDevice->GetViewport(&g_ViewPort);
if(!fName)  D3DXCreateFont(pDevice, 11, 0, FW_BOLD, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Tahoma", &fName);//15
if(!fSmall) D3DXCreateFont(pDevice, 14, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Tahoma", &fSmall);//18
if(!Title)	D3DXCreateFont(pDevice, 16, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Monotype Corsiva", &Title);//13
if(!fTime) D3DXCreateFont(pDevice, 40, 0, FW_NORMAL, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &fTime);
if(g_pFont2 == NULL) D3DXCreateFont(pDevice, 16, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Comic Sans MS", &g_pFont2); //Create fonts//Papyrus
if(RainbowTexts!=100){RainbowR-=2,RainbowG-=3,RainbowB-=3;}
if(RainbowTexts!=255){RainbowR+=2,RainbowG+=3,RainbowB+=4;}GenerateTexture(pDevice, &RainbowTextTestX,  RainbowTextTest);
if(!pLine)	D3DXCreateLine( pDevice, &pLine );

////-------------------------------------------------------------------------------
if(*(PBYTE)ResultBaseAmmo2 > NULL){
DrawObserver(pDevice);
EspMode(pDevice);
ESPBoneX(pDevice);
KickPlayer(pDevice);
CallGranade(pDevice);
if(AutoHS2){AutoHsReal(pDevice);}
if(AutoHS){AutoBulletTarget(pDevice);
}
RCHknife();
KnifeKillers();
Grenade();
BOMKiller();
DoAutoShot();
Fitured();
ResCyRankHack();
GHOST_Hacks();
BulletKillers();
WPSmokeKiller();
//Func_NoReload();
_Fitur_RapidFire();
AmmoLauncher();
AmmoRocket();
KnifeGila();
AmmoReloads();
if(DefuseX==1){
	dmcDefusTwo_On();
}
if(PlantedX==1){
	mcdPlantOne_On ();
}
}
if(!GetBattleState()){
AimReal = false;RapitFire=0;FakeReplace=0;UNYU=0;BulletCall=0;AutoHS=0;Zombie=0;AutoHS2=0;ESPObserver=0;AmmoEdan=0;Atap=0;PlantedX=0;DefuseX=0;
AutoAja=0;AmmoBomb=0;BomKiller=0;VoteKick=0;WallBug=0;FreeMove=0;SmokeCall=0;BrustKnife=0;AutoShot=0;NoFallDamage=0;BugLuxivile=0;ram =0;Walllshoot =0;
Invincible=0;Smoke=0;RPG=0;Ammo=0;JumpHight2=0;JumpHight=0;KniffKiller=0;HK=0;Freeze=0;SmokeBomb=0;Pisau=0;PesoEdan=0;PlayerSpeed=0;AutoFire =0;
TelePortal=0;R_AllMode2=0;R_AllMode=0;AmmoLC=0;AmmoHK69A=0;AmmoRPG=0;ReloadBom=0;RCHFC = false;RCHBOMB=false;RCHRPG=false;
	}
Hotkeymenu();
//--------------------------------------------------------------------
DrawMouse(YELLOW,pDevice,mpos);
return oEndScene(pDevice);
}

//-------------------------------------------------------------------------------

#include "RCHHooked.h"
