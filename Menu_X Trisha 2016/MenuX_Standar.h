
int MenuFolder[100];
void MenuX_Standar(LPDIRECT3DDEVICE9 pDevice)
{
	Current = 1;
		Folder("Vip Cyber Crekerz",MoptCredit,MenuFolder[0],2,pDevice);
		if(MenuFolder[0])
		{
	 	Folder("[Direct3D]",Moptfolder,MenuFolder[1],2,pDevice);
		if(MenuFolder[1])
		{
			Item("WallHack"		, SwiftONOF		,Nh_Teknology32	,2 ,pDevice);
			Item("Chams Teror"	, optColor2		,Nh_Teknology30	,10,pDevice);
			Item("Chams Swat"	, optColor2		,Nh_Teknology31 ,10,pDevice);
			Item("Wireframe"	, optColor2		,Wireframe      ,10,pDevice);
			Item("Remove Smoke"	, SwiftONOF		,Nh_Teknology33 ,2 ,pDevice);
			Item("CrossHair"	, optcrosshair	,Nh_Teknology34 ,3 ,pDevice);
		}
		Folder("[ESP Mode]",Moptfolder,MenuFolder[2],2,pDevice);
		if(MenuFolder[2])
		{
		    Item("ESP Name"		, SwiftONOF		,ESPName	    ,2 ,pDevice);
		    Item("ESP KDH"		, SwiftONOF		,ESPKD	        ,2 ,pDevice);
		    Item("ESP Box"		, SwiftONOF		,ESPBoox	    ,2 ,pDevice);
			Item("ESP Line"		, SwiftONOF		,FileLine	    ,2 ,pDevice);
		    Item("ESP Distance"	, SwiftONOF		,ESPDistance	,2 ,pDevice);
			Item("ESP Health"	, SwiftONOF		,ESPHealth	    ,2 ,pDevice);
			Item("ESP Bone"		, SwiftONOF		,ESPBone	    ,2 ,pDevice);
			Item("ESP Volume"	, SwiftONOF		,ESPVolume	    ,2 ,pDevice);
			Item("ESP Observer"	, SwiftONOF		,Nh_Teknology27	,2 ,pDevice);
		}
		Folder("[AimBot Visions]",Moptfolder,MenuFolder[3],2,pDevice);
		if(MenuFolder[3])
		{
		    Item("AIM Bullet"	, SwiftONOF		,Accuracy      ,2 ,pDevice);
			Item("Target AIM"	, MopTarget		,AimBody       ,2 ,pDevice);
			Item("Target Random", SwiftONOF		,Nh_NEWAIM	   ,2 ,pDevice);
			Item("Auto Killer"  , SwiftONOF     ,Nh_Teknology9 ,2 ,pDevice);
		}
		Folder("[Player Direct]",Moptfolder,MenuFolder[4],2,pDevice);
		if(MenuFolder[4])
		{ 
			Item("Unyu Bugs"	  , SwiftONOF	,UNYU			,2 ,pDevice);
			Item("Freeze Respown" , SwiftONOF	,Freeze			,2 ,pDevice);
			Item("No FallDamage"  , SwiftONOF	,NoFallDamage	,2 ,pDevice);			
		    Item("Wall Bugs"      , SwiftONOF	,WallBug	    ,2 ,pDevice);
			Item("Doble Jump"	  , SwiftONOF	,FlyCacadMode   ,2 ,pDevice);
			Item("Jump High"	  , SwiftONOF	,JumpHight		,2 ,pDevice);
			Item("VK Pilih"	      , SwiftONOF	,VoteKick       ,2 ,pDevice);
			Item("Flood Kick"	  , SwiftONOF	,FloodVk        ,2 ,pDevice);
			Item("Rank Hack"	  , MopRank 	,autoGM			,2 ,pDevice);
			Item("No AFK"		  , SwiftONOF	,AntiOut		,2 ,pDevice);
			Item("Player Speed"	  , SwiftONOF	,PlayerSpeed    ,2 ,pDevice);
			Item("Unlimited HP"	  , SwiftONOF	,UnHP		    ,2 ,pDevice);
			Item("No AFK"		  , SwiftONOF	,AntiOut		,2 ,pDevice);
			Item("Out Games"      , SwiftONOF   ,GameFastExit   ,2 ,pDevice);
			Item("Free Move[RM]"  , SwiftONOF   ,FreeMove       ,2 ,pDevice);

		}
		Folder("[Weapon Direct]",Moptfolder,MenuFolder[5],2,pDevice);
		if(MenuFolder[5])
		{ 
			Item("Hidden Weapon"	,SwiftONOF	,HiddenWeapon	,2 ,pDevice);
			Item("Rafid Fire"	    ,SwiftONOF	,RafidFire	    ,2 ,pDevice);
            Item("Smart Ammo"	    ,SwiftONOF	,SmartAmmoX		,2 ,pDevice);
			Item("Norecoil"			,SwiftONOF	,Recoil			,2 ,pDevice);
			Item("Fast Change"	    ,SwiftONOF	,QuickChange	,2 ,pDevice);
			Item("Fast Reload"		,SwiftONOF	,Reload			,2 ,pDevice);
			Item("Fast Knife"		,SwiftONOF	,BrustKnife		,2 ,pDevice);
		}
		Folder("[View Mode]",Moptfolder,MenuFolder[6],2,pDevice);
		if(MenuFolder[6])
		{ 
		    Item("Fast Killer"      , SwiftONOF    ,FastKelar      ,2 ,pDevice);
		    Item("WPSmoke Killer"   , SwiftONOF    ,SmokeCall      ,2 ,pDevice);
		    Item("Bullet Killer"    , SwiftONOF    ,BulletCall     ,2 ,pDevice);
		    Item("K-400 Brusht"     , SwiftONOF    ,BomKiller      ,2 ,pDevice);
		    Item("WallShoot"		, SwiftONOF	   ,WallShotHero   ,2 ,pDevice);
		    Item("Invi Time"	    , SwiftONOF	   ,Invincible	   ,2 ,pDevice);
		    Item("Zombie Killer"	, SwiftONOF	   ,ZombieCall	   ,2 ,pDevice);
		    Item("Magnet Killer"    , SwiftONOF    ,Magnet         ,2 ,pDevice);
		    Item("Tele Magnet"		, SwiftONOF    ,MagnetTele	   ,2 ,pDevice);
	      	Item("Sucide Killer"	, SwiftONOF	   ,SuicideCall	   ,2 ,pDevice);
		}

		Folder("[Weapon Setting]",Moptfolder,MenuFolder[7],2,pDevice);
		if(MenuFolder[7])
		{ 
            Item("Control -F2"		,SwiftONOF	    ,FakeReplace1		,2 ,pDevice);
            Item("RPG-7"			,SwiftONOF	    ,ReplaceRPG			,2 ,pDevice);
		    Item("Weapon Asault "	,MoptReplace	,ReplaceAsault		,7 ,pDevice);
		    Item("Granade"			,Granade	    ,ReplaceSmoke		,6 ,pDevice);
            Item("Scondary"		    ,MoptPistol	    ,HK		            ,3 ,pDevice);
		    Item("Knife"			,MoptPisoRep	,ReplacePiso		,7 ,pDevice);
		}

		Folder("[Ammo Setting]",Moptfolder,MenuFolder[8],2,pDevice);
		if(MenuFolder[8])
		{
            Item("Ammo RPG"         , SwiftONOF       ,AmmoRPG    ,2 ,pDevice);
		    Item("Ammo LC"          , SwiftONOF       ,AmmoLC     ,2 ,pDevice);
		    Item("Ammo Scondary"    , SwiftONOF       ,AmmoHK69A  ,2 ,pDevice);
		}

		Folder("[Setting]",Moptfolder,MenuFolder[9],2,pDevice);
		if(MenuFolder[9])
		{ 
			Item("Menu Mouse "			,SwiftONOF, MenuX_MouseShow	, 2 ,pDevice);
		}}
}
void Navigation(LPDIRECT3DDEVICE9 pDevice)
{

	if(Menu && NHT3XT)
	{
		if(IsKeyPressed(VK_DOWN,0))
			MenuSelection++;
		if(IsKeyPressed(VK_UP,0))
			MenuSelection--;
        
		MenuX_Standar(pDevice);

		if(MenuSelection >qntHacks - 1)
			MenuSelection = 0;
		if(MenuSelection < 0)
			MenuSelection = qntHacks - 1;
	}
}

void MenuSettings()
{
	menux = 10;
	menuy = 10;
	mxofs = 180;
	qntHacks = 0;
}
//#define STRING_TITLE                "Menu Selection v5"
VOID RenderMenu_S(LPDIRECT3DDEVICE9 pDevice)
{
	MenuSettings();
	if(Menu && NHT3XT)
	{	/* Main Menu */
		FillGradients (20, 10,(Current * 20),180,Menu_Standar,Menu_Standar,pDevice);
		pMenu.Rectangle(20, 10, 180, (Current * 20), Menu_rectangle, pDevice);
		pMenu.Rectangle(19, 9, 182, (Current * 20), Menu_special, pDevice);
		/* Windows Title */
		FillGradients (20,10,20,180,White,Grey,pDevice);
		pMenu.Rectangle(20, 10, 180, 20, Menu_rectangle, pDevice);
		pMenu.DrawString("Menu Bomberman", 110, 12, TextWarna2, 1);
		/* Main select */
		FillGradients (20 + 1,menuy + 22 + (MenuSelection * 20),14,178,Grey,SKYBLUE,pDevice);
	}
	Navigation(pDevice);
}