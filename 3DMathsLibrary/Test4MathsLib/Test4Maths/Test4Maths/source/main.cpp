//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <crtdbg.h>
#include <iostream>
#include "Vector2Tests.h"





char theend;

int main( int argc, char* argv[] )
{	
	Vector2Tests Addition;

	Addition.SetData();
	Addition.RunTestAll();

 cin >> theend;



	return 0;
}

