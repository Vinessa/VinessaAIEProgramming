#pragma once
#ifndef _PLAYSTATE_H_
#define _PLAYSTATE_H_

#include "GameState.h"
#include <list>
#include <stdio.h>
#include "GameEngine.h"
//#include "MenuState.h"
#include "Main.h"
#include "AIE.h"
#include "Hero.h"
#include "Enemy.h"



class PlayState :
	public GameState
{
public:
	void Initialize();
	void InitializeBackground();
	void InitializeHero();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);
	std::list<Enemy> CreateEnemyWave(int SpawnPosition,Hero& Player);

	int Background;

	static PlayState* Instance()
	{
		return &m_PlayState;
	}

protected:
	PlayState()
	{
	}

private:
	static PlayState m_PlayState;
	/*SDL_Surface* Background;*/
	
};
#endif

