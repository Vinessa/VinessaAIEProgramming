#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "Main.h"
#include "Class_Sprite.h"
#include "Bullet_Class.h"
#include "AIE.h"
#include <list>

class Enemy :
	public Sprite
{
public:
	//CONSTRUCTORS & DESTRUCTOR//
	Enemy(void);
	Enemy(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_x, float a_Position_y, float a_Velocity_X, float a_Velocity_Y, int a_Health);
	~Enemy(void);
	
	
	//MEMBER FUNCTIONS///////////////////////
	void UpdateEnemy(float dt);
	void FireLazer();
	void CheckForPewPewPew(float dt);
	bool TestOnScreen_Enemy();
	void TakeDamage();
	std::list<Bullet*> GetBulletList();
	void SetBulletList(std::list<Bullet*> a_list);
	void Die();
	void UpdatePosition();

	//VARIABLES/////////////////////////////
	bool IsAlive; //Alive or Dead? >^._.^<
	int m_EnemyHealth; //Current Health
	char m_SpriteType; //E= Enemy, F= Friendly, H = Hero
	void BulletCollisionCheck();
	std::list<Bullet *> EBullets;
	std::list<Bullet *> BulletList;
	
	int i;
	float time;
};

#endif