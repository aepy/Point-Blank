
//========================OFFSET BYPASS HOOK=============================//
#define Endrender 0x26CA0												 //
#define g_Render  0x1A0610												 //
#define HendyCode 21352										 //
#define HeNdYz 0x1474D8//0x133E10//0x135480										 //
//=======================================================================//

#define MAXPLAYERS 16
#define PLAYERSIZE 0x12F8		// "struct GAMEINFO_CHARACTER *__thiscall C"...
#define NAMESIZE   0x21
#define RANKSIZE   0x2B
#define ALSIZE     0x01
#define HPSIZE     0x20
#define IDSIZE     0x01
#define ALIVESIZE	0x24
#define OFS_HEADSH  0x62B8
#define OFS_HEADSP  0x62BC
#define OFS_HEALTH  0x264		// "class CGameCharaBase *__thiscall CGameCharaManager::AddChara(int,int,enum CHARARES_TYPE,int,enum CHARA_TYPE,bool)" + 4
#define OFS_ISALIVE 0x208		// "void __thiscall CEffectManager::InitAge"
#define OFS_WEAPON  0x5BC
// OFS_TEAM : "struct _NetCharaInfo *__thiscall CGameC" g_pGameContext->iMySlot
//-----------------------------------------------------------
#define OFS_TEAM				0x2BCB8
#define OFS_PLAYER				0x27340
#define ALLWEAPSIZE				0x27574
#define WEAPSIZE				0x158
#define OFS_WEAPSECONDAY		0x15C 
#define OFS_WEAPMEELE			0x160 
#define OFS_WEAPEXPLOSIVE		0x164 
#define OFS_WEAPSPECIAL			0x168 
#define OFS_RANK				0x2B5D5
#define OFS_RANK2				0x2B5D6
#define OFS_Hacker				0x40E58
#define OFS_Hacker2				0x40DD5
#define OFS_NAMES				0x2B894
#define OFS_RESPAWN				0x2B5D6
// ------------------------------------------------------------
#define OFS_Player 0x714310
#define OFS_Player2 0xB14310
#define OFS_Weapon 0x7142F4
#define OFS_Weapon2 0xB142F4
#define OFS_Ammo 0x7142D8
#define OFS_Ammo2 0xB142D8
#define OFS_Health				0x7142DC
#define OFS_Health2				0xB142DC
#define OFS_BaseHeadShot		0x7058E4
#define OFS_BaseHeadShot2		0xB058E4
#define OFS_BaseWM				0x7058E0
#define OFS_BaseWM2				0xB058E0
#define OFS_BaseGhost			0x705898
#define OFS_BaseGhost2			0xB05898
#define OFS_BaseDirect			0x706258
#define OFS_BaseDirect2			0xB06258
#define OFS_BaseVoteKick		0x70587C 
#define OFS_BaseVoteKick2		0xB0587C 
#define OFS_BaseRespon			0x7058D0
#define OFS_BaseRespon2			0xB058D0
#define OFS_BasePelor			0xB11904
#define OFS_BasePeler			0xB09D90 
// ------------------------------------------------------------
#define OFS_AntiVoteKick		0xADDB0
#define OFS_AntiVoteKick2		0x4AC710
// ------------------------------------------------------------
//			* ->>>   OFFSET HACK   <<<- *
// ------------------------------------------------------------
#define OFS_NET					0x40A820
#define OFS_PlayerXZ				0xE8019
#define OFS_BLUE_TEAM				0x1F030

#define OFS_TeamHS2				0x2BCA4


#define OFS_Damage				0x2D310
#define OFS_Damage2				0x2D278
#define OFS_BypassPI				0x2D510
#define OFS_BypassPI2				0x2D338
#define OFS_BypassKaca				0x2D050
#define OFS_BypassKaca2				0x2CFB8
#define OFS_PlayerSize				0x4A0
#define OFS_AMMOX				0x76 
#define OFS_AMMOX2				0x15B 
#define OFS_AmmoXX2				0x83
#define OFS_AmmoXX4				0x87
#define OFS_AmmoXX5				0x8D
// ------------------------------------------------------------
//			* ->>>   PLAYER HACK   <<<- *
// ------------------------------------------------------------
#define OFS_Pasang				0x5DC400
#define OFS_Defuse				0x57CC50
#define OFS_Planted				0x57CC52
#define OFS_MSpeed				0x577908
#define OFS_Chaos				0x589588
#define OFS_Ninja				0x57790A
#define OFS_NoRecoil				0x5779DC
#define OFS_Suiced				0x57CE60
#define OFS_FacingDirect			0x5779E4
#define OFS_InvicibleTime4vs4			0x589A78
#define OFS_InvicibleTime3			0x5DC660
#define OFS_SKILL1				0xADA3
#define OFS_SkillGM				0x4DEE4
#define OFS_FallDamage				0x243F4B
#define OFS_Unfreeze2 0x5945D4
#define OFS_Super				0xAE43B
#define OFS_BaseGhoster				0x589588 
#define OFS_Ninja				0x57790A
#define OFS_Control1				0x5F68F8
#define OFS_Control2				0x5F6900
#define OFS_NoRespawn				0x5DC400
#define OFS_I3VisibleTime			0x5988D4
#define OFS_SuperJump				0x445FBD
#define OFS_Gravity				0x5934DA
#define OFS_Grade				0x57CFE0
#define OFS_HealthHP				0x57D120
// ------------------------------------------------------------
//			* ->>>   SYSTEM HACK   <<<- *
// ------------------------------------------------------------
#define OFS_AntiPI1				0x5986A4 
#define OFS_AntiPI2				0x5A8660 
#define OFS_AntiPI3				0x5F7A4C 
#define OFS_AntiPI4				0x59861C 
#define OFS_ValueMax				0x577178
#define OFS_Minimize1				0x5882B4
#define OFS_Minimize2				0x588268
#define OFS_ReadMinimize			0x14
#define OFS_UnFrezze1				0x4A481
#define OFS_EventLog1				0x45015A
#define OFS_EventLog2				0xB32FB
#define OFS_STR_HACK				0x5986A4
#define OFS_STR_ID				0x5A8660
#define OFS_STR_ID_2				0x5F7A4C
// ------------------------------------------------------------
//			* ->>>   WEAPON HACK   <<<- *
// ------------------------------------------------------------
#define OFS_KrissSV				0x5A064C
#define OFS_K2					0x5DED28
#define OFS_P90					0x5EE1E0
#define OFS_M1887				0x5BC5C7
#define OFS_MAGNUM				0x5DF498
#define OFS_AKSOPMOD				0x5EE164
#define OFS_FireBullet				0x59A3CC
#define OFS_FireBullet2				0x59AA98
#define OFS_FireBullet3				0x59B448
#define OFS_FireBullet4				0x59B8DB
#define OFS_FireBullet5				0x59D53B
#define OFS_FireDecBullet			0x59A3E0
#define OFS_BomMiddle				0x576E0B
#define OFS_NoScope				0x589E34
#define OFS_ReloadSpeed				0x589E44
#define OFS_ReloadTime				0x59A578
#define OFS_ReloadBullet			0x59A3B0
#define OFS_AimAngle				0x589AD8
#define OFS_SGBrutall				0x58F9EC
#define OFS_AmmoCall				0x15C1F0
#define OFS_AmmoBased				0x3FFFC8 
#define OFS_UnAmmo1				0x497EA6
#define OFS_Reload				0xE8AEA
#define OFS_SpeedReload				0xE5306
#define OFS_FSpeed				0x5988D4
#define OFS_FourHack				0x5DC402
#define OFS_FiveHack				0x3BB5C
#define OFS_Brutal				0x5988D7
#define OFS_Unlimited				0x5FC470
#define OFS_Unlimited1				0x5E3BD8