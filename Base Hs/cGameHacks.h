/*cGameHacks.h D3D9 PBHacks Last Edit By ZrC-CyB Hacks*/
#include <windows.h>
#include "cColor.h"
#include "cOptions.h"
#include "hModule.h"
#include "cFunction.h"
#include "cClass.h"
#include "KeyPresent.h"
   
int	 AimSlot = 0;
#define PISSS 3.14159265
bool AimEnable    = false;
bool BulletEnable = false;
bool bHookedTele = false;
bool AimStart = false;
bool Shot = false;
bool HookedShot = false;
bool bGhost = false;
bool bPiso  = false;
bool bAmmo	= false;
float DeltaX   = 0;    
float DeltaY   = 0;     
float fX,fY,fZ = 0;  
float MouseDeltaX, MouseDeltaY, MouseDeltaZ = 0;
DWORD GetDeltaX     = 0;  
DWORD GetDeltaY     = 0; 
DWORD BackupEDXTele = 0;
DWORD TeamColor;
DWORD BokongKill;
DWORD BurstPiso;
D3DVECTOR Player;
D3DVECTOR HeadPos;
D3DVECTOR PlayerScaled;
D3DVECTOR HeadScaled;
D3DVECTOR BonePos;
D3DVECTOR ScreenPos;

/*-------------------------------------------------------------------------------------------------------------------*/
LPDIRECT3DTEXTURE9 texRed,texBlue,texGreen,texAqua,texPurple,texWhite,texYellow,texPink,texTurquoise,texOrange,texBlack = NULL;
const BYTE bRed[60] =
{
0x42, 0x4D, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,
0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x12, 0x0B, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFF, 0x00, 0x00, 0x00
};

const BYTE bBlue[60] =
{
0x42, 0x4D, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,
0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x12, 0x0B, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0x00, 0x00, 0x00, 0x00, 0x00
};

const BYTE bGreen[60] =
{
0x42, 0x4D, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,
0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00,
0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x12, 0x0B, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x9E, 0x00, 0x00, 0x00, 0x00
};

const BYTE bAqua[58] =
{
0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,
0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0x00, 0x00
};

const BYTE bPurple[58] =
{
0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,
0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0x00, 0xFF, 0x00
};

const BYTE bWhite[58] =
{
0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,
0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0x00
};

const BYTE bYellow[60] =
{
   0x42, 0x4D, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
   0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,
   0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x12, 0x0B, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00
};

const BYTE bPink[58] =
{
   0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
   0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,
   0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x80, 0x00, 0xFF, 0x00
};

const BYTE bTurquoise[60] =
{
   0x42, 0x4D, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
   0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,
   0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x12, 0x0B, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00
};

const BYTE bOrange[60] =
{
   0x42, 0x4D, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
   0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,
   0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x12, 0x0B, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x10, 0x80, 0xF0, 0xB0, 0x00, 0x00
};

const BYTE bBlack[58] = {
    0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/*-------------------------------------------------------------------------------------------------------------------*/
void DrawTextColor(LPDIRECT3DDEVICE9 pDevice)
{
	if(texRed == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bRed, sizeof(bRed), &texRed);
	if(texBlue == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bBlue, sizeof(bBlue), &texBlue);
	if(texGreen == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bGreen, sizeof(bGreen), &texGreen);
	if(texAqua == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bAqua, sizeof(bAqua), &texAqua);
	if(texPurple == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bPurple, sizeof(bPurple), &texPurple);
	if(texWhite == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bWhite, sizeof(bWhite), &texWhite);
	if(texYellow == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bYellow, sizeof(bYellow), &texYellow);
	if(texPink == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bPink, sizeof(bPink), &texPink);
	if(texTurquoise == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bTurquoise, sizeof(bTurquoise), &texTurquoise);
	if(texOrange == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bOrange, sizeof(bOrange), &texOrange);
	if(texBlack == NULL) D3DXCreateTextureFromFileInMemory(pDevice, (LPCVOID)&bBlack, sizeof(bBlack), &texBlack);
}

/*---------------------------------------- Declaration D3DTLVERTEX ----------------------------------------------------*/
struct D3DTLVERTEX
{
	float fX;
	float fY;
	float fZ;
	float fRHW;
	D3DCOLOR Color;
	float fU;
	float fV;
};

D3DTLVERTEX CreateD3DTLVERTEX (float X, float Y, float Z, float RHW, D3DCOLOR color, float U, float V)
{
	D3DTLVERTEX v;
	v.fX = X;
	v.fY = Y;
	v.fZ = Z;
	v.fRHW = RHW;
	v.Color = color;
	v.fU = U;
	v.fV = V;
	return v;
}

/*---------------------------------------- Declaration Circle ----------------------------------------------------*/
void Circle( float x, float y, float rad, bool center, DWORD color ,LPDIRECT3DDEVICE9 pDevice)
{
	const int NUMPOINTS = 34;

	if(!center)
	{
		x -= rad;
		y -= rad;
	}

	D3DTLVERTEX Circle[NUMPOINTS + 1];
	int i;
	float X;
	float Y;
	float Theta;
	float WedgeAngle;
	WedgeAngle = (float)( (2*PISSS) / NUMPOINTS );
	for( i=0; i<=NUMPOINTS; i++ )
	{
		Theta = i * WedgeAngle;
		X = (float)( x + rad * cos(Theta) );
		Y = (float)( y - rad * sin(Theta) );
		Circle[i] = CreateD3DTLVERTEX( X, Y, 0.0f, 1.0f, color, 0.0f, 0.0f );
	}
	pDevice->SetFVF( D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1 );
	pDevice->SetTexture( 0, NULL );
	pDevice->DrawPrimitiveUP( D3DPT_LINESTRIP, NUMPOINTS, &Circle[0], sizeof(Circle[0]) );
}

/*---------------------------------------- Declaration FillRGB ----------------------------------------------------*/
void FillRGB( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice )
{
	if( w < 0 )w = 1;
	if( h < 0 )h = 1;
	if( x < 0 )x = 1;
	if( y < 0 )y = 1;
	D3DRECT rec = { x, y, x + w, y + h };
	pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}

/*---------------------------------------- Declaration DrawPoint ----------------------------------------------------*/
void DrawPoint(int x, int y, int w, int h, D3DCOLOR color, LPDIRECT3DDEVICE9 pDevice )
{
    FillRGB((int)x, (int)y, (int)w, (int)h, color,pDevice);
}

/*---------------------------------------- Declaration DrawBorder ----------------------------------------------------*/
void DrawBorder( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
	FillRGB( x, (y + h - px), w, px, BorderColor, pDevice );
	FillRGB( x, y, px, h, BorderColor, pDevice );
	FillRGB( x, y, w, px, BorderColor, pDevice );
	FillRGB( (x + w - px), y, px, h, BorderColor, pDevice );
}

/*---------------------------------------- Declaration DrawBoxESP ----------------------------------------------------*/
void DrawBoxESP( int x, int y, int w, int h, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
	DrawBorder( x, y, w, h, 1, BorderColor, pDevice );
} 

/*---------------------------------------- Declaration DrawBoxESP ----------------------------------------------------*/
void HealthBar(LPDIRECT3DDEVICE9 pDevice,float x, float y, float Health)
{
	DWORD HPcol = GREEN;
	if (Health < 90)HPcol = YELLOW;
	if (Health < 80) HPcol = ORANGE;
	if (Health < 40) HPcol = RED;
	if (Health < 10) HPcol = BLACK;
	FillRGB(x-1,y-1,52,5,GREY,pDevice );
	DrawBorder(x-1,y-1,52,5,1,BLACK,pDevice );
	FillRGB(x,y,Health/2,3,HPcol,pDevice );
}
/*---------------------------------------- Declaration DrawString ----------------------------------------------------*/
void DrawString(int x, int y, DWORD color, const char *fmt, ...)
{
	RECT FontPos = { x, y, x + 300, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	
	g_pFont->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP , color);
	g_pFont->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP , BLACK);
	g_pFont->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP , BLACK);
	g_pFont->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP , BLACK);
	g_pFont->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP , BLACK);
}


/*---------------------------------------- Declaration Team ----------------------------------------------------*/
int GetTeam(char MyTeam)
{
	for(int i = 0; i < 16; i+=2)
		if(i == MyTeam)return 2;
	for(int i = 1; i< 16; i+=2)
		if(i == MyTeam)return 1;
	return -1; 
}

/*---------------------------------------- Declaration BattleState ----------------------------------------------------*/
bool GetBattleState() 
{ 
	unsigned long xBase = *(DWORD*)(ResultBaseAmmo2); 
	if(xBase > NULL)
	{ 
		return true; 
	} return false; 
}

/*---------------------------------------- Declaration MyCharaIndex ----------------------------------------------------*/
int GetMyCharaIndex()
{
	unsigned long dwBase	= *(DWORD*)(ResultBasePlayer2);
	CTeam *MyTeam = (CTeam*) ((dwBase + ResultTEAM));
	return MyTeam->iTeam;
}

/*---------------------------------------- Declaration PlayerTarget ----------------------------------------------------*/
DWORD GetPlayerTarget(int MyIdx)
{
	DWORD BasePlayer_B = *(DWORD*)(ResultBaseHealth2);
	if(IsBadReadPtr((void*)BasePlayer_B,4))return 0;
	DWORD PlayerIndexA = *(DWORD*)(BasePlayer_B + 0x14 + (MyIdx * 4));
	if(IsBadReadPtr((void*)PlayerIndexA,4))return 0;
	DWORD PlayerIndexB = *(DWORD*)(PlayerIndexA + ResultPTRpTarget);
	if(IsBadReadPtr((void*)PlayerIndexB,4))return 0;
	DWORD IsTargetingEnemy = *(DWORD*)(PlayerIndexB + ResultPTRpTarget2);
	if(IsBadReadPtr((void*)IsTargetingEnemy,4))return 0;
	return IsTargetingEnemy;
}

/*---------------------------------------- Declaration TargetIndex ----------------------------------------------------*/
int GetTargetIndex(DWORD PlayerTarget)
{
	DWORD BasePlayer_B = *(DWORD*)(ResultBaseHealth2);
	if(PlayerTarget && BasePlayer_B){
		for(int i = 0; i<=15; i++){
			DWORD PlayerIndexA = *(DWORD*)(BasePlayer_B + 0x14 + (i * 4));
			if(PlayerIndexA == PlayerTarget)return i;
		}
	}
	return -1;
}

/*---------------------------------------- Declaration CalcDistance ----------------------------------------------------*/
float CalcDistance( D3DXVECTOR3 VecA, D3DXVECTOR3 VecB )
{
        return sqrt( ( ( VecA.x - VecB.x ) * ( VecA.x - VecB.x ) ) +
                 ( ( VecA.y - VecB.y ) * ( VecA.y - VecB.y ) ) +
                 ( ( VecA.z - VecB.z ) * ( VecA.z - VecB.z ) ) );
}

/*---------------------------------------- Declaration IsAlive ----------------------------------------------------*/
bool IsAlive(int Index)
{
	unsigned long dwBase2	= *(DWORD*)(ResultBaseHealth2);
	CHealth		*Health		= (CHealth*) ((dwBase2 + ResultHEALTH) + Index * ResultHEALTHSIZE);
	if(Health->CurHP > 0.1f)
		return true;
	return false;
}

/*---------------------------------------- Declaration UserVector ----------------------------------------------------*/
D3DXVECTOR3 GetUserVector( int Index )
{
	DWORD ADR_PLAYER = *(DWORD*)(ResultBasePlayer2);
	DWORD OldProtect;
	DWORD pCalculate = *(DWORD*)(ADR_PLAYER + 4 * Index + ResultPLAYER );
	VirtualProtect ( (LPVOID)(pCalculate), sizeof (pCalculate), PAGE_EXECUTE_READWRITE, &OldProtect );
	CPlayers	*Players	= (CPlayers*)(pCalculate + 0x64 );
	VirtualProtect ( (LPVOID)(pCalculate), sizeof (pCalculate), OldProtect, &OldProtect );
	return Players->pos;
}

/*---------------------------------------- Declaration UserBone ----------------------------------------------------*/
bool GetUserBone( D3DXVECTOR3 &Out, int Idx, int BoneIdx )
{
	unsigned long dwGameBase = *(DWORD*)(ResultBaseHealth2);
	if ( dwGameBase )
	{
		CGameCharaBase* GameBase = (CGameCharaBase*)( *(DWORD*)(dwGameBase + 0x14 + ( 0x4 * Idx ) ) );
		if ( GameBase && GameBase->m_BoneContext )
		{
			Out.x = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._41;
			Out.y = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._42;
			Out.z = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._43;
			return true;
		}
	}
	return false;
}

/*---------------------------------------- Declaration Target_World ----------------------------------------------------*/
int AutomaticTarget_World()
{
	int Result = -1;
	float NearDistance = 1000.0f;
	int MyTeam = GetTeam(GetMyCharaIndex());
	if(!IsAlive(GetMyCharaIndex()))return Result;
	for(int i = 0; i<=16; i++)
	{
		int TargetTeam = GetTeam(i);
		if(TargetTeam == MyTeam)continue;
		if(TargetTeam == 0)continue;
		if ( IsAlive(i) )
		{
			D3DXVECTOR3 Head;
			if ( GetMyCharaIndex( ) %2 != i % 2 && GetUserBone( Head, i, 7.7 ) )
			{
				if(CalcDistance(GetUserVector(GetMyCharaIndex()),GetUserVector(i)) < NearDistance)
				{
					NearDistance = CalcDistance(GetUserVector(GetMyCharaIndex()),GetUserVector(i));
					Result = i;
				}
			}
		}
	}
	return Result;
}

/*---------------------------------------- Declaration WorldToScreen ----------------------------------------------------*/
bool ADDXW2S(LPDIRECT3DDEVICE9 pDevice, D3DVECTOR Player,D3DVECTOR &PlayerScaled)
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

/*---------------------------------------- Declaration DrawLineBone ----------------------------------------------------*/
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

/*---------------------------------------- Declaration GetBonePos ----------------------------------------------------*/
bool GetBonePos(CGameCharaBase*m_CharaBase,D3DXVECTOR3 &outpos,int BoneIndex)
{
	outpos.x = m_CharaBase->m_BoneContext->m_Bone[BoneIndex].m_Bone._41;
	outpos.y = m_CharaBase->m_BoneContext->m_Bone[BoneIndex].m_Bone._42;
	outpos.z = m_CharaBase->m_BoneContext->m_Bone[BoneIndex].m_Bone._43;
	return true;
}

/*---------------------------------------- Declaration DrawBone ----------------------------------------------------*/
void DrawBone(CGameCharaBase* m_CharaBase,int Start,int End,DWORD Color,LPDIRECT3DDEVICE9 pDevice)
{
	D3DXVECTOR3 vStart,vEnd;
	D3DXVECTOR3 vvStart,vvEnd;
	if(GetBonePos(m_CharaBase,vStart,Start))
	{
		if(GetBonePos(m_CharaBase,vEnd,End))
		{
			if(ADDXW2S(pDevice,vStart,vvStart))
			{
				if(ADDXW2S(pDevice,vEnd,vvEnd))
				{
					DrawLineBone(vvStart.x,vvStart.y,vvEnd.x,vvEnd.y,1,Color);
				}
			}
		}
	}
}

/*---------------------------------------- Declaration DrawSkeleton ----------------------------------------------------*/
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

/*---------------------------------------- Declaration AutoShoot ----------------------------------------------------*/
_declspec(naked)void MouseHook()
{
	_asm {
		cmp [Shot],0
			je Normal
			mov eax, 1;
		ret
Normal:
		mov eax, [ecx+0x20]
		ret
	}
}

/*---------------------------------------- Declaration AsmAimBot ----------------------------------------------------*/
__declspec(naked)void Aim_DeltaX()
{
	_asm
	{
		cmp AimHead,1
			je StartAim
NORMAL:
		fld dword ptr [ecx+0x14]
		ret
StartAim:
		cmp AimEnable,0
			je NORMAL
			fld dword ptr[MouseDeltaX]
		ret 
	}
}

__declspec(naked)void Aim_DeltaY()
{
	_asm
	{
		cmp AimHead,1
			je StartAim
NORMAL:
		fld dword ptr [ecx+0x18]
		ret
StartAim:
		cmp AimEnable,0
			je NORMAL
			fld dword ptr[MouseDeltaY]
		ret 
	}
}

/*---------------------------------------- Declaration AsmAimBullet ----------------------------------------------------*/
_declspec(naked)void i3CollideeLine_SetEnd()
{
	_asm
	{
		cmp [BulletEnable],0
			je Skip
			mov eax,dword ptr ss:[esp+0x4]
		mov [BackupEDXTele],edx
			mov edx,[fX]
		mov [eax+0],edx
			mov edx,[fY]
		mov [eax+4],edx
			mov edx,[fZ]
		mov [eax+8],edx
			mov edx,[BackupEDXTele]
Skip:
		mov eax,dword ptr ss:[esp+0x4]
		fld dword ptr ds:[eax]
		fstp dword ptr ds:[ecx+0x18]
		fld dword ptr ds:[eax+0x4]
        fstp dword ptr ds:[ecx+0x1C]
        fld dword ptr ds:[eax+0x8]
        fstp dword ptr ds:[ecx+0x20]
        fld dword ptr ds:[ecx+0x18]
        fsub dword ptr ds:[ecx+0x0C]
        fstp dword ptr ds:[ecx+0x24]
        fld dword ptr ds:[ecx+0x1C]
        fsub dword ptr ds:[ecx+0x10]
		fstp dword ptr ds:[ecx+0x28]
        fld dword ptr ds:[ecx+0x20]
        fsub dword ptr ds:[ecx+0x14]
        fstp dword ptr ds:[ecx+0x2C]
        retn 0x4                             
	}
}

/*---------------------------------------- Declaration CallAimBot ----------------------------------------------------*/
void Thread_Aimbot()
{
	MakePTR((PBYTE)ResultDeltaX,(DWORD)Aim_DeltaX);
	MakePTR((PBYTE)ResultDeltaY,(DWORD)Aim_DeltaY);
}

/*---------------------------------------- Declaration AimBot ----------------------------------------------------*/
void DoAimBot(LPDIRECT3DDEVICE9 pDevice)
{
	unsigned long dwBase	= *(DWORD*)(ResultBasePlayer2);
	int ScreenCenterX = (g_ViewPort.Width /2.0f);
	int ScreenCenterY = (g_ViewPort.Height /2.0f);
		if(AimHead)
		{
			int AimSlot = AutomaticTarget_World();
			if(AimSlot != -1)
			{
				D3DXVECTOR3 OnWorld,OnScreen;
				int BoneIndexSelector = 0;
				switch(AimBody)
				{
				case 0:
					BoneIndexSelector = 7.0;
					break;
				case 1:
					BoneIndexSelector = 5;
					break;
				}
				if(GetUserBone(OnWorld,AimSlot,BoneIndexSelector)){
					if(ADDXW2S(pDevice,OnWorld,OnScreen))
					{
						int x = ( GetSystemMetrics( 0 ) / 2);
						int y = ( GetSystemMetrics( 1 ) / 2);
						if(RainbowTexts!=100)
						{RainbowR-=2,RainbowG-=3,RainbowB-=3;}
						if(RainbowTexts!=255)
						{RainbowR+=2,RainbowG+=3,RainbowB+=4;}
						Circle (OnScreen.x, OnScreen.y,6,true,RainbowTextTest,pDevice);
						FillRGB(OnScreen.x-10, OnScreen.y, 7, 1,RainbowTextTest,pDevice);
						FillRGB(OnScreen.x+4, OnScreen.y, 7, 1,RainbowTextTest,pDevice);
						FillRGB(OnScreen.x, OnScreen.y-10, 1, 7,RainbowTextTest,pDevice);
						FillRGB(OnScreen.x, OnScreen.y+4, 1, 7,RainbowTextTest,pDevice);
						AimEnable = true;
						int LocalX = OnScreen.x;
						int LocalY = OnScreen.y;
						if(LocalX == ScreenCenterX && LocalY == ScreenCenterY)
						{ 
							MouseDeltaX = 0;
							MouseDeltaY = 0;
						}
						else
						{
							MouseDeltaX = LocalX - ScreenCenterX;
							MouseDeltaY = LocalY - ScreenCenterY;
						}
					}
					else
					{
						AimEnable = false;
					}
				}
				else
				{
					AimEnable = false;
				}
			}
			else
			{
				AimEnable = false;
			}
		}
		else
		{
			AimEnable = false;
		}
	}

/*---------------------------------------- Declaration CallAimBullet ----------------------------------------------------*/
void HookTelekill()
{
	if(bHookedTele)return;
	MakePTR((PBYTE)ResultBullet,(DWORD)i3CollideeLine_SetEnd);
	bHookedTele = true;
}

/*---------------------------------------- Declaration AimBullet ----------------------------------------------------*/
void DoAimBullet(LPDIRECT3DDEVICE9 pDevice){
	if(Accuracy==1)
	{
		int AimSlot = AutomaticTarget_World();
		if(AimSlot != -1)
		{
			D3DXVECTOR3 OnWorld,OnScreen;
			int BoneIndexSelector = 0;
			switch(AimBody)
			{
			case 0:
				BoneIndexSelector = 7.0;
				break;
			case 1:
				BoneIndexSelector = 5;
				break;
			}
			if(GetUserBone(OnWorld,AimSlot,BoneIndexSelector)){
				BulletEnable = true;
				fX = OnWorld.x;
				fY = OnWorld.y + 0.1f;
				fZ = OnWorld.z;
				if(ADDXW2S(pDevice,OnWorld,OnScreen))
				{
					int x = ( GetSystemMetrics( 0 ) / 2);
					int y = ( GetSystemMetrics( 1 ) / 2);
					if(RainbowTexts!=100)
					{RainbowR-=2,RainbowG-=3,RainbowB-=3;}
					if(RainbowTexts!=255)
					{RainbowR+=2,RainbowG+=3,RainbowB+=4;}
					Circle (OnScreen.x, OnScreen.y,6,true,RainbowTextTest,pDevice);
					FillRGB(OnScreen.x-10, OnScreen.y, 7, 1,RainbowTextTest,pDevice);
					FillRGB(OnScreen.x+4, OnScreen.y, 7, 1,RainbowTextTest,pDevice);
					FillRGB(OnScreen.x, OnScreen.y-10, 1, 7,RainbowTextTest,pDevice);
					FillRGB(OnScreen.x, OnScreen.y+4, 1, 7,RainbowTextTest,pDevice);
				}
			}
			else
			{
				BulletEnable = false;
			}
		}
		else
		{
			BulletEnable = false;
		}
	}
	if(Accuracy == 0 && !Accuracy)
	{
		BulletEnable = false;
	}
}

/*---------------------------------------- Declaration AutoShoot ----------------------------------------------------*/
void DoAutoShot()
{
	if(HookedShot == false){
		MakePTR((PBYTE)ResultGetButton,(DWORD)MouseHook);
		HookedShot = true;
	}
	if(AutoShot==1){
		if(GetPlayerTarget(GetMyCharaIndex()) > NULL)Shot = true;
		else Shot = false;
	}
}

/*---------------------------------------- Declaration AutoHeadShoot ----------------------------------------------------*/
void DoAutoHSNoSyarat(LPDIRECT3DDEVICE9 pDevice)
{
	if(AutoHS2 == 1)
	{
		DWORD pMyTarget = GetPlayerTarget(GetMyCharaIndex());
		if(pMyTarget > NULL)
		{
			DWORD TargetIndex = GetTargetIndex(pMyTarget);
			D3DXVECTOR3 OnWorld,OnScreen;
			GetUserBone(OnWorld,TargetIndex,7.0);
			BulletEnable = true;
			fX = OnWorld.x;
			fY = OnWorld.y + 0.1f;
			fZ = OnWorld.z;
		}
		else BulletEnable = false;
	}
	if(AutoHS2 == 0 && !AutoHS2)
	{
		BulletEnable = false;
	}
}

/*---------------------------------------- Declaration AutoBody ----------------------------------------------------*/
void DoAutoBody(LPDIRECT3DDEVICE9 pDevice)
{
	if(AutoBody == 1)
	{
		DWORD pMyTarget = GetPlayerTarget(GetMyCharaIndex());
		if(pMyTarget > NULL)
		{
			DWORD TargetIndex = GetTargetIndex(pMyTarget);
			D3DXVECTOR3 OnWorld,OnScreen;
			GetUserBone(OnWorld,TargetIndex,5);
			BulletEnable = true;
			fX = OnWorld.x;
			fY = OnWorld.y + 0.1f;
			fZ = OnWorld.z;
		}
		else BulletEnable = false;
	}
	if(AutoBody == 0 && !AutoBody)
	{
		BulletEnable = false;
	}
}

/*---------------------------------------- Declaration All Esp ----------------------------------------------------*/
void DrawESP(LPDIRECT3DDEVICE9 pDevice)
{
	unsigned long dwBase	= *(DWORD*)(ResultBasePlayer2);
	unsigned long dwBase2	= *(DWORD*)(ResultBaseHealth2);	
	CTeam		*pTeam		= ((CTeam*)(dwBase + ResultTEAM));

	CGameCharaBase* m_CharaBase = NULL;

	float ScreenCenterX = (Viewport.Width /2.0f);
	float ScreenCenterY = (Viewport.Height /2.0f);
	float ScreenBottomY = (Viewport.Height);

	int MyTeam = GetTeam(pTeam->iTeam);
	if(*(PBYTE)ResultBaseAmmo2 > NULL){
		for (int i = 0; i<=0x16;i++)
		{
				CNames		*pNames		= (CNames*)((dwBase + ResultNAMES) + i * ResultNAMESIZE);
				CHealth		*pHealth	= (CHealth*)((dwBase2 + ResultHEALTH) + i * ResultHEALTHSIZE);
				CHealth		*mHealth	= (CHealth*)((dwBase2 + ResultHEALTH) + pTeam->iTeam * ResultHEALTHSIZE);
				DWORD ADR_PLAYER		= *(DWORD*)(ResultBasePlayer2);
				DWORD OldProtect;
				DWORD pCalculate		= *(DWORD*)(ADR_PLAYER + 0x4 * i + ResultPLAYER );
				DWORD pCalculate2		= *(DWORD*)(ADR_PLAYER + 0x4 * pTeam->iTeam + ResultPLAYER );
				VirtualProtect ( (LPVOID)(pCalculate), sizeof (pCalculate), PAGE_EXECUTE_READWRITE, &OldProtect );
				VirtualProtect ( (LPVOID)(pCalculate2), sizeof (pCalculate2), PAGE_EXECUTE_READWRITE, &OldProtect );
				CPlayers	*pPlayer	= (CPlayers*)(pCalculate + 0x64 );
				CPlayers	*pLocal		= (CPlayers*)(pCalculate2 + 0x64 );
				VirtualProtect ( (LPVOID)(pCalculate), sizeof (pCalculate), OldProtect, &OldProtect );
				VirtualProtect ( (LPVOID)(pCalculate2), sizeof (pCalculate2), OldProtect, &OldProtect );
				Player.x				=  pPlayer->pos.x;
				Player.y				=  pPlayer->pos.y;
				Player.z				=  pPlayer->pos.z;
				HeadPos.x				=  pPlayer->pos.x;
				HeadPos.y				=  1.6f + pPlayer->pos.y;
				HeadPos.z				=  pPlayer->pos.z;
				
				D3DXVECTOR3 MyDistance	=	pLocal->pos - pPlayer->pos;
				float MyaDistance = D3DXVec3Length(&MyDistance );

				int iTeam	= GetTeam(i);
				if (iTeam == MyTeam)continue;
				
				D3DXVECTOR3 OnWorld,OnScreen;
				if(ADDXW2S(pDevice,Player,PlayerScaled))
				{
					if (pHealth->CurHP > 1)
					{
						/*---------------------------- Declaration Esp Health ----------------------------------------*/
						if (ESPHealth)
						{
							HealthBar(pDevice,(float)PlayerScaled.x-25,(float)PlayerScaled.y+5,pHealth->CurHP);
						}
					}
				}

				/*--------------------------------- Declaration Esp Name ---------------------------------------------*/
				if(GetUserBone(OnWorld,i,7))
				{
					if (ADDXW2S(pDevice,OnWorld,OnScreen))
					{
						if (pHealth->CurHP > 1) 
						{
							if(ESPName)
							{
								DrawString((float)OnScreen.x-9	,OnScreen.y-35	,RED,	"%s",pNames->szNames);
								DrawString((float)OnScreen.x-9	,OnScreen.y-35	,BLACK,	"%s",pNames->szNames);
								DrawString((float)OnScreen.x-9	,OnScreen.y-35	,BLACK,	"%s",pNames->szNames);
							}
							
							/*---------------------------- Declaration Esp Head ----------------------------------------*/
							if (ESPHead)
							{
								FillRGB((float)OnScreen.x, (float)OnScreen.y, 3, 3,YELLOW, pDevice );
							}

							/*---------------------------- Declaration Esp Bone ----------------------------------------*/
							if (ESPBone)
							{
									m_CharaBase = (CGameCharaBase*)((*(DWORD*)(dwBase2 + 0x14 + 0x4*i)));
									if(m_CharaBase!=0)
										if(m_CharaBase->m_BoneContext!=0)
										{
											DrawSkeleton(m_CharaBase, WHITE, pDevice);
										}
							}
						}
					}
				}
		}
	}
}

/*---------------------------------------- Declaration Suicide ----------------------------------------------------*/
typedef void (__thiscall * tCmd_Damage)(DWORD CGameCharaLocalBase, int HPDrain, int a2, int a3);
tCmd_Damage Cmd_Damage;

void KillMySelf()
{
	Cmd_Damage = (tCmd_Damage)(ResultSuicide);
	DWORD CGameCharaLocalBase = *(DWORD*)(ResultBaseAmmo2);
	Cmd_Damage(CGameCharaLocalBase,0xFF,0xFFFF,false);
}

/*---------------------------------------- Declaration GhostHide ----------------------------------------------------*/
void GhostHide()
{
	DWORD PactPBexe = *(DWORD *)ResultBasePlayer2;
	CTeam* GetCSlot	= (CTeam*)(PactPBexe + ResultTEAM);
	if(bGhost == false){
		BokongKill = Read( ResultBaseHealth2, ResultHEALTH-0x4 + GetCSlot->iTeam * ResultHEALTHSIZE);
	}
	if(Zombie == 0){
		bGhost = false;
		WritePtr( ResultBaseHealth2, ResultHEALTH-0x4 + GetCSlot->iTeam * ResultHEALTHSIZE, BokongKill);
	}
	if(Zombie == 1){
		bGhost = true;
		WritePtr( ResultBaseHealth2, ResultHEALTH-0x4 + GetCSlot->iTeam * ResultHEALTHSIZE, BokongKill-1);
	}
}

/*---------------------------------------- Declaration Hacks ----------------------------------------------------*/
DWORD WINAPI ThreadHaxAll()
{
	if(GetBattleState()){
	if(Rspw == 1)
	{
		WritePtr(ResultBaseAmmo2, ResultPTRRepeat, 0x40);
	}}

	if(GetBattleState()){
	if(FallDamage == 1)
	{
		WritePtr(ResultBaseAmmo2, ResultPTRFall, 0x64047214);
	}}

	if(AntiOut == 1)
	{
		LongPtr(ResultBaseIdle2, 0x18, ResultPTRIdle, 0x41);
		LongPtr(ResultBaseIdle2, 0x18, ResultPTRIdle2, 0x42);
	}

	if(GetBattleState()){
	if(FreeMove == 1)
	{
		_WriteMEM(ResultBaseMove2, 0x44, 0x18, 0xDC, 0x4);
	}}

	if(autoGM == 1)
	{
		unsigned long dwBase	= *(DWORD*)(ResultBasePlayer2);
		CTeam *pTeam		= ((CTeam*)(dwBase + ResultTEAM)); 
		int MyTeam = GetTeam(pTeam->iTeam);
			GM			*DualDinamic = (GM*)((dwBase + ResultSKILL2)+ pTeam->iTeam * ResultRANKSIZE);
			CNames		*pFake	     = (CNames*)((dwBase + ResultNAMES) + pTeam->iTeam  * ResultNAMESIZE);
			if(autoGM == 1)
			{
				DualDinamic->iRank = 0x36;
				DualDinamic->iHack = 0xFFFFFF;
				strcpy(pFake->szNames,"{/COL}"); // max 16 angka/huruf
			}
	}
	
	if(autoGM == 2)
	{
		unsigned long dwBase	= *(DWORD*)(ResultBasePlayer2);
		CTeam *pTeam		= ((CTeam*)(dwBase + ResultTEAM)); 
		int MyTeam = GetTeam(pTeam->iTeam);
			GM			*DualDinamic = (GM*)((dwBase + ResultSKILL2)+ pTeam->iTeam * ResultRANKSIZE);
			CNames		*pFake		 = (CNames*)((dwBase + ResultNAMES) + pTeam->iTeam  * ResultNAMESIZE);
			if(autoGM == 2)
			{
				DualDinamic->iRank = 0x35;
				DualDinamic->iHack = 0xFFFFFF;
				strcpy(pFake->szNames,"FUCKGMPB!!!"); // max 16 angka/huruf
			}
	}
	
	if(GetBattleState()){
	if(BombEnywhere == 1)
	{
		cGameBases *GameBase = (cGameBases*) *(DWORD*)(ResultBasePlayer2);
		DWORD dwBase = *(DWORD*)(ResultBasePlayer2);
		CTeam *pTeam				= ((CTeam*)(dwBase + ResultTEAM)); 
		DWORD pCalculate2 = *(DWORD*)(dwBase + 0x4 * pTeam->iTeam + ResultPLAYER);
		CPlayers	*Me	= (CPlayers*)(pCalculate2 + 0x64 );
		if(BombEnywhere == 1)
		{
			GameBase->StageInfo->BombPositionA.x = Me->pos.x;
			GameBase->StageInfo->BombPositionA.y = Me->pos.y;
			GameBase->StageInfo->BombPositionA.z = Me->pos.z;
		}
	}}
	
	if(GetBattleState()){
	if(BombEnywhere == 2)
	{
		cGameBases *GameBase = (cGameBases*) *(DWORD*)(ResultBasePlayer2);
		DWORD dwBase = *(DWORD*)(ResultBasePlayer2);
		CTeam *pTeam				= ((CTeam*)(dwBase + ResultTEAM)); 
		DWORD pCalculate2 = *(DWORD*)(dwBase + 0x4 * pTeam->iTeam + ResultPLAYER);
		CPlayers	*Me	= (CPlayers*)(pCalculate2 + 0x64 );
		if(BombEnywhere == 2)
		{
			GameBase->StageInfo->BombPositionB.x = Me->pos.x;
			GameBase->StageInfo->BombPositionB.y = Me->pos.y;
			GameBase->StageInfo->BombPositionB.z = Me->pos.z;
		}
	}}

	if(GetBattleState()){
	if (BugWS == 0)
	{
		PacthHook((void *)(ResultBugUnyu),(void*)(PBYTE)"\xBE",1);
	}}
	if(GetBattleState()){
	if (BugWS == 1)
	{
		PacthHook((void *)(ResultBugUnyu),(void*)(PBYTE)"\xC0",1);
	}}

	if(GetBattleState()){
	if (BugDt == 0)
	{
		PacthHook((void *)(NxCha+ResultDatar+0x2),(void*)(PBYTE)"\x34",1);
	}}
	if(GetBattleState()){
	if (BugDt == 1)
	{
		PacthHook((void *)(NxCha+ResultDatar+0x2),(void*)(PBYTE)"\x38",1);
	}}

	/*-------------------------------------------------------------------------------------------------------------------*/
	if(GetBattleState()){
	if( bPiso == false )
	{
		BurstPiso	= _ReadMEM(ResultBaseAmmo2, ResultPTRWeapon, ResultMALESIZE, ResultPTRCaclKnife);
	}
	if(BstPs == 0)
	{
		bPiso = false;
		_WriteMEM(ResultBaseAmmo2, ResultPTRWeapon, ResultMALESIZE, ResultPTRCaclKnife, BurstPiso);
	}
	if(BstPs == 1)
	{
		bPiso = true;
		_WriteMEM(ResultBaseAmmo2, ResultPTRWeapon, ResultMALESIZE, ResultPTRCaclKnife, BurstPiso);
	}}
	
	if(GetBattleState()){
	if(qece == 1)
	{
		_WriteMEM(ResultBaseAmmo2, ResultPTRQC, 0x3C, 0x64, 0x3FC28F5B);
	}}

	if(GetBattleState()){
	if(FsSht == 1)
	{
		WritePtr(ResultBaseAmmo2, ResultPTRFShot, 0);
	}}

	if(GetBattleState()){
	if(frpid == 1)
	{
		LongPtr(ResultBaseAmmo2, ResultPTRWeapon, 0x38, 1);
		LongPtr(ResultBaseAmmo2, ResultPTRWeapon, 0x38, 0);
		LongPtr(ResultBaseAmmo2, 0x30, ResultPTRRapid, 0);
		WritePtr(ResultBaseAmmo2, ResultPTRFShot, 0);
	}}

	if(GetBattleState()){
	if(Nrld == 1)
	{
		_patchPTR(ResultBaseAmmo2, ResultPTRWeapon, ResultPRIMARYSIZE, 0x30, 0x67, 65);
		_patchPTR(ResultBaseAmmo2, ResultPTRWeapon, ResultSECONDARYSIZE, 0x30, 0x67, 65);
	}}
	
	if(GetBattleState()){
	if(wutmo == 1)
	{
		if(bAmmo == false)
		{
			__ReadMem(ResultBaseAmmo2, ResultPTRWeapon, ResultPRIMARYSIZE, ResultPTRCaclAmmo, 1);
			__ReadMem(ResultBaseAmmo2, ResultPTRWeapon, ResultSECONDARYSIZE, ResultPTRCaclAmmo, 2);
			bAmmo = true;
		}
		if(bAmmo == true)
		{
			_WriteMEM(ResultBaseAmmo2, ResultPTRWeapon, ResultPRIMARYSIZE, ResultPTRCaclAmmo, Weapon);
			_WriteMEM(ResultBaseAmmo2, ResultPTRWeapon, ResultSECONDARYSIZE, ResultPTRCaclAmmo, Pistol);
		}
	}}

	/*--------------------------------*/
	if(GetBattleState()){
	if(IsKeyPressed(VK_END, 0)&1)
	{
		KillMySelf();
	}}

	if(GetBattleState()){
	if(IsKeyPressed(VK_RMENU, 0)&1){
		AimHead=!AimHead;
	}}

	if(GetBattleState()){
	if(IsKeyPressed(VK_LSHIFT, 0)&1){
		Accuracy=!Accuracy;
	}}

	if(GetBattleState()){
	if(IsKeyPressed(VK_CAPITAL, 0)&1){
		AutoHS2=!AutoHS2;
	}}

	if(GetBattleState()){
	if(IsKeyPressed(VK_RSHIFT, 0)&1){
		AutoBody=!AutoBody;
	}}

	if(GetBattleState()){
	if(IsKeyPressed(VK_LMENU, 0)&1){
		Zombie=!Zombie;
	}}

	if(GetBattleState()){
	if(IsKeyPressed(VK_F6, 0)&1){
		BugWS=!BugWS;
	}}

	if(GetBattleState()){
	if(IsKeyPressed(VK_F7, 0)&1){
		BugDt=!BugDt;
	}}
	
	return (0);
}


/*-------------------------------------------------------------------------------------------------------------------*/