//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include <map>
#include <time>
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
	
void flee()
	cout << "You attempt to run away to escape danger!";
	float rand;
		srand (time(null));
		rand()%100;
		if (rand > 50);
		{
			cout << "You trip over your own feet and fall to the ground. Your clumbsiness has foiled your escape." << endl;
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
	/*// iPHealth = Player Health
	int iPHealth = 100;
	//Enemy identifier variable obtained by user input
	int iEnemy;

	//Battle Loop
	char ActionChoice;
	cout << "Will you ATTACK or FLEE?" << endl;
	cin >> (ActionChoice);

	switch(ActionChoice)

		case Attack;
			{
			Attack();
			}

*/
	flee();

	return 0;
}

