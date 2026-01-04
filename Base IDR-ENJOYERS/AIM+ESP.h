bool AimOff = false;
bool BHookedTele = false;
bool SHookedShot = false;
bool LHookedTele = false;
bool BulletEnable = false;
float fX,fY,fZ = 0;
//--------------------------------------------------------------------
DWORD BackupEDXTele;
_declspec(naked)void i3CollideeLine_SetEnd(){
_asm{
cmp [BulletEnable],0
je Skip
mov eax,dword ptr ss:[esp+0x4]
mov [BackupEDXTele],edx
mov edx,[fX]
mov [eax+0x0],edx
mov edx,[fY]
mov [eax+0x4],edx
mov edx,[fZ]
mov [eax+0x8],edx
mov edx,[BackupEDXTele]
Skip:
MOV EAX,DWORD PTR SS:[ESP+0x4]
FLD DWORD PTR DS:[EAX]
FSTP DWORD PTR DS:[ECX+0x18]
FLD DWORD PTR DS:[EAX+0x4]
FSTP DWORD PTR DS:[ECX+0x1C]
FLD DWORD PTR DS:[EAX+0x8]
FSTP DWORD PTR DS:[ECX+0x20]
FLD DWORD PTR DS:[ECX+0x18]
FSUB DWORD PTR DS:[ECX+0xC]
FSTP DWORD PTR DS:[ECX+0x24]
FLD DWORD PTR DS:[ECX+0x1C]
FSUB DWORD PTR DS:[ECX+0x10]
FSTP DWORD PTR DS:[ECX+0x28]
FLD DWORD PTR DS:[ECX+0x20]
FSUB DWORD PTR DS:[ECX+0x14]
FSTP DWORD PTR DS:[ECX+0x2C]
RETN 0x4
}
}
//--------------------------------------------------------------------
BYTE GetUserLife(int iSlot){
DWORD g_pGameContext   = *(DWORD*)ResultBasePlayer2;
CDeathPlayer *Life = (CDeathPlayer *) (g_pGameContext + ResultUserDeath);
return Life->Death[iSlot];
VirtualProtect((PVOID*)(g_pGameContext + ResultUserDeath), 10, PAGE_EXECUTE_READWRITE, &d);
}
//--------------------------------------------------------------------
int GetCharaIndex(){
DWORD g_pGameContext   = *(DWORD*)ResultBasePlayer2;
CLocalPlayerID *LocID = (CLocalPlayerID *) (g_pGameContext + OFS_Team);
return LocID->ID;
VirtualProtect((PVOID*)(g_pGameContext + OFS_Team), 10, PAGE_EXECUTE_READWRITE, &d);
}
//--------------------------------------------------------------------
int GetPriorityTarget(){
int Result = -1;
float fMaxDistance = 180.0f;
D3DXVECTOR3 PlayerEnd, LocPlayer;
for(int index = 0; index < 16; index++){
if(!GetUserLife(index) && GetCharaIndex() != index){
if(GetCharaIndex() %2 != index % 2){
GetUserBone(LocPlayer, 7 , GetCharaIndex());
GetUserBone(PlayerEnd, 7 , index);
if (CalcDistance(LocPlayer, PlayerEnd) < fMaxDistance){
fMaxDistance = CalcDistance(PlayerEnd, LocPlayer);
Result = index;
}
}
}
}
return Result;
}
DWORD OldProtect;

//--------------------------------------------------------------------
bool xHookedTele,cHookedShot = false;
void NNCZHOOKAIM(){
if(BHookedTele)return;
DWORD OFS_Telekill = (DWORD)GetModuleHandleA("PointBlank.exe") + ResultBaseBullet; 
VirtualProtect ( (LPVOID)(OFS_Telekill), sizeof (OFS_Telekill), PAGE_EXECUTE_READWRITE, &OldProtect ); 
NNCZPeler((PBYTE)OFS_Telekill,(DWORD)i3CollideeLine_SetEnd);
VirtualProtect ( (LPVOID)(OFS_Telekill), sizeof (OFS_Telekill), OldProtect, &OldProtect ); 
BHookedTele = true;
}
void AIMBulletMode(LPDIRECT3DDEVICE9 pDevice){
	NNCZHOOKAIM();
if(AimBullet){
if(*(PBYTE)ResultBaseAmmo2 > NULL){
int AimSlot = GetPriorityTarget();
if(AimSlot != -1){
D3DXVECTOR3 OnWorld,OnScreen;
switch(AimBody){
case 0:
BoneIndexSelector = 7;
break;
case 1:
BoneIndexSelector = 5;
break;
}
float ScreenCenterX = (Viewport.Width /2.0f);
float ScreenCenterY = (Viewport.Height /2.0f);
float ScreenBottomY = (Viewport.Height);
if(GetUserBone(OnWorld,BoneIndexSelector,AimSlot)){
BulletEnable = true;
fX = OnWorld.x;
fY = OnWorld.y + 0.1f;
fZ = OnWorld.z;
if(YoWorlToScreenGa(pDevice,OnWorld,OnScreen)){
						int x = ( OnScreen.x);
							int y = ( OnScreen.y);
							int Color = RED;
							//Circle (x,y,6,true,Color,pDevice);
							FillRGB(x-10, y, 7, 1,Color,pDevice);//Left line
							FillRGB(x+4, y, 7, 1,Color,pDevice);//Right line
							FillRGB(x, y-10, 1, 7,Color,pDevice);//Top line
							FillRGB(x, y+4, 1, 7,Color,pDevice);//Bottom line
							D3DRECT rec16 = {x-2, y-2, x+ 2, y+2};
							D3DRECT rec17 = {x-2, y-2, x+ 2, y+2};  
							pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), 0,  0 );//red
							pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), 0,  0 );
DrawLine(ScreenCenterX,ScreenCenterY,OnScreen.x,OnScreen.y,1,YELLOW);
}
}else{
BulletEnable = false;
}
}else{
BulletEnable = false;
}
}
}
}

//--------------------------------------------------------------------
void DrawObserver(LPDIRECT3DDEVICE9 pDevice){
if(ESPObserver==1){
if(GetBattleState1()){
int ServerRED =500;
int ServerBLUE =250;
int ServerY1 =480;
D3DVIEWPORT9 NNCZPort;
pDevice->GetViewport(&NNCZPort);
DWORD ScreenCenterX = NNCZPort.Width / 2;
DWORD ScreenCenterY = NNCZPort.Height / 2;
unsigned long dwBase	= *(DWORD*)(ResultBasePlayer2);
for (int i = 0; i <= 16; i++){
TeamScore	*TeamzScore	= (TeamScore*)((dwBase + ResultScore));
int myTeam	= GetTeam(i);
//--------------------------------------------------------------------
if (myTeam == 1){
TeamColor = Blue;
DrawBoxServer(ScreenCenterX + ServerBLUE + 40,(ServerY1-10)+(10*i),pDevice);
HealthbarServer(pDevice, ScreenCenterX + ServerBLUE + 65,(int)((ServerY1+2)-10)+(10*i),oHealth(i)->CurHP);
PingServer(ScreenCenterX + ServerBLUE + 187,(int)((ServerY1+2)-10)+(10*i),pPing(i)->iLog, pDevice);
DrawString(ScreenCenterX + ServerBLUE + 45,((ServerY1+2)-10)+(10*i),WHITE,"%d|%d   %s",pKill(i)->bKill,pKill(i)->bDead,oNames(i)->szNames);
DrawString2(ScreenCenterX + ServerBLUE + 40,460,Blue,"[Blue Team : %d]",TeamzScore->TScoreBlue);
}
//--------------------------------------------------------------------
if(myTeam ==2){
TeamColor = Red;
DrawBoxServer(ScreenCenterX - ServerRED + 40,(int)ServerY1+(10*i),pDevice);
HealthbarServer(pDevice,ScreenCenterX - ServerRED + 65,(int)(ServerY1+2)+(10*i),oHealth(i)->CurHP);
PingServer(ScreenCenterX - ServerRED + 187,(int)(ServerY1+2)+(10*i),pPing(i)->iLog, pDevice);
DrawString(ScreenCenterX - ServerRED + 45,(ServerY1+2)+(10*i),WHITE,"%d|%d   %s",pKill(i)->bKill,pKill(i)->bDead,oNames(i)->szNames);
DrawString2(ScreenCenterX - ServerRED + 40,460,Red,"[Red Team : %d]",TeamzScore->TScoreRed);	
}}}}}
//--------------------------------------------------------------------
void NNCZESPMode(LPDIRECT3DDEVICE9 pDevice){
unsigned long dwBase	= *(DWORD*)ResultBasePlayer2;
unsigned long dwBase2	= *(DWORD*)ResultBaseHealth2;	
CTeam		*pTeam		= ((CTeam*)(dwBase + OFS_Team));
//--------------------------------------------------------------------
char *dis		= new char[33];
//--------------------------------------------------------------------
float ScreenCenterX = (Viewport.Width /2.0f);
float ScreenCenterY = (Viewport.Height /2.0f);
float ScreenBottomY = (Viewport.Height);
//--------------------------------------------------------------------
for (int i = 0; i<=16; i++){
if (dwBase !=0){
if (dwBase2 !=0){
//--------------------------------------------------------------------
CNames		*pNames		= (CNames*)((dwBase + 0x295D4) + i * NAMESIZE);
CHealth		*pHealth	= (CHealth*)((dwBase2 + PTR_HEALTH) + i * ALIVESIZE);
//--------------------------------------------------------------------
DWORD ADR_PLAYER		= *(DWORD*)(ResultBasePlayer2);
DWORD pCalculate		= *(DWORD*)(ADR_PLAYER + 0x4 * i + PTR_Player );
DWORD pCalculate2		= *(DWORD*)(ADR_PLAYER + 0x4 * pTeam->iTeam + PTR_Player );
CPlayers	*pPlayer	= (CPlayers*)(pCalculate + 0x64 );
CPlayers	*pLocal		= (CPlayers*)(pCalculate2 + 0x64 );
D3DXVECTOR3 MyDistance	=	pLocal->pos - pPlayer->pos;
float MyaDistance = D3DXVec3Length(&MyDistance );
//--------------------------------------------------------------------
int MySlot = GetTeam(GetMyCharaIndex()); 
if(GetTeam(i) == MySlot) continue; 

//--------------------------------------------------------------------
if(GetUserBone(vEnd10,7,i)){
if(GetUserBone(vvEnd10,7,i)){
if(YoWorlToScreenGa(pDevice,vStart10,vvStart10)){
if(YoWorlToScreenGa(pDevice,vEnd10,vvEnd10)){
if (pHealth->CurHP > 1){
//----------------------------------------------------------------------------------
if(ESPBox == 1){
DrawBoxESP((float)vvStart10.x-(5000/MyaDistance)/30,(float)vvEnd10.y-(35000/MyaDistance)/45, 50000/MyaDistance/6*2/40,50000/MyaDistance/3*2/40, TeamColor, pDevice);
}
//--------------------------------------------------------------------
if (ESPName==1){
DrawStringESP(vvEnd10.x-10,vvEnd10.y-40,RED," %s ",pNames->szNames);
DrawStringESP(vvEnd10.x-9,vvEnd10.y-41,BLACK," %s ",pNames->szNames);
DrawStringESP(vvEnd10.x-9,vvEnd10.y-42,BLACK," %s ",pNames->szNames);
}


	}}}}}
//--------------------------------------------------------------------
if(GetBattleState1()){
if(GetUserBone(vStart,15,i)){
if(GetUserBone(vEnd,9,i)){
if(GetUserBone(vStart2,7,i)){
if(YoWorlToScreenGa(pDevice,vStart,vvStart)){
if(YoWorlToScreenGa(pDevice,vEnd,vvEnd)){
if(YoWorlToScreenGa(pDevice,vStart2,vvStart2)){
if(pHealth->CurHP > 1){

//--------------------------------------------------------------------
if(ESPHealth==1){
HealthBarNew(pDevice,(int)vvStart.x-25,(int)vvStart.y+10,pHealth->CurHP);
HealthEqui(pDevice,(int)vvStart.x-30,(int)vvEnd.y+15,pHealth->CurHP);
}
//--------------------------------------------------------------------
if(ESPLine==1){
DrawLine((float)ScreenCenterX,(float)ScreenBottomY,(float)vvStart.x,(float)vvEnd.y,1,GREEN);
}
//--------------------------------------------------------------------
if(ESPHead==1){
FillRGB((float)vvStart2.x,(float)vvStart2.y,3,3,Yellow, pDevice);
}
//--------------------------------------------------------------------
}}}}}}}}}}}}
//--------------------------------------------------------------------
void NNCZBone(LPDIRECT3DDEVICE9 pDevice){
unsigned long dwBase       = *(DWORD*)(ResultBasePlayer2);
unsigned long A_CGameChara = *(DWORD*)(ResultBaseHealth2);
CTeam         *pTeam       = ((CTeam*)(dwBase + OFS_Team));
CGameCharaBase* m_CharaBase = NULL;
int MyTeam = GetTeam(pTeam->iTeam);
for (int i = 0; i<= 0x16;i++){
if(A_CGameChara !=0){
m_CharaBase = (CGameCharaBase*)((*(DWORD*)(A_CGameChara + 0x14 + 0x4*i)));
int iTeam = GetTeam(i);
if (iTeam == MyTeam)continue;		
if (iTeam == 1){
TeamColor = Blue;
} 
else
if (iTeam == 2){
TeamColor = Red;
}
else{ continue;
}
if(m_CharaBase!=0)
if(m_CharaBase->m_BoneContext!=0){
if(ESPBone==1){
if(GetBattleState1()){
DrawSkeleton(m_CharaBase, ORANGE, pDevice);
}}}}}}