#include "Menu.h"
#include "GameHack.h"
#include "BulletKiller.h"
#include "AutoKillz.h"
#include "FloodVK.h"
int MenuFolder[100];

char* GetDate(){
	SYSTEMTIME st;
	GetSystemTime(&st);
	char *logbuf = new char[ 256 ];
	sprintf(logbuf,"Date : %d-%d-%d" ,st.wDay,st.wMonth,st.wYear);
	return logbuf;
}

/*------------------------------------------- Declaration Time ------------------------------------------------------*/
char* GetTime()
{
	struct tm * current_tm;
	time_t current_time;
	time (&current_time);
	current_tm = localtime(&current_time);
	char *logbuf = new char[ 256 ];
	sprintf(logbuf, "Time : %02d:%02d:%02d", current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec );
	return logbuf;
}
char* FPS(int en)
{
	static int	 FPScounter = 0;
	static float FPSfLastTickCount = 0.0f;
	static float FPSfCurrentTickCount;
	static char  cfps[6] = "";

	if(!en)
	{
		FPSfCurrentTickCount = clock() * 0.001f;
		FPScounter++;

		if((FPSfCurrentTickCount - FPSfLastTickCount) > 1.0f)
		{
			FPSfLastTickCount = FPSfCurrentTickCount;
			sprintf(cfps,"%d FPS",FPScounter);
			FPScounter = 0;
		}
	}
	return cfps;
}
char *Moptfolder   [] = {"[╗╗╗]","[ллл]"};
char *ONOF		   [] = {"Х","On"};
char *ONOF2		   [] = {"Х","RPG-7","K-201 Exit","AK 47 FC","AK Sopmod R","AK 47 FC RED","Scar Light"};
char *Replace2	   [] = {"Х","HK-69","MK-79"};
char *Replace3	   [] = {"Х","Mini Axe F2","Fang Blade F2","Combat F2"};
char *Replace	   [] = {"Х-╗","Famas","K-201","AK-47 FC R.","AK-47 FC","Scar D","RPG-7","M4 SR-16 FC"};
char *ONOF3		   [] = {"Head","Body"};
char *Ritem		   []  ={"Х-╗","Soccer","Candy","Lantern","Decoy","Bread","WP Smoke ++","WP Smoke D"}; 
char *RMelee	   [] = {"Х-╗","Kukri","Mini Axe","Fang Blade","Random"};
char *ONCO		   [] = {"Х","+","Х"};
char *Rank		   [] = {"Х-╗","B3","B4","B5","B5 Gold","Bomb","GM"};
char *Plant		   [] = {"Х","Site A","Site B"};
char *Tutor		   [] = {"Show","Hide"};
char *Bull		   [] = {"Х","RPG","AK-47"};
char *DinanInfo    [] = {""};
char *Bullet	   [] = {"Х","Caps Lock"};

#define A_NFCZ "╗ JRC Cyber л"

void D3DMENU_NFCZ(LPDIRECT3DDEVICE9 pDevice){
Current = 1;
Folder("[Visual Menu]",Moptfolder,MenuFolder[0],2,pDevice);
if(MenuFolder[0]){
Item(" Х Wallhack Clean"		    ,ONOF		,WallHack		,2 ,pDevice);
Item(" Х Wallhack Leopard"	            ,ONOF   	,Leopard         ,2 ,pDevice);
Item(" Х Wallhack Kaca"				,ONOF		,WHRobot		 ,2	,pDevice);
Item(" Х Remove Smoke"					,ONOF		,NOSMOKE         ,2 ,pDevice);
Item(" Х CrossHair",ONCO,CROSS,3,pDevice);
}
Folder("[Chams Menu]",Moptfolder,MenuFolder[1],2,pDevice);
if(MenuFolder[1]){
Item(" Х Chams Player TR"				,ONOF		,ChamsTR		 ,2	,pDevice);
Item(" Х Chams Player CT"				,ONOF		,ChamsCT		 ,2	,pDevice);
Item(" Х Chams Rainbow"			,ONOF		,ChamsRainbow	 ,2 ,pDevice);
Item(" Х Chams Weapon"					,ONOF		,ChamsWeapon	 ,2 ,pDevice);
}
Folder("[Esp Menu]",Moptfolder,MenuFolder[2],2,pDevice);
if(MenuFolder[2]){
Item(" Х Esp Name"						,ONOF       ,ESPName	     ,2 ,pDevice);
Item(" Х Esp Line"						,ONOF       ,ESPLine		 ,2 ,pDevice);
Item(" Х Esp Head"						,ONOF       ,ESPHead		 ,2 ,pDevice);
Item(" Х Esp Bone"					    ,ONOF       ,ESPBone		 ,2 ,pDevice);
Item(" Х Esp Box"						,ONOF       ,ESPBox			 ,2 ,pDevice);
Item(" Х Esp Health Bar"				,ONOF       ,ESPHealth		 ,2 ,pDevice);
Item(" Х Esp Observer"					,ONOF       ,ESPObserver   	 ,2 ,pDevice);
}
Folder("[Player Menu]",Moptfolder,MenuFolder[3],2,pDevice);
if(MenuFolder[3]){
Item(" Х Suicide"           ,ONOF		,SuicideCall	,2 ,pDevice);
Item(" Х Jump Hack"					,ONOF		,JumpHight		 ,2 ,pDevice);
Item(" Х Fall Damage"					,ONOF		,NoFallDamage    ,2 ,pDevice);
Item(" Х Rank"							,Rank		,RankHack		 ,7	,pDevice);
Item(" Х Anti Out"					    ,ONOF		,AntiOut		 ,2 ,pDevice);
Item(" Х Bug Unyu"          ,ONOF			,BugUnyu		,2 ,pDevice);
Item(" Х Wall Bug"          ,ONOF			,Wallbug		,2 ,pDevice);
Item(" Х Bug Hover"          ,ONOF			,BugLuxivile		,2 ,pDevice);
Item(" Х Zombie Real"       ,ONOF		,ZombieCall		,2 ,pDevice);
Item(" Х Vote Kick", ONOF,VoteKick,2,pDevice);
Item(" Х Flood Vote Kick", ONOF, Flood,2,pDevice); 
Item(" Х Plant Bomb", Plant,PlantBomb,3,pDevice);
}
Folder("[Weapon Menu]",Moptfolder,MenuFolder[4],2,pDevice);
if(MenuFolder[4]){
Item(" Х Ammo Kanan"				   ,ONOF		,Ammo			,2 ,pDevice);
Item(" Х Quick Change"				   ,ONOF		,QuickChange    ,2 ,pDevice);
Item(" Х Quick Reload"				   ,ONOF		,FastReload		,2 ,pDevice);
Item(" Х Burst Knife"				   ,ONOF		,BrustKnife		,2 ,pDevice);
Item(" Х Fire Speed"				   ,ONOF		,RapidFire		,2 ,pDevice);
}
Folder("[Ammo Menu]",Moptfolder,MenuFolder[5],2,pDevice);
if(MenuFolder[5]){
Item(" Х Ammo Launcher"				   ,ONOF		,AmmoLC		,2 ,pDevice);
Item(" Х Ammo Secondary"				   ,ONOF		,AmmoHK ,2 ,pDevice);
Item(" Х Ammo Bomb"				   ,ONOF		,AmmoBomb		,2 ,pDevice);
}
Folder("[Aim Menu]",Moptfolder,MenuFolder[6],2,pDevice);
if(MenuFolder[6]){
Item(" Х Aim Lock"          ,ONOF			,AimBullet		,2 ,pDevice);
Item(" Х Target"			,ONOF3		,AimBodyi		,2 ,pDevice);
Item(" Х Auto Fire"			,ONOF		,AutoFire,2,pDevice);
}
Folder("[Replace Menu]",Moptfolder,MenuFolder[7],2,pDevice);
if(MenuFolder[7]){
Item(" Х Auto Replace"			   ,ONOF		,DinanBrutal	,2 ,pDevice);
Item(" Х Melee"					   ,RMelee		,R_Melee		,5 ,pDevice);
Item(" Х Launcher"				   ,Replace     ,R_Launcher		,8 ,pDevice);
Item(" Х Secondary"				   ,ONOF		,R_Secondary	,2 ,pDevice);
Item(" Х Grenade"				   ,Ritem		,Rep_Item		,8 ,pDevice);
}
Folder("[Killer Menu]",Moptfolder,MenuFolder[8],2,pDevice);
if(MenuFolder[8]){
Item(" Х Invicible Time",ONOF,BP_Invi,2,pDevice);
Item(" Х Wallshot"					   ,ONOF		,WallShot		,2 ,pDevice);
Item(" Х Magnet"			   ,ONOF		,Magnet		    ,2 ,pDevice);
Item(" Х AutoKill"			,Bullet		,KillerKey		,2 ,pDevice);
Item(" Х Smoke Killer"				   ,ONOF		,SmokeCall		,2 ,pDevice);
Item(" Х Bomb Killer"				   ,ONOF		,BombKiller		,2 ,pDevice);
Item(" Х Bomberman"				   ,ONOF		,Bomberman,2,pDevice);
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
VOID RenderMenu_S(LPDIRECT3DDEVICE9 pDevice)
{
	MenuSettings();
	if(Menu && NHT3XT)
	{	
		FillGradients (20, 10,(Current * 20),173,Menu_background,Black,pDevice);
	//	Rectangle(20, 10, 173, (Current * 20), BLACK, pDevice);
	//	Rectangle(19, 9, 173, (Current * 20), BLACK, pDevice);
		/* Windows Title */
		FillGradients (20,10,20,173,WHITE,WHITE,pDevice);
	//	Rectangle(20, 10, 173, 20, WHITE, pDevice);
		DrawString(A_NFCZ, 100, 12, TitleText, 1);
	//	DrawBorder(menux + 1, menuy + 20 + (MenuSelection * 20), mxofs -/*kiri*/ 7,/*Bawah*/ 15, 1, RainbowTextTest, pDevice);
		FillGradients (menux + 1,menuy + 22 + (MenuSelection * 20),14,170,Skyblue,Skyblue,pDevice);
	//	PrintTextv2("Х-╗",menux + 1, menuy + 20 + (MenuSelection * 20), Red, NHT3XT);
		
		
		
	

	}
	Navigation(pDevice);
}