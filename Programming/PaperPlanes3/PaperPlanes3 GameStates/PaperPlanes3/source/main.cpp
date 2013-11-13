//////////////////////////////////////////////////////////////////////////
#include "Main.h"
#include <string>
#include <time.h>
#include "AIE.h"
#include "Class_Sprite.h"
#include "Enemy.h"

GameState eCurrentState;

std::list<Enemy> CreateEnemyWave(int SpawnPosition,Hero& Player);
void MakeGame();

void CheckForChoice();

int main( int argc, char* argv[] )
{

	eCurrentState= SPLASH;
Timer SplashTimer;

	Initialise(ciScreenX, ciScreenY, false );
	SplashTimer.SetTimer(6);
	ClearScreen();

	do
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
			Sprite TITLEBG("./images/TITLE.png", 1080, 720, 540, 360, 0,0);
			TITLEBG.Move();
			ClearScreen();
			TITLEBG.Draw();
			CheckForChoice();
			}
			break;

		case GAMESTATE:
			MakeGame();
			CheckForGameOver();

			break;

		case GAMEOVER:
			{
			Sprite GAMEOVERBG("./images/GAMEOVER.png",1080, 720, 540, 360, 0,0);
			GAMEOVERBG.Move();
			ClearScreen();
			GAMEOVERBG.Draw();
			}
			break;

		case ENDSTATE:
				//DestroyGame();
				Shutdown();
				return 0;
				break;

		default:
				break;
} //Closes the Switch loop
	}//Closes the do loop
	while (FrameworkUpdate() == false);
} //closes main




void CheckForChoice()
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
std::list<Enemy> CreateEnemyWave(int SpawnPosition,Hero& Player)
{
	std::list<Enemy> UFOWave;
	for( int i=0; i < 10; i++)

	{

		Enemy UFO("./images/UFO.png", 32,32,SpawnPosition,SpawnPosition,1,.25,3,Player.Score);
		Player.SetBulletList(UFO.GetBulletList());
		UFO.SetBulletList(Player.GetBulletList());
		UFOWave.push_back(UFO);
		UFO.Move();
		SpawnPosition += 40;

	}
	return UFOWave;

}
void CheckforGameOver()
{
	if ((Player.GetLives()) < 0)
	{
		eCurrentState = GAMEOVER;
	}


void MakeGame()
{
	Sprite BACKGROUND("./images/PlayScreenPNG.png", 1080, 720, 540, 360, 0,0);
	BACKGROUND.Move();

	Hero Player("./images/HERO2.png", 32,32,100,100,0,0,5);
	Player.Move();

	std::list<Enemy> UFOWave = CreateEnemyWave(-100,Player);
	
	
	


	do{
		ClearScreen();
		
		static char c_PlayerScore[5] = {'\n'};

sprintf (c_PlayerScore, "Score: %f",Player.Score );  

DrawString(c_PlayerScore, 10, 10, SColour (0,0,0,255));

static char c_PlayerLives[5] = {'\n'};

sprintf (c_PlayerLives, "Lives Remaining: %f", Player.Lives);

DrawString (c_PlayerLives,1000, 10, SColour (0,0,0,255));




		BACKGROUND.Draw();
 		float dt = GetDeltaTime();

		for (std::list<Enemy>::iterator IT = UFOWave.begin(); IT != UFOWave.end(); ++IT)
		{
			IT->UpdateEnemy(dt);
			IT->Draw();

		}
		Player.UpdateHero(dt);

		Player.Draw();








	}while(FrameworkUpdate() ==false);
	Shutdown();
	return ;
}
}