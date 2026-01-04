bool XFC=false;
bool XSMOKE=false;
bool XBOMB=false;
bool XPISTOL=false;
DWORD AmmoPrymariFC,AmmoSMOKE,AmmoBOMB,AmmoPistol;
void BypassPrimary()
{
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, NeoPTRProtectA, 0x00); // NeoPTRProtectA
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, NeoPTRProtectB, 0x00); // NeoPTRProtectB
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, NeoPTRProtectC, 0x00); // NeoPTRProtectC
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, NeoPTRProtectA-0x10, 0x00); // NeoPTRProtectA
}
void BypassSecondary()
{
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, NeoPTRProtectA, 0x00); // NeoPTRProtectA
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, NeoPTRProtectB, 0x00); // NeoPTRProtectB
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, NeoPTRProtectC, 0x00); // NeoPTRProtectC
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, NeoPTRProtectA-0x10, 0x00); // NeoPTRProtectA
}
void BypassBomb()
{
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x28, NeoPTRProtectA, 0x00); // NeoPTRProtectA
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x28, NeoPTRProtectB, 0x00); // NeoPTRProtectB
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x28, NeoPTRProtectC, 0x00); // NeoPTRProtectC
	WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x28, NeoPTRProtectA-0x10, 0x00); // NeoPTRProtectA
}
//------------------------------------------------------------------------------
void AmmoLauncher()
{ 

	if(AmmoLC==1)
	{
		if(XFC == false)
		{ 
			AmmoPrymariFC = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, NeoPTRAmmoC); // NeoPTRAmmoC
			XFC = true;
		}
		else 
			if(XFC==true)
			{ 
				BypassPrimary();
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x1C, NeoPTRAmmoC, AmmoPrymariFC); // NeoPTRAmmoC
				BypassPrimary();	
				Sleep(25);
			}
	}
	else
		XFC=false; 
}
void AmmoSecondary()
{ 

	if(AmmoLC==1)
	{
		if(XPISTOL == false)
		{ 
			AmmoPistol = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, NeoPTRAmmoC); // NeoPTRAmmoC
			XPISTOL= true;
		}
		else 
			if(XPISTOL==true)
			{ 
				BypassSecondary();
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x20, NeoPTRAmmoC, AmmoPistol); // NeoPTRAmmoC
				BypassSecondary();	
				Sleep(25);
			}
	}
	else
		XPISTOL=false; 
}

/*---------------------------------------- Declaration Ammo Test ----------------------------------------------------*/
void AmmoGrenade()
{
	if(AmmoBomb==1)
	{
		if(XBOMB==false)
		{
			AmmoBOMB = RecordPTR(ResultBaseAmmo2, ResultPTRAmmo, 0x28, NeoPTRAmmoA); // NeoPTRAmmoA
			XBOMB=true;
		}
		else 
			if(XBOMB==true)
			{
				BypassBomb();
				WritePTR(ResultBaseAmmo2, ResultPTRAmmo, 0x28, NeoPTRAmmoA, AmmoBOMB); // NeoPTRAmmoA
				BypassBomb();
				Sleep(25);
			}
	}
	else
		XBOMB=false;
}

