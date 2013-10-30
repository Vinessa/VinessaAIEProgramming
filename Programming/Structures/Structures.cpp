// Structures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Point2D
	{
	float x, y;
	};

struct Character
{
	char cName[10];
	int  iScore;
	float fHealth;
	Point2D origin;
	Point2D velocity;

};

int _tmain(int argc, _TCHAR* argv[])

{
	Character a = {"bob",10,1.5f,0.0,0.0,1,1};
	a.iScore = 10;
	a.fHealth = 100;
	Point2D org = {1,1};
	a.origin = org;

	if(a.fHealth < 1)
		cout << "Bob has died! x_x\n";
	else
		cout << "Bob is A - OK\n";


	return 0;
}

