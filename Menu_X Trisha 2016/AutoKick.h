DWORD PTR_Caller,BaseECX,CallBasePB,Definition,ReDefinition,ReadProcASM, StartRouneAmmo= NULL;
void FloodKickPlayer(int IndexPlayer) 
{ 
Sleep(100); 
if(Keprox == false) 
{ 
CallBasePB = (DWORD)GetModuleHandle("Pointblank.exe");
PTR_Caller = (DWORD)( ResultSetEvent ); 
BaseECX = *(DWORD*)( ResultBasePlayer2); 
BYTE pKick[15]; 
*(BYTE*)(pKick) = IndexPlayer; 
Definition = (DWORD)pKick; 
ReDefinition = (DWORD)pKick + 0x4; 
Sleep(5); 
__asm 
{ 
push 0x01 
push 0x01 
push 0x01 
push [ReDefinition] 
push [Definition] 
push 0xA0 
mov ecx,[BaseECX] 
call [PTR_Caller] 
} 
Sleep(100); 
Keprox = true; 
}
} 
DWORD WINAPI ThreadFloodVK() //pemanggil void nih 
{ 
while(1) 
{ 
if(FloodVk == 1) 
{ 
Sleep(100); 
Keprox = false; 
if(*(PBYTE)ResultBaseAmmo2 > NULL) 
{ 
Sleep(5); 
for (int i = 0; i<=15; i++) 
{ 
int MySlot = GetMyCharaIndex(); 
if( i == MySlot)continue; 
FloodKickPlayer(i); 
}}} 
Sleep(100); 
} 
return 0; 
}   

void DrawChekBoxServer( int x, int y, int &Var, IDirect3DDevice9* pDevice )
{
	if( !pDevice )
		return;
    DrawBoxObsv( x, y, 167, 18,Black, TeamColor, pDevice );
}
int lm;
int rm;
int flm;
int frm;

void VKPilih(int IndexPlayer) 
{ 
Sleep(0); 
if(Keprox == false) 
{ 
CallBasePB = (DWORD)GetModuleHandle("Pointblank.exe");
PTR_Caller = (DWORD)( ResultSetEvent ); 
BaseECX = *(DWORD*)( ResultBasePlayer2); 
BYTE pKick[15]; 
*(BYTE*)(pKick) = IndexPlayer; 
Definition = (DWORD)pKick; 
ReDefinition = (DWORD)pKick + 0x4; 
Sleep(5); 
__asm 
{ 
push 0x01 
push 0x01 
push 0x01 
push [ReDefinition] 
push [Definition] 
push 0xA0 
mov ecx,[BaseECX] 
call [PTR_Caller] 
} 
Sleep(0); 
Keprox = true; 
}
} 

void KickPlayer(LPDIRECT3DDEVICE9 pDevice)
{
	
//pDevice->GetViewport(&viewP);
lm	 =    GetAsyncKeyState(VK_LBUTTON)&1;	
rm   =    GetAsyncKeyState(VK_RBUTTON)&1;
flm	 =    GetAsyncKeyState(VK_LBUTTON);	
frm  =    GetAsyncKeyState(VK_RBUTTON);	
if(GetBattleState1()){
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
DrawString(ScreenCenterX - ServerRED + 40,480,RED,".:: Silahkan Memilih Player Yang Mau Di VK ::.",pDevice);				
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
if(*(PBYTE)ResultBaseAmmo2 > NULL) 
{ 
Sleep(10); 
for (int i = 0; i<=15; i++) 
{ 
int MySlot = GetMyCharaIndex(); 
if( i == MySlot)continue;

if (VoteKick == 1){
if(GetAsyncKeyState(VK_LBUTTON)&&0x8000)
{
VKPilih(i); 
VoteKick=0;
}
}
}
}}