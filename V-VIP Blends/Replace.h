int SecondaryBro =0;
DWORD WINAPI SecondariGeng(LPVOID param){
Nay_Item:
//--------------------------------------------------------------------> HK-69
if (SecondaryBro)
{
if(R_Secoandary == 1){
unsigned long PtrRB = *(LPBOOL)(ResultBasePlayer2);
CTeam* GetSlot = (CTeam*)(PtrRB + P_BaseTEAM);{
MakePoint(ResultBasePlayer2, 0x2817C + (GetSlot->iTeam * 0x158), 0x23D2902A);
}}
}
goto Nay_Item;
}
//---------------------------------------------------------------------------