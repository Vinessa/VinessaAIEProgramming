// By Vinessa
#pragma once
#ifndef _ANIMATIONS_H_
#define _ANIMATIONS_H_
#include "GlobalUtilities.h"
class Animations
{
public:
	Animations(void);
	Animations(float a_U1, float a_V1, float a_U2, float a_V2, float a_U3, float a_V3, float a_U4, float a_V4,  float a_AniOffsetU, float a_AniOffsetV, int a_LengthInFrames);
	~Animations(void);

	//Animation Variables

	Vector2 StartUV0;
	Vector2 StartUV1;
	Vector2 StartUV2;
	Vector2 StartUV3;

	float m_AnimationOffsetU;
	float m_AnimationOffsetV;

	int m_LengthInFrames;
	int CurrentFrame;

};
#endif //_ANIMATIONS_H_
