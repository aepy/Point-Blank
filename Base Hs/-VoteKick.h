/*- VoteKick.h D3D9 PBHacks Last Edit By Angga Reviza*/
/*---------------------------------------- Declaration String----------------------------------------------------*/
DWORD CGameContextPointer(void) {	
	
	unsigned long dwBase = *(DWORD*)ResultBasePlayer2;
		return dwBase;
}

CNames	*oNames(UINT i)	
{
	return 
		(CNames*)((CGameContextPointer() + ResultNAMES) + i * ResultRANKSIZE);
}

/*---------------------------------------- Declaration Mouse ----------------------------------------------------*/
BOOL  IsInBox(int x, int y, int w, int h)
{
	POINT MousePosition;
	GetCursorPos(&MousePosition);
	ScreenToClient(GetForegroundWindow(), &MousePosition);
	return(MousePosition.x >= x && MousePosition.x <= x + w && MousePosition.y >= y && MousePosition.y <= y + h);
}

/*---------------------------------------- Declaration DrawBoxz ----------------------------------------------------*/
void DrawBoxz( int x, int y, int w, int h, D3DCOLOR BoxColor, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
	FillRGB( x, y, w, h, BoxColor, pDevice );
	DrawBorder( x, y, w, h, 1, BorderColor, pDevice );
}

/*---------------------------------------- Declaration DrawBox ----------------------------------------------------*/
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

/*---------------------------------------- Declaration DrawChekBoxServer ----------------------------------------------------*/
void DrawChekBoxServer( int x, int y, int &Var, IDirect3DDevice9* pDevice )
{
	if( !pDevice )
		return;
	DrawBoxz( x, y, 147, 18,BLACK, TeamColor, pDevice );
	if (IsInBox(x, y, 147, 18))
	{
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
	}
	Box(x + 1, y + 1, 38, 13, RED, pDevice);
	if (Var > 0)
	{
		Box(x+29, y - 2, 13, 19, EColOn, pDevice);
	}
	else
	{
		Box(x - 2, y - 2, 13, 19, EColOn, pDevice);
	}
}

/*---------------------------------------- Declaration Vote Kick ----------------------------------------------------*/
void SendEventVK(LPDIRECT3DDEVICE9 pDevice)
{
	if(VoteKick==1)
	{
		int ServerX1=750;
		int ServerY1=480;
		int ServerX2=100;
		int ServerY2=480;
		if(*(PBYTE)ResultBaseAmmo2 > NULL)
		{
			for (int i = 0; i<=15; i++)
			{
				int MySlot = GetMyCharaIndex(); 
				if( i == MySlot)continue; 
				int iTeam= GetTeam(i);
				VKick();
				if (iTeam == 1)
				{
					TeamColor = BLUE;
					DrawChekBoxServer((int)ServerX1 + 10,(int)ServerY1+(10*i),iTeam,pDevice);
					DrawString(ServerX1 + 10,(ServerY1+2)+(10*i),WHITE,"%s ",oNames(i)->szNames);
				}
				if (iTeam == 2)
				{
					TeamColor = RED;
					DrawChekBoxServer((int)ServerX2 + 10,(int)(ServerY2+9)+(10*i),iTeam,pDevice);	
					DrawString(ServerX1 + 16,(ServerY1+2)+(10*i),WHITE," %s ",oNames(i)->szNames);
				}
			}
		}
	}
	Sleep(10);
}

/*-------------------------------------------------------------------------------------------------------------------*/