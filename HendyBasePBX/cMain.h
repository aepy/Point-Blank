//==================================================================================================================================//
//											AUTHOR	: M. Hendy																		//											  
//											Me      : M. Hendy
//											RELEASE : Kreasi Sendiri ^_^																	//
//											WEB		: Palembang-Community.blogspot.com													//
//																																	//
//										    NO SHARE TO PUBLIC || BASE RESMI Muhammad Hendy											//
//==================================================================================================================================//
#ifndef _DRTEAM_H
#define _DRTEAM_H

typedef HRESULT (WINAPI* tEndScene)(LPDIRECT3DDEVICE9 pDevice);
tEndScene oEndScene;

typedef HRESULT (WINAPI* tDrawIndexedPrimitive)(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount);
tDrawIndexedPrimitive oDrawIndexedPrimitive = NULL;

//Sprites Definitions
//Body
LPDIRECT3DTEXTURE9 txBody;
LPD3DXSPRITE spBody;
//Header
LPDIRECT3DTEXTURE9 txHeader;
LPD3DXSPRITE spHeader;	
//Footer
LPDIRECT3DTEXTURE9 txFooter;
LPD3DXSPRITE spFooter;
//Halloween
LPDIRECT3DTEXTURE9 txHalloween;
LPD3DXSPRITE spHalloween;

//Some Declarations
D3DXVECTOR3 pHeader; 
D3DXVECTOR3 pBody;
D3DXVECTOR3 pHalloween;
D3DXVECTOR3 pFooter;

BOOL Create;
LPDIRECT3DVERTEXBUFFER9 StreamData;
UINT OffsetInBytes;
UINT m_Stride;
LPDIRECT3DVERTEXBUFFER9 Stream_Data;
UINT Offset = 0;
UINT Stride = 0;
BOOL Color = TRUE;
BOOL FirstLog2 = true;
BOOL SecondLog2 = false;
BOOL firsthook = true;

char *Moptfolder        []  = {"<OPEN>", "<CLOSE>"}; 
char *Moptonoff         []  = {"[OFF]", "[ON]"};
char *Chams				[]  = {"••->•","[ Blue ]","[ Green ]","[ Orange ]","[ Purple ]","[ Red ]","[ White ]","[ Yellow ]","[ Black ]",""};
char *PEPPISTOL         []  = {"••->•", "UZZI", "Glock18", "R.B 454 SS8M+S", "Python", "Dual Eagle", "HK 69"};
char *PEPPISO         []  = {"••->•", "Flang", "Amok Kukri", "Mini Axe"};
char *assaulter         []  = {"••->•", "SG-550 Ext", "AK-47 Ext", "M4A1 Ext", "K-2", "F2000", "AK-47", "AK-47 G", "M4A1 S", "K-201 Ext", "G36C Ext", "SG-550 S", "AK SOPMOD", "AUG A3", "AUG A3G", "AUG A3 D"};
char *smger         []  = {"••->•", "kriss svd", "batik", "P90 MCD", "P90 D", "dual uzi", "MP7 Sl"};
char *sger         []  = {"••->•", "spass SI", "SPASS . D", "spass MCS", "SG putar", "SG putar Silver", "jackhammer"};
char *sper         []  = {"••->•", "magnum", "cheytac 200m", "barreta", "range master stby", "L115A1 Black", "jackhammer"};
char *REPBOM         []  = {"••->•", "k400 Dual", "Cokolate", "C-5"};
char *REPBARRET         []  = {"••->•", "Asault +++", "SubManchine Gun ", "Sniper"};
char *Carakter         []  = {"••->•", "Kopasus", "", ""};
/*char *optRepleckSMG		[]  = {"[OFF]","KrissSuperV","Kriss S. V",""};
char *optRepleckAWP     []	= {"","•[ Barrett M82A1 ]•","•[ Windchester M70 ]•","•[ CheyTac 200M ]•","•[ VSK94 ]•","•[ Dragunov D ]•","•[ Rangemaster .338 ]•","•[ Rangemaster 7.62 ]•","•[ Rangemaster 7.62 STBY ]•","•[ SPSG 1 G ]•","•[ ALL ]•"};
char *optAsallut        []	= {"","•[ SG-550 Ext ]•","•[ AK-47 Ext ]•","•[ M4A1 Ext ]•","•[ Kriss S. V ]•","•[ F2000 Ext ]•","•[ AK-47 G ]•","•[ M4A1 S ]•","•[ P90 ]•","•[ G36C Ext ]•","•[ ALL ]•"};
char*/ //*optRepleckSG      []	= {"","•[ Gang Chol ]•","•[ SPAS-15 Sl ]•","•[ 870MCS ]•","•[ SPAS-15 ]•","•[ 870MCS W. ]•","•[ M1887 ]•","•[ 870MCS T. ]•","•[ 870MCS Sl ]•","•[ SPAS-15 Sl.+]•","•[ ALL ]•"};
//char *optHEADGER        []	= {"","•[ PISO ]•","•[ BERET GM ]•","•[ HEADGER ]•","•[ SMOKE ]•","•[ ALL ]•"};
char *optColor1         []	= {"","•[ White ]•","•[ Red ]•","•[ Green ]•","•[ Blue ]•","•[ Black ]•","•[ Purple ]•","•[ Grey ]•","•[ Yellow ]•","•[ Orange ]•","•[ ALL ]•"};
char *optColor2			[]	= {"White","Red","Green","Blue","Black","Purple","Grey","Yellow","Orange"};
char *optFog			[]	= {"[OFF]","White","Red","Green","Blue","Black","Purple","Grey","Yellow","Orange","None"};
char *optcrosshair		[]= {"[OFF]","Purple","Blue","Cyan","Green","Yellow","Orange","Red","ALL"};
char *optTrigger		[]= {"[OFF]","Red","Blue"};
char *optSPEED			[]= {"[OFF]","1","2","3","4","5","6","7","8"};
char ijumas				[100] = "";
//char *MoptNgento		[] = {"OFF", "F2"};
char *NULLknop			[] = {"", ""};
char *MenuAIM			[]= {"•[ Head ]•","•[ Body ]•","•[ Righ Foot ]•","•[ Left Foot ]•","•[ Righ Hand ]•","•[ Left Hand ]•"};
char *MenuAIMH			[]= {"[OFF]","Hold Shift","L MOUSE"};
char *MoptMove			[] = {"[OFF]", "Plus x1","Plus x2"};
char *MoptHit			[] = {"[OFF]", "2 Hit","3 Hit","4 Hit","5 Hit","6 Hit","7 Hit"};
char *MoptNgento		[] = {"[OFF]", "Active"};
char *MoptNgentot1		[] = {"[OFF]","LSHIFT"};

char *SettingPangkat    [] = {"OFF","GM Jancok","Bom Hack","Bintang Emas","Bintang 5","Bintang 4","Bintang 3"};
char *MoptAutoHs		[] = {"Disable", "CapsLock Untuk On/Off"};
char *MoptPistol		[] = {"IMI UZI", "Glock", "D.Eagle", "Cpython", "RB", "P99"};
char *MoptPisau 		[] = {"FangBlade", "Keris", "Combat", "Axe", "Amox"};
char *MoptWece			[] = {"[OFF]", "Machete", "Balistik"};
char *MoptDCE			[] = {"[OFF]", "SG Gaul", "M Black"};
char *Moptcham			[]= {"••->•","[ Blue ]","[ Green ]","[ Orange ]","[ Purple ]","[ Red ]","[ White ]","[ Yellow ]","[ Black ]",""};
char *MoptRank			[] = {"••->•", "•[B*3]•" , "•[B*4]•" , "•[B*5]•" , "•[GM]•"};
char *MoptSkill			[] = {"••->•", "•[B*3]•" , "•[B*5]•" , "•[GM]• " , "•[BOM]•"};

char *MoptSnip			[] = {"••->•", "•[bareta]•" , "•[DragunovSl]•" , "•[L115A1]•" , "•[PSG-1S]•" , "•[SSG-69Sl]•","•[DragunovCS]•","•[DragunovCG]•","•[Rangemaster338]•","•[L115A1Black]•","•[CheyTac200M]•"};

char *MoptSubmg			[] = {"••->•", "•[SpectreExt]•" , "•[MP7Ext]•" , "•[P90M.C]•" , "•[P90Ext]•","•[KrissSuperV]•","•[KrissS.V]•","•[SpectreWh]•","•[MP7 Sl]•"};

char *MoptAssal			[] = {"••->•", "•[Null]•" , "•[SG-550 Ext]•" , "•[AK-47 Ext]•" , "•[M4A1 Ext]•" , "•[K-2]•","•[F2000 Ext]•","•[AK-47 G]•","•[M4A1 S]•","•[K-201 Ext]•","•[G36C Ext]•","•[SG-550 S]•","•[AK SOPMOD]•","•[AUG A3]•","•[AUG A3G]•","•[AUG A3D]•"};

char *MoptShtgu			[] = {"••->•", "•[870MCS]•" , "•[SPAS-15]•" , "•[870MCS W]•" , "•[M1887]•" , "•[SPAS-15 Sl]•"};


char *MoptAsult			[] = {"••->•", "•[SG-550 Ext]•" , "•[AK-47 Ext]•" , "•[M4A1 Ext]•" , "•[K-2]•" , "•[F2000 Ext]•", "•[AK-47 G]•", "•[M4A1 S]•", "•[K-201 Ext]•", "•[G36C Ext]•", "•[G36C Ext]•", "•[SG-550 S]•", "•[AK SOPMOD]•", "•[AUG A3]•", "•[AUG A3G]•", "•[AUG A3 D]•"};

char *Moptsmgs			[] = {"••->•", "•[kriss svd]•" , "•[batik]•" , "•[P90 MCD]•" , "•[P90 D]•" , "•[dua uzi]•", "•[MP7 Sl]•"};

char *Moptsg			[] = {"••->•", "•[spass SI]•" , "•[SPASS.D]•" , "•[spass MCS]•" , "•[SG putar]•" ,"•[SGputarSlver]•" , "•[jackhammer]•"};

char *MoptAwp			[] = {"••->•", "•[magnum]•" , "•[cytac 200m]•" , "•[dragunnov]•" , "•[barreta]•" , "•[rangemasterstby]•", "•[L115A1 Black]•"};

char *MoptSec			[] = {"••->•", "•[UZZI]•" , "•[Glock18]•" , "•[R.B 454]•"};

char *MoptMale			[] = {"••->•", "•[Fang Blade]•" , "•[Combat]•" , "•[Mini Axe]•"};


char *MoptFace			[] = {"[OFF]", "FB" , "BOKEP"};
char *opt_Bandi         [] = {"OFF","Auto"};
char *opt_Bandi2        [] = {"OFF","•[ F5 "};
char *opt_Bandi3        [] = {"•[ F12 ]•"};
char *NULLknop4[] = {"Show","DM= Headshot asli 1x.ON kan.. Mati 2x OFF kan!"};
char *NULLknop6[] = {"Show","BM= OFF kan tiap ronde Berganti!"};
char *NULLknop7[] = {"Show","Jgn sampai mati ketika posisi Ghost lagi ON!"};
char *NULLknop5[] = {"Show","ON kan.. Bokongi lawan.OFF kan baru Kill!"};

int Count = 0;
int AutoON=1;
D3DXMATRIX cProjection, cWorld, cView ;

#endif