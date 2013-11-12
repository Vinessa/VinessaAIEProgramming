
#include <stdio.h>

#include "GameEngine.h"



///INITIALIZE///
void GameEngine::Initialize (const char* title, int width, int height, int bpp, bool fullscreen)
{
	/*int flags = 0;
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *screen = SDL_CreateWindow("PaperPlanes",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1080, 720,
		SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);*/
	Initialise(ciScreenX, ciScreenY, false );
	ClearScreen();
	printf ("GameEngine Initializing\n");

}


void GameEngine::Cleanup()
{
	while (!states.empty())
	{
		states.back() -> Cleanup();
		states.pop_back();
	}


	/*if (m_Fullscreen)
	{
		SDL_Window *sdlWindow = SDL_CreateWindow("PaperPlanes",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			0, 0,
			SDL_WINDOW_FULLSCREEN_DESKTOP);
	}*/

	printf("GameEngineCleanup");


}

void GameEngine::ChangeState(GameState* state)
{
	if (!states.empty())
	{
		states.back()->Cleanup();
		states.pop_back();
	}

	states.push_back(state);
	states.back() ->Initialize();
}

void GameEngine::PushState(GameState* state)
{
	if (!states.empty())
	{
		states.back()->Pause();
	}

	states.push_back(state);
	states.back() -> Initialize();
}

void GameEngine::PopState()
{
	if (!states.empty())
	{
		states.back()->Cleanup();
		states.pop_back();
	}
	if(!states.empty())
	{
		states.back()->Resume();
	}

}

void GameEngine::HandleEvents()
{
	states.back() ->HandleEvents(this);
}

void GameEngine::Update()
{
	states.back() ->Update(this);
}

void GameEngine::Draw()
{
	states.back()->Draw(this);
}

bool GameEngine::Running()
	{
		return m_Running;
	}
	void GameEngine::Quit()
	{
		m_Running = false;
	}