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
#pragma message("SourceCode Database By: SOMALI JCO")
#pragma message("Author : MR.UBED ADMIN S.O.M.A.L.I")
#pragma message("Ingat! : Hack Cipta Dilindungi")
#pragma message("Copyright ©2014-2015 SOMALI-JCO.TK")

#define Green				D3DCOLOR_ARGB(255, 000, 255, 000)
#define White				D3DCOLOR_ARGB(255, 255, 255, 255)
#define Red					D3DCOLOR_ARGB(255, 255, 000, 000)
#define Blue				D3DCOLOR_ARGB(255, 000, 000, 255)
#define Black				D3DCOLOR_ARGB(255, 000, 000, 000)
#define Black_transparant	D3DCOLOR_ARGB(200, 000, 000, 000)
#define Purple				D3DCOLOR_ARGB(255, 125, 000, 125)
#define Yellow				D3DCOLOR_ARGB(255, 255, 255, 000)
#define Orange				D3DCOLOR_ARGB(255, 255, 125, 000)
#define Grey				D3DCOLOR_ARGB(255, 128, 128, 128)
#define Cyan				D3DCOLOR_ARGB(255, 000, 032, 032)
#define Custom				D3DCOLOR_ARGB(225, 000, 120, 120)
#define Maroon				D3DCOLOR_ARGB(255, 128, 0, 0)
#define MCOLOR_FOLDER		D3DCOLOR_ARGB(255, 255, 000, 000)  ///RED
#define MCOLOR_CURRENT		D3DCOLOR_ARGB(255, 255, 255, 000)  ///YELLOW
#define MCOLOR_TEXT			D3DCOLOR_ARGB(255, 255, 255, 255)  ///WHITE
#define MCOLOR_ACTIVE		D3DCOLOR_ARGB(255, 000, 255, 000)  ///GREEN
#define MCOLOR_INACTIVE		D3DCOLOR_ARGB(255, 195, 195, 195)  ///GREY
#define MCOLOR_TITLE	D3DCOLOR_ARGB(255, 000, 000, 255)			// Warna Judul
#define TLeft				DT_NOCLIP | DT_LEFT
#define TRight				DT_NOCLIP | DT_RIGHT
#define Menu_background		Black_transparant
#define Menu_rectangle		Green//
#define Menu_special		Blue//garis menu
#define TitleText			Red//title tex

DWORD NFCZ = NULL;
int qntHacks = 0;
int MenuX_sShow		= 1;

int mx,my;
int menux, menuy, mxofs;
int MenuSelection;
int Current     = true;
bool Menu       = true;
bool ShowX	    = true;
bool FontCreate = true;
//creat
LPD3DXFONT NHT3XT	= NULL;
//LPD3DXFONT pFont	= NULL;
LPD3DXFONT fName	= NULL;
LPD3DXFONT Title    = NULL;
//LPD3DXLINE pLine    = NULL;
LPDIRECT3DDEVICE9 pDevice;
LPDIRECT3DDEVICE9 npDevice; 
LPDIRECT3DDEVICE9 pGDevice = NULL;
LPD3DXFONT fBig	= NULL;



static struct key_s
{
	bool        bPressed;
	DWORD        dwStartTime;
}kPressingKey[256];


void DrawString(char * string, int x, int y, int color, int f){
RECT pText;
SetRect(&pText, x, y, x, y);

switch(f){

case 0:
Title->DrawTextA(NULL, string, -1, &pText, DT_NOCLIP | DT_RIGHT, color);
break;

case 1:
Title->DrawTextA(NULL, string, -1, &pText, DT_NOCLIP | DT_CENTER, color);
break;

case 2:
Title->DrawTextA(NULL, string, -1, &pText, DT_NOCLIP | DT_LEFT, color);
break;
	}
}
void Box(int x, int y, int w, int h, DWORD Color, LPDIRECT3DDEVICE9 pDevice){
	
if( !pDevice )
return;

const DWORD D3D_FVF = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
struct Vertex {
float x,y,z,ht;
DWORD yourcolor;
}
V[4] = 
{
{(float)x		,(float)(y+h)	, 0.0f, 0.0f, Color},
{(float)x		,(float)y		, 0.0f, 0.0f, Color},
{(float)(x+w)	,(float)(y+h)	, 0.0f, 0.0f, Color},
{(float)(x+w)	,(float)y		, 0.0f, 0.0f, Color}
};
	
	pDevice->SetTexture( 0, NULL );
	pDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
	pDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW);
	pDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
	pDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
	pDevice->SetRenderState( D3DRS_ZENABLE, D3DZB_FALSE );
	pDevice->SetRenderState( D3DRS_FOGENABLE, false );

	pDevice->SetFVF(D3D_FVF);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,V,sizeof(Vertex));
}

void Rectangle(int x, int y, int w, int h, D3DCOLOR BorderColor, IDirect3DDevice9 * pDevice) 
{ 
	int px = 1;
	if( !pDevice )
		return;

    Box( x, (y + h - px), w, px,     BorderColor, pDevice ); 
    Box( x, y, px, h,                BorderColor, pDevice ); 
    Box( x, y, w, px,                BorderColor, pDevice ); 
    Box( (x + w - px), y, px, h,     BorderColor, pDevice ); 
}
/*void FillRGB( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice )
{
if( w < 0 )w = 1;
if( h < 0 )h = 1;
if( x < 0 )x = 1;
if( y < 0 )y = 1;
 
D3DRECT rec = { x, y, x + w, y + h };
pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}*/
/*void DrawBorder(int x, int y, int w, int h, int px, D3DCOLOR BorderColor, LPDIRECT3DDEVICE9 pDevice)
{
	FillRGB(x,(y + h - px), w, px, BorderColor, pDevice);
	FillRGB(x, y, px, h, BorderColor, pDevice);
	FillRGB(x, y, w, px, BorderColor, pDevice);
	FillRGB(x + w - px, y, px, h, BorderColor, pDevice);
}*/


void PrintText(LPD3DXFONT g_pFont, INT x, INT y, DWORD Flags, DWORD Color, CHAR *text, ...)
{
	RECT rec;
	SetRect(&rec, x, y, x, y);
	CHAR logbuf[512] = {0};

	va_list va_alist;
	va_start(va_alist, text);
	vsnprintf(logbuf + strlen(logbuf), sizeof(logbuf) - strlen(logbuf), text, va_alist);
	
	va_end(va_alist);
	g_pFont->DrawTextA(NULL, logbuf, -1, &rec, Flags, Color);
}
BOOL IsKeyPressed(int Key,DWORD dwTimeOut){

if( HIWORD( GetKeyState( Key ) ) ){
if( !kPressingKey[Key].bPressed || ( kPressingKey[Key].dwStartTime && ( kPressingKey[Key].dwStartTime + dwTimeOut ) <= GetTickCount( ) ) ){
kPressingKey[Key].bPressed = TRUE;
if( dwTimeOut > NULL )
kPressingKey[Key].dwStartTime = GetTickCount( );
 return TRUE;
}}
else
kPressingKey[Key].bPressed = FALSE;
return FALSE;
}
VOID FillGradients(int x, int y, int h, int w, DWORD color1, DWORD color2, LPDIRECT3DDEVICE9 pDevice);
void Item(CHAR *text, CHAR **opt, INT &val, INT maxvalue, LPDIRECT3DDEVICE9 pDevice)
{
	DWORD Color1, Color2;
	INT bVar = (val)?(val):0;
	extern INT Current;
	if(Menu && NHT3XT)
	{
		if(MenuSelection == qntHacks)
		{
			if(IsKeyPressed(VK_RIGHT,0))
				if(val < maxvalue - 1)
					val++;
			if(IsKeyPressed(VK_LEFT,0))
				if(val > 0)
					val--;
		}else{}
		if(val > 0)
		{
			//Rectangle(menux + 2, menuy + 22 + (qntHacks * 20), 12, 12, Red, pDevice);
			FillGradients (menux + 3,menuy + 23 + (qntHacks * 20),10,10,Green,White,pDevice);//indikator tombol fiturjika on
		}
		if(val == 0)
		{
			//Rectangle(menux + 2, menuy + 22 + (qntHacks * 20), 12, 12, Green, pDevice);//bingkai indikator fitur
			FillGradients (menux + 3,menuy + 23 + (qntHacks * 20),10,10,Red,White,pDevice);//indikator tombol fiturjika off
		}

		Color1 = White;
		Color2 = (bVar)?Green:Red;
		PrintText(NHT3XT, menux + 20, menuy + 20 + (qntHacks * 20), TLeft, Color1, text);
		PrintText(NHT3XT, menux - 15 + mxofs, menuy + 20 + (qntHacks * 20), TRight, Color2, opt[bVar]);


		qntHacks++;
	}
	Current++;
}

void Folder(CHAR *text, CHAR **opt, INT &val, INT maxvalue, LPDIRECT3DDEVICE9 pDevice)
{
	DWORD Color1, Color2;
	int bVar = (val)?(val):0;
	extern int Current;
	if(Menu && NHT3XT)
	{
		if(MenuSelection == qntHacks)
		{
			if(IsKeyPressed(VK_RIGHT,0))
				if(val < maxvalue - 1)
					val++;
			if(IsKeyPressed(VK_LEFT,0))
				if(val > 0)
					val--;
		}else{}
		if(val > 0)
		{
			//Rectangle(menux + 2, menuy + 22 + (qntHacks * 20), 12, 12, Red, pDevice);
			FillGradients (menux + 3,menuy + 23 + (qntHacks * 20),10,10,Blue,Grey,pDevice);//indikator tombol fiturjika on
		}
		if(val == 0)
		{
			//Rectangle(menux + 2, menuy + 22 + (qntHacks * 20), 12, 12, Red, pDevice);//bingkai indikator fitur
			FillGradients (menux + 3,menuy + 23 + (qntHacks * 20),10,10,Grey,Blue,pDevice);//indikator tombol fiturjika off
		}

		Color1 = Yellow;
		Color2 = (bVar)?Yellow:Yellow;

		PrintText(NHT3XT, menux + 20, menuy + 20 + (qntHacks * 20), TLeft, Color1, text);
		PrintText(NHT3XT, menux - 15 + mxofs, menuy + 20 + (qntHacks * 20), TRight, Color2, opt[bVar]);

		qntHacks++;
	}
	Current++;
}
void PrintTextv2(char pString[], int x, int y, D3DCOLOR col, ID3DXFont *font){
RECT FontRect = { x, y, x+500, y+30 };
font->DrawText( NULL, pString, -1, &FontRect, DT_LEFT | DT_NOCLIP, col);
}
float RainbowTexts=100;
int RainbowR=100,RainbowG=100,RainbowB=100;
#define   RainbowTextTest     D3DCOLOR_ARGB(255,RainbowR,RainbowG, RainbowB)

void XTitle(int x, int y, char *text)
{
		if(RainbowTexts!=100)
		{RainbowR-=2,RainbowG-=3,RainbowB-=3;}
		if(RainbowTexts!=255)
		{RainbowR+=2,RainbowG+=3,RainbowB+=4;}
		PrintTextv2(text,x, y, RainbowTextTest, NHT3XT);
}
//========================================================================
#define 	            MENUMAXINDEX	100
#define 	            MENUFOLDER		1
#define 	            MENUTEXT		2
#define 	            MENUBASE		10
int Mpos=0;
int Active=0;
int	Mxofs =150;
int	Mysize=15;
int ShowMenu = 1;
char Mtitle[81]= "";

RECT rect,rect2,rect3;

struct{
int  *var;
int  maxvalue;
int  typ;
char *txt;
char **opt;
}
#define 	            MENUMAXINDEX	100
#define 	            MENUFOLDER		1
#define 	            MENUTEXT		2
#define 	            MENUITEM		3
#define 	            MENUBASE		10


//------------------------------------------------------------------//
D3MENU[MENUMAXINDEX];
void DrawAddItem(char *txt, char **opt, int *var, int maxvalue, int typ){
  D3MENU[Active].typ=typ;
  D3MENU[Active].txt=txt;
  D3MENU[Active].opt=opt;
  D3MENU[Active].var=var;
  D3MENU[Active].maxvalue=maxvalue;
  Active++;
}
void DrawAddText(char *txt, char *opt){
  D3MENU[Active].typ=MENUTEXT;
  D3MENU[Active].txt=txt;
  D3MENU[Active].opt=(char **)opt;
  D3MENU[Active].var=0;
  D3MENU[Active].maxvalue=0;
  Active++;
}

void DrawMenuShow(LPDIRECT3DDEVICE9 pDevice,int x, int y,	ID3DXFont *pFont)
{

  int i, val;
  DWORD color;
    SetRect( &rect, x+Mxofs/2, y, x+Mxofs /2 , y );
  if (!ShowMenu) return;

  if (Mtitle[0]) {

	  pFont->DrawText(NULL,Mtitle,-1,&rect,DT_NOCLIP | DT_CENTER, MCOLOR_TITLE);

	  y+=Mysize;
  }
  for (i=0; i<Active; i++) {
	   val=(D3MENU[i].var)?(*D3MENU[i].var):0;
	   // determine color
       if (i==Mpos)
           color=MCOLOR_CURRENT;
       else if (D3MENU[i].typ==MENUFOLDER)
           color=MCOLOR_FOLDER;
       else if (D3MENU[i].typ==MENUTEXT)
           color=MCOLOR_TEXT;
       else
		   color=(val)?MCOLOR_ACTIVE:MCOLOR_INACTIVE;
     SetRect( &rect3, x, y, x , y );
     SetRect( &rect2, x+Mxofs, y, x+Mxofs , y );
	   pFont->DrawText(NULL,D3MENU[i].txt,-1,&rect3, DT_NOCLIP,color);
       if (D3MENU[i].opt) {
		   if (D3MENU[i].typ==MENUTEXT)
		   	   pFont->DrawText(NULL,(char *)D3MENU[i].opt,-1,&rect2, DT_NOCLIP | DT_RIGHT, color);
		   else
			   pFont->DrawText(NULL,(char *)D3MENU[i].opt[val],-1,&rect2, DT_NOCLIP | DT_RIGHT, color);
	   }
       y+=Mysize;
  }
}
void DrawMenuNav(LPDIRECT3DDEVICE9 pDevice)
{
	if (GetAsyncKeyState(VK_INSERT)&1) ShowMenu=(!ShowMenu);
	if (!ShowMenu) return;
	if (GetAsyncKeyState(VK_UP)&1) {
		do {
			Mpos--;
			if (Mpos<0)  Mpos=Active-1;
		} while (D3MENU[Mpos].typ==MENUTEXT);
	
	} else if (GetAsyncKeyState(VK_DOWN)&1) {
		do {
			Mpos++;
		    if (Mpos==Active) Mpos=0;
		} while (D3MENU[Mpos].typ==MENUTEXT);
  } else if (D3MENU[Mpos].var) {
		int dir=0;
		
		if (GetAsyncKeyState(VK_LEFT )&1 && *D3MENU[Mpos].var > 0                      ) dir=-1;
		
		if (GetAsyncKeyState(VK_RIGHT)&1 && *D3MENU[Mpos].var < (D3MENU[Mpos].maxvalue-1)) dir=1;
		if (dir) {
			*D3MENU[Mpos].var += dir;
			if (D3MENU[Mpos].typ==MENUFOLDER) Active=0;
		}
	}
}
