//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <crtdbg.h>
#include <iostream>
#include "Vector2Tests.h"
#include "vector3Tests.h"





char theend;

int main( int argc, char* argv[] )
{	
	Vector2Tests V2s;
	Vector3Tests V3s;

	V2s.SetData();
	V2s.RunTestAll();
	
	V3s.SetData();
	V3s.RunTestAll();

 cin >> theend;



	return 0;
}

