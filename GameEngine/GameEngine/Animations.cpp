// by Vinessa
#include "Animations.h"


Animations::Animations(void)
{
}

Animations::Animations(float a_U0, float a_V0, float a_U1, float a_V1, float a_U2, float a_V2, float a_U3, float a_V3, float a_AniOffsetU, float a_AniOffsetV, int a_LengthInFrames)
{
	//Initial UV locations for the first frame in this animation
	StartUV0.m_fX = a_U0;
	StartUV0.m_fY = a_V0;

	StartUV1.m_fX = a_U1;
	StartUV1.m_fY = a_V1;

	StartUV2.m_fX = a_U2;
	StartUV2.m_fY = a_V2;

	StartUV3.m_fX = a_U3;
	StartUV3.m_fY = a_V3;
	

	//the amount that the UV is offset to go to the next frame in the animation (Usually 1/Number of frames on the U or V)
	m_AnimationOffsetU = a_AniOffsetU;
	m_AnimationOffsetV = a_AniOffsetV;

	CurrentFrame = 0;

	//The Length of the animation in frames
	m_LengthInFrames = a_LengthInFrames;
}

Animations::~Animations(void)
{
}
