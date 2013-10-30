
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // File: main.cpp (V's Pongy Pong)
 // Author: Vinessa Mayer
 // Date Created: September 25th 2013
 // Brief: Main function of the game V's Pongy Pong. An exercise as part of Year 1 Semester 1 Game Programming.
 // Copyright: Vinessa Mayer 2013
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include "Pong_Functions.h"
#include "Pong_Defines.h"



int main( int argc, char* argv[] )
{	
	GameState eCurrentState = TITLE;
	Initialise(ciScreenX, ciScreenY, false );

	InitGame();

	do
	{
		switch(eCurrentState)
		{
		case TITLE:
			InitiateTitle();
			ClearScreen();
			DrawTitle();
			CheckForStart (eCurrentState);
			CheckForQuit (eCurrentState);

			break;

		case GAME_STATE:
			do 
			{
				ClearScreen();
				UpdateGame();
				DrawGame();

				CheckForQuitFromInGame(eCurrentState);
				DeclareWinnerPlayer1(eCurrentState);
				DeclareWinnerPlayer2(eCurrentState);
				FrameworkUpdate();

			} while ( eCurrentState == GAME_STATE);
			break;

		case P1WIN:
			{
			InitiateP1Win();
			ClearScreen();
			DrawP1Win();
			CheckForMenu (eCurrentState);
			CheckForQuit (eCurrentState);
			
			break;
			}

		case P2WIN:
			{
			InitiateP2Win();
			ClearScreen();
			DrawP2Win();
			CheckForMenu (eCurrentState);
			CheckForQuit (eCurrentState);
			
			break;
			}

		case END_STATE:
			{
			DestroyGame();
			Shutdown();
			return 0;
			break;
			}

		default:
			{
				break;
			}
		} //Closes the Switch loop
	}//Closes the do loop
	while (FrameworkUpdate() == false);
} //closes main





