#include "Bullet_Class.h"



//CONSTRUCTORS/////////////////////////

Bullet::Bullet(void)
{
}

Bullet::Bullet(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_X, float a_Position_Y, float a_Velocity_X, float a_Velocity_Y, char a_AggressionType, int a_Health)
{

	Init(a_TextureName, a_Sprite_W,  a_Sprite_H, a_Position_X, a_Position_Y);
	m_SpriteID = CreateSprite( m_TextureName, m_Sprite_W, m_Sprite_H, true );
	MoveSprite(m_SpriteID, m_Position.GetX(),m_Position.GetY());
	m_IsAlive = false;
	a_AggressionType = m_AggressionType; 
	m_Collider.SetRadius(4.0f);
	m_BulletHealth = a_Health;
}
Bullet::~Bullet(void)
{
}

//MEMBER FUNCTIONS//////////////////////
float BulletSpeed = 1.5;
void Bullet::FireBullet(Vector2D a_Position)
{
	SetPosition(a_Position);
	m_Velocity.SetY(-BulletSpeed);
	m_Collider.SetCenter(m_Position);
	m_IsAlive = true;
}

void Bullet::FireLazer(Vector2D a_Position)
{
	SetPosition(a_Position);
	m_Velocity.SetY(+BulletSpeed);
	m_Collider.SetCenter(m_Position);
	m_IsAlive = true;
}

void Bullet::Respawn() 
{

	m_Position.SetX(-50);
	m_Position.SetY(-50);
	m_Velocity.SetX(0);
	m_Velocity.SetY(0);
	m_IsAlive = false;
}

void Bullet::CheckRespawn() 
{
	if (TestOnScreen())
	{
		Respawn();
	}
	
}



void Bullet::TakeDamage()
{

	if (m_BulletHealth > 0)
	{
		--m_BulletHealth;
	}
	else
	{
		Respawn();
	}
}

void Bullet::UpdateBullet()
{

	m_Position += m_Velocity;
	m_Collider.SetCenter(m_Position);
	TestOnScreen();
	CheckRespawn();
}

void Bullet::UpdateLazer()
{

	m_Position += m_Velocity;
	m_Collider.SetCenter(m_Position);
	TestOnScreen();
	CheckRespawn();
}

//bool Bullet::EnemyCollisionCheck()
//{
//	for (std::list<Enemy>::iterator IT = UFOWave.begin(); IT != UFOWave.end(); ++IT)
//	{
//		if ((((m_Position.GetX()) < (IT -> m_Position.GetX() + (IT-> m_Sprite_W /2))&& 
//		((m_Position.GetX()) > (IT -> m_Position.GetX() - (IT -> m_Sprite_W /2))) && 
//		(((m_Position.GetY()) < (IT -> m_Position.GetY() + (IT -> m_Sprite_H /2))&& 
//		((m_Position.GetY()) >= (IT -> m_Position.GetY() - (IT-> m_Sprite_H /2))))))))
//
//	{
//
//return true;
//
//	}
//}
//}