// 3DMathsLibrary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector3.h"
#include <iostream>;
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Vector3 SomeVector(12,3,24); //Creates a 3D Vector
	Vector3 SomeVectorB(-3, 10,2);

	//Does the maths, returns and assigns the magnitude to float "Magnitude" for storage.
	cout <<"Magnitude\n"<< SomeVector.GetMagnitude3D()<<"\n\n"; // Prints the value of Magnitude

	SomeVector.GetDotProduct3D(SomeVectorB);
	cout <<"DotProduct:\n";
	cout << SomeVector.GetDotProduct3D(SomeVectorB) <<"\n";

	return 0;
}

