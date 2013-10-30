/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // File: Class_Sprite.h (PaperPlanes)
 // Author: Vinessa Mayer
 // Date Created: October 15th 2013
 // Brief: header for custom Sprite Class originally made for PaperPlanes, but intended for later use.
 // Copyright: Vinessa Mayer 2013
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _CLASS_SPRITE_H_
#define _CLASS_SPRITE_H_

class Sprite
{
	public:

		Sprite();
		Sprite(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_X, float a_Position_Y, float a_Speed);
		Sprite(const char* a_TextureName, float a_Health, int a_Sprite_W, int a_Sprite_H, float a_Position_X, float a_Position_Y, float a_Speed);
		~Sprite();

		void DrawSprite();
		void Move();
		void LoseHealth();

	private:
		char m_TextureName;
		float m_Health;
		int m_Sprite_W;
		int m_Sprite_H;

		float m_Position_X;
		float m_Position_Y;

		float m_Speed;

		int SpriteID;

};

#endif