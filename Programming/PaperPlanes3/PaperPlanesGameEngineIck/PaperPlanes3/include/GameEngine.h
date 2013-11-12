#pragma once
#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_

#include "GameState.h"
#include "IntroState.h"
#include "AIE.h"
#include "Main.h"
#include <vector>
using namespace std;


class GameState;


class GameEngine
{
public:
	
	void Initialize(const char* title, int width = 1080, int height = 720, int bpp = 0, bool fullscreen = false);
	void Cleanup();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();
	bool Running();
	void Quit();

	IntroState Intro;

	

private:

	vector <GameState*> states;
	bool m_Running;
	bool m_Fullscreen;
	

};
#endif

