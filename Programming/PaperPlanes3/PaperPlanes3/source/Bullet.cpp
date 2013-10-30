#include "Bullet.h"


Bullet::Bullet(void) // Default Bullet Spawns at 100, 100 with no speed so I can see if my specific bullet failed.
{
	Sprite("./images/BULLET.png", 4, 4,100,100,0,0);
	IsAlive = false;
}

Bullet::Bullet(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, Vector2D a_Position, Vector2D a_Velocity )
{
	Sprite("./images/BULLET.png",4,4,a_Position);
	//a_BulletType = m_BulletType;
	IsAlive = false;
	GetPosition();
}

Bullet::~Bullet(void)
{
}

bool Bullet::CheckIfAlive()
{
	return IsAlive;
}

/*void Bullet::Die()
{
IsAlive = false;
SetSpeed(new Vector(0,0));
SetPosition(new Vector(-10,-10));

}*/

void Bullet::Spawn()
{
	Draw();
}
void Bullet::Respawn() 
{
	/*SetSpeed(Speed);
	SetPosition(Place);
	IsAlive = true;*/
	//BulletLocation = SpawnPosition;
	//BulletVelocity = SpawnVelocity;
	IsAlive = false;
}

void Bullet::FireBullet()

{
	//BulletLocation = FirePosition; //Swaps Bullet Sprite's position to Fire Position which should be equal to the Mother Sprite's current Position (UFO or Hero)
	//BulletVelocity = FireVelocity; // Swaps bullet velocity with one that moves it in the Y position
	IsAlive = true;
}

/*bool Bullet::IsBulletAlive()
{
	//int iXVariable = 50;
	if (BulletLocation.mf_x > ciScreenX || BulletLocation.GetX() < (ciScreenX - ciScreenX )
	{
		//m_Speed.SetX (m_Speed.GetX() * -1);
		//m_Speed.SetY (m_Speed.GetY() + .01);
		//iXVariable + 10;
		//m_Position.SetX(m_Position.GetX() - 5);
		//m_Position.SetY(m_Position.GetY() - 5);
		return true;
	}
	else if (BulletLocation.GetY() > ciScreenY) /*|| m_Position.GetY() < (ciScreenY - ciScreenY)*/
	/*{
		//m_Position.SetY(ciScreenY - ciScreenY);
		//m_Speed.SetY (m_Speed.GetY() == 1);
		//m_Speed.SetX (m_Speed.GetX() * -1);
		return true;

	else if (CheckCollisionHero() = true)
	{
		return true;
	}

	else if (CheckCollisionEnemy() = true)
	{
		return true;
	}
	}
	return false;
}
*/
void Bullet::Update_Bullet()
{

	if(IsAlive == true)
	{
		BulletLocation + BulletVelocity;
	}
	if(TestOnScreen_Bullet() == true)
	{
		Respawn();

	}

}

/*bool Bullet:: CheckIfInHero()
{
	// If this bullet is within the same area:
	//(((if Bullet Position is within OtherObject's current Position_X + OtherObject's Sprite Width / 2) ::OR:: (if Bullet Position is within OtherObject's current Position_X - OtherObject's Sprite Width / 2))
	//::OR::((if Bullet Position is within OtherObject's current Position_Y + OtherObject's Sprite Height / 2) ::OR:: (if Bullet Position is within OtherObject's current Position_Y - OtherObject's Sprite Height / 2))) Use Linked List
	if (((BulletLocation.GetX) > (Hero.HeroLocation.GetX - (Hero.m_Sprite_W / 2))) && 
		((BulletLocation.GetX) < (Hero.HeroLocation.GetX + (Hero.m_Sprite_W / 2))) &&
		((BulletLocation.GetY) > (Hero.HeroLocation.GetY - (Hero.m_Sprite_H / 2))) && 
		((BulletLocation.GetY) < (Hero.HeroLocation.GetY + (Hero.m_Sprite_H / 2))))
	{

		return true;
	}
	return false;
}*/

/*bool Bullet:: CheckIfInUFO()
{
	// If this bullet is within the same area:
	//(((if Bullet Position is within OtherObject's current Position_X + OtherObject's Sprite Width / 2) ::OR:: (if Bullet Position is within OtherObject's current Position_X - OtherObject's Sprite Width / 2))
	//::OR::((if Bullet Position is within OtherObject's current Position_Y + OtherObject's Sprite Height / 2) ::OR:: (if Bullet Position is within OtherObject's current Position_Y - OtherObject's Sprite Height / 2))) Use Linked List
	if (((BulletLocation.GetX) > (UFO.UFOLocation.GetX - (UFO.m_Sprite_W / 2))) && 
		((BulletLocation.GetX) < (UFO.UFOLocation.GetX + (UFO.m_Sprite_W / 2))) &&
		((BulletLocation.GetY) > (UFO.UFOLocation.GetY - (UFO.m_Sprite_H / 2))) && 
		((BulletLocation.GetY) < (UFO.UFOLocation.GetY + (UFO.m_Sprite_H / 2))))
	{
		return true;
	}
	return false;
}*/



//bool Bullet::CheckCollisionHero()//will be referred to in Hero Class when taking damage.
//{
//	for(std::list<Bullet>:: iterator it = UFO1Bullets.begin(); it!= UFO1Bullets.end(); ++it)
//
//		if (IfAlive = true)
//		{
//			CheckIfInHero();
//			break;
//
//		}
//
//bool Bullet::CheckCollisionEnemy();
//{
//	for (std::list<Bullet>:: iterator it = HeroBullets.begin(); it!= HeroBullets.end(); ++it)
//	{
//		for (std::list<UFO>:: iterator i = UFOEnemies.begin(); i!= UFOEnemies.end(); ++i)
//		{
//			CheckIfInUFO;
//		}
//	}
//}