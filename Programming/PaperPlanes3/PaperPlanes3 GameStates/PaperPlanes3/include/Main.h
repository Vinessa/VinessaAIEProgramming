///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Main.h
// Author:			Vinessa Mayer
// Date Created:	October 2013
// Brief:			PaperPlanes Main Header
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\

//guards
#pragma once
#ifndef _MAIN_H_
#define _MAIN_H_


#include "Time_VM.h"
#include <list>
#include "Enemy.h"
#include "Hero.h"

class Enemy;
class Hero;
class Timer;

const int ciScreenX = 1080;
const int ciScreenY = 720;

void CheckForChoice();
void MakeGame();

typedef enum GameStates
{
	SPLASH,
	TITLE,
	HIGHSCORES,
	GAMESTATE,
	ENDSTATE,

	PLAYER_STATE_COUNT, 
}GameState;





#endif
