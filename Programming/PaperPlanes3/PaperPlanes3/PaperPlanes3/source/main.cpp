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
#include "Scoreboard.h"


std::list<Enemy> CreateEnemyWave(int SpawnPosition,Hero& Player);



int main( int argc, char* argv[] )
{




	Initialise(ciScreenX, ciScreenY, false );
	ClearScreen();

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
}
