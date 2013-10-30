/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File: Class_Sprite.h (PaperPlanes)
// Author: Vinessa Mayer
// Date Created: October 15th 2013
// Brief: header for custom Sprite Class originally made for PaperPlanes, but intended for later use.
// Copyright: Vinessa Mayer 2013
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _CLASS_SPRITE_H_
#define _CLASS_SPRITE_H_

#include "Vector2D.h"
class Sprite
{
public:

	Sprite();
	Sprite(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_X, float a_Position_Y, float a_Velocity_X, float a_Velocity_Y);
	Sprite(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, Vector2D a_Position); //Bullet
	Sprite(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_X, float a_Position_Y); //UFO and Heros
	~Sprite();

	void Init(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_X, float a_Position_Y);
	void Draw();
	void Move();
	void Update();
	int GetSpriteID();
	bool TestOnScreen();
	Vector2D GetPosition();

	void SetPosition(Vector2D pos);

	const char *m_TextureName;
	int m_Sprite_W;
	int m_Sprite_H;
	Vector2D m_Position;



	unsigned int m_SpriteID;

};

#endif