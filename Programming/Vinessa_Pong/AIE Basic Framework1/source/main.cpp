//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include <map>
using namespace std;

//Very basic action functions

void Walk()
{
	cout<<"You walk along the path before you.\n";
}

void Jump()
{
	cout<<"You leap through the air.\n";
}

void Attack()
{
	char WeaponChoice = ' ';
	int iSDamage;
	int iFDamage;
	cout<<"Will you use your sword or fist?\n";
	cin>> (WeaponChoice);
	switch(WeaponChoice)
	{
		case 'sword':
		aEnemyHealth[iEnemy]-= iSDamage;
}

void Sleep()
{
	cout<<"You fall asleep.\n";
}

void Eat()
{
	cout<<"You enjoy a Snack.\n";
}

void Drink()
{
	cout<<"You enjoy a refreshing Drink.\n";
}
void Run()
{
	cout<<"You sprint ahead!\n";
}
void Escape()
{
	cout<<"You run away to safety!\n";
}

void Die()
{
	cout<<"You have died.\n";
}

int main( int argc, char* argv[] )
{	
	// iPHealth = Player Health
	int iPHealth = 100;
	//Enemy identifier variable obtained by user input
	int iEnemy;
	
	return 0;
}

