/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // File: Pong_Functions.h (V's Pongy Pong)
 // Author: Vinessa Mayer
 // Date Created: September 25th 2013
 // Brief: Collection of the custom functions and enums used within the game V's Pongy Pong. An exercise as part of Year 1 Semester 1 Game Programming.
 // Copyright: Vinessa Mayer 2013
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once // I am noting that #pragma once is not industry standard and is discouraged, however in this case they were added as part of troubleshooting and I do not yet understand why it doesn't like to function without pragma and with just normal guards. I will make a point of learning this after assessment.
#ifndef _PONG_FUNCTIONS_
#define _PONG_FUNCTIONS_

#include "Pong_Defines.h" // I am noting that requiring a header for a header is discouraged in the standards. I will keep this in mind when composing projects in the future.
#include "AIE.h"

//ENUM GAME STATES
typedef enum GameStates
{
	TITLE, //=== TITLE SCREEN === CAN START GAME OR QUIT
	GAME_STATE, // GAME AND UPDATES ARE RUNNING
	END_STATE, //=== DESTROYS GAME AND SHUTS DOWN ===
	P1WIN, // == NOTIFIES PLAYER 1 OF WIN == CAN RETURN TO MAIN MENU OR QUIT
	P2WIN,// == NOTIFIES PLAYER 1 OF WIN == CAN RETURN TO MAIN MENU OR QUIT

	PLAYER_STATE_COUNT, //5 PLAYER STATES TOTAL

}GameState;

//Protoypes
//GAME AND ASSET CREATION
//GENERAL
void ClearScreen();

//TITLE STATE CREATION
void InitiateTitle(); // CREATES A SPACE FOR THE TITLE SPRITES IN MEMORY AND CREATES THE WINDOW IN IT'S PREDEFINED SIZE.
void DrawTitle(); // DRAWS THE SPRITES FOR THE TITLE SCREEN.
  
//GAME STATE CREATION AND UPDATE
void InitGame(); // CREATES A SPACE FOR THE GAME SPRITES IN MEMORY AND CREATES THE WINDOW IN IT'S PREDEFINED SIZE.
void DrawGame(); // DRAWS THE SPRITES PREVIOUSLY INITIATED ON SCREEN AND MOVES THEM.
void DrawScores(); // DRAWS THE PLAYER NAME AND SCORES ON SCREEN ON TOP OF THE OTHER SPRITES.
void UpdateGame(); //UPDATES THE GAME WITH NEW INFORMATION.


//END STATE CREATION
void DestroyGame(); // DESTROYS ALL THE GAME ASSETS AND WIPES THEM FROM MEMORY.
void Shutdown(); // SHUTS DOWN THE WINDOW NICE AND NEATLY.
	
//PLAYER1 WIN STATE CREATION
void InitiateP1Win (); // CREATES A SPACE FOR THE PLAYER 1 WIN STATE SPRITES IN MEMORY AND CREATES THE WINDOW IN IT'S PREDEFINED SIZE.
void DrawP1Win (); // DRAWS THE SPRITES PREVIOUSLY INITIATED ON SCREEN AND MOVES THEM.

//PLAYER2 WIN STATE CREATION
void InitiateP2Win (); // CREATES A SPACE FOR THE PLAYER 1 WIN STATE SPRITES IN MEMORY AND CREATES THE WINDOW IN IT'S PREDEFINED SIZE.
void DrawP2Win (); // DRAWS THE SPRITES PREVIOUSLY INITIATED ON SCREEN AND MOVES THEM.

//CHECKS
bool TestOnScreen(); // CHECKS TO SEE IF THE BALL HAS HIT THE EDGE OF THE SCREEN, IF SO, IT REVERSES IT'S VELOSITY AND GIVES A PLAYER A POINT IF NEEDED.
void CheckPaddleCollision(); // CHECKS TO SEE IF THE BALL HAS HIT A PADDLE, IF SO, IT REVERSES IT'S VELOSITY AND ALTERS IT'S SPEED A BIT.
//bool CheckPlayerMovementVert(); //CHECKS TO SEE IF A PLAYER IS MOVING VERTICALLY ON THE Y AXIS, ALSO CHECKS PADDLE SPEED BUFFS AND DEBUFFS.
bool CheckPlayerMovementVertSimp();
void PaddleWrapAround(); // ENSURES THAT THE PADDLE WRAPS AROUND TO THE OTHER SIDE OF THE SCREEN WHEN IT REACHES AND EDGE.
bool CheckForStart(GameState &eCurrentState); // ===(DURING MENU/TITLE STATE ONLY)=== CHECKS TO SEE IF THE USER HAS PRESSED SPACE BAR, IF SO, CHANGES THE CURRENT STATE TO GAME_STATE TO BEGIN GAME.
bool CheckForQuitFromInGame (GameState &eCurrentState); // ===(DURING GAME STATE ONLY)=== CHECKS TO SEE IF THE USER HAS PRESSED BACKSPACE, IF SO, CHANGES THE CURRENT STATE TO TITLE TO RETURN USER TO TITLE.
bool CheckForQuit (GameState &eCurrentState); // ===(DURING MENU/TITLE STATE ONLY)=== CHECKS TO SEE IF THE USER HAS PRESSED ESC, IF SO, CHANGES THE CURRENT STATE TO END TO EXIT GAME.
bool DeclareWinnerPlayer1(GameState &eCurrentState); //CHECKS TO SEE IF PLAYER 1 HAS 10 POINTS AND IF PLAYER 2 HAS LESS POINTS THAN PLAYER 1, IF SO, CHANGES CURRENT STATE TO P1WIN.
bool DeclareWinnerPlayer2(GameState &eCurrentState);//CHECKS TO SEE IF PLAYER 2 HAS 10 POINTS AND IF PLAYER 1 HAS LESS POINTS THAN PLAYER 2, IF SO, CHANGES CURRENT STATE TO P2WIN.
bool CheckForMenu (GameState &eCurrentState);//====(DURING P1WIN AND P2WIN STATES ONLY)====CHECKS TO SEE IF THE USER HAS PRESSED BACKSPACE, IF SO, CHANGES THE CURRENT STATE TO TITLE TO RETURN USER TO TITLE.

// UNUSED FUNCTIONS
	//bool checkPlayerMovementHoriz();
	//bool changePlaces();
#endif 