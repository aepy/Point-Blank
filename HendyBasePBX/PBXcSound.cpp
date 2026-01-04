//==================================================================================================================================//
//											AUTHOR	: M. Hendy																		//											  
//											Me      : M. Hendy
//											RELEASE : Kreasi Sendiri ^_^																	//
//											WEB		: Palembang-Community.blogspot.com													//
//																																	//
//										    NO SHARE TO PUBLIC || BASE RESMI Muhammad Hendy											//
//==================================================================================================================================//

#include "cSound.h"

#pragma comment(lib, "WinMM.Lib")

void cSound::swav::playsound(LPCSTR sound)
{
	sndPlaySound(sound,SND_ASYNC);
}
void cSound::swav::playsoundmem(LPCSTR sound)
{
	sndPlaySound(sound,SND_ASYNC|SND_MEMORY);
}
