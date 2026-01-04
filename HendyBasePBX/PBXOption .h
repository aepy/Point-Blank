#pragma warning(disable: 4700 4101 4309 4305 4996)
int PI=false,Autoon=true,Charhack=true,Bypass=true,BypassHS=true,Striing=true,bypassilegal=true,bypassilegal2=true,FastPlant=true,Magnet=true,KillTeam=true,OnPrimary=true,RoolBack=true;
DWORD ResultBasePlayer,ResultBaseHealth,dwBase,dwSizee,dwSize,dwSize2,dwStartAddress,ResultWH3,Readwrite,ResultAMMOX,AmmoCall,ResultNameTag1,ResultNameTag2,
ResultRecoil,ResultRecoil1,ResultRecoil2,ResultRecoil3,ResultRecoil4,Quick,wire,ResultRecoil5,
ResultBrust1,ResultBrust2,ResultBrust3,ResultBrust4,ResultBrust5,ResultDrop1,ResultDrop2,
ResultBase,ResultBaseWeapon,ResultBaseAmmo,Addres_MSpeed,RETURN_MSpeed,
ResultBasePlayer2,ResultBaseWeapon2,ResultBaseHealth2,ResultBaseAmmo2,ResultBaseAmmo3,ResultBaseVK,
Skill,Frezzer,weapons,IndexReplace,tagName,Ammo,ResultOpen,ResultOpen2,ResultOpen3,ResultTeam,
ResultAVK,ResultSkill,ResultSkill2,ResultSkill3,ResultReplace,ResultReplace2,ResultReplace3,ResultReplace4,ResultReplace5,
ResultChar,dwBCLOG,SuperJump,dwBPEventLog1,dwBPEventLog2,dwFail,dwRemote,BP1,BP2,BP3,BP4,
ResultChar2,ResultChar3,ResultChar4,FallDamage,dwHS,dwHS2,dwHS3,dwHS4,OFS_AMMO2,
ResultHelm,ResultDMG,ResultHS,ResultBypassPI,ResultBypassKaca,ResultAmmo,
ResultAmmo2,ResultAmmo3,ResultAmmo4,ResultAmmo5,ResultBaseWinMode,ResultBaseWinMode2,ResultBaseNoDC2,
ResultGhost,ResultBetlayers,ResultBaseDirect,ResultPlayerSize,ByHS,HS,
ResultChaos,ResultPasang,ResultDeffuse,ResultRespwan,ResultMSpeed,ResultInvicible,ResultUnyu,I3STRHACKER,BasePeler,
ResultOFS_Winmode,ResultOFS_Minimiz,BypassRET;
DWORD ResultResPawn,ResultResPawn2,ResultOffset1,adr_autoshot_2,ret_autoshot,ret_autoshot_2,adr_autoshot_1,ResultOffset2,ResultOffset3,ResultOffset4,ResultOffset5;
DWORD  AdrX3, AdrX4, adrInvitime12, adrInvitime13, adrInvicible, adrGravity, dwI3EXEC, adrProteck, adrRep, adrBrutal, Neversaydie, ofsMNZ1,Change, CheckProtection;	
DWORD dewa19, ResultAOB =0;
int I3WallHack_Protect,I3PlayerSpeed,Submachine,Assault,Sniper, ResultPlant,ResultDefuse,Shotgun,I3VisibleTime,I3PlayerBase,I3KikAllEnemyALL,I3PlayerWepon,I3PelorReload,I3WM,I3ESP,ResultBypas,ResultBypasN,ResultWS,ResultWSFrame,ResultWSFrameB,ResultWSFrameC,ResultRIDA,ResultRIDB,ResultRIDC,ResultMAG,ResultRENDER,ResultHover,ResultMINI,I3PlayerRecoil,ResultRecV,ResultAku = 0;
bool Norespawn,FLOODAVK,NameTag,autoshot,Spam,AFK,UltimateAmmo,floodkickasu,NoRECOIL,akurasi = 0, WSCOY, FSpeed,HeadSs,AutoGM,AmmoKiri,AmmoKanan,AntiVote,GHOST,Speed,boomccd,Zombie,Hollow,GameMasterHPCT,GameMasterHPTero;
//---------------------------------------------------------------------------------------------------------------------------------

//==============================Replace==========================================// 
DWORD  Replace;
BOOL Memek(unsigned long ADRexec, int OFSexec, int PTRexec)
{
if (!IsBadWritePtr((void*)ADRexec, sizeof(unsigned long)))
{
if (!IsBadWritePtr((void*)(*(unsigned long*)ADRexec + OFSexec), sizeof(unsigned long)))
{
*(int*)(*(unsigned long*)ADRexec + OFSexec) = PTRexec;
}
}
return (0);
}
int __fastcall ProtectShield(void)
{
return (0);
}
//==============================BYPASS HOOK==========================================// 

void Func_Detour(PDWORD target, PDWORD newfunc)
{
DWORD Jmpto=(DWORD)(newfunc)-(DWORD)target-5;
DWORD a;
VirtualProtect(target, 8, PAGE_EXECUTE_READWRITE, &a);
*(PBYTE)(target)=0xE9;
*(PDWORD)((DWORD)(target)+1)=Jmpto;
VirtualProtect(target, 8, a, &a);
}
class clasicmenu
{
public:
char _0x0000[168];
DWORD cES;
char _0x00AC[156];
DWORD dipps;
};

void DRC(PDWORD target, PDWORD newfunc)
{
	DWORD Jmpto=(DWORD)(newfunc)-(DWORD)target-5;
	DWORD a;
    VirtualProtect(target, 8, PAGE_EXECUTE_READWRITE, &a);
    *(PBYTE)(target)=0xE9;
    *(PDWORD)((DWORD)(target)+1)=Jmpto;
	VirtualProtect(target, 8, a, &a);
}
class CHSBypass
{
public:
char _0x0000[168];
DWORD dwES;
char _0x00AC[156];
DWORD dwDIP;
};

//---------------------------------------------------------------------------------------------------------------------------------
void PrivateOnly(void *adr, void *ptr, int size)
{ 
        DWORD NextProtection;
        VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &NextProtection);
		Sleep(1);
        Sleep(1);
        RtlMoveMemory(adr,ptr,size);
		Sleep(1);
        Sleep(1);
        VirtualProtect(adr,size,NextProtection, &NextProtection);
}
void Alif(void *adr, void *ptr, int size)
{
DWORD NextProtection;
VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &NextProtection);
Sleep(1);
Sleep(1);
RtlMoveMemory(adr,ptr,size);
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
void destroyer(unsigned long ulBase, int iOffset, int iValue)
{
if (!IsBadReadPtr((VOID*)ulBase, sizeof(unsigned long)))
{
if (!IsBadWritePtr((void*)(*(unsigned long*)ulBase + iOffset), sizeof(unsigned long)))
{
*(int*)(*(unsigned long*)ulBase + iOffset) = iValue;
}
}}


DWORD Function_Two (DWORD Base,DWORD Ofs1,DWORD Ofs2, BYTE Value)
{ 
DWORD Temp=NULL;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
*(PBYTE)Temp=Value;
}
}
}
return (0);
}
//================================================================
void Function_One (DWORD Base,DWORD Ofs1, BYTE Value)
{ 
DWORD Temp=NULL;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
*(PBYTE)Temp=Value;
}
}
}
//---------------------------------------------------------------------------------------------------------------------------------
void MemWrite ( void* pxAddress, BYTE *code, int size )
{
unsigned long Protection;
VirtualProtect((void*)pxAddress, size, PAGE_READWRITE, &Protection);
memcpy((void*)pxAddress, (const void*)code, size);
VirtualProtect((void*)pxAddress, size, Protection, 0);
}
void OnlyMe(void *adr, void *ptr, int size)
{
        DWORD NextProtection;
        VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &NextProtection);
		Sleep(1);
        Sleep(1);
        RtlMoveMemory(adr,ptr,size);
		Sleep(1);
        Sleep(1);
        VirtualProtect(adr,size,NextProtection, &NextProtection);
}

//---------------------------------------------------------------------------------------------------------------------------------
void  Ripto_Post(void  *adr, void  *ptr, int  size)
{{
DWORD clinic;
VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &clinic);
Sleep(1); 
memcpy(adr,ptr,size);
Sleep(1); 
VirtualProtect(adr,size,clinic, &clinic);
}}
//---------------------------------------------------------------------------------------------------------------------------------
BYTE wepon,piso,pistol,bom,asep,dual;
void GetWeaponHack(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, int opt)
{
DWORD Temp =0;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
Temp=*(PDWORD)((DWORD)(Temp))+Ofs3;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
switch (opt){
	                    case 1:
							wepon = *(PBYTE)Temp;
						case 2:
							pistol = *(PBYTE)Temp;
						case 3:
							piso = *(PBYTE)Temp;
						case 4:
							bom = *(PBYTE)Temp;
						case 5:
							asep = *(PBYTE)Temp;
						case 6:
							dual = *(PBYTE)Temp;
}}}}}}
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
}}}}}

//--------------------------------------------------DR AMMO-------------------------------------------------------------------------------
WORD pKey, pBase, pValue, pSoul;
void GetValue(DWORD BaseOfs, DWORD Offset1, DWORD Offset2, DWORD Offset3)
{
DWORD Temp=0;
if (IsBadReadPtr((PDWORD)BaseOfs, 4) == 0){ 
Temp = *(PDWORD)((DWORD)(BaseOfs)) + Offset1;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
Temp = *(PDWORD)((DWORD)(Temp)) + Offset2;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
Temp = *(PDWORD)((DWORD)(Temp)) + Offset3;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){
switch (Offset3){
						case 0x979:
							pKey = *(PWORD)Temp;
						case 0x980:
							pBase = *(PWORD)Temp;
						case 0x984:
							pValue = *(PWORD)Temp;
						case 0x98C:
							pSoul = *(PWORD)Temp;
}}}}}}
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
//=================================================================
void PachtChara(DWORD B,DWORD A1,DWORD B1, DWORD ISI){
DWORD A=0;
if (IsBadReadPtr((PDWORD)B,4)==0){
A=*(PDWORD)((DWORD)(B))+A1;
if (IsBadReadPtr((PDWORD )A,4)==0){
A=*(PDWORD)((DWORD)(A ))+ B1;
if (IsBadReadPtr((PDWORD)A,4)==0) {
{*(PDWORD)A=ISI;}}}}}
//================================================================
void _patchPTR(unsigned long adr, unsigned long Ofset, DWORD dwValue)
{ DWORD A=0;
if (IsBadReadPtr((PDWORD)adr,4)==0)
{ A=*(PDWORD)((DWORD)(adr))+Ofset;
if (IsBadReadPtr((PDWORD)A,4)==0)
{*(PDWORD)A=dwValue;
}}} 
void  DonnyAchmadFauziGanteng(void  *adr, void  *ptr, int  size)
{

{   DWORD dwElla;
    VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &dwElla);
        Sleep(1); 
        memcpy(adr,ptr,size);
        Sleep(1); 
        VirtualProtect(adr,size,dwElla, &dwElla);
}
}
//---------------------------------------------------------------------------------------------------------------------------------
void TwoParam(DWORD B,DWORD A1, DWORD ISI)
{ DWORD A=0;
if (IsBadReadPtr((PDWORD)B,4)==0)
{ A=*(PDWORD)((DWORD)(B))+A1;
if (IsBadReadPtr((PDWORD)A,4)==0)
{*(PDWORD)A=ISI;
}}}

DWORD fnTwoParam(DWORD B, DWORD A1) {
DWORD A=0;
if (IsBadReadPtr((PDWORD)B,4)==0) { 
A=*(PDWORD)((DWORD)(B))+A1;
if (IsBadReadPtr((PDWORD)A,4)==0) {
return *(PDWORD)A;
}}
return A;}
//---------------------------------------------------------------------------------------------------------------------------------
DWORD ReadHS,ReadDM,ReadDM1,ReadDI,ReadPI,ReadHH,ReadDD,ReadDP,ReadPL,ReadPE,ReadPG,ReadPA,ReadPN,ReadPW,ReadBI,ReadBL,ReadBE,ReadBG,ReadBA,ReadBN,ReadBS,ReadBW,ReadPS,ReadDEMAGE,KeyHS1,KeyHS2,dwIndex,ReadHS1,ReadHS2,Ghoster,Bhetrayer;
bool bReadHS = false;
bool bReadDEMAGE = false;
bool bGhost = false;
bool bBetrayer = false;
bool cheadshot = false;
bool Ghosths = false;
DWORD Read(DWORD dwPtr, DWORD dwOfs){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return *(PDWORD)C; 
} } 
return C;
}


 