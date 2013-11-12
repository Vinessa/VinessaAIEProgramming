#pragma once

#include "Vector2D.h"


class CircleCollider
{
public:
	CircleCollider(void);
	~CircleCollider(void);
	float GetRadius(){return m_radius;}
	Vector2D GetCenter(){return m_center;}
	void SetRadius(float a_radius){m_radius = a_radius;}
	void SetCenter(Vector2D a_center){m_center = a_center;}
	bool CheckCollision(CircleCollider a_OtherCircle);


private:
	float m_radius;
	Vector2D m_center;

};

