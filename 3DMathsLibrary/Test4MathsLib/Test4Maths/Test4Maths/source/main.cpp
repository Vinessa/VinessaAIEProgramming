//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <crtdbg.h>
#include <iostream>
#include "Vector2Tests.h"
#include "Vector3Tests.h"
#include "Vector4Tests.h"
#include "Matrix3Tests.h"




char theend;

int main( int argc, char* argv[] )
{	
	Vector2Tests V2s;
	Vector3Tests V3s;
	Vector4Tests V4s;
	Matrix3Tests M3s;

	V2s.SetData();
	V2s.RunTestAll();
	
	V3s.SetData();
	V3s.RunTestAll();

	V4s.SetData();
	V4s.RunTestAll();

	M3s.SetData();
	M3s.RunTestAll();

 cin >> theend;



	return 0;
}

