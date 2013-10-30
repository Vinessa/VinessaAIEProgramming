/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // File: SpriteClass.cpp (PaperPlanes)
 // Author: Vinessa Mayer
 // Date Created: Oct 8th 2013
 // Brief: Cleass .cpp for Sprites
 // Copyright: Vinessa Mayer 2013
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Vector2D.h"
#include "Class_Sprite.h"
Sprite::Sprite()
{
	iWidth = a_iWidth;
	iHeight = a_iHeight;
	Position = Vector2D (fXPosition,fYPosition);
	Velosity = Vector2D (fXPosition,fYPosition);
	m_uiSpriteID = -1;
}

Sprite::Sprite(const char* a_pTextureName, int a_iWidth, int a_iHeight, bool a_bDrawFromCenter = true, SColour a_sColour = SColour(0xFF,0xFF,0xFF,0xFF) );
{   m_uiSpriteID = -1;
	iWidth = a_iWidth;
	iHeight = a_iHeight;
	Position = Vector2D (fXPosition,fYPosition);
	Velosity = Vector2D (fXPosition,fYPosition);
	m_pTextureName = *a_pTextureName;
	m_uiSpriteID = CreateSprite (a_pTextureName, int a_iWidth, int a_iHeight, bool a_bDrawFromCenter = true, SColour a_sColour = SColour(0xFF,0xFF,0xFF,0xFF) );
{

Sprite::Draw();
{
	DrawSprite( unsigned int a_uiSpriteID );
}