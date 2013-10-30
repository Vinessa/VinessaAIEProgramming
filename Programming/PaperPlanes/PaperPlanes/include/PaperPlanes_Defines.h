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
#include "Class_Sprite.h"
#include "Time_VM.h"

Timer SplashTimer;

typedef enum GameStates
{
	SPLASH,
	TITLE,
	HIGHSCORES,
	GAMESTATE,
	ENDSTATE,

	PLAYER_STATE_COUNT, 
}GameState;


//unsigned int uiBackgroundGame = -1;
//unsigned int uiBackgroundTitle = -1;

//Functions
void InitiateSplash();
void DrawSplash();
void InitiateGame();
void DrawGame();
void DestroyGame();
void InitiateTitle();
void DrawTitle();
bool CheckForStart(GameState &eCurrentState);
bool CheckForQuit (GameState &eCurrentState);
bool CheckForQuitFromInGame(GameState &eCurrentState);

//Screen Size
const int ciScreenX = 1080;
const int ciScreenY = 720;

//Hero (Player) Size
const int ciHeroWidth = 64;
const int ciHeroHeight = 64;

//Enemy Size
const int ciEnemyWidth = 64;
const int ciEnemyHeight = 64;

//Speeds
const float fSpeed = 2;

//Structs
struct fVelosity //Velosity
{
	float X;
	float Y;
};

struct Enemy //Enemy
{
	fVelosity Position;
	fVelosity Speed;
	int Sprite;
	int Width;
	int Height;
};
struct Hero //hero
{
	fVelosity Position;
	fVelosity Speed;
	int Sprite;
	int Width;
	int Height;
};

//Hero Player1 = {960, 540, 0, 0, -1, ciHeroWidth, ciHeroHeight};
//Enemy PaperClips = {600, 600, 1,1, -1, ciEnemyWidth, ciEnemyHeight};

#endif