//--------------------------------------------------------------------
DWORD dwBasett,dwBasettt,dwBasetttt,NNCZCallHitEvent,DoLineColly,getVCPos,getVCPos1;
DWORD dwBombBasett,dwBombBasettt,dwBombBasetttt,NNCZCallHitEventBomb,DoLineCollyBomb,getVCPosBomb;
DWORD dwBulletBasett,dwBulletBasettt,dwBulletBasetttt,NNCZCallHitEventBullet,DoLineCollyBullet,getVCPosBullet;
//--------------------------------------------------------------------
int SmokeCall = NULL;
int DamageCall = NULL;
//--------------------------------------------------------------------
int BombCall = NULL;
int DamageBombCall = NULL;
//--------------------------------------------------------------------
int BulletCall = NULL;
int DamageBulletCall = NULL;
//--------------------------------------------------------------------
int GetTeam1(int MyT){
for(int i = 0; i<=15; i+=2)
if( i == MyT ) return 1;
for(int i = 1; i<=15; i+=2)
if( i == MyT ) return 2;
return 0;
}
//--------------------------------------------------------------------
DWORD NNCZPatchKiller1(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
C=*(PDWORD)((DWORD)(C))+dwOfs2;
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return *(PDWORD)C; 
}}} 
return C;
}
//--------------------------------------------------------------------
DWORD NNCZPatchKiller2(DWORD dwPtr, DWORD dwOfs){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return *(PDWORD)C; 
}}
return C;
}
//--------------------------------------------------------------------
DWORD NNCZPatchKiller3(DWORD dwPtr){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=(*(DWORD*)(dwPtr)); 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return C; 
}}
return C;
}
//--------------------------------------------------------------------
DWORD NNCZPatchKiller4(DWORD dwPtr){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=((DWORD)dwPtr); 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return C; 
}} 
return C;
}
//--------------------------------------------------------------------
int GetMyCharaIndexed(unsigned int Index){
DWORD dwI3EXEC	 = (DWORD)GetModuleHandleA("PointBlank.exe");
unsigned long dwBase	= *(DWORD*)(dwI3EXEC + ResultBasePlayer);
CTeam *MyTeam = (CTeam*) ((dwBase + 0x2989C));
Index=MyTeam->iTeam;
return Index;
}

//--------------------------------------------------------------------
DWORD GetVCPos(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk){
dwBasettt = NNCZPatchKiller2(ResultBaseAmmo2, 0x554);
getVCPos  = NNCZPatchKiller4(0x71CF00);
if (!dwBasettt)return 0;
DWORD getVCPosss;
if(dwBasettt){
getVCPosss = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))getVCPos)(dwBasettt, Vect, Mat, iUnk);
}
return getVCPosss;
}
//--------------------------------------------------------------------
DWORD GetVCPos2(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk){
dwBombBasettt = NNCZPatchKiller2(ResultBaseAmmo2, 0x554);
getVCPosBomb  = NNCZPatchKiller4(0x71CF00);
if (!dwBombBasettt)return 0;
DWORD getVCPosssBomb;
if(dwBombBasettt){
getVCPosssBomb = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))getVCPosBomb)(dwBombBasettt, Vect, Mat, iUnk);
}
return getVCPosssBomb;
}
//--------------------------------------------------------------------
DWORD GetVCPos3(D3DXVECTOR3* Vect, D3DXMATRIX* Mat, int iUnk){
dwBulletBasettt = NNCZPatchKiller2(ResultBaseAmmo2, 0x554);
getVCPosBullet  = NNCZPatchKiller4(0x71CF00);
if (!dwBulletBasettt)return 0;
DWORD getVCPosssBullet;
if(dwBulletBasettt){
getVCPosssBullet = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXMATRIX*, int))getVCPosBullet)(dwBulletBasettt, Vect, Mat, iUnk);
}
return getVCPosssBullet;
}
//--------------------------------------------------------------------
DWORD NNCZDoLineColly1(UINT i){
D3DXVECTOR3	vBone, vLocal;
DWORD DoLineCollyyy;
switch(AimBody){
case 0:
BoneIndexSelector = 7.7;
break;
case 1:
BoneIndexSelector = 5;
break;
}
dwBasett    = NNCZPatchKiller1(ResultBaseAmmo2, ResultPTRAmmo , 0x2C);
DoLineColly = NNCZPatchKiller4(0x58A7E0);
GetVCPos(&vLocal,0,0);
vBone = _NNCZ->GetUserBone2(i,BoneIndexSelector);
if(dwBasett){
DoLineCollyyy = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))DoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
}
return DoLineCollyyy;
}
//--------------------------------------------------------------------
DWORD NNCZDoLineColly2(UINT i){
D3DXVECTOR3	vBoneBomb, vLocalBomb;
DWORD DoLineCollyyyBomb;
switch(AimBody){
case 0:
BoneIndexSelector = 7.7;
break;
case 1:
BoneIndexSelector = 5;
break;
}
dwBombBasett    = NNCZPatchKiller1(ResultBaseAmmo2, ResultPTRAmmo , 0x28);
DoLineCollyBomb = NNCZPatchKiller4(0x58A7E0);
GetVCPos2(&vLocalBomb,0,0);
vBoneBomb = _NNCZ->GetUserBone2(i,BoneIndexSelector);
if(dwBombBasett){
DoLineCollyyyBomb = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))DoLineCollyBomb)(dwBombBasett, &vLocalBomb, &vBoneBomb, GetTeam1(i));
}
return DoLineCollyyyBomb;
}
//--------------------------------------------------------------------
DWORD NNCZDoLineColly3(UINT i){
D3DXVECTOR3	vBoneBullet, vLocalBullet;
DWORD DoLineCollyyyBullet;
switch(AimBody){
case 0:
BoneIndexSelector = 7.7;
break;
case 1:
BoneIndexSelector = 5;
break;
}
dwBulletBasett    = NNCZPatchKiller1(ResultBaseAmmo2, ResultPTRAmmo , 0x1C);
DoLineCollyBullet = NNCZPatchKiller4(0x58A7E0);
GetVCPos3(&vLocalBullet,0,0);
vBoneBullet = _NNCZ->GetUserBone2(i,BoneIndexSelector);
if(dwBulletBasett){
DoLineCollyyyBullet = ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))DoLineCollyBullet)(dwBulletBasett, &vLocalBullet, &vBoneBullet, GetTeam1(i));
}
return DoLineCollyyyBullet;
}
//--------------------------------------------------------------------
DWORD NNCZCallHitEvent1(UINT i){
D3DXVECTOR3	vEnemy;
DWORD NNCZCallHitEventtt;
dwBasett   = NNCZPatchKiller1(ResultBaseAmmo2, ResultPTRAmmo, 0x2C);
dwBasetttt = NNCZPatchKiller3(ResultBaseAmmo2);
NNCZCallHitEvent = NNCZPatchKiller4(0x8E6F50);
GetVCPos(&vEnemy,0,0);
if(dwBasett){
NNCZCallHitEventtt = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))NNCZCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
}
return NNCZCallHitEventtt;
}
//--------------------------------------------------------------------
DWORD NNCZCallHitEvent2(UINT i){
D3DXVECTOR3	vEnemyBomb;
DWORD NNCZCallHitEventttBomb;
dwBombBasett   = NNCZPatchKiller1(ResultBaseAmmo2, ResultPTRAmmo, 0x28);
dwBombBasetttt = NNCZPatchKiller3(ResultBaseAmmo2);
NNCZCallHitEventBomb = NNCZPatchKiller4(0x8E6F50);
GetVCPos2(&vEnemyBomb,0,0);
if(dwBombBasett){
NNCZCallHitEventttBomb = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))NNCZCallHitEventBomb)(dwBombBasett, dwBombBasetttt, &vEnemyBomb, dwBombBasett);
}
return NNCZCallHitEventttBomb;
}

//--------------------------------------------------------------------
DWORD NNCZCallHitEvent3(UINT i){
D3DXVECTOR3	vEnemyBullet;
DWORD NNCZCallHitEventttBullet;
dwBulletBasett   = NNCZPatchKiller1(ResultBaseAmmo2, ResultPTRAmmo, 0x1C);
dwBulletBasetttt = NNCZPatchKiller3(ResultBaseAmmo2);
NNCZCallHitEventBullet = NNCZPatchKiller4(0x8E6F50);
GetVCPos3(&vEnemyBullet,0,0);
if(dwBulletBasett){
NNCZCallHitEventttBullet = ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))NNCZCallHitEventBullet)(dwBulletBasett, dwBulletBasetttt, &vEnemyBullet, dwBulletBasett);
}
return NNCZCallHitEventttBullet;
}

//--------------------------------------------------------------------
void NNCZCallDoLineColly1(){
for (int i = 0; i < 16; i++){
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(_NNCZ->IsAlive(i)){
NNCZDoLineColly1(i);
}
}
}
//--------------------------------------------------------------------
void NNCZCallDoLineColly2(){
for (int i = 0; i < 16; i++){
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(_NNCZ->IsAlive(i)){
NNCZDoLineColly2(i);
}
}
}
//--------------------------------------------------------------------
void NNCZCallDoLineColly3(){
for (int i = 0; i < 16; i++){
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(_NNCZ->IsAlive(i)){
NNCZDoLineColly3(i);
}
}
}
//--------------------------------------------------------------------
void NNCZHitEvent1(){
for (int i = 0; i < 16; i++){
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
NNCZCallHitEvent1(i);
if(_NNCZ->IsAlive(i)){				
NNCZCallHitEvent1(i);
}
}
}
//--------------------------------------------------------------------
void NNCZHitEvent2(){
for (int i = 0; i < 16; i++){
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
NNCZCallHitEvent2(i);
if(_NNCZ->IsAlive(i)){				
NNCZCallHitEvent2(i);
}
}
}
//--------------------------------------------------------------------
void NNCZHitEvent3(){
for (int i = 0; i < 16; i++){
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(_NNCZ->IsAlive(i)){				
NNCZCallHitEvent3(i);
}
}
}
//--------------------------------------------------------------------
void WPSMOKEFUNCTION(){
if(SmokeCall){
NNCZCallDoLineColly1();
DamageCall = 1;
}
if(SmokeCall==0){
DamageCall = 0;
}
if(DamageCall==1){
NNCZHitEvent1();
}
}
//--------------------------------------------------------------------
void BOMBFUNCTION(){
if(BombCall){
NNCZCallDoLineColly2();
DamageBombCall = 1;
}
if(BombCall==0){
DamageBombCall = 0;
}
if(DamageBombCall==1){
NNCZHitEvent2();
}
}
//--------------------------------------------------------------------
void BULLETFUNCTION(){
if(BulletCall){
NNCZCallDoLineColly3();
DamageBombCall = 1;
WallShot = NULL;
}
if(BulletCall==0){
DamageBombCall = 0;
}
if(DamageBulletCall==1){
NNCZHitEvent3();
}
}
//--------------------------------------------------------------------