#include "Bullet_Class.h"
#include "Class_Sprite.h"

//CONSTRUCTORS/////////////////////////

Bullet::Bullet(void)
{
}

Bullet::Bullet(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_X, float a_Position_Y, float a_Velocity_X, float a_Velocity_Y, char a_AggressionType)
{
	
	Init(a_TextureName, a_Sprite_W,  a_Sprite_H, a_Position_X, a_Position_Y);
	m_SpriteID = CreateSprite( m_TextureName, m_Sprite_W, m_Sprite_H, true );
	MoveSprite(m_SpriteID, m_Position.GetX(),m_Position.GetY());
	m_IsAlive = false;
	a_AggressionType = m_AggressionType; 
}
Bullet::~Bullet(void)
{
}

//MEMBER FUNCTIONS//////////////////////
float BulletSpeed = 1;
void Bullet::FireBullet(Vector2D a_Position)
{
	SetPosition(a_Position);
	m_Velocity.SetY(-BulletSpeed);
	m_IsAlive = true;
}

void Bullet::Respawn() 
{
	if (TestOnScreen())
	{

		m_Position.SetX(50);
		m_Position.SetY(50);
		m_Velocity.SetX(0);
		m_Velocity.SetY(0);
		m_IsAlive = false;
	}
	/*SetSpeed(Speed);
	SetPosition(Place);
	IsAlive = true;*/
	//BulletLocation = SpawnPosition;
	//BulletVelocity = SpawnVelocity;
}

void Bullet::UpdateBullet()
{

	m_Position += m_Velocity;
	TestOnScreen();
	Respawn();
}

