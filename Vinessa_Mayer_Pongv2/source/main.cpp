//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include "Pong_Functions.h"
#include "Pong_Defines.h"

//const int iScreenWidth = 1280;
//const int iScreenHeight = 780;

int main( int argc, char* argv[] )
{	
		Initialise(SCREEN_X, SCREEN_Y, false );

	initGame();
		do 
		{
		//ClearScreen();
		updateGame();
		drawGame();
		
	} while ( FrameworkUpdate() == false );

	//destroyGame();
	//Shutdown();



	return 0;
}



