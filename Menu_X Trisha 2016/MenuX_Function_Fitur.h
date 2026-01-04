DWORD ModulePB = (DWORD)LoadLibraryA("PointBlank.exe");
bool bBetrayer = false;
bool bGExit = false;
bool Bbetrayer = true;
bool BGExit = true;
bool Shot = false;
bool HookedShot = false;
int CallReplace = NULL;
bool xPiso = false;
bool xbAmmo=false;
bool bGhoster = false;
static BOOL sprite = TRUE; 
DWORD XL,Betrayer;
void gEtWeapon_IndexA(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, DWORD Value)
{ 
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)Base,4)==0){
	Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
	if (IsBadReadPtr((PDWORD)Temp,4)==0){
	Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
	if (IsBadReadPtr((PDWORD)Temp,4)==0){
	Temp=*(PDWORD)((DWORD)(Temp))+Ofs3;
	if (IsBadReadPtr((PDWORD)Temp,4)==0){
	*(PDWORD)Temp=Value;}}}}
}
int GetTeam1(int JONES)
{
for(int i = 0; i<=15; i+=2)
if( i == JONES ) return 1;
for(int i = 1; i<=15; i+=2)
if( i == JONES ) return 2;
return 0;
}
LPTSTR PointBlankSTR8 = "PointBlank.exe";
int GetMyCharaIndexed(unsigned int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR8);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + ResultBasePlayer);
CTeam *MyTeam = (CTeam*) ((dwBase + ResultTeam));
Index=MyTeam->iTeam;
return Index;
}
void c_WeaponIndex_B(unsigned long adr, unsigned long Ofset1, unsigned long Ofset2, unsigned long Ofset3, unsigned long Ofset4, DWORD dwValue){ 
DWORD A=0;
if(IsBadReadPtr((PDWORD)adr,4))return;
A=*(PDWORD)((DWORD)(adr))+Ofset1;
if(IsBadReadPtr((PDWORD)A,4))return;
A=*(PDWORD)((DWORD)(A))+Ofset2;
if(IsBadReadPtr((PDWORD)A,4))return;
A=*(PDWORD)((DWORD)(A))+Ofset3;
if(IsBadReadPtr((PDWORD)A,4))return;
A=*(PDWORD)((DWORD)(A))+Ofset4;
if(IsBadReadPtr((PDWORD)A,4))return;
if(*(PDWORD)A!=dwValue)*(PDWORD)A=dwValue;
}
DWORD ReadFunct(DWORD dwPtr, DWORD dwOfs){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return *(PDWORD)C; 
}
}
return C;
}
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
DWORD TestPacth(DWORD dwPtr,DWORD A1,DWORD B1,DWORD C1)
{
	DWORD C=0;
	if (IsBadReadPtr((PDWORD)dwPtr,4)==0){
	C=*(PDWORD)((DWORD)(dwPtr))+A1;
	if (IsBadReadPtr((PDWORD )C,4)==0){
	C=*(PDWORD)((DWORD)(C ))+ B1;
	if (IsBadReadPtr((PDWORD)C,4)==0) {
	C=*(PDWORD)((DWORD)(C ))+ C1;
	if (IsBadReadPtr((PDWORD)C,4)==0) {
	return *(PDWORD)C; } } }
	}
	return C;
}
void PacthWeapone(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, DWORD Value)
{ 
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)Base,4)==0){
	Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
	if (IsBadReadPtr((PDWORD)Temp,4)==0){
	Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
	if (IsBadReadPtr((PDWORD)Temp,4)==0){
	Temp=*(PDWORD)((DWORD)(Temp))+Ofs3;
	if (IsBadReadPtr((PDWORD)Temp,4)==0){
	*(PDWORD)Temp=Value;}}}}
}
void PactJumper (DWORD Base,DWORD Ofs1, BYTE Value)
{ 
DWORD Temp=NULL;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
*(PBYTE)Temp=Value;
}
}
}
void PatchValue(DWORD BaseOfs, DWORD Offset1, DWORD Offset2, DWORD Offset3, DWORD Value)
{
DWORD Temp=0;
if (IsBadReadPtr((PDWORD)BaseOfs, 4) == 0){ 
Temp = *(PDWORD)((DWORD)(BaseOfs)) + Offset1;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
Temp = *(PDWORD)((DWORD)(Temp)) + Offset2;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
Temp = *(PDWORD)((DWORD)(Temp)) + Offset3;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){
*(PDWORD)Temp = Value;
}}}}}
void LongPtr ( DWORD adress, DWORD offset, DWORD offset2, int Value )
{
	__try
	{
		DWORD OldPtr;
		OldPtr = *(PDWORD)((DWORD)adress) + offset;
		OldPtr = *(PDWORD)((DWORD)OldPtr) + offset2;
		*(int*)(OldPtr) = Value;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
	}

}
void PatchBom(DWORD B,DWORD A1,DWORD B1, DWORD ISI)
{ DWORD A=0;
if (IsBadReadPtr((PDWORD)B,1)==0)
{ A=*(PDWORD)((DWORD)(B))+A1;
if (IsBadReadPtr((PDWORD)A,1)==0)
{ A=*(PDWORD)((DWORD)(A))+B1;
if (IsBadReadPtr((PDWORD)A,1)==0)
{*(PDWORD)A=ISI;
}
}
}
}
void PachtChara(DWORD B,DWORD A1,DWORD B1, DWORD ISI){
		DWORD A=0;
		if (IsBadReadPtr((PDWORD)B,4)==0){
		A=*(PDWORD)((DWORD)(B))+A1;
		if (IsBadReadPtr((PDWORD )A,4)==0){
		A=*(PDWORD)((DWORD)(A ))+ B1;
		if (IsBadReadPtr((PDWORD)A,4)==0) {
		{*(PDWORD)A=ISI;}}}}}
void PacthHook(void *adr, void *ptr, int size)
{
DWORD CheckProtection = 0;
VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &CheckProtection);
RtlMoveMemory(adr,ptr,size);
VirtualProtect(adr,size,CheckProtection, &CheckProtection);
}
bool IsAlive(int Index)
{
//DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA("PointBlank.exe");
unsigned long dwBase2	= *(DWORD*)(ResultBaseHealth2);
CHealth		*Health		= (CHealth*) ((dwBase2 + 0x264) + Index * 0x24);
if(Health->CurHP > 0.1f)
return true;
return false;
}
void Error_Log(void  *Mini, void  *ptr, int  size)
{
DWORD Minimize;
VirtualProtect(Mini,size,PAGE_EXECUTE_READWRITE, &Minimize);
memcpy(Mini,ptr,size); 
VirtualProtect(Mini,size,Minimize, &Minimize);
}
void Replay_12ddfx(DWORD BaseOfs, DWORD Offset1, DWORD Offset2, DWORD Offset3, DWORD Value) 
{ 
DWORD Temp=0; if (IsBadReadPtr((PDWORD)BaseOfs, 4) == 0)
{ 
	Temp = *(PDWORD)((DWORD)(BaseOfs)) + Offset1; 
	if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
	Temp = *(PDWORD)((DWORD)(Temp)) + Offset2; 
	if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
	Temp = *(PDWORD)((DWORD)(Temp)) + Offset3; 
	if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
	*(PDWORD)Temp = Value;
	}}}}}
int GetMyCharaIndex(){
		unsigned long dwBase	= *(DWORD*)(ModulePB + ResultBasePlayer);
		unsigned long dwBase2	= *(DWORD*)(ModulePB + ResultBasePlayer-0x34);
		CTeam *MyTeam = (CTeam*) ((dwBase + ResultTeam));
		return MyTeam->iTeam;
}

bool GetUserBone( D3DXVECTOR3 &Out,  int BoneIdx ,int Idx)
{
	DWORD dwGameBase = *(DWORD*)ResultBaseHealth2;
	if ( dwGameBase )
	{
		CGameBase* GameBase = (CGameBase*)( *(DWORD*)(dwGameBase + 0x14 + ( 0x4 * Idx ) ) );
		if ( GameBase && GameBase->Bones)
		{
			Out.x = GameBase->Bones->BoneData[ BoneIdx ].BoneMatrix._41;
			Out.y = GameBase->Bones->BoneData[ BoneIdx ].BoneMatrix._42;
			Out.z = GameBase->Bones->BoneData[ BoneIdx ].BoneMatrix._43;
			return true;
		}
	}
	return false;
}

bool YoWorlToScreenGa(LPDIRECT3DDEVICE9 pDevice, D3DVECTOR Player,D3DVECTOR &PlayerScaled)
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
void DrawLine ( long Xa, long Ya, long Xb, long Yb, DWORD dwWidth, float Health) 
{    
	DWORD HPcol = Blue;
	if (Health < 90)HPcol = Green;
	if (Health < 80) HPcol = Yellow;
	if (Health < 40) HPcol = Orange;
	if (Health < 10) HPcol = Red;
	D3DXVECTOR2 vLine[ 2 ]; // 2 Poin 
	NHLine->SetAntialias( 0 ); // Set Tepi 

	NHLine->SetWidth( dwWidth ); // Lebar Dari Line 
	NHLine->Begin(); 

	vLine[ 0 ][ 0 ] = Xa; // Jadikan Point Menjadi Array 
	vLine[ 0 ][ 1 ] = Ya; 
	vLine[ 1 ][ 0 ] = Xb; 
	vLine[ 1 ][ 1 ] = Yb; 

	NHLine->Draw( vLine, 2, HPcol ); // Draw Garis , Jumlah Garis , Warna Garis  
	NHLine->End(); // Selesai 
} 
float FindDistance(D3DXVECTOR3 my,D3DXVECTOR3 other,CPlayers* pPlayer,CPlayers* pLocal){
	return sqrt((pLocal->pos.x-pPlayer->pos.x)*(pLocal->pos.x-pPlayer->pos.x) + (pLocal->pos.y-pPlayer->pos.y)*(pLocal->pos.y-pPlayer->pos.y) + (pLocal->pos.z-pPlayer->pos.z)*(pLocal->pos.z-pPlayer->pos.z));
} 
void DrawStringH(float x, float y , DWORD color, const char *fmt, ...){ 
	RECT FontPos = { x, y, x + 20, y + 10 };
	char buf[1024] = {'\0'};
	va_list va_alist;
	va_start(va_alist, fmt);
	vsprintf(buf, fmt, va_alist);
	va_end(va_alist);
	fName->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
} 
void HealthBar15(int x, int y, float Health)
{
	const D3DCOLOR colours[] = { Red, Red, Red, Red, Orange, Orange, Orange, Orange, Yellow, Yellow, Yellow, Yellow, Green, Green, Green, Green, Green, Green, Blue, Blue }; // this is our order
	int boxSizeX = 2; 
	int boxSizeY = 7;
	int boxGap = 1;
	for ( int c = 0 ; c < 20; c++ )
	{
		if ( Health > ( 5 * c ) )
			DrawBorder(x-1,y-1,62,9,1,colours[c],i3Device );
	}
	for ( int i = 0 ; i < 20; i++ )
	{
		if ( Health > ( 5 * i ) )
			FillRGB(x,y, boxSizeX, boxSizeY,colours[i],i3Device);		
		else
			FillRGB(x,y, boxSizeX, boxSizeY,Grey,i3Device);
			x = x + boxSizeX+ boxGap;
	}
}
void DrawStringESP(int x, int y, DWORD color, const char *fmt, ...)
{
	RECT FontPos = { x, y, x + 200, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	
	NHT3XT->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}


void DrawBoxESP( int x, int y, int w, int h, float Health, IDirect3DDevice9* pDevice )
{
	DWORD HPcol = Blue;
	if (Health < 90)HPcol = Green;
	if (Health < 80) HPcol = Yellow;
	if (Health < 40) HPcol = Orange;
	if (Health < 10) HPcol = Red;
	DrawBorder( x, y, w, h, 1, HPcol, pDevice );
} 

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

#define PISSS 3.14159265
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
	pDevice	->	SetFVF			( D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1 );
	pDevice	->	SetTexture		( 0, NULL );
	pDevice	->	DrawPrimitiveUP	( D3DPT_LINESTRIP, NUMPOINTS, &Circle[0], sizeof(Circle[0]) );
}

DWORD GetPlayerTarget(int myIDX)
{
	DWORD BasePlayer_B = *(DWORD*)(ResultBaseHealth2);
	if(IsBadReadPtr((void*)BasePlayer_B,4))return 0;
	DWORD PlayerIndexA = *(DWORD*)(BasePlayer_B + 0x14 + (myIDX * 4));
	if(IsBadReadPtr((void*)PlayerIndexA,4))return 0;
	DWORD PlayerIndexB = *(DWORD*)(PlayerIndexA + 0x560);  //560
	if(IsBadReadPtr((void*)PlayerIndexB,4))return 0;
	DWORD IsTargetingEnemy = *(DWORD*)(PlayerIndexB + 0x94E8);
	if(IsBadReadPtr((void*)IsTargetingEnemy,4))return 0;
return IsTargetingEnemy;
}


DWORD BurstPiso, vReload = 0;
DWORD _ReadMEM(DWORD dwPtr,DWORD A1,DWORD B1,DWORD C1,DWORD D1)
{
	DWORD C=0;
	if (IsBadReadPtr((PDWORD)dwPtr,4)==0)
	{
		C=*(PDWORD)((DWORD)(dwPtr))+A1;
		if (IsBadReadPtr((PDWORD )C,4)==0)
		{
			C=*(PDWORD)((DWORD)(C ))+ B1;
			if (IsBadReadPtr((PDWORD)C,4)==0)
			{
				C=*(PDWORD)((DWORD)(C ))+ C1;
				if (IsBadReadPtr((PDWORD)C,4)==0)
				{
					C=*(PDWORD)((DWORD)(C ))+ D1;
					if (IsBadReadPtr((PDWORD)C,4)==0)
					{
						return *(PDWORD)C; 
					}
				}
			}
		}
	}
	return C;
}
DWORD _ReadMEM(DWORD dwPtr,DWORD A1,DWORD B1,DWORD C1)
{
	DWORD C=0;
	if (IsBadReadPtr((PDWORD)dwPtr,4)==0)
	{
		C=*(PDWORD)((DWORD)(dwPtr))+A1;
		if (IsBadReadPtr((PDWORD )C,4)==0)
		{
			C=*(PDWORD)((DWORD)(C ))+ B1;
			if (IsBadReadPtr((PDWORD)C,4)==0)
			{
				C=*(PDWORD)((DWORD)(C ))+ C1;
				if (IsBadReadPtr((PDWORD)C,4)==0)
				{
					return *(PDWORD)C; 
				}
			}
		}
	}
	return C;
}
DWORD BulletFast = 0;
DWORD _ReadMEM(DWORD dwPtr,DWORD A1,DWORD B1)
{
	DWORD C=0;
	if (IsBadReadPtr((PDWORD)dwPtr,4)==0)
	{
		C=*(PDWORD)((DWORD)(dwPtr))+A1;
		if (IsBadReadPtr((PDWORD )C,4)==0)
		{
			C=*(PDWORD)((DWORD)(C ))+ B1;
			if (IsBadReadPtr((PDWORD)C,4)==0)
			{
				return *(PDWORD)C; 
			}
		}
	}
	return C;
}
bool GetBattleState1() { 
unsigned long xBase = *(DWORD*)ResultBaseAmmo2; 
if(xBase > NULL)
{ 
return true; 
}return false; 
}

void _WriteMEM(DWORD Adr, DWORD Ptr1, DWORD Ptr2, DWORD WriteValue)
{
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)Adr, 4) == 0)
	{ 
		Temp = *(PDWORD)((DWORD)(Adr)) + Ptr1;
		if (IsBadReadPtr((PDWORD)Temp,4) == 0)
		{ 
			Temp = *(PDWORD)((DWORD)(Temp)) + Ptr2;
			if (IsBadReadPtr((PDWORD)Temp,4) == 0)
			{ 
				*(PDWORD)Temp = WriteValue;
			}
		}
	}
}

WORD WriteVaL1, WriteVaL2, WriteVaL3, WriteVaL4, WriteVaL5;
void __ReadMEM(DWORD Adr, DWORD Ptr1, DWORD Ptr2, DWORD Ptr3, DWORD ReadValue)
{
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)Adr, 4) == 0)
	{ 
		Temp = *(PDWORD)((DWORD)(Adr)) + Ptr1;
		if (IsBadReadPtr((PDWORD)Temp,4) == 0)
		{ 
			Temp = *(PDWORD)((DWORD)(Temp)) + Ptr2;
			if (IsBadReadPtr((PDWORD)Temp,4) == 0)
			{ 
				Temp = *(PDWORD)((DWORD)(Temp)) + Ptr3;
				if (IsBadReadPtr((PDWORD)Temp,4) == 0)
				{
					switch (ReadValue)
					{
						case 1:
						WriteVaL1 = *(PWORD)Temp;
						case 2:
						WriteVaL2 = *(PWORD)Temp;
						case 3:
						WriteVaL3 = *(PWORD)Temp;
						case 4:
						WriteVaL4 = *(PWORD)Temp;
						case 5:
						WriteVaL5 = *(PWORD)Temp;
					}
				}
			}
		}
	}
}
void _WriteMEM(DWORD Adr, DWORD Ptr1, DWORD Ptr2, DWORD Ptr3, DWORD WriteValue)
{
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)Adr, 4) == 0)
	{ 
		Temp = *(PDWORD)((DWORD)(Adr)) + Ptr1;
		if (IsBadReadPtr((PDWORD)Temp,4) == 0)
		{ 
			Temp = *(PDWORD)((DWORD)(Temp)) + Ptr2;
			if (IsBadReadPtr((PDWORD)Temp,4) == 0)
			{ 
				Temp = *(PDWORD)((DWORD)(Temp)) + Ptr3;
				if (IsBadReadPtr((PDWORD)Temp,4) == 0)
				{
					*(PDWORD)Temp = WriteValue;
				}
			}
		}
	}
}


void _WriteMEM(DWORD Adr, DWORD Ptr1, DWORD Ptr2, DWORD Ptr3, DWORD Ptr4, DWORD WriteValue)
{
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)Adr, 4) == 0)
	{ 
		Temp = *(PDWORD)((DWORD)(Adr)) + Ptr1;
		if (IsBadReadPtr((PDWORD)Temp,4) == 0)
		{ 
			Temp = *(PDWORD)((DWORD)(Temp)) + Ptr2;
			if (IsBadReadPtr((PDWORD)Temp,4) == 0)
			{ 
				Temp = *(PDWORD)((DWORD)(Temp)) + Ptr3;
				if (IsBadReadPtr((PDWORD)Temp,4) == 0)
				{
					Temp = *(PDWORD)((DWORD)(Temp)) + Ptr4;
					if (IsBadReadPtr((PDWORD)Temp,4) == 0)
					{
						*(PDWORD)Temp = WriteValue;
					}
				}
			}
		}
	}
}
void PrivateOnly(void *adr, void *ptr, int size)
{ 
DWORD NextProtection;
VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &NextProtection);
Sleep(1);
Sleep(1);
RtlCopyMemory(adr,ptr,size);
Sleep(1);
Sleep(1);
VirtualProtect(adr,size,NextProtection, &NextProtection);
}
bool MakePoint(unsigned long ADRexec, int OFSexec, int PTRexec)
{
if (!IsBadReadPtr((void*)ADRexec, sizeof(unsigned long)))
{
if (!IsBadReadPtr((void*)(*(unsigned long*)ADRexec + OFSexec), sizeof(unsigned long)))
{
*(int*)(*(unsigned long*)ADRexec + OFSexec) = PTRexec;
}
}
return 0;
}
void NHMemFuction (void *adr, void *ptr, int size)
{
        DWORD CheckProtection;
        VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &CheckProtection);
        memcpy(adr,ptr,size);
        VirtualProtect(adr,size,CheckProtection, &CheckProtection);
} 
void patchPTR(unsigned long adr, unsigned long Ofset1, DWORD dwValue){ 
DWORD A=0;
if(IsBadReadPtr((PDWORD)adr,4))return;
A=*(PDWORD)((DWORD)(adr))+Ofset1;
if(IsBadReadPtr((PDWORD)A,4))return;
if(*(PDWORD)A!=dwValue)*(PDWORD)A=dwValue;
}
void Function_One(DWORD Base,DWORD Ofs1, BYTE Value){ 
DWORD Temp=NULL;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
*(PBYTE)Temp=Value;
}
}
}
void GetWeapon_IndexA(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, DWORD Value){ 
DWORD Temp=0;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
Temp=*(PDWORD)((DWORD)(Temp))+Ofs3;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
*(PDWORD)Temp=Value;}}}}
}