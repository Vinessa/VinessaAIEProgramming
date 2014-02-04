#ifndef _SPRITE_H_
#define _SPRITE_H_


#include "Utilities.h"
#include"Quad.h"
#include <Soil.h>

class Sprite: public Quad
{
public:
	Sprite(void);
	~Sprite(void);
	Sprite( const char*, int, int, tbyte::Vector4,GLFWwindow*);
	void Draw();
	void Input();

private:
	Vertex m_aoVerts[4];
	float * modelMatrix;

	tbyte::Vector2 m_v2Scale;
	tbyte::Vector3 m_v3Position;
	tbyte::Vector4 m_v4SpriteColor;

	unsigned int m_uiTexture;
	GLFWwindow * GameWindow;

	//this part below will be used later...

	unsigned int m_uSourceBlendMode;
	unsigned int m_uDestinationBlendMode;
	int tex_loc;
	int matrix_location;
};