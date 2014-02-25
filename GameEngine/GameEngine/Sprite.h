//By Vinessa

#pragma once
#ifndef _SPRITE_H_
#define _SPRITE_H_
#include "GlobalUtilities.h"
#include"Quad.h"
#include <SOIL.h>
#include <gl\glew.h>
#include <GL/glfw3.h>
#include "Vi_Timer.h"
#include "Animations.h"

class Sprite: public Quad
{
public:
	Sprite(void);
	~Sprite(void);
	Sprite(const char*, int, int, tbyte::Vector4 a_v4Color,GLFWwindow*);

	void Draw();
	//virtual void Input();
	void SetVertexData(Vertex* a_vertexData);
	const Vertex* GetVertexData() const;
	void AnimateRunR();
	void AnimateRunL();
	void AnimateJumpRight();
	void AnimateJumpLeft();
	//void Animate(Animations a_AnimationName);



	GLFWwindow * GameWindow;
//private:
	Vertex m_aoVerts[4];
	tbyte::Matrix4 * modelMatrix;
	tbyte::Matrix4 MVP; 
	tbyte::Vector2 m_v2Scale;
	tbyte::Vector3 m_v3Position;
	tbyte::Vector4 m_v4SpriteColor;

	tbyte::Vector2 m_minUVCoords;
	tbyte::Vector2 m_maxUVCoords;
	tbyte::Vector2 m_uvScale;
	tbyte::Vector2 m_uvOffset;
	unsigned int m_uiTexture;
	

	
	
	



	//this part below will be used later...

	unsigned int m_uSourceBlendMode;
	unsigned int m_uDestinationBlendMode;
	int tex_loc;
	int matrix_location;
	int AnimationFrameRun;
	int AnimationFrameJump;
	//int AnimationFrame;
	float AnimationOffsetU;
	float AnimationOffsetV;
	
	float DT;
};
#endif //_SPRITE_H_