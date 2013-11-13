/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File: Class_Sprite.h (PaperPlanes)
// Author: Vinessa Mayer
// Date Created: October 15th 2013
// Brief: header for custom Sprite Class originally made for PaperPlanes, but intended for later use.
// Copyright: Vinessa Mayer 2013
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Vector2D.h"
#include "CircleCollider.h"
#include <time.h>
#include "AIE.h"

#ifndef _SPRITE_H_
#define _SPRITE_H_

//char array of

//sprintf array name, "what to print (%f)"
//drawstring (arrayname

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

	Vector2D m_Velocity;

	unsigned int m_SpriteID;
	CircleCollider m_Collider;

	int m_iScreenX, m_iScreenY;

};

#endif