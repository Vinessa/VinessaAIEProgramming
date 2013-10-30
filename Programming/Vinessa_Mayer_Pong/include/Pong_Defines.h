/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // File: Pong_Defines.h (V's Pongy Pong)
 // Author: Vinessa Mayer
 // Date Created: September 25th 2013
 // Brief: Collection of global variables and structs used within V's Pongy Pong. An exercise as part of Year 1 Semester 1 Game Programming.
 // Copyright: Vinessa Mayer 2013
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once // I am noting that #pragma once is not industry standard and is discouraged, however in this case they were added as part of troubleshooting and I do not yet understand why it doesn't like to function without pragma and with just normal guards. I will make a point of learning this after assessment.
#ifndef _PONG_DEFINES_
#define _PONG_DEFINES_

#include <ctime>
#include <stdlib.h>

const float fSpeed = 10; //BASE SPEED (PADDLES) NOT DIRECTLY USED ITSELF, BUT USED IN PART OF SPEED BUFF AND DEFUFF MODIFIERS
const float fHalfSpeed = fSpeed / 2; //HALFSPEED IS THE SPEED OF AN UNHINDERED BUT BUFFED SPEED
const float fQuarterSpeed = fHalfSpeed / 2; //QUARTERSPEED DOESN'T APPEAR TO BE USED CURRENTLY = CONSIDER REMOVING TO CONSERVE MEMORY
const float fTinySpeed = fQuarterSpeed / 2; //TINYSPEED IS THE SPEED OF AN UNHINDERED AND UNBUFFED SPEED AND A HINDERED AND BUFFED SPEED
const float fSnailSpeed = fTinySpeed / 2; //SNAILSPEED IS THE SPEED OF AN UNBUFFED BUT HINDERED SPEED
const int ciScreenX = 900; // WINDOW SIZE IN THE X AXIS (HORIZONTAL) (WIDTH)
const int ciScreenY = 800; // WINDOW SIZE IN THE Y AXIS (VERTICAL) (HEIGHT)
const int ciScreenHalfW = ciScreenX / 2; // HALF THE HORIZONAL WINDOW SIZE AS MENTIONED ABOVE = MAY NOT BE USED.
const int ciScreenHalfH = ciScreenY / 2; // HALF THE VERTICAL WINDOW SIZE A MENTIONED ABOVE = MAY NOT BE USED.

const int ciPlayer1X = 30; //PLAYER1'S POSITION ON THE X AXIS. THIS VALUE DOESN'T CHANGE (CHANGE PLACES FUNCTION IS DISBLED)
const int ciPlayer1W = 50; //PLAYER1'S DIMENTIONS IN THE X AXIS (WIDTH)
const int ciPlayer1H = 125;//PLAYER 1'S DIMENTIONS IN THE Y AXIS (HEIGHT)

const int ciPlayer2X = 870; //PLAYER2'S POSITION ON THE X AXIS. THIS VALUE DOESN'T CHANGE (CHANGE PLACES FUNCTION IS DISBLED)
const int ciPlayer2W = 50; //PLAYER2'S DIMENTIONS IN THE X AXIS (WIDTH)
const int ciPlayer2H = 125;//PLAYER2'S DIMENTIONS IN THE Y AXIS (HEIGHT)

const int ciBallW = 64; //BALL'S DIMENTIONS IN THE X AXIS (WIDTH)
const int ciBallH = 64; //BALL'S DIMENTIONS IN THE Y AXIS (HEIGHT)


//STRUCTS
struct vector2{ // STRUCTURE STATING THE VELOSITY OF OF WHATEVER = USED IN BALL MOVEMENT AND SPEED
	float X;
	float Y;
};

struct movableObject //STRUCTURE FOR A MOVING OBJECT USED IN BALL AND PADDLES
{
	vector2 Position;
	vector2 Speed;
	int Sprite;
	int Width;
	int Height;
};


#endif