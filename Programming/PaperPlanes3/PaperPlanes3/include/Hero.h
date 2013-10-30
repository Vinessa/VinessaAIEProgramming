#ifndef _HERO_H_
#define _HERO_H_
#include "Class_Sprite.h"
#include "Bullet_Class.h"
#include "AIE.h"
#include <list>

class Hero :
	public Sprite
{
public:
	//CONSTRUCTORS & DESTRUCTOR//
	Hero(void);
	Hero(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_x, float a_Position_y, float a_Velocity_X, float a_Velocity_Y, int a_Health);
	~Hero(void);

	//MEMBER FUNCTIONS///////////////////////
	void UpdateHero();
	void CheckForFire(); // change back to bool


	//VARIABLES/////////////////////////////
	bool IsAlive; //Alive or Dead? >^._.^<
	int m_HeroHealth; //Current Health
	char m_SpriteType; //E= Enemy, F= Friendly, H = Hero
	std::list<Bullet> HBullets;
	int i;
};

#endif //_HERO_H_