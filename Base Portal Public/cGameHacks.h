/*cGameHacks.h D3D9 PBHacks Last Edit By Angga Reviza*/
#include <windows.h>
#include "cColor.h"
#include "cOptions.h"
#include "hModule.h"
#include "cFunction.h"
#include "cClass.h"
#include "KeyPresent.h"

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
void HealthNew(LPDIRECT3DDEVICE9 pDevice, int x, int y, float Health)
{
	const D3DCOLOR colours[] = { RED, RED, RED, RED, ORANGE, ORANGE, ORANGE, ORANGE, YELLOW, YELLOW, YELLOW, YELLOW, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLUE, BLUE }; // this is our order
	int boxSizeX = 2;	// you can fiddle with the box size and gap between them
	int boxSizeY = 7;
	int boxGap = 1;

for ( int i = 0 ; i < 20; i++ )
	{
		if ( Health > ( 5 * i ) )
	DrawBorder(x-1,y-1,62,9,1,colours[i],pDevice );		
	}

for ( int i = 0 ; i < 20; i++ )
	{
		if ( Health > ( 5 * i ) )
			FillRGB(x,y, boxSizeX, boxSizeY,colours[i],pDevice);
		else
            FillRGB(x,y, boxSizeX, boxSizeY,GREY,pDevice);
	//DrawBorder(x-1,y-1,50,6,1,BLACK,npDevice);
		x = x + boxSizeX+ boxGap;	// will move to next tile 1 unit to the right
	}
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

/*---------------------------------------- Declaration GetUserBonePos2 ----------------------------------------------------*/
D3DXVECTOR3 GetUserBonePos2(int Idx ,int BoneIdx)
{
D3DXVECTOR3 Out;
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA("PointBlank.exe");
unsigned long dwGameBase = *(DWORD*)(dwI3EXEC + ResultBaseHealth);
if ( dwGameBase )
{
CGameCharaBase* GameBase = (CGameCharaBase*)( *(DWORD*)(dwGameBase + 0x14 + ( 0x4 * Idx ) ) );
if ( GameBase && GameBase->m_BoneContext )
{
Out.x = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._41;
Out.y = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._42;
Out.z = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._43;
}}
return Out;
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
					int COLOR = SKYBLUE;
					Circle (OnScreen.x, OnScreen.y,6,true,COLOR,pDevice);
					FillRGB(OnScreen.x-10, OnScreen.y, 7, 1,COLOR,pDevice);
					FillRGB(OnScreen.x+4, OnScreen.y, 7, 1,COLOR,pDevice);
					FillRGB(OnScreen.x, OnScreen.y-10, 1, 7,COLOR,pDevice);
					FillRGB(OnScreen.x, OnScreen.y+4, 1, 7,COLOR,pDevice);
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

/*---------------------------------------- Declaration Bullet Killerz & Smoke Killerz ----------------------------------------------------*/
DWORD dwBasett,dwBasettt,dwBasetttt,baseALEXCallHitEvent,baseDoLineColly,basegetVCPos;
LPTSTR PointBlankSTR8 = "PointBlank.exe";
/*----------------------------------------------------------------------------------*/
bool IsAlivedf(int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR8);
unsigned long dwBase2	= *(DWORD*)(dwI3EXEC + ResultBaseHealth);
CHealth		*Health		= (CHealth*) ((dwBase2 + 0x264) + Index * 0x24);
if(Health->CurHP > 0.1f)
return true;
return false;
}

/*----------------------------------------------------------------------------------*/
int GetTeam1(int JONES)
{
for(int i = 0; i<=15; i+=2)
if( i == JONES ) return 1;
for(int i = 1; i<=15; i+=2)
if( i == JONES ) return 2;
return 0;
}

/*----------------------------------------------------------------------------------*/
DWORD NayzAngels1st(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
C=*(PDWORD)((DWORD)(C))+dwOfs2;
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return *(PDWORD)C; 
} }
} 
return C;
}

/*----------------------------------------------------------------------------------*/
DWORD NayzAngels2st(DWORD dwPtr, DWORD dwOfs){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return *(PDWORD)C; 
} 
} 
return C;
}

/*----------------------------------------------------------------------------------*/
DWORD NayzAngels3st(DWORD dwPtr){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=(*(DWORD*)(dwPtr)); 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return C; 
} 
} 
return C;
}

/*----------------------------------------------------------------------------------*/
DWORD NayzAngels4st(DWORD dwPtr){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=((DWORD)dwPtr); 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return C; 
} 
} 
return C;
}

/*----------------------------------------------------------------------------------*/
int GetMyCharaIndexed(unsigned int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR8);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + ResultBasePlayer);
CTeam *MyTeam = (CTeam*) ((dwBase + ResultTEAM));
Index=MyTeam->iTeam;
return Index;
}

/*----------------------------------------------------------------------------------*/
#define basegetVCPoss resultbasegetVCPoss
DWORD getVCPosa(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk)
{
dwBasettt = NayzAngels2st(ResultBaseAmmo2, 0x554);
basegetVCPos = NayzAngels4st(ResultCamPos);
if (!dwBasettt)return 0;
DWORD getVCPosss;
if (dwBasettt)
{
getVCPosss = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))basegetVCPos)(dwBasettt, Vect, Mat, iUnk);
}
return getVCPosss;
}

/*----------------------------------------------------------------------------------*/
#define baseDoLineCollyy resultbaseDoLineCollyy
int Target;

/*----------------------------------------------------------------------------------*/
D3DXVECTOR3 OnWorld,OnScreen;
DWORD NayzCyber1st(UINT i)
{
D3DXVECTOR3	vBone, vLocal;
DWORD DoLineCollyyy;
int BoneIndexSelector;
switch(AimBody)
{
	case 0: BoneIndexSelector = 7.7; break;
	case 1: BoneIndexSelector = 5;   break;
}
dwBasett   = NayzAngels1st(ResultBaseAmmo2, 0x544 , 0x34);
baseDoLineColly = NayzAngels4st (ResultDoLine);
getVCPosa(&vLocal,0,0);
vBone = GetUserBonePos2(i,BoneIndexSelector);
if (dwBasett)
{
DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
}
return DoLineCollyyy;
}

/*----------------------------------------------------------------------------------*/
DWORD NayHit1st(UINT i)
{
D3DXVECTOR3	vEnemy;
DWORD ALEXCallHitEventtt;
dwBasett   = NayzAngels1st(ResultBaseAmmo2, 0x544, 0x1C);
dwBasetttt   = NayzAngels3st(ResultBaseAmmo2);
baseALEXCallHitEvent = NayzAngels4st(ResultEventFire);
getVCPosa(&vEnemy,0,0);
if (dwBasett)
{
ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
}
return ALEXCallHitEventtt;
}

/*----------------------------------------------------------------------------------*/
void NayzLine1st()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(IsAlivedf(i)){
NayzCyber1st(i);
}
}
}
/*----------------------------------------------------------------------------------*/
void NayzHitEvent1st()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
NayHit1st(i);
if(IsAlivedf(i)){				
NayHit1st(i);
}
}
}
/*----------------------------------------------------------------------------------*/
DWORD NayzCyber2st(UINT i)
{
D3DXVECTOR3	vBone, vLocal;
DWORD DoLineCollyyy,DoLineCollyyy2,DoLineCollyyy3,DoLineCollyyy4,DoLineCollyyy5,DoLineCollyyy6,DoLineCollyyy7;
DWORD DoLineCollyyy8,DoLineCollyyy9,DoLineCollyyy0,DoLineCollyyy11,DoLineCollyyy12,DoLineCollyyy13,DoLineCollyyy14,DoLineCollyyy15;
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
       case 0:  BoneIndexSelector = 7.7;   break;
			case 1: BoneIndexSelector = 5;  break;
				case 2: BoneIndexSelector = 2;  break;
					case 3: BoneIndexSelector = 0;  break;
						 case 4: BoneIndexSelector = 12;   break;
							  case 5:  BoneIndexSelector = 13;   break;
									  case 6: BoneIndexSelector = 14;  break;
										   case 7: BoneIndexSelector = 15;   break;
												case 8: BoneIndexSelector = 8;   break;
													 case 9:  BoneIndexSelector = 9;   break;
														  case 10:  BoneIndexSelector = 10;   break;
															   case 11:  BoneIndexSelector = 11;  break;
					}
dwBasett   = NayzAngels1st(ResultBaseAmmo2, 0x544 , 0x2C);
baseDoLineColly = NayzAngels4st (ResultDoLine);
getVCPosa(&vLocal,0,0);
vBone = GetUserBonePos2(i,BoneIndexSelector);
if(DAMAGESMOKE){
if (dwBasett){
DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy2 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy3 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy4 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy5 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy6 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy7 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy8 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy9 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy0 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy11 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy12 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy13 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy14 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
DoLineCollyyy15 = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
	}}}}
return DoLineCollyyy;
return DoLineCollyyy2;
return DoLineCollyyy3;
return DoLineCollyyy4;
return DoLineCollyyy5;
return DoLineCollyyy6;
return DoLineCollyyy7;
return DoLineCollyyy8;
return DoLineCollyyy9;
return DoLineCollyyy0;
return DoLineCollyyy11;
return DoLineCollyyy12;
return DoLineCollyyy13;
return DoLineCollyyy14;
return DoLineCollyyy15;
			}

/*----------------------------------------------------------------------------------*/
DWORD NayHit2st(UINT i)
{
D3DXVECTOR3	vEnemy;
DWORD ALEXCallHitEventtt;
dwBasett   = NayzAngels1st(ResultBaseAmmo2, 0x544, 0x2C);
dwBasetttt   = NayzAngels3st(ResultBaseAmmo2);
baseALEXCallHitEvent = NayzAngels4st(ResultEventFire);
getVCPosa(&vEnemy,0,0);
if (dwBasett)
{
ALEXCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
}
return ALEXCallHitEventtt;
}

/*----------------------------------------------------------------------------------*/
void NayzLine2st()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(IsAlivedf(i)){
NayzCyber2st(i);
}
}
}

/*----------------------------------------------------------------------------------*/
void NayzHitEvent2st()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
NayHit2st(i);
if(IsAlivedf(i)){				
NayHit2st(i);
}
}
}

/*----------------------------------------------------------------------------------*/
void BULLETFUNCTION()
{
if(GetBattleState()){
if(BulletCall){
NayzLine1st();
DamageBulletCall=1;
}
if(BulletCall==0){
DamageBulletCall=0;
}
if(DamageBulletCall==1){
NayzHitEvent1st();
}}}

/*----------------------------------------------------------------------------------*/
void WPSMOKEFUNCTION()
{
if(GetBattleState()){
if(SmokeCall){
NayzLine2st();
DamageCall=1;
DAMAGESMOKE=1;
}
if(SmokeCall==0){
DamageCall=0;
DAMAGESMOKE=0;
}
if(DamageCall==1){
NayzHitEvent2st();
}}}

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
						if(ESPHealth==1)
						{
							HealthNew(pDevice,(int)PlayerScaled.x-30,(int)PlayerScaled.y+15,pHealth->CurHP);
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
											DrawSkeleton(m_CharaBase, RainbowTextTest, pDevice);
										}
							}
						}
					}
				}
		}
	}
if(Cross)
	{
		D3DVIEWPORT9 viewP;
		pDevice->GetViewport( &viewP );
		DWORD ScreenCenterX = viewP.Width / 2; 
		DWORD ScreenCenterY = viewP.Height / 2; 

		D3DRECT rec1 = {ScreenCenterX-35, ScreenCenterY, ScreenCenterX+ 35, ScreenCenterY+1};
		D3DRECT rec2 =	{ScreenCenterX, ScreenCenterY-35, ScreenCenterX+ 1,ScreenCenterY+35};  

		if(Cross==1)
		{	
			D3DRECT rec10 = {ScreenCenterX-6, ScreenCenterY, ScreenCenterX+ 6, ScreenCenterY+1};
			D3DRECT rec11 = {ScreenCenterX, ScreenCenterY-6, ScreenCenterX+ 1,ScreenCenterY+6};  
			pDevice->Clear( 1, &rec10, D3DCLEAR_TARGET, D3DXCOLOR(0.0, 1.0, 0.0, 1.0), 0,  0 );// green
			pDevice->Clear( 1, &rec11, D3DCLEAR_TARGET, D3DXCOLOR(0.0, 1.0, 0.0, 1.0), 0,  0 );

			D3DRECT rec12 = {ScreenCenterX-4, ScreenCenterY, ScreenCenterX+ 4, ScreenCenterY+1};
			D3DRECT rec13 = {ScreenCenterX, ScreenCenterY-4, ScreenCenterX+ 1,ScreenCenterY+4};  
			pDevice->Clear( 1, &rec12, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 1.0, 0.0, 1.0), 0,  0 );// yellow
			pDevice->Clear( 1, &rec13, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 1.0, 0.0, 1.0), 0,  0 );

			D3DRECT rec16 = {ScreenCenterX-1, ScreenCenterY, ScreenCenterX+ 1, ScreenCenterY+1};
			D3DRECT rec17 = {ScreenCenterX, ScreenCenterY-1, ScreenCenterX+ 1,ScreenCenterY+1};  
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), 0,  0 );//red
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), 0,  0 );
		}
		if(Cross==2)
		{	
			D3DRECT rec16 = {ScreenCenterX-2, ScreenCenterY-2, ScreenCenterX+ 2, ScreenCenterY+2};
			D3DRECT rec17 = {ScreenCenterX-2, ScreenCenterY-2, ScreenCenterX+ 2,ScreenCenterY+2};  
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), 0,  0 );//red
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), 0,  0 );
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

/*---------------------------------------- Declaration Fake Replace ----------------------------------------------------*/
typedef void (__thiscall * tSetCharaWeaponSet)(DWORD CGameCharaManager,DWORD CGameCharaBase, DWORD pNetCharaInfo); 
tSetCharaWeaponSet SetCharaWeaponSet;

DWORD CGameCharaBaseShoot(void) 
{ 
unsigned long dwBase = *(DWORD*)ResultBasePlayer2-0x34; 
return dwBase; 
}

void FakeAbal(){
if(GetBattleState()){ 
if(On==1){
DWORD ModuleHandle = (DWORD)GetModuleHandle("PointBlank.exe");
DWORD BasePlayer_A = *(DWORD*)(ModuleHandle + ResultBasePlayer);
DWORD BasePlayer_B = *(DWORD*)(ModuleHandle + ResultBaseHealth);
int MyIndex = GetMyCharaIndex();
DWORD CGameCharaManager = CGameCharaBaseShoot();
DWORD CGameCharaBase = *(DWORD*)(BasePlayer_B + 0x14 + (MyIndex*4));
DWORD pNetCharaInfo = BasePlayer_A + ((ResultRESPAWN) + (MyIndex*0x158)); 
SetCharaWeaponSet = (tSetCharaWeaponSet)ResultFakeReplace;
SetCharaWeaponSet(CGameCharaManager, CGameCharaBase, pNetCharaInfo);
}}}

#define OFS_Primary			0x28178
#define OFS_Secondary		0x2817C
#define OFS_Melee			0x28180
#define OFS_Explosive		0x28184
#define OFS_Special			0x28188
#define OFS_Helm			0x27EF8
//----------------------------------------------------------------------
//                       [ OFS_ReplaceBOM ]							
//----------------------------------------------------------------------
#define OFS_Soccer				0x35E20D79
#define Candy_Granade			0x35E20D6C
#define Lantern_Grenade			0x35E20D6F
#define Decoy_Bomb				0x35E20D72
#define Bread_Grenade			0x35E20D70
#define WP_Smoke				0x35E20D64
#define WP_SmokeD				0x35E20D5D
/*---------------------------------------- Declaration Hacks ----------------------------------------------------*/
DWORD WINAPI ThreadHaxAll()
{
	if(autoGM==1)
		{
		DWORD dwI3EXEC	= (DWORD)GetModuleHandleA("PointBlank.exe");
		unsigned long dwBase	= *(DWORD*)(dwI3EXEC + ResultBasePlayer);
		CTeam *pTeam		= ((CTeam*)(dwBase + ResultTEAM)); 
		int MyTeam = GetTeam(pTeam->iTeam);
		for (int i = 0; i <= 15 ; i++)
			{
			GM	  *DualDinamic   = (GM*)((dwBase + ResultSKILL2)+ pTeam->iTeam * ResultRANKSIZE);
			HackName	  *Name	 = (HackName*)((dwBase + ResultNAMES)+ pTeam->iTeam * ResultNAMESIZE);
			HackName2	  *Name2 = (HackName2*)((dwBase + ResultNAMES+0x4)+ pTeam->iTeam * ResultNAMESIZE);
			HackName3	  *Name3 = (HackName3*)((dwBase + ResultNAMES+0x8)+ pTeam->iTeam * ResultNAMESIZE);
			HackName4	  *Name4 = (HackName4*)((dwBase + ResultNAMES+0xC)+ pTeam->iTeam * ResultNAMESIZE);
			if(autoGM==1)
				{
				MakePoint(ResultBasePlayer2, 0x27E70 + (pTeam->iTeam*0x158), 0x41AF3B3E);
				MakePoint(ResultBasePlayer2, 0x27E6C + (pTeam->iTeam*0x158), 0x41AF3B3F);
				DualDinamic->iRank = 0x35;
				DualDinamic->iHack = 0xFFFFFF;
				Name->iName1=0x4D476B637546;//Fuck
				Name2->iName2=0x4D47;//GM
				}
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

	DWORD PactPBexe = *(DWORD *)ResultBasePlayer2;
	CTeam* GetCSlot	= (CTeam*)(PactPBexe + ResultTEAM);
	if(bGhost == false){
		BokongKill = Read( ResultBaseHealth2, ResultHEALTH-0x4 + GetCSlot->iTeam * ResultHEALTHSIZE);
	}
	if(Ghost == 0){
		bGhost = false;
		WritePtr( ResultBaseHealth2, ResultHEALTH-0x4 + GetCSlot->iTeam * ResultHEALTHSIZE, BokongKill);
	}
	if(Ghost == 1){
		bGhost = true;
		WritePtr( ResultBaseHealth2, ResultHEALTH-0x4 + GetCSlot->iTeam * ResultHEALTHSIZE, BokongKill-1);
	}

	DWORD PactPBexe1 = *(DWORD *)ResultBasePlayer2;
	CTeam* GetCSlot1 = (CTeam*)(PactPBexe1 + ResultTEAM);
	if(bGhost == false){
		BokongKill = Read( ResultBaseHealth2, ResultHEALTH-0x4 + GetCSlot1->iTeam * ResultHEALTHSIZE);
	}
	if(Zombie == 0){
		bGhost = false;
		WritePtr( ResultBaseHealth2, ResultHEALTH-0x4 + GetCSlot1->iTeam * ResultHEALTHSIZE, BokongKill);
	}
	if(Zombie == 1){
	KillMySelf();
		bGhost = true;
		WritePtr( ResultBaseHealth2, ResultHEALTH-0x4 + GetCSlot1->iTeam * ResultHEALTHSIZE, BokongKill-1);
	}

	if (antigyg == 1) 
		{ 
			for( int iR = 32; iR <= 108; iR += 4 )
				LongPtr(ResultBaseAmmo2, ResultPTRRecoil, iR, 0);
		}

	if(BP_Invi ==1)
		{
			DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
			DWORD GM = ModulePB + ResultInvi;
				PrivateOnly((void *)(GM),(int*)(PBYTE)"\x6F\x12\x83\x40",4);
		}
	if(BP_Invi ==0)
		{
			DWORD ModulePB = (DWORD)GetModuleHandleA("PointBlank.exe");
			DWORD GM = ModulePB + ResultInvi;
				PrivateOnly((void *)(GM),(int*)(PBYTE)"\x6F\x12\x83\x3C",4);
		}

	if(GetBattleState()){
	if(FreeMove == 1)
	{
		_WriteMEM(ResultBaseMove2, 0x44, 0x18, 0xDC, 0x4);
	}}

	if(AntiOut == 1)
	{
		LongPtr(ResultBaseIdle2, 0x18, ResultPTRIdle, 0x41);
		LongPtr(ResultBaseIdle2, 0x18, ResultPTRIdle2, 0x42);
	}

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

	if(NoLife ==1)
	{
		PatchValue(ResultBaseAmmo2, 0x18, 0x18, 0xE8, 0x01);
	}

if(GetBattleState()){
if(Rep_Item){
	for (int i = 0; i <=16;i++)
		switch(Rep_Item){
		case 1: MakePoint(ResultBasePlayer2 ,OFS_Special + (i * 0x158),OFS_Soccer		); break;
		case 2: MakePoint(ResultBasePlayer2 ,OFS_Special + (i * 0x158),Candy_Granade	); break;
		case 3: MakePoint(ResultBasePlayer2 ,OFS_Special + (i * 0x158),Lantern_Grenade	); break;
		case 4: MakePoint(ResultBasePlayer2 ,OFS_Special + (i * 0x158),Decoy_Bomb		); break;
		case 5: MakePoint(ResultBasePlayer2 ,OFS_Special + (i * 0x158),Bread_Grenade	); break;
		case 6: MakePoint(ResultBasePlayer2 ,OFS_Special + (i * 0x158),WP_Smoke		); break;
		case 7: MakePoint(ResultBasePlayer2 ,OFS_Special + (i * 0x158),WP_SmokeD		); break; 
			}}
}
	if(GetBattleState()){ 
	if(R_Launcher){
	for (int i = 0; i <=16;i++)
	switch(R_Launcher){
	case 1: MakePoint(ResultBasePlayer2 ,OFS_Primary		+ (i * 0x158),0x5F5ECEC); break;
	case 2: MakePoint(ResultBasePlayer2 ,OFS_Primary		+ (i * 0x158),0x5F5ECC3); break;
	case 3: MakePoint(ResultBasePlayer2 ,OFS_Primary		+ (i * 0x158),0x5F5ECF2); break;
	case 4: MakePoint(ResultBasePlayer2 ,OFS_Primary		+ (i * 0x158),0x5F5ECFC); break;
	case 5: MakePoint(ResultBasePlayer2 ,OFS_Primary		+ (i * 0x158),0x5F5ED18); break;
	case 6: MakePoint(ResultBasePlayer2 ,OFS_Primary		+ (i * 0x158),0x5F5ECE5); break;
	case 7: MakePoint(ResultBasePlayer2 ,OFS_Primary		+ (i * 0x158),0x5F61F82); break;
	case 8: MakePoint(ResultBasePlayer2 ,OFS_Secondary		+ (i * 0x158),0x23D2902A); break;
		}
	}
	}

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

	if(GetBattleState()){
	if(Nrld == 1)
	{
		_patchPTR(ResultBaseAmmo2, ResultPTRWeapon, ResultPRIMARYSIZE, 0x30, 0x67, 65);
		_patchPTR(ResultBaseAmmo2, ResultPTRWeapon, ResultSECONDARYSIZE, 0x30, 0x67, 65);
	}}

	if(GetBattleState()){
	if(qece == 1)
	{
		_WriteMEM(ResultBaseAmmo2, ResultPTRQC, 0x3C, 0x64, 0x3FC28F5B);
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

	if(WShoot ==1)
	{
		DWORD Pointblank = (DWORD)LoadLibraryA("Pointblank.exe"); 
			PrivateOnly((void *)(Pointblank + ResultWallshoot),(int*)(PBYTE)"\x90\x90",2);
	}
	if(WShoot ==0)
	{ 
		DWORD Pointblank = (DWORD)LoadLibraryA("Pointblank.exe"); 
			PrivateOnly((void *)(Pointblank + ResultWallshoot),(int*)(PBYTE)"\x75\x1F",2);
	}

	if(GetBattleState()){
	if(JumpHight==1)
		{
		if (GetAsyncKeyState(VK_SPACE)&&0x8000)
			{
				{
				if(IsBadReadPtr((void*)ResultBaseAmmo2,4)==0)
					{
					DWORD TheRead = *(PDWORD)((DWORD)(ResultBaseAmmo2))+0x548;
					if(IsBadReadPtr((void*)TheRead,4)==0)
						{
						DWORD ReadKe1 = *(PDWORD)((DWORD)(TheRead))+0x98;
						DWORD ReadKe2 = *(PDWORD)((DWORD)(TheRead))+0x9C;
						if(IsBadReadPtr((void*)ReadKe1,4)==0)
							{
							*(PDWORD)ReadKe1=0x00000000;
							}
						if(IsBadReadPtr((void*)ReadKe2,4)==0)
							{
							*(PDWORD)ReadKe2=0x00000000;
							}
						}
					}
				}
			}
		}
	}

	if(BrustMode==1)
		{
			if((GetKeyState(VK_LBUTTON) & 0x80) != 0)
				{
					FakeAbal();
				}
				else
			{
			Sleep(1);
			}
	}
	return (0);
}

/*---------------------------------------- Declaration BypassNick ----------------------------------------------------*/
void CallByPassNick(void) // Call To EndScene
{
	PacthHook((void *)(0x508C8A),(void*)(PBYTE)"\xEB",1);
	PacthHook((void *)(0x508CBD),(void*)(PBYTE)"\xEB",1);
	PacthHook((void *)(0x508CF0),(void*)(PBYTE)"\xEB",1);
	PacthHook((void *)(0x508D29),(void*)(PBYTE)"\xEB",1);
	PacthHook((void *)(0x508D5C),(void*)(PBYTE)"\xEB",1);
	PacthHook((void *)(0x508D92),(void*)(PBYTE)"\xEB",1);
	PacthHook((void *)(0x508DC8),(void*)(PBYTE)"\xEB",1);
}
/*-------------------------------------------------------------------------------------------------------------------*/