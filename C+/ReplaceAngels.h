//-----------------------------------------------------------------------------------------> Replace Granade
DWORD WINAPI NayzReplace(LPVOID param){
Nay_Item:
//--------------------------------------------------------------------> Soccer Granade
if(Rep_Item)
{
if(Rep_Item == 1){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + P_BaseTEAM);{
MakePoint(ResultBasePlayer2, 0x28188 + (GetSlot->iTeam * 0x158), 0x35E20D79);
}}
//--------------------------------------------------------------------> Candy Granade
if(Rep_Item == 2){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + P_BaseTEAM);{
MakePoint(ResultBasePlayer2, 0x28188 + (GetSlot->iTeam * 0x158), 0x35E20D6C);
}}
//--------------------------------------------------------------------> Lantern Grenade
if(Rep_Item == 3){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + P_BaseTEAM);{
MakePoint(ResultBasePlayer2, 0x28188 + (GetSlot->iTeam * 0x158), 0x35E20D6F);
}}}
//-----------------------------------------------------------------------------------------> Replace Launcher 
if(R_Launcher)
{
//--------------------------------------------------------------------> Famas Launcher 
if(R_Launcher == 1){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + P_BaseTEAM);{
MakePoint(ResultBasePlayer2, 0x28178 + (GetSlot->iTeam * 0x158), 0x5F5ECEC);
}}
//--------------------------------------------------------------------> K-201 Exit
if(R_Launcher == 2){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + P_BaseTEAM);{
MakePoint(ResultBasePlayer2, 0x28178 + (GetSlot->iTeam * 0x158), 0x5F5ECC3);
}}
//--------------------------------------------------------------------> AK 47 FC
if(R_Launcher == 3){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + P_BaseTEAM);{
MakePoint(ResultBasePlayer2, 0x28178 + (GetSlot->iTeam * 0x158), 0x5F5ECF2);
}}
//--------------------------------------------------------------------> AK Sopmod R
if(R_Launcher == 4){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + P_BaseTEAM);{
MakePoint(ResultBasePlayer2, 0x28178 + (GetSlot->iTeam * 0x158), 0x5F5ECFC);
}}
//--------------------------------------------------------------------> SCAR D
if(R_Launcher == 5){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + P_BaseTEAM);{
MakePoint(ResultBasePlayer2, 0x28178 + (GetSlot->iTeam * 0x158), 0x5F5ED18);
}}
//--------------------------------------------------------------------> RPG-7
if(R_Launcher == 6){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + P_BaseTEAM);{
MakePoint(ResultBasePlayer2, 0x28178 + (GetSlot->iTeam * 0x158), 0x5F61F82);
}}}
//--------------------------------------------------------------------
goto Nay_Item;
}