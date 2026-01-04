/*File.h D3D9 PBHacks Last Edit By Fatur Rezo*/
#include "cClass.h"
#include "cColor.h"

/*-------------------------------------------------------------------------------------------------------------------*/
#define hD3D "i3GfxDx.dll"
DWORD AdressAndByte,GetEngine,Calculate = NULL;

/*-------------------------------------------------------------------------------------------------------------------*/
D3DVIEWPORT9 Viewport;
D3DVIEWPORT9 g_ViewPort;
LPDIRECT3DDEVICE9 npDevice; 
LPDIRECT3DDEVICE9 pDevice; 
LPDIRECT3DDEVICE9 pGDevice = NULL;
LPD3DXFONT fName	= NULL;
DWORD TeamColor;
D3DVECTOR Player;
D3DVECTOR HeadPos;
D3DVECTOR PlayerScaled;
D3DVECTOR HeadScaled;
D3DVECTOR BonePos;
BOOL Create;
bool bHooIsRedTeam	= false;
bool SetPlayerPos	= false;
int Transperency = 255;

/*-------------------------------------------------------------------------------------------------------------------*/
D3DXVECTOR3 vStart,vEnd;
D3DXVECTOR3 vvStart,vvEnd;
D3DXVECTOR3 vStart2,vEnd2;
D3DXVECTOR3 vvStart2,vvEnd2;
D3DXVECTOR3 vStart3,vEnd3;
D3DXVECTOR3 vvStart3,vvEnd3;
D3DXVECTOR3 vStart4,vEnd4;
D3DXVECTOR3 vvStart4,vvEnd4;
D3DXVECTOR3 vStart5,vEnd5;
D3DXVECTOR3 vvStart5,vvEnd5;
D3DXVECTOR3 vStart6,vEnd6;
D3DXVECTOR3 vvStart6,vvEnd6;
D3DXVECTOR3 vStart7,vEnd7;
D3DXVECTOR3 vvStart7,vvEnd7;
D3DXVECTOR3 vStart8,vEnd8;
D3DXVECTOR3 vvStart8,vvEnd8;
D3DXVECTOR3 vStart9,vEnd9;
D3DXVECTOR3 vvStart9,vvEnd9;
D3DXVECTOR3 vStart10,vEnd10;
D3DXVECTOR3 vvStart10,vvEnd10;
BYTE Byte [40];

/*-------------------------------------------------------------------------------------------------------------------*/
int GetTeam(int JONES){
	for(int i = 0; i<=15; i+=2)
		if( i == JONES ) return 1;
	for(int i = 1; i<=15; i+=2)
		if( i == JONES ) return 2;
	return 0;
}
BYTE GetUserLife(int iSlot)
{
    DWORD g_pGameContext   = *(DWORD*)ResultBasePlayer2;
    CDeathPlayer *Life = (CDeathPlayer *) (g_pGameContext + ResultBONE);
    return Life->Death[iSlot];
}
/*-------------------------------------------------------------------------------------------------------------------*/
bool GetBattleState() { 
	DWORD BaseG = (DWORD)GetModuleHandleA("PointBlank.exe");
	unsigned long xBase = *(DWORD*)(BaseG + ResultBaseAmmo); 
	if(xBase > NULL){ 
		return true; }
	return false; 
}

/*-------------------------------------------------------------------------------------------------------------------*/
int IsRedTeam(int iSlot)
{
	if(bHooIsRedTeam == true)
	{
		if (iSlot == 0 ||iSlot == 2||iSlot == 4||iSlot == 6||iSlot == 8||iSlot == 10||iSlot == 12||iSlot == 14)return 1;
		else
		if (iSlot == 1 ||iSlot == 3||iSlot == 5||iSlot == 7||iSlot == 9||iSlot == 11||iSlot == 13||iSlot == 15)return 2;
		bHooIsRedTeam = false;
	}
	return 0;
}

/*-------------------------------------------------------------------------------------------------------------------*/
bool IsAlive(int Index){
	unsigned long dwBase2	= *(DWORD*)ResultBaseHealth2;
	CHealth		*Health		= (CHealth*) ((dwBase2 + 0x264) + Index * 0x24);
	if(Health->CurHP > 0.1f)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------------------------------*/
VOID JMPE9(BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen)
{
    DWORD dwOldProtect, dwBkup, dwRelAddr;
    VirtualProtect(pAddress, dwLen, PAGE_EXECUTE_READWRITE, &dwOldProtect);
    dwRelAddr = (DWORD) (dwJumpTo - (DWORD) pAddress) - 5;
    *pAddress = 0xE9;
    *((DWORD *)(pAddress + 0x1)) = dwRelAddr;
    for(DWORD x = 0x5; x < dwLen; x++) *(pAddress + x) = 0x90;
    VirtualProtect(pAddress, dwLen, dwOldProtect, &dwBkup);
    return;
}

/*-------------------------------------------------------------------------------------------------------------------*/
void MemWrite(void *adr, void *byte, int size)
{
	DWORD X;
    VirtualProtect(adr, size, PAGE_EXECUTE_READWRITE, &X);
	memcpy(adr, byte, size);   
    VirtualProtect(adr,size,X,&X);
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD WritePTR(DWORD Base,DWORD PTR1,DWORD Byte){ 
if (!IsBadReadPtr((PDWORD)Base,4)){DWORD RPTR1=*(PDWORD)((DWORD)(Base))+PTR1;
if (!IsBadReadPtr((PDWORD)RPTR1,4)){*(PDWORD)RPTR1=Byte;}}
return 0;}

/*-------------------------------------------------------------------------------------------------------------------*/
int GetMyCharaIndex(){
	unsigned long dwBase	= *(DWORD*)(ResultBasePlayer2);
	CTeam *MyTeam = (CTeam*) ((dwBase + ResultTeam));
	return MyTeam->iTeam;
}

/*-------------------------------------------------------------------------------------------------------------------*/
bool GetUserBone( D3DXVECTOR3 &Out,  int BoneIdx ,int Idx){
	DWORD dwGameBase = *(DWORD*)ResultBaseHealth2;
	if ( dwGameBase ){
		CGameBase* GameBase = (CGameBase*)( *(DWORD*)(dwGameBase + 0x14 + ( 0x4 * Idx ) ) );
		if ( GameBase && GameBase->Bones){
			Out.x = GameBase->Bones->BoneData[ BoneIdx ].BoneMatrix._41;
			Out.y = GameBase->Bones->BoneData[ BoneIdx ].BoneMatrix._42;
			Out.z = GameBase->Bones->BoneData[ BoneIdx ].BoneMatrix._43;
			return true;
		}}
	return false;
}

/*-------------------------------------------------------------------------------------------------------------------*/
bool YoWorlToScreenGa(LPDIRECT3DDEVICE9 pDevice, D3DVECTOR Player,D3DVECTOR &PlayerScaled){
	D3DXVECTOR3 PlayerPos(Player.x,Player.y,Player.z);
	D3DXMATRIX identity;
    D3DXVECTOR3 vScreen;
	pDevice->GetViewport(&Viewport);
	Viewport.X = Viewport.Y = 0;
    Viewport.MinZ     = 0;
    Viewport.MaxZ     = 1;
	D3DXVec3Project(&vScreen, &PlayerPos, &Viewport, &pRC->pRenderData->ProjMatrix, &pRC->pRenderData->ViewMatrix, &pRC->pRenderData->World);
	if (vScreen.z < 1.0f && vScreen.x > 0.0f && vScreen.y > 0.0f && vScreen.x < Viewport.Width && vScreen.y < Viewport.Height){
		PlayerScaled.x = vScreen.x;
		PlayerScaled.y = vScreen.y ;
		PlayerScaled.z = vScreen.z;
		return true; 
	}return false;
}

/*-------------------------------------------------------------------------------------------------------------------*/
void PrivateOnly(void *adr, void *ptr, int size){ 
	DWORD NextProtection;
	VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &NextProtection);
	Sleep(1);
	Sleep(1);
	RtlCopyMemory(adr,ptr,size);
	Sleep(1);
	Sleep(1);
	VirtualProtect(adr,size,NextProtection, &NextProtection);
}
/*-------------------------------------------------------------------------------------------------------------------*/
void Hooked(PDWORD target, PDWORD newfunc){
	DWORD Jmpto=(DWORD)(newfunc)-(DWORD)target-5;
	DWORD a;
	VirtualProtect(target, 8, PAGE_EXECUTE_READWRITE, &a);
	*(PBYTE)(target)=0xE9;
	*(PDWORD)((DWORD)(target)+1)=Jmpto;
	VirtualProtect(target, 8, a, &a);
}

/*-------------------------------------------------------------------------------------------------------------------*/
void PacthWeapone(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, DWORD Value){ 
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)Base,4)==0){
		Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
		if (IsBadReadPtr((PDWORD)Temp,4)==0){
			Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
			if (IsBadReadPtr((PDWORD)Temp,4)==0){
				Temp=*(PDWORD)((DWORD)(Temp))+Ofs3;
				if (IsBadReadPtr((PDWORD)Temp,4)==0){
					*(PDWORD)Temp=Value;
				}
			}
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
bool GetPlayerState() 
{ 
	unsigned long xBase = *(DWORD*)(ResultBasePlayer2); 
	if (!IsBadReadPtr((PDWORD)xBase,4))return true; 
	return false; 
}

/*-------------------------------------------------------------------------------------------------------------------*/
void c_WeaponIndex_B(unsigned long adr, unsigned long Ofset1, unsigned long Ofset2, unsigned long Ofset3, unsigned long Ofset4, DWORD dwValue){ 
	DWORD A=0;
	if(IsBadReadPtr((PDWORD)adr,4))return;
	A=*(PDWORD)((DWORD)(adr))+Ofset1;
	if(IsBadReadPtr((PDWORD)A,4))return;
	A=*(PDWORD)((DWORD)(A))+Ofset2;
	if(IsBadReadPtr((PDWORD)A,4))return;
	A=*(PDWORD)((DWORD)(A))+Ofset3;
	if(IsBadReadPtr((PDWORD)A,4))return;
	A=*(PDWORD)((DWORD)(A))+Ofset4;
	if(IsBadReadPtr((PDWORD)A,4))return;
	if(*(PDWORD)A!=dwValue)*(PDWORD)A=dwValue;
}

/*-------------------------------------------------------------------------------------------------------------------*/
void WeaponHack2(DWORD B,DWORD A1,DWORD B1, DWORD ISI){ 
	DWORD A=0;
	if (IsBadReadPtr((PDWORD)B,1)==0){ 
		A=*(PDWORD)((DWORD)(B))+A1;
		if (IsBadReadPtr((PDWORD)A,1)==0){ 
			A=*(PDWORD)((DWORD)(A))+B1;
			if (IsBadReadPtr((PDWORD)A,1)==0){
				*(PDWORD)A=ISI;
			}
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
void _WriteMEM(DWORD Adr, DWORD Ptr1, DWORD Ptr2, DWORD Ptr3, DWORD WriteValue)
{
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)Adr, 4) == 0)
	{ 
		Temp = *(PDWORD)((DWORD)(Adr)) + Ptr1;
		if (IsBadReadPtr((PDWORD)Temp,4) == 0)
		{ 
			Temp = *(PDWORD)((DWORD)(Temp)) + Ptr2;
			if (IsBadReadPtr((PDWORD)Temp,4) == 0)
			{ 
				Temp = *(PDWORD)((DWORD)(Temp)) + Ptr3;
				if (IsBadReadPtr((PDWORD)Temp,4) == 0)
				{
					*(PDWORD)Temp = WriteValue;
				}
			}
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
BYTE Weapon,Pistol,Knife,Bomb,Smoke,Dual;
void __ReadMem(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, int opt)
{
	DWORD Temp =0;
	if (IsBadReadPtr((PDWORD)Base,4)==0){
		Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
		if (IsBadReadPtr((PDWORD)Temp,4)==0){
			Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
			if (IsBadReadPtr((PDWORD)Temp,4)==0){
				Temp=*(PDWORD)((DWORD)(Temp))+Ofs3;
				if (IsBadReadPtr((PDWORD)Temp,4)==0){
					switch (opt)
					{
					case 1:
						Weapon = *(PBYTE)Temp;
					case 2:
						Pistol = *(PBYTE)Temp;
					case 3:
						Knife = *(PBYTE)Temp;
					case 4:
						Bomb = *(PBYTE)Temp;
					case 5:
						Smoke = *(PBYTE)Temp;
					case 6:
						Dual = *(PBYTE)Temp;
					}
				}
			}
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD RecordPTR(DWORD Base,DWORD PTR1,DWORD PTR2,DWORD PTR3){ 
DWORD RPTR1,RPTR2,RPTR3;
if (!IsBadReadPtr((PDWORD)Base,4)){RPTR1=*(PDWORD)((DWORD)(Base))+PTR1;
if (!IsBadReadPtr((PDWORD)RPTR1,4)){RPTR2=*(PDWORD)((DWORD)(RPTR1))+PTR2;
if (!IsBadReadPtr((PDWORD)RPTR2,4)){RPTR3=*(PDWORD)((DWORD)(RPTR2))+PTR3;
if (!IsBadReadPtr((PDWORD)RPTR3,4)){return *(PDWORD)RPTR3;}}}}
return RPTR3;}

/*-------------------------------------------------------------------------------------------------------------------*/
WORD pKey, pBase, pValue, pSoul;
void GetValue(DWORD BaseOfs, DWORD Offset1, DWORD Offset2, DWORD Offset3)
{
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)BaseOfs, 4) == 0)
	{ 
		Temp = *(PDWORD)((DWORD)(BaseOfs)) + Offset1;
		if (IsBadReadPtr((PDWORD)Temp,4) == 0)
		{ 
			Temp = *(PDWORD)((DWORD)(Temp)) + Offset2;
			if (IsBadReadPtr((PDWORD)Temp,4) == 0)
			{ 
				Temp = *(PDWORD)((DWORD)(Temp)) + Offset3;
				if (IsBadReadPtr((PDWORD)Temp,4) == 0)
				{
					switch (Offset3)
					{
					case 0xC9C:
						pKey = *(PWORD)Temp;
					case 0xCA0:
						pBase = *(PWORD)Temp;
					case 0xCA4:
						pValue = *(PWORD)Temp;
					case 0xCA8:
						pSoul = *(PWORD)Temp;
					}
				}
			}
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
void PatchValue(DWORD BaseOfs, DWORD Offset1, DWORD Offset2, DWORD Offset3, DWORD Value)
{
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)BaseOfs, 4) == 0)
	{ 
		Temp = *(PDWORD)((DWORD)(BaseOfs)) + Offset1;
		if (IsBadReadPtr((PDWORD)Temp,4) == 0)
		{ 
			Temp = *(PDWORD)((DWORD)(Temp)) + Offset2;
			if (IsBadReadPtr((PDWORD)Temp,4) == 0)
			{ 
				Temp = *(PDWORD)((DWORD)(Temp)) + Offset3;
				if (IsBadReadPtr((PDWORD)Temp,4) == 0)
				{
					*(PDWORD)Temp = Value;
				}
			}
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD WritePTR(DWORD Base,DWORD PTR1,DWORD PTR2,DWORD PTR3,DWORD Byte){ 
if (!IsBadReadPtr((PDWORD)Base,4)){DWORD RPTR1=*(PDWORD)((DWORD)(Base))+PTR1;
if (!IsBadReadPtr((PDWORD)RPTR1,4)){DWORD RPTR2=*(PDWORD)((DWORD)(RPTR1))+PTR2;
if (!IsBadReadPtr((PDWORD)RPTR2,4)){DWORD RPTR3=*(PDWORD)((DWORD)(RPTR2))+PTR3;
if (!IsBadReadPtr((PDWORD)RPTR3,4)){*(PDWORD)RPTR3=Byte;}}}}
return 0;}

/*-------------------------------------------------------------------------------------------------------------------*/
void Replay_12ddfx(DWORD BaseOfs, DWORD Offset1, DWORD Offset2, DWORD Offset3, DWORD Value) { 
	DWORD Temp=0; if (IsBadReadPtr((PDWORD)BaseOfs, 4) == 0){ 
		Temp = *(PDWORD)((DWORD)(BaseOfs)) + Offset1; 
		if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
			Temp = *(PDWORD)((DWORD)(Temp)) + Offset2; 
			if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
				Temp = *(PDWORD)((DWORD)(Temp)) + Offset3; 
				if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
					*(PDWORD)Temp = Value;
				}
			}
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
BYTE wepon,piso,pistol,bom,asep,dual;
void GoWeaponHack(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, BYTE Value){ 
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)Base,4)==0){
		Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
		if (IsBadReadPtr((PDWORD)Temp,4)==0){
			Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
			if (IsBadReadPtr((PDWORD)Temp,4)==0){
				Temp=*(PDWORD)((DWORD)(Temp))+Ofs3;
				if (IsBadReadPtr((PDWORD)Temp,4)==0){
					*(PBYTE)Temp=Value;
				}
			}
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD TestPacth(DWORD dwPtr,DWORD A1,DWORD B1,DWORD C1){
	DWORD C=0;
	if (IsBadReadPtr((PDWORD)dwPtr,4)==0){
		C=*(PDWORD)((DWORD)(dwPtr))+A1;
		if (IsBadReadPtr((PDWORD )C,4)==0){
			C=*(PDWORD)((DWORD)(C ))+ B1;
			if (IsBadReadPtr((PDWORD)C,4)==0) {
				C=*(PDWORD)((DWORD)(C ))+ C1;
				if (IsBadReadPtr((PDWORD)C,4)==0) {
					return *(PDWORD)C; 
				} 
			} 
		}
	}
	return C;
}

/*-------------------------------------------------------------------------------------------------------------------*/
void Function_One (DWORD Base,DWORD Ofs1, BYTE Value){
	DWORD Temp=NULL;
	if (IsBadReadPtr((PDWORD)Base,4)==0){
		Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
		if (IsBadReadPtr((PDWORD)Temp,4)==0){
			*(PBYTE)Temp=Value;
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
void PachtChara(DWORD B,DWORD A1,DWORD B1, DWORD ISI){
	DWORD A=0;
	if (IsBadReadPtr((PDWORD)B,4)==0){
		A=*(PDWORD)((DWORD)(B))+A1;
		if (IsBadReadPtr((PDWORD )A,4)==0){
			A=*(PDWORD)((DWORD)(A ))+ B1;
			if (IsBadReadPtr((PDWORD)A,4)==0) {
				{*(PDWORD)A=ISI;
				}
			}
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
void PacthHook(void *adr, void *ptr, int size)
{
	DWORD CheckProtection = 0;
	VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &CheckProtection);
	RtlMoveMemory(adr,ptr,size);
	VirtualProtect(adr,size,CheckProtection, &CheckProtection);
}

/*-------------------------------------------------------------------------------------------------------------------*/
void PacthWeapon(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, DWORD Value){ 
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)Base,4)==0){
		Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
		if (IsBadReadPtr((PDWORD)Temp,4)==0){
			Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
			if (IsBadReadPtr((PDWORD)Temp,4)==0){
				Temp=*(PDWORD)((DWORD)(Temp))+Ofs3;
				if (IsBadReadPtr((PDWORD)Temp,4)==0){
					*(PDWORD)Temp=Value;
				}
			}
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
int WritePtr (unsigned long ads, unsigned long ptr, int value){
	__try
	{
		unsigned long WrtPointer = false;
		WrtPointer = *(unsigned long*)((ads))+ptr;
		*(int*)(WrtPointer) = value;
		return true;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return false;
	}
}
int WritePtr1 (unsigned long ads, unsigned long ptr, int value)
{
	__try
	{
		unsigned long WrtPointer = false;
		WrtPointer = *(unsigned long*)((ads))+ptr;
		*(int*)(WrtPointer) = value;
		return true;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return false;
	}
}
/*-------------------------------------------------------------------------------------------------------------------*/
int WritePointer2 (unsigned long ads, unsigned long ptr, unsigned long ptr2,int value){
	__try{
		unsigned long WrtPointer = false;
		WrtPointer = *(unsigned long*)((ads))+ptr;
		WrtPointer = *(unsigned long*)((WrtPointer))+ptr2;
		*(int*)(WrtPointer) = value;
		return true;
	}
	__except (EXCEPTION_EXECUTE_HANDLER){
		return false;
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
void LongPtr1 ( DWORD adress, DWORD offset, DWORD offset2, int Value ){
	__try
	{
		DWORD OldPtr;
		OldPtr = *(PDWORD)((DWORD)adress) + offset;
		OldPtr = *(PDWORD)((DWORD)OldPtr) + offset2;
		*(int*)(OldPtr) = Value;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
	}
}

/*-------------------------------------------------------------------------------------------------------------------*/
void gEtWeapon_IndexA(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, DWORD Value){ 
	DWORD Temp=0;
	if (IsBadReadPtr((PDWORD)Base,4)==0){
	Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
	if (IsBadReadPtr((PDWORD)Temp,4)==0){
	Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
	if (IsBadReadPtr((PDWORD)Temp,4)==0){
	Temp=*(PDWORD)((DWORD)(Temp))+Ofs3;
	if (IsBadReadPtr((PDWORD)Temp,4)==0){
	*(PDWORD)Temp=Value;}}}}
}

/*-------------------------------------------------------------------------------------------------------------------*/
bool MakePoint(unsigned long ADRexec, int OFSexec, int PTRexec){
	if (!IsBadReadPtr((void*)ADRexec, sizeof(unsigned long))){
		if (!IsBadReadPtr((void*)(*(unsigned long*)ADRexec + OFSexec), sizeof(unsigned long))){
			*(int*)(*(unsigned long*)ADRexec + OFSexec) = PTRexec;
		}
	}
	return 0;
}

/*-------------------------------------------------------------------------------------------------------------------*/
DWORD Read(DWORD dwPtr, DWORD dwOfs){ 
	DWORD C; 
	if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
		C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
		if(IsBadReadPtr((PDWORD)(C),4)==0){ 
			return *(PDWORD)C; 
		}
	}
	return C;
}

/*-------------------------------------------------------------------------------------------------------------------*/