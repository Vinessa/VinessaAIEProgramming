///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			CircleCollider.cpp
// Author:			Justin Loudermilk
// Date Created:	November 2013
// Brief:			CircleCollider CPP (Originally for PaperPlanes)
// Copyright: Justin Loudermilk 2013
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "CircleCollider.h"


CircleCollider::CircleCollider(void)
{
}


CircleCollider::~CircleCollider(void)
{
}


bool CircleCollider::CheckCollision(CircleCollider a_OtherCircle)
{
	float lhs, rhsX, rhsY;

	lhs = (m_radius * m_radius) + (a_OtherCircle.GetRadius() * a_OtherCircle.GetRadius() );

	rhsX = m_center.GetX() -a_OtherCircle.GetCenter().GetX();
	rhsY = m_center.GetY() -a_OtherCircle.GetCenter().GetY();

	if(lhs > (rhsX *rhsX)+ (rhsY*rhsY))
	{
		return true;
	}
	return false;
}