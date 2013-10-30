//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include <cstring>
using namespace std;



int main( int argc, char* argv[] )
{	
	char cAskName[] = "What is your name? \n";
	char cGotName[] = "Your name is";
	char cUserName [25];

	cout<< cAskName;
	cin >> cUserName;
	cout<< cGotName << cUserName;


	return 0;
}

