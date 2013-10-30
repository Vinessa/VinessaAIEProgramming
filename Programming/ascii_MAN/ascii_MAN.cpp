// ascii_MAN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

	void Man()
{
	cout<<"  0\n" << " -|- \n" << " / \\\n";
}

int _tmain(int argc, _TCHAR* argv[])
{// for( Loop starting position = 0; 5 Positions in Loop; Loop position +1)
	for(int i = 0;i <5; i++)
	{
	Man();
	}
	return 0;
}



