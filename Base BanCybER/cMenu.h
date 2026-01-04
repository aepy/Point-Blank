/*cMenu.h D3D9 PBHacks Last Edit By BanCyberz Hacks*/
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
char *Moptfolder          []   = {"Open", "Close"}; 
char *Moptonoff           []   = {"•", "On"};
char *Moptono             []   = {"•", "On", "On"};
char *MoptDsb			  []   = {"Perbaikan"};
char *MoptTarget		  []   = {"Head", "Body"};
char *MoptKiller		  []   = {"•", "WP Smoke", "Bomb Kill"};
char *Moptplant		      []   = {"•", "Site Bomb A", "Site Bomb B"};
char *MoptRank			  []   = {"•", "Blank", "GM"};
char *MoptRpp			  []   = {"•", "HK-69", "K201 Ext", "Famas G2 C", "AK47 FC", "RPG-7", "RPG-7 (3)"};
char *MoptBeret			  []   = {"•", "Assault", "Submachinegun", "Shootgun", "Sniper", "Pistol", "Best Clan", "Red Star", "Yellow Star", "Cross Knife", "GM", "Bope", "General", "PBNC5", "Kopassus"};
char *MoptHedger		  []   = {"•", "Tracking ++", "Tracking Red ++"};

/*-------------------------------------------------------------------------------------------------------------------*/
#define 		MENUMAXINDEX	100
#define 		MENUFOLDER		1
#define 		MENUTEXT		2
#define 		MENUITEM		3
#define			MENUCAT			4
#define			COLORFOLDER		D3DCOLOR_ARGB(255, 127, 255, 212)
#define			COLORTEXT		D3DCOLOR_ARGB(255, 255, 255, 000)
#define			COLORON			D3DCOLOR_ARGB(255, 255, 255, 255)
#define			COLOROFF		D3DCOLOR_ARGB(255, 245, 000, 000)
#define			COLORCURENT		D3DCOLOR_ARGB(255, 255, 255, 255)

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
			sprintf(text, "=> %s", D3MENU[i].txt);
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
	AddText("V~vip Cyber Crekerz"		,"Update @2016");
	AddText("Admin : Muhammad sadam s"	,"www.SadamCyber419.Blogspot.com");
/*------------------------------------------- Declaration D3D ------------------------------------------------------*/
	AddItem("Visual Menu"			, Moptfolder, &Direct_D3D		   , 2, MENUFOLDER);
	if(Direct_D3D)
	{
	  AddText("Date"												, GetDate());
	  AddText("Time"												, GetTime());
	  AddItem("Wallhack Bersih"		, Moptonoff, &WHClean			, 2,  MENUCAT);
	  AddItem("Wallhack Robot"		, Moptonoff, &WHRobot			, 2,  MENUCAT);
	  AddItem("Champ Rainbow"		, Moptonoff, &Chams				, 2,  MENUCAT);
	  AddItem("NoFog & Smoke"		, Moptonoff, &DontSmoke			, 2,  MENUCAT);
	  AddItem("CrossHair"		    , Moptonoff, &Cross				, 2,  MENUCAT);
    }

	AddItem("Menu Esp"			, Moptfolder, &Direct_ESP		   , 2, MENUFOLDER);
	if(Direct_ESP)
	{
	  AddItem("Esp Name"		    , Moptonoff,  &ESPName			, 2,  MENUCAT);
	  AddItem("Esp Health"		    , Moptonoff,  &ESPHealth		, 2,  MENUCAT);
	  AddItem("Esp Head"		    , Moptonoff,  &ESPHead			, 2,  MENUCAT);
	  AddItem("Esp Bone"		    , Moptonoff,  &ESPBone			, 2,  MENUCAT);
	}

	AddItem("Menu Aim"			, Moptfolder, &Direct_HOT		   , 2, MENUFOLDER);
	if(Direct_HOT)
	{
	  AddItem("Target Bone"		    , MoptTarget, &AimBody			, 2,  MENUCAT);
	  AddItem("AimBot"				, Moptonoff,  &AimHead			, 2,  MENUCAT);
	  AddText("AimBot"				,"Jalan Pintas Tekan 'Alt Kanan' Untuk On/Off");
	  AddItem("AimBullet"			, Moptonoff,  &Accuracy			, 2,  MENUCAT);
	  AddText("AimBullet"			,"Jalan Pintas Tekan 'Shift Kiri' Untuk On/Off");
	  AddItem("Auto HS"			    , Moptonoff,  &AutoHS2			, 2,  MENUCAT);
	  AddText("Auto HS"				,"Jalan Pintas Tekan 'Capslock' Untuk On/Off");
	  AddItem("Auto Body"			, Moptonoff,  &AutoBody			, 2,  MENUCAT);
	  AddText("Auto Body"			,"Jalan Pintas Tekan 'Shift Kanan' Untuk On/Off");
	  AddItem("AutoShoot"			, Moptonoff,  &AutoShot			, 2,  MENUCAT);
	}

	AddItem("Menu Player"			, Moptfolder, &Direct_PLAYER    , 2, MENUFOLDER);
	if(Direct_PLAYER)
	{
	  AddItem("Rank Hack"		    , MoptRank,   &autoGM			, 3,  MENUCAT);
	  AddItem("Free Plant C4"		, Moptplant,  &BombEnywhere		, 3,  MENUCAT);
	  AddItem("Bug Hand"		    , Moptonoff,  &BugWS			, 2,  MENUCAT);
	  AddText("Bug Hand"			,"Jalan Pintas Tekan 'F6' Untuk On/Off");
	  AddItem("Bug Datar"		    , Moptonoff,  &BugDt			, 2,  MENUCAT);
	  AddText("Bug Datar"			,"Jalan Pintas Tekan 'F7' Untuk On/Off");
	  AddItem("Repeat Back"		    , Moptonoff,  &Rspw				, 2,  MENUCAT);
	  AddItem("Fall Damage"			, Moptonoff,  &FallDamage		, 2,  MENUCAT);
	  AddItem("Anti Idle"		    , Moptonoff,  &AntiOut			, 2,  MENUCAT);
	  AddItem("Free Move"		    , Moptonoff,  &FreeMove			, 2,  MENUCAT);
	  AddItem("Ghost Hide"		    , Moptonoff,  &Zombie			, 2,  MENUCAT);
	  AddText("Ghost Hide"			,"Jalan Pintas Tekan 'Alt Kiri' Untuk On/Off");
	  AddText("Suicide"			    ,"Jalan Pintas Tekan 'END'");

	}

	AddItem("Menu Weapon"			, Moptfolder, &Direct_WEAPON    , 2, MENUFOLDER);
	if(Direct_WEAPON)
	{
	  AddItem("No Recoil"			, Moptonoff,  &antigyg			, 2,  MENUCAT);
	  AddItem("Reload Skill"		, Moptonoff,  &RldM				, 2,  MENUCAT);
	  AddItem("No Reload"		    , Moptonoff,  &Nrld				, 2,  MENUCAT);
	  AddItem("Fast Shoot"		    , Moptonoff,  &FsSht			, 2,  MENUCAT);
	  AddItem("Inf Ammo"			, Moptonoff,  &wutmo			, 2,  MENUCAT);
	  AddItem("Burst Knife"		    , Moptonoff,  &BstPs			, 2,  MENUCAT);
	  AddItem("Quick Change"		, Moptonoff,  &qece				, 2,  MENUCAT);
	  AddItem("Rapid Fire"		    , Moptonoff,  &frpid			, 2,  MENUCAT);
	  
	}

	AddItem("Menu BoomBerman"	    , Moptfolder, &Direct_WEAPON    , 2, MENUFOLDER);
	if(Direct_WEAPON)
	{
	  AddItem("BoomBerman"			, Moptonoff,  &antigyg			, 2,  MENUCAT);
	  AddItem("Brust BoomBer"		, Moptonoff,  &RldM				, 2,  MENUCAT);
	  AddItem("Hit Boomber"		    , Moptonoff,  &Nrld				, 2,  MENUCAT);
	  AddItem("Auto Lempar Boomber"	, Moptonoff,  &FsSht			, 2,  MENUCAT);
	  /*------------------------------------------- Declaration Title ------------------------------------------------------*/
	  AddText("Tutorial BoomBerman" , " 1.Aktifkan BoomBerman Trus Tekan F3");
      AddText(" "                   , " 2.Tekan 5 Trus Aktifkan Brust BoomBer ");
      AddText(" "                   , " 3.Aktifkan Hit BoomBer");
	  AddText(" "                   , " 4.Aktifkan Auto Lempar");
	  AddText(" "                   , "Nb: Jangan Terlalu Lama Aktifkan BoomBer Nya Agar Tidak DC ");

	}
	/*------------------------------------------- Declaration Title ------------------------------------------------------*/
	  AddText("Exit Game"           , " Wajib Tekan F12");
}

/*-------------------------------------------------------------------------------------------------------------------*/
