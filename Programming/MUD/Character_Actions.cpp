//Character Actions.cpp
//Author: Vinessa Mayer
//Date: September 16th 2013
//Purpose: What is contained in each function being referenced by Character Actions.h
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Character_Actions.h"

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
}

void flee()
{
	cout<<"You attempt to run away to escape danger!";
	float rand;
		srand (time(null));
		rand()%100;
		if (rand > 50);
		{
			cout << "You trip over your own feet and fall to the ground. Your clumbsiness has foiled your escape." << endl;
		}
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

void Die()
{
	cout<<"You have died.\n";
}

void BattleLoop();
// iPHealth = Player Health and Enemy identifier variable obtained by user input
int iPHealth = 100;
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
			break;
					
		case Flee;
			{
			Flee();
			break;