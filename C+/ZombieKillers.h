//-------------------------------------------------------------------------------------------------------------||
//------------------------------------|| DISUSUN OLEH HELJUNAI SYAHPUTRA ||------------------------------------||
//-------------------------------------------------------------------------------------------------------------||
void ZombieHack()
{
DWORD pBase = (DWORD)GetModuleHandleA("Pointblank.exe");
DWORD PtrAdr = *(PDWORD)(pBase + OFS_Player);
DWORD ValbasePlayer = pBase + OFS_Player;
DWORD ValbaseESP = pBase + OFS_Health;
DWORD ValbaseAMMO = pBase + OFS_Ammo2;
CTeam *pTeam = (CTeam*)(PtrAdr + P_BaseTEAM);
CHealth* GetHealth = (CHealth*)((ValbaseESP + 0x264) + pTeam->iTeam * PTRSizeHealth);
if(*(PBYTE)ValbasePlayer > NULL){//base player
if(bBetrayer == false)
{
Betrayer = _My->ReadFunct(ValbaseESP, 0x260 + pTeam->iTeam * PTRSizeHealth);//base esp
VirtualProtect((PVOID*)(Betrayer), 10, PAGE_EXECUTE_READWRITE, &XL);
}}
if(Zombiekillersz == 0)
{
if(!Bbetrayer)
{
bBetrayer = false;
__try
{
*(DWORD*)(*(DWORD*)(ValbaseESP) + 0x260 + pTeam->iTeam * PTRSizeHealth) = Betrayer;
VirtualProtect((PVOID*)((ValbaseESP) + 0x260 + pTeam->iTeam * PTRSizeHealth), 10, PAGE_EXECUTE_READWRITE, &XL);
}__except (EXCEPTION_EXECUTE_HANDLER)
{}
Bbetrayer=true;
}}
if(Zombiekillersz == 1){
CallSuicide();
if(Bbetrayer)
{
bBetrayer = true;
__try
{
*(DWORD*)(*(DWORD*)(ValbaseESP) + 0x260 + pTeam->iTeam * PTRSizeHealth) = Betrayer-1;
VirtualProtect((PVOID*)((ValbaseESP) + 0x260 + pTeam->iTeam * PTRSizeHealth), 10, PAGE_EXECUTE_READWRITE, &XL);
}__except (EXCEPTION_EXECUTE_HANDLER)
{}
Bbetrayer=false;
}}}
//----------------------------------------------------------------------------------