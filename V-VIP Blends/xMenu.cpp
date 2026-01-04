//====================================================================================================//
#include <stdio.h>
#include "xMenu.h"
#pragma warning(disable:4244)
#pragma warning(disable:4996)
#pragma warning(disable:4800)

int				RainbowR		= 100;
int				RainbowG		= 100;
int				RainbowB		= 100;
float			RainbowTexts	= 100;
#define			RainbowTextTest D3DCOLOR_ARGB(255, RainbowR, RainbowG, RainbowB)
///////////////////////////////////////////////////////
#define MCOLOR_CURRENT	D3DCOLOR_ARGB(255,30,30,30)//Grey
#define MCOLOR_TEXT		D3DCOLOR_ARGB(255, 000, 255, 000)//Red
#define MCOLOR_ACTIVE	D3DCOLOR_ARGB(255, 245, 000, 000)//White
#define MENUCOLOR_TITLE	D3DCOLOR_ARGB(255, 000, 255, 000) //Green
#define MCOLOR_FOLDER	D3DCOLOR_ARGB(255, 255, 255, 000) //Blue
#define MCOLOR_INACTIVE	D3DCOLOR_ARGB(255, 255, 255, 255)//Black
////////////////////////////////////////////////////////
#define RED				D3DCOLOR_ARGB(255, 245, 000, 000)
#define WHITE			D3DCOLOR_ARGB(255, 255, 255, 255)
#define YELLOW			D3DCOLOR_ARGB(255, 255, 255, 000) 
#define GREEN			D3DCOLOR_ARGB(255, 000, 255, 000)
#define ORANGE			D3DCOLOR_ARGB(255, 255, 125, 000)
#define BLACK			D3DCOLOR_ARGB(150, 000, 000, 000)
#define PURPLE			D3DCOLOR_ARGB(255, 125, 000, 255)
#define BLUE			D3DCOLOR_ARGB(255, 19, 84, 199) 
#define DEEPSKYBLUE     D3DCOLOR_ARGB(255, 30, 144, 255) //
#define CHOCOLATE2      D3DCOLOR_ARGB(255, 238, 118, 33) //
#define GOLD2			D3DCOLOR_ARGB(255, 238, 201, 0)  //
#define SQUA			D3DCOLOR_ARGB(255, 0, 255, 255)  //
#define DARKGREY        D3DCOLOR_ARGB(255,62,62,62)      //
#define Functions       D3DCOLOR_ARGB(255,26,115,145)//
#define MenuGreen       D3DCOLOR_ARGB(255,43,119,64) //
#define MenuGREY        D3DCOLOR_ARGB(255,30,30,30)  //
#define FUCK_ON			D3DCOLOR_ARGB(255,14,159,47) //
#define FUCK_OFF		D3DCOLOR_ARGB(255,62,120,167)//
#define BLACK			D3DCOLOR_ARGB(150, 000, 000, 000)
#define WHITE			D3DCOLOR_ARGB(255, 255, 255, 255)
#define D3DFONT_BOLD 0x0000
#define dSKYBLUE			D3DCOLOR_ARGB(255, 0,   180, 255)
#define dWhite	D3DCOLOR_RGBA(255, 255, 255, 255)
#define dRed	D3DCOLOR_RGBA(255, 000, 000, 255)
#define dGreen	D3DCOLOR_RGBA(000, 255, 000, 255)
#define dBlue	D3DCOLOR_RGBA(000, 000, 255, 255)
#define dBlack	D3DCOLOR_RGBA(128, 128, 128, 255)
#define dPurple	D3DCOLOR_RGBA(125, 000, 255, 255)
#define dGrey	D3DCOLOR_RGBA(128, 128, 128, 255)
#define dLightGrey	D3DCOLOR_RGBA(188, 188, 188, 255)
#define dYellow	D3DCOLOR_RGBA(255, 255, 000, 255)
#define dOrange	D3DCOLOR_RGBA(255, 125, 000, 255)
#define D3DFONT_BOLD 0x0000
LPDIRECT3DDEVICE9 g_pDevice;
ID3DXFont	*pFont1;






void D3D9Menu::AddItem(char *txt, char **opt, int *var, int maxvalue)
{
  MENU[Mmax]->typ=MENUITEM;
  MENU[Mmax]->txt=txt;
  MENU[Mmax]->opt=opt;
  MENU[Mmax]->var=var;
  MENU[Mmax]->maxvalue=maxvalue;
  Mmax++;
}

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

void D3D9Menu::DrawTextR(int x,int y,DWORD color,char *text)
{
    RECT rect, rect1, rect2, rect3, rect4, rect5;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect1, x-1, y, x-1, y );
    SetRect( &rect2, x, y, x, y );
	SetRect( &rect3, x, y+1, x, y+1 );
    SetRect( &rect4, x, y, x, y );
	SetRect( &rect5, x - 0.1, y + 0.2, x - 0.1, y + 0. );
	pFont1->DrawTextA(NULL,text,-1,&rect5, DT_LEFT|DT_NOCLIP, color );
    pFont1->DrawTextA(NULL,text,-1,&rect,  DT_LEFT|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect1, DT_LEFT|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect2, DT_LEFT|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect3, DT_LEFT|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect4, DT_LEFT|DT_NOCLIP, BLACK );
}

void D3D9Menu::FontCreate(LPDIRECT3DDEVICE9 pDevice)
{
if (g_pDevice != pDevice)
{
g_pDevice = pDevice;
try
{
if (pFont1 != 0)
pFont1->Release();
} catch (...) {}
pFont1 = 0;
D3DXCreateFontA(pDevice, 11, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Tahoma", &pFont1);
}
}

void D3D9Menu::DrawTextL(int x,int y,DWORD color,char *text)
{
    RECT rect, rect1, rect2, rect3, rect4, rect5;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect1, x-1, y, x-1, y );
    SetRect( &rect2, x, y, x, y );
	SetRect( &rect3, x, y+1, x, y+1 );
    SetRect( &rect4, x, y, x, y );
	SetRect( &rect5, x - 0.1, y + 0.2, x - 0.1, y + 0. );
	pFont1->DrawTextA(NULL,text,-1,&rect5, DT_RIGHT|DT_NOCLIP, color );
    pFont1->DrawTextA(NULL,text,-1,&rect,  DT_RIGHT|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect1, DT_RIGHT|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect2, DT_RIGHT|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect3, DT_RIGHT|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect4, DT_RIGHT|DT_NOCLIP, BLACK );
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

void D3D9Menu::MenuShow(float x, float y, LPDIRECT3DDEVICE9 pDevice)//(float x, float y, LPDIRECT3DDEVICE9 pDevice)
{
    int i, val;
  DWORD color;
  DWORD texty;
  char text[100];
  if (!aktifmenu) return;
  for (i=0; i<Mmax; i++) 
  {
	   val=(MENU[i]->var)?(*MENU[i]->var):0;
	   sprintf(text, "%s", MENU[i]->txt);
	  if (i==Mpos){
			if(RainbowTexts!=100)
			{RainbowR-=2,RainbowG-=3,RainbowB-=3;}
			if(RainbowTexts!=255)
			{RainbowR+=2,RainbowG+=3,RainbowB+=4;}
			color=RainbowTextTest;
			texty=RainbowTextTest;
			sprintf(text, "~> %s <~", MENU[i]->txt);
		}
	   else if (MENU[i]->typ==MENUFOLDER){
           color=dYellow; 
	       texty=dYellow;
	   }
	   else if (MENU[i]->typ==MENUTEXT){
		   color=dGreen;
	       texty=dGreen;
	   }
	   else{
		   color=(val)?dSKYBLUE:dWhite;
	       texty=(val)?dSKYBLUE:dWhite;
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
  }}

void D3D9Menu::MenuNav(void)
{
	//bool bBothPressed = GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState(VK_NUMPAD0)&0x8000;

	if (GetAsyncKeyState(VK_INSERT)&1)aktifmenu=(!aktifmenu);
  if (!aktifmenu) return;

  if (GetAsyncKeyState(VK_UP)&1) {
		do {
			//Sound.wav.playsoundmem((LPCSTR)MOVE);
			Mpos--;
			if (Mpos<0)  Mpos=Mmax-1;
		} while (MENU[Mpos]->typ==MENUTEXT);	
  } else if (GetAsyncKeyState(VK_DOWN)&1) {
		do {
			//Sound.wav.playsoundmem((LPCSTR)MOVE);
			Mpos++;
		    if (Mpos==Mmax) Mpos=0;
		} while (MENU[Mpos]->typ==MENUTEXT);		
  } else if (MENU[Mpos]->var) {
		int dir=0;

		if ( ( GetAsyncKeyState(VK_LEFT )&1 ) && *MENU[Mpos]->var > 0 ) dir=-1;//, Sound.wav.playsoundmem((LPCSTR)SWITCH);
		if ( ( GetAsyncKeyState(VK_RIGHT)&1 ) && *MENU[Mpos]->var < (MENU[Mpos]->maxvalue-1)) dir=1;//, Sound.wav.playsoundmem((LPCSTR)SWITCH);
		if (dir) {
			*MENU[Mpos]->var += dir;
			if (MENU[Mpos]->typ==MENUFOLDER) Mmax=0;
			if (MENU[Mpos]->typ==MENUCAT) Mmax=0;  
		}
  }
}