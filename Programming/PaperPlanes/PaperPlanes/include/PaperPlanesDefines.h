/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // File: PaperPlanes_Defines.h (PaperPlanes)
 // Author: Vinessa Mayer
 // Date Created: September 30th 2013
 // Brief: Collection of global variables and structs used within PaperPlanes. An exercise as part of Year 1 Semester 1 Game Programming.
 // Copyright: Vinessa Mayer 2013
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _PAPERPLANES_DEFINES_
#define _PAPERPLANES_DEFINES_

#include <stdlib.h>


//Screen Size
const int ciScreenX = 1920;
const int ciScreenY = 1080;

//Player Size
const int ciPlayerSize = 64;
const int ciPlayerSize = 64;

//Speeds
const float fSpeed = 2;

//Structs
struct fVelosity //Velosity
{
	float X;
	float Y;
};

struct Enemy //Enemy
	fVelosity Position;
	fVelosity Speed;
	int Sprite;
	int Width;
	int Height;

struct Hero
	fVelosity Position;
	fVelosity Speed;
	int Sprite;
	int Width;
	int Height;


#endif