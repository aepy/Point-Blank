#include "NFCZ_Menu.h"
#include "NFCZ_Hack.h"
int MenuFolder[100];

char *Moptfolder [] = {	">>>","<<<"};
char *ONOF [] = {	"OFF","ON"};
char *ONOF2 [] = {	"None","RPG-7","AK.FC","AK.FC RED.","S.Ligh"};
char *ONOF3 [] = {	"Head","Body"};
char *ONCO [] = {	"OFF","+","*"};
#define T_NFCZ "TEAM-HACKER"

void D3DMENU_NFCZ(LPDIRECT3DDEVICE9 pDevice){

Current = 1;

Folder("VISUAL HACK",Moptfolder,MenuFolder[0],2,pDevice);
if(MenuFolder[0]){
Item("WallHack"		           , ONOF		,WallHack	     ,2 ,pDevice);
Item("Remove Smoke"	           , ONOF		,NOSMOKE         ,2 ,pDevice);
Item("CrossHair"	           , ONCO   	,CROSS           ,3 ,pDevice);
}
Folder("VISUAL ESP",Moptfolder,MenuFolder[1],2,pDevice);
if(MenuFolder[1]){
Item("ESP N.a.m.e"              , ONOF       ,ESPName      ,2 ,pDevice);
Item("ESP L.i.n.e"              , ONOF       ,ESPLine      ,2 ,pDevice);
Item("ESP H.e.a.d"              , ONOF       ,ESPHead      ,2 ,pDevice);
Item("ESP B.o.n.e"              , ONOF       ,ESPBone      ,2 ,pDevice);
Item("ESP B.o.x.e"              , ONOF       ,ESPBox      ,2 ,pDevice);
Item("ESP H.e.a.l.t.h"          , ONOF       ,ESPHealth    ,2 ,pDevice);
Item("ESP O.b.s.e.r.v.e.r"      , ONOF       ,ESPObserver  ,2 ,pDevice);
	}
Folder("VISUAL PLAYER",Moptfolder,MenuFolder[2],2,pDevice);
if(MenuFolder[2]){
Item("No Li.e"           , ONOF ,NoLife       ,2 ,pDevice);
Item("Suicide"           , ONOF ,SuicideCall  ,2 ,pDevice);
Item("Wall Bug"          , ONOF ,WallBug      ,2 ,pDevice);
//Item("Bug Atas"         , ONOF ,Bug Atas     ,2 ,pDevice);
Item("Hack Rank"         , ONOF ,RankHack     ,2 ,pDevice);

	}
Folder("VISUAL WEAPON",Moptfolder,MenuFolder[3],2,pDevice);
if(MenuFolder[3]){
Item("NoRecoil "         , ONOF ,NoRecoil    ,2 ,pDevice);
Item("Ammo Kanan"        , ONOF ,Ammo         ,2 ,pDevice);
Item("Fast Knife"        , ONOF ,BrustKnife   ,2 ,pDevice);
Item("Fast Reload"       , ONOF ,FastReload   ,2 ,pDevice);
//Item("Fast Change"       , ONOF ,Quick        ,2 ,pDevice);
Item("RapidFire"         , ONOF , RapidFire   ,2 ,pDevice);
	}
Folder("VISUAL BULLET",Moptfolder,MenuFolder[4],2,pDevice);
if(MenuFolder[4]){
Item("A.I.M"             , ONOF ,AimBullet    ,2 ,pDevice);
Item("T.a.r.g.e.t"       , ONOF ,AimBody      ,2 ,pDevice);
//Item("AIM all Target"    , ONOF ,BulletCall   ,2 ,pDevice);
	}

Folder("VISUAL REPLACE",Moptfolder,MenuFolder[5],2,pDevice);
if(MenuFolder[5]){
Item("Control Weapon F2" , ONOF   ,FakeReplace   ,2 ,pDevice);
Item("R. Launcher"       , ONOF2   ,ReplaceRPG   ,5 ,pDevice);
Item("R. HandGun"        , ONOF    ,HK   ,6 ,pDevice);
Item("R. Smoke"          , ONOF   ,ReplaceSmoke ,2 ,pDevice);
	}
Folder("VISUAL KILLER",Moptfolder,MenuFolder[6],2,pDevice);
if(MenuFolder[6]){

Item("Smoke Killer"      , ONOF ,SmokeCall    ,2 ,pDevice);
Item("Bullet Killer"     , ONOF ,BulletCall   ,2 ,pDevice);
Item("Zombie Killer"     , ONOF ,ZombieCall   ,2 ,pDevice);
Item("WallShot Killer"   , ONOF ,WallShot     ,2 ,pDevice);
Item("Invicible Killer"  , ONOF ,Invincible   ,2 ,pDevice);
	}
}
void Navigation(LPDIRECT3DDEVICE9 pDevice)
{

	if(Menu && NHT3XT)
	{
		if(IsKeyPressed(VK_DOWN,0))
			MenuSelection++;
		if(IsKeyPressed(VK_UP,0))
			MenuSelection--;
        
		D3DMENU_NFCZ(pDevice);

		if(MenuSelection >qntHacks - 1)
			MenuSelection = 0;
		if(MenuSelection < 0)
			MenuSelection = qntHacks - 1;
	}
}

void MenuSettings()
{
	menux = 20;
	menuy = 10;
	mxofs = 177;
	qntHacks = 0;
}
//#define STRING_TITLE                "Menu Selection v5"
VOID RenderMenu_S(LPDIRECT3DDEVICE9 pDevice)
{
	MenuSettings();
	if(Menu && NHT3XT)
	{	/* Main Menu */
		//FillGradients (20, 10,(Current * 20),173,Menu_background,Grey,pDevice);
		//Rectangle(20, 10, 173, (Current * 20), Menu_rectangle, pDevice);
		//Rectangle(19, 9, 173, (Current * 20), Menu_special, pDevice);
		/* Windows Title */
		//FillGradients (20,10,20,173,White,Grey,pDevice);
		//Rectangle(20, 10, 173, 20, Menu_rectangle, pDevice);
		DrawString(T_NFCZ, 100, 12, TitleText, 1);
		/* Main select */
		DrawBorder(menux + 15, menuy + 20 + (MenuSelection * 20), mxofs -/*kiri*/ 60,/*Bawah*/ 15, 1, Red, pDevice);
	}
	Navigation(pDevice);
}