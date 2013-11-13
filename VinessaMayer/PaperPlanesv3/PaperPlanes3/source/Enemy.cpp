///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Enemy.cpp
// Author:			Vinessa Mayer
// Date Created:	October 2013
// Brief:			Enemy Class CPP (Originally for PaperPlanes)
// Note: Sub Class of Class_Sprite.
// Copyright: Vinessa Mayer 2013
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Enemy.h"

/////////CONSTRUCTERS AND DESTRUCTORS///////////////////////

Enemy::Enemy()
{
}

Enemy::Enemy(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_X, float a_Position_Y, float a_Velocity_X, float a_Velocity_Y, int a_Health, float* PlayerScore)
{
	score = PlayerScore;
	time = 0;
	Init(a_TextureName, a_Sprite_W,  a_Sprite_H, a_Position_X, a_Position_Y);
	m_SpriteID = CreateSprite( m_TextureName, m_Sprite_W, m_Sprite_H, true );
	m_EnemyHealth = a_Health;
	IsAlive = true;
	m_SpriteType = 'E';
	m_Velocity = Vector2D(a_Velocity_X, a_Velocity_Y);
	m_Collider.SetRadius(16.0f);
	for( i=0; i < 40; i++)
	{
		Bullet* EnemyBullet = new Bullet("./images/RedLazerPaperClip16x64.png",8,32, -10, -10, 0, 0,'E',1);
		EBullets.push_back(EnemyBullet);
	}
}

Enemy::~Enemy()
{
}

//MEMBER FUNCTIONS///////////////////////
void Enemy::CheckForPewPewPew(float dt)//CHECKS TO SEE IF ITS TIME TO SHOOT
{
	{
		time += dt;
		if(time > .5){
			time = 0;
			for (std::list<Bullet *>::iterator it=EBullets.begin(); it != EBullets.end(); ++it)
			{
				if(!(*it)->IsAlive())
				{
					(*it)->FireLazer(GetPosition());
					return;
				}
			}
		}
	}

} 
bool Enemy:: TestOnScreen_Enemy()//CHECKS TO SEE IF THE ENEMY IS STILL ONSCREEN AND DOES APPROPRIATE STUFF
{
	if ((m_Position.GetX() > (m_iScreenX) || m_Position.GetX() < (m_iScreenX - (m_iScreenX) )))
	{
		m_Velocity.SetX (m_Velocity.GetX() * -1);
	}
	else if( (m_Position.GetY() > (m_iScreenY + m_Sprite_H))||( m_Position.GetY() < (m_iScreenY - m_iScreenY)))
	{
		m_Position.SetY(0);
		m_Velocity.SetX (m_Velocity.GetX() * -1);
		return true;
	}
	return false;
} 

void Enemy::UpdatePosition() // UPDATES POSITION
{
	m_Position.SetX(m_Position.GetX() + m_Velocity.GetX());
	m_Position.SetY(m_Position.GetY() + m_Velocity.GetY());
}

void Enemy::UpdateEnemy(float dt)
{
	UpdatePosition();
	BulletCollisionCheck();
	TestOnScreen_Enemy();
	CheckForPewPewPew(dt);
	Move();
	Draw();
	m_Collider.SetCenter(m_Position);

	for (std::list<Bullet*>::iterator it= EBullets.begin(); it != EBullets.end(); ++it)
	{
		if((*it)->IsAlive())
		{
			(*it)->UpdateLazer();
			(*it)->Move();
			(*it)->Draw();
		}

	}
}
std::list<Bullet*>Enemy::GetBulletList()
{
	return EBullets;
}
void Enemy::SetBulletList(std::list<Bullet*> a_list)
{

	BulletList = std::list<Bullet*>(a_list);
}

void Enemy::BulletCollisionCheck()
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


void Enemy::Die()
{

	m_Velocity.SetX(0);
	m_Velocity.SetY(0);
	m_Position.SetX(-500);
	m_Position.SetY(-500);
	*score += 100;
	IsAlive = false;
}


void Enemy::TakeDamage()
{

	if (m_EnemyHealth > 0)
	{
		--m_EnemyHealth;
	}
	else
	{
		Die();
	}
}

