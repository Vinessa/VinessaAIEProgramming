#pragma once
#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_
#include "GameEngine.h"

class GameEngine;
class GameState
{
public:
	/*GameState(void);
	~GameState(void);*/
virtual void Initialize() = 0;
virtual void Cleanup() = 0;

virtual void Pause() = 0;
virtual void Resume() = 0;

virtual void HandleEvents (GameEngine* game) = 0;
virtual void Update (GameEngine* game) = 0;
virtual void Draw (GameEngine* game) = 0;

void ChangeState(GameEngine* game, GameState* state);

protected: 
	GameState()
		{
		  
		}
};
#endif
