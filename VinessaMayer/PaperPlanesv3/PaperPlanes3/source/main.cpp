///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Main.cpp
// Author:			Vinessa Mayer
// Date Created:	October 2013
// Brief:			PaperPlanes Main
// Copyright: Vinessa Mayer 2013
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Main.h"
#include <string>
#include <time.h>
#include "AIE.h"
#include "Class_Sprite.h"
#include "Enemy.h"


//FORWARD DECLARATIONS ETC/////////////
GameState eCurrentState;

std::list<Enemy> CreateEnemyWave(int SpawnPosition,Hero& Player);
void MakeGame();

void CheckForChoice();
void CheckforGameOver(Hero& Player);

//MAIN///////////////////////////////////

int main( int argc, char* argv[] )
{

	eCurrentState= SPLASH; //SETS STARTING STATE TO SPLASH
	Timer SplashTimer; // CREATES SPLASHTIMER

	Initialise(ciScreenX, ciScreenY, false ); //INITS SCREEN
	SplashTimer.SetTimer(3); //SETS SPLASH TIMER
	ClearScreen(); // CLEARS SCREEN

	do //BEGIN SWITCH STATEMENT FOR STATES
	{
		switch(eCurrentState)
		{

		case SPLASH:
			{
				Sprite SPLASHBG("./images/SplashScreen.png", 1080, 720, 540, 360, 0,0);
				SPLASHBG.Move();
				SPLASHBG.Draw();

				SplashTimer.UpdateCountdown();
				if(SplashTimer.IsTimeUp())
					eCurrentState = TITLE;
			}
			break;


		case TITLE:
			{
				Sprite TITLEBG("./images/TITLE2.png", 1080, 720, 540, 360, 0,0);
				TITLEBG.Move();
				ClearScreen();
				TITLEBG.Draw();
				CheckForChoice();
			}
			break;

		case GAMESTATE:
			MakeGame();
			break;

		case GAMEOVER:
			{
				Sprite GAMEOVERBG("./images/GAMEOVER.png",1080, 720, 540, 360, 0,0);
				GAMEOVERBG.Move();
				ClearScreen();
				GAMEOVERBG.Draw();
				CheckForChoice();

			}
			break;

		case ENDSTATE:
			Shutdown();
			return 0;
			break;

		default:
			break;
		} //Closes the Switch loop
	}//Closes the do loop
	while (FrameworkUpdate() == false);
	//Shutdown();
} //closes main




void CheckForChoice() //CHECKS TO SEE IF THE PLAYER QUITS OR STARTS ETC
{
	if (IsKeyDown(KEY_SPACE))
	{
		eCurrentState = GAMESTATE;
	}
	else 
		if (IsKeyDown(KEY_ESC))
		{
			eCurrentState = ENDSTATE;

		}
}
std::list<Enemy> CreateEnemyWave(int SpawnPosition,Hero& Player) // CREATES ENEMY WAVES
{
	std::list<Enemy> UFOWave;
	for( int i=0; i < 10; i++)

	{
		Enemy UFO("./images/UFO.png", 32,32,SpawnPosition,SpawnPosition,1,.25,3,&Player.Score);
		Player.SetBulletList(UFO.GetBulletList());
		UFO.SetBulletList(Player.GetBulletList());
		UFOWave.push_back(UFO);
		UFO.Move();
		SpawnPosition += 40;

	}
	return UFOWave;

}
void CheckforGameOver(Hero& Player) //CHECKS TO SEE IF HERO HAS RUN OUT OF LIVES
{
	if ((Player.GetLives()) <= 0)
	{
		eCurrentState = GAMEOVER;
	}
}

void MakeGame() //MAIN GAME LOOP
{
	Sprite BACKGROUND("./images/PlayScreenPNG.png", 1080, 720, 540, 360, 0,0);
	BACKGROUND.Move();

	Hero Player("./images/HERO2.png", 32,32,100,100,0,0,5);
	Player.Move();

	std::list<Enemy> UFOWave = CreateEnemyWave(-100,Player);





	do{
		ClearScreen();

		//PRINTING SCORE AND LIVES
		static char c_PlayerScore[1] = {'\n'};

		sprintf (c_PlayerScore, "Score: %f",Player.Score );  

		DrawString(c_PlayerScore, 10, 10, SColour (0,0,0,255));

		static char c_PlayerLives[1] = {'\n'};

		sprintf (c_PlayerLives, "Lives Remaining: %f", Player.Lives);

		DrawString (c_PlayerLives,800, 10, SColour (0,0,0,255));




		BACKGROUND.Draw();
		float dt = GetDeltaTime();

		for (std::list<Enemy>::iterator IT = UFOWave.begin(); IT != UFOWave.end(); ++IT)
		{
			IT->UpdateEnemy(dt);
			IT->Draw();

		}
		Player.UpdateHero(dt);
		CheckforGameOver(Player);
		Player.Draw();



		if(eCurrentState == GAMEOVER) return; //debugging




	}while(FrameworkUpdate() ==false || eCurrentState == GAMEOVER);
	//Shutdown();
	return ;
}
