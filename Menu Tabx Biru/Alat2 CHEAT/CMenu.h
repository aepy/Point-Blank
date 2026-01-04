#include "StandardIncludes.h"
#include "CFont.h"
#include "CTools.h"


#pragma once

#define ITEM_ARRAY 64 // Maximum of 64 Items change to reduce Static address size

// ============ SOME CALCULATION MACROS FOR LONG CALCULATIONS ================
// ============                THE PREFIX IS MC				  ================
#define MC_MAXX					(X+WIDTH)												// X of Menu + Width
#define MC_FCTR(x,y)			((x+y)/2)												// Calculate Center Point Between two items
#define MC_ITEMY(index)			(Y+(index*I_SPC)+T_SPC+(T_SPC/2))						// Calculate Y of Item using Index or calculate Menu Maximum Y
#define MC_ITEMY1(index)		(Y+(index*I_SPC)+T_SPC+(T_SPC/2)-1)
#define MC_ITEMY2(index)		(Y+(index*I_SPC)+T_SPC+(T_SPC/2)+20)
#define MC_ITEMY3(index)		(Y+(index*I_SPC)+T_SPC+(T_SPC/2)+41)
#define MC_ITEMY4(index)		(Y+(index*I_SPC)+T_SPC+(T_SPC/2)+60)
#define MC_ITEMY5(index)		(Y+(index*I_SPC)+T_SPC+(T_SPC/2)+81)
#define MC_MSY					(Y+T_SPC+(T_SPC/2))

// ============ Menu Manger Class ================
class cMenu{

public:

//-----------------------------------------------------------------------------
// Desc: Item Index Structure
//-----------------------------------------------------------------------------
	struct sitem{
			char title[50];		// Name Of Item to Display
			char state[50];	// States of Item
			int	 type;			// Type of Item ie. Cat , Items
			int  max;			// Number of States
			int  no;			// number inside the Array
			int	 *val;			// Variable Being Controlled
	} items[ITEM_ARRAY];
//-----------------------------------------------------------------------------
// Desc: Item Color Enumeration
//-----------------------------------------------------------------------------
	enum COLORS{  // Normal Colors
#define WHITE			D3DCOLOR_ARGB(255,255,255,255)
#define RED				D3DCOLOR_ARGB(255,255,000,000)
#define GREEN			D3DCOLOR_ARGB(255,000,255,000)
#define BLUE			D3DCOLOR_ARGB(255,000,000,255)
#define BLACK			D3DCOLOR_ARGB(255,000,000,000)
#define TRANSBLACK      D3DCOLOR_ARGB(225,000,000,000)
#define PURPLE			D3DCOLOR_ARGB(255,125,000,255)
#define GREY			D3DCOLOR_ARGB(255,128,128,128)
#define YELLOW			D3DCOLOR_ARGB(255,255,255,000)
#define ORANGE			D3DCOLOR_ARGB(255,255,125,000)
#define WHITE2			D3DCOLOR_ARGB(100,255,255,255)
#define RED2			D3DCOLOR_ARGB(100,255,000,000)
#define GREEN2			D3DCOLOR_ARGB(100,000,255,000)
#define BLUE2			D3DCOLOR_ARGB(100,000,000,255)
#define BLACK2			D3DCOLOR_ARGB(100,000,000,000)
#define PURPLE2			D3DCOLOR_ARGB(100,125,000,255)
#define GREY2			D3DCOLOR_ARGB(100,128,128,128)
#define YELLOW2			D3DCOLOR_ARGB(100,255,255,000)
#define ORANGE2			D3DCOLOR_ARGB(100,255,125,000)
#define BROWN           D3DCOLOR_ARGB(255,77,46,38)
#define CYAN			D3DCOLOR_ARGB(255,255,255,000)
#define PINK            D3DCOLOR_ARGB(255,255,192,203)
#define SKYBLUE         D3DCOLOR_ARGB(255,0,180,255)
#define DARKGRAY        D3DCOLOR_ARGB(255,71,65,64)
	};
//-----------------------------------------------------------------------------
// Desc: Item Color Enumeration
//-----------------------------------------------------------------------------
	enum I_COLORS{  // Item Colors
		C_OFF	 =	D3DCOLOR_ARGB(255,255,255,255),//ini warna pada nama fitur saat keadaan [OFF]
		C_ON	 =  D3DCOLOR_ARGB(255,0,180,255),//ini warna pada nama fitur saat keadaan [ON]
		C_OFF2	 =	D3DCOLOR_ARGB(255,255,255,255),//ini warna pada [OFF]
		C_OFF3	 =	D3DCOLOR_ARGB(255,255,255,000),//warna kotak aitem pada saat [OFF]
		C_ON2	 =  D3DCOLOR_ARGB(255,0,180,255),//warna kotak aitem pada saat [ON]
		C_CAT	 =	D3DCOLOR_ARGB(255,0,180,255),//ini warna pada nama folder [OPEN]|[CLOSE]
		C_INFO	 =	D3DCOLOR_ARGB(255,255,255,255),//tidak diketahui
		C_INFO2	 =	D3DCOLOR_ARGB(255,255,255,255),//tidak diketahui
		C_CUR	 =	D3DCOLOR_ARGB(255,0,180,255),//warna block folder saat pindah
		C_FOOTER =	D3DCOLOR_ARGB(255,255,255,255),//tidak diketahui
		C_TITLE	 =	D3DCOLOR_ARGB(255,255,255,255)//warna pada judul
	};
//-----------------------------------------------------------------------------
// Desc: BackGround Color Enumeration
//-----------------------------------------------------------------------------
	enum BK_COLORS{ // BackGround Colors
		C_BOX    = D3DCOLOR_ARGB(255, 000, 000, 000), //Box
		C_BOX2   = D3DCOLOR_ARGB(255, 000, 000, 000), //Box
		C_BORDER = D3DCOLOR_ARGB(255,0,180,255) //Border
	};

//-----------------------------------------------------------------------------
// Desc: Menu Types Enumeration
//-----------------------------------------------------------------------------

	enum I_TYPES{
		T_TEXT = 0,
		T_ITEM = 1,
		T_CAT  = 2
	};

//-----------------------------------------------------------------------------
// Desc: Class Global Variables
//-----------------------------------------------------------------------------

	CD3DFont *font;
	bool FontCreated;
	int  X,Y;			// TOP LEFT OF MENU
	POINT mofs;			// Offset From Mouse Last Point
	POINT mpos;			// Mouse Coordinates
	int  M_DRAG;		// is Menu Being Dragged
	int  WIDTH;			// Width of Menu
	int  I_OFS,S_OFS;	// Item Title Column Start
	int  I_SPC,I_TSPC;  // Title Spacing and Item Spacing
	int  T_SPC,F_SPC;	// Title Spacing from Menu Items and Footer Spacing
	int  NO;			// Number of Menu Items
	int  I_CUR;			// Current Menu Item
	bool SHOW;			// Is menu shown
	bool INIT;			// Has Menu Been Setup

//-----------------------------------------------------------------------------
// Desc: Class Global Functions
//-----------------------------------------------------------------------------

	void	DrawBox( int x, int y, int w, int h, D3DCOLOR Color,LPDIRECT3DDEVICE9 pDevice);
	void	DrawBorder(int x, int y, int w, int h, int s, D3DCOLOR Color, LPDIRECT3DDEVICE9 device);
	void	DrawGameTextPixelFlag(int x, int y, DWORD color, DWORD flags, char *szFormat, ... );
	char*	oprintf (const char *fmt, ...);
	void	PostReset(LPDIRECT3DDEVICE9 pDevice);
	void	PreReset(void);
    char*	FPS(int en = 1);
	char*	TIME(void);
	char*	DATE(void);
	void	ShowMenu(LPDIRECT3DDEVICE9 pDevice);
	void	ShowBox(LPDIRECT3DDEVICE9 pDevice);

//-----------------------------------------------------------------------------
private:

//-----------------------------------------------------------------------------
// Desc: Class Private Functions
//-----------------------------------------------------------------------------
	void	acat(char *title, char *states, int *var);
	void	aitem(char *title, char *states,int *var, int show, int when);
	void	atext(char *title, char *states,int show, int when);
	void	atext(char *title, char *states);
	void	additem(char *title, char *states,int type, int *var, int show, int when);
	void	getfield(char *str,char *dst,int no);
	int		nofields(char *str);
	void	Init(void);
	int		Load(char* szSection, char* szKey, int iDefaultValue,LPCSTR file);
	void	Save(char* szSection, char* szKey, int iValue,LPCSTR file);

//-----------------------------------------------------------------------------


};
extern cMenu Menu;

// Item Manager Struct
struct copt{
//Global Variables
int text; // Text Items
		struct sinfo{
			    int main;
				int main1;
				int main2;
				int main3;
				int main4;
				int main5;
				int main6;
		}info;
		struct sd3d{
			    int main;
				int Chams;
				int cross;
				int asus;
				int naked;
				int flash;
				int smoke;
				int scope;
				int fbright;
				/*------------------*/
	int WHClean;
	int WHRobot;
	int CROSS;
	int DontSmoke;
	int chamsWeapon;
	int NoFog;
	/*------------------*/
		}d3d;
			/*------------------*/
		struct ccoba{
	int main;
	int ESPHealth;
	int ESPHealth2;
	int ESPHealth3;
	int ESPLine;
	int ESPObserver;
	int ESPDistance;
	int ESPKD;
	int ESPBox;
	int ESPName;
	int ESPRank;
	int ESPBone;
	}ccoba;
			struct cPlayer{
	int main;
	int VoteKick;
	int PlayerSpeed;
	int UnHP;
	int autoGM;
	int WallBug;
	int BugLuxivile;
	int FreeMove;
	int Rspw;
	int CallFlyHack;
	int Freeze;
	int AntiOut;
	int JumpHight;
	int UNYU;
	int BombEnywhere;
	}cPlayer;
			struct cWeapon{
	int main;
	int frspd;
	int HiddenWeapon;
	int KnifeKill;
	int RapidFire;
	int Reload;
	int QuickChange;
	int FastShot;
	int Recoil;
	int BrustKnife;
	int Ammo;
	}cWeapon;
			struct cKiller{
	int main;
	int CallTele;
	int TellePlayer;
	int WsHt;
	int PisoTeleKill1;
	int PisoTeleKill;
	int DamagePisoTeleKill;
	int BulletCall;
	int DamageBombKill;
	int BombKill;
	int Invincible;
	int Zombie;
	int Switch;
	int FastBM;
	int FastDM;
	}cKiller;
			struct cAmmo{
	int main;
	int ammoroll;
	int AmmoHK69A;
	int AmmoRPG;
	int AmmoLC;
	int AmmoSmoke;
	int AmmoBomb;
	}cAmmo;
			struct cSpesial{
	int main;
	int FakeReplace;
	int smk;
	int Beret;
	int lchr;
	int ram;
	int AutoAja;
	}cSpesial;
		struct soptions{
				int main;
				int move;
				int reset;
				int save;
				int load;
		}options;
		struct wAim{
				int cAim;
				int Accuracy;
				int AutoShot;
				int AutoFire;
				int AutoHS2;
				int AimBody;
		}ModAim;
};
extern copt opt;
