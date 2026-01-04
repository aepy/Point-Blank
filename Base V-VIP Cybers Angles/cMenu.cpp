//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
#include <stdio.h>
#include "cMenu.h"
#include "PointBlank DxColor.h"
#include "cPragma.h"

ID3DXFont	*pFont1;
//=========================================================================//
void D3D9Menu::AddFolder(char *txt, char **opt, int *var, int maxvalue)
{
  MENU[Mmax]->typ=MENUFOLDER;
  MENU[Mmax]->txt=txt;
  MENU[Mmax]->opt=opt;
  MENU[Mmax]->var=var;
  MENU[Mmax]->maxvalue=maxvalue;
  Mmax++;
}
//=========================================================================//
void D3D9Menu::AddTutor(char *txt, char **opt, int *var, int maxvalue)
{
  MENU[Mmax]->typ=MENUTUTOR;
  MENU[Mmax]->txt=txt;
  MENU[Mmax]->opt=opt;
  MENU[Mmax]->var=var;
  MENU[Mmax]->maxvalue=maxvalue;
  Mmax++;
}
//=========================================================================//
void D3D9Menu::AddItem(char *txt, char **opt, int *var, int maxvalue)
{
  MENU[Mmax]->typ=MENUITEM;
  MENU[Mmax]->txt=txt;
  MENU[Mmax]->opt=opt;
  MENU[Mmax]->var=var;
  MENU[Mmax]->maxvalue=maxvalue;
  Mmax++;
}

//=========================================================================//
void D3D9Menu::AddText(char *txt, char *opt)
{
	MENU[Mmax]->typ=MENUTEXT;
	MENU[Mmax]->txt=txt;
	MENU[Mmax]->opt=(char **)opt;
	MENU[Mmax]->var=0;
	MENU[Mmax]->maxvalue=0;
	Mmax++;
}

//=========================================================================//
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

//=========================================================================//
void D3D9Menu::FontCreate(LPDIRECT3DDEVICE9 pDevice)
{
	D3DXCreateFontA(pDevice, 14, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Sylfaen", &pFont1);
}

void D3D9Menu::FontReset()
{
	pFont1->OnLostDevice();
	pFont1->OnResetDevice();
}

void D3D9Menu::OnLostDevice()
{
	pFont1->OnLostDevice();	
}

//=========================================================================//
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

//=========================================================================//
void D3D9Menu::DrawTextC(int x,int y,DWORD color,char *text )
{
    RECT rect, rect2;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect2, x - 0.1, y + 0.2, x - 0.1, y + 0. );
	pFont1->DrawTextA(NULL,text,-1,&rect2, DT_CENTER|DT_NOCLIP, 0x00000000 );
    pFont1->DrawTextA(NULL,text,-1,&rect, DT_CENTER|DT_NOCLIP, color );
}
//------------------------------------------------------------------------------------------------//
void DrawBoxs( LPDIRECT3DDEVICE9 pDevice , int x, int y, int w, int h, DWORD Color )
{
D3DRECT rec;
rec.x1 = x;
rec.x2 = x + w;
rec.y1 = y;
rec.y2 = y + h;
pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, Color, 0, 0 );
}
//------------------------------------------------------------------------------------------------//
void DrawBoxs1( LPDIRECT3DDEVICE9 pDevice , int x, int y, int w, int h, DWORD Color )
{
D3DRECT rec1;
rec1.x1 = x;
rec1.x2 = x + w;
rec1.y1 = y;
rec1.y2 = y + h;
pDevice->Clear( 1, &rec1, D3DCLEAR_TARGET, Color, 0, 0 );
}
//------------------------------------------------------------------------------------------------//
void DrawRectangle(int x, int y, int w, int h, int s, DWORD Color, LPDIRECT3DDEVICE9 pDevice)
{
DrawBoxs(pDevice, x, y, w, s, Color );
DrawBoxs(pDevice, x, y, s, h, Color );
DrawBoxs(pDevice, (x+w), y, s, h, Color );
DrawBoxs(pDevice, x, (y+h), w+s, s, Color );
}
//------------------------------------------------------------------------------------------------//
void DrawRectangle1(int x, int y, int w, int h, int s, DWORD Color, LPDIRECT3DDEVICE9 pDevice)
{
DrawBoxs1(pDevice, x, y, w, s, Color );
DrawBoxs1(pDevice, x, y, s, h, Color );
DrawBoxs1(pDevice, (x+w), y, s, h, Color );
DrawBoxs1(pDevice, x, (y+h), w+s, s, Color );
}
//------------------------------------------------------------------------------------------------//
void drawlineorrect(LPDIRECT3DDEVICE9 pDevice,int tx,int ty,int tw,int th,D3DCOLOR COLORZ)
{
D3DRECT RECTONE;
RECTONE.x1 = tx;
RECTONE.y1 = ty;
RECTONE.x2 = tx+tw;
RECTONE.y2 = ty+th;
pDevice->Clear(1,&RECTONE,D3DCLEAR_TARGET,COLORZ,0,0);
}
//------------------------------------------------------------------------------------------------//
void drawlineorrect1(LPDIRECT3DDEVICE9 pDevice,int tx,int ty,int tw,int th,D3DCOLOR COLORZ)
{
D3DRECT RECTONE;
RECTONE.x1 = tx;
RECTONE.y1 = ty;
RECTONE.x2 = tx+tw;
RECTONE.y2 = ty+th;
pDevice->Clear(1,&RECTONE,D3DCLEAR_TARGET,COLORZ,0,0);
}
//=========================================================================//
void D3D9Menu::MenuShow(float x, float y, LPDIRECT3DDEVICE9 pDevice)
{
  int i, val;
  DWORD color;
  DWORD texty;
  char text[100];
  if (!Mvisible) return;
//------------------------------------------------------------------------------------------------// [D3D KOTAK CREDIT]210,670
  //DrawRectangle1(50/*Kiri*/, 100/*Atas*/, 802/*Kolom_Menyempit*/, 172, 1, WHITE, pDevice); // Menu
  //drawlineorrect1(pDevice, 52/*Kiri*/, 102/*Atas*/, 800/*Kolom_Menyempit*/, 170, BLACK); // Menu
//------------------------------------------------------------------------------------------------//
  for (i=0; i<Mmax; i++) 
  {
	   val=(MENU[i]->var)?(*MENU[i]->var):0;
	   sprintf(text, "%s", MENU[i]->txt);
	   if (i==Mpos){
	
           color=dRed;
		   texty=dRed;

		   sprintf(text, "%s", MENU[i]->txt);
	   }
	   else if (MENU[i]->typ==MENUFOLDER){
           color=dBlue;
	       texty=dBlue;
	   }
	   else if (MENU[i]->typ==MENUTUTOR){
           color=dGreen;
	       texty=dGreen;
	   }
	   else if (MENU[i]->typ==MENUTEXT){
		   color=dRed;
	       texty=dRed;
	   }
	   else{
		   color=(val)?dRed:dGreen;
	       texty=(val)?SKYBLUE:SKYBLUE;
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

//=========================================================================//
void D3D9Menu::MenuNav(void)
{
bool bBothPressed = GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState(VK_NUMPAD0)&0x8000;
if (GetAsyncKeyState(VK_INSERT)&1)
{
Mvisible=(!Mvisible);
}
if (!Mvisible) return;
if (GetAsyncKeyState(VK_UP)&1) {
do {
Mpos--;
if (Mpos<0)  Mpos=Mmax-1;
} 
while (MENU[Mpos]->typ==MENUTEXT);	
}else if (GetAsyncKeyState(VK_DOWN)&1) {
do {
Mpos++;
if (Mpos==Mmax) Mpos=0;
} while (MENU[Mpos]->typ==MENUTEXT);		
} else if (MENU[Mpos]->var) {
int dir=0;

if ( ( GetAsyncKeyState(VK_LEFT )&1 ) && *MENU[Mpos]->var > 0 ) dir=-1;
if ( ( GetAsyncKeyState(VK_RIGHT)&1 ) && *MENU[Mpos]->var < (MENU[Mpos]->maxvalue-1)) dir=1;
if (dir) {
*MENU[Mpos]->var += dir;
if (MENU[Mpos]->typ==MENUFOLDER) Mmax=0;
if (MENU[Mpos]->typ==MENUCAT) Mmax=0;  
}}}