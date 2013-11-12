#include "MenuState.h"
#include <stdio.h>
//#include "SDL.h"
#include "GameEngine.h"
#include "GameState.h"
#include "Main.h"
#include "PlayState.h"

//MenuState MenuState::m_MenuState;

void MenuState::Initialize()
{
	//May have to change SDL_Surface to SDL_Texture. 
	//Need to install SDL_Images2.0 lib to be able to use anything other than BMP.
	/*SDL_Surface* temp = SDL_LoadBMP("MenuBMP.bmp");*/

	/*Background = SDL_ConvertSurface(temp);*/

	/*SDL_FreeSurface(temp);*/
	Background = CreateSprite( "./images/TITLE.png", ciScreenX, ciScreenY, true );
	MoveSprite(Background, ciScreenX>>1, ciScreenY>>1);
	

	
	printf ("MenuState Initialize.\n");
}

void MenuState::Cleanup()
{
	/*SDL_FreeSurface(Background);*/
	printf("MenuState Cleanup\n");

}

void MenuState::Pause()
{
	printf("MenuState Pause\n");
}

void MenuState::Resume()
{
	printf("MenuState Resume\n");
}



void MenuState::CheckForChoice()
{
	if (IsKeyDown('Q')) //Quit
	{
		Choice = 0;
	}
	else if (IsKeyDown(KEY_SPACE)) //Start
	{
		Choice = 1;
	}
	else if (IsKeyDown(KEY_ESC)) //Back (resumes to previous state)
	{
		Choice = 2;
	}
}

void MenuState::HandleEvents(GameEngine* game)
{
	CheckForChoice();

		switch(Choice)
		{
		case 0:
			game -> Quit();
			break;

		case 1:
			game -> ChangeState(PlayState::Instance());
			break;
			{
			
		case 2:
				game->PopState();
				break;

			}
			break;
		}
	}



void MenuState::Draw(GameEngine* game)
{
	//SDL_BlitSurface(Background, NULL, game ->Screen, NULL);
	//SDL_UpdateRect(game->Screen,0,0,0,0);

	DrawSprite(Background);
}
