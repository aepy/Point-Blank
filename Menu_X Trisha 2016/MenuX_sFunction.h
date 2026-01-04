LPD3DXFONT fSmall	= NULL;
void DrawString(int x, int y, DWORD color, const char *fmt, ...)
{
	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	
	fSmall->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}
void DrawBorder(int x, int y, int w, int h, int px, D3DCOLOR BorderColor, LPDIRECT3DDEVICE9 pDevice)
{
	FillRGB(x,(y + h - px), w, px, BorderColor, pDevice);
	FillRGB(x, y, px, h, BorderColor, pDevice);
	FillRGB(x, y, w, px, BorderColor, pDevice);
	FillRGB(x + w - px, y, px, h, BorderColor, pDevice);
}

void DrawBox(int x, int y, int w, int h, D3DCOLOR Color, D3DCOLOR BorderColor, LPDIRECT3DDEVICE9 pDevice) 
{

	DrawBorder(x, y, w, h, 2, BorderColor, pDevice);
	
	const DWORD D3D_FVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE;
	struct Vertex {
		float x, y, w, h;
		D3DCOLOR Color;
	}
	V[4] = {{(float) x, (float)(y + h), 0.0f, 0.0f, Color}, 
			{(float) x, (float)y, 0.0f, 0.0f, Color}, 
			{(float)(x + w), (float)(y + h), 0.0f, 0.0f, Color}, 
			{(float)(x + w), (float)y, 0.0f, 0.0f, Color}
	};
	pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, D3DZB_TRUE);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
	pDevice->SetRenderState(D3DRS_FOGENABLE, D3DZB_FALSE);

	pDevice->SetFVF(D3D_FVF);
	pDevice->SetTexture(0, NULL);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, V, sizeof(Vertex));
}
void HealthEqui(LPDIRECT3DDEVICE9 pDevice,int x, int y, float Health)
{
const int SizeY[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
const D3DCOLOR colours[] = { RED, RED, RED, RED, ORANGE, ORANGE, ORANGE, ORANGE, YELLOW, YELLOW, YELLOW, YELLOW, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, BLUE, BLUE }; // this is our order
int boxSizeX = 2; // you can fiddle with the box size and gap between them
int boxSizeY = 6;
int boxGap = 1;
for ( int i = 0 ; i < 20; i++ )
{
if ( Health > ( 5 * i ) )
FillRGB(x,y, boxSizeX, SizeY[i],colours[i],pDevice);
else
FillRGB(x,y, boxSizeX, SizeY[i],GREY,pDevice);
//DrawBorder(x-1,y-1,50,6,1,BLACK,npDevice);
x = x + boxSizeX+ boxGap; // will move to next tile 1 unit to the right
}
}
void Healthbarnew(LPDIRECT3DDEVICE9 pDevice,float x, float y, float Health)
{
DWORD HPcol = GREEN;
if (Health < 90 )HPcol = BLUE;
if (Health < 70 )HPcol = DEEPSKYBLUE;
if (Health < 50 )HPcol = ORANGE;
if (Health < 40 )HPcol = YELLOW;
if (Health < 30) HPcol = RED;
if (Health < 10) HPcol = RED;
DrawBorder(x-1,y-1,52,5,1,BLACK,pDevice);
FillRGB(x,y,Health/2,3,HPcol,pDevice );
}
void PrintText(LPD3DXFONT g_pFont, INT x, INT y, DWORD Flags, DWORD Color, CHAR *text, ...)
{
	RECT rec;
	SetRect(&rec, x, y, x, y);
	CHAR logbuf[512] = {0};

	va_list va_alist;
	va_start(va_alist, text);
	vsnprintf(logbuf + strlen(logbuf), sizeof(logbuf) - strlen(logbuf), text, va_alist);
	
	va_end(va_alist);
	g_pFont->DrawTextA(NULL, logbuf, -1, &rec, Flags, Color);
}

void Item(CHAR *text, CHAR **opt, INT &val, INT maxvalue, LPDIRECT3DDEVICE9 pDevice)
{
	DWORD Color1, Color2;
	INT bVar = (val)?(val):0;
	extern INT Current;
	if(Menu && NHT3XT)
	{
	FillGradients (30 + 1,menuy + 22 + (qntHacks * 20),19,169,Grey,Black,pDevice);
		if(MenuSelection == qntHacks)
		{
			if(IsKeyPressed(VK_RIGHT,0))
				if(val < maxvalue - 1)
					val++;
			if(IsKeyPressed(VK_LEFT,0))
				if(val > 0)
					val--;
		}else{}
		if(val > 0)
		{
			FillGradients (30 + 3,menuy + 23 + (qntHacks * 20),10,10,Green,Green,pDevice);//indikator tombol fiturjika on
		}
		if(val == 0)
		{

			FillGradients (30 + 3,menuy + 23 + (qntHacks * 20),10,10,Red,Red,pDevice);//indikator tombol fiturjika off
		}

		Color1 = White;
		Color2 = (bVar)?Green:Red;
		PrintText(NHT3XT, 30 + 20, menuy + 20 + (qntHacks * 20), TLeft, Color1, text);
		PrintText(NHT3XT, 30 - 15  + mxofs, menuy + 25 + (qntHacks * 20), TRight, Color2, opt[bVar]);
		

		qntHacks++;
	}
	Current++;
}

void Folder(CHAR *text, CHAR **opt, INT &val, INT maxvalue, LPDIRECT3DDEVICE9 pDevice)
{
	DWORD Color1, Color2;
	int bVar = (val)?(val):0;
	extern int Current;
	if(Menu && NHT3XT)
	{
		if(MenuSelection == qntHacks)
		{
			if(IsKeyPressed(VK_RIGHT,0))
				if(val < maxvalue - 1)
					val++;
			if(IsKeyPressed(VK_LEFT,0))
				if(val > 0)
					val--;
		}else{}
		if(val > 0)
		{
			FillGradients (20 + 3,menuy + 23 + (qntHacks * 20),10,10,Orange,Orange,pDevice);//indikator tombol fiturjika on
		}
		if(val == 0)
		{
			FillGradients (20 + 3,menuy + 23 + (qntHacks * 20),10,10,White,White,pDevice);//indikator tombol fiturjika off
		}

		Color1 = Yellow;
		Color2 = (bVar)?Yellow:Yellow;

		PrintText(NHT3XT, 20 + 20, menuy + 20 + (qntHacks * 20), TLeft, Color1, text);
		PrintText(NHT3XT, 30 - 15 + mxofs, menuy + 20 + (qntHacks * 20), TRight, Color2, opt[bVar]);

		qntHacks++;
	}
	Current++;
}










