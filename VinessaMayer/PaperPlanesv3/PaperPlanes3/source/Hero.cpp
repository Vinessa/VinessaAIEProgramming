///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Hero.cpp
// Author:			Vinessa Mayer
// Date Created:	October 2013
// Brief:			Hero Class CPP (Originally for PaperPlanes)
// Note: Sub Class of Class_Sprite.
// Copyright: Vinessa Mayer 2013
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Hero.h"


//CONSTRUCTORS & DESTRUCTOR//
Hero::Hero()
{
}

Hero::Hero(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_X, float a_Position_Y, float a_Velocity_X, float a_Velocity_Y, int a_Health)
{

	Init(a_TextureName, a_Sprite_W,  a_Sprite_H, a_Position_X, a_Position_Y);
	m_SpriteID = CreateSprite( m_TextureName, m_Sprite_W, m_Sprite_H, true );
	m_HeroHealth = a_Health;
	IsAlive = true;
	m_SpriteType = 'H';
	Vector2D Velocity (a_Velocity_X, a_Velocity_Y);
	m_Collider.SetRadius(8.0f);
	Vector2D tempPosition(200,300);
	m_DeathID = CreateSprite( "./images/Crumpled_Plane.png", m_Sprite_W, m_Sprite_H, true );
	m_RespawnID = CreateSprite( "./images/HERO2.png", m_Sprite_W, m_Sprite_H, true );
	Score = 0;
	Lives = 1;


	BulletList = std::list<Bullet*>();
	for( i=0; i < 20; i++)
	{
		Bullet* HeroBullet = new Bullet("./images/BlueLazerPaperClip16x64.png",8, 32, 10, 10, 0, 0,'H', 1);
		HBullets.push_back(HeroBullet);
	}
}


Hero::~Hero(void)
{
}

//MEMBER FUNCTIONS///////////////////////
float atime =0;
void Hero::CheckForFire(float dt)
{


	if(GetMouseButtonDown(MOUSE_BUTTON_1))
	{
		atime +=dt;
		if(atime > .1){
			atime = 0;
			for (std::list<Bullet *>::iterator it=HBullets.begin(); it != HBullets.end(); ++it)
			{
				if(!(*it)->IsAlive())
				{
					(*it)->FireBullet(GetPosition());
					return;
				}
			}
		}
	}
}

float Hero::GetLives() //GETTER FOR NUMBER OF LIVES HERO HAS
{
	return Lives;
}
void Hero::Respawn() // REMOVES A LIFE, OF PLAYER IS NOT OUT OF LIVES CHANGES THE SPRITE TO THE LIVE VERSION AND SETS ISALIVE TO ALIVE AGAIN
{
	--Lives;

	if (Lives >=0 )
	{
		m_SpriteID = m_RespawnID;
		IsAlive = true;
	}
}

void Hero::UpdateHero(float dt) //UPDATES HERO TO FOLLOW MOUSE, CHECKS TO SEE IF RESPAWN IS NEEDED.
{
	if(IsAlive== false)
	{
		RespawnTimer.UpdateCountdown();
		if (RespawnTimer.IsTimeUp())
		{
			Respawn();
		}
	}
	BulletCollisionCheck();
	GetMouseLocation(MouseX, MouseY);
	m_Position.SetX (MouseX);
	m_Position.SetY (MouseY);
	CheckForFire(dt);
	Move();
	m_Collider.SetCenter(m_Position);
	Draw();
	for (std::list<Bullet *>::iterator it=HBullets.begin(); it != HBullets.end(); ++it)
	{
		if((*it)->IsAlive())
		{
			(*it)->UpdateBullet();
			(*it)->Move();
			(*it)->Draw();
		}

	}
}

std::list<Bullet *> Hero::GetBulletList() //GET ENEMY BULLET LIST FOR COLLISION
{
	return HBullets;
}
void Hero::SetBulletList(std::list<Bullet *> a_list)
{

	BulletList.insert(BulletList.end(), a_list.begin(), a_list.end());
}

void Hero::Die() //KILLS PLAYER, SETS RESPAWN TIMER
{
	RespawnTimer.SetTimer(1);
	m_SpriteID = m_DeathID;
	IsAlive = false;
}

void Hero::TakeDamage() // REMOVES HEALTH FROM PLAYER AND REMOVES SCORE, CALLS DIE FUNCTION IF NO MORE HEALTH
{

	if (m_HeroHealth > 0)
	{
		--m_HeroHealth;
		if(Score > 0)
			Score -= 100;

	}
	else
	{
		Die();
	}
}
void Hero::BulletCollisionCheck() // CHECKS TO SEE IF ENEMY BULLETS ARE INSIDE PLAYER, IF SO, CALLS TAKEDAMAGE FUNCTION
{
	for (std::list<Bullet *>::iterator IT = BulletList.begin(); IT != BulletList.end(); ++IT)
	{
		if((*IT)->IsAlive())
		{
			if(m_Collider.CheckCollision((*IT)->m_Collider))
			{
				TakeDamage();
				((*IT)-> TakeDamage());
			}
		}
	}
}



