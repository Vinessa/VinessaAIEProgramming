#include "UFO.h"
//#include <list>
//using std::list
//
//	////CONSTRUCTORS/////////////////////////////////////////////////
//
//	UFO::UFO(void)
//{
//	Sprite("./images/UFO.png", 32, 32, 298, -64);
//	IsAlive = true;
//	m_SpriteType = "E";
//
//}
//
//UFO::UFO(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, Vector2D a_Position, Vector2D a_Velocity, int a_UFOHealth)
//{
//	a_UFOHealth = m_UFOHealth;
//	Sprite(a_TextureName,32,32,a_Position);
//	IsAlive = true;
//	m_SpriteType = 'E';
//	GetPosition();
//}
//
//
//UFO::~UFO(void)
//{
//}
//
////// FUNCTIONS ////////////////////////////////////////////////////////////////////////////
//
//void UFO::TakeDamage()
//{
//	while (IsAlive = true)
//		if (Bullet::TestBulletCollision = true)
//		{
//			--m_UFOHealth;
//		}
//		
//}
//
//void UFO::FireWeapon()
//{
//	Timer::SetTimer(1);
//	if (Timer::IsTimeUp() == true)
//	{
//		bullet::FireBullet();
//	}
//	else
//	{
//		UpdateCountdown();
//	}
//}
//
//bool UFO:: TestonScreen_UFO()
//{
//	int iXVariable = 50;
//	if ((m_Position.GetX() > (ciScreenX - iXVariable) || m_Position.GetX() < (ciScreenX - (ciScreenX - iXVariable) )))
//	{
//		return true;
//	}
//	else if (m_Position.GetY() > (ciScreenY + m_Sprite_H)) || m_Position.GetY() < (ciScreenY - ciScreenY)*/
//	{
//		return true;
//	}
//
//	return false;
//}
//
//void UFO::Respawn() 
//{
//	/*SetSpeed(Speed);
//	SetPosition(Place);
//	IsAlive = true;*/
//	UFOposition = SpawnPosition;
//	UFOVelocity = SpawnVelocity;
//	IsAlive = false;
//}
//
//bool UFODeath()
//{
//	if(m_UFOHealth < 1)
//	{
//		return true;
//	}
//}
//
//void UFO::Update_UFO()
//{
//
//	if(IsAlive == true)
//	{
//		UFOPosition + UFOVelosity;
//		FireWeapon();
//	}
//	if(UFODeath() == true)
//	{
//		Respawn();
//
//	}
//
//}
