//=============================================== UNLIMITED AMMO PISTOL ==================================================//
DWORD StartRouneAmmo= NULL;
bool bAmmo=false;
void AmmoReloads()
{
	if(bAmmo == false){
			StartRouneAmmo = _My->GetAmmoIndex(c_pPelorReload, PTRWeaponSize2Ammo, PTRSizeHealth, SizeValAmmo);
	}
	if(DepositAmmo == 0){
		bAmmo = false;
		_My->gEtWeapon_IndexA( c_pPelorReload, PTRWeaponSize2Ammo, PTRSizeHealth, SizeValAmmo, StartRouneAmmo);
    }
	if(DepositAmmo == 1){
		bAmmo = true;
		_My->gEtWeapon_IndexA( c_pPelorReload, PTRWeaponSize2Ammo, PTRSizeHealth, SizeValAmmo, StartRouneAmmo);
		}}