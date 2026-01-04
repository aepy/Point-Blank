#include <Windows.h>
#include <winbase.h>
#include <fstream>
#include <Windows.h>
#include <winbase.h>
#include <fstream>
bool RCHHK69,RCHRPG,RCHFC,RCHSMOKE,RCHBOMB,bAmmo=false;
void AmmoReloads()
{
	if(bAmmo == false){
			StartRouneAmmo = TestPacth(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, ResultPTRCaclAmmo);
	}
	if(Ammo == 0){
		bAmmo = false;
		gEtWeapon_IndexA( ResultBaseAmmo2, ResultPTRAmmo, 0x1C, ResultPTRCaclAmmo, StartRouneAmmo);
    }
	if(Ammo == 1){
		bAmmo = true;
		gEtWeapon_IndexA( ResultBaseAmmo2, ResultPTRAmmo, 0x1C, ResultPTRCaclAmmo, StartRouneAmmo);
		}}
void BrustLauncher(){
__try{
if (*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+ResultPTRAmmo)+0x38)==1){
*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30)+ResultRafid)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
}
if (*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+ResultPTRAmmo)+0x38)==0){
*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30)+ResultRafid)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;
}}
__except ( EXCEPTION_EXECUTE_HANDLER ){ 
}
}

/*---------------------------------------- Declaration Ammo Rocket ----------------------------------------------------*/
void AmmoRocket()
{
	if(AmmoRPG==1)
	{ 
		Ammo=0;
		Reload =0;
		//Reaload();
		BrustLauncher();
		if(RCHRPG==false)
		{
			AmmoRPG1  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, ResultPTRCaclAmmo-0x27);
			AmmoRPG2  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, ResultPTRCaclAmmo-0x10);
			AmmoRPG3  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, ResultPTRCaclAmmo-0xC);
			AmmoRPG4  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, ResultPTRCaclAmmo-0x8);
			AmmoRPG5  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C,  ResultPTRCaclAmmo-0x4);
			AmmoRPG6  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, ResultPTRCaclAmmo); // NeoPTRAmmoB
			RCHRPG=true;
		}
		else 
			if(RCHRPG==true)
			{
				
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, ResultPTRCaclAmmo-0x27, AmmoRPG1);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, ResultPTRCaclAmmo-0x10, AmmoRPG2);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, ResultPTRCaclAmmo-0xC, AmmoRPG3);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, ResultPTRCaclAmmo-0x8, AmmoRPG4);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, ResultPTRCaclAmmo-0x4, AmmoRPG5);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, ResultPTRCaclAmmo, AmmoRPG6); // NeoPTRAmmoB
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRProtectA, 0x00); // NeoPTRProtectA
	            WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRProtectB, 0x00); // NeoPTRProtectB
	            WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRProtectA-0x10, 0x00); // NeoPTRProtectA

				Sleep(10);
			}
	}
	else
		RCHRPG=false;
}

/*---------------------------------------- Declaration Ammo Launcher ----------------------------------------------------*/
void AmmoLauncher()
{
	if(AmmoLC==1)
	{   
		Ammo=0;
		Reload =0;
		BrustLauncher();
		if(RCHFC == false)
		{
			AmmoPrymariFC = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRAmmoC); 
			RCHFC = true;
		}
		else 
			if(RCHFC==true)
			{
				
			
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRAmmoC, AmmoPrymariFC); // NeoPTRAmmoC
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRProtectA, 0x00); // NeoPTRProtectA
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRProtectB, 0x00); // NeoPTRProtectB
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRProtectA-0x10, 0x00); // NeoPTRProtectA

				Sleep(50);
			}
	}
	else
		RCHFC=false;
}

/*---------------------------------------- Declaration Ammo Smoke ----------------------------------------------------*/
void _stdcall BomberMan()
{
	if(GetBattleState())
	{
		if(*(PBYTE)ResultBaseAmmo2 > NULL)
		{
			if (*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+ResultPTRAmmo) + 0x40) == 3)//primary ==0 ) //k400 ==3)//smok++ ==4)
			{
				*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30) + 0x30) + 0x58) = 0;
			}
			if (*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+ResultPTRAmmo) + 0x40) == 4)//primary ==0 ) //k400 ==3)//smok++ ==4)
			{
				*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30) + 0x30) + 0x58) = 0;
			}
		}
	}
}

void FastBom() {
PachtChara(ResultBaseAmmo2,0x53C,0x20,0x41);
//c_WeaponIndex_B(mBase + ResultBaseAmmo,0x544,0x28, 0x30,0x67,0x41);
//c_WeaponIndex_B(mBase + ResultBaseAmmo,0x544,0x2C, 0x30,0x67,0x41); 
} 
void CallGranade(LPDIRECT3DDEVICE9 pDevice){
if(BrustBomb == 1){
__try{ 
*(int*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2) + ResultPTRAmmo) + 0x28)+ 0x510)+ 0x0)+ PTRProtectC) = 0; 
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectA, 0x00);
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectB, 0x00);
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectC, 0x00); 
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectD, 0x00); 
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectA-0x10, 0x00);} 
__except (EXCEPTION_EXECUTE_HANDLER){} 
}}
/*---------------------------------------- Declaration Ammo Test ----------------------------------------------------*/

void Grenade(){

if(bBOM == false){
bOMGila1 = TestPacth(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo-0x27);
bOMGila2 = TestPacth(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo-0x10);
bOMGila3 = TestPacth(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo-0xC);
bOMGila4 = TestPacth(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo-0x8);
bOMGila5 = TestPacth(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo-0x4);
bOMGila6 = TestPacth(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo);

}
if(BomKiller==0){
bBOM = false;
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo-0x27, bOMGila1);
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo-0x10, bOMGila2);
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo-0xC, bOMGila3);
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo-0x8, bOMGila4);
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo-0x4, bOMGila5);
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo, bOMGila6);

}
if(BomKiller == 1){
FastBom() ;
BomberMan();
BrustBomb=1;
bBOM = true;
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo-0x27, bOMGila1);
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo-0x10, bOMGila2);
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo-0xC, bOMGila3);
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo-0x8, bOMGila4);
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo-0x4, bOMGila5);
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, ResultPTRCaclAmmo, bOMGila6);
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectA, 0x00);
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectB, 0x00);
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectC, 0x00); 
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectD, 0x00); 
PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectA-0x10, 0x00);

}
}
void _stdcall sPisauw()
{
	if(GetBattleState())
	{
		if(*(PBYTE)ResultBaseAmmo2 > NULL)
		{
			if (*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x544) + 0x40) == 2)//primary ==0 ) //k400 ==3)//smok++ ==4)
			{
				*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30) + 0x30) + 0x58) = 0;
			}
		}
	}
}
void FastPisau() {
DWORD mBase = (DWORD)GetModuleHandleA	(PointBlankSTR8);
c_WeaponIndex_B(mBase + ResultBaseAmmo,0x544,0x24, 0x30,0x67,0x65); 
//c_WeaponIndex_B(mBase + ResultBaseAmmo,0x544,0x24, 0x30,0x67,0x41);
} 
void KnifeGila(){

if(bpeso == false){

PisauGila6 = TestPacth(ResultBaseAmmo2, ResultPTRAmmo, 0x24, 0xC9C);

}
if(PesoEdan==0){
bpeso = false;

PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x24, 0xC9C, PisauGila6);
}
if(PesoEdan == 1){
//FastPisau() ;
//sPisauw();
bpeso = true;

PacthWeapon(ResultBaseAmmo2, ResultPTRAmmo, 0x24, 0xC9C, PisauGila6);

}
}


