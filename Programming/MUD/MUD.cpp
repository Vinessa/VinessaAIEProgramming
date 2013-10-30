//////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include <map>
#include "time.h"
using namespace std;


int main( int argc, char* argv[] )
{	
	// iPHealth = Player Health
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

	flee();

	return 0;
}

