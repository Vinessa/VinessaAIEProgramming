// By Vinessa

#pragma once
#ifndef _GAME_ENTITY_H_
#define _GAME_ENTITY_H_
#include "Sprite.h"
#include "Animations.h"


class GameEntity :
	public Sprite
{
public:


	GameEntity(void);
	GameEntity(const char* a_TextureName, int a_iEntityWidth, int a_iEntityHeight, tbyte::Vector4 a_v4MaterialColor, GLFWwindow* Window);
	~GameEntity(void);

	Animations RunRight;
	Animations RunLeft;
	Animations Jump;

	void AnimateHalfSecond(Animations &a_AnimationName);
	void AnimateSecond(Animations &a_AnimationName);
	

	void Input();
	void Animate(Animations &a_AnimationName);
	Vi_Timer PlaySpeedTimer;
	

	/*void Move();
	void Scale();
	void PlayAnimation();
	void StopAnimation();*/

	
};

#endif //_GAME_ENTITY_H_
