// While Loop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string catname;
	string quit ("Q");

	
	cout<< "Here is a Cat. >^..^<\nWhat will you name it?\n";
	
	getline (cin, catname);

	do
	{
	
		cout<< "What kind of name is " << catname << "?\nIf you would like to rename your cat do so now, or type Q to Quit\n";
		getline (cin, catname);

	} while (catname.compare(quit) !=0);

	return 0;
}

