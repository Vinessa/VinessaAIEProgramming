//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include "PaperPlanes_Defines.h"
#include "Time_VM.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
using namespace std;


unsigned int uiBackgroundGame = -1;
unsigned int uiBackgroundTitle = -1;
unsigned int uiBackgroundSplash = -1;






//Creating Hero and Enemy
Hero Player1 = {960, 540, 0, 0, -1, ciHeroWidth, ciHeroHeight};
Enemy PaperClips = {600, 600, 1,1, -1, ciEnemyWidth, ciEnemyHeight};




int main( int argc, char* argv[] )
{	
	

	GameState eCurrentState = SPLASH;
	Initialise(ciScreenX, ciScreenY, false );

		SplashTimer.SetTimer(6);
	//InitiateGame();
	InitiateSplash();


do
	{
		switch(eCurrentState)
		{

		case SPLASH:
			InitiateSplash();
			ClearScreen();
			DrawSplash();
			SplashTimer.UpdateCountdown();
			if(SplashTimer.IsTimeUp())
				eCurrentState = TITLE;
			
			break;
			

		case TITLE:
			InitiateTitle();
			ClearScreen();
			DrawTitle();
			CheckForStart (eCurrentState);
			CheckForQuit (eCurrentState);
			break;

		case GAMESTATE:
			
				ClearScreen();
				//UpdateGame();
				DrawGame();
				

				CheckForQuitFromInGame(eCurrentState);
				//DeclareWinnerPlayer1(eCurrentState);
				//DeclareWinnerPlayer2(eCurrentState);
				//FrameworkUpdate();


			break;

		case ENDSTATE:
			{
			DestroyGame();
			Shutdown();
			return 0;
			break;
			}
		
		default:
			{
				break;
			}
		} //Closes the Switch loop
	}//Closes the do loop
	while (FrameworkUpdate() == false);
} //closes main
// CREATES A SPACE FOR THE TITLE SPRITES IN MEMORY AND CREATES THE WINDOW IN IT'S PREDEFINED SIZE.

void InitiateSplash()
{
	uiBackgroundSplash = CreateSprite( "./images/SplashScreen.png", ciScreenX, ciScreenY, true );
	MoveSprite(uiBackgroundSplash, ciScreenX>>1, ciScreenY>>1);
}

void DrawSplash()
{
	DrawSprite(uiBackgroundSplash);
}

void InitiateTitle()
{
	uiBackgroundTitle = CreateSprite( "./images/TITLE.png", ciScreenX, ciScreenY, true );
	MoveSprite(uiBackgroundTitle, ciScreenX>>1, ciScreenY>>1);
}

void DrawTitle()
{
	DrawSprite(uiBackgroundTitle);
}

bool CheckForStart(GameState &eCurrentState)
{
	if (IsKeyDown(KEY_SPACE))
	{
		eCurrentState = GAMESTATE;
		return true;
	}

	return false;
}

//CHECK TO SEE IF THE USER HAS SELECTED ESC (TITLE STATE ONLY) CHANGES CURRENT STATE TO END
bool CheckForQuit (GameState &eCurrentState)
{
	if (IsKeyDown(KEY_ESC)) 
	{
		eCurrentState = ENDSTATE;
		return true;
	}
	return false;
}

//CHECK TO SEE IF THE USER HAS SELECTED BACKSPACE GAME STATE ONLY SETS CURRENT STATE TO TITLE
bool CheckForQuitFromInGame (GameState &eCurrentState)
{
	if (IsKeyDown(KEY_BACKSPACE))
	{
		eCurrentState = TITLE;
		return true;
	}
	return false;
}
//Preparing space in memory for sprites


void InitiateGame()
{
	srand((int)time(0));
	uiBackgroundGame = CreateSprite("./images/BackgroundPlaceholder.png", ciScreenX, ciScreenY, true);
	MoveSprite(uiBackgroundGame, ciScreenX>>1, ciScreenY>>1);

	Player1.Sprite = CreateSprite("./images/Paper_Airplane.png", ciHeroWidth, ciHeroHeight, true);
	PaperClips.Sprite = CreateSprite("./images/UFO.png", ciEnemyWidth, ciEnemyHeight, true);
	MoveSprite(Player1.Sprite, Player1.Position.X, Player1.Position.Y);
	MoveSprite(PaperClips.Sprite, PaperClips.Position.X, PaperClips.Position.Y);
}

void DrawGame()
{
	DrawSprite(uiBackgroundGame);
	DrawSprite(Player1.Sprite);
	DrawSprite(PaperClips.Sprite);
}

void DestroyGame() 
{
	DestroySprite(uiBackgroundGame);
	DestroySprite(Player1.Sprite);
	DestroySprite(PaperClips.Sprite);
}