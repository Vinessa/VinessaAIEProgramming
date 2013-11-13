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
	m_RespawnID = CreateSprite( "./images/HERO.png", m_Sprite_W, m_Sprite_H, true );
	Score = 1000;
	Lives = 3;
	

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
void Hero::CheckForFire(float dt)/// change back to bool
{


	if(GetMouseButtonDown(MOUSE_BUTTON_1))
	{
		atime +=dt;
		if(atime > .1){
			atime = 0;
			for (std::list<Bullet *>::iterator it=HBullets.begin(); it != HBullets.end(); ++it)
			{
				//HBullets.FireBullet(GetPosition());
				if(!(*it)->IsAlive())
				{
					(*it)->FireBullet(GetPosition());
					return;
				}
			}
		}
	}
}

float Hero::GetLives()
{
	return Lives;
}
void Hero::Respawn()
{
	--Lives;
	
	if (Lives >=0 )
	{
	m_SpriteID = m_RespawnID;
	IsAlive = true;
	}
}
int MouseX;
int MouseY;
void Hero::UpdateHero(float dt)
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

std::list<Bullet *> Hero::GetBulletList()
{
	return HBullets;
}
void Hero::SetBulletList(std::list<Bullet *> a_list)
{

	BulletList.insert(BulletList.end(), a_list.begin(), a_list.end());
}

void Hero::Die()
{
	RespawnTimer.SetTimer(3);
	m_SpriteID = m_DeathID;
	IsAlive = false;
}

void Hero::TakeDamage()
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
void Hero::BulletCollisionCheck()
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



