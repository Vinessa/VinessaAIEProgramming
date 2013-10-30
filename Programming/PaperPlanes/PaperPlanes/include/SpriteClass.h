/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // File: SpriteClass.h (PaperPlanes)
 // Author: Vinessa Mayer
 // Date Created: Oct 8th 2013
 // Brief: Class header file for Sprites
 // Copyright: Vinessa Mayer 2013
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _SPRITECLASS_H_
#define _SPRITECLASS_H_

class Sprite
{
public:
	Sprite(void); //default constructor
	Sprite(int a_fWidth, int a_fHeight, float a_fYPosition, float a_fXPosition, char *a_pTextureName, bool a_bDrawFromCenter);
	Sprite.Draw ( unsigned int a_uiSpriteID );
	~Sprite(void);//destructor

	
private:
	int m_fWidth;
	int m_fHeight;
Vector2D Position;
Vector2D Velosity;
	char *m_pTextureName;
	unsigned int m_uiSpriteID;
};

#endif
 
Sprite(5, 10, 1.0, 1.0, "filename") Tom;
int IntegerVariable;

Sprite player;

DrawSprite(Tom.m_uiSpriteID);

for (all my sprites) //iterator is 'i'
{
	i.Draw()