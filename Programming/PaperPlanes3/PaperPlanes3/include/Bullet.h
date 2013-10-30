#ifndef _BULLET_H_
#define _BULLET_H_
#include "Class_Sprite.h"
#include <list>

class Bullet :
	public Sprite
{
public:
	Bullet(void);
	Bullet(Sprite, Vector2D BulletVelocity);
	Bullet(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, Vector2D a_Position, Vector2D a_Velocity);
	~Bullet(void);

	bool CheckIfAlive();
	//void Die();
	void Respawn(/*Vector2D SpawnPosition, Vector2D SpawnVelocity*/);
	void Spawn();
	void Update_Bullet();
	//int Damage;
	bool IsAlive;
	void FireBullet();
	bool TestOnScreen_Bullet();
	//bool TestBulletCollision();
	bool CheckIfInHero();
	bool CheckCollisionHero();
	bool IsBulletAlive();


	char m_BulletType; //E= Enemy, F = Friendly, H = Hero


	float m_Velocity_X;
	float m_Velosity_Y;
	float m_Position_X;
	float m_Position_Y;

//	Vector2D SpawnPosition(int,int);
//	Vector2D SpawnVelocity(int,int);
	//Vector2D BulletVelocity(m_Velocity_X, m_Velocity_Y)
	Vector2D BulletVelocity;
	Vector2D BulletLocation;
	Vector2D FireVelocity(int,int);
	Vector2D FirePosition(Vector2D);


};
#endif
