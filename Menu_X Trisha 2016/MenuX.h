#include "MenuX_Tools.h"
#define WHITE			D3DCOLOR_ARGB(255, 255, 255, 255)
#define RED				D3DCOLOR_ARGB(255, 255, 000, 000)
#define GREEN			D3DCOLOR_ARGB(255, 000, 255, 000)
#define BLUE			D3DCOLOR_ARGB(255, 000, 000, 255) 
#define BLACK			D3DCOLOR_ARGB(150, 000, 000, 000)
#define mBLACK			D3DCOLOR_ARGB(100, 000, 000, 205)
#define PURPLE			D3DCOLOR_ARGB(255, 125, 000, 255) 
#define GREY			D3DCOLOR_ARGB(255, 128, 128, 128) 
#define YELLOW			D3DCOLOR_ARGB(255, 255, 255, 000) 
#define ORANGE			D3DCOLOR_ARGB(255, 255, 125, 000)
#define WHITE2			D3DCOLOR_ARGB(100, 255, 255, 255)
#define RED2			D3DCOLOR_ARGB(100, 255, 000, 000)
#define GREEN2			D3DCOLOR_ARGB(100, 000, 255, 000)
#define BLUE2			D3DCOLOR_ARGB(100, 000, 000, 255) 
#define BLACK2			D3DCOLOR_ARGB(100, 000, 000, 000)
#define PURPLE2			D3DCOLOR_ARGB(100, 125, 000, 255) 
#define GREY2			D3DCOLOR_ARGB(100, 128, 128, 128) 
#define YELLOW2			D3DCOLOR_ARGB(100, 255, 255, 000) 
#define ORANGE2			D3DCOLOR_ARGB(100, 255, 125, 000)
#define TEAL			D3DCOLOR_ARGB(255, 0,	255, 255)
#define PINK			D3DCOLOR_ARGB(255, 255, 240,   0)
#define LIME			D3DCOLOR_ARGB(255, 198, 255,   0)
#define SKYBLUE			D3DCOLOR_ARGB(255, 0,   180, 255)
#define MAROON			D3DCOLOR_ARGB(255, 142, 30,    0)
#define LGRAY			D3DCOLOR_ARGB(255, 174, 174, 174) 
#define DGRAY			D3DCOLOR_ARGB(255, 71,  65,   64) 
#define BROWN2			D3DCOLOR_ARGB(255, 77,  46,   38)
#define SHIT			D3DCOLOR_ARGB(255, 74,  38,   38) 
#define DEEPSKYBLUE     D3DCOLOR_ARGB(190, 30, 144, 255)
#define Green				D3DCOLOR_ARGB(255, 000, 255, 000)
#define White				D3DCOLOR_ARGB(255, 255, 255, 255)
#define Red					D3DCOLOR_ARGB(255, 255, 000, 000)
#define Blue				D3DCOLOR_ARGB(255, 000, 000, 255)
#define Black				D3DCOLOR_ARGB(255, 000, 000, 000)
#define Black_transparant	D3DCOLOR_ARGB(200, 000, 000, 000)
#define Purple				D3DCOLOR_ARGB(255, 125, 000, 125)
#define Yellow				D3DCOLOR_ARGB(255, 255, 255, 000)
#define Orange				D3DCOLOR_ARGB(255, 255, 125, 000)
#define Grey				D3DCOLOR_ARGB(255, 128, 128, 128)
#define Cyan				D3DCOLOR_ARGB(255, 000, 032, 032)
#define Custom				D3DCOLOR_ARGB(225, 000, 120, 120)
#define Maroon				D3DCOLOR_ARGB(255, 128, 0, 0)
#define MCOLOR_FOLDER		D3DCOLOR_ARGB(255, 255, 000, 000)  ///RED
#define MCOLOR_CURRENT		D3DCOLOR_ARGB(255, 255, 255, 000)  ///YELLOW
#define MCOLOR_TEXT			D3DCOLOR_ARGB(255, 255, 255, 255)  ///WHITE
#define MCOLOR_ACTIVE		D3DCOLOR_ARGB(255, 000, 255, 000)  ///GREEN
#define MCOLOR_INACTIVE		D3DCOLOR_ARGB(255, 195, 195, 195)  ///GREY


int Current = true;
int qntHacks = 0;
int menux, menuy, mxofs;
int MenuSelection;
bool Menu = true;
#define TLeft				DT_NOCLIP | DT_LEFT
#define TRight				DT_NOCLIP | DT_RIGHT
#define Tab_background		D3DCOLOR_ARGB(255, 040, 040, 040)
#define Tab_rectangle		Black
#define Tab_off				White
#define Tab_on				Red
#define Item_off			Tab_off
#define Item_on				Tab_on
#define Item_check			White
#define Item_current		Orange
#define Menu_background		Tab_background
#define Menu_Standar		Tab_background
#define Menu_rectangle		Tab_rectangle
#define Menu_special		D3DCOLOR_ARGB(255,  60,  60,  60)
#define ComboBox_back		White
#define ComboBox_rect		Grey
#define ComboBox_text		Red
#define Group				White
#define Title				White //warna text credit & fitur
#define TextWarna2			Blue
#define TitleText			Black   //warna text judul
#define Trans D3DCOLOR_ARGB(000, 000, 000, 000)

class menu
{
public:

	/* Tab releated */
	void AddTab(char * string, int x, int y, int &function, int Wert, LPDIRECT3DDEVICE9 pDevice);
	void AddCheck(CHAR *text, CHAR **opt, INT &val, INT maxvalue, LPDIRECT3DDEVICE9 pDevice);
	void AddText(char * string, LPSTR function, LPDIRECT3DDEVICE9 pDevice);
	void AddScroll(int x, int y, int height, int position, LPDIRECT3DDEVICE9 pDevice);
	void SelectionButton(char ** var, int function, int x, int y, LPDIRECT3DDEVICE9 pDevice);
	void SelectionButtonMinimize(int function, int x, int y, LPDIRECT3DDEVICE9 pDevice);
	
	DWORD * SelectionReturn(int x, int y, int function, int maxvalue);
	DWORD * SelectionMinimizeReturn(int x, int y, int function);
	DWORD * ScrollBar(int x, int y, int height, int position);
	DWORD * ScrollBar_Value(int position);
	DWORD * ReturnFunction(int function, int x, int y);

	/* Menu releated */
	void ShowMenu(void);
	SHORT MouseClick(int key);

	/* Look releated */
	void BoardersMinimize(LPDIRECT3DDEVICE9 pDevice);
	void BoardersDireX(LPDIRECT3DDEVICE9 pDevice);
	void BoardersESP(LPDIRECT3DDEVICE9 pDevice);
	void BoardersAIM(LPDIRECT3DDEVICE9 pDevice);
	void BoardersMemory(LPDIRECT3DDEVICE9 pDevice);
	void BoardersSetting(LPDIRECT3DDEVICE9 pDevice);
	void BoardersSMenuX(LPDIRECT3DDEVICE9 pDevice);
	void DrawString(char * string, int x, int y, int color, int f);
	void Rectangle(int x, int y, int w, int h, D3DCOLOR BorderColor, IDirect3DDevice9 * pDevice);
	void Box(int x, int y, int w, int h, DWORD Color, LPDIRECT3DDEVICE9 pDevice);
	void DrawCrosshair(int x, int y, LPDIRECT3DDEVICE9 pDevice);

	/* Menu defenitions */
	int Visible;
	POINT Cursor;

private:
	int Current;
	int List;
	int render;
}; menu pMenu;


void menu::AddTab(char * string, int x, int y, int &function, int Wert, LPDIRECT3DDEVICE9 pDevice)
{
	int w = 70;
	int h = 20;
	pMenu.Box(x - 36, y - 11, 72, 22, Tab_background, pDevice);
	pMenu.Rectangle(x - 36, y - 11, 72, 22, Tab_rectangle, pDevice);
	FillGradient(x - 35, y - 10, h, w, D3DCOLOR_ARGB(100, 000, 000, 205),D3DCOLOR_ARGB(70,255,0,0),  pDevice);
	if(IsInTabBox(x,y))
	{
		if(IsKeyPressed(VK_LBUTTON,0))
		{
			function = Wert;
		}
	}else 
	if(function == Wert)
	{
		DrawString(mTitle, 230, 12, TitleText, 1);
		DrawString(string, x, y - 8, Yellow, 1); //Active
	}else{
		FillGradient (x - 35, y - 10, h, w, D3DCOLOR_ARGB(70,255,0,0), D3DCOLOR_ARGB(70,0,0,0), pDevice);
		DrawString(string, x, y - 8, Tab_off, 1); //Disabled	
	}
	DrawString(mTitle, 230, 12, TitleText, 1);
	DrawString(string, x, y - 8, White, 1); //Active
}

void menu::SelectionButton(char ** var, int function, int x, int y, LPDIRECT3DDEVICE9 pDevice)
{
	sprintf_s(Text, "%s", var[function]);

	DrawString("<", x + 1, y - 9, Red, 1);
	Rectangle(x - 6, y - 6, 12, 12, Menu_rectangle, pDevice);
	Rectangle(x - 7, y - 7, 14, 14, Menu_special, pDevice);
	DrawString(Text, x + 37, y - 9, White, 1);

	DrawString(">", x + 73, y - 9, Red, 1);
	Rectangle(x + 67, y - 6,  12, 12, Menu_rectangle, pDevice);
	Rectangle(x + 66, y - 7,  14, 14, Menu_special, pDevice);
}

void menu::SelectionButtonMinimize(int function, int x, int y, LPDIRECT3DDEVICE9 pDevice)
{
	Rectangle(x - 6, y - 6, 13, 13, Menu_rectangle, pDevice);
	Rectangle(x - 7, y - 7, 15, 15, Menu_special, pDevice);
}

DWORD * menu::SelectionMinimizeReturn(int x, int y, int function)
{
	GetCursorPos(&Cursor);

	if(Cursor.x < (x + 6) && Cursor.x > (x - 6) && Cursor.y < (y + 7) && Cursor.y > (y - 7))
	{
		if(IsKeyPressed(VK_LBUTTON,0))
		{
			if (function == 1) function = 0;
			else function = 1;
		}
	}
	return (DWORD*)(function);
}

DWORD * menu::SelectionReturn(int x, int y, int function, int maxvalue)
{
	GetCursorPos(&Cursor);

	if(Cursor.x < (x + 6) && Cursor.x > (x - 6) && Cursor.y < (y + 7) && Cursor.y > (y - 7))
	{
		if(IsKeyPressed(VK_LBUTTON,0))
		{
			if(function > 0)
			{
				function--;
			}
		}
	}

	if(Cursor.x < (x + 79) && Cursor.x > (x + 67) && Cursor.y < (y + 7) && Cursor.y > (y - 7))
	{
		if(IsKeyPressed(VK_LBUTTON,0))
		{
			if(function < maxvalue)
			{
				function++;
			}
		}
	}
	return (DWORD*)(function);
}

void menu::AddCheck(CHAR *text, CHAR **opt, INT &val, INT maxvalue, LPDIRECT3DDEVICE9 pDevice)
{
	int w = 218;
	int h = 20;
	extern INT Current;
	if(Menu && NHT3XT)
	{
		FillGradients(menux + 22, menuy + 82 + (qntHacks * 20), h , w, Grey, Black, pDevice );
		if(IsInFiturBox(menux + 40,menuy + 90 + (qntHacks * 20),w,h))
		{
			FillGradient (menux + 22, menuy + 82 + (qntHacks * 20), h , w, D3DCOLOR_ARGB(70,255,0,0), D3DCOLOR_ARGB(70,0,0,0), pDevice);
		}
		if(IsInFiturBox(menux + 40,menuy + 90 + (qntHacks * 20),115,h))
		{
			if(IsKeyPressed(VK_LBUTTON,0))
			{
				if (val == 1) val = 0;
				else val = 1;
			}
		}else{}
		if(val > 0)
		{
			FillGradient (menux + 22, menuy + 82 + (qntHacks * 20), h , w, D3DCOLOR_ARGB(70,255,0,0), D3DCOLOR_ARGB(70,0,0,0), pDevice);
			Rectangle(menux + 33, menuy + 85 + (qntHacks * 20), 14, 14, Menu_special, pDevice);
			Rectangle(menux + 34, menuy + 86 + (qntHacks * 20), 12, 12, White, pDevice);
			FillGradients (menux + 35,menuy + 87 + (qntHacks * 20),10,10,Green,Green,pDevice);//indikator tombol fiturjika on
		}
		if(val == 0)
		{
			Rectangle(menux + 33, menuy + 85 + (qntHacks * 20), 14, 14, Menu_special, pDevice);
			Rectangle(menux + 34, menuy + 86 + (qntHacks * 20), 12, 12, White, pDevice);//bingkai indikator fitur
			FillGradients (menux + 35,menuy + 87 + (qntHacks * 20),10,10,Red,Red,pDevice);//indikator tombol fiturjika off
		}
		DrawString(text,menux + 51, menuy + 84 + (qntHacks * 20), Item_off, 2);
		pMenu.SelectionButton(opt,val,165,menuy + 92 + (qntHacks * 20),pDevice);
		val	= (int)pMenu.SelectionReturn(165,menuy + 92 + (qntHacks * 20),val,maxvalue);
		qntHacks++;
	}
	Current++;
}
void menu::AddText(char * string, LPSTR function, LPDIRECT3DDEVICE9 pDevice)
{
	int w = 218;
	int h = 20;
	extern INT Current;
	if(Menu && NHT3XT)
	{
		FillGradients(menux + 22, menuy + 82 + (qntHacks * 20), h , w, Grey, Black, pDevice );
		if(IsInFiturBox(menux + 40,menuy + 90 + (qntHacks * 20),w,h))
		{
			FillGradient (menux + 22, menuy + 82 + (qntHacks * 20), h , w, D3DCOLOR_ARGB(70,255,0,0), D3DCOLOR_ARGB(70,0,0,0), pDevice);
		}
		Rectangle(menux + 33, menuy + 85 + (qntHacks * 20), 14, 14, Menu_special, pDevice);
		Rectangle(menux + 34, menuy + 86 + (qntHacks * 20), 12, 12, White, pDevice);
		FillGradients (menux + 35,menuy + 87 + (qntHacks * 20),10,10,Green,Green,pDevice);
		DrawString(string,menux + 51, menuy + 84 + (qntHacks * 20), Item_off, 2);
		DrawString(function,menux + 156, menuy + 84 + (qntHacks * 20), Item_off, 2);
		qntHacks++;
	}
	Current++;
}

DWORD * menu::ScrollBar_Value(int position)
{
	position = position / 266;

	return (DWORD*)position;
}

DWORD * menu::ReturnFunction(int function, int x, int y)
{
	GetCursorPos(&pMenu.Cursor);

	if(Cursor.x < x + 10 && Cursor.x > x - 10 && Cursor.y < y + 10 && Cursor.y > y - 10)
	{
		if(MouseClick(VK_LBUTTON))
		{
			switch(function)
			{
				case 0: function = 1; break;
				case 1: function = 0; break;
			}
		}
	}
	return (DWORD*)function;
}

void menu::ShowMenu(void)
{
	if(MouseClick(VK_INSERT))
	{
		switch(Visible)
		{
			case 0: Visible = 1; break;
			case 1: Visible = 0; break;
		}
	}
}

SHORT menu::MouseClick(int key)
{
	if(GetAsyncKeyState(key) &1)
	{
		return true;
	}else{
		return false;
	}
}

#include "MenuX_BorderStyle.h"

void menu::DrawString(char * string, int x, int y, int color, int f)
{
	RECT pText;
	SetRect(&pText, x, y, x, y);

	switch(f)
	{
		case 0:
			NHT3XT->DrawTextA(NULL, string, -1, &pText, DT_NOCLIP | DT_RIGHT, color);
			break;

		case 1:
			NHT3XT->DrawTextA(NULL, string, -1, &pText, DT_NOCLIP | DT_CENTER, color);
			break;

		case 2:
			NHT3XT->DrawTextA(NULL, string, -1, &pText, DT_NOCLIP | DT_LEFT, color);
			break;
	}
}

void menu::Box(int x, int y, int w, int h, DWORD Color, LPDIRECT3DDEVICE9 pDevice)
{
	if( !pDevice )
		return;

	const DWORD D3D_FVF = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	
	struct Vertex 
	{
		float x,y,z,ht;
		DWORD yourcolor;
	}
	V[4] = 
	{
		{(float)x		,(float)(y+h)	, 0.0f, 0.0f, Color},
		{(float)x		,(float)y		, 0.0f, 0.0f, Color},
		{(float)(x+w)	,(float)(y+h)	, 0.0f, 0.0f, Color},
		{(float)(x+w)	,(float)y		, 0.0f, 0.0f, Color}
	};
	
	pDevice->SetTexture( 0, NULL );
	pDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
	pDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW);
	pDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
	pDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
	pDevice->SetRenderState( D3DRS_ZENABLE, D3DZB_FALSE );
	pDevice->SetRenderState( D3DRS_FOGENABLE, false );

	pDevice->SetFVF(D3D_FVF);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,V,sizeof(Vertex));
}

void menu::Rectangle(int x, int y, int w, int h, D3DCOLOR BorderColor, IDirect3DDevice9 * pDevice) 
{ 
	int px = 1;
	if( !pDevice )
		return;

    Box( x, (y + h - px), w, px,     BorderColor, pDevice ); 
    Box( x, y, px, h,                BorderColor, pDevice ); 
    Box( x, y, w, px,                BorderColor, pDevice ); 
    Box( (x + w - px), y, px, h,     BorderColor, pDevice ); 
}

void menu::DrawCrosshair(int x, int y, LPDIRECT3DDEVICE9 pDevice)
{
	for(int dx = 0; dx < 30; dx++)
	{
		Rectangle(x - 15 + dx, y - 1, 1, 2, D3DCOLOR_ARGB(255, dx * 4, dx + 40, 255), pDevice);
		Rectangle(x - 1, y - 15 + dx, 2, 1, D3DCOLOR_ARGB(255, 205, dx + 60, dx * 7), pDevice);
	}
}
