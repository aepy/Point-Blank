//====================== Ghost Hide  =====================//
DWORD Ghoster;
bool bGhost = false;
void GhostHide()
{
	DWORD AdrBaseAmoo = OFS_Ammo + (DWORD)GetModuleHandleA(PointBlankSTR4);
	DWORD pBase = (DWORD)GetModuleHandleA(PointBlankSTR4);
	DWORD PtrAdr = *(PDWORD)(pBase + ResultBasePlayer);
	DWORD PtrHP  = *(PDWORD)(pBase + ResultBaseHealth);
	CTeam* GetSlot	= (CTeam*)(PtrAdr + OFS_Team);
	CHealth* GetHealth = (CHealth*)((PtrHP + 0x264) + GetSlot->iTeam * 0x24);
	if(*(PBYTE)(OFS_Player+0x400000)> 0x01){
	if(bGhost == false){
	Ghoster = Read( OFS_Health+0x400000, 0x260 + GetSlot->iTeam * 0x24);
	}}
	if(Zombie==0){
	bGhost = false;
	_patchPTRZ( OFS_Health+0x400000, 0x260 + GetSlot->iTeam * 0x24, Ghoster);
    }
	if(*(PBYTE)AdrBaseAmoo > 0x01){
	if(GetHealth->CurHP > 0){
	if(GetBattleState1()){
	if(Zombie==1){
	KillMySelf();
	bGhost = true;
	_patchPTRZ( OFS_Health+0x400000, 0x260 + GetSlot->iTeam * 0x24, Ghoster-1);
	}}
	if(GetHealth->CurHP < 0){
	_patchPTRZ( OFS_Health+0x400000, 0x260 + GetSlot->iTeam * 0x24, Ghoster);
	}}}}
