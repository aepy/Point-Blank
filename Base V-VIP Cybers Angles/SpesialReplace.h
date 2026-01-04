//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
DWORD WINAPI ReplaceSecondary(LPVOID param)
{
ZRCReplaceON:
if (Secondary){
if ( Secondary==1 ) { 
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM);{ 
MakePoint(OFS_Player2, 0x28020 + 0x04 + (GetSlot->iTeam * 0x158), 0x23D2902A);// HK 69 
}}
}
Sleep(0);
goto ZRCReplaceON;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
DWORD WINAPI ReplaceRPG(LPVOID param)
{
ZRCReplaceON:
if (RPG){
if ( RPG==1 ) { 
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM);{ 
MakePoint(OFS_Player2, 0x28020 + (GetSlot->iTeam * 0x158), 0x5F61F82);// RPG7
}}
}
Sleep(0);
goto ZRCReplaceON;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
DWORD WINAPI ReplaceSmoke(LPVOID param)
{
ZRCReplaceON:
if(WPSmoke)
{
if(WPSmoke == 1){
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM);{
MakePoint(OFS_Player2, 0x28020 + 0x10 + (GetSlot->iTeam * 0x158), 0x35E20D64);// WPSmoke D
}}
////---------------------------------------------------------------
if(WPSmoke == 2){
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM);{
MakePoint(OFS_Player2, 0x28020 + 0x10 + (GetSlot->iTeam * 0x158), 0x35E20D61);//Bread Granade
}}
////---------------------------------------------------------------
if(WPSmoke == 3){
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM);{
MakePoint(OFS_Player2, 0x28020 + 0x10 + (GetSlot->iTeam * 0x158), 0x35E20D6C);//Candy Granade
}}
////---------------------------------------------------------------
if(WPSmoke == 4){
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM);{
MakePoint(OFS_Player2, 0x28020 + 0x10 + (GetSlot->iTeam * 0x158), 0x35E20D6F);//Lantern Granade
}}
////---------------------------------------------------------------
if(WPSmoke == 5){
unsigned long PtrAdrkla = *(LPBOOL)(OFS_Player2); 
CTeam* GetSlot = (CTeam*)(PtrAdrkla + OFS_TEAM);{
MakePoint(OFS_Player2, 0x28020 + 0x10 + (GetSlot->iTeam * 0x158), 0x2FDCEA1E); // C-5 D
}}
////---------------------------------------------------------------
}
Sleep(0);
goto ZRCReplaceON;
}