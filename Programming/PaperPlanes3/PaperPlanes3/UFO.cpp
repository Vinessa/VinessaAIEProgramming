#include "UFO.h"
#include <list>
using std::list


UFO::UFO(void)
{
	Sprite("./images/UFO.png", 10, 32, 32, 298, -64,.5,.25);
	

}


UFO::~UFO(void)
{
}


void UFO::FireWeapon()
{
	bullet::FireBullet();

}

bool Sprite:: TestonScreen()
{
	int iXVariable = 50;
	if ((m_Position.GetX() > (ciScreenX - iXVariable) || m_Position.GetX() < (ciScreenX - (ciScreenX - iXVariable) )))
	{
		m_Speed.SetX (m_Speed.GetX() * -1);
		//m_Speed.SetY (m_Speed.GetY() + .01);
		iXVariable + 10;
		//m_Position.SetX(m_Position.GetX() - 5);
		//m_Position.SetY(m_Position.GetY() - 5);
		return true;
	}
	else if (m_Position.GetY() > (ciScreenY + m_Sprite_H)) /*|| m_Position.GetY() < (ciScreenY - ciScreenY)*/
		{
			m_Position.SetY(ciScreenY - ciScreenY);
			//m_Speed.SetY (m_Speed.GetY() == 1);
			m_Speed.SetX (m_Speed.GetX() * -1);
			return true;
		}
	return false;
}