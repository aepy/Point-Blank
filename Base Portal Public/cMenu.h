/*cMenu.h D3D9 PBHacks Last Edit By Angga Reviza*/
#include <windows.h>
#include "cGameHacks.h"

/*-------------------------------------------------------------------------------------------------------------------*/
int Drawing		= 0;
int Mpos		= 0;	
int Mmax		= 0;
int DrawFont	= 1;
int Mvisible	= 1;
int Mxofs		= 25.0f;
int Mysize		= 15.0f;
int my			= 59; // Up Down
int	mx			= 110; // Right Left
char Mtitle[81]	= "";

LPDIRECT3DVERTEXBUFFER9 Stream_Data;
UINT Offset = 0;
UINT Stride = 0;
LPDIRECT3DDEVICE9 npDevice, pGDevice; 

/*-------------------------------------------------------------------------------------------------------------------*/
char *Moptfolder          []   = {"OPEN", "CLOSE"}; 
char *Moptonoff           []   = {"OFF", "ON"};
char *MoptCross           []   = {"OFF", "+", "•"};
char *MoptAimPel          []   = {"OFF Pintas 'HOME'", "ON Pintas 'HOME'"};
char *MoptAutoHS          []   = {"OFF Pintas 'Capslock'", "ON Pintas 'Capslock'"};
char *MoptAutoBody        []   = {"OFF Pintas 'Shift Kanan'", "ON Pintas 'Shift Kanan'"};
char *MoptZombie          []   = {"OFF Pintas 'Alt Kiri'", "ON Pintas 'Alt Kiri'"};
char *MoptGhost           []   = {"OFF Pintas 'Shift Kiri'", "ON Pintas 'Shift Kiri'"};
char *MoptFake			  []   = {"OFF", "F2"};
char *MoptDsb			  []   = {"Perbaikan"};
char *MoptTarget		  []   = {"Head", "Body"};
char *Moptplant		      []   = {"OFF", "Site Bomb A", "Site Bomb B"};
char *MoptRank1			  []   = {"OFF", "GM"};
char *MoptGrenade         []   = {"OFF" ,"Soccer Granade","Candy Granade","Lantern Grenade","Decoy Bomb","Bread Grenade","WP Smoke ++","WP Smoke D"}; 
char *MoptLauncher        []   = {"OFF" ,"Famas G2 C","K201 Ext","AK47 FC","AK Sopmod R","SCAR D","M4 SR-16 FC","RPG-7","HK-69"};

/*-------------------------------------------------------------------------------------------------------------------*/
#define 		MENUMAXINDEX	100
#define 		MENUFOLDER		1
#define 		MENUTEXT		2
#define 		MENUITEM		3
#define			MENUCAT			4
#define			COLORFOLDER		RED		//D3DCOLOR_ARGB(255, 255, 255, 000)
#define			COLORTEXT		GREEN	//D3DCOLOR_ARGB(255, 000, 255, 000)
#define			COLORON			SKYBLUE	//D3DCOLOR_ARGB(255, 000, 255, 000)
#define			COLOROFF		WHITE	//D3DCOLOR_ARGB(255, 245, 000, 000)
#define			COLORCURENT		WHITE	//D3DCOLOR_ARGB(255, 245, 000, 000)

struct{
int  *var;
int  maxvalue;
int  typ;
char *txt;
char **opt;
}


D3MENU[MENUMAXINDEX];
LPD3DXFONT pFont;
/*------------------------------------------- Declaration AddText ------------------------------------------------------*/
void AddItem(char *txt, char **opt, int *var, int maxvalue, int typ)
{
	D3MENU[Mmax].typ=typ;
	D3MENU[Mmax].txt=txt;
	D3MENU[Mmax].opt=opt;
	D3MENU[Mmax].var=var;
	D3MENU[Mmax].maxvalue=maxvalue;
	Mmax++;
}

/*------------------------------------------- Declaration AddText ------------------------------------------------------*/
void AddText(char *txt, char *opt)
{
	D3MENU[Mmax].typ=MENUTEXT;
	D3MENU[Mmax].txt=txt;
	D3MENU[Mmax].opt=(char **)opt;
	D3MENU[Mmax].var=0;
	D3MENU[Mmax].maxvalue=0;
	Mmax++;
}

/*------------------------------------------- Declaration TextR ------------------------------------------------------*/
void DrawTextR(int x,int y,DWORD color,char *text)
{
    RECT rect, rect1, rect2, rect3, rect4, rect5;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect1, x-1, y, x-1, y );
    SetRect( &rect2, x, y, x, y );
	SetRect( &rect3, x, y+1, x, y+1 );
    SetRect( &rect4, x, y, x, y );
	SetRect( &rect5, x - 0.1, y + 0.2, x - 0.1, y + 0. );
	pFont->DrawTextA(NULL,text,-1,&rect5, DT_LEFT|DT_NOCLIP, color );
    pFont->DrawTextA(NULL,text,-1,&rect,  DT_LEFT|DT_WORDBREAK, BLACK );
	pFont->DrawTextA(NULL,text,-1,&rect1, DT_LEFT|DT_WORDBREAK, BLACK );
	pFont->DrawTextA(NULL,text,-1,&rect2, DT_LEFT|DT_WORDBREAK, BLACK );
	pFont->DrawTextA(NULL,text,-1,&rect3, DT_LEFT|DT_WORDBREAK, BLACK );
	pFont->DrawTextA(NULL,text,-1,&rect4, DT_LEFT|DT_WORDBREAK, BLACK );
}

/*------------------------------------------- Declaration TextL ------------------------------------------------------*/
void DrawTextL(int x,int y,DWORD color,char *text)
{
	RECT rect, rect1, rect2, rect3, rect4, rect5;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect1, x-1, y, x-1, y );
    SetRect( &rect2, x, y, x, y );
	SetRect( &rect3, x, y+1, x, y+1 );
    SetRect( &rect4, x, y, x, y );
	SetRect( &rect5, x - 0.1, y + 0.2, x - 0.1, y + 0. );
	pFont->DrawTextA(NULL,text,-1,&rect5, DT_RIGHT|DT_NOCLIP, color );
    pFont->DrawTextA(NULL,text,-1,&rect,  DT_RIGHT|DT_WORDBREAK, BLACK );
	pFont->DrawTextA(NULL,text,-1,&rect1, DT_RIGHT|DT_WORDBREAK, BLACK );
	pFont->DrawTextA(NULL,text,-1,&rect2, DT_RIGHT|DT_WORDBREAK, BLACK );
	pFont->DrawTextA(NULL,text,-1,&rect3, DT_RIGHT|DT_WORDBREAK, BLACK );
	pFont->DrawTextA(NULL,text,-1,&rect4, DT_RIGHT|DT_WORDBREAK, BLACK );
}

/*------------------------------------------- Declaration TextC ------------------------------------------------------*/
void DrawTextC(int x,int y,DWORD color,char *text )
{
    RECT rect, rect2;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect2, x - 0.1, y + 0.2, x - 0.1, y + 0. );
	pFont->DrawTextA(NULL,text,-1,&rect2, DT_CENTER|DT_NOCLIP, 0x00000000 );
    pFont->DrawTextA(NULL,text,-1,&rect, DT_CENTER|DT_NOCLIP, color );
}

/*------------------------------------------- Declaration MenuShow ------------------------------------------------------*/
void MenuShow(float x, float y, LPDIRECT3DDEVICE9 pDevice)
{
	int i, val;
	DWORD color;
	DWORD texty;
	char text[100];
	if (!Mvisible) return;
	for (i=0; i<Mmax; i++) 
	{
		val=(D3MENU[i].var)?(*D3MENU[i].var):0;
		sprintf(text, "%s", D3MENU[i].txt);
		if (i==Mpos){
			if(RainbowTexts!=100)
			{RainbowR-=2,RainbowG-=3,RainbowB-=3;}
			if(RainbowTexts!=255)
			{RainbowR+=2,RainbowG+=3,RainbowB+=4;}
			color=RainbowTextTest;
			texty=RainbowTextTest;
			sprintf(text, "%s", D3MENU[i].txt);
		}
		else if (D3MENU[i].typ==MENUFOLDER){
			color=COLORFOLDER;
			texty=COLORFOLDER;
		}
		else if (D3MENU[i].typ==MENUTEXT){
			color=COLORTEXT;
			texty=COLORTEXT;
		}
		else{
			color=(val)?COLORON:COLOROFF;
			texty=(val)?COLORCURENT:COLORCURENT;
		}
		if (D3MENU[i].opt)
		{
			if (D3MENU[i].typ==MENUITEM){
				DrawTextL(x+3, y, texty,text);
				y = y + 2;
			}else{
				DrawTextL(x+3, y, texty,text);
			}
		}
		if (D3MENU[i].opt) {
			if (D3MENU[i].typ==MENUTEXT)
				DrawTextR((x+Mxofs), y, color,(char *)D3MENU[i].opt);
			else
				DrawTextR((x+Mxofs), y, color,(char *)D3MENU[i].opt[val]);
		}
		y+=Mysize;
	}
}

/*------------------------------------------- Declaration MenuNavigation ------------------------------------------------------*/
void MenuNav(void)
{
	if (IsKeyPressed(VK_INSERT, 0)&1)
	{
		Mvisible=(!Mvisible);
	}
	if (!Mvisible) return;
	if (IsKeyPressed(VK_UP, 0)&1) {
		do {
			Mpos--;
			if (Mpos<0)  Mpos=Mmax-1;
		} 
		while (D3MENU[Mpos].typ==MENUTEXT);	
	}else if (IsKeyPressed(VK_DOWN, 0)&1) {
		do {
			Mpos++;
			if (Mpos==Mmax) Mpos=0;
		} while (D3MENU[Mpos].typ==MENUTEXT);		
	} else if (D3MENU[Mpos].var) {
		int dir=0;
		if ( ( IsKeyPressed(VK_LEFT, 0)&1 ) && *D3MENU[Mpos].var > 0 ) dir=-1;
		if ( ( IsKeyPressed(VK_RIGHT, 0)&1 ) && *D3MENU[Mpos].var < (D3MENU[Mpos].maxvalue-1)) dir=1;
		if (dir) {
			*D3MENU[Mpos].var += dir;
			if (D3MENU[Mpos].typ==MENUFOLDER) Mmax=0;
			if (D3MENU[Mpos].typ==MENUCAT) Mmax=0;  
		}
	}
}

/*------------------------------------------- Declaration Date ------------------------------------------------------*/
char* GetDate()
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	char *logbuf = new char[ 256 ];
	sprintf(logbuf,": %d-%d-%d" ,st.wDay,st.wMonth,st.wYear);
	return logbuf;
}

/*------------------------------------------- Declaration Time ------------------------------------------------------*/
char* GetTime()
{
	struct tm * current_tm;
	time_t current_time;
	time (&current_time);
	current_tm = localtime(&current_time);
	char *logbuf = new char[ 256 ];
	sprintf(logbuf, ": %02d:%02d:%02d", current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec );
	return logbuf;
}

/*------------------------------------------- Declaration Menu ------------------------------------------------------*/
void RebuildMenu(LPDIRECT3DDEVICE9 pDevice)
{
/*------------------------------------------- Declaration Title ------------------------------------------------------*/
	AddText("Product"		,"www.SadamCyber419.com");
	AddText("V~VIP VCC HACK"		,"PBGI @2016");
/*------------------------------------------- Declaration D3D ------------------------------------------------------*/
	AddItem("(Direct_D3D)"			, Moptfolder, &Direct_D3D		, 2, MENUFOLDER);
	if(Direct_D3D)
	{
	  AddText("[Date]"												, GetDate());
	  AddText("[Time]"												, GetTime());
	  AddItem("[Wallhack Clean]"		    , Moptonoff,  &WHClean			, 2,  MENUCAT);// Khusus PB Indo
	  AddItem("[No Smoke]"		    , Moptonoff,  &DontSmoke		, 2,  MENUCAT);
	  AddItem("[CrossHair]"		    , MoptCross,  &Cross			, 2,  MENUCAT);
	  AddItem("[Esp.B o n e]"				, Moptonoff,  &ESPBone			, 2,  MENUCAT);
	  AddItem("[Esp.Health]"				, Moptonoff,  &ESPHealth		, 2,  MENUCAT);
	  AddItem("[Esp.Name]"				, Moptonoff,  &ESPName			, 2,  MENUCAT);
    }

	AddItem("(Direct_HOT)"			, Moptfolder, &Direct_HOT		, 2, MENUFOLDER);
	if(Direct_HOT)
	{
	  AddItem("[Aim Lock Target]"		, MoptTarget, &AimBody			, 2,  MENUCAT);
	  AddItem("[Aim Pelor]"			, MoptAimPel, &Accuracy			, 2,  MENUCAT);
	  AddItem("[Auto HS]"			    , MoptAutoHS, &AutoHS2			, 2,  MENUCAT);
	  AddItem("[Auto Shot][NEW]"			, Moptonoff,  &AutoShot			, 2,  MENUCAT);
	  AddItem("[Bullet Killer Real]"	, Moptonoff,  &BulletCall		, 2,  MENUCAT);
	  AddItem("[Plant Bomb]"			, Moptplant,  &BombEnywhere		, 3,  MENUCAT);
	  AddItem("[No Recoil]"			, Moptonoff,  &antigyg			, 2,  MENUCAT);
	  AddItem("[Ammo Right]"			, Moptonoff,  &wutmo			, 2,  MENUCAT);
	  AddItem("[BUG No Clip]"		    , Moptonoff,  &BugDt			, 2,  MENUCAT);
	  AddItem("[BUG Unyu Unyu]"		, Moptonoff,  &BugWS			, 2,  MENUCAT);
	}

	AddItem("(Direct_PLAYER)"		, Moptfolder, &Direct_PLAYER    , 2, MENUFOLDER);
	if(Direct_PLAYER)
	{
	  AddItem("[Fall Damage]"			, Moptonoff,  &FallDamage		, 2,  MENUCAT);
	  AddItem("[Repeat Back]"		    , Moptonoff,  &Rspw				, 2,  MENUCAT);
	  AddItem("[Fast Reload]"		    , Moptonoff,  &Nrld				, 2,  MENUCAT);
	  AddItem("[Fast Change]"			, Moptonoff,  &qece				, 2,  MENUCAT);
	  AddItem("[Fast Knife]"		    , Moptonoff,  &BstPs			, 2,  MENUCAT);
	  AddItem("[RapidFire]"		    , Moptonoff,  &frpid			, 2,  MENUCAT);
	  AddItem("[FastShot]"		    , Moptonoff,  &FsSht			, 2,  MENUCAT);
	  AddItem("[Free Move]"		    , Moptonoff,  &FreeMove			, 2,  MENUCAT);
	  AddItem("[Anti Idle]"		    , Moptonoff,  &AntiOut			, 2,  MENUCAT);
	  AddItem("[Skill GM]"		    , MoptRank1,  &autoGM			, 2,  MENUCAT);
	  AddItem("[Jumping]"				, Moptonoff,  &JumpHight		, 2,  MENUCAT);
	  AddText("[Suicide]"			    ," [Jalan Pintas Tekan 'END']");
	  AddText("[Exit Game]"			," [Jalan Pintas Tekan 'F12']");
	}

	AddItem("(Direct_SPECIAL)"		, Moptfolder, &Direct_SPECIAL   , 2, MENUFOLDER);
	if(Direct_SPECIAL)
	{
	  AddItem("[Fake Replace]"		, MoptFake ,  &On				, 2,  MENUCAT);
	  AddItem("[Fake Rep No F2]"		, Moptonoff,  &BrustMode		, 2,  MENUCAT);
	  AddText("[Fake Rep No F2]"		," [Pertama Tama On Kan Dulu Fake Replace Lalu Tekan 'F2']");
	  AddText("________________"					,"  [Terus On Kan Fake Rep No F2 Tekan 'Klik Kiri']");
	  AddText("________________"					,"  [Fiture Ini Khusus Brutal Mode]");
	  AddItem("[Replace Launcher]"	, MoptLauncher,&R_Launcher		, 9,  MENUCAT);
	  AddItem("[Replace Grenade]"		, MoptGrenade,&Rep_Item			, 8,  MENUCAT);
	  AddItem("[Ghost Zombie]"		, MoptZombie, &Zombie			, 2,  MENUCAT);
	  AddItem("[Ghost Killerz]"		, MoptGhost,  &Ghost			, 2,  MENUCAT);
//	  AddItem("Auto Kill (Madness)"	, Moptonoff,  &AutoKill			, 2,  MENUCAT);
	  AddItem("[Smoke Killerz]"		, Moptonoff,  &SmokeCall		, 2,  MENUCAT);
	  AddItem("[WallShot]"			, Moptonoff,  &WShoot			, 2,  MENUCAT);
	  AddItem("[Invicible Time]"		, Moptonoff,  &BP_Invi			, 2,  MENUCAT);
//	  AddItem("Magnet"				, Moptonoff,  &Magnet			, 2,  MENUCAT);// Jangan Pasang Fiture Magnet di Base Ini Karena Magnetnya On Sendiri Ntar Pas Baru Main :v
	  AddItem("[Freeze Respawn]"		, Moptonoff,  &NoLife			, 2,  MENUCAT);
//	  AddText("Fast Kill DM"		,"Jalan Pintas Tekan 'F9' Untuk On/Off");
//	  AddText("Fast Kill BM"		,"Jalan Pintas Tekan 'F10' Untuk On/Off");
	}
	{
	  AddText("[Credit By]~>"			,"[Muhammad Sadam S]");
	  AddText("[My Blog]~>"			," [www.Sadamcyber419.blogspot.com]"); 
  	  AddText("[JIKA CHEAT ADA KEKURANGAN ATAU EROR SILAHKAN HUB ADMIN]~>[MUHAMMAD SADAM S] "		,"[TRIAL 3 HARI]"); 
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
