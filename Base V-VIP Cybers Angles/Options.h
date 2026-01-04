//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
#pragma warning(disable: 4700 4101 4309 4305 4996)
//=========================================================================//

void  Error_Log(void  *Mini, void  *ptr, int  size)
{{
DWORD Minimize;
VirtualProtect(Mini,size,PAGE_EXECUTE_READWRITE, &Minimize);
memcpy(Mini,ptr,size); 
VirtualProtect(Mini,size,Minimize, &Minimize);
}}
//=========================================================================//
bool Keprok,Keprox = false;
//=========================================================================//
bool MakePoint(unsigned long ADRexec, int OFSexec, int PTRexec)
{
if (!IsBadReadPtr((void*)ADRexec, sizeof(unsigned long)))
{
if (!IsBadReadPtr((void*)(*(unsigned long*)ADRexec + OFSexec), sizeof(unsigned long)))
{
*(int*)(*(unsigned long*)ADRexec + OFSexec) = PTRexec;
}
}
return 0;
}
//=========================================================================//
void PacthWeapone(DWORD Base,DWORD Ofs1,DWORD Ofs2, DWORD Ofs3, DWORD Value)
{
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
//=========================================================================//

void Function_One (DWORD Base,DWORD Ofs1, BYTE Value)
{ 
DWORD Temp=NULL;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
*(PBYTE)Temp=Value;
}
}
}

//=========================================================================//

void WeaponHack1(DWORD B,DWORD A1,DWORD B1, DWORD C1, DWORD ISI)
    { DWORD A=0;
    if (IsBadReadPtr((PDWORD)B,1)==0)
    { A=*(PDWORD)((DWORD)(B))+A1;
    if (IsBadReadPtr((PDWORD)A,1)==0)
    { A=*(PDWORD)((DWORD)(A))+B1;
    if (IsBadReadPtr((PDWORD)A,1)==0)
    { A=*(PDWORD)((DWORD)(A))+C1;
    if (IsBadReadPtr((PDWORD)A,1)==0)
    {*(PDWORD)A=ISI;
    }
    }
    }
    }
    }
//=========================================================================//

void WeaponHack2(DWORD B,DWORD A1,DWORD B1, DWORD ISI)
    { DWORD A=0;
    if (IsBadReadPtr((PDWORD)B,1)==0)
    { A=*(PDWORD)((DWORD)(B))+A1;
    if (IsBadReadPtr((PDWORD)A,1)==0)
    { A=*(PDWORD)((DWORD)(A))+B1;
	if (IsBadReadPtr((PDWORD)A,1)==0)
    {*(PDWORD)A=ISI;
    }
    }
    }
    }

void FuncDua(DWORD B,DWORD A1,DWORD B1, DWORD ISI){
DWORD A=0;
if (IsBadReadPtr((PDWORD)B,4)==0){
A=*(PDWORD)((DWORD)(B))+A1;
if (IsBadReadPtr((PDWORD )A,4)==0){
A=*(PDWORD)((DWORD)(A ))+ B1;
if (IsBadReadPtr((PDWORD)A,4)==0) {
{*(PDWORD)A=ISI;}}}}}
//=========================================================================//
void PrivateOnly(void *adr, void *ptr, int size)
{ 
DWORD NextProtection;
VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &NextProtection);
Sleep(1);
Sleep(1);
RtlCopyMemory(adr,ptr,size);
Sleep(1);
Sleep(1);
VirtualProtect(adr,size,NextProtection, &NextProtection);
}
//=========================================================================//
DWORD Function_Two (DWORD Base,DWORD Ofs1,DWORD Ofs2, BYTE Value)
{ 
DWORD Temp=NULL;
if (IsBadReadPtr((PDWORD)Base,4)==0){
Temp=*(PDWORD)((DWORD)(Base))+Ofs1;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
Temp=*(PDWORD)((DWORD)(Temp))+Ofs2;
if (IsBadReadPtr((PDWORD)Temp,4)==0){
*(PBYTE)Temp=Value;
}}}
return (0);
}
//=========================================================================//
void PatchValue(DWORD BaseOfs, DWORD Offset1, DWORD Offset2, DWORD Offset3, DWORD Value)
{
DWORD Temp=0;
if (IsBadReadPtr((PDWORD)BaseOfs, 4) == 0){ 
Temp = *(PDWORD)((DWORD)(BaseOfs)) + Offset1;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
Temp = *(PDWORD)((DWORD)(Temp)) + Offset2;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
Temp = *(PDWORD)((DWORD)(Temp)) + Offset3;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){
*(PDWORD)Temp = Value;
}}}}}
//=========================================================================//
WORD pKey, pBase, pValue, pSoul;
void GetValue(DWORD BaseOfs, DWORD Offset1, DWORD Offset2, DWORD Offset3)
{
DWORD Temp=0;
if (IsBadReadPtr((PDWORD)BaseOfs, 4) == 0){ 
Temp = *(PDWORD)((DWORD)(BaseOfs)) + Offset1;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
Temp = *(PDWORD)((DWORD)(Temp)) + Offset2;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){ 
Temp = *(PDWORD)((DWORD)(Temp)) + Offset3;
if (IsBadReadPtr((PDWORD)Temp,4) == 0){
switch (Offset3){
case 0x898:
pKey = *(PWORD)Temp;
case 0x879:
pBase = *(PWORD)Temp;
case 0x894:
pValue = *(PWORD)Temp;
case 0x8A0:
pSoul = *(PWORD)Temp;
}
}
}
}
}
}
//=========================================================================//
bool REPALCE(unsigned long ADRexec, int OFSexec, int PTRexec)
{
if (!IsBadReadPtr((void*)ADRexec, sizeof(unsigned long)))
{
if (!IsBadReadPtr((void*)(*(unsigned long*)ADRexec + OFSexec), sizeof(unsigned long)))
{
*(int*)(*(unsigned long*)ADRexec + OFSexec) = PTRexec;
}
}
return 0;
}
//=========================================================================//
bool WriteSimpleOther(unsigned long ADRexec, int OFSexec, int PTRexec)
{
if (!IsBadReadPtr((void*)ADRexec, sizeof(unsigned long)))
{
if (!IsBadReadPtr((void*)(*(unsigned long*)ADRexec + OFSexec), sizeof(unsigned long)))
{
*(int*)(*(unsigned long*)ADRexec + OFSexec) = PTRexec;
}
}
return 0;
}

//=========================================================================//

void _patchPTRZ(unsigned long adr, unsigned long Ofset1, DWORD dwValue)
{ 
	DWORD A=0;
	if(IsBadReadPtr((PDWORD)adr,4))return;
	A=*(PDWORD)((DWORD)(adr))+Ofset1;
	if(IsBadReadPtr((PDWORD)A,4))return;
	if(*(PDWORD)A!=dwValue)*(PDWORD)A=dwValue;
}

//=========================================================================//
DWORD Read(DWORD dwPtr, DWORD dwOfs){ 
DWORD C; 
if(IsBadReadPtr((PDWORD)(dwPtr),4)==0){ 
C=*(PDWORD)((DWORD)(dwPtr))+dwOfs; 
if(IsBadReadPtr((PDWORD)(C),4)==0){ 
return *(PDWORD)C; 
} } 
return C;
}
