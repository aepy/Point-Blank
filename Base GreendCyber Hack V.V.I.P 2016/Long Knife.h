#include <windows.h>
void  MakeJMP( BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen )
{
__try {
    DWORD dwOldProtect, dwBkup, dwRelAddr;
    VirtualProtect(pAddress, dwLen, PAGE_EXECUTE_READWRITE, &dwOldProtect);
    dwRelAddr = (DWORD) (dwJumpTo - (DWORD) pAddress) - 5;
    *pAddress = 0xE9;
    *((DWORD *)(pAddress + 0x1)) = dwRelAddr;
    for(DWORD x = 0x5; x < dwLen; x++) *(pAddress + x) = 0x90;
    VirtualProtect(pAddress, dwLen, dwOldProtect, &dwBkup);
    return;
}__except ( EXCEPTION_EXECUTE_HANDLER ) {
	return ;
	}
}
float acr = 2000;
DWORD Retn_Range = OFS_Longknife  + 0x5; //  //0x59927D
__declspec(naked) void Range_On()
{
	_asm
	{
		fld dword ptr [acr]
		mov esp,ebp
			jmp [Retn_Range]
	}
}

__declspec(naked) void Range_Off()
{
	_asm
	{
		fld dword ptr[ebp-04]
		mov esp,ebp
			jmp [Retn_Range]
	}
}


float RcH = 2000;
DWORD Rch_Range = OFS_Longknife  + 0x5;
__declspec(naked) void Rch_On()
{
	_asm
	{
		fld dword ptr [RcH]
		mov esp,ebp
			jmp [Rch_Range]
	}
}

__declspec(naked) void Rch_Off()
{
	_asm
	{
		fld dword ptr[ebp-04]
		mov esp,ebp
			jmp [Rch_Range]
	}
}

DWORD RCHhack(DWORD dwPtr){ 
	__try{
	DWORD C; 
	if(IsBadReadPtr((PDWORD)(dwPtr),4)==0)
	{ 
		C=(*(DWORD*)(dwPtr)); 
		if(IsBadReadPtr((PDWORD)(C),4)==0)
		{ 
			return C; 
		}
		else return 0;
	} 
	else 
		return 0;
	}__except ( EXCEPTION_EXECUTE_HANDLER ) {return 0;}
}

/*---------------------------------------- Declaration _WriteBasePB ----------------------------------------------------*/
DWORD RCHkru(DWORD dwPtr)
{ 
	__try{
	DWORD C; 
	if(IsBadReadPtr((PDWORD)(dwPtr),4)==0)
	{ 
		C=((DWORD)dwPtr); 
		if(IsBadReadPtr((PDWORD)(C),4)==0)
		{ 
			return C; 
		} 
		else return 0;
	} 
	else return 0;
	}__except ( EXCEPTION_EXECUTE_HANDLER ) {return 0;}
}



/*---------------------------------------- Declaration _SetBaseWeaponKiller ----------------------------------------------------*/
DWORD RCHbrew(DWORD dwPtr, DWORD dwOfs, DWORD dwOfs2)
{ 
	__try{
	DWORD C; 
	if(IsBadReadPtr((PDWORD)(dwPtr),4)==0)
	{ 
		C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
		if(IsBadReadPtr((PDWORD)(C),4)==0)
		{ 
			C=*(PDWORD)((DWORD)(C))+dwOfs2;
			if(IsBadReadPtr((PDWORD)(C),4)==0)
			{ 
				return *(PDWORD)C; 
			} 
			else return 0;
		}
		else return 0;
	} 
	else return 0;
	}__except ( EXCEPTION_EXECUTE_HANDLER ) 
	{
		return 0;}
}
DWORD Kampretloh(UINT i)
{
__try
{
D3DXVECTOR3	vBone, vLocal;
int BoneIndexSelector;
switch(Target){
case 0:
BoneIndexSelector = 7.7;
break;
case 1:
BoneIndexSelector = 5;
break;
}
dwBasett   = RCHbrew(ResultBaseAmmo2, ResultPTRAmmo , 0x24);
baseDoLineColly = RCHkru  (ResultDoLine);
getVCPosa(&vLocal,0,0);
vBone = GetUserBonePos2(i,BoneIndexSelector);
if (dwBasett!=NULL)
return ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
}__except ( EXCEPTION_EXECUTE_HANDLER )
{Sleep(0);
	
}
return 0;
}
//----------------------------------------------------------------------------------
DWORD KampretHit(UINT i)
{
__try
{
D3DXVECTOR3	vEnemy;
dwBasett   = RCHbrew(ResultBaseAmmo2, ResultPTRAmmo, 0x24);
dwBasetttt   = RCHhack(ResultBaseAmmo2);
baseALEXCallHitEvent = RCHkru(ResultEventFire);
getVCPosa(&vEnemy,0,0);
if (dwBasett!=NULL)

 return  ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
}__except ( EXCEPTION_EXECUTE_HANDLER
) 
{
Sleep(0);
}
	return(0);
}

//----------------------------------------------------------------------------------

void KampretLine()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(IsAlivedf(i)){
KampretHit(i);
Kampretloh(i);
KampretHit(i);
}}}
DWORD Kampretloh12(UINT i)
{
__try
{
D3DXVECTOR3	vBone, vLocal;
int BoneIndexSelector;
switch(Target){
case 0:
BoneIndexSelector = 7.7;
break;
case 1:
BoneIndexSelector = 5;
break;
}
dwBasett   = RCHbrew(ResultBaseAmmo2, ResultPTRAmmo , 0x1C);
baseDoLineColly = RCHkru  (ResultDoLine);
getVCPosa(&vLocal,0,0);
vBone = GetUserBonePos2(i,BoneIndexSelector);
if (dwBasett!=NULL)
return ((DWORD (__thiscall *)(DWORD, D3DXVECTOR3*, D3DXVECTOR3*, DWORD))baseDoLineColly)(dwBasett, &vLocal, &vBone, GetTeam1(i));
}__except ( EXCEPTION_EXECUTE_HANDLER )
{Sleep(0);
	
}
return 0;
}
//----------------------------------------------------------------------------------
DWORD KampretHit12(UINT i)
{
__try
{
D3DXVECTOR3	vEnemy;
dwBasett   = RCHbrew(ResultBaseAmmo2, ResultPTRAmmo, 0x24);
dwBasetttt   = RCHhack(ResultBaseAmmo2);
baseALEXCallHitEvent = RCHkru(ResultEventFire);
getVCPosa(&vEnemy,0,0);
if (dwBasett!=NULL)

 return  ((DWORD (__thiscall *)(DWORD, DWORD, D3DXVECTOR3*, DWORD))baseALEXCallHitEvent)(dwBasett, dwBasetttt, &vEnemy, dwBasett);
}__except ( EXCEPTION_EXECUTE_HANDLER
) 
{
Sleep(0);
}
	return(0);
}

//----------------------------------------------------------------------------------

void KampretLine12()
{
for (int i = 0; i < 16; i++)
{
if (!GetMyCharaIndexed (i))continue;
if(GetTeam1(GetMyCharaIndexed (i)) == GetTeam1(i))continue;
if(IsAlivedf(i)){
KampretHit12(i);
Kampretloh12(i);
KampretHit12(i);
}}}

//----------------------------------------------------------------------------------

void RCHknife()
{

	if(PesoEdan == 1){
		MakeJMP((PBYTE)OFS_Longknife , (DWORD)Range_On, 5); 
		MemWrite((void *)(dwPBExe + ResultWallShot),(int*)(PBYTE)"\x90\x90",2);

KampretLine();
	}else{
		MakeJMP((PBYTE)OFS_Longknife , (DWORD)Range_Off, 5);
		MemWrite((void *)(dwPBExe + ResultWallShot),(int*)(PBYTE)"\x75\x1F",2);

	}
}
void KnifeKillers()
{

	if(AutoFire == 1){
		MakeJMP((PBYTE)OFS_Longknife , (DWORD)Rch_On, 5); 
	//	MemWrite((void *)(dwPBExe + ResultWallShot),(int*)(PBYTE)"\x90\x90",2);

KampretLine12();
	}else{
		MakeJMP((PBYTE)OFS_Longknife , (DWORD)Rch_Off, 5);
	//	MemWrite((void *)(dwPBExe + ResultWallShot),(int*)(PBYTE)"\x75\x1F",2);

	}
}