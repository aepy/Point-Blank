
#include <windows.h>

//-------------------------------------------------------------------------------
char *eRanks[50] ={"Trainee","Senior Trainee"};
struct CRank
{
	BYTE iRank;
};
//-------------------------------------------------------------------------------
void FillRGB( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice )
{
if( w < 0 )w = 1;
if( h < 0 )h = 1;
if( x < 0 )x = 1;
if( y < 0 )y = 1;
 
D3DRECT rec = { x, y, x + w, y + h };
pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}
//-------------------------------------------------------------------------------
void DrawBorder( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
FillRGB( x, (y + h - px), w, px, BorderColor, pDevice );
FillRGB( x, y, px, h, BorderColor, pDevice );
FillRGB( x, y, w, px, BorderColor, pDevice );
FillRGB( (x + w - px), y, px, h, BorderColor, pDevice );
}
 //-------------------------------------------------------------------------------
void Healthbarnew(LPDIRECT3DDEVICE9 pDevice,float x, float y, float Health)
{
	DWORD HPcol = GREEN;
	if (Health < 90)HPcol = YELLOW;
	if (Health < 80) HPcol = ORANGE;
	if (Health < 40) HPcol = RED;
	if (Health < 10) HPcol = BLACK;
	DrawBorder(x-1,y-1,52,5,1,BLACK,pDevice );
	FillRGB(x,y,Health/2,3,HPcol,pDevice );
}
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
void obFillRGB( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice )
{
if( w < 0 )w = 1;
if( h < 0 )h = 1;
if( x < 0 )x = 1;
if( y < 0 )y = 1;
 
D3DRECT rec = { x, y, x + w, y + h };
pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}
//-------------------------------------------------------------------------------
void obDrawBorder( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
obFillRGB( x, (y + h - px), w, px, BorderColor, pDevice );
obFillRGB( x, y, px, h, BorderColor, pDevice );
obFillRGB( x, y, w, px, BorderColor, pDevice );
obFillRGB( (x + w - px), y, px, h, BorderColor, pDevice );
}
//-------------------------------------------------------------------------------
void DrawBoxob( int x, int y, int w, int h, D3DCOLOR BoxColor, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
obFillRGB( x, y, w, h, BoxColor, pDevice );
obDrawBorder( x, y, w, h, 1, BorderColor, pDevice );
}
//-------------------------------------------------------------------------------
void DrawBoxServer( int x, int y, IDirect3DDevice9* pDevice )
{
	if( !pDevice )
		return;
   DrawBoxob( x, y, 180, 18,BLACK, BLUE, pDevice );
}
//-------------------------------------------------------------------------------
void PingServer(int x, int y, float Health, IDirect3DDevice9* pDevice)
{
	if( !pDevice )
		return;
	for (int index = 0; index <= (Health-1); index++)
	{
	D3DCOLOR HPcol = GREEN;
	if (Health == 3 )HPcol = ORANGE;
	if (Health == 2 )HPcol = ORANGE;
	if (Health == 1) HPcol = RED;
	obFillRGB(x + (index*4),y,3,14,HPcol,pDevice);
	}
}
//-------------------------------------------------------------------------------
void HealthbarServer(IDirect3DDevice9* pDevice, int x, int y, float Health)
{
	if( !pDevice )
		return;
	float Long = (Health);
	obFillRGB(x,y,Health,14,RED,pDevice );
}
//-------------------------------------------------------------------------------
void DrawString(int x, int y, DWORD color, const char *fmt, ...)
{
	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	
	fName->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}
//-------------------------------------------------------------------------------
void DrawString21(int x, int y, DWORD color, const char *fmt, ...)
{
	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	
	Title->DrawText(NULL, buf, -1, &FontPos,  DT_LEFT | DT_WORDBREAK, color);
}
//-------------------------------------------------------------------------------
void PrintText(LPD3DXFONT Font, long x, long y, D3DCOLOR fontColor, char *text, ...)
{
RECT rct;
rct.left = x - 1;
rct.right = x + 1;
rct.top = y - 1 ;
rct.bottom = y + 1;

if(!text) { return; }
va_list va_alist;
char logbuf[256] = {0};
va_start (va_alist, text);
_vsnprintf (logbuf+strlen(logbuf), sizeof(logbuf) - strlen(logbuf), text, va_alist);
va_end (va_alist);
RECT FontRect = { x, y, x, y };
Font->DrawText(0, logbuf, -1, &rct, DT_NOCLIP, fontColor);
}
void DrawStringESP(int x, int y, DWORD color, const char *fmt, ...){
RECT FontPos = { x, y, x + 200, y + 16 };
char buf[1024] = {'\0'};
va_list va_alist;
va_start(va_alist, fmt);
vsprintf_s(buf, fmt, va_alist);
va_end(va_alist);
fName->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}
void DrawStringH(float x, float y , DWORD color, const char *fmt, ...)
{ 

RECT FontPos = { x, y, x + 20, y + 10 };
char buf[1024] = {'\0'};
va_list va_alist;
va_start(va_alist, fmt);
vsprintf(buf, fmt, va_alist);
va_end(va_alist);
fName->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
} 

float FindDistance(D3DXVECTOR3 my,D3DXVECTOR3 other,CPlayers* pPlayer,CPlayers* pLocal)
{
return sqrt((pLocal->pos.x-pPlayer->pos.x)*(pLocal->pos.x-pPlayer->pos.x) + (pLocal->pos.y-pPlayer->pos.y)*(pLocal->pos.y-pPlayer->pos.y) + (pLocal->pos.z-pPlayer->pos.z)*(pLocal->pos.z-pPlayer->pos.z));
} 
void FillRGBBOX( float x, float y, float w, float h, D3DCOLOR color)
{
if( w < 0 )w = 1;
if( h < 0 )h = 1;
if( x < 0 )x = 1;
if( y < 0 )y = 1;

D3DRECT rec = { x, y, x + w, y + h };
npDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}
void DrawBorder( float x, float y, float w, float h, int px, float Health)
{

FillRGBBOX( x, (y + h - px), w, px, TeamColor);
FillRGBBOX( x, y, px, h, TeamColor);
FillRGBBOX( x, y, w, px, TeamColor);
FillRGBBOX( (x + w - px), y, px, h, TeamColor); 
  
}
void DrawBorderz( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
FillRGB( x, (y + h - px), w, px, BorderColor, pDevice );
FillRGB( x, y, px, h, BorderColor, pDevice );
FillRGB( x, y, w, px, BorderColor, pDevice );
FillRGB( (x + w - px), y, px, h, BorderColor, pDevice );
}
void DrawBoxESP( int x, int y, int w, int h, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
DrawBorder( x, y, w, h, 1, BorderColor, pDevice );
}
void HealthEqui(LPDIRECT3DDEVICE9 pDevice, int x, int y, float Health)
{
	const D3DCOLOR colours[] = { RED, RED, RED, RED, ORANGE, ORANGE, ORANGE, ORANGE, YELLOW, YELLOW, YELLOW, YELLOW, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLUE, BLUE }; // this is our order
	int boxSizeX = 2;	// you can fiddle with the box size and gap between them
	int boxSizeY = 7;
	int boxGap = 1;

for ( int i = 0 ; i < 20; i++ )
	{
		if ( Health > ( 5 * i ) )
	DrawBorderz(x-1,y-1,62,9,1,colours[i],pDevice );		
	}

for ( int i = 0 ; i < 20; i++ )
	{
		if ( Health > ( 5 * i ) )
			FillRGB(x,y, boxSizeX, boxSizeY,colours[i],pDevice);
		else
            FillRGB(x,y, boxSizeX, boxSizeY,GREY,pDevice);
		x = x + boxSizeX+ boxGap;	// will move to next tile 1 unit to the right
	}
}
void HealthEqui2(LPDIRECT3DDEVICE9 pDevice, int x, int y, float Health)
{
const int SizeY[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
const D3DCOLOR colours[] = { RED, RED, RED, RED, ORANGE, ORANGE, ORANGE, ORANGE, YELLOW, YELLOW, YELLOW, YELLOW, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLUE, BLUE }; // this is our order
int boxSizeX = 2;	// you can fiddle with the box size and gap between them
	int boxSizeY = 6;
	int boxGap = 1;
for ( int i = 0 ; i < 20; i++ )
	{
		if ( Health > ( 5 * i ) )
			FillRGB(x,y, boxSizeX, SizeY[i],colours[i],pDevice);
		else
            FillRGB(x,y, boxSizeX, SizeY[i],D3DCOLOR_ARGB(255,128,128,128),pDevice);
		x = x + boxSizeX+ boxGap;	// will move to next tile 1 unit to the right
	}
}

//-------------------------------------------------------------------------------
void DrawObserver(LPDIRECT3DDEVICE9 pDevice){
if(ESPObserver==1){
if(GetBattleState()){
int ServerRED =500;
int ServerBLUE =250;
int ServerY1 =480;
D3DVIEWPORT9 BECKYPort;
pDevice->GetViewport(&BECKYPort);
DWORD ScreenCenterX = BECKYPort.Width / 2;
DWORD ScreenCenterY = BECKYPort.Height / 2;
unsigned long dwBase	= *(DWORD*)(ResultBasePlayer2);
unsigned long dwBase2	= *(DWORD*)ResultBaseHealth2;
for (int i = 0; i <= 16; i++){
TeamScore	*TeamzScore	= (TeamScore*)((dwBase + ResultScore));
CLog		*pPing		= (CLog*)	((dwBase + ResultPing) + i * 0x1);
CKill		*pKill		= (CKill*)	((dwBase + ResultKill) + i * 0x4);
CNames		*pNames		= (CNames*)	((dwBase + ResultName) + i * 0x21);
CRank		*pRank		= (CRank*)	((dwBase + ResultSkill2) + i * 0x2B);
CHealth		*pHealth	= (CHealth*)((dwBase2 + ResultHealth) + i * 0x24);
int myTeam	= GetTeam(i);
//--------------------------------------------------------------------
if (myTeam == 1){
TeamColor = BLUE;

DrawBoxServer(ScreenCenterX + ServerBLUE + 40,(ServerY1-10)+(10*i),pDevice);
HealthbarServer(pDevice, ScreenCenterX + ServerBLUE + 65,(int)((ServerY1+2)-10)+(10*i),pHealth->CurHP);
PingServer(ScreenCenterX + ServerBLUE + 187,(int)((ServerY1+2)-10)+(10*i),pPing->iLog, pDevice);
DrawString(ScreenCenterX + ServerBLUE + 45,((ServerY1+2)-10)+(10*i),WHITE,"%d|%d   %s",pKill->bKill,pKill->bDead,pNames->szNames);
DrawString21(ScreenCenterX + ServerBLUE + 40,460,BLUE,"[Blue Team : %d]",TeamzScore->TScoreBlue);
}
//--------------------------------------------------------------------
if(myTeam ==2){
TeamColor = RED;
DrawBoxServer(ScreenCenterX - ServerRED + 40,(int)ServerY1+(10*i),pDevice);
HealthbarServer(pDevice,ScreenCenterX - ServerRED + 65,(int)(ServerY1+2)+(10*i),pHealth->CurHP);
PingServer(ScreenCenterX - ServerRED + 187,(int)(ServerY1+2)+(10*i),pPing->iLog, pDevice);
DrawString(ScreenCenterX - ServerRED + 45,(ServerY1+2)+(10*i),WHITE,"%d|%d   %s",pKill->bKill,pKill->bDead,pNames->szNames);
DrawString21(ScreenCenterX - ServerRED + 40,460,RED,"[Red Team : %d]",TeamzScore->TScoreRed);	
}}}}}
//--------------------------------------------------------------------
void EspMode (LPDIRECT3DDEVICE9 pDevice)
{

int ServerX1=100;
int ServerY1=480;
int ServerX2=900;
int ServerY2=480;
D3DXVECTOR3 ScreenPos;
unsigned long dwBase	= *(DWORD*)ResultBasePlayer2;
unsigned long dwBase2	= *(DWORD*)ResultBaseHealth2;	
CTeam		*pTeam		= ((CTeam*)(dwBase + ResultTeam));
TeamScore	*TeamzScore	= (TeamScore*)((dwBase + ResultScore));
//--------------------------------------------------------------------
char *dis		= new char[33];
//--------------------------------------------------------------------
float ScreenCenterX = (Viewport.Width /2.0f);
float ScreenCenterY = (Viewport.Height /2.0f);
float ScreenBottomY = (Viewport.Height);
//--------------------------------------------------------------------
for (int i = 0; i<=16; i++){
if (dwBase !=0){
if (dwBase2 !=0){
//--------------------------------------------------------------------
CLog		*pPing		= (CLog*)	((dwBase + ResultPing) + i * 0x1);
CKill		*pKill		= (CKill*)	((dwBase + ResultKill) + i * 0x4);
CNames		*pNames		= (CNames*)	((dwBase + ResultName) + i * 0x21);
CRank		*pRank		= (CRank*)	((dwBase + ResultSkill2) + i * 0x2B);
CHealth		*pHealth	= (CHealth*)((dwBase2 + ResultHealth) + i * 0x24);
//--------------------------------------------------------------------
int iTeam    = GetTeam(i);
			DWORD pCalculate = *(DWORD*)(dwBase + 0x4 * i + ResultPlayer );//
			DWORD pCalculate2 = *(DWORD*)(dwBase + 0x4 * pTeam->iTeam + ResultPlayer );

			CPlayers	*pPlayer	= (CPlayers*)(pCalculate + 0x64 );
			CPlayers	*pLocal	= (CPlayers*)(pCalculate2 + 0x64 );
//			Player.x	=  pPlayer->pos.x;
	//		Player.y	=  pPlayer->pos.y;
	//		Player.z	=  pPlayer->pos.z;
	//		HeadPos.x	=	pPlayer->pos.x;
	//		HeadPos.y	=	1.6f + pPlayer->pos.y;
	//		HeadPos.z	=	pPlayer->pos.z;
		//	D3DXVECTOR3 MyDistance	=	pLocal->pos - pPlayer->pos;
		//	float MyaDistance = D3DXVec3Length(&MyDistance );
		//	float PosX = 0.0f;
		//	float PosY = 0.0f;
//--------------------------------------------------------------------
int MySlot = GetTeam(GetMyCharaIndex()); 
if(GetTeam(i) == MySlot) continue; 
if (iTeam == 1){ TeamColor = RED; } // warna ESP Box
else if (iTeam == 2){ TeamColor = BLUE; }    // warna ESP Box
else{ continue;} 
//========================================================================
if( GetUserBone(vStart10,15,i)){
if( GetUserBone(vEnd10,9,i)){
if( YoWorlToScreenGa(pDevice,vStart10,vvStart10)){
if( YoWorlToScreenGa(pDevice,vEnd10,vvEnd10)){
if(YoWorlToScreenGa(pDevice,pPlayer->pos,ScreenPos)){
if (pHealth->CurHP > 1){

if (ESPHealth == 1){
 Healthbarnew(pDevice,(int)vvStart10.x-25,(int)vvEnd10.y+10,pHealth->CurHP);
}
if (ESPHealth2 == 1){
 HealthEqui(pDevice,(int)vvStart10.x-25,(int)vvEnd10.y+10,pHealth->CurHP);
}
if (ESPHealth3 == 1){
 HealthEqui2(pDevice,(int)vvStart10.x-25,(int)vvEnd10.y+10,pHealth->CurHP);
}
if (ESPLine==1){
 DrawLine((float)512,(float)384,(float)vvStart10.x,(float)vvEnd10.y,1,YELLOW);
 DrawLine((float)512,(float)0,(float)vvStart10.x,(float)vvEnd10.y,1,RED);
}
if (ESPDistance==1){
DrawStringH(ScreenPos.x-30,ScreenPos.y-25,YELLOW,"[Distance : %0.1f M]",FindDistance(pLocal->pos,pPlayer->pos,pPlayer,pLocal));
	}
if (ESPKD==1){
DrawString(ScreenPos.x-30,ScreenPos.y-35,YELLOW," KILL[ %d]DEATH[%d ]HEALTH[%0.f]",pKill->bKill,pKill->bDead,pHealth->CurHP);
DrawString(ScreenPos.x-30,ScreenPos.y-36,RED," KILL[ %d]DEATH[%d ]HEALTH[%0.f]",pKill->bKill,pKill->bDead,pHealth->CurHP);
	}
if(ESPBox == 1){
//	DrawBorder(ScreenPos.x-(10000/MyaDistance)/40,ScreenPos.y-(35000/MyaDistance)/40,50000/MyaDistance/6*2/40,50000/MyaDistance/3*2/40,2,pHealth->CurHP);
}
	}}}}}}


if (pHealth->CurHP > 1){

if (ESPName){
PrintText(fSmall,(float)vvStart10.x-15,(float)vvStart10.y - 40.0,BLUE," %s ",pNames->szNames);
PrintText(fSmall,(float)vvStart10.x-15,(float)vvStart10.y - 41.0,RED," %s ",pNames->szNames);
}
if (ESPRank){
PrintText(fSmall,(float)vvStart10.x-15,(float)vvStart10.y - 50.0,RED," %s ",eRanks[pRank->iRank]);
PrintText(fSmall,(float)vvStart10.x-15,(float)vvStart10.y - 51.0,BLUE," %s ",eRanks[pRank->iRank]);
}

}	}}}
//}
bHookedTele = false;
}//*/
void ESPBoneX(LPDIRECT3DDEVICE9 pDevice){
unsigned long dwBase       = *(DWORD*)(ResultBasePlayer2);
unsigned long A_CGameChara = *(DWORD*)(ResultBaseHealth2);
CTeam         *pTeam       = ((CTeam*)(dwBase + ResultTeam));
CGameCharaBase* m_CharaBase = NULL;
int MyTeam = GetTeam(pTeam->iTeam);
for (int i = 0; i<= 0x16;i++){
if(A_CGameChara !=0){
m_CharaBase = (CGameCharaBase*)((*(DWORD*)(A_CGameChara + 0x14 + 0x4*i)));
int iTeam = GetTeam(i);
if (iTeam == MyTeam)continue;		
if (iTeam == 1){
TeamColor = BLUE;
} 
else
if (iTeam == 2){
TeamColor = RED;
}
else{ continue;
}
if(m_CharaBase!=0)
if(m_CharaBase->m_BoneContext!=0){
if(ESPBone==1){
if(GetBattleState()){
DrawSkeleton(m_CharaBase, WHITE, pDevice);
}}}}}}