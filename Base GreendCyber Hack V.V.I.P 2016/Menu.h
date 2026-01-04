#include <Windows.h>
#include <stdio.h>
#include <fstream>
#include <d3dx9.h>
#include <d3d9.h>
#include <time.h>
//==========pragma comment========
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "Winmm.lib")
#pragma warning(disable:4996 4244)
#pragma warning(disable:4700 4293 4554)
#define WIN32_LEAN_AND_MEAN
//-------------------------------------------------------------------------------
#ifndef D3DFONT_RIGHT
#define D3DFONT_RIGHT		0x0008
//#endif

#define 	MENUMAXITEMS	100
#define 	MENUFOLDER		1
#define 	MENUTEXT		2
#define 	MENUITEM		3
#define		MENUCAT			4

typedef struct {
  int  typ;		
  char *txt;	
  char **opt;	
  int  *var;	  
  int  maxvalue;
} tMENU;

class D3D9Menu
{
public:
	D3D9Menu(char *Title = 0)
	{
		Mtitle=Title;	 
		Mpos=0;			
		Mmax=0;		
		Mxofs =170.0f;	// jarak text ke samping
		Mysize=15.0f;	// jarak text ke atas
		Mvisible=1;
		MENU=(tMENU **)malloc(4*MENUMAXITEMS);
		for (int i=0; i<MENUMAXITEMS; i++) MENU[i]=(tMENU *)malloc(sizeof(tMENU));
	}
	~D3D9Menu() {
		for (int i=0; i<MENUMAXITEMS; i++) free(MENU[i]);
		free(MENU);
	}

	int		Mmax;
	int		Mvisible;
	tMENU		**MENU;
	void AddItem(char *txt, char **opt, int *var, int maxvalue);
	void AddFolder(char *txt, char **opt, int *var, int maxvalue);
	void AddCategory(char *txt, char **opt, int *var, int maxvalue);
	void MenuAdd(char *txt, char **opt, int *var, int maxvalue, int typ);
		void  DrawBox12(LPDIRECT3DDEVICE9 pDevice, int x, int y, int w, int h, D3DCOLOR color);
	void  DrawBorder12(int x, int y, int w, int h, int px,D3DCOLOR col ,LPDIRECT3DDEVICE9 pDevice);
	void  DrawBox13(LPDIRECT3DDEVICE9 pDevice, int x, int y, int w, int h, D3DCOLOR color);
	void  DrawBorder13(int x, int y, int w, int h, int px,D3DCOLOR col ,LPDIRECT3DDEVICE9 pDevice);
	void  DrawMenu11(int x, int y, int w, int h, int px,D3DCOLOR col1,D3DCOLOR col2, LPDIRECT3DDEVICE9 pDevice);
	void  DrawMenu12(int x, int y, int w, int h, int px,D3DCOLOR col1,D3DCOLOR col2, LPDIRECT3DDEVICE9 pDevice);
	void  DrawMenu13(int x, int y, int w, int h, int px,D3DCOLOR col1,D3DCOLOR col2, LPDIRECT3DDEVICE9 pDevice);
	void PrintTextv2(char pString[], int x, int y, D3DCOLOR col, ID3DXFont *font,LPDIRECT3DDEVICE9 pDevice);
	void PrintTextv1(char pString[], int x, int y, D3DCOLOR col, ID3DXFont *font,LPDIRECT3DDEVICE9 pDevice);
	void MenuShow(float x, float y, LPDIRECT3DDEVICE9 pDevice);
	void Crosshair(LPDIRECT3DDEVICE9 pDevice, D3DCOLOR Color);
	void AddText(char *txt, char *opt);
	void MenuNav(void);
	void DrawTextR(int x,int y,DWORD color,char *text);
	void DrawTextF(int x,int y,DWORD color,char *text);
	void DrawTextL(int x,int y,DWORD color,char *text);
	void DrawTextC(int x,int y,DWORD color,char *text);
	void DrawBox(LPDIRECT3DDEVICE9 pDevice, int x, int y, int w, int h);
	void FontCreate(LPDIRECT3DDEVICE9 pDevice);
//	void DrawBox12    (LPDIRECT3DDEVICE9 pDevice, int x, int y, int w, int h, D3DCOLOR Color);
//	void DrawBorder12 (int x, int y, int w, int h, int px,D3DCOLOR col ,LPDIRECT3DDEVICE9 pDevice);
//	void DrawMenu12   (int x, int y, int w, int h, int px,D3DCOLOR col1,D3DCOLOR col2, LPDIRECT3DDEVICE9 pDevice);
	BOOL Font();
	void OnLostDevice();
	void FontReset();
	BOOL _cInMenu();

private:
	
	char	*Mtitle;
	int 	Mpos;
	float	Mxofs;	  
	float	Mysize;	
	POINT posMenu;
	POINT maxMenu;
	int FindItem();
};
#endif


//-------------------------------------------------------------------------------
RECT rect,rect2,rect3;
ID3DXFont	*pFont1;
//-------------------------------------------------------------------------------
char *Moptfolder[2] = {"Buka", "Tutup"};
char *Moptonoff[2]   = {"Off", "On"};
char *Moptonof[2]   = {"Info", "Tutup"};
char *Moptonoff2[3]   = {"Off", "+", "*"};
char *Moptonoff3[2]   = {"Head", "Body"};
char *MoptReplace   [7] =  {"Select", "Famas","K-201 Exit","AK 47 FC","AK Sopmod R","SCAR D","M4 SR-16 FC"};
char *MoptReplaceHK		[3]  = {"Select", "HK-69","MK-79"};
char *MoptRep_Item  [7]  = {"Select", "Soccer","LolPop","Latern","Rotiw","OFS_Soccer","Decoy_Bomb"}; 

//-------------------------------------------------------------------------------
int MenuFolder[100];
int uyeh = 0;int RenderText = 1;int INFO=0;int Exite=0;
#define RHC WHITE 
int RH=250;
POINT  mpos;
CHAR TimeAndDate[MAX_PATH];
time_t TimeValue;
INT Fps = 0;
FLOAT LastTickCount = 0.0f;
FLOAT CurrentTickCount;
CHAR FrameRate[50] = "";
#define WHITE			D3DCOLOR_ARGB(255, 255, 255, 255)
#define GREEN			D3DCOLOR_ARGB(255, 000, 255, 000)

#define mBLACK			D3DCOLOR_ARGB(100, 000, 000, 205)
#define PURPLE			D3DCOLOR_ARGB(255, 125, 000, 255) 
#define GREY			D3DCOLOR_ARGB(255, 128, 128, 128) 
#define ORANGE			D3DCOLOR_ARGB(255, 255, 125, 000)
#define WHITE2			D3DCOLOR_ARGB(100, 255, 255, 255)
#define RED2			D3DCOLOR_ARGB(100, 255, 000, 000)
#define GREEN2			D3DCOLOR_ARGB(100, 000, 255, 000)
#define BLUE2			D3DCOLOR_ARGB(100, 000, 000, 255) 
#define BLACK2			D3DCOLOR_ARGB(100, 000, 000, 000)
#define PURPLE2			D3DCOLOR_ARGB(100, 125, 000, 255) 
#define GREY2			D3DCOLOR_ARGB(100, 128, 128, 128) 
#define YELLOW2			D3DCOLOR_ARGB(100, 255, 255, 000) 
#define ORANGE2			D3DCOLOR_ARGB(100, 255, 125, 000)
#define WHITE           D3DCOLOR_ARGB(255, 255, 255, 255)
#define TEAL            D3DCOLOR_ARGB(255, 0, 255, 255)

#define LIME            D3DCOLOR_ARGB(255, 198, 255, 0)
#define SKYBLUE         D3DCOLOR_ARGB(255, 0, 180, 255)
#define MAROON          D3DCOLOR_ARGB(255, 142, 30, 0)
#define LGRAY           D3DCOLOR_ARGB(255, 174, 174, 174) 
#define DGRAY           D3DCOLOR_ARGB(255, 71, 65, 64) 
#define BROWN           D3DCOLOR_ARGB(255, 77, 46, 38)
#define SHIT            D3DCOLOR_ARGB(255, 74, 38, 38)
#define Biru	        D3DCOLOR_ARGB( 250, 25, 220, 251)
#define Biru	        D3DCOLOR_ARGB( 250, 25, 220, 251)

/********************************************************************************/

#define D3DFONT_BOLD 0x0000
char Mtitle[81];
char Mtitle1[81];


//-------------------------------------------------------------------------------
int				RainbowR2		= 255;
int				RainbowG2		= 255;
int				RainbowB2		= 255;
float			RainbowTexts2	= 255;
#define			RainbowTextTest2 D3DCOLOR_ARGB(255, RainbowR2, RainbowG2, RainbowB2)
//-------------------------------------------------------------------------------
void RainBow2(){
if(RainbowTexts2!=100)
{RainbowR2-=2,RainbowG2-=3,RainbowB2-=3;}
	}
//-------------------------------------------------------------------------------

void D3D9Menu::AddFolder(char *txt, char **opt, int *var, int maxvalue)
{
  MENU[Mmax]->typ=MENUFOLDER;
  MENU[Mmax]->txt=txt;
  MENU[Mmax]->opt=opt;
  MENU[Mmax]->var=var;
  MENU[Mmax]->maxvalue=maxvalue;
  Mmax++;
}

void D3D9Menu::AddCategory(char *txt, char **opt, int *var, int maxvalue)
{
  MENU[Mmax]->typ=MENUCAT;
  MENU[Mmax]->txt=txt;
  MENU[Mmax]->opt=opt;
  MENU[Mmax]->var=var;
  MENU[Mmax]->maxvalue=maxvalue;
  Mmax++;
}

void D3D9Menu::AddItem(char *txt, char **opt, int *var, int maxvalue)
{
  MENU[Mmax]->typ=MENUITEM;
  MENU[Mmax]->txt=txt;
  MENU[Mmax]->opt=opt;
  MENU[Mmax]->var=var;
  MENU[Mmax]->maxvalue=maxvalue;
  Mmax++;
}
void  D3D9Menu::DrawBox12(LPDIRECT3DDEVICE9 pDevice, int x, int y, int w, int h, D3DCOLOR color)
{
	D3DRECT rec;
	rec.x1 = x;
	rec.x2 = x + w;
	rec.y1 = y;
	rec.y2 = y + h;
	pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
} 
void  D3D9Menu::DrawBorder12(int x, int y, int w, int h, int px,D3DCOLOR col ,LPDIRECT3DDEVICE9 pDevice)
{
DrawBox12(pDevice,x+px,y+h-px,w-px-px,px,col);// Bottom
DrawBox12(pDevice,x,y,px,h,col); // Left
DrawBox12(pDevice,x+px,y,w-px-px,px,col); // TOP
DrawBox12(pDevice,x+w-px,y,px,h,col); // RIGHT
}
//-------------------------------------------------------------------------------
void  D3D9Menu::DrawBox13(LPDIRECT3DDEVICE9 pDevice, int x, int y, int w, int h, D3DCOLOR color)
{
	D3DRECT rec;
	rec.x1 = x;
	rec.x2 = x + w;
	rec.y1 = y;
	rec.y2 = y + h;
	pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}
//-------------------------------------------------------------------------------
void  D3D9Menu::DrawBorder13(int x, int y, int w, int h, int px,D3DCOLOR col ,LPDIRECT3DDEVICE9 pDevice)
{
DrawBox13(pDevice,x+px,y+h-px,w-px-px,px,col);// Bottom
DrawBox13(pDevice,x,y,px,h,col); // Left
//DrawBox13(pDevice,x+px,y,w-px-px,px,col); // TOP
DrawBox13(pDevice,x+w-px,y,px,h,col); // RIGHT
}
//-------------------------------------------------------------------------------
void  D3D9Menu::DrawMenu11(int x, int y, int w, int h, int px,D3DCOLOR col1,D3DCOLOR col2, LPDIRECT3DDEVICE9 pDevice)
{
	//DrawBox12(pDevice,x,y,w,h,col1);
    DrawBorder12 ( x,y,w,h,px,col2,pDevice);
}
//-------------------------------------------------------------------------------
void  D3D9Menu::DrawMenu12(int x, int y, int w, int h, int px,D3DCOLOR col1,D3DCOLOR col2, LPDIRECT3DDEVICE9 pDevice)
{
	DrawBox12(pDevice,x,y,w,h,col1);
    DrawBorder12 ( x,y,w,h,px,col2,pDevice);
}
//-------------------------------------------------------------------------------
void  D3D9Menu::DrawMenu13(int x, int y, int w, int h, int px,D3DCOLOR col1,D3DCOLOR col2, LPDIRECT3DDEVICE9 pDevice)
{
	DrawBox13(pDevice,x,y,w,h,col1);
    DrawBorder13 ( x,y,w,h,px,col2,pDevice);
}
void D3D9Menu::DrawTextR(int x,int y,DWORD color,char *text)
{
    RECT rect, rect2;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect2, x - 0.1, y + 0.2, x - 0.1, y + 0. );
	pFont1->DrawTextA(NULL,text,-1,&rect2, DT_LEFT|DT_NOCLIP, 0x00000000 );
    pFont1->DrawTextA(NULL,text,-1,&rect, DT_LEFT|DT_NOCLIP, color );
}
BOOL D3D9Menu::Font()
{
	if(pFont1)
		return FALSE;
	else return TRUE;
}

//_______________________Versi Edit:DwiYanto____________________
void D3D9Menu::FontCreate(LPDIRECT3DDEVICE9 pDevice)
{
	D3DXCreateFont(pDevice, 15, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype", &pFont1);
}
//_______________________________________________________________
void D3D9Menu::FontReset()
{
	pFont1->OnLostDevice();
	pFont1->OnResetDevice();
}

void D3D9Menu::OnLostDevice()
{
	pFont1->OnLostDevice();	
}
void D3D9Menu::PrintTextv2(char pString[], int x, int y, D3DCOLOR col, ID3DXFont *font,LPDIRECT3DDEVICE9 pDevice){
//DrawMenu12(x+Mxofs-155, y-2, Mxofs+300, Mysize+1, 2,RED,GREEN , pDevice);
RECT FontRect = { x, y, x+500, y+30 };
font->DrawText( NULL, pString, -1, &FontRect, DT_LEFT | DT_NOCLIP, col);
}
//-------------------------------------------------------------------------------
void D3D9Menu::PrintTextv1(char pString[], int x, int y, D3DCOLOR col, ID3DXFont *font,LPDIRECT3DDEVICE9 pDevice){
//DrawMenu13(x+Mxofs-155, y-2, Mxofs+300, Mysize+1, 1,BLACK,GREEN , pDevice);
RECT FontRect = { x, y, x+500, y+30 };
font->DrawText( NULL, pString, -1, &FontRect, DT_LEFT | DT_NOCLIP, col);
}
void D3D9Menu::DrawTextL(int x,int y,DWORD color,char *text)
{
    RECT rect, rect1, rect2, rect3, rect4, rect5;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect1, x-1, y, x-1, y );
	SetRect( &rect2, x+1, y, x+1, y );
	SetRect( &rect3, x, y-1, x, y-1 );
	SetRect( &rect4, x, y+1, x, y+1 );
	SetRect( &rect5, x - 0.1, y + 0.2, x - 0.1, y + 0. );
	pFont1->DrawTextA(NULL,text,-1,&rect5, DT_LEFT|DT_NOCLIP, color );// menunya arah ke tengah
    pFont1->DrawTextA(NULL,text,-1,&rect,  DT_LEFT|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect1, DT_LEFT|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect2, DT_LEFT|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect3, DT_LEFT|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect4, DT_LEFT|DT_NOCLIP, BLACK );
}

void D3D9Menu::DrawBox(LPDIRECT3DDEVICE9 pDevice, int x, int y, int w, int h)
{
	D3DRECT rec;
	rec.x1 = x;
	rec.x2 = x + w;
	rec.y1 = y;
	rec.y2 = y + h;
	pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, GREEN, 0, 0 );
} 

void D3D9Menu::AddText(char *txt, char *opt)
{
	MENU[Mmax]->typ=MENUTEXT;
	MENU[Mmax]->txt=txt;
	MENU[Mmax]->opt=(char **)opt;
	MENU[Mmax]->var=0;
	MENU[Mmax]->maxvalue=0;
	Mmax++;
}

void D3D9Menu::DrawTextC(int x,int y,DWORD color,char *text)
{
    RECT rect, rect2;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect2, x - 0.1, y + 0.2, x - 0.1, y + 0. );
	pFont1->DrawTextA(NULL,text,-1,&rect2, DT_CENTER|DT_NOCLIP, 0x00000000 );
    pFont1->DrawTextA(NULL,text,-1,&rect, DT_CENTER|DT_NOCLIP, color );
}


void D3D9Menu::Crosshair(LPDIRECT3DDEVICE9 pDevice, D3DCOLOR Color)
{
	    int size = 5, strong = 1;

		int iCenterX = GetSystemMetrics( 0 ) / 2;
		int iCenterY = GetSystemMetrics( 1 ) / 2;

		if( iCenterX < 20 && iCenterY < 20 )
		{
			iCenterX = ( GetSystemMetrics( 0 ) / 2 );
			iCenterY = ( GetSystemMetrics( 1 ) / 2 );
		}

		D3DRECT rec_a = { iCenterX - size, iCenterY, iCenterX + size, iCenterY + strong};
		D3DRECT rec_b = { iCenterX, iCenterY - size, iCenterX + strong,iCenterY + size};
		pDevice->Clear(1, &rec_a, D3DCLEAR_TARGET, Color, 0,  0);
		pDevice->Clear(1, &rec_b, D3DCLEAR_TARGET, Color, 0,  0);
}

void D3D9Menu::MenuShow(float x, float y, LPDIRECT3DDEVICE9 pDevice)
{
  int i, val;
  DWORD color;
  DWORD texty;
  char text[100];
  if (!Mvisible) return;
  for (i=0; i<Mmax; i++) {
	   val=(MENU[i]->var)?(*MENU[i]->var):0;
	   sprintf(text, "%s", MENU[i]->txt);
	   if (i==Mpos){
           color=RainbowTextTest;
		   texty=RainbowTextTest;
//		   CMenuItem_DrawCronersBox((INT)x - 0,(INT)y - 4,17,152, pDevice);
		   sprintf(text, "%s", MENU[i]->txt);
	   }
	   else if (MENU[i]->typ==MENUFOLDER){
		   
           color=RED;
	       texty=RED;
if (ColorMenu==1){ 
           color=BLUE;
		   texty=BLUE;}
if (ColorMenu==2){ 
           color=YELLOW;
	       texty=YELLOW;
}
	   }
	   else if (MENU[i]->typ==MENUTEXT){
           color=ORANGE;
	       texty=ORANGE;
if (ColorMenu==1){ 
	color=GREEN;
	texty=GREEN;}
if (ColorMenu==2){ 
	color=BLUE;
	texty=BLUE;}
	   }
	   else{
		   color=(val)?RED:GREEN;
	       texty=(val)?WHITE:WHITE;
	   }

	   if (MENU[i]->opt) 
	   {
		   if (MENU[i]->typ==MENUITEM){
				DrawTextL(x+3, y, texty,text);
				y = y + 2;
		   }else{
				DrawTextL(x+3, y, texty,text);
		   }
	   }

       if (MENU[i]->opt) {
		   if (MENU[i]->typ==MENUTEXT)
			   DrawTextR((x+Mxofs), y, color,(char *)MENU[i]->opt);
		   else
			   DrawTextR((x+Mxofs), y, color,(char *)MENU[i]->opt[val]);
	   }

       y+=Mysize;
  }
}

void D3D9Menu::MenuNav(void)
{



if (GetAsyncKeyState(VK_UP)&1) {
		do {
			//Sound.wav.playsoundmem((LPCSTR)MOVE);
			Mpos--;
			if (Mpos<0)  Mpos=Mmax-1;
		} while (MENU[Mpos]->typ==MENUTEXT);	
  } else if (GetAsyncKeyState(VK_DOWN)&1) {
		do {
		//	Sound.wav.playsoundmem((LPCSTR)MOVE);
			Mpos++;
		    if (Mpos==Mmax) Mpos=0;
		} while (MENU[Mpos]->typ==MENUTEXT);		
  } else if (MENU[Mpos]->var) {
		int dir=0;

		if ( ( GetAsyncKeyState(VK_LEFT )&1 ) && *MENU[Mpos]->var > 0 ) dir=-1;// Sound.wav.playsoundmem((LPCSTR)SWITCH);
		if ( ( GetAsyncKeyState(VK_RIGHT)&1 ) && *MENU[Mpos]->var < (MENU[Mpos]->maxvalue-1)) dir=1;// Sound.wav.playsoundmem((LPCSTR)SWITCH);
		if (dir) {
			*MENU[Mpos]->var += dir;
			if (MENU[Mpos]->typ==MENUFOLDER) Mmax=0;
			if (MENU[Mpos]->typ==MENUCAT) Mmax=0;  
		}
  }
}