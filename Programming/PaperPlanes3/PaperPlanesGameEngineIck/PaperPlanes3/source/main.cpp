//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include <list>
#include "Class_Sprite.h"
#include "Bullet_Class.h"
#include "Main.h"
#include "Hero.h"
#include "Enemy.h"
#include "GameEngine.h"
#include "IntroState.h"
//#include "Scoreboard.h"






int main( int argc, char* argv[] )
{
	GameEngine game;

	game.Initialize("PaperPlanes ETest v1");

	game.ChangeState(game.);

	while (game.Running())
	{
		game.HandleEvents();
		game.Update();
		game.Draw();
	}

	game.Cleanup();
	return 0;
}

//
//	Initialise(ciScreenX, ciScreenY, false );
//	ClearScreen();
//
//	Sprite BACKGROUND("./images/BACKGROUNDPLACEHOLDER.png", 1080, 720, 540, 360, 0,0);
//	BACKGROUND.Move();
//
//	Hero Player("./images/HERO2.png", 32,32,100,100,0,0,5);
//	Player.Move();
//
//	std::list<Enemy> UFOWave = CreateEnemyWave(-100,Player);
//
//	
////	Score1.Move();
//
//	do{
//		ClearScreen();
//
//
//
//		BACKGROUND.Draw();
//		float dt = GetDeltaTime();
//
//		for (std::list<Enemy>::iterator IT = UFOWave.begin(); IT != UFOWave.end(); ++IT)
//		{
//			IT->UpdateEnemy(dt);
//			IT->Draw();
//
//		}
//		Player.UpdateHero(dt);
////		Score1.Draw();
//		Player.Draw();
//
//
//
//
//
//
//
//
//	}while(FrameworkUpdate() ==false);
//	Shutdown();
//	return 0;
//}

