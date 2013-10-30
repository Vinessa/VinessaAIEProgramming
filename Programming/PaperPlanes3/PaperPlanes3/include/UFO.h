#ifndef _UFO_H_
#define _UFO_H_

#include "Class_Sprite.h"
class UFO :
	public Sprite
{
public:
	UFO(void);
	UFO(Sprite, Vector2D BulletVelocity);
	UFO(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, Vector2D a_Position, Vector2D a_Velocity);
	~UFO(void);

	bool TestonScreen_UFO(); //Sees if the UFO is on screen, if not it will move it to the top of the screen to loop around
	void FireWeapon(); // Uses a timer to fire a bullet every second (Updates timer as well)
	void TakeDamage(); // Will see if a bullet 
	void Update_UFO();

	int m_UFOHealth; //Current Health
	char m_SpriteType; //E= Enemy, F= Friendly, H = Hero
	//bool HasBeenShot;
	bool IsAlive;
	Vector2D UFOVelocity; //Current UFO Velosity
	Vector2D UFOPosition; //Current UFO Position
	Vector2D SpawnPosition(Vector2D a_Position); //Saves the starting location in a variable for use later when resetting position
	Vector2D SpawnVelocity(Vector2D a_Velocity); // Saves the starting velocity in a variable for later use when resetting velocity
};
#endif
