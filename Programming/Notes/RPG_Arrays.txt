// RPG_Array2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int aEnemyHealth [5] = {100,100,100,100,100};
	int iEnemy;
	int iDamage;
	cout<<"ENEMIES HAVE APPEARED!\n\n";
	bool bWin = false;
	while(!bWin){



	cout<< "Enemy 0   Enemy 1   Enemy 2   Enemy 3   Enemy 4\n";
	cout<<" ____      ____      ____      ____      ____\n";
	cout<<"(@  @)    (@  @)    (@  @)    (@  @)    (@  @)\n";
	cout<<" VVVV      VVVV      VVVV      VVVV      VVVV\n\n";
	cout<<" ";
	cout<< aEnemyHealth[0];
	cout<<"       ";
	cout<< aEnemyHealth[1];
	cout<<"       ";
	cout<< aEnemyHealth[2];
	cout<<"       ";
	cout<< aEnemyHealth[3];
	cout<<"       ";
	cout<< aEnemyHealth[4];
	cout<<"       \n";
	cout<<"Enter a number to select which enemy you will Attack!\n";
	
	cin>> (iEnemy);
	cout<<"How much Damage will your attack do?\n";
	cin>> (iDamage);
	cout << "You attack Enemy ";
	cout << (iEnemy);
	cout << " for ";
	cout << (iDamage);
	cout << " damage!\n\n";

	aEnemyHealth[iEnemy]-= iDamage;
	bWin = true;
	for(int i = 0;i <5; i++)
	{
		if(aEnemyHealth[i] > 0)
		{
			bWin = false;
			break;
		}
	}
	

	}
	cout << "YOU ARE VICTORIOUS!";
	return 0;
}

