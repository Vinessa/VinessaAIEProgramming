#include "IntroState.h"


//IntroState IntroState::m_IntroState;

void IntroState::Initialize()
{
	/*Background = CreateSprite( "./images/SplashScreen.png", ciScreenX, ciScreenY, true );*/
	Sprite BACKGROUND("./images/SplashScreen.png", 1080, 720, 540, 360, 0,0);
	BACKGROUND.Move();
	IntroTimer.SetTimer(6);

	printf ("IntroState Initialize.\n");
}

void IntroState::Cleanup()
{
	/*SDL_FreeSurface(Background);
	SDL_FreeSurface(Fader);*/

	printf("IntroState Cleanup\n");

}

void IntroState::Pause()
{
	printf("IntroState Pause\n");
}

void IntroState::Resume()
{
	printf("IntroState Resume\n");
}

void IntroState::HandleEvents(/*GameEngine* game*/)
{
	printf("IntroState Handle Events");

}
//{
//	SDL_Event event;
//
//	if (SDL_PollEvent(&event))
//	{
//		switch(event.type)
//		{
//		case SDL_QUIT:
//			game -> Quit();
//			break;
//
//		case SDL_KEYDOWN:
//			switch (event.key.keysym.sym)
//			{
//			case SDLK_SPACE:
//				game->ChangeState(PlayState::Instance());
//				break;
//
//			case SDLK_ESCAPE:
//				game->Quit();
//				break;
//
//			}
//			break;
//		}
//	}
//}


void IntroState::Update(GameEngine* game)
{
	IntroTimer.UpdateCountdown();
	if(IntroTimer.IsTimeUp())
		game ->ChangeState(MenuState::Instance());
}
	

void IntroState::Draw(/*GameEngine* game*/)
{
	DrawSprite(Background);

}