//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
using namespace std;



int main( int argc, char* argv[] )
{
	int num1 = 5, *pNum1 = &num1;
	int num2 = 7, *pNum2 = &num2;

	int pNumDiff = pNum2 - pNum1;
	pNum1 += 10; 
	pNum2++;

	int i = *(pNum1+3);

	cout<< pNum1 << endl <<
		pNum2 << endl <<
		pNumDiff << endl <<
		i;

	return 0;
}

