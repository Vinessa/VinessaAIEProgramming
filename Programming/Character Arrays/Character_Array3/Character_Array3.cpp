// Character_Array3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;


int main( int argc, char* argv[] )
{	
	//char cAskName[] = "What is your name? \n";
	//char cGotName[] = "Your name is ";
	//char cUserName [25];

	//cout<< cAskName;
	//cin.getline(cUserName,24);
	//cout<< cGotName << cUserName << endl;

	//------------------------------------------
	// Defines array type as "char", The name of the array as cUserInput, [Length of Array]
	char cUserInput[257];
	// requests user input as a string, assigns the input to the array (cUserInput, availiable characters)<- Make avaliable characters one less than room in array to make room for null character "/0".
	cin.getline(cUserInput,256);
	//Start of FOR LOOP (Defines stored variable as Int, with a value of/ starting position at 0; Variable is less than strlen ("String Length" default function) of the User Input Variable; Move i to the next position in the array.
	for(int i = 0;i <strlen(cUserInput); i++)
	{ 
		//If the charcter in array position i is equal to a space ('==' = "checks if equal to") 
		if(cUserInput[i] == ' ')
			// then make the character in array position i = an underscore ('=' assigns a value to)
			cUserInput[i] = '_';
	}
	return 0;
}
