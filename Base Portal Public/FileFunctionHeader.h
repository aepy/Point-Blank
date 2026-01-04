#include <windows.h>
#include <wininet.h>
#include <time.h>


/*---------------------------------------- Declaration Auto Kill (Madness Mode) ----------------------------------------------------*/
#define ResultAutoKill1 - 0x100   //0x2C678//kalo ini Gak Work Kurangi 100
#define ResultAutoKill2           //0x2C560
#define ResultAutoKill3           //0x2C564
/*-------------------------------------------*/
#define OFS_AutoKill1				0x2C678
#define OFS_AutoKill2				0x2C560
#define OFS_AutoKill3				0x2C564

void SendDeathCharaCyberZModerZ(int IndexPlayer)
{
*(DWORD*)(*(DWORD*)(ResultBasePlayer2) + OFS_AutoKill1) = IndexPlayer; //- 8A 84 0A ?? ?? 02
*(DWORD*)(*(DWORD*)(ResultBasePlayer2) + OFS_AutoKill2) = 200004010; // 200004013 // 8B 94 01 ?? ?? 02 ?? 89 95 C3 FE ?? ?? 8A 45  //Kill com Lantern BOM
*(DWORD*)(*(DWORD*)(ResultBasePlayer2) + OFS_AutoKill3) = 1;  // C7 84 0A ?? ?? 02
//Sleep(100);
}
/*------------------------------------------- Declaration DrawCross ------------------------------------------------------*/
void Crosshair(LPDIRECT3DDEVICE9 pDevice, D3DCOLOR Color)
{
	int x = ( GetSystemMetrics( 0 ) / 2);
	int y = ( GetSystemMetrics( 1 ) / 2);
	Circle (x,y,6,true,Color,pDevice);
	FillRGB(x-10, y, 7, 1,Color,pDevice);
	FillRGB(x+4, y, 7, 1,Color,pDevice);
	FillRGB(x, y-10, 1, 7,Color,pDevice);
	FillRGB(x, y+4, 1, 7,Color,pDevice);
}

/*------------------------------------------- Declaration DrawMenuD3D ------------------------------------------------------*/
void DrawMenuD3D(LPDIRECT3DDEVICE9 pDevice)
{
	if (DrawFont == 1) 
	{
		D3DXCreateFontA(pDevice, 11, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Tahoma", &pFont);
		DrawFont = 0;
	}

	if (Drawing == 0)
	{
		if(Mmax==0) 
		RebuildMenu(pDevice);
		MenuShow(mx,my,pDevice);
		MenuNav();
	}

	if(!g_pFont)	D3DXCreateFontA(pDevice, 15, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Hud_Small_Font", &g_pFont);//15
	if(!pLine)		D3DXCreateLine( pDevice, &pLine );
}
/*------------------------------------------- Declaration GenerateTexture ------------------------------------------------------*/
LPDIRECT3DTEXTURE9 RainbowTextTestX;
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
