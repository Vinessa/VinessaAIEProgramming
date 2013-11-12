#include "PlayState.h"


//PlayState PlayState::m_PlayState;

void PlayState::InitializeHero()
{
	
	Hero Player("./images/HERO2.png", 32,32,100,100,0,0,5);
	Player.Move();
}

void PlayState::InitializeBackground()
{
	Sprite BACKGROUND("./images/PlayScreen.BMP", 1080, 720, 540, 360, 0,0);
	BACKGROUND.Move();
}

void InitializeEnemyWaves()
{
	std::list<Enemy> UFOWave;
}

void PlayState::Initialize()
{	
	InitializeBackground();

	InitializeHero();
	


	printf ("PlayState Initialize.\n");
}

void PlayState::Pause()
{
	printf("PlayState Pause\n");
}

void PlayState::Resume()
{
	printf("PlayState Resume\n");
}

void PlayState::HandleEvents(GameEngine* game)
{
	/*SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			game -> Quit();
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			
			case SDLK_ESCAPE:
				game->Quit();
				break;

			case SDLK_m:
				game->PushState( MenuState::Instance());
				break;

			}
			break;
		}
	}*/
}


void PlayState::Update(GameEngine* game)
{
	
}

void PlayState::Draw(GameEngine* game)
{
	DrawSprite(Background);
		
}



std::list<Enemy> PlayState::CreateEnemyWave(int SpawnPosition,Hero& Player)
{
	std::list<Enemy> UFOWave;
	for( int i=0; i < 10; i++)

	{

		Enemy UFO("./images/UFO.png", 32,32,SpawnPosition,SpawnPosition,1,.25,3);
		Player.SetBulletList(UFO.GetBulletList());
		UFO.SetBulletList(Player.GetBulletList());
		UFOWave.push_back(UFO);
		UFO.Move();
		SpawnPosition += 40;

	}
	return UFOWave;
}