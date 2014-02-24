#pragma once
#include "sprite.h"
class GameEntity :
	public Sprite
{
public:


	GameEntity(void);
	GameEntity(const char* a_TextureName, int a_iEntityWidth, int a_iEntityHeight, tbyte::Vector4 a_v4MaterialColor, GLFWwindow* Window);
	~GameEntity(void);

	void Move();
	void Scale();
	void PlayAnimation();
	void StopAnimation();

	tbyte::Vector2 Velocity;
};

