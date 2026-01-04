#include <stdio.h>
#include "cMenu.h"
#include "cColor.h"
#include "cPragma.h"
#include "cSound.h"
#include "Sounds.h"
#define D3DFONT_BOLD 0x0000
ID3DXFont	*pFont1;
int Mmax=0;
int aktifmenu=1;
int Mpos=0;
int Mxofs=180.0f;
int Mysize=14.0f;

char Mtitle[50];
char Mtitle1[50];

RECT rect;
RECT rect2;
RECT rect3;
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

void D3D9Menu::DrawTextR(int x,int y,DWORD color,char *text)
{
    RECT rect, rect1, rect2, rect3, rect4, rect5;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect1, x-1, y, x-1, y );
	SetRect( &rect2, x+1, y, x+1, y );
	SetRect( &rect3, x, y-1, x, y-1 );
	SetRect( &rect4, x, y+1, x, y+1 );
	SetRect( &rect5, x - 0.1, y + 0.2, x - 0.1, y + 0. );
	pFont1->DrawTextA(NULL,text,-1,&rect5, DT_LEFT|DT_NOCLIP, color );////////////// ON OFF MENGARAH KE KIRI
    pFont1->DrawTextA(NULL,text,-1,&rect,  DT_LEFT|DT_NOCLIP, BLACK );////////////////////
	pFont1->DrawTextA(NULL,text,-1,&rect1, DT_LEFT|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect2, DT_LEFT|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect3, DT_LEFT|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect4, DT_LEFT|DT_NOCLIP, BLACK );
}

BOOL D3D9Menu::Font()
{
	if(pFont1)
		return FALSE;
	else return TRUE;
}

void D3D9Menu::FontCreate(LPDIRECT3DDEVICE9 pDevice)
{
	D3DXCreateFont(pDevice, 14, 0, FW_REGULAR, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Berlin Sans FB", &pFont1);
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
	pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, BLACK, 0, 0 );
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
VOID __stdcall CMenuItem_DrawCronersBox(INT xx,INT yy,INT hh,INT ww,LPDIRECT3DDEVICE9 pDevice)
{
D3DRECT rec;
FLOAT x,y,w,h;
    
struct vertex 
{
FLOAT x,y,z,t;
DWORD Color;
};

vertex V[8];

x = (float)xx; y = (float)yy; h = (float)hh; w = (float)ww;

V[0].Color = V[1].Color = V[2].Color = V[3].Color = D3DCOLOR_ARGB( 000, 00, 00, 00 );
V[4].Color = V[5].Color = V[6].Color = V[7].Color = D3DCOLOR_ARGB( 000, 00, 00, 00 );

V[0].z  = V[1].z = V[2].z  = V[3].z  = 0;
V[4].z  = V[5].z = V[6].z  = V[7].z  = 0;
V[0].t  = V[1].t = V[2].t  = V[3].t  = 0;
V[4].t  = V[5].t = V[6].t  = V[7].t  = 0;

V[0].x = V[1].x = x;
V[0].y = V[2].y = y + h;
V[1].y = V[3].y = y;
V[2].x = V[3].x = x + w;
V[4].x = V[5].x = x;
V[4].y = V[6].y = y + h;
V[5].y = V[7].y = y;
V[6].x = V[7].x = x + w;

pDevice->SetTexture(0, NULL);
pDevice->SetPixelShader( NULL );
pDevice->SetRenderState(D3DRS_CLIPPING,FALSE); 
pDevice->SetFVF(D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1);
pDevice->DrawPrimitiveUP( D3DPT_TRIANGLESTRIP,2,V,sizeof(vertex));

rec.x1 = xx;rec.y1 = yy;rec.x2 = xx+ww;rec.y2 = yy+1;
//pDevice->Clear(1,&rec,D3DCLEAR_TARGET,D3DCOLOR_ARGB(255, 255, 255, 000),0,0);
rec.x1 = xx;rec.y1 = hh+yy;rec.x2 = xx+ww;rec.y2 = hh+yy+1;
//pDevice->Clear(1,&rec,D3DCLEAR_TARGET,D3DCOLOR_ARGB(255, 255, 255, 000),0,0);
rec.x1 = xx;rec.y1 = yy;rec.x2 = xx+1;rec.y2 = yy+hh;
//pDevice->Clear(1,&rec,D3DCLEAR_TARGET,D3DCOLOR_ARGB(255, 255, 255, 000),0,0);
rec.x1 = xx+ww;rec.y1 = yy;rec.x2 = xx+ww+1;rec.y2 = yy+hh;
//pDevice->Clear(1,&rec,D3DCLEAR_TARGET,D3DCOLOR_ARGB(255, 255, 255, 000),0,0);

return;
}
void D3D9Menu::DrawTextC(int x,int y,DWORD color,char *text)
{
    RECT rect, rect1, rect2, rect3, rect4, rect5;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect1, x-1, y, x-1, y );
	SetRect( &rect2, x+1, y, x+1, y );
	SetRect( &rect3, x, y-1, x, y-1 );
	SetRect( &rect4, x, y+1, x, y+1 );
	SetRect( &rect5, x - 0.1, y + 0.2, x - 0.1, y + 0. );
	pFont1->DrawTextA(NULL,text,-1,&rect5, DT_CENTER|DT_NOCLIP, color );
    pFont1->DrawTextA(NULL,text,-1,&rect,  DT_CENTER|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect1, DT_CENTER|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect2, DT_CENTER|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect3, DT_CENTER|DT_NOCLIP, BLACK );
	pFont1->DrawTextA(NULL,text,-1,&rect4, DT_CENTER|DT_NOCLIP, BLACK );
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
void D3D9Menu::DrawBox12(LPDIRECT3DDEVICE9 pDevice, int x, int y, int w, int h, D3DCOLOR color)
{
	D3DRECT rec;
	rec.x1 = x;
	rec.x2 = x + w;
	rec.y1 = y;
	rec.y2 = y + h;
	pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
} 

void D3D9Menu::DrawBorder12(int x, int y, int w, int h, int px,D3DCOLOR col ,LPDIRECT3DDEVICE9 pDevice)
{
DrawBox12(pDevice,x+px,y+h-px,w-px-px,px,col);// Bottom
DrawBox12(pDevice,x,y,px,h,col); // Left
DrawBox12(pDevice,x+px,y,w-px-px,px,col); // TOP
DrawBox12(pDevice,x+w-px,y,px,h,col); // RIGHT
}

void D3D9Menu::DrawMenu12(int x, int y, int w, int h, int px,D3DCOLOR col1,D3DCOLOR col2, LPDIRECT3DDEVICE9 pDevice)
{
DrawBox12(pDevice,x,y,w,h,col1);    		
DrawBorder12(x,y,w,h,px,col2,pDevice);
}

void D3D9Menu::MenuShow(float x, float y, LPDIRECT3DDEVICE9 pDevice)
{
  int i, val;
  DWORD color;
  DWORD texty;
  char text[100];
  if (!aktifmenu) return;
  for (i=0; i<Mmax; i++) {

	   val=(MENU[i]->var)?(*MENU[i]->var):0;
	   sprintf(text, "%s", MENU[i]->txt);
	   if (i==Mpos){
           color=MCOLOR_CURRENT;
		   texty=MCOLOR_CURRENT;
//		   pFont->DrawText((float)(x+totwidth/2), (float)cy-3, col_title,title,D3DFONT_SHADOW|D3DFONT_CENTERED);
		   //CMenuItem_DrawCronersBox((INT)x - 0,(INT)y - 4,17,152, pDevice);
		   sprintf(text, "%s", MENU[i]->txt);
	   }
	   else if (MENU[i]->typ==MENUFOLDER){
           color=MCOLOR_FOLDER;
	       texty=MCOLOR_FOLDER;
	   }
	   else if (MENU[i]->typ==MENUTEXT){
           color=MCOLOR_TEXT;
	       texty=MCOLOR_TEXT;
	   }
	   else{
		   color=(val)?MCOLOR_ACTIVE:MCOLOR_INACTIVE;
	       texty=(val)?LGRAY:LGRAY;
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
	bool bBothPressed = GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState(VK_NUMPAD0)&0x8000;

	if (GetAsyncKeyState(VK_INSERT)&1)aktifmenu=(!aktifmenu);
  if (!aktifmenu) return;

  if (GetAsyncKeyState(VK_UP)&1) {
		do {
			Sound.wav.playsoundmem((LPCSTR)MOVE);
			Mpos--;
			if (Mpos<0)  Mpos=Mmax-1;
		} while (MENU[Mpos]->typ==MENUTEXT);	
  } else if (GetAsyncKeyState(VK_DOWN)&1) {
		do {
			Sound.wav.playsoundmem((LPCSTR)MOVE);
			Mpos++;
		    if (Mpos==Mmax) Mpos=0;
		} while (MENU[Mpos]->typ==MENUTEXT);		
  } else if (MENU[Mpos]->var) {
		int dir=0;

		if ( ( GetAsyncKeyState(VK_LEFT )&1 ) && *MENU[Mpos]->var > 0 ) dir=-1, Sound.wav.playsoundmem((LPCSTR)SWITCH);
		if ( ( GetAsyncKeyState(VK_RIGHT)&1 ) && *MENU[Mpos]->var < (MENU[Mpos]->maxvalue-1)) dir=1, Sound.wav.playsoundmem((LPCSTR)SWITCH);
		if (dir) {
			*MENU[Mpos]->var += dir;
			if (MENU[Mpos]->typ==MENUFOLDER) Mmax=0;
			if (MENU[Mpos]->typ==MENUCAT) Mmax=0;  
		}
  }
}





