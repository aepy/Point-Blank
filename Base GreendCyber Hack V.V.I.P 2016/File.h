
#include "Class.h"
//-------------------------------------------------------------------------------
#define hD3D "i3GfxDx.dll"
DWORD AdressAndByte,GetEngine,Calculate = NULL;
//-------------------------------------------------------------------------------
#define StartRoutine(Function) CreateThread(0,0,(LPTHREAD_START_ROUTINE)Function,0,0,0);
//-------------------------------------------------------------------------------
typedef HRESULT (WINAPI* tEndScene)(LPDIRECT3DDEVICE9 pDevice);
tEndScene oEndScene;
//-------------------------------------------------------------------------------
typedef HRESULT (WINAPI* tDrawIndexedPrimitive)(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount);
tDrawIndexedPrimitive oDrawIndexedPrimitive = NULL;
//-------------------------------------------------------------------------------
LPDIRECT3DTEXTURE9	g_TexTest;
LPD3DXSPRITE		g_pSprite;
D3DVIEWPORT9 Viewport;
D3DVIEWPORT9 g_ViewPort;
LPD3DXLINE pLine    = NULL;
LPDIRECT3DDEVICE9 npDevice; 
LPDIRECT3DDEVICE9 pDevice; 
LPDIRECT3DDEVICE9 pGDevice = NULL;
LPD3DXFONT pFont = NULL;
LPD3DXFONT g_pFont2 = NULL;
LPD3DXFONT fName	= NULL;
LPD3DXFONT fSmall	= NULL;
LPD3DXFONT fTime	= NULL;
LPD3DXFONT Title    = NULL;
DWORD TeamColor;
D3DVECTOR Player;
D3DVECTOR HeadPos;
D3DVECTOR PlayerScaled;
D3DVECTOR HeadScaled;
D3DVECTOR BonePos;
BOOL Create;
int Transperency = 255;
//-------------------------------------------------------------------------------
#define RED				D3DCOLOR_ARGB(255, 245, 000, 000)
#define WHITE			D3DCOLOR_ARGB(255, 255, 255, 255)
#define YELLOW			D3DCOLOR_ARGB(255, 255, 255, 000) 
#define GREEN			D3DCOLOR_ARGB(255, 000, 255, 000)
#define ORANGE			D3DCOLOR_ARGB(255, 255, 125, 000)
#define BLACK			D3DCOLOR_ARGB(150, 000, 000, 000)
#define BLUE			D3DCOLOR_ARGB(255, 19, 84, 199) 
#define DEEPSKYBLUE     D3DCOLOR_ARGB(255, 30, 144, 255) //
#define GREY			D3DCOLOR_ARGB(255, 128, 128, 128) 
#define	 DARKWHITE		      D3DCOLOR_ARGB(255, 135, 135, 135)
#define	 newColor	      D3DCOLOR_ARGB(250,177,30,58)
#define	DARKWHITE2		     D3DCOLOR_ARGB(255, 50, 50,50)
#define BLACK2			D3DCOLOR_ARGB(100, 000, 000, 000)
#define CHOCOLATE2      D3DCOLOR_ARGB(255, 238, 118, 33) //
#define GOLD2			D3DCOLOR_ARGB(255, 238, 201, 0)  //
#define SQUA			D3DCOLOR_ARGB(255, 0, 255, 255)  //
#define DARKGREY        D3DCOLOR_ARGB(255,62,62,62)      //
#define Functions       D3DCOLOR_ARGB(255,26,115,145)//
#define MenuGreen       D3DCOLOR_ARGB(255,43,119,64) //
#define MenuGREY        D3DCOLOR_ARGB(255,30,30,30)  //
#define FUCK_ON			D3DCOLOR_ARGB(255,14,159,47) //
#define FUCK_OFF		D3DCOLOR_ARGB(255,62,120,167)//
#define dWhite	D3DCOLOR_RGBA(255, 255, 255, 255)
#define dRed	D3DCOLOR_RGBA(255, 000, 000, 255)
#define dGreen	D3DCOLOR_RGBA(000, 255, 000, 255)
#define dBlue	D3DCOLOR_RGBA(000, 000, 255, 255)
#define dBlack	D3DCOLOR_RGBA(Transperency, 128, 128, 255)
#define mBLACK			D3DCOLOR_ARGB(100, 000, 000, 205)
#define dPurple	D3DCOLOR_RGBA(125, 000, 255, 255)
#define dGrey	D3DCOLOR_RGBA(128, 128, 128, 255)
#define dLightGrey	D3DCOLOR_RGBA(188, 188, 188, 255)
#define dYellow	D3DCOLOR_RGBA(255, 255, 000, 255)
#define dOrange	D3DCOLOR_RGBA(255, 125, 000, 255)
//-------------------------------------------------------------------------------
D3DXVECTOR3 vStart,vEnd;
D3DXVECTOR3 vvStart,vvEnd;
D3DXVECTOR3 vStart2,vEnd2;
D3DXVECTOR3 vvStart2,vvEnd2;
D3DXVECTOR3 vStart3,vEnd3;
D3DXVECTOR3 vvStart3,vvEnd3;
D3DXVECTOR3 vStart4,vEnd4;
D3DXVECTOR3 vvStart4,vvEnd4;
D3DXVECTOR3 vStart5,vEnd5;
D3DXVECTOR3 vvStart5,vvEnd5;
D3DXVECTOR3 vStart6,vEnd6;
D3DXVECTOR3 vvStart6,vvEnd6;
D3DXVECTOR3 vStart7,vEnd7;
D3DXVECTOR3 vvStart7,vvEnd7;
D3DXVECTOR3 vStart8,vEnd8;
D3DXVECTOR3 vvStart8,vvEnd8;
D3DXVECTOR3 vStart9,vEnd9;
D3DXVECTOR3 vvStart9,vvEnd9;
D3DXVECTOR3 vStart10,vEnd10;
D3DXVECTOR3 vvStart10,vvEnd10;
BYTE Byte [40];
bool bHookedTele = false;
//-------------------------------------------------------------------------------
int GetTeam(int JONES)
{
for(int i = 0; i<=15; i+=2)
if( i == JONES ) return 1;
for(int i = 1; i<=15; i+=2)
if( i == JONES ) return 2;
return 0;
}

//-------------------------------------------------------------------------------
bool GetBattleState() { 
DWORD BaseG = (DWORD)GetModuleHandleA("PointBlank.exe");
unsigned long xBase = *(DWORD*)(BaseG + ResultBaseAmmo); 
if(xBase > NULL){ 
return true; 
}
return false; 
}
//-------------------------------------------------------------------------------
bool IsAlive(int Index)
{
unsigned long dwBase2	= *(DWORD*)ResultBaseHealth2;
CHealth		*Health		= (CHealth*) ((dwBase2 + 0x264) + Index * 0x20);
if(Health->CurHP > 0.1f)
return true;
return false;
}
DWORD MakePTR(BYTE *MemoryTarget, DWORD FunctionTarget)
{
	DWORD dwOldProtect,dwBkup;
	DWORD dwRetn = *(DWORD*)(MemoryTarget);

	VirtualProtect(MemoryTarget, 4, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	*((DWORD *)(MemoryTarget)) = FunctionTarget;
	VirtualProtect(MemoryTarget, 4, dwOldProtect, &dwBkup);
	return dwRetn;
}
//--------------------------------------------------------------------
D3DXVECTOR3 Vector( int Index )
{
	DWORD ADR_PLAYER = *(DWORD*)(ResultBasePlayer2);
	DWORD OldProtect;
	DWORD pCalculate = *(DWORD*)(ADR_PLAYER + 4 * Index + ResultPlayer );
	VirtualProtect ( (LPVOID)(pCalculate), sizeof (pCalculate), PAGE_EXECUTE_READWRITE, &OldProtect );
	CPlayers	*Players	= (CPlayers*)(pCalculate + 0x64 );
	VirtualProtect ( (LPVOID)(pCalculate), sizeof (pCalculate), OldProtect, &OldProtect );
	return Players->pos;
}
//--------------------------------------------------------------------
float Distance( D3DXVECTOR3 VecA, D3DXVECTOR3 VecB )
{
        return sqrt( ( ( VecA.x - VecB.x ) * ( VecA.x - VecB.x ) ) +
                 ( ( VecA.y - VecB.y ) * ( VecA.y - VecB.y ) ) +
                 ( ( VecA.z - VecB.z ) * ( VecA.z - VecB.z ) ) );
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
int MyCharaIndex()
{
	unsigned long dwBase	= *(DWORD*)(ResultBasePlayer2);
	CTeam *MyTeam = (CTeam*) ((dwBase + ResultTeam));
	return MyTeam->iTeam;
}
int TargetPlayer(DWORD PlayerTarget)
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
bool UserBone( D3DXVECTOR3 &Out, int Idx, int BoneIdx )
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

int AutomaticTarget()
{
	int Result = -1;
	float NearDistance = 1000.0f;
	int MyTeam = GetTeam(MyCharaIndex());
	if(!IsAlive(MyCharaIndex()))return Result;
	for(int i = 0; i<=16; i++)
	{
		int TargetTeam = GetTeam(i);
		if(TargetTeam == MyTeam)continue;
		if(TargetTeam == 0)continue;
		if ( IsAlive(i) )
		{
			D3DXVECTOR3 Head;
			if ( MyCharaIndex( ) %2 != i % 2 && UserBone( Head, i, 7.7 ) )
			{
				if(Distance(Vector(MyCharaIndex()),Vector(i)) < NearDistance)
				{
					NearDistance = Distance(Vector(MyCharaIndex()),Vector(i));
					Result = i;
				}
			}
		}
	}
	return Result;
}

DWORD GetPlayer(int MyIdx)
{
	DWORD BasePlayer_B = *(DWORD*)(ResultBaseHealth2);
	if(IsBadReadPtr((void*)BasePlayer_B,4))return 0;
	DWORD PlayerIndexA = *(DWORD*)(BasePlayer_B + 0x14 + (MyIdx * 4));
	if(IsBadReadPtr((void*)PlayerIndexA,4))return 0;
	DWORD PlayerIndexB = *(DWORD*)(PlayerIndexA + PTR_Target);
	if(IsBadReadPtr((void*)PlayerIndexB,4))return 0;
	DWORD IsTargetingEnemy = *(DWORD*)(PlayerIndexB + ResultPTRTarget);
	if(IsBadReadPtr((void*)IsTargetingEnemy,4))return 0;
	return IsTargetingEnemy;
}

//-------------------------------------------------------------------------------
int GetMyCharaIndex()
{
	unsigned long dwBase	= *(DWORD*)(ResultBasePlayer2);
	CTeam *MyTeam = (CTeam*) ((dwBase + ResultTeam));
	return MyTeam->iTeam;
}
//-------------------------------------------------------------------------------
bool GetUserBone( D3DXVECTOR3 &Out,  int BoneIdx ,int Idx){
DWORD dwGameBase = *(DWORD*)ResultBaseHealth2;
if ( dwGameBase ){
CGameBase* GameBase = (CGameBase*)( *(DWORD*)(dwGameBase + 0x14 + ( 0x4 * Idx ) ) );
if ( GameBase && GameBase->Bones){
Out.x = GameBase->Bones->BoneData[ BoneIdx ].BoneMatrix._41;
Out.y = GameBase->Bones->BoneData[ BoneIdx ].BoneMatrix._42;
Out.z = GameBase->Bones->BoneData[ BoneIdx ].BoneMatrix._43;
return true;
}}
return false;
}
//-------------------------------------------------------------------------------
bool YoWorlToScreenGa(LPDIRECT3DDEVICE9 pDevice, D3DVECTOR Player,D3DVECTOR &PlayerScaled){
   D3DXVECTOR3 PlayerPos(Player.x,Player.y,Player.z);
	D3DXMATRIX identity;
    D3DXVECTOR3 vScreen;
	pDevice->GetViewport(&Viewport);
	Viewport.X = Viewport.Y = 0;
    Viewport.MinZ     = 0;
    Viewport.MaxZ     = 1;
	D3DXVec3Project(&vScreen, &PlayerPos, &Viewport, &pRC->pRenderData->ProjMatrix, &pRC->pRenderData->ViewMatrix, &pRC->pRenderData->World);
 if (vScreen.z < 1.0f && vScreen.x > 0.0f && vScreen.y > 0.0f && vScreen.x < Viewport.Width && vScreen.y < Viewport.Height){
     PlayerScaled.x = vScreen.x;
     PlayerScaled.y = vScreen.y ;
     PlayerScaled.z = vScreen.z;
 return true; 
}return false;
}
//-------------------------------------------------------------------------------
void PrivateOnly(void *adr, void *ptr, int size){ 
DWORD NextProtection;
VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &NextProtection);
Sleep(1);
Sleep(1);
RtlCopyMemory(adr,ptr,size);
Sleep(1);
Sleep(1);
VirtualProtect(adr,size,NextProtection, &NextProtection);
}
//--------------------------------------------------------------------
void PacthWeapone(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, DWORD Value){ 
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
//--------------------------------------------------------------------
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
//-------------------------------------------------------------------------------
void WeaponHack2(DWORD B,DWORD A1,DWORD B1, DWORD ISI)
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
BYTE wepon,piso,pistol,bom,asep,dual;
void GoWeaponHack(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, BYTE Value)
{ 
DWORD Temp=0;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
Temp=*(PDWORD)((DWORD)(Temp))+Ofs3;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
*(PBYTE)Temp=Value;
}
}
}
}
}
DWORD TestPacth(DWORD dwPtr,DWORD A1,DWORD B1,DWORD C1){
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
//--------------------------------------------------------------------
void PacthWeapon(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, DWORD Value){ 
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
void _patchPTR(unsigned long adr, unsigned long Ofset, DWORD dwValue)
{ DWORD A=0;
 if (IsBadReadPtr((PDWORD)adr,4)==0)
{ A=*(PDWORD)((DWORD)(adr))+Ofset;
if (IsBadReadPtr((PDWORD)A,4)==0)
{*(PDWORD)A=dwValue;
}
}
} 
//-------------------------------------------------------------------------------
void WritePTR(DWORD Base,DWORD PTR1,DWORD PTR2,DWORD PTR3,DWORD Byte){
DWORD Temp =0;
if (!IsBadReadPtr((PDWORD)Base,4)){Temp=*(PDWORD)((DWORD)(Base))+PTR1;
if (!IsBadReadPtr((PDWORD)Temp,4)){Temp=*(PDWORD)((DWORD)(Temp))+PTR2;
if (!IsBadReadPtr((PDWORD)Temp,4)){Temp=*(PDWORD)((DWORD)(Temp))+PTR3;
if (!IsBadReadPtr((PDWORD)Temp,4)){*(PDWORD)Temp=Byte;}}}
}
}
DWORD RecordPTR(DWORD Base,DWORD PTR1,DWORD PTR2,DWORD PTR3){ 
DWORD RPTR1,RPTR2,RPTR3;
if (!IsBadReadPtr((PDWORD)Base,4)){RPTR1=*(PDWORD)((DWORD)(Base))+PTR1;
if (!IsBadReadPtr((PDWORD)RPTR1,4)){RPTR2=*(PDWORD)((DWORD)(RPTR1))+PTR2;
if (!IsBadReadPtr((PDWORD)RPTR2,4)){RPTR3=*(PDWORD)((DWORD)(RPTR2))+PTR3;
if (!IsBadReadPtr((PDWORD)RPTR3,4)){
	return *(PDWORD)RPTR3;}}}}
return RPTR3;}
int WritePtr (unsigned long ads, unsigned long ptr, int value)
{
	__try
	{
		unsigned long WrtPointer = false;
		WrtPointer = *(unsigned long*)((ads))+ptr;
		*(int*)(WrtPointer) = value;
		return true;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return false;
	}
}
DWORD addworx1;
void ChangesVirtualProtect(void* address, char bytes)
{

	VirtualProtect(address, bytes, PAGE_EXECUTE_READWRITE, &addworx1);
}

/*-------------------------------------------------------------------------------------------------------------------*/
void RestoreVirtualProtect(void* address, char bytes)
{
	VirtualProtect(address,bytes,addworx1,&addworx1);
}

char Mem_ASM(void* address, void* val, char bytes)
{
	ChangesVirtualProtect(address, bytes);
	memcpy(address, val, bytes);
	RestoreVirtualProtect(address, bytes);
	return(0);
}
void MemWrite(void *adr, void *byte, int size)
{
	DWORD X;
    VirtualProtect(adr, size, PAGE_EXECUTE_READWRITE, &X);
	memcpy(adr, byte, size);   
    VirtualProtect(adr,size,X,&X);
}
VOID JMPE9(BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen)
{
    DWORD dwOldProtect, dwBkup, dwRelAddr;
    VirtualProtect(pAddress, dwLen, PAGE_EXECUTE_READWRITE, &dwOldProtect);
    dwRelAddr = (DWORD) (dwJumpTo - (DWORD) pAddress) - 5;
    *pAddress = 0xE9;
    *((DWORD *)(pAddress + 0x1)) = dwRelAddr;
    for(DWORD x = 0x5; x < dwLen; x++) *(pAddress + x) = 0x90;
    VirtualProtect(pAddress, dwLen, dwOldProtect, &dwBkup);
    return;
}
//-------------------------------------------------------------------------------
int WritePointer2 (unsigned long ads, unsigned long ptr, unsigned long ptr2,int value){
__try{
unsigned long WrtPointer = false;
WrtPointer = *(unsigned long*)((ads))+ptr;
WrtPointer = *(unsigned long*)((WrtPointer))+ptr2;
*(int*)(WrtPointer) = value;
return true;
}
__except (EXCEPTION_EXECUTE_HANDLER){
return false;
}
}
//-------------------------------------------------------------------------------
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
void PachtChara(DWORD B,DWORD A1,DWORD B1, DWORD ISI){
		DWORD A=0;
		if (IsBadReadPtr((PDWORD)B,4)==0){
		A=*(PDWORD)((DWORD)(B))+A1;
		if (IsBadReadPtr((PDWORD )A,4)==0){
		A=*(PDWORD)((DWORD)(A ))+ B1;
		if (IsBadReadPtr((PDWORD)A,4)==0) {
		{*(PDWORD)A=ISI;}}}}}
//-------------------------------------------------------------------------------
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
bool MakePoint(unsigned long ADRexec, int OFSexec, int PTRexec){
if (!IsBadReadPtr((void*)ADRexec, sizeof(unsigned long))){
if (!IsBadReadPtr((void*)(*(unsigned long*)ADRexec + OFSexec), sizeof(unsigned long))){
*(int*)(*(unsigned long*)ADRexec + OFSexec) = PTRexec;
}
}
return 0;
}
DWORD Read(DWORD dwPtr, DWORD dwOfs){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return *(PDWORD)C; 
}
}
return C;
}
void Crosshair(LPDIRECT3DDEVICE9 pDevice, D3DCOLOR Color)
{
		int size = 8, strong = 1;

		int iCenterX = GetSystemMetrics( 0 ) / 2;
		int iCenterY = GetSystemMetrics( 1 ) / 2;

		if( iCenterX < 20 && iCenterY < 20 )
		{
			iCenterX = ( GetSystemMetrics( 0 ) / 2 );
			iCenterY = ( GetSystemMetrics( 1 ) / 2 );
		}

		D3DRECT rec_a = { iCenterX - size, iCenterY, iCenterX + size, iCenterY + strong};
		D3DRECT rec_b = { iCenterX, iCenterY - size, iCenterX + strong,iCenterY + size};
		pDevice->Clear(1, &rec_a, D3DCLEAR_TARGET, Color, 0,  0);
		pDevice->Clear(1, &rec_b, D3DCLEAR_TARGET, Color, 0,  0);
}
void DrawLine(long Xa, long Ya, long Xb, long Yb, DWORD dwWidth, D3DCOLOR Color){
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
bool GetBonePos(CGameCharaBase*m_CharaBase,D3DXVECTOR3 &outpos,int BoneIndex){
outpos.x = m_CharaBase->m_BoneContext->m_Bone[BoneIndex].m_Bone._41;
outpos.y = m_CharaBase->m_BoneContext->m_Bone[BoneIndex].m_Bone._42;
outpos.z = m_CharaBase->m_BoneContext->m_Bone[BoneIndex].m_Bone._43;
return true;
}
//--------------------------------------------------------------------
void DrawBone(CGameCharaBase* m_CharaBase,int Start,int End,DWORD Color,LPDIRECT3DDEVICE9 pDevice){
D3DXVECTOR3 vStartBone,vEndBone;
D3DXVECTOR3 vvStartBone,vvEndBone;
if(GetBonePos(m_CharaBase,vStartBone,Start)){
if(GetBonePos(m_CharaBase,vEndBone,End)){
if(YoWorlToScreenGa(pDevice,vStartBone,vvStartBone)){
if(YoWorlToScreenGa(pDevice,vEndBone,vvEndBone)){
DrawLine(vvStartBone.x,vvStartBone.y,vvEndBone.x,vvEndBone.y,1,Color);
}
}
}
}
}
//--------------------------------------------------------------------
void DrawSkeleton(CGameCharaBase* m_CharaBase,DWORD Color,LPDIRECT3DDEVICE9 pDevice){
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
//-------------------------------------------------------------------------------
int				RainbowR		= 100;
int				RainbowG		= 100;
int				RainbowB		= 100;
float			RainbowTexts	= 100;
#define			RainbowTextTest D3DCOLOR_ARGB(255, RainbowR, RainbowG, RainbowB)
//-------------------------------------------------------------------------------
void RainBow(){
						if(RainbowTexts!=100)
						{RainbowR-=2,RainbowG-=3,RainbowB-=3;}
						if(RainbowTexts!=255)
						{RainbowR+=2,RainbowG+=3,RainbowB+=4;}
	}
//-------------------------------------------------------------------------------