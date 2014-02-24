#pragma once
#include "sprite.h"
class GameEntity :
	public Sprite
{
public:


	GameEntity(void);
	GameEntity(const char* a_TextureName, int a_iEntityWidth, int a_iEntityHeight, tbyte::Vector4 a_v4MaterialColor, GLFWwindow* Window, float a_AniOffsetU,float a_AniOffsetV,float Z_Position, tbyte::Vector3 UVCoord1,tbyte::Vector3 UVCoord2,tbyte::Vector3 UVCoord3,tbyte::Vector3 UVCoord4);
	~GameEntity(void);

	void Move();
	void Scale();
	void PlayAnimation();
	void StopAnimation();

	tbyte::Vector2 Velocity;
};

