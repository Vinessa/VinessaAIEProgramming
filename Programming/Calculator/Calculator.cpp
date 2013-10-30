// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;



float Add(float fFirstNumber, float fSecondNumber)
{
	return fFirstNumber + fSecondNumber;
}

float Subtract(float fFirstNumber, float fSecondNumber)
{
	return fFirstNumber - fSecondNumber;
}

float Multiply(float fFirstNumber, float fSecondNumber)
{
	return fFirstNumber * fSecondNumber;
}

float Divide(float fFirstNumber, float fSecondNumber)
{
	return fFirstNumber / fSecondNumber;
}


int _tmain(int argc, _TCHAR* argv[])
{
	float fInput1;
	float fInput2;
	char Choice = ' ';
	float fResult;
	cin >> (fInput1);
	cin >> (fInput2);
	cin >> (Choice);

	switch(Choice) 
	{
	case '+':
		fResult = Add(fInput1,fInput2);
		break;
	case '-':
		fResult = Subtract(fInput1,fInput2);
		break;
	case '*':
		fResult = Multiply(fInput1,fInput2);
		break;
	case '/':
		fResult = Divide(fInput1,fInput2);
		break;
	}
	
	cout<<fResult;
	return 0;
}

