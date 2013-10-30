#include "StdAfx.h"
#include "Vector2D.h"


Vector2D::Vector2D(void)
{
	x = 0;
	y = 0;
}

Vector2D::Vector2D (fXPosition,fYPosition)
{
x = fXPosition;
y = fYPosition;
}



Vector2D::~Vector2D(void)
{
}

void Vector2D::Subtract(Vector2D &v)
{
	x = x - v.x;

	y = y - v.y;
}

void Vector2D::Add(Vector2D &v)
{
	x = x + v.x;

	y = y + v.y;
}

float Dot(Vector2D &v, Vector2D &v2)
{

return (v2.x*v.x)+(v2.y*v.y);
}
