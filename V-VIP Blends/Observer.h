//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
#include <windows.h>

DWORD CGameContextPointer(void) {	
	
	unsigned long dwBase = *(DWORD*)OFS_Player2;
		return dwBase;
}
DWORD GetBasePlayerHealth(void) {	
	
	unsigned long dwBase2 = *(DWORD*)OFS_Health2;
		return dwBase2;
}
//=========================================================================//
class CLog; 
class CLog
{
public:
BYTE iLog;
};

class CKill;
class CKill
{
public:
BYTE bKill;
char _0001[1];
BYTE bDead;
char _0003[1];
};
struct TeamScore
{
public:
WORD  TScoreRed;
WORD  TScoreBlue;
};
//=========================================================================//
CLog		*pPing(UINT i)	
{
return (CLog*)((CGameContextPointer() + OFS_PING) + i * 1);
}

CKill		*pKill(UINT i)	
{
return (CKill*)((CGameContextPointer() + OFS_KILL) + i * 4);
}

CNames		*oNames(UINT i)	
{
return (CNames*)((CGameContextPointer() + OFS_NAMES) + i * NAMESIZE);
}

CHealth		*oHealth(UINT i)	
{
return (CHealth*)((GetBasePlayerHealth() + OFS_HEALTH) + i * HPSIZE);
}
//=========================================================================//
void DrawString(int x, int y, DWORD color, const char *fmt, ...)
{
	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	
	fName->DrawText(NULL, buf, -1, &FontPos, DT_LEFT | DT_WORDBREAK, color);
}
//=========================================================================//
void PingServer(int x, int y, float Health, IDirect3DDevice9* pDevice)
{
	if( !pDevice )
		return;
	for (int index = 0; index <= (Health-1); index++)
	{
	D3DCOLOR HPcol = GREEN;
	if (Health == 3 )HPcol = ORANGE;
	if (Health == 2 )HPcol = ORANGE;
	if (Health == 1) HPcol = RED;
	DxESP->FillRGB(x + (index*4),y,3,14,HPcol,pDevice);
	}
}
//=========================================================================//
void HealthbarServer(IDirect3DDevice9* pDevice, int x, int y, float Health)
{
	if( !pDevice )
		return;
	float Long = (Health);
	DxESP->FillRGB(x,y,Health,14,TeamColor,pDevice );
}
//=========================================================================//
void DrawBoxServer( int x, int y, IDirect3DDevice9* pDevice )
{
	if( !pDevice )
		return;
    DxESP->DrawBoxz( x, y, 147, 18,BLACK, TeamColor, pDevice );
}
//=========================================================================//
void DrawBoxTeam( int x, int y, IDirect3DDevice9* pDevice )
{
	if( !pDevice )
		return;
    DxESP->DrawBoxz( x, y,120, 15,TeamColor, BLACK, pDevice );
}
//=========================================================================//
void DrawString2(int x, int y, DWORD color, const char *fmt, ...)
{
	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	
	Title->DrawText(NULL, buf, -1, &FontPos,  DT_LEFT | DT_WORDBREAK, color);
}

//====================== DEKLARASI OBSERVER =====================//
void RadarBM(LPDIRECT3DDEVICE9 pDevice)
{
if(GetBattleState1()){
if(ESPObserver==1)
{
int ServerX1=750;
int ServerY1=480;
int ServerX2=100;
int ServerY2=480;
unsigned long dwBase2	= *(DWORD*)(OFS_Health2);
unsigned long dwBase	= *(DWORD*)(OFS_Player2);
TeamScore	*TeamzScore	= (TeamScore*)((dwBase + OFS_TEAMSCORE));
for (int i = 0; i <= 16; i++)
{
int iTeam	= DxESP->GetTeam(i);
if(*(PBYTE)OFS_Ammo2 > 1){
if (iTeam == 1)
{
TeamColor = dBlue;

DrawBoxServer((int)ServerX1 + 10,(int)ServerY1+(10*i),pDevice);
HealthbarServer(pDevice,(int)ServerX1+36,(int)(ServerY1+2)+(10*i),oHealth(i)->CurHP);
PingServer((int)ServerX1 + 137,(int)(ServerY1+2)+(10*i),pPing(i)->iLog, pDevice);
DrawString(ServerX1 + 16,(ServerY1+2)+(10*i),dWhite,"%d|%d    %s",pKill(i)->bKill,pKill(i)->bDead,oNames(i)->szNames);
DrawString2(ServerX1+10,460,dBlue,"[BLUE TEAM : %d]",TeamzScore->TScoreBlue);
DrawString2(ServerX1+10,460,BLACK,"[BLUE TEAM : %d]",TeamzScore->TScoreBlue);		
}

if (iTeam == 2)
{
TeamColor = dRed;

DrawBoxServer((int)ServerX2 + 10,(int)(ServerY2+9)+(10*i),pDevice);
HealthbarServer(pDevice, (int)ServerX2+36 ,(int)((ServerY2+2)+9)+(10*i),oHealth(i)->CurHP);
PingServer((int)ServerX2 + 137,(int)((ServerY2+2)+9)+(10*i),pPing(i)->iLog, pDevice);	
DrawString(ServerX2 + 16,((ServerY2+2)+9)+(10*i),dWhite,"%d|%d    %s",pKill(i)->bKill,pKill(i)->bDead,oNames(i)->szNames);						
DrawString2(ServerX2+10,460,dRed,"[RED TEAM : %d]",TeamzScore->TScoreRed);	
DrawString2(ServerX2+10,460,BLACK,"[RED TEAM : %d]",TeamzScore->TScoreRed);					
}
}
}
}
}}