/*XIGNCODE3.h D3D9 PBHacks Last Edit By Fatur Rezo*/
	LPD3DXFONT pFont;
	LPD3DXFONT g_pFont	= NULL;
	LPD3DXLINE g_pLine = 0;
	/*-------------------------------------------------------------------------------------------------------------------*/
typedef HRESULT (WINAPI* tEndScene)(LPDIRECT3DDEVICE9 pDevice);
tEndScene oEndScene = NULL;
HRESULT APIENTRY myEndScene( LPDIRECT3DDEVICE9 pDevice )
{
	_asm pushad;

	if(!fName)  D3DXCreateFont(pDevice, 14, 0, FW_BOLD  , 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Segoe UI"			 , &fName);//15
   if(!GetBattleState()){
			opt.cWeapon.FastShot=0;
			opt.cWeapon.RapidFire=0;
			opt.cSpesial.FakeReplace=0;
			opt.cPlayer.UNYU=0;
			opt.ModAim.Accuracy=0;
			opt.cKiller.Zombie=0;
			opt.cSpesial.AutoAja=0;
			opt.cPlayer.WallBug=0;
			opt.cPlayer.FreeMove=0;
			opt.cWeapon.BrustKnife=0;
			opt.cKiller.Invincible=0;
			opt.cSpesial.smk=0;
			opt.cSpesial.lchr=0;
			opt.cSpesial.ram=0;
			opt.cPlayer.Freeze=0;
			opt.cKiller.BombKill=0;
		    opt.cKiller.PisoTeleKill=0;
			opt.cKiller.PisoTeleKill1=0;
   }
   
   if(GetBattleState()){
	if(IsKeyPressed(VK_END, 0)&1){
		KillMySelf();
	}}
   if(GetBattleState()){
	       if(IsKeyPressed(VK_HOME, 0)&1){
		   opt.ModAim.Accuracy = !opt.ModAim.Accuracy;
		     BulletEnable = false;
	           }}
		if(GetBattleState()){
			if(IsKeyPressed(VK_F2, 0)&1){
				FakeEvolution();
			}}
		if(opt.cSpesial.AutoAja == 1)
	{
		if(IsKeyPressed(VK_LBUTTON, 1)&1){
		FakeEvolution();}
	}
		
	if(GetBattleState()){
if(opt.cKiller.FastDM == 1)
{
		KillMySelf();
		opt.cKiller.PisoTeleKill=!opt.cKiller.PisoTeleKill;
		opt.cKiller.WsHt=!opt.cKiller.WsHt;
		opt.cKiller.Invincible=!opt.cKiller.Invincible;
		opt.cKiller.TellePlayer=!opt.cKiller.TellePlayer;
		opt.cPlayer.Freeze=!opt.cPlayer.Freeze;}}
	if(GetBattleState()){
if(opt.cKiller.FastBM == 1)
{
		KillMySelf();
		opt.cKiller.PisoTeleKill=!opt.cKiller.PisoTeleKill;
		opt.cKiller.WsHt=!opt.cKiller.WsHt;
		opt.cKiller.Invincible=!opt.cKiller.Invincible;
		opt.cKiller.TellePlayer=!opt.cKiller.TellePlayer;
		}}
	if(IsKeyPressed(VK_F12, 0)&1)
	{
		ExitProcess(0);
	}
	if(!Tools.Init)
	{
			D3DXCreateLine(pDevice,&Tools.pLine);
			Tools.Init = TRUE;
	}
		PostReset(pDevice);
		Menu.ShowMenu(pDevice);
		PreReset(pDevice);
		

		pDevice->GetViewport(&Tools.g_ViewPort);
		ScreenCenterX = (float)Tools.g_ViewPort.Width / 2;
		ScreenCenterY = (float)Tools.g_ViewPort.Height / 2;
		if(*(PBYTE)ResultBaseAmmo2 > NULL)
		{
			EspMode(pDevice);
			DoAimBullet(pDevice);
			RapidFireWeapon();
			GhostHacks();
			BulletKiller();
		    SmokeKill();
		    GrenadeKill();
			AmmoRocket();
		    AmmoHK69();
		    AmmoLauncher();
			FastReload();
			BrustKnife();
			AmmoReload();
			/*AmmoGrenade();
			UnlimitedSmoke();*/
			
		}

	if(opt.d3d.cross)
	{
		Tools.FillRGB(ScreenCenterX-14, ScreenCenterY, 10, 1,D3DXCOLOR(1.0, 0.0, 0.0, 1.0),pDevice);//Left line
		Tools.FillRGB(ScreenCenterX+5, ScreenCenterY, 10, 1,D3DXCOLOR(1.0, 0.0, 0.0, 1.0),pDevice);//Right line
		Tools.FillRGB(ScreenCenterX, ScreenCenterY-14, 1, 10,D3DXCOLOR(1.0, 0.0, 0.0, 1.0),pDevice);//Top line
		Tools.FillRGB(ScreenCenterX, ScreenCenterY+5, 1, 10,D3DXCOLOR(1.0, 0.0, 0.0, 1.0),pDevice);//Bottom line
		Tools.DrawCircle(D3DXVECTOR2(ScreenCenterX,ScreenCenterY),8,60,D3DXCOLOR(1.0, 0.0, 0.0, 1.0));//Circle
		Tools.DrawPoint(ScreenCenterX,ScreenCenterY,1,1,D3DXCOLOR(0.0, 1.0, 0.0, 1.0),pDevice);//Point
	}
	_asm popad;

	return pEndScene( pDevice );
}
/*-------------------------------------------------------------------------------------------------------------------*/
void Hooked(PDWORD target, PDWORD newfunc){
	DWORD Jmpto=(DWORD)(newfunc)-(DWORD)target-5;
	DWORD a;
	VirtualProtect(target, 8, PAGE_EXECUTE_READWRITE, &a);
	*(PBYTE)(target)=0xE9;
	*(PDWORD)((DWORD)(target)+1)=Jmpto;
	VirtualProtect(target, 8, a, &a);
}

/*-------------------------------------------------------------------------------------------------------------------*/
#define pD3DdeviceX       LPDIRECT3DDEVICE9
#define Detour_Type_0xE9  1
#define Detour_Type_0xB8  2
#define Detour_Type_0x68  3

bool DeviceReset = true;
 
        DWORD Return_EndScene;
        DWORD retMyDIP;
        HMODULE Module_d3d9;
        LPDIRECT3DDEVICE9 ReadyDevice;
        pD3DdeviceX g_pDevice = 0;


/*-------------------------------------------------------------------------------------------------------------------*/
void *DetourFunction (BYTE *src, const BYTE *dst, const int len) 
{ 
        BYTE *jmp = (BYTE*)malloc(len+5); 
        DWORD dwBack; 

        VirtualProtect(src, len, PAGE_EXECUTE_READWRITE, &dwBack); 
        memcpy(jmp, src, len); 
        jmp += len; 
        jmp[0] = 0xE9; 
        *(DWORD*)(jmp+1) = (DWORD)(src+len - jmp) - 5; 
        src[0] = 0xE9; 
        *(DWORD*)(src+1) = (DWORD)(dst - src) - 5; 
        for (int i=5; i<len; i++)   
            src[i]=0x90; 
        VirtualProtect(src, len, dwBack, &dwBack); 
        return (jmp-len); 
} 

/*-------------------------------------------------------------------------------------------------------------------*/
void PreReset(pD3DdeviceX pDevice)
{
	if(pFont)
		pFont = NULL;
	if(g_pFont)
		g_pFont = NULL;
	if(g_pDevice != pDevice )
		g_pDevice = pDevice;
	if(pFont)
	{
		pFont->Release();
		pFont = NULL;
		pFont = FALSE;
	}
	if(g_pFont)
	{
		g_pFont->Release();
		g_pFont = NULL;
		g_pFont = FALSE;
	}
	pFont = NULL;
	g_pFont = NULL;
}

/*-------------------------------------------------------------------------------------------------------------------*/
void PresetDevice()
{
	PreReset(pDevice);
	DeviceReset = true;
	ReadyDevice = pDevice;
}

/*-------------------------------------------------------------------------------------------------------------------*/
void PostReset(LPDIRECT3DDEVICE9 pDevice)
{
	if(!Create)
	{
		D3DXCreateFont(pDevice, 14, 0, FW_HEAVY, 0, FALSE, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY, /*DEFAULT_PITCH | */FF_DONTCARE, TEXT("Showcard Gothic"), &pFont );
		if(pFont == NULL)D3DXCreateFont(pDevice, 14, 0, FW_HEAVY, 0, FALSE, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY, /*DEFAULT_PITCH | */FF_DONTCARE, TEXT("Arial"), &pFont );
		D3DXCreateFontA(pDevice, 14, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arail", &g_pFont); //Create fonts
		if(g_pFont == NULL)D3DXCreateFontA(pDevice, 14, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arail", &g_pFont); //Create fonts
		D3DXCreateLine(pDevice,&g_pLine);
		if(g_pLine == NULL)D3DXCreateLine(pDevice,&g_pLine);
		Create = true;
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
void FontReset()
{
	Tools.pLine->OnLostDevice();
	Tools.pLine->OnResetDevice();
	Tools.pLine->OnLostDevice();
	Tools.pLine->OnResetDevice();
	Tools.pLine->OnLostDevice();  
	Tools.pLine->OnResetDevice();
}
//aq mw off dah mlm bisa
/*-------------------------------------------------------------------------------------------------------------------*/
void Render()
{
pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
	if (DeviceReset == true)
	{
		if(pDevice !=  ReadyDevice)
		{
			DeviceReset = false;
			PresetDevice();
		}
	}
	if (DeviceReset == true)
	{
		if  (pFont==NULL)
		{
			PostReset(pDevice);
			ReadyDevice = pDevice;
		}
		else
		{      
			FontReset();
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
__declspec(naked) void MidFunction_EndScene()
{
        __asm
        {
                mov edi,edi
                push ebp
                mov ebp,esp
                mov pDevice,esi
                pushad
                call [Render]
                popad
                jmp [Return_EndScene]
        }
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD CreateDetour(DWORD dwThread,DWORD dwAdress,DWORD dwType,DWORD dwSize)
{
        DWORD dwDetour,dwProtect,i;
        if (dwAdress&&dwThread&&dwSize>= dwSize)
        {
                dwDetour = (DWORD)VirtualAlloc(0,dwSize+dwSize,0x1000,0x40);
                if (dwDetour&&VirtualProtect((VOID*)dwAdress,dwSize,0x40,&dwProtect))
                {
                        for (i=0;i<dwSize;i++)
                        {
                                *(BYTE*)(dwDetour+i)=*(BYTE*)(dwAdress+i);
                        }
                        switch (dwType)
                        {
                            case Detour_Type_0xE9:
                                {
                                    *(BYTE*)(dwDetour+dwSize+0)=0xE9;
                                    *(DWORD*)(dwDetour+dwSize+1)=(dwAdress-dwDetour-dwSize);
                                    *(BYTE*)(dwAdress+0)=0xE9;
                                    *(DWORD*)(dwAdress+1)=(dwThread-dwAdress-dwSize);
                                }
                                break;
                                case Detour_Type_0xB8:
                                {
                                    *(BYTE*)(dwDetour+dwSize+0)=0xB8;
                                    *(DWORD*)(dwDetour+dwSize+1)=(dwAdress+dwSize);
                                    *(WORD*)(dwDetour+dwSize+5)=0xE0FF;
                                    *(BYTE*)(dwAdress+0)=0xB8;            
                                    *(DWORD*)(dwAdress+1)=(dwThread);
                                    *(WORD*)(dwAdress+5)=0xE0FF;
                                }
                                break;
                                case Detour_Type_0x68:
                                {
                                    *(BYTE*)(dwDetour+dwSize+0)=0x68;
                                    *(DWORD*)(dwDetour+dwSize+1)=(dwAdress+dwSize);
                                    *(WORD*)(dwDetour+dwSize+5)=0xC3;
                                    *(BYTE*)(dwAdress+0)=0x68;            
                                    *(DWORD*)(dwAdress+1)=(dwThread);
                                    *(WORD*)(dwAdress+5)=0xC3;
                                }
                                break;
                        }
                        VirtualProtect((VOID*)dwAdress,dwSize,dwProtect,&dwProtect);
                        VirtualProtect((VOID*)dwDetour,dwSize+dwSize,0x20,&dwProtect);
                        return dwDetour;
                }
        }
        Sleep(10);
        return (0);
}

/*-------------------------------------------------------------------------------------------------------------------*/
_declspec(naked)void EndRender_Hook()
{
	_asm
	{
		mov edx,[ecx+0xA8]
		mov [oEndScene],edx
			mov edx,[hkEndScene]
		jmp EndRenderBCK;
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
_declspec(naked)void DrawIndexPrim_Hook()
{
	_asm
	{
		mov eax,[ecx+0x148]
		mov [oDrawIndexedPrimitive],eax
			mov eax,[hkDrawIndexedPrimitive]
		jmp DrawIndexPrimBCK;
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
INT HookD3D9()
{
    DWORD D3D9 = NULL;
    DWORD Address;
    DWORD* vTable;
    while( D3D9 == NULL )
    {
        D3D9 = ( DWORD ) GetModuleHandle( "d3d9.dll" );
    }
    Address = FindPattern( D3D9, 0x128000, ( BYTE* ) "\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86", "xx????xx????xx");
    memcpy( &vTable, ( void* ) ( Address + 2 ), 4 );
    oEndScene = ( tEndScene ) DetourFunction( ( PBYTE ) vTable[ 42 ], ( PBYTE ) myEndScene , 5);
    return 0;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD WINAPI NxHook(LPVOID param)
{
	while(true)
	{
	if(ChekLogPortal==true)
	{
		if(GetPlayerState()==true && CHekHook==false)
		{	
			if(GetDevice__EndScene!=NULL)
			{
				Return_EndScene = GetDevice__EndScene + 0x5;
			    CreateDetour((DWORD)MidFunction_EndScene,(DWORD)GetDevice__EndScene,Detour_Type_0xE9, 5);
			}
			else
			{
				JMPE9((PBYTE)NeoEndRenderTarget,(DWORD)EndRender_Hook,6);
				JMPE9((PBYTE)NeoDrawIndexPrimTarget,(DWORD)DrawIndexPrim_Hook,6);	
			}
		CHekHook=true;
		}		
	}
	Sleep(10);
	}
	return 0;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD WINAPI Discover_Portal(LPVOID param)
{
	while(true)
	{
	if(ChekLogPortal==true && CHekHook==false)
	{
		//if(GetAsyncKeyState(VK_HOME)&&0x8000)
		if(GetPlayerState())
		{	
			JMPE9((PBYTE)NeoEndRenderTarget,(DWORD)EndRender_Hook,6);
			JMPE9((PBYTE)NeoDrawIndexPrimTarget,(DWORD)DrawIndexPrim_Hook,6);
		//CHekHook=true;
		}		
	}
	Sleep(1);
	}
	return 0;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD WINAPI HookEngine(LPVOID Param)
{
	if (hGfxDx > 0){
		DWORD tmp1 = (DWORD)GetProcAddress(GetModuleHandleA("i3GfxDx.dll"), "?g_pRenderContext@@3PAVi3RenderContext@@A");
		DWORD tmp2 = 0;
		Sleep(1);
		while(!pGDevice){
			if(IsBadReadPtr((PDWORD)tmp1,4)==NULL)tmp2 = *(PDWORD)((DWORD)(tmp1))+0x5368;
			Sleep(1);
			if(IsBadReadPtr((PDWORD)tmp2,4)==NULL){
				DWORD OldProtect;
				VirtualProtect((void*)(tmp2), 4, PAGE_EXECUTE_READWRITE, &OldProtect);
				memcpy(&pGDevice, (void *)tmp2, 4);
				VirtualProtect((void*)(tmp2), 4, OldProtect, NULL);}
		}
		DWORD *g_pDevice = (DWORD*)pGDevice;
		g_pDevice = (DWORD*)g_pDevice[0];
		while(!npDevice)npDevice = (LPDIRECT3DDEVICE9)(DWORD*)g_pDevice;
		*(PDWORD)&oEndScene	= g_pDevice[42];
		*(PDWORD)&oDrawIndexedPrimitive	= g_pDevice[82];
		*(PDWORD)&oReset	= g_pDevice[16];
		Hooked((PDWORD)(g_pDevice[1] - 5), (PDWORD)(g_pDevice[4] - 5));
		Hooked((PDWORD)(g_pDevice[2] - 5), (PDWORD)(g_pDevice[5] - 5));
		Hooked((PDWORD)(g_pDevice[3] - 5), (PDWORD)(g_pDevice[6] - 5));
		Hooked((PDWORD)(g_pDevice[4] - 5), (PDWORD)hkEndScene);
		Hooked((PDWORD)(g_pDevice[5] - 5), (PDWORD)hkDrawIndexedPrimitive);
		Hooked((PDWORD)(g_pDevice[6] - 5), (PDWORD)hkReset);
		for(;;)
		{
			g_pDevice[42] = (DWORD)g_pDevice[1] - 5;
			g_pDevice[82] = (DWORD)g_pDevice[2] - 5;
			g_pDevice[16] = (DWORD)g_pDevice[3] - 5;
			DWORD ByPass = (DWORD)LoadLibraryA("i3BaseDx_Cli.dll");
			PacthHook((void *)(ByPass+0xEF94),(void*)(PBYTE)"\xEB",1);
			PacthHook((void *)(ByPass+0xEFC3),(void*)(PBYTE)"\xEB",1);
			PacthHook((void *)(ByPass+0xF025),(void*)(PBYTE)"\xEB",1);
			PacthHook((void *)(ByPass+0xF115),(void*)(PBYTE)"\xEB",1);
		}
		Sleep(100); 
	}
	return 0;
}
