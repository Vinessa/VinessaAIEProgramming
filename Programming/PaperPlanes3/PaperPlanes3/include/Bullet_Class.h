#ifndef _BULLET_CLASS_H_
#define _BULLET_CLASS_H_
#include "Class_Sprite.h"
#include "AIE.h"

class Bullet:
	public Sprite
{

public:
	Bullet(void);
	Bullet(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_x, float a_Position_y, float a_Velocity_X, float a_Velocity_Y, char AggressionType);
	~Bullet(void);
	void FireBullet(Vector2D a_Pos);
	void UpdateBullet();
	void Respawn();
	bool IsAlive(){return m_IsAlive;}
private:
	/*float RespawnPosition_X;
	float RespawnPosition_Y;
	float RespawnVelocity_X;
	float RespawnVelocity_Y;*/

char m_AggressionType; //'E' = Enemy, 'H' = Hero, 'F' = Friendly
bool m_IsAlive;
Vector2D m_Velocity;
};
#endif// _BULLET_CLASS_H_