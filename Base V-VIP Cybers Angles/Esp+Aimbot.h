//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
bool AimEnable    = false;
bool BulletEnable = false;
float DeltaX   = 0;    
float DeltaY   = 0;     
float fX,fY,fZ = 0;     
int AimSlot = 0;
DWORD d = 0;
DWORD GetDeltaX     = 0;  
DWORD GetDeltaY     = 0; 
DWORD BackupEDXTele = 0;
DWORD TeamColor;
D3DVECTOR Player;
D3DVECTOR HeadPos;
D3DVECTOR PlayerScaled;
D3DVECTOR HeadScaled;
D3DVECTOR BonePos;
D3DVECTOR ScreenPos;
//=========================================================================//
LPTSTR PointBlanki3Gfx = "i3GfxDx.dll";
LPTSTR PointBlankSTR2 = "PointBlank.exe";
//=========================================================================//
bool WorldToScreenA(D3DXVECTOR3 inpos, D3DXVECTOR3 &outpos, LPDIRECT3DDEVICE9 pDevice)
{
DWORD dwRenderData = (DWORD)GetModuleHandleA(PointBlanki3Gfx) + g_Render;
RenderContext* GfxDx = (RenderContext*)(dwRenderData);

D3DXMATRIX identity;
D3DXVECTOR3 vScreen;

D3DVIEWPORT9 g_ViewPort;
pDevice->GetViewport(&g_ViewPort);
g_ViewPort.X = g_ViewPort.Y = 0;
g_ViewPort.MinZ = 0;
g_ViewPort.MaxZ = 1;
D3DXVec3Project(&vScreen, &inpos, &g_ViewPort,
&GfxDx->pRenderData->ProjMatrix,
&GfxDx->pRenderData->ViewMatrix,
&GfxDx->pRenderData->World);

if (vScreen.z < 1.0f && vScreen.x > 0.0f && vScreen.y > 0.0f && vScreen.x < g_ViewPort.Width && vScreen.y < g_ViewPort.Height)
{
outpos.x = vScreen.x;
outpos.y = vScreen.y;
outpos.z = vScreen.z;
AimEnable=false;
return true;
}
AimEnable=true;
return false;
}

//=========================================================================//
DWORD MakePTR(BYTE *MemoryTarget, DWORD FunctionTarget)
{
DWORD dwOldProtect,dwBkup;
DWORD dwRetn = *(DWORD*)(MemoryTarget);

VirtualProtect(MemoryTarget, 4, PAGE_EXECUTE_READWRITE, &dwOldProtect);
*((DWORD *)(MemoryTarget)) = FunctionTarget;
VirtualProtect(MemoryTarget, 4, dwOldProtect, &dwBkup);
return dwRetn;
}
//=========================================================================//
int GetMyCharaIndex()
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR2);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + OFS_Player);
unsigned long dwBase2	= *(DWORD*)(dwI3EXEC + OFS_Player-0x34);
CTeam *MyTeam = (CTeam*) ((dwBase + OFS_TEAM));
return MyTeam->iTeam;
}

//=========================================================================//

bool GetUserBone( D3DXVECTOR3 &Out, int Idx, int BoneIdx )
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR2);
unsigned long dwGameBase = *(DWORD*)(dwI3EXEC + OFS_Health);
if ( dwGameBase )
{
CGameCharaBase* GameBase = (CGameCharaBase*)( *(DWORD*)(dwGameBase + 0x14 + ( 0x4 * Idx ) ) );
if ( GameBase && GameBase->m_BoneContext )
{
Out.x = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._41;
Out.y = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._42;
Out.z = GameBase->m_BoneContext->m_Bone[ BoneIdx ].m_Bone._43;
return true;
}}
return false;
}
//=========================================================================//
D3DXVECTOR3 GetUserBonePos2(int Idx ,int BoneIdx)
{
D3DXVECTOR3 Out;
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR2);
unsigned long dwGameBase = *(DWORD*)(dwI3EXEC + OFS_Health);
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
//=========================================================================//

float CalcDistance( D3DXVECTOR3 VecA, D3DXVECTOR3 VecB )
{
return sqrt( ( ( VecA.x - VecB.x ) * ( VecA.x - VecB.x ) ) +
( ( VecA.y - VecB.y ) * ( VecA.y - VecB.y ) ) +
( ( VecA.z - VecB.z ) * ( VecA.z - VecB.z ) ) );
}

//=========================================================================//

bool IsAlive(int Index)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR2);
unsigned long dwBase2	= *(DWORD*)(dwI3EXEC + OFS_Health);
CHealth		*Health		= (CHealth*) ((dwBase2 + OFS_HEALTH) + Index * 0x20);
if(Health->CurHP > 0.1f)
return true;
return false;
}

//=========================================================================//

D3DXVECTOR3 GetUserVector( int Index )
{
DWORD ADR_PLAYER = *(DWORD*)(OFS_Player2);
DWORD OldProtect;
DWORD pCalculate = *(DWORD*)(ADR_PLAYER + 4 * Index + OFS_PLAYER );
VirtualProtect ( (LPVOID)(pCalculate), sizeof (pCalculate), PAGE_EXECUTE_READWRITE, &OldProtect );
CPlayers	*Players	= (CPlayers*)(pCalculate + 0x64 );
VirtualProtect ( (LPVOID)(pCalculate), sizeof (pCalculate), OldProtect, &OldProtect );
return Players->pos;
}

//=========================================================================//

int AutomaticTarget_World()
{
int Result = -1;
float NearDistance = 1000.0f;
int MyTeam = DxESP->GetTeam(GetMyCharaIndex());
if(!IsAlive(GetMyCharaIndex()))return Result;
for(int i = 0; i<=16; i++)
{
int TargetTeam = DxESP->GetTeam(i);
if(TargetTeam == MyTeam)continue;
if(TargetTeam == 0)continue;
if ( IsAlive(i) )
{
D3DXVECTOR3 Head;
if ( GetMyCharaIndex( ) %2 != i % 2 && GetUserBone( Head, i, 7.7 ) )
{
if(CalcDistance(GetUserVector(GetMyCharaIndex()),GetUserVector(i)) < NearDistance)
{
NearDistance = CalcDistance(GetUserVector(GetMyCharaIndex()),GetUserVector(i));
Result = i;
}
}
}
}
return Result;
}

//====================== GET ASM MOUSE DELTA X & Y =====================//
float MouseDeltaX, MouseDeltaY, MouseDeltaZ = 0;
bool AimStart = false;
__declspec(naked)void Aim_DeltaX()
{
_asm
{
cmp AimHead,1
je StartAim
NORMAL:
fld dword ptr [ecx+0x20]
ret
StartAim:
cmp AimEnable,0
je NORMAL
fld dword ptr[MouseDeltaX]
ret 
}
}

__declspec(naked)void Aim_DeltaY()
{
_asm
{
cmp AimHead,1
je StartAim
NORMAL:
fld dword ptr [ecx+0x28]
ret
StartAim:
cmp AimEnable,0
je NORMAL
fld dword ptr[MouseDeltaY]
ret 
}
}

_declspec(naked)void MyDeltaX()
{
_asm{
cmp [AimEnable],1
jne Normal
fld dword ptr [MouseDeltaX]
jmp Return
Normal:
fld dword ptr [ecx + 0x20]
Return:
ret
}
}

_declspec(naked)void MyDeltaY()
{
_asm{
cmp [AimEnable],1
jne Normal
fld dword ptr [MouseDeltaY]
jmp Return
Normal:
fld dword ptr [ecx + 0x28]
Return:
ret
}
}

//=========================================================================//
#define MSDeltaX  0x600944 // i3InputMouse::GetDeltaX
#define MSDeltaY  0x600948 // i3InputMouse::GetDeltaY
//====================== AIMLOCK MODE =====================//
DWORD OFS_MouseX = (DWORD)GetModuleHandleA(PointBlankSTR2) + MSDeltaX;
DWORD OFS_MouseY = (DWORD)GetModuleHandleA(PointBlankSTR2) + MSDeltaY;
//====================== CALL AIMBOT =====================//
void Thread_Aimbot()
{
MakePTR((PBYTE)OFS_MouseX,(DWORD)Aim_DeltaX);
MakePTR((PBYTE)OFS_MouseY,(DWORD)Aim_DeltaY);
}
//=========================================================================//
void DoAimbot(LPDIRECT3DDEVICE9 pDevice)
{
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA(PointBlankSTR2);
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + OFS_Player);
int ScreenCenterX = (g_ViewPort.Width /2.0f);
int ScreenCenterY = (g_ViewPort.Height /2.0f);
if(GetBattleState1()){
if(AimHead)
{
//====================== GET SCREEN AIMLOCK MODE =====================//
int AimSlot = AutomaticTarget_World(); //get priority target, player that alive, nearest, and visible

if(AimSlot != -1)
{
D3DXVECTOR3 OnWorld,OnScreen;
int BoneIndexSelector = 0;
switch(AimBody)
{
case 0:
BoneIndexSelector = 7.7; // Kepala
break;
case 1:
BoneIndexSelector = 5; // Badan
break;
case 2:
BoneIndexSelector = 2; // Perut
break;
case 3:
BoneIndexSelector = 0; // Vital
break;
case 4:
BoneIndexSelector = 12; // Pinggang Kiri
break;
case 5:
BoneIndexSelector = 13; // Pinggang Kanan
break;
case 6:
BoneIndexSelector = 14; // Lutut Kiri
break;
case 7:
BoneIndexSelector = 15; // Lutut Kanan
break;
case 8:
BoneIndexSelector = 8; // Kaki Kiri
break;
case 9:
BoneIndexSelector = 9; // Kaki Kanan
break;
case 10:
BoneIndexSelector = 10; // Tangan Kiri
break;
case 11:
BoneIndexSelector = 11; // Tangan Kanan
break;
}
if(GetUserBone(OnWorld,AimSlot,BoneIndexSelector)){
if(WorldToScreenA(OnWorld,OnScreen,pDevice))// World To Screen
{
int x = ( GetSystemMetrics( 0 ) / 2);
int y = ( GetSystemMetrics( 1 ) / 2);
DxESP->FillRGB(OnScreen.x-10, OnScreen.y, 7, 1,SKYBLUE,pDevice);//Left line
DxESP->FillRGB(OnScreen.x+4, OnScreen.y, 7, 1,SKYBLUE,pDevice);//Right line
DxESP->FillRGB(OnScreen.x, OnScreen.y-10, 1, 7,SKYBLUE,pDevice);//Top line
DxESP->FillRGB(OnScreen.x, OnScreen.y+4, 1, 7,SKYBLUE,pDevice);//Bottom line
DxESP->DrawPoint(OnScreen.x,OnScreen.y,2,2,dRed,pDevice);//Point
AimEnable = true; // Enable the aimlock
int LocalX = OnScreen.x; //Define that player on screen
int LocalY = OnScreen.y;
int LocalZMax = OnScreen.z;
int LocalZMin = OnScreen.z;
if(LocalX == ScreenCenterX && LocalY == ScreenCenterY) // if the screen center is player target
{ 
MouseDeltaX = 0; // make mouse delta is NULL
MouseDeltaY = 0;
}
else
{   // if not then
MouseDeltaX = LocalX - ScreenCenterX; // Mouse delta X is LocalX - ScreenCenterX
MouseDeltaY = LocalY - ScreenCenterY;
}
}
else
{
AimEnable = false;//Disable the aimlock
}
}
else
{
AimEnable = false;//Disable the aimlock
}
}
else
{
AimEnable = false;//Disable the aimlock
}
}
else
{
AimEnable = false;//Disable the aimlock
}
}}
//====================== GET ASM I3COLLIDEELINE =====================//
_declspec(naked)void i3CollideeLine_SetEnd()
{
_asm{

cmp [BulletEnable],0
je Skip
mov eax,dword ptr ss:[esp+0x4]
mov [BackupEDXTele],edx
mov edx,[fX]
mov [eax+0],edx
mov edx,[fY]
mov [eax+4],edx
mov edx,[fZ]
mov [eax+8],edx
mov edx,[BackupEDXTele]
Skip:
mov eax,dword ptr ss:[esp+0x4]
fld dword ptr ds:[eax]
fstp dword ptr ds:[ecx+0x18]
fld dword ptr ds:[eax+0x4]
fstp dword ptr ds:[ecx+0x1C]
fld dword ptr ds:[eax+0x8]
fstp dword ptr ds:[ecx+0x20]
fld dword ptr ds:[ecx+0x18]
fsub dword ptr ds:[ecx+0x0C]
fstp dword ptr ds:[ecx+0x24]
fld dword ptr ds:[ecx+0x1C]
fsub dword ptr ds:[ecx+0x10]
fstp dword ptr ds:[ecx+0x28]
fld dword ptr ds:[ecx+0x20]
fsub dword ptr ds:[ecx+0x14]
fstp dword ptr ds:[ecx+0x2C]
retn 0x4                             


}
}

//=========================================================================//
#define IATOFS_SetEnd	0x600EC0 // i3CollideeLine::SetEnd
//=========================================================================//
bool bHookedTele = false;
void HookTelekill()
{
if(bHookedTele)return;
DWORD OFS_Telekill 	= (DWORD)GetModuleHandleA(PointBlankSTR2) + IATOFS_SetEnd;
MakePTR((PBYTE)OFS_Telekill,(DWORD)i3CollideeLine_SetEnd);
bHookedTele = true;
}

//====================== Bullet Mode  =====================//

void DoAimBullet(LPDIRECT3DDEVICE9 pDevice){
if(GetBattleState1()){
if(Accuracy==1)
{
int AimSlot = AutomaticTarget_World();
if(AimSlot != -1)
{
D3DXVECTOR3 OnWorld,OnScreen;
int BoneIndexSelector = 0;
switch(AimBody)
{
case 0:
BoneIndexSelector = 7.7; // Kepala
break;
case 1:
BoneIndexSelector = 5; // Badan
break;
case 2:
BoneIndexSelector = 2; // Perut
break;
case 3:
BoneIndexSelector = 0; // Vital
break;
case 4:
BoneIndexSelector = 12; // Pinggang Kiri
break;
case 5:
BoneIndexSelector = 13; // Pinggang Kanan
break;
case 6:
BoneIndexSelector = 14; // Lutut Kiri
break;
case 7:
BoneIndexSelector = 15; // Lutut Kanan
break;
case 8:
BoneIndexSelector = 8; // Kaki Kiri
break;
case 9:
BoneIndexSelector = 9; // Kaki Kanan
break;
case 10:
BoneIndexSelector = 10; // Tangan Kiri
break;
case 11:
BoneIndexSelector = 11; // Tangan Kanan
break;
}
if(GetUserBone(OnWorld,AimSlot,BoneIndexSelector)){
BulletEnable = true;
fX = OnWorld.x;
fY = OnWorld.y + 0.1f;
fZ = OnWorld.z;

//====================== Screen Automatic Mode  =====================//

if(DxESP->ADDXW2S(pDevice,OnWorld,OnScreen))
{
int x = ( GetSystemMetrics( 0 ) / 2);
int y = ( GetSystemMetrics( 1 ) / 2);
DxESP->FillRGB(OnScreen.x-10, OnScreen.y, 7, 1,SKYBLUE,pDevice);//Left line
DxESP->FillRGB(OnScreen.x+4, OnScreen.y, 7, 1,SKYBLUE,pDevice);//Right line
DxESP->FillRGB(OnScreen.x, OnScreen.y-10, 1, 7,SKYBLUE,pDevice);//Top line
DxESP->FillRGB(OnScreen.x, OnScreen.y+4, 1, 7,SKYBLUE,pDevice);//Bottom line
DxESP->DrawPoint(OnScreen.x,OnScreen.y,2,2,dRed,pDevice);//Point
}
}

//=========================================================================//

else
{
BulletEnable = false;
}
}
else
{
BulletEnable = false;
}
}
if(Accuracy == 0 && !Accuracy)
{
BulletEnable = false;
}
}}

#include "WPSmoke.h"
#include "WPSmokeBM.h"
#include "BulletKiller.h"
#include "PistolKiller.h"
#include "GranadeKiller.h"
#include "SpesialReplace.h"
//====================== ESP Bone Mode  =====================//

void BoneESP(LPDIRECT3DDEVICE9 pDevice)
{
	DWORD dwI3EXEC			= (DWORD)GetModuleHandleA(PointBlankSTR2);
	unsigned long dwBase	= *(DWORD*)(dwI3EXEC + OFS_Player);
	unsigned long A_CGameCharaManager = *(DWORD*)(dwI3EXEC + OFS_Health);//ResultBaseHealth
	CTeam		*pTeam		= ((CTeam*)(dwBase + OFS_TEAM));
	CGameCharaBase* m_CharaBase = NULL;
	int MyTeam = DxESP->GetTeam(pTeam->iTeam);
	for (int i = 0; i<=0x16;i++)
{
	if(A_CGameCharaManager !=0){
	
	m_CharaBase = (CGameCharaBase*)((*(DWORD*)(A_CGameCharaManager + 0x14 + 0x4*i)));
	
	int iTeam = DxESP->GetTeam(i);
	if (iTeam == MyTeam)continue;
			
	if (iTeam == 1){ TeamColor = dBlue; } 
	else if (iTeam == 2){ TeamColor = dRed; }
	else{ continue; }

	if(m_CharaBase!=0)
	if(m_CharaBase->m_BoneContext!=0){
	if(GetBattleState1()){
	if(ESPBone==1){
	DrawSkeleton(m_CharaBase, dWhite, pDevice);
	}}}}}}

//=========================================================================//

bool ADDXW2S(LPDIRECT3DDEVICE9 pDevice, D3DVECTOR Player,D3DVECTOR &PlayerScaled)
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

//====================== Visual Mode ESP  =====================//

void ADDXESP(LPDIRECT3DDEVICE9 pDevice)
{
DWORD dwI3EXEC			= (DWORD)GetModuleHandleA(PointBlankSTR2);
	unsigned long dwBase	= *(DWORD*)(dwI3EXEC + OFS_Player);
	unsigned long dwBase2	= *(DWORD*)(dwI3EXEC + OFS_Player-0x34);	
	CTeam		*pTeam		= ((CTeam*)(dwBase + OFS_TEAM));

	CPlayers *pNearEnt		= NULL;
	float NearTargetX = 0.0f;
	float NearTargetY = 0.0f;
	float DisX = 0.0f;
	float DisY = 0.0f;
	CNames		*pTarget	= NULL;
	CHealth		*iTarget	= NULL;
	char *dis		= new char[33];
	char *hp		= new char[33];
	char *bone		= new char[33];
	char *state		= new char[33];

	float ScreenCenterX = (Viewport.Width /2.0f);
	float ScreenCenterY = (Viewport.Height /2.0f);
	float ScreenBottomY = (Viewport.Height);

	int MyTeam = DxESP->GetTeam(pTeam->iTeam);
	if(*(PBYTE)OFS_Ammo2 > 1.){
	for (int i = 0; i<=0x16;i++)
	{
		if (dwBase !=0)
		{
			CNames		*pNames		= (CNames*)((dwBase + OFS_NAMES) + i * NAMESIZE);
			CRank		*pRank		= (CRank*)((dwBase + OFS_RANK) + i * RANKSIZE);
			CRank		*pRespawn	= (CRank*)((dwBase + OFS_RANK+0x1) + pTeam->iTeam * RANKSIZE);
			CHealth		*pHealth	= (CHealth*)((dwBase2 + OFS_HEALTH) + i * HPSIZE);
			CHealth		*mHealth	= (CHealth*)((dwBase2 + OFS_HEALTH) + pTeam->iTeam * HPSIZE);
			DWORD ADR_PLAYER		= *(DWORD*)(OFS_Player2);
			DWORD OldProtect;
			DWORD pCalculate		= *(DWORD*)(ADR_PLAYER + 0x4 * i + OFS_PLAYER );
			DWORD pCalculate2		= *(DWORD*)(ADR_PLAYER + 0x4 * pTeam->iTeam + OFS_PLAYER );
			VirtualProtect ( (LPVOID)(pCalculate), sizeof (pCalculate), PAGE_EXECUTE_READWRITE, &OldProtect );
			VirtualProtect ( (LPVOID)(pCalculate2), sizeof (pCalculate2), PAGE_EXECUTE_READWRITE, &OldProtect );
			CPlayers	*pPlayer	= (CPlayers*)(pCalculate + 0x64 );
			CPlayers	*pLocal		= (CPlayers*)(pCalculate2 + 0x64 );
			VirtualProtect ( (LPVOID)(pCalculate), sizeof (pCalculate), OldProtect, &OldProtect );
			VirtualProtect ( (LPVOID)(pCalculate2), sizeof (pCalculate2), OldProtect, &OldProtect );
			Player.x				=  pPlayer->pos.x;
			Player.y				=  pPlayer->pos.y;
			Player.z				=  pPlayer->pos.z;

			HeadPos.x				=	pPlayer->pos.x;
			HeadPos.y				=	1.6f + pPlayer->pos.y;
			HeadPos.z				=	pPlayer->pos.z;
			
			D3DXVECTOR3 MyDistance	=	pLocal->pos - pPlayer->pos;
			float MyaDistance = D3DXVec3Length(&MyDistance );
			
			float Nearest = (float) INT_MAX;
			float PosX = 0.0f;
			float PosY = 0.0f;

			int iTeam				= DxESP->GetTeam(i);
			if (iTeam == MyTeam)continue;

			if (iTeam == 1){ TeamColor = dBlue; } 
			else if (iTeam == 2){ TeamColor = dRed; }
			else{ continue; }

//====================== Esp Bone & Line  =====================//

if (DxESP->ADDXW2S(pDevice,Player,PlayerScaled))
{
if (pHealth->CurHP > 1) 
{
if(GetBattleState1()){
if(ESPBox)
{
DxESP->DrawBoxESP((float)PlayerScaled.x-(5000/MyaDistance)/30,(float)PlayerScaled.y-(35000/MyaDistance)/45, 50000/MyaDistance/6*2/40,50000/MyaDistance/3*2/40, TeamColor, pDevice);
}
}
}
D3DXVECTOR3 OnWorld,OnScreen;
if(GetUserBone(OnWorld,i,0)){
if (DxESP->ADDXW2S(pDevice,OnWorld,OnScreen))
{
if (pHealth->CurHP > 1) 
{
if(GetBattleState1()){
if (ESPLine)
{
DxESP->DrawLine((float)ScreenCenterX,(float)ScreenBottomY,(float)OnScreen.x,(float)OnScreen.y,1,dRed);
}}}}

if(GetUserBone(OnWorld,i,7)){
if (DxESP->ADDXW2S(pDevice,OnWorld,OnScreen))
{
if (pHealth->CurHP > 1) 
{

//====================== Esp Name  =====================//

if(GetBattleState1()){
if(ESPName)
{
DxESP->DrawString((float)OnScreen.x-50	,(float)OnScreen.y-35	,TeamColor,	"%s",pNames->szNames);
DxESP->DrawString((float)OnScreen.x-50	,(float)OnScreen.y-35	,BLACK,	"%s",pNames->szNames);
DxESP->DrawString((float)OnScreen.x-50	,(float)OnScreen.y-35	,BLACK,	"%s",pNames->szNames);
}

//====================== Esp Distance  =====================//

if(GetBattleState1()){
if (ESPDistance){
sprintf(dis,"[Dist: %0.0f M]",(DxESP->FindDistance(pLocal->pos,pPlayer->pos,pPlayer,pLocal))/4);
DxESP->PrintText(dis,(float)PlayerScaled.x-25,(float)PlayerScaled.y+8,dBlue,fName);
DxESP->PrintText(dis,(float)PlayerScaled.x-25,(float)PlayerScaled.y+8,BLACK,fName);
DxESP->PrintText(dis,(float)PlayerScaled.x-25,(float)PlayerScaled.y+8,BLACK,fName);
}

//====================== Esp Health  =====================//

if(GetBattleState1()){
if (ESPHealth){
DxESP->Healthbarnew(pDevice,(float)PlayerScaled.x-25,(float)PlayerScaled.y+5,pHealth->CurHP);
}

//====================== Esp Head  =====================//

if(GetBattleState1()){
if (ESPHead){
DxESP->FillRGB((float)OnScreen.x, (float)OnScreen.y, 3, 3,dYellow, pDevice );
}

}
}
}
}
}
}
}}}}}}}

