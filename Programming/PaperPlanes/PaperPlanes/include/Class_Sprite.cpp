

#include <time.h>
#include "AIE.h"
#include "Class_Sprite2.h"


Sprite::Sprite()
{
		m_TextureName = NULL;
		m_Sprite_W = 64;
		m_Sprite_H = 64;
		m_Position_X = 0;
		m_Position_Y = 0;

		m_Speed = 0,0;
		SpriteID = -1;
}

Sprite::Sprite(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_X, float a_Position_Y, float a_Speed_X, float a_Speed_Y)
{
	m_TextureName = a_TextureName;
	
	m_Sprite_W = a_Sprite_W;
	m_Sprite_H = a_Sprite_H;
	
	m_Position = Vector2D(a_Position_X,a_Position_Y);

	m_Speed = Vector2D(a_Speed_X, a_Speed_Y);
	SpriteID = CreateSprite( m_TextureName,m_Sprite_W,m_Sprite_H,true );
}

Sprite::Sprite(const char* a_TextureName, float a_Health, int a_Sprite_W, int a_Sprite_H, float a_Position_X, float a_Position_Y, float a_Speed_X, float a_Speed_Y)
{
	m_TextureName = a_TextureName;
	m_Health = a_Health;
	
	m_Sprite_W = a_Sprite_W;
	m_Sprite_H = a_Sprite_H;
	
	m_Position = Vector2D(a_Position_X,a_Position_Y);

	m_Speed = Vector2D(a_Speed_X, a_Speed_Y);

	SpriteID = CreateSprite( m_TextureName, m_Sprite_W, m_Sprite_H, true );
}

Sprite::~Sprite()
{

}

void Sprite::DrawTheSprite()

{

	DrawSprite(SpriteID);
}

