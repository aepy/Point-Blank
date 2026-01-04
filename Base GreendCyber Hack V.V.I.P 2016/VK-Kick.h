#include <windows.h>
DWORD CGameContextPointer(void) {	
	
	unsigned long dwBase = *(DWORD*)ResultBasePlayer2;
		return dwBase;
}
CNames *oNames(UINT i)
{
return (CNames*)((CGameContextPointer() + ResultName) + i * 0x21);
}
void DrawBox13( int x, int y, int w, int h, D3DCOLOR BoxColor, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
FillRGB( x, y, w, h, BoxColor, pDevice );
DrawBorder( x, y, w, h, 1, BorderColor, pDevice );
}
void SString(int x, int y, DWORD Color, DWORD Style, const char *Format, ...)
	{
		RECT rect;
		SetRect(&rect, x, y, x, y);
		char Buffer[1024] = { '\0' };
		va_list va_alist;
		va_start(va_alist, Format);
		vsprintf_s(Buffer, Format, va_alist);
		va_end(va_alist);
		pFont->DrawTextA(NULL, Buffer, -1, &rect, Style, Color);

		return;
	}
void DrawString4(int x, int y, DWORD color, DWORD Style,const char *fmt, ...)
{
	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	
	fSmall->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}

	int	GetTextLen(LPCTSTR szString)
{
    RECT rect = {0,0,0,0};
    fSmall->DrawText(NULL, szString, -1, &rect, DT_CALCRECT, 0);
    return rect.right;
}
BOOL  IsInBox(int x,int y,int w,int h)
{
	POINT MousePosition; 
	GetCursorPos(&MousePosition); 
	ScreenToClient(GetForegroundWindow(),&MousePosition);
	return(MousePosition.x >= x && MousePosition.x <= x + w && MousePosition.y >= y && MousePosition.y <= y + h);
}


void PrintTextm(LPD3DXFONT g_pFont, long x, long y, D3DCOLOR fontColor, char *text, ...)
{
    RECT rct;
    rct.left     = x - 1;
    rct.right    = x + 1;
    rct.top      = y - 1 ;
    rct.bottom   = y + 1;

    if(!text) { return; }
    va_list va_alist;
    char logbuf[256] = {0};
    va_start (va_alist, text);
    _vsnprintf(logbuf+strlen(logbuf), sizeof(logbuf) - strlen(logbuf), text, va_alist);
    va_end (va_alist);
    RECT FontRect = { x, y, x, y };
    g_pFont->DrawTextA(NULL, logbuf, -1, &rct, DT_NOCLIP, fontColor);
	}
void FillRGBM( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice )
{
    if( w < 0 )w = 1;
    if( h < 0 )h = 1;
    if( x < 0 )x = 1;
    if( y < 0 )y = 1;

    D3DRECT rec = { x, y, x + w, y + h };
    pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}

	 
VOID DrawMouse(DWORD color,LPDIRECT3DDEVICE9 pDevice,POINT Cur)
{
if(VoteKick==1)
{
POINT myCursor;
GetCursorPos(&myCursor);
//PrintTextm(pFonts,myCursor.x,myCursor.y,D3DCOLOR_ARGB(255, 255, 255, 000),"\n ResCyberHack : %d - Irman R : %d\n~| RChcode |~",myCursor.x,myCursor.y);
FillRGBM(myCursor.x + 0, myCursor.y + 0,1, 11, color,  pDevice);
FillRGBM(myCursor.x + 1, myCursor.y + 1, 1, 9, color,  pDevice);
FillRGBM(myCursor.x + 2, myCursor.y + 2, 1, 7, color,  pDevice);
FillRGBM(myCursor.x + 3, myCursor.y + 3, 1, 7, color,  pDevice);
FillRGBM(myCursor.x + 4, myCursor.y + 4, 1, 8, color,  pDevice);
FillRGBM(myCursor.x + 5, myCursor.y + 5, 1, 3, color,  pDevice);
FillRGBM(myCursor.x + 6, myCursor.y + 6, 1, 2, color,  pDevice);
FillRGBM(myCursor.x + 7, myCursor.y + 6, 1, 1, color,  pDevice);
FillRGBM(myCursor.x + 5, myCursor.y + 10, 1, 4, color, pDevice);
FillRGBM(myCursor.x + 6, myCursor.y + 12, 1, 2, color, pDevice);
}
}
DWORD PTR_Caller,BaseECX,CallBasePB,StringMessage,Definition,ReDefinition,ReadProcASM, StartRouneAmmo= NULL;
void FloodKickPlayer(int IndexPlayer) 
{ 
Sleep(20); 
if(Keprox == false) 
{ 
PTR_Caller = (DWORD)( ResultSetEvent ); 
BaseECX = *(DWORD*)( ResultBasePlayer2); 
BYTE pKick[15]; 
*(BYTE*)(pKick) = IndexPlayer; 
Definition = (DWORD)pKick; 
ReDefinition = (DWORD)pKick + 0x4; 
Sleep(5); 
__asm 
{ 
push 0x00 
push 0x00 
push 0x00 
push [ReDefinition] 
push [Definition] 
push 0xA0 
mov ecx,[BaseECX] 
call [PTR_Caller] 
} 
Sleep(20); 
Keprox = true; 
}
} 
void ThreadFloodVK() //pemanggil void nih 
{ 
if(VoteKick==1){
Sleep(20); 
Keprox = false; 
if(*(PBYTE)ResultBaseAmmo2 > NULL) 
{ 
Sleep(5); 
for (int i = 0; i<=15; i++) 
{ 
int MySlot = GetMyCharaIndex(); 
if( i == MySlot)continue; 
FloodKickPlayer(i); 
}
Sleep(20); 
} 
}}                   
void Box(int x, int y, int w, int h, D3DCOLOR Color, LPDIRECT3DDEVICE9 pD3D9)
{
	struct Vertex
	{
		float x, y, z, ht;
		DWORD Color;
	}
	V[4] = { {x, y + h, 0.0f, 0.0f, Color}, { x, y, 0.0f, 0.0f, Color }, { x + w, y + h, 0.0f, 0.0f, Color }, { x + w, y, 0.0f, 0.0f, Color } };

	pD3D9->SetTexture(0, NULL);
	pD3D9->SetPixelShader(0);
	pD3D9->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	pD3D9->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	pD3D9->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pD3D9->SetRenderState(D3DRS_ZENABLE, FALSE);
	pD3D9->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	pD3D9->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, V, sizeof(Vertex));
	return;
}
	
void DrawChekBoxServer( int x, int y, int &Var, IDirect3DDevice9* pDevice )
{
	if( !pDevice )
		return;
	int w=15,h=15;
D3DCOLOR EColOn=DARKWHITE;
D3DCOLOR Col=DARKWHITE,Col2=DARKWHITE2,Col3=BLACK2,Col4=DARKWHITE2,Col5=RainbowTextTest;
	DrawBox13( x, y, 147, 18,BLACK, TeamColor, pDevice );
	if (IsInBox(x, y, 147, 18))
	{
Col=newColor;
			Col2 = DARKWHITE2;
			Col5 = DARKWHITE2;
		if (Var == 0)
		{
		}
		if (lm)
		{
			Var = !Var; 
		}
	}
	if (Var == 1)
	{ 
Col=newColor;
			Col4=GREEN;
	}

			Box(x + 1, y + 1,145,18,Col5,pDevice);
	
}


void KickPlayer(LPDIRECT3DDEVICE9 pDevice)
{
	
	//pDevice->GetViewport(&viewP);
	lm	 =    GetAsyncKeyState(VK_LBUTTON)&1;	
    rm   =    GetAsyncKeyState(VK_RBUTTON)&1;
	flm	 =    GetAsyncKeyState(VK_LBUTTON);	
    frm  =    GetAsyncKeyState(VK_RBUTTON);	
if(GetBattleState()){
if(VoteKick==1)
{

int ServerRED =170;
int ServerBLUE =-20;
int ServerY1 =500;
D3DVIEWPORT9 viewP;
pDevice->GetViewport( &viewP );
DWORD ScreenCenterX = viewP.Width / 2;
DWORD ScreenCenterY = viewP.Height / 2;
unsigned long dwBase = *(DWORD*)ResultBasePlayer;
			for (int i = 0; i <= 15; i++)
			{
			bHookedTele = true;
int myTeam = GetTeam(i);
			int iTeam	= GetTeam(i);
			if(*(PBYTE)ResultBaseAmmo2 > 1){
if (iTeam == 1)
			{
DrawChekBoxServer(ScreenCenterX - ServerRED + 40,(int)ServerY1+(10*i),iTeam,pDevice);
DrawString(ScreenCenterX - ServerRED + 45,(ServerY1+2)+(10*i),WHITE," | %s",oNames(i)->szNames);
DrawString21(ScreenCenterX - ServerRED + 40,480,RED,"VOTEKICK PLAYER",pDevice);				
}
if (iTeam == 2){					
DrawChekBoxServer(ScreenCenterX + ServerBLUE + 40,(ServerY1-10)+(10*i),iTeam,pDevice);
DrawString(ScreenCenterX + ServerBLUE + 45,((ServerY1+2)-10)+(10*i),WHITE," | %s",oNames(i)->szNames);
}
}
}
}
bHookedTele = false;
}
if(GetAsyncKeyState(VK_LBUTTON)&&0x8000)
{
ThreadFloodVK();
VoteKick=0;
}
}
