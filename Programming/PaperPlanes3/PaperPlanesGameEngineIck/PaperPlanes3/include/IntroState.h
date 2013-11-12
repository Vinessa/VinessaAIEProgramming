#pragma once
#ifndef _INTROSTATE_H_
#define _INTROSTATE_H_

//#include "SDL.h"
#include "GameState.h"
#include "Time_VM.h"
#include "MenuState.h"
#include "AIE.h"
#include <stdio.h>

#include "GameEngine.h"
#include "GameState.h"
#include "PlayState.h" 
#include "Main.h"
#include "Class_Sprite.h"


class IntroState :
	public GameState
{
public:
	void Initialize();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(/*GameEngine* game*/);
	void Update(GameEngine* game);
	void Draw(/*GameEngine* game*/);
	int Background ;
	Timer IntroTimer;

	//static IntroState* Instance()
	//{
	//	return &m_IntroState;
	//}

protected:
	IntroState()
	{
	}

private:

	//static IntroState m_IntroState;

	//SDL_Surface* Background; //SDL_Surface may need to be changed to SDL_Texture depennding on compatability with SDL 2.0 (PaperPlanes uses SDL2.0 while tutorial uses an earlier version)
	//SDL_Surface* Fader; // Does cool fade to black thingy.. also, see note above abot SDL_Surface
	//int Alpha;
};

#endif
