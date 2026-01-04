DWORD ValueName(DWORD Base, DWORD Ofs1, DWORD Ofs2,DWORD Ofs3, PBYTE Value, int size)
{
	DWORD Temp = NULL;
	if (IsBadReadPtr((PDWORD)Base, 4) == 0) {
		Temp = *(PDWORD)((DWORD)(Base)) + Ofs1;
		if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
			Temp = *(PDWORD)((DWORD)(Temp)) + Ofs2;
			if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
				Temp = *(PDWORD)((DWORD)(Temp)) + Ofs3;
				if (IsBadReadPtr((PDWORD)Temp, 4) == 0) {
					Patch_((void*)(Temp), (void*)(PBYTE)Value, size);
				}
			}
		}
	}
	return (0);
}

#define OFS_NICK 	0x0 // blm nemu :(
ValueName(BASE_REPLACE, OFS_REPLACE_1, OFS_REPLACE_2, OFS_NICK_1, (PBYTE)"Anyme", 50);




		void Patch_(void *adr, void *ptr, int size)
{
	DWORD OldProtection;
	VirtualProtect(adr, size, PAGE_EXECUTE_READWRITE, &OldProtection);
	memcpy(adr, ptr, size);
	VirtualProtect(adr, size, OldProtection, &OldProtection);
}