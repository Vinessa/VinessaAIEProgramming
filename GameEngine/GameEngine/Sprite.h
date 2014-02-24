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

class Sprite: public Quad
{
public:
	Sprite(void);
	~Sprite(void);
	Sprite(const char*, int, int, tbyte::Vector4 a_v4Color,GLFWwindow*,float a_AniOffsetU,float a_AniOffsetV,float Z_Position, tbyte::Vector3 UVCoord1,tbyte::Vector3 UVCoord2,tbyte::Vector3 UVCoord3,tbyte::Vector3 UVCoord4);

	void Draw();
	void Input();
	void SetVertexData(Vertex* a_vertexData);
	const Vertex* GetVertexData() const;
	void AnimateRunR();
	void AnimateRunL();
	void AnimateJump();
	//void Animate();




private:
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
	GLFWwindow * GameWindow;
	double m_UCoord;
	double m_VCoord;

	
	
	



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
	Vi_Timer PlaySpeedTimer;
	float DT;
};
#endif //_SPRITE_H_