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


int main( int argc, char* argv[] )
{

	//std::list <Bullet> EnemyBulletList (5, Sprite UFO1Bullets("./images/BULLET.png", 4, 4, , 0,5, E);


	Initialise(ciScreenX, ciScreenY, false );
	ClearScreen();

	Sprite BACKGROUND("./images/BACKGROUNDPLACEHOLDER.png", 1080, 720, 540, 360, 0,0);
	BACKGROUND.Move();
	Hero Player("./images/HERO2.png", 32,32,100,100,0,0,5);
	Player.Move();

	//Bullet Bullets("./images/Bullet.png",4, 4, 10, 10, 0, 0,'H');
{
	
	/*Sprite UFO("./images/UFO.png", 10, 32, 32, 298, -64,.5,.25);
	Sprite UFO1("./images/UFO1.png", 10, 32, 32, 328, -128,.5,.25);
	Sprite UFO2("./images/UFO2.png", 10, 32, 32, 360, -192,.5,.25);
	Sprite UFO3("./images/UFO.png", 10, 32, 32, 392, -256,.5,.25);
	Sprite UFO4("./images/UFO1.png", 10, 32, 32, 424, -320,.5,.25);
	Sprite UFO5("./images/UFO2.png", 10, 32, 32, 456, -384,.5,.25);

	Sprite Bullet ("./images/BULLET.png", 4, 4, BulletSpawnPos,  0,5,E);
	Sprite Bullet1("./images/BULLET.png", 4, 4, BulletSpawnPos, 0,5, E);
	Sprite Bullet2("./images/BULLET.png", 4, 4, BulletSpawnPos, 0,5, E);
	Sprite Bullet3("./images/BULLET.png", 4, 4, BulletSpawnPos, 0,5, E);
	Sprite Bullet4("./images/BULLET.png", 4, 4, BulletSpawnPos, 0,5, E);
	Sprite Bullet5("./images/BULLET.png", 4, 4, BulletSpawnPos, 0,5, E);*/

	
//	Sprite HERO("./images/HERO.png", 10, 64, 64, 540, 360, 0,0);
	do{
		ClearScreen();
		BACKGROUND.Draw();
		Player.UpdateHero();
		
		Player.Draw();
		
		
	


	}while(FrameworkUpdate() ==false);
	Shutdown();
	return 0;
}
}