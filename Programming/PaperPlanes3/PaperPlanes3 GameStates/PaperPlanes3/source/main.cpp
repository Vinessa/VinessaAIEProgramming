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
			//ClearScreen();
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
// CREATES A SPACE FOR THE TITLE SPRITES IN MEMORY AND CREATES THE WINDOW IN IT'S PREDEFINED SIZE.

/*Sprite BACKGROUND("./images/BACKGROUNDPLACEHOLDER.png", 1080, 720, 540, 360, 0,0);
BACKGROUND.Move();

Hero Player("./images/HERO2.png", 32,32,100,100,0,0,5);
Player.Move();

std::list<Enemy> UFOWave = CreateEnemyWave(-100,Player);




do{
ClearScreen();



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
return 0;
}
std::list<Enemy> CreateEnemyWave(int SpawnPosition,Hero& Player)
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
}*/




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

		Enemy UFO("./images/UFO.png", 32,32,SpawnPosition,SpawnPosition,1,.25,3);
		Player.SetBulletList(UFO.GetBulletList());
		UFO.SetBulletList(Player.GetBulletList());
		UFOWave.push_back(UFO);
		UFO.Move();
		SpawnPosition += 40;

	}
	return UFOWave;

}
void MakeGame()
{
	Sprite BACKGROUND("./images/BACKGROUNDPLACEHOLDER.png", 1080, 720, 540, 360, 0,0);
	BACKGROUND.Move();

	Hero Player("./images/HERO2.png", 32,32,100,100,0,0,5);
	Player.Move();

	std::list<Enemy> UFOWave = CreateEnemyWave(-100,Player);

	


	do{
		ClearScreen();



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