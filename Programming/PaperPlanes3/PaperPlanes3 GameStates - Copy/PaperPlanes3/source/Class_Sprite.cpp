#include "Class_Sprite.h"



Sprite::Sprite()
{
	m_TextureName = "./images/null.png";
	m_Sprite_W = 64;
	m_Sprite_H = 64;
	m_Position = Vector2D(0, 0);

	m_SpriteID = -1;
}

Sprite::Sprite(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_X, float a_Position_Y)
{
	m_TextureName = a_TextureName;

	m_Sprite_W = a_Sprite_W;
	m_Sprite_H = a_Sprite_H;

	m_Position = Vector2D(a_Position_X, a_Position_Y);

	m_SpriteID = CreateSprite( m_TextureName, m_Sprite_W, m_Sprite_H, true );
}

Sprite::Sprite(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_X, float a_Position_Y, float a_Speed_X, float a_Speed_Y)
{
	m_TextureName = a_TextureName;


	m_Sprite_W = a_Sprite_W;
	m_Sprite_H = a_Sprite_H;

	m_Position = Vector2D(a_Position_X, a_Position_Y);


	m_SpriteID = CreateSprite(m_TextureName, m_Sprite_W, m_Sprite_H,true );
}

Sprite::Sprite(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, Vector2D Spawn)
{
	m_TextureName = a_TextureName;

	m_Sprite_W = a_Sprite_W;
	m_Sprite_H = a_Sprite_H;

	Spawn = GetPosition();


	m_SpriteID = CreateSprite(m_TextureName, m_Sprite_W, m_Sprite_H,true );
}

Sprite::~Sprite()
{

}

void Sprite::Init(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_X, float a_Position_Y)
{
	m_TextureName = a_TextureName;

	m_Sprite_W = a_Sprite_W;
	m_Sprite_H = a_Sprite_H;

	m_iScreenX = 1080;
	m_iScreenY = 720;

	m_Position = Vector2D(a_Position_X, a_Position_Y);
}

void Sprite::Move()
{
	MoveSprite(m_SpriteID, m_Position.GetX(),m_Position.GetY());
}
void Sprite::Draw()

{
	//MoveSprite(m_SpriteID, m_Position.GetX(),m_Position.GetY());
	DrawSprite(m_SpriteID);
}

int Sprite::GetSpriteID()
{
	return m_SpriteID;


}

bool Sprite:: TestOnScreen()
{
	int iXVariable = 50;
	if ((m_Position.GetX() > (m_iScreenX) || m_Position.GetX() < (m_iScreenX - (m_iScreenX) )))
	{
		//m_Speed.SetX (m_Speed.GetX() * -1);
		//m_Speed.SetY (m_Speed.GetY() + .01);
		//iXVariable += 10;
		//m_Position.SetX(m_Position.GetX() - 5);
		//m_Position.SetY(m_Position.GetY() - 5);
		return true;
	}
	else if( (m_Position.GetY() > (m_iScreenY + m_Sprite_H))||( m_Position.GetY() < (m_iScreenY - m_iScreenY)))
	{
		//m_Position.SetY(ciScreenY - ciScreenY);
		//m_Speed.SetY (m_Speed.GetY() == 1);
		//m_Speed.SetX (m_Speed.GetX() * -1);
		return true;
	}
	return false;
}
void Sprite::Update()
{
	
	TestOnScreen();
	Move();
	Draw();
}


Vector2D Sprite::GetPosition()
{
	Vector2D Temp;

	Temp.SetX(m_Position.GetX());
	Temp.SetY(m_Position.GetY());

	return Temp;
}


void Sprite::SetPosition(Vector2D pos)
{
	m_Position = pos;
}
