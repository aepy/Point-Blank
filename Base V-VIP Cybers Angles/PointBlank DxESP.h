//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
#include "PointBlank DxColor.h"
#include "PointBlank DxStruct.h"
#pragma warning(disable:4996)
#pragma warning(disable:4244)
#define LR_WIDTH 1
LPTSTR PointBlanki3Gfx1 = "i3GfxDx.dll";

#define OFS_RDATA   0x1AD2F0 // ?g_pRenderContext@@3PAVi3RenderContext
LPD3DXLINE pLine    = NULL;
LPD3DXFONT fName	= NULL;
LPD3DXFONT fSmall	= NULL;
LPD3DXFONT Title    = NULL;
LPD3DXFONT      g_pFont = NULL; //D3D Font
LPD3DXFONT      g_pFont2 = NULL; //D3D Font
LPD3DXLINE      g_Line = NULL; //D3D Line
D3DVIEWPORT9    g_ViewPort; //ViewPort
LPDIRECT3DDEVICE9 pDevice;
D3DVIEWPORT9 Viewport;
	float ScreenCenterX = (Viewport.Width /2.0f);
	float ScreenCenterY = (Viewport.Height /2.0f);
	float ScreenBottomY = (Viewport.Height);

DWORD dwGFX			= (DWORD)GetModuleHandleA(PointBlanki3Gfx1);
RenderContext *pRC	= (RenderContext*)(dwGFX + OFS_RDATA);

//=========================================================================//

class dxESP;

class dxESP
{
public:
	int GetTeam(char MyT);
	void DrawString(int x, int y, DWORD color, const char *fmt, ...);
	bool ADDXW2S(LPDIRECT3DDEVICE9 pDevice,D3DVECTOR Player,D3DVECTOR &PlayerScaled); 
	void PrintText(char pString[], int x, int y, D3DCOLOR col, ID3DXFont *font);
	void DrawRect ( long X, long Y, long W, long H, D3DCOLOR Color );
	void DrawLineRect( long X, long Y, long W, long H, D3DCOLOR Color );
	void Crosshairzz(LPDIRECT3DDEVICE9 pDevice, D3DCOLOR Color);
	void DrawBoxz( int x, int y, int w, int h, D3DCOLOR BoxColor, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice );
	void GarisGrentong  ( long Xa, long Ya, long Xb, long Yb, DWORD dwWidth, float Health);
	void DrawLine ( long Xa, long Ya, long Xb, long Yb, DWORD dwWidth, D3DCOLOR Color );
	void DrawBorder( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice );
	void DrawBoxESP(int x, int y, int w, int h, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice);
	void DrawBox( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice );
	void FillRGB( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice );
	void DrawPoint(int x, int y, int w, int h, D3DCOLOR color, LPDIRECT3DDEVICE9 pDevice );
	void DrawCircle(D3DXVECTOR2 Pos,float Radius,int Sides,D3DCOLOR Color,IDirect3DDevice9* pDevice);
	void Healthbarnew(LPDIRECT3DDEVICE9 pDevice,float x, float y, float Health);
	float FindDistance(D3DXVECTOR3 my,D3DXVECTOR3 other,CPlayers* pPlayer,CPlayers* pLocal);
	int __stdcall GetDistance( long x1, long x2, long y1, long y2 );
};

class GM;
class CHANGENICK1;
class CHANGENICK2;
class CHANGENICK3;
class CHANGENICK4;

class GM
{
public:
BYTE iRank; //0x0000
char _0x0001[15];
WORD iHack; //0x0010

};//Size=0x0012


class CHANGENICK1
{
public:
DWORD iName1;
};

class CHANGENICK2
{
public:
DWORD iName2;
};

class CHANGENICK3
{
public:
DWORD iName3;
};

class CHANGENICK4
{
public:
DWORD iName4;
};

float FindDistance(D3DXVECTOR3 my,D3DXVECTOR3 other,CPlayers* pPlayer,CPlayers* pLocal)
{
	return sqrt((pLocal->pos.x-pPlayer->pos.x)*(pLocal->pos.x-pPlayer->pos.x) + (pLocal->pos.y-pPlayer->pos.y)*(pLocal->pos.y-pPlayer->pos.y) + (pLocal->pos.z-pPlayer->pos.z)*(pLocal->pos.z-pPlayer->pos.z));
}


//=========================================================================//

int dxESP::GetTeam(char MyTeam)
{
for(int i = 0; i < 16; i+=2)
if(i == MyTeam)return 2; // Index = Genap, maka team adalah Tero
for(int i = 1; i< 16; i+=2)
if(i == MyTeam)return 1; // Index = Ganjil, maka team adalah CT
return -1; // return -1 jika area dari index tidak dari 0 sampai 15
}

//=========================================================================//

void dxESP::PrintText(char pString[], int x, int y, D3DCOLOR col, ID3DXFont *font)
{
    RECT FontRect = { x, y, x+500, y+50 };
    font->DrawText( NULL, pString, -1, &FontRect, DT_LEFT | DT_WORDBREAK, col);
}

//=========================================================================//

void dxESP::DrawLine ( long Xa, long Ya, long Xb, long Yb, DWORD dwWidth, D3DCOLOR Color )
{
	D3DXVECTOR2 vLine[ 2 ];
	pLine->SetAntialias( 0 );

	pLine->SetWidth( (float)dwWidth );
	pLine->Begin();

	vLine[ 0 ][ 0 ] = (float)Xa;
	vLine[ 0 ][ 1 ] = (float)Ya;
	vLine[ 1 ][ 0 ] = (float)Xb;
	vLine[ 1 ][ 1 ] = (float)Yb;

	pLine->Draw( vLine, 2, Color );
	pLine->End();
}

//=========================================================================//

bool dxESP::ADDXW2S(LPDIRECT3DDEVICE9 pDevice, D3DVECTOR Player,D3DVECTOR &PlayerScaled)
{
   D3DXVECTOR3 PlayerPos(Player.x,Player.y,Player.z);
	D3DXMATRIX identity;
    D3DXVECTOR3 vScreen;
	pDevice->GetViewport(&Viewport);
	Viewport.X = Viewport.Y = 0;
    Viewport.MinZ     = 0;
    Viewport.MaxZ     = 1;
	D3DXVec3Project(&vScreen, &PlayerPos, &Viewport, &pRC->pRenderData->ProjMatrix, &pRC->pRenderData->ViewMatrix, &pRC->pRenderData->World);
  
 if (vScreen.z < 1.0f && vScreen.x > 0.0f && vScreen.y > 0.0f && vScreen.x < Viewport.Width && vScreen.y < Viewport.Height)
 {
     PlayerScaled.x = vScreen.x;
     PlayerScaled.y = vScreen.y ;
     PlayerScaled.z = vScreen.z;

  return true; 
 }
 return false;
}

//=========================================================================//

void dxESP::DrawString(int x, int y, DWORD color, const char *fmt, ...)
{
	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	
	fSmall->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}

//=========================================================================//

void dxESP::DrawRect ( long X, long Y, long W, long H, D3DCOLOR Color )
{
        D3DXVECTOR2 vLine[ 2 ];
        pLine->SetWidth( (float) W );
        pLine->SetAntialias( 0 );
        pLine->SetGLLines( 1 );
 
        pLine->SetWidth( (float) W );
        pLine->Begin();
 
                vLine[ 0 ][ 0 ] = (float)X+W/2;
                vLine[ 0 ][ 1 ] = (float)Y;
                vLine[ 1 ][ 0 ] = (float)X+W/2;
                vLine[ 1 ][ 1 ] = (float)Y+H;
 
        pLine->Draw( vLine, 2, Color );
        pLine->End();
}

void dxESP::DrawLineRect( long X, long Y, long W, long H, D3DCOLOR Color )
{
       
        DrawRect( X, Y, W, LR_WIDTH, Color );
        DrawRect( X, Y, LR_WIDTH, H, Color );
       
        DrawRect( X + W, Y, LR_WIDTH, H, Color );
        DrawRect( X, Y + H, W, LR_WIDTH, Color );
}

//=========================================================================//

bool DRW2S(LPDIRECT3DDEVICE9 pDevice, D3DVECTOR Player,D3DVECTOR &PlayerScaled)
{
   D3DXVECTOR3 PlayerPos(Player.x,Player.y,Player.z);
	D3DXMATRIX identity;
    D3DXVECTOR3 vScreen;
	pDevice->GetViewport(&Viewport);
	Viewport.X = Viewport.Y = 0;
    Viewport.MinZ     = 0;
    Viewport.MaxZ     = 1;
	D3DXVec3Project(&vScreen, &PlayerPos, &Viewport, &pRC->pRenderData->ProjMatrix, &pRC->pRenderData->ViewMatrix, &pRC->pRenderData->World);
  
 if (vScreen.z < 1.0f && vScreen.x > 0.0f && vScreen.y > 0.0f && vScreen.x < Viewport.Width && vScreen.y < Viewport.Height)
 {
     PlayerScaled.x = vScreen.x;
     PlayerScaled.y = vScreen.y ;
     PlayerScaled.z = vScreen.z;

  return true; 
 }
 return false;
}
float dxESP::FindDistance(D3DXVECTOR3 my,D3DXVECTOR3 other,CPlayers* pPlayer,CPlayers* pLocal)
{
	return sqrt((pLocal->pos.x-pPlayer->pos.x)*(pLocal->pos.x-pPlayer->pos.x) + (pLocal->pos.y-pPlayer->pos.y)*(pLocal->pos.y-pPlayer->pos.y) + (pLocal->pos.z-pPlayer->pos.z)*(pLocal->pos.z-pPlayer->pos.z));
}

//=========================================================================//

void DrawLineBone ( long Xa, long Ya, long Xb, long Yb, DWORD dwWidth, D3DCOLOR Color )
{
	D3DXVECTOR2 vLine[ 2 ];
	pLine->SetAntialias( 0 );

	pLine->SetWidth( (float)dwWidth );
	pLine->Begin();

	vLine[ 0 ][ 0 ] = (float)Xa;
	vLine[ 0 ][ 1 ] = (float)Ya;
	vLine[ 1 ][ 0 ] = (float)Xb;
	vLine[ 1 ][ 1 ] = (float)Yb;

	pLine->Draw( vLine, 2, Color );
	pLine->End();
}

//=========================================================================//

bool GetBonePos(CGameCharaBase*m_CharaBase,D3DXVECTOR3 &outpos,int BoneIndex)
{
outpos.x = m_CharaBase->m_BoneContext->m_Bone[BoneIndex].m_Bone._41;
outpos.y = m_CharaBase->m_BoneContext->m_Bone[BoneIndex].m_Bone._42;
outpos.z = m_CharaBase->m_BoneContext->m_Bone[BoneIndex].m_Bone._43;
return true;
}

//=========================================================================//

void DrawBone(CGameCharaBase* m_CharaBase,int Start,int End,DWORD Color,LPDIRECT3DDEVICE9 pDevice)
{
D3DXVECTOR3 vStart,vEnd;
D3DXVECTOR3 vvStart,vvEnd;
if(GetBonePos(m_CharaBase,vStart,Start))
{
if(GetBonePos(m_CharaBase,vEnd,End))
{
if(DRW2S(pDevice,vStart,vvStart))
{
if(DRW2S(pDevice,vEnd,vvEnd))
{
DrawLineBone(vvStart.x,vvStart.y,vvEnd.x,vvEnd.y,1,Color);
}
}
}
}
}

//=========================================================================//

void DrawSkeleton(CGameCharaBase* m_CharaBase,DWORD Color,LPDIRECT3DDEVICE9 pDevice)
{
float wraw = 2;
DrawBone(m_CharaBase,0,6,Color,pDevice);
DrawBone(m_CharaBase,6,10,Color,pDevice);
DrawBone(m_CharaBase,6,11,Color,pDevice);
DrawBone(m_CharaBase,0,12,Color,pDevice);
DrawBone(m_CharaBase,0,13,Color,pDevice);
DrawBone(m_CharaBase,12,14,Color,pDevice);
DrawBone(m_CharaBase,13,15,Color,pDevice);
DrawBone(m_CharaBase,14,8,Color,pDevice);
DrawBone(m_CharaBase,15,9,Color,pDevice);
}

//=========================================================================//

int __stdcall dxESP::GetDistance( long x1, long x2, long y1, long y2 )
{
	long ResA = (x1 - x2) * (x1 - x2);

	long ResB = (y1 - y2) * (y1 - y2);

	double ResC = (double)(ResA + ResB);

	return (int)sqrt( ResC );
}

//=========================================================================//

void FillRGB3( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice )
{
if( w < 0 )w = 1;
if( h < 0 )h = 1;
if( x < 0 )x = 1;
if( y < 0 )y = 1;

D3DRECT rec = { x, y, x + w, y + h };
pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}


//=========================================================================//

void dxESP::FillRGB( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice )
{
if( w < 0 )w = 1;
if( h < 0 )h = 1;
if( x < 0 )x = 1;
if( y < 0 )y = 1;
 
D3DRECT rec = { x, y, x + w, y + h };
pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}

//=========================================================================//

void dxESP::DrawBorder( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
FillRGB( x, (y + h - px), w, px, BorderColor, pDevice );
FillRGB( x, y, px, h, BorderColor, pDevice );
FillRGB( x, y, w, px, BorderColor, pDevice );
FillRGB( (x + w - px), y, px, h, BorderColor, pDevice );
}

//=========================================================================//

void dxESP::DrawBoxESP( int x, int y, int w, int h, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
DrawBorder( x, y, w, h, 1, BorderColor, pDevice );
} 

//=========================================================================//

void dxESP::DrawBoxz( int x, int y, int w, int h, D3DCOLOR BoxColor, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
FillRGB( x, y, w, h, BoxColor, pDevice );
DrawBorder( x, y, w, h, 1, BorderColor, pDevice );
}

//=========================================================================//

void dxESP::Healthbarnew(LPDIRECT3DDEVICE9 pDevice,float x, float y, float Health)
{
DWORD HPcol = GREEN;
if (Health < 90 )HPcol = GREEN;
if (Health < 70 )HPcol = ORANGE;
if (Health < 50 )HPcol = YELLOW;
if (Health < 30) HPcol = RED2;
if (Health < 15) HPcol = RED2;
DrawBorder(x-1,y-1,52,5,1,BLACK,pDevice);
FillRGB(x,y,Health/2,3,HPcol,pDevice );
}
