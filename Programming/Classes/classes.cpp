// classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector2D.h"

int _tmain(int argc, _TCHAR* argv[])
{//(Type of Object "Vector2D"(predefined class that you made in Vector2D.h and Vector2D.cpp) "Vec" = name of the object created.(follows the parameters of the class you set up)
	Vector2D Vec;
	Vec.x = 1;
	Vec.y = 1;

	Vector2D sub;
	sub.x = 1;
	sub.y = 0;

	Vec.Subtract(sub);
	//Vec.x = 0, Vec.y = 1
	float dot = Vec.Dot(sub);
	
	return 0;
}

