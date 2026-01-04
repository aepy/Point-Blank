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
}
}
}
}
}
}
void WritePTR(DWORD Base,DWORD PTR1,DWORD PTR2,DWORD PTR3,DWORD Byte){
DWORD Temp =0;
if (!IsBadReadPtr((PDWORD)Base,4)){Temp=*(PDWORD)((DWORD)(Base))+PTR1;
if (!IsBadReadPtr((PDWORD)Temp,4)){Temp=*(PDWORD)((DWORD)(Temp))+PTR2;
if (!IsBadReadPtr((PDWORD)Temp,4)){Temp=*(PDWORD)((DWORD)(Temp))+PTR3;
if (!IsBadReadPtr((PDWORD)Temp,4)){*(PDWORD)Temp=Byte;}}}
}
}
DWORD AmmoHK691,AmmoHK692,AmmoHK693,AmmoHK694,AmmoHK695,AmmoHK696;
DWORD AmmoRPG1,AmmoRPG2,AmmoRPG3,AmmoRPG4,AmmoRPG5,AmmoRPG6,AmmoPrymariFC,AmmoSMOKE,AmmoBOMB;
DWORD AmmoBOMB1,AmmoBOMB2,AmmoBOMB3,AmmoBOMB4,AmmoBOMB5,AmmoBOMB6;
DWORD RecordPTR(DWORD Base,DWORD PTR1,DWORD PTR2,DWORD PTR3){ 
DWORD RPTR1,RPTR2,RPTR3;
if (!IsBadReadPtr((PDWORD)Base,4)){RPTR1=*(PDWORD)((DWORD)(Base))+PTR1;
if (!IsBadReadPtr((PDWORD)RPTR1,4)){RPTR2=*(PDWORD)((DWORD)(RPTR1))+PTR2;
if (!IsBadReadPtr((PDWORD)RPTR2,4)){RPTR3=*(PDWORD)((DWORD)(RPTR2))+PTR3;
if (!IsBadReadPtr((PDWORD)RPTR3,4)){return *(PDWORD)RPTR3;}}}}
return RPTR3;}
bool RCHHK69,RCHRPG,RCHFC,RCHSMOKE,RCHBOMB=false;
bool ReadAmmo = false; 
void _fastcall MenuX_SmartAmmoX(LPDIRECT3DDEVICE9 pDevice)
{
	
		//if(SmartAmmoX==1)
		//{
DWORD pBase = (DWORD)GetModuleHandleA("PointBlank.exe"); 
DWORD AdrBaseAmoo = pBase + ResultBasePlayer2-0x38;// 
if(*(PBYTE)AdrBaseAmoo > 0x01) { 
if(SmartAmmoX==1) { 
if(ReadAmmo == false){ 
GetWeaponHack(ResultBaseAmmo2, 0x544, 0x1C, 0xCA8, 1); 
GetWeaponHack(ResultBaseAmmo2, 0x544, 0x20, 0xCA8, 2); 
ReadAmmo=true; } 
if(ReadAmmo == true){ 
GoWeaponHack(ResultBaseAmmo2, 0x544, 0x1C, 0xCA8, wepon); 
GoWeaponHack(ResultBaseAmmo2, 0x544, 0x20, 0xCA8, pistol); 
}}}}
void FastReaload() {
DWORD mBase = (DWORD)GetModuleHandleA	("PointBlank.exe");
if(Reload){ 
c_WeaponIndex_B(mBase + ResultBaseAmmo,ResultPTRAmmo,0x1C, 0x30,0x67,0x41);
c_WeaponIndex_B(mBase + ResultBaseAmmo,ResultPTRAmmo,0x20, 0x30,0x67,0x41); 
} 
}
void BypassProtect1()
{
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRProtectA, 0x00); // NeoPTRProtectA
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRProtectB, 0x00); // NeoPTRProtectB
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRProtectC, 0x00); // NeoPTRProtectC
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRProtectA-0x10, 0x00); // NeoPTRProtectA
}

void BypassProtect1_A()
{
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRProtectA, 0x00); // NeoPTRProtectA
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRProtectB, 0x00); // NeoPTRProtectB
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRProtectA-0x10, 0x00); // NeoPTRProtectA
}

void BypassProtect2()
{
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, PTRProtectA, 0x00); // NeoPTRProtectA
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, PTRProtectB, 0x00); // NeoPTRProtectB
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, PTRProtectB+0x4, 0x00); // NeoPTRProtectB
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, PTRProtectC, 0x00); // NeoPTRProtectC
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, PTRProtectD, 0x00); // NeoPTRProtectD
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, PTRProtectA-0x10, 0x00); // NeoPTRProtectA
}



void BypassProtect4()
{
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectA, 0x00); // NeoPTRProtectA
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectB, 0x00); // NeoPTRProtectB
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectC, 0x00); // NeoPTRProtectC
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectD, 0x00); // NeoPTRProtectD
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x28, PTRProtectA-0x10, 0x00); // NeoPTRProtectA
}

void Reaload() {
DWORD mBase = (DWORD)GetModuleHandleA	("PointBlank.exe");
c_WeaponIndex_B(mBase + ResultBaseAmmo,0x544,0x1C, 0x30,0x67,0x41);
} 
void RapidFire(){
	 
__try{ 
					if (*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x544)+0x38)==1){
						*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30)+0x5D4)=0;
						*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;} 
					if (*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x544)+0x38)==0){ 
						*(DWORD*)(*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x30)+0x5D4)=0; 
						*(DWORD*)(*(DWORD*)(ResultBaseAmmo2)+0x504)=0;} 
				}__except (EXCEPTION_EXECUTE_HANDLER )
					{
					}
	}

void AmmoHK69()
{
	if(AmmoHK69A==1)
	{
		SmartAmmoX=0;
		RapidFire();
		Reload =0;
		if(RCHHK69==false)
		{
			AmmoHK691  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0xC81);
			AmmoHK692  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0xC98);
			AmmoHK693  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0xC9C);
			AmmoHK694  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0xCA0);
			AmmoHK695  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0xCA4);
			AmmoHK696  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0xCA8); // NeoPTRAmmoB
			RCHHK69=true;
		}
		else 
			if(RCHHK69==true)
			{
				BypassProtect2();
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0xC81, AmmoHK691);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0xC98, AmmoHK692);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0xC9C, AmmoHK693);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0xCA0, AmmoHK694);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0xCA4, AmmoHK695);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, 0xCA8, AmmoHK696); // NeoPTRAmmoB
				BypassProtect2();
				Sleep(25);
		}
	}
	else
		RCHHK69=false;
}
/*---------------------------------------- Declaration Ammo Rocket ----------------------------------------------------*/
void AmmoRocket()
{
	if(AmmoRPG==1)
	{ 
		SmartAmmoX=0;
		Reload =0;
		Reaload();
		RapidFire();
		if(RCHRPG==false)
		{
			AmmoRPG1  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0xC81);
			AmmoRPG2  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0xC98);
			AmmoRPG3  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0xC9C);
			AmmoRPG4  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0xCA0);
			AmmoRPG5  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0xCA4);
			AmmoRPG6  = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0xCA8); // NeoPTRAmmoB
			RCHRPG=true;
		}
		else 
			if(RCHRPG==true)
			{
				BypassProtect1_A();
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0xC81, AmmoRPG1);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0xC98, AmmoRPG2);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0xC9C, AmmoRPG3);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0xCA0, AmmoRPG4);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0xCA4, AmmoRPG5);
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, 0xCA8, AmmoRPG6); // NeoPTRAmmoB
				BypassProtect1_A();
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
		SmartAmmoX=0;
		Reload =0;
		RapidFire();
		if(RCHFC == false)
		{
			AmmoPrymariFC = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRAmmoC); // NeoPTRAmmoC
			RCHFC = true;
		}
		else 
			if(RCHFC==true)
			{
				
				BypassProtect1();
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, PTRAmmoC, AmmoPrymariFC); // NeoPTRAmmoC
				BypassProtect1();
				Sleep(50);
			}
	}
	else
		RCHFC=false;
}
