//==================================================================================================================================//
//											AUTHOR	: M. Hendy																		//											  
//											Me      : M. Hendy
//											RELEASE : Kreasi Sendiri ^_^																	//
//											WEB		: Palembang-Community.blogspot.com													//
//																																	//
//										    NO SHARE TO PUBLIC || BASE RESMI Muhammad Hendy											//
//==================================================================================================================================//
#include "stdafx.h"
#include <mmsystem.h>

#pragma once

// Stripped Sound Class kinda pointless for public release since i stripped all the cool functions but more pain to remove lol

class cSound
{
	
public:

	struct smp3
	{
	
	}mp3;

	struct swav
	{
	void playsound(LPCSTR sound);
	void playsoundmem(LPCSTR sound);
	}wav;

};
extern cSound Sound;



