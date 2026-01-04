int Flood = NFCZ;
bool Keproxxx = false;
bool DinoSpam = false;

void FloodKickPlayer(int IndexPlayer)
{
Sleep(100);
if(DinoSpam == false)
{

DWORD PTR_Caller = (DWORD)(ResultFloodKick);
DWORD BaseECX = *(DWORD*)(ResultBasePlayer2);
BYTE pKick[15];
*(BYTE*)(pKick) = IndexPlayer;
DWORD Definition = (DWORD)pKick;
DWORD ReDefinition = (DWORD)pKick + 0x4;
Sleep(5);
__asm
{
push 0x01
push 0x01
push 0x01
push [ReDefinition]
push [Definition]
push 0xA0
mov ecx, [BaseECX]
call ResultSetEvent
}
Sleep(100);
Keproxxx = true;
}}
DWORD WINAPI ThreadFloodVK() //pemanggil void nih 
{
while(1)
{
if(Flood == 1)
{
Sleep(100);
Keproxxx = false;
if(*(PBYTE)ResultBaseAmmo2 > NULL)
{
Sleep(5);
for (int i = 0; i<=15; i++)
{
int MySlot = GetMyCharaIndex(); 
if( i == MySlot)continue; 
FloodKickPlayer(i);
}}}

Sleep(100);
}
return 0;
}