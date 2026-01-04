//====================================================================================================//
#include <stdio.h>
#include "xMenu.h"
#pragma warning(disable:4244)
#pragma warning(disable:4996)
#pragma warning(disable:4800)
///////////////////////////////////////////////////////
#define MCOLOR_CURRENT	D3DCOLOR_ARGB(PINK)
#define MCOLOR_TEXT		D3DCOLOR_ARGB(GREEN)
#define MCOLOR_ACTIVE	D3DCOLOR_ARGB(RED)
#define MCOLOR_FOLDER	D3DCOLOR_ARGB(BLUE)
#define MCOLOR_INACTIVE	D3DCOLOR_ARGB(WHITE)
////////////////////////////////////////////////////////
#define RED				D3DCOLOR_ARGB(255, 245, 000, 000)
#define WHITE			D3DCOLOR_ARGB(255, 255, 255, 255)
#define YELLOW			D3DCOLOR_ARGB(255, 255, 255, 000) 
#define GREEN			D3DCOLOR_ARGB(255, 000, 255, 000)
#define ORANGE			D3DCOLOR_ARGB(255, 255, 125, 000)
#define BLACK			D3DCOLOR_ARGB(150, 000, 000, 000)
#define PURPLE			D3DCOLOR_ARGB(255, 125, 000, 255)
#define BLUE			D3DCOLOR_ARGB(255, 19, 84, 199) 
#define BIRU			D3DCOLOR_ARGB(000, 000, 255, 255)
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
ID3DXFont	*pFont1;
LPDIRECT3DDEVICE9 g_pDevice;