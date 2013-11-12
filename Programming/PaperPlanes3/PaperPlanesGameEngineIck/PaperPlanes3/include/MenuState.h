#pragma once
#ifndef _MENUSTATE_H_
#define _MENUSTATE_H_

#include "GameState.h"

class MenuState :
	public GameState
{
public:
	void Initialize();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);
	void CheckForChoice();
	
	int Background;
	int Choice;

	//static MenuState* Instance()
	//{
	//	return &m_MenuState;
	//}

	protected:
	MenuState()
	{
	}

private:

	//static MenuState m_MenuState;
	//SDL_Surface* Background; //SDL_Surface may need to be changed to SDL_Texture depennding on compatability with SDL 2.0 (PaperPlanes uses SDL2.0 while tutorial uses an earlier version)
	
};
	

#endif
