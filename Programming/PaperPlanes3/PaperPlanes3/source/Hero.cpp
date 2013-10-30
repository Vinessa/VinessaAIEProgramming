#include "Hero.h"
#include "Bullet_Class.h"

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
	//HeroBullet = Bullet("./images/Bullet.png",4, 4, 10, 10, 0, 0,'H');
	Vector2D tempPosition(200,300);
	//HeroBullet.SetPosition(tempPosition);
	//std::list<Bullet>HeroBullets(20, Bullet("./images/Bullet.png",4, 4, 10, 10, 0, 0,'H'));
	for( i=0; i < 20; i++)
	{
		Bullet HeroBullet("./images/Bullet.png",4, 4, 10, 10, 0, 0,'H');
		HBullets.push_back(HeroBullet);
	}
}


Hero::~Hero(void)
{
}

//MEMBER FUNCTIONS///////////////////////
float time =0;
void Hero::CheckForFire()/// change back to bool
{


	if(GetMouseButtonDown(MOUSE_BUTTON_1))
	{
		time += GetDeltaTime();
		if(time > .1){
			time = 0;
		for (std::list<Bullet>::iterator it=HBullets.begin(); it != HBullets.end(); ++it)
		{
			//HBullets.FireBullet(GetPosition());
			if(!it->IsAlive())
			{
				it->FireBullet(GetPosition());
				return;
			}
		}
		}
	}
	
}

int MouseX;
int MouseY;
void Hero::UpdateHero()
{
	GetMouseLocation(MouseX, MouseY);
	m_Position.SetX (MouseX);
	m_Position.SetY (MouseY);
	CheckForFire();
	Move();
	Draw();
	for (std::list<Bullet>::iterator it=HBullets.begin(); it != HBullets.end(); ++it)
		{
			if(it->IsAlive())
	{
		it->UpdateBullet();
	it->Move();
	it->Draw();
	}

}
}