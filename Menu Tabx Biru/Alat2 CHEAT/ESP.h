/*ESP.h D3D9 PBHacks Last Edit By Fatur Rezo*/
#include <windows.h>

/*-------------------------------------------------------------------------------------------------------------------*/
bool bHookedTele = false;
char *eRanks[50] ={"Trainee","Senior Trainee"};

/*-------------------------------------------------------------------------------------------------------------------*/
struct CRank
{
	BYTE iRank;
};

/*---------------------------------------- Declaration GetTeam ----------------------------------------------------*/
int GetTeamLol(char MyT);;
int GetTeamLol(char MyT)
{
	if(bHookedTele == true)
	{
		if (MyT == 0 ||MyT == 2||MyT == 4||MyT == 6||MyT == 8||MyT == 10||MyT == 12||MyT == 14)
			return 1;
		else
			if (MyT == 1 ||MyT == 3||MyT == 5||MyT == 7||MyT == 9||MyT == 11||MyT == 13||MyT == 15)
				return 2;
		bHookedTele = false;
	}
	return 0;
}

/*---------------------------------------- Declaration FillRGB ----------------------------------------------------*/
void FillRGB( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice ){
	if( w < 0 )w = 1;
	if( h < 0 )h = 1;
	if( x < 0 )x = 1;
	if( y < 0 )y = 1;
	D3DRECT rec = { x, y, x + w, y + h };
	pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}

/*---------------------------------------- Declaration PrintText ----------------------------------------------------*/
void PrintText(char pString[], int x, int y, D3DCOLOR col, ID3DXFont *font){
	RECT FontRect = { x, y, x+500, y+30 };
	fName->DrawText( NULL, pString, -1, &FontRect, DT_LEFT | DT_WORDBREAK, col);
}

/*---------------------------------------- Declaration DrawBorder ----------------------------------------------------*/
void DrawBorder( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice ){
	FillRGB( x, (y + h - px), w, px, BorderColor, pDevice );
	FillRGB( x, y, px, h, BorderColor, pDevice );
	FillRGB( x, y, w, px, BorderColor, pDevice );
	FillRGB( (x + w - px), y, px, h, BorderColor, pDevice );
}

/*---------------------------------------- Declaration Healthbarnew ----------------------------------------------------*/
void Healthbarnew(LPDIRECT3DDEVICE9 pDevice,float x, float y, float Health){
	DWORD HPcol = GREEN;
	if (Health < 90)HPcol = YELLOW;
	if (Health < 80) HPcol = ORANGE;
	if (Health < 40) HPcol = RED;
	if (Health < 10) HPcol = BLACK;
	DrawBorder(x-1,y-1,52,5,1,BLACK,pDevice );
	FillRGB(x,y,Health/2,3,HPcol,pDevice );
}

/*---------------------------------------- Declaration DrawLine ----------------------------------------------------*/
void  DrawLine ( long Xa, long Ya, long Xb, long Yb, DWORD dwWidth, D3DCOLOR Color ){
	D3DXVECTOR2 vLine[ 2 ];
	Tools.pLine->SetAntialias( 0 );
	Tools.pLine->SetWidth( (float)dwWidth );
	Tools.pLine->Begin();
	vLine[ 0 ][ 0 ] = (float)Xa;
	vLine[ 0 ][ 1 ] = (float)Ya;
	vLine[ 1 ][ 0 ] = (float)Xb;
	vLine[ 1 ][ 1 ] = (float)Yb;
	Tools.pLine->Draw( vLine, 2, Color );
	Tools.pLine->End();
}

/*---------------------------------------- Declaration FillRGB ----------------------------------------------------*/
void obFillRGB( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice ){
	if( w < 0 )w = 1;
	if( h < 0 )h = 1;
	if( x < 0 )x = 1;
	if( y < 0 )y = 1;
	D3DRECT rec = { x, y, x + w, y + h };
	pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}

/*---------------------------------------- Declaration DrawBorder ----------------------------------------------------*/
void obDrawBorder( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice ){
	obFillRGB( x, (y + h - px), w, px, BorderColor, pDevice );
	obFillRGB( x, y, px, h, BorderColor, pDevice );
	obFillRGB( x, y, w, px, BorderColor, pDevice );
	obFillRGB( (x + w - px), y, px, h, BorderColor, pDevice );
}

/*---------------------------------------- Declaration DrawBox ----------------------------------------------------*/
void DrawBoxob( int x, int y, int w, int h, D3DCOLOR BoxColor, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice ){
	obFillRGB( x, y, w, h, BoxColor, pDevice );
	obDrawBorder( x, y, w, h, 1, BorderColor, pDevice );
}

/*---------------------------------------- Declaration DrawBoxServer ----------------------------------------------------*/
void DrawBoxServer( int x, int y, IDirect3DDevice9* pDevice ){
	if( !pDevice )
		return;
   DrawBoxob( x, y, 147, 18,BLACK, BLUE, pDevice );
}

/*---------------------------------------- Declaration PingServer ----------------------------------------------------*/
void PingServer(int x, int y, float Health, IDirect3DDevice9* pDevice){
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

/*---------------------------------------- Declaration HealthbarServer ----------------------------------------------------*/
void HealthbarServer(IDirect3DDevice9* pDevice, int x, int y, float Health){
	if( !pDevice )
		return;
	float Long = (Health);
	obFillRGB(x,y,Health,14,RED,pDevice );
}

/*---------------------------------------- Declaration DrawString ----------------------------------------------------*/
void DrawString(int x, int y, DWORD color, const char *fmt, ...){
	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;
	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	fName->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}

/*---------------------------------------- Declaration DrawString ----------------------------------------------------*/
void DrawString21(int x, int y, DWORD color, const char *fmt, ...){
	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;
	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	fName->DrawText(NULL, buf, -1, &FontPos,  DT_LEFT | DT_WORDBREAK, color);
}

/*---------------------------------------- Declaration PrintText ----------------------------------------------------*/
void PrintText(LPD3DXFONT Font, long x, long y, D3DCOLOR fontColor, char *text, ...){
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
	fName->DrawText(0, logbuf, -1, &rct, DT_NOCLIP, fontColor);
}

/*---------------------------------------- Declaration Wp Smoke Kill ----------------------------------------------------*/
void DrawStringH(float x, float y , DWORD color, const char *fmt, ...){ 
	RECT FontPos = { x, y, x + 20, y + 10 };
	char buf[1024] = {'\0'};
	va_list va_alist;
	va_start(va_alist, fmt);
	vsprintf(buf, fmt, va_alist);
	va_end(va_alist);
	fName->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
} 

/*---------------------------------------- Declaration FindDistance ----------------------------------------------------*/
float FindDistance(D3DXVECTOR3 my,D3DXVECTOR3 other,CPlayers* pPlayer,CPlayers* pLocal){
	return sqrt((pLocal->pos.x-pPlayer->pos.x)*(pLocal->pos.x-pPlayer->pos.x) + (pLocal->pos.y-pPlayer->pos.y)*(pLocal->pos.y-pPlayer->pos.y) + (pLocal->pos.z-pPlayer->pos.z)*(pLocal->pos.z-pPlayer->pos.z));
} 

/*---------------------------------------- Declaration FillRGB ----------------------------------------------------*/
void FillRGBBOX( float x, float y, float w, float h, D3DCOLOR color){
	if( w < 0 )w = 1;
	if( h < 0 )h = 1;
	if( x < 0 )x = 1;
	if( y < 0 )y = 1;
	D3DRECT rec = { x, y, x + w, y + h };
	npDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}

/*---------------------------------------- Declaration DrawBorder ----------------------------------------------------*/
void DrawBorder( float x, float y, float w, float h, int px, float Health){
	FillRGBBOX( x, (y + h - px), w, px, TeamColor);
	FillRGBBOX( x, y, px, h, TeamColor);
	FillRGBBOX( x, y, w, px, TeamColor);
	FillRGBBOX( (x + w - px), y, px, h, TeamColor); 
}

/*---------------------------------------- Declaration BoxEsp ----------------------------------------------------*/
void DrawBoxESP( int x, int y, int w, int h, float Health, IDirect3DDevice9* pDevice )
{
	DWORD HPcol = YELLOW;
	if (Health < 90)HPcol = GREEN;
	if (Health < 80) HPcol = GREEN;
	if (Health < 40) HPcol = GREEN;
	if (Health < 10) HPcol = GREEN;
	DrawBorder( x, y, w, h, 1, HPcol, pDevice );
}

/*---------------------------------------- Declaration DrawBorder ----------------------------------------------------*/
void DrawBorderz( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice ){
	FillRGB( x, (y + h - px), w, px, BorderColor, pDevice );
	FillRGB( x, y, px, h, BorderColor, pDevice );
	FillRGB( x, y, w, px, BorderColor, pDevice );
	FillRGB( (x + w - px), y, px, h, BorderColor, pDevice );
}

/*---------------------------------------- Declaration HealthEqui ----------------------------------------------------*/
void HealthEqui(LPDIRECT3DDEVICE9 pDevice, int x, int y, float Health){
	const D3DCOLOR colours[] = { RED, RED, RED, RED, ORANGE, ORANGE, ORANGE, ORANGE, YELLOW, YELLOW, YELLOW, YELLOW, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLUE, BLUE }; // this is our order
	int boxSizeX = 2;	// you can fiddle with the box size and gap between them
	int boxSizeY = 7;
	int boxGap = 1;
	for ( int i = 0 ; i < 20; i++ ){
		if ( Health > ( 5 * i ) )
			DrawBorderz(x-1,y-1,62,9,1,colours[i],pDevice );	
	}
	for ( int i = 0 ; i < 20; i++ ){
		if ( Health > ( 5 * i ) )
			FillRGB(x,y, boxSizeX, boxSizeY,colours[i],pDevice);
		else
			FillRGB(x,y, boxSizeX, boxSizeY,GREY,pDevice);
		x = x + boxSizeX+ boxGap;	// will move to next tile 1 unit to the right
	}
}

/*---------------------------------------- Declaration HealthEqui ----------------------------------------------------*/
void HealthEqui2(LPDIRECT3DDEVICE9 pDevice, int x, int y, float Health){
	const int SizeY[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	const D3DCOLOR colours[] = { RED, RED, RED, RED, ORANGE, ORANGE, ORANGE, ORANGE, YELLOW, YELLOW, YELLOW, YELLOW, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLUE, BLUE }; // this is our order
	int boxSizeX = 2;	// you can fiddle with the box size and gap between them
	int boxSizeY = 6;
	int boxGap = 1;
	for ( int i = 0 ; i < 20; i++ ){
		if ( Health > ( 5 * i ) )
			FillRGB(x,y, boxSizeX, SizeY[i],colours[i],pDevice);
		else
			FillRGB(x,y, boxSizeX, SizeY[i],D3DCOLOR_ARGB(255,128,128,128),pDevice);
		x = x + boxSizeX+ boxGap;	// will move to next tile 1 unit to the right
	}
}

/*---------------------------------------- Declaration All Esp ----------------------------------------------------*/
void EspMode (LPDIRECT3DDEVICE9 pDevice){
	int ServerX1=100;
	int ServerY1=480;
	int ServerX2=900;
	int ServerY2=480;
	int ServerRED=500;
	int ServerBLUE=250;
	D3DXVECTOR3 ScreenPos;
	unsigned long dwBase	= *(DWORD*)ResultBasePlayer2;
	unsigned long dwBase2	= *(DWORD*)ResultBaseHealth2;	
	CTeam		*pTeam		= ((CTeam*)(dwBase + ResultTeam));
	TeamScore	*TeamzScore	= (TeamScore*)((dwBase + ResultScore));
	char *dis		= new char[33];
	float ScreenCenterX = (Viewport.Width /2.0f);
	float ScreenCenterY = (Viewport.Height /2.0f);
	float ScreenBottomY = (Viewport.Height);
	for (int i = 0; i<=16; i++){
		if (dwBase !=0){
			if (dwBase2 !=0){
				CLog		*pPing		= (CLog*)	((dwBase + ResultPing) + i * 0x1);
				CKill		*pKill		= (CKill*)	((dwBase + ResultKill) + i * 0x4);
				CNames		*pNames		= (CNames*)	((dwBase + ResultName) + i * 0x21);
				CRank		*pRank		= (CRank*)	((dwBase + ResultSkill2) + i * 0x2B);
				CHealth		*pHealth	= (CHealth*)((dwBase2 + ResultHealth) + i * 0x24);
				int iTeam    = GetTeam(i);
				DWORD pCalculate = *(DWORD*)(dwBase + 0x4 * i + ResultPlayer );//
				DWORD pCalculate2 = *(DWORD*)(dwBase + 0x4 * pTeam->iTeam + ResultPlayer );
				CPlayers	*pPlayer	= (CPlayers*)(pCalculate + 0x64 );
				CPlayers	*pLocal	= (CPlayers*)(pCalculate2 + 0x64 );
				Player.x	=  pPlayer->pos.x;
				Player.y	=  pPlayer->pos.y;
				Player.z	=  pPlayer->pos.z;
				HeadPos.x	=	pPlayer->pos.x;
				HeadPos.y	=	1.6f + pPlayer->pos.y;
				HeadPos.z	=	pPlayer->pos.z;
				D3DXVECTOR3 MyDistance	=	pLocal->pos - pPlayer->pos;
				float MyaDistance = D3DXVec3Length(&MyDistance );
				float PosX = 0.0f;
				float PosY = 0.0f;
				int MySlot = GetTeam(GetMyCharaIndex()); 
				int myTeam = GetTeamLol(i);
				if(GetTeam(i) == MySlot) continue; 
				if (iTeam == 1){ TeamColor = RED; } // warna ESP Box
				else if (iTeam == 2){ TeamColor = BLUE; }    // warna ESP Box
				else{ continue;} 
				if( GetUserBone(vStart10,15,i)){
					if( GetUserBone(vEnd10,9,i)){
						if( YoWorlToScreenGa(pDevice,vStart10,vvStart10)){
							if( YoWorlToScreenGa(pDevice,vEnd10,vvEnd10)){
								if(YoWorlToScreenGa(pDevice,pPlayer->pos,ScreenPos)){
									if (pHealth->CurHP > 1){
										/*---------------------------- Declaration Esp Health ----------------------------------------*/
										if (opt.ccoba.ESPHealth == 1){
											Healthbarnew(pDevice,(int)vvStart10.x-25,(int)vvEnd10.y+10,pHealth->CurHP);
										}
										if (opt.ccoba.ESPHealth == 2){
											HealthEqui(pDevice,(int)vvStart10.x-25,(int)vvEnd10.y+10,pHealth->CurHP);
										}
										if (opt.ccoba.ESPHealth == 3){
											HealthEqui2(pDevice,(int)vvStart10.x-25,(int)vvEnd10.y+10,pHealth->CurHP);
										}
										/*---------------------------- Declaration Esp Line ----------------------------------------*/
										if (opt.ccoba.ESPLine==1){
											DrawLine((float)ScreenCenterX,(float)ScreenBottomY,(float)vvStart10.x,(float)vvEnd10.y,1,YELLOW);
										}
										/*---------------------------- Declaration Esp Distance ----------------------------------------*/
										if (opt.ccoba.ESPDistance==1){
											DrawStringH(ScreenPos.x-30,ScreenPos.y-25,YELLOW,"[Distance : %0.1f M]",FindDistance(pLocal->pos,pPlayer->pos,pPlayer,pLocal));
										}
										/*---------------------------- Declaration Esp Kill Health Death ----------------------------------------*/
										if (opt.ccoba.ESPKD==1){
											DrawString(ScreenPos.x-30,ScreenPos.y-35,YELLOW," KILL[ %d]DEATH[%d ]HEALTH[%0.f]",pKill->bKill,pKill->bDead,pHealth->CurHP);
										}
										/*---------------------------- Declaration Esp Box ----------------------------------------*/
										if(opt.ccoba.ESPBox == 1)
										{
											DrawBoxESP((float)vvStart10.x-(5000/MyaDistance)/30,(float)vvEnd10.y-(35000/MyaDistance)/45, 50000/MyaDistance/6*2/40,50000/MyaDistance/3*2/40, TeamColor, pDevice);
										}
									}
								}
							}
						}
					}
				}
				/*---------------------------- Declaration Esp Observer ----------------------------------------*/
				/*if(ESPObserver==1)
				{
					if(myTeam == 1)
					{
						TeamColor = RED;
						DrawBoxServer(ScreenCenterX - ServerRED + 40,(int)ServerY1+(10*i),pDevice);
						HealthbarServer(pDevice,ScreenCenterX - ServerRED + 65,(int)(ServerY1+2)+(10*i),pHealth->CurHP);
						PingServer(ScreenCenterX - ServerRED + 187,(int)(ServerY1+2)+(10*i),pPing->iLog, pDevice);
						DrawString(ScreenCenterX - ServerRED + 45,(ServerY1+2)+(10*i),WHITE,"%d|%d %s",pKill->bKill,pKill->bDead,pNames->szNames);
						DrawString21(ScreenCenterX - ServerRED + 40,460,RED,"[Red Team : %d]",TeamzScore->TScoreRed);
					}
					if(myTeam == 2)
					{
						TeamColor = BLUE;
						DrawBoxServer(ScreenCenterX + ServerBLUE + 40,(ServerY1-10)+(10*i),pDevice);
						HealthbarServer(pDevice, ScreenCenterX + ServerBLUE + 65 ,(int)((ServerY1+2)-10)+(10*i),pHealth->CurHP);
						PingServer(ScreenCenterX + ServerBLUE + 187,(int)((ServerY1+2)-10)+(10*i),pPing->iLog, pDevice);
						DrawString(ScreenCenterX + ServerBLUE + 45,((ServerY1+2)-10)+(10*i),WHITE,"%d|%d %s",pKill->bKill,pKill->bDead,pNames->szNames);
						DrawString21(ScreenCenterX + ServerBLUE + 40,460,BLUE,"[Blue Team : %d]",TeamzScore->TScoreBlue);
					}
				}*/
				if (pHealth->CurHP > 1){
					/*---------------------------- Declaration Esp Name ----------------------------------------*/
					if (opt.ccoba.ESPName){
						PrintText(fName,(float)vvStart10.x-15,(float)vvStart10.y - 41.0,RED," %s ",pNames->szNames);
					}
					/*---------------------------- Declaration Esp Rank ----------------------------------------*/
					if (opt.ccoba.ESPRank){
						PrintText(fName,(float)vvStart10.x-15,(float)vvStart10.y - 51.0,BLUE," %s ",eRanks[pRank->iRank]);
					}
					/*---------------------------- Declaration Esp Bone ----------------------------------------*/
					if(opt.ccoba.ESPBone == 1){
if( GetUserBone(vStart,6,i)){
if( GetUserBone(vEnd,7,i)){
if( YoWorlToScreenGa(pDevice,vStart,vvStart)){
if( YoWorlToScreenGa(pDevice,vEnd,vvEnd)){
if( GetUserBone(vStart2,6,i)){
if( GetUserBone(vEnd2,0,i)){
if( YoWorlToScreenGa(pDevice,vStart2,vvStart2)){
if( YoWorlToScreenGa(pDevice,vEnd2,vvEnd2)){
if( GetUserBone(vStart3,6,i)){
if( GetUserBone(vEnd3,10,i)){
if( YoWorlToScreenGa(pDevice,vStart3,vvStart3)){
if( YoWorlToScreenGa(pDevice,vEnd3,vvEnd3)){
if( GetUserBone(vStart4,6,i)){
if( GetUserBone(vEnd4,11,i)){
if( YoWorlToScreenGa(pDevice,vStart4,vvStart4)){
if( YoWorlToScreenGa(pDevice,vEnd4,vvEnd4)){
if( GetUserBone(vStart5,0,i)){
if( GetUserBone(vEnd5,12,i)){
if( YoWorlToScreenGa(pDevice,vStart5,vvStart5)){
if( YoWorlToScreenGa(pDevice,vEnd5,vvEnd5)){
if( GetUserBone(vStart6,0,i)){
if( GetUserBone(vEnd6,13,i)){
if( YoWorlToScreenGa(pDevice,vStart6,vvStart6)){
if( YoWorlToScreenGa(pDevice,vEnd6,vvEnd6)){
if( GetUserBone(vStart7,12,i)){
if( GetUserBone(vEnd7,14,i)){
if( YoWorlToScreenGa(pDevice,vStart7,vvStart7)){
if( YoWorlToScreenGa(pDevice,vEnd7,vvEnd7)){
if( GetUserBone(vStart8,13,i)){
if( GetUserBone(vEnd8,15,i)){
if( YoWorlToScreenGa(pDevice,vStart8,vvStart8)){
if( YoWorlToScreenGa(pDevice,vEnd8,vvEnd8)){
if( GetUserBone(vStart9,14,i)){
if( GetUserBone(vEnd9,8,i)){
if( YoWorlToScreenGa(pDevice,vStart9,vvStart9)){
if( YoWorlToScreenGa(pDevice,vEnd9,vvEnd9)){
if( GetUserBone(vStart10,15,i)){
if( GetUserBone(vEnd10,9,i)){
if( YoWorlToScreenGa(pDevice,vStart10,vvStart10)){
if( YoWorlToScreenGa(pDevice,vEnd10,vvEnd10)){
DrawLine(vvStart.x,vvStart.y,vvEnd.x,vvEnd.y,1,WHITE);//leher-kepala
DrawLine(vvStart2.x,vvStart2.y,vvEnd2.x,vvEnd2.y,1,WHITE);//badan ampe kontol
DrawLine(vvStart3.x,vvStart3.y,vvEnd3.x,vvEnd3.y,1,WHITE);//tangan kiri
DrawLine(vvStart4.x,vvStart4.y,vvEnd4.x,vvEnd4.y,1,WHITE);//tangan kanan
DrawLine(vvStart5.x,vvStart5.y,vvEnd5.x,vvEnd5.y,1,WHITE);//pinggul kiri
DrawLine(vvStart6.x,vvStart6.y,vvEnd6.x,vvEnd6.y,1,WHITE);//pinggul kanan
DrawLine(vvStart7.x,vvStart7.y,vvEnd7.x,vvEnd7.y,1,WHITE);//paha kiri
DrawLine(vvStart8.x,vvStart8.y,vvEnd8.x,vvEnd8.y,1,WHITE);//paha kanan
DrawLine(vvStart9.x,vvStart9.y,vvEnd9.x,vvEnd9.y,1,WHITE);//kaki kiri
DrawLine(vvStart10.x,vvStart10.y,vvEnd10.x,vvEnd10.y,1,WHITE);//kaki kanan
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}	
}
	bHookedTele = false;
}