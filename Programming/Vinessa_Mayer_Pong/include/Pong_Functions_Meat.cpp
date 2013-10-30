///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // File: Pong_Functions_Meat.cpp (V's Pongy Pong)
 // Author: Vinessa Mayer
 // Date Created: September 25th 2013
 // Brief: The meat of all custom functions used within the game V's Pongy Pong. An exercise as part of Year 1 Semester 1 Game Programming.
 // Copyright: Vinessa Mayer 2013
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 


#include "Pong_Defines.h"
#include "Pong_Functions.h"
#include "AIE.h"
#include <time.h>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <stdio.h>

movableObject Player1 = {ciPlayer1X, 100, 0, 0, -1 , ciPlayer1W, ciPlayer1H}; // DEFINING PLAYER 1
movableObject Player2 = {ciPlayer2X, 620, 0, 0, -1, ciPlayer2W, ciPlayer2H}; // DEFINING PLAYER 2
movableObject Ball = {500, 500, 1,1, -1, ciBallW, ciBallH}; // DEFINING BALL
int uiPlayer1Score = 0; // MAKING A SPACE IN MEMORY FOR PLAYER 1'S SCORE
int uiPlayer2Score = 0; // MAKING A SPACE IN MEMORY FOR PLAYER 2'S SCORE
unsigned int uiBackgroundImage = -0;// MAKING A SPACE IN MEMORY FOR BG IMAGE'S SPRITE
unsigned int uiBackgroundImageTitle = -0; // MAKING A SPACE IN MEMORY FOR BG IMAGE TITLE'S SPRITE
unsigned int uiBackgroundImageP1Win = -0; // MAKING A SPACE IN MEMORY FOR BG IMAGE P1WIN'S SPRITE
unsigned int uiBackgroundImageP2Win = -0; // MAKING A SPACE IN MEMORY FOR BG IMAGE P2WIN'S SPRITE

// CREATES A SPACE FOR THE GAME SPRITES IN MEMORY AND CREATES THE WINDOW IN IT'S PREDEFINED SIZE.
void InitGame()
{
	srand((int)time(0));

	uiBackgroundImage = CreateSprite( "./images/voidgrid.png", ciScreenX, ciScreenY, true );
	MoveSprite(uiBackgroundImage, ciScreenX>>1, ciScreenY>>1);

	Player1.Sprite = CreateSprite( "./images/paddle1.png", ciPlayer1W, ciPlayer1H, true );
	Player2.Sprite = CreateSprite( "./images/paddle2.png", ciPlayer2W, ciPlayer2H, true );
	Ball.Sprite = CreateSprite( "./images/Ball.png", ciBallW, ciBallH, true );
	MoveSprite(Player1.Sprite,Player1.Position.X,Player1.Position.Y);
	MoveSprite(Ball.Sprite, Ball.Position.X ,Ball.Position.Y);

}

// Tests to see if Ball is on screen, if it hits a wall, reverses velosity (Speed) value and bumps it away from th edge of the window by 5 pixels to prevent it from getting stuck, Also adds a score to the appropriate place if it hits on the X axis!
bool TestOnScreen(movableObject &obj)
{
	int BallHalfW = Ball.Width / 2;
	int BallHalfH = Ball.Height /2;

	if(obj.Position.X + BallHalfW > ciScreenX)
	{
		obj.Position.X -= 5;
		obj.Speed.X *= -1; 
		uiPlayer1Score++;

		return true;
	}
	else if(obj.Position.X - BallHalfW < 0)
	{
		obj.Position.X += 5;
		obj.Speed.X *= -1;
		uiPlayer2Score++;
		return true;
	}
	else if(obj.Position.Y + BallHalfH > ciScreenY)
	{
		obj.Position.Y -= 5;
		obj.Speed.Y *= -1;
		return true;
	}
	else if(obj.Position.Y - BallHalfH < 0)
	{
		obj.Position.Y += 5;
		obj.Speed.Y *= -1;
		return true;
	}
	return false;
}

// Tests to see if paddle needs to wrap around to the other side of the screen
void PaddleWrapAround(movableObject &obj)
{
	if(obj.Position.Y < 0)
	{
		obj.Position.Y = ciScreenY - 5;
	}

	else if(obj.Position.Y > ciScreenY)
	{
		obj.Position.Y = 5;

	}
}

// CONTROLS BALL MOVEMENT
void BallMovement()
{
	Ball.Position.X += Ball.Speed.X;
	Ball.Position.Y += Ball.Speed.Y;
}

// DRAWS THE PLAYER NAME AND SCORES ON SCREEN ON TOP OF THE OTHER SPRITES.
void DrawScores()
{
	// Creating the container for scores
	char outScore1[30];
	char outScore2[30];

	// Creating the Content for the score containiers
	sprintf(outScore1, "PLAYER1: %d", uiPlayer1Score);
	sprintf(outScore2, "PLAYER2: %d", uiPlayer2Score);

	//Drawing the scores on the screen
	DrawString(outScore1,5,5, SColour(255,0,0,255));
	DrawString(outScore2, 725, 5, SColour(255,0,0,255));
}

// CREATES A SPACE FOR THE TITLE SPRITES IN MEMORY AND CREATES THE WINDOW IN IT'S PREDEFINED SIZE.
void InitiateTitle ()
{
	uiBackgroundImageTitle = CreateSprite( "./images/title.png", ciScreenX, ciScreenY, true );
	MoveSprite(uiBackgroundImageTitle, ciScreenX>>1, ciScreenY>>1);
}

// DRAWS THE SPRITES PREVIOUSLY INITIATED ON SCREEN AND MOVES THEM.
void DrawTitle ()
{
	DrawSprite(uiBackgroundImageTitle);
}

// CREATES A SPACE FOR THE PLAYER 1 WIN STATE SPRITES IN MEMORY AND CREATES THE WINDOW IN IT'S PREDEFINED SIZE.
void InitiateP1Win ()
{
	uiBackgroundImageP1Win = CreateSprite( "./images/P1WIN.png", ciScreenX, ciScreenY, true );
	MoveSprite(uiBackgroundImageP1Win, ciScreenX>>1, ciScreenY>>1);

}

// DRAWS THE SPRITES PREVIOUSLY INITIATED ON SCREEN AND MOVES THEM.
void DrawP1Win ()
{
	DrawSprite(uiBackgroundImageP1Win);

}

// CREATES A SPACE FOR THE PLAYER 2 WIN STATE SPRITES IN MEMORY AND CREATES THE WINDOW IN IT'S PREDEFINED SIZE.
void InitiateP2Win ()
{
	uiBackgroundImageP2Win = CreateSprite( "./images/P2WIN.png", ciScreenX, ciScreenY, true );
	MoveSprite(uiBackgroundImageP2Win, ciScreenX>>1, ciScreenY>>1);
}

// DRAWS THE SPRITES PREVIOUSLY INITIATED ON SCREEN AND MOVES THEM.
void DrawP2Win ()
{
	DrawSprite(uiBackgroundImageP2Win);

}

// DRAWS THE SPRITES PREVIOUSLY INITIATED ON SCREEN AND MOVES THEM.
void DrawGame ()
{
	DrawSprite(uiBackgroundImage);
	DrawSprite(Player1.Sprite);
	DrawSprite(Player2.Sprite);
	DrawSprite(Ball.Sprite);
	MoveSprite(Player1.Sprite, Player1.Position.X,Player1.Position.Y );
	MoveSprite(Player2.Sprite, Player2.Position.X,Player2.Position.Y );
	DrawScores();
}

//SIMPLIFIED PADDLE MOVEMENT

bool CheckPlayerMovementVertSimp()
{
	if (IsKeyDown(KEY_SPECIAL+27)) // DOWN ARROW (P2 VERTICAL MOVEMENT DOWN)
	{
		Player2.Position.Y -= fTinySpeed; // CHANGE P2 SPEED TO TINYSPEED
		return true;
	}

	else
		if (IsKeyDown(KEY_SPECIAL+28)) //UP ARROW (P2 VERTICAL MOVEMENT UP)
		{
			Player2.Position.Y += fTinySpeed; // CHANGE P2 SPEED TO TINYSPEED
			return true;
		}

		else
			if(IsKeyDown('W')) // W (P1 VERTICAL MOVEMENT UP)
			{
				Player1.Position.Y -= fTinySpeed; // CHANGE P1 SPEED TO TINYSPEED
				return true;
			}

			else
				if(IsKeyDown('S')) // S (P1 VERTICAL MOVEMENT DOWN)
				{
					Player1.Position.Y += fTinySpeed; // CHANGE P1 SPEED TO TINYSPEED
					return true;
				}

				else
					if(IsKeyDown(KEY_SPECIAL+27)&& // DOWN ARROW (P2 VERTICAL MOVEMENT DOWN)
						(IsKeyDown('S'))) // S (P1 VERTICAL MOVEMENT DOWN)
					{
						Player1.Position.Y += fTinySpeed;
						Player2.Position.Y -= fTinySpeed;
						return true;
					}

					else
						if(IsKeyDown(KEY_SPECIAL+28)&& //UP ARROW (P2 VERTICAL MOVEMENT UP)
							(IsKeyDown('W'))) // W (P1 VERTICAL MOVEMENT UP)
						{
							Player1.Position.Y -= fTinySpeed;
							Player2.Position.Y += fTinySpeed;
							return true;
						}

						else
							if(IsKeyDown(KEY_SPECIAL+27)&& // DOWN ARROW (P2 VERTICAL MOVEMENT DOWN)
								(IsKeyDown('W'))) // W (P1 VERTICAL MOVEMENT UP)
							{
								Player1.Position.Y -= fTinySpeed; 
								Player2.Position.Y -= fTinySpeed;
								return true;
							}
							else 
								if(IsKeyDown(KEY_SPECIAL+28)&& //UP ARROW (P2 VERTICAL MOVEMENT UP)
									(IsKeyDown('S'))) // S (P1 VERTICAL MOVEMENT DOWN)
								{
									Player2.Position.Y += fTinySpeed;
									Player1.Position.Y += fTinySpeed;
									return true;
								}
				return false;
}


/*/PADDLE MOVEMENT AND SPEED BUFFS / DEBUFFS
bool CheckPlayerMovementVert()

{
	// SPEED BUFF + DEBUFF
	if (IsKeyDown(KEY_SPECIAL+28)&& //UP ARROW (P2 VERTICAL MOVEMENT UP)
		(IsKeyDown(KEY_SPECIAL+32)&& // RIGHT SHIFT (BUFF)
		(IsKeyDown(KEY_SPECIAL+33)))) // LEFT CTRL (P1 DEBUFF)
	{
		Player2.Position.Y += fTinySpeed; // CHANGE P2 SPEED TO TINYSPEED
		return true;
	}
	else
		if (IsKeyDown(KEY_SPECIAL+27)&& // DOWN ARROW (P2 VERTICAL MOVEMENT DOWN)
			(IsKeyDown(KEY_SPECIAL+32)&& // RIGHT SHIFT (BUFF)
			(IsKeyDown(KEY_SPECIAL+33)))) // LEFT CTRL (P1 DEBUFF)
		{
			Player2.Position.Y -= fTinySpeed; // CHANGE P2 SPEED TO TINYSPEED
			return true;
		}
		else
			if(IsKeyDown('W')&& // W (P1 VERTICAL MOVEMENT UP)
				(IsKeyDown(KEY_SPECIAL+31)&& // LEFT SHIFT (BUFF)
				(IsKeyDown(KEY_SPECIAL+34)))) // RIGHT CTRL (P2 DEBUFF)
			{
				Player1.Position.Y -= fTinySpeed; // CHANGE P1 SPEED TO TINYSPEED
				return true;
			}

			else
				if(IsKeyDown('S')&& // S (P1 VERTICAL MOVEMENT DOWN)
					(IsKeyDown(KEY_SPECIAL+31)&& // LEFT SHIFT (BUFF)
					(IsKeyDown(KEY_SPECIAL+34)))) // RIGHT CTRL (P2 DEBUFF)
				{
					Player1.Position.Y += fTinySpeed; // CHANGE P1 SPEED TO TINYSPEED
					return true;
				}
				// + SPEED BUFF

				if (IsKeyDown(KEY_SPECIAL+28)&& //UP ARROW (P2 VERTICAL MOVEMENT UP)
					(IsKeyDown(KEY_SPECIAL+32))) // RIGHT SHIFT (BUFF)
				{
					Player2.Position.Y += fHalfSpeed; // CHANGE P2 SPEED TO HALFSPEED
					return true;
				}
				else
					if (IsKeyDown(KEY_SPECIAL+27)&& // DOWN ARROW (P2 VERTICAL MOVEMENT DOWN)
						(IsKeyDown(KEY_SPECIAL+32)))// RIGHT SHIFT (BUFF)
					{
						Player2.Position.Y -= fHalfSpeed; // CHANGE P2 SPEED TO HALFSPEED
						return true;
					}
					else
						if(IsKeyDown('W')&& // W (P1 VERTICAL MOVEMENT UP)
							(IsKeyDown(KEY_SPECIAL+31))) // LEFT SHIFT (BUFF)
						{
							Player1.Position.Y -= fHalfSpeed; // CHANGE P1 SPEED TO HALFSPEED
							return true;
						}

						else
							if(IsKeyDown('S')&& // S (P1 VERTICAL MOVEMENT DOWN)
								(IsKeyDown(KEY_SPECIAL+31))) // LEFT SHIFT (BUFF)
							{
								Player1.Position.Y += fHalfSpeed; // CHANGE P1 SPEED TO HALFSPEED
								return true;
							}

							// + SPEED DEBUFF

							if (IsKeyDown(KEY_SPECIAL+28)&& //UP ARROW (P2 VERTICAL MOVEMENT UP)
								(IsKeyDown(KEY_SPECIAL+33))) // LEFT CTRL (P1 DEBUFF)
							{
								Player2.Position.Y += fSnailSpeed; // CHANGE P2 SPEED TO SNAILSPEED
								return true;
							}
							else
								if (IsKeyDown(KEY_SPECIAL+27)&& // DOWN ARROW (P2 VERTICAL MOVEMENT DOWN)
									(IsKeyDown(KEY_SPECIAL+33))) // LEFT CTRL (P1 DEBUFF)
								{
									Player2.Position.Y -= fSnailSpeed; // CHANGE P2 SPEED TO SNAILSPEED
									return true;
								}
								else
									if(IsKeyDown('W')&& // W (P1 VERTICAL MOVEMENT UP)
										(IsKeyDown(KEY_SPECIAL+34))) // RIGHT CTRL (P2 DEBUFF)
									{
										Player1.Position.Y -= fSnailSpeed; // CHANGE P1 SPEED TO SNAILSPEED
								return true;
										return true;
									}

									else
										if(IsKeyDown('S')&& // S (P1 VERTICAL MOVEMENT DOWN)
											(IsKeyDown(KEY_SPECIAL+34))) // RIGHT CTRL (P2 DEBUFF)
										{
											Player1.Position.Y += fSnailSpeed; // CHANGE P1 SPEED TO SNAILSPEED
											return true;
										}

										// JUST SPEED, NO BUFFS OR DEBUFFS
										else
											if (IsKeyDown(KEY_SPECIAL+27)) // DOWN ARROW (P2 VERTICAL MOVEMENT DOWN)
											{
												Player2.Position.Y -= fTinySpeed; // CHANGE P2 SPEED TO TINYSPEED
												return true;
											}

											else
												if (IsKeyDown(KEY_SPECIAL+28)) //UP ARROW (P2 VERTICAL MOVEMENT UP)
												{
													Player2.Position.Y += fTinySpeed; // CHANGE P2 SPEED TO TINYSPEED
													return true;
												}

												else
													if(IsKeyDown('W')) // W (P1 VERTICAL MOVEMENT UP)
													{
														Player1.Position.Y -= fTinySpeed; // CHANGE P1 SPEED TO TINYSPEED
														return true;
													}

													else
														if(IsKeyDown('S')) // S (P1 VERTICAL MOVEMENT DOWN)
														{
															Player1.Position.Y += fTinySpeed; // CHANGE P1 SPEED TO TINYSPEED
															return true;
														}


														return false;
}*/

// PADDLE COLLISION AND BALL SPEED VERTS
void CheckPaddleCollision() 
{
	int iSpeed = Ball.Speed.X;
	int BallHalfW = Ball.Width / 2;
	int BallHalfH = Ball.Height / 2;
	int Player1HalfW = Player1.Width / 2;
	int Player1HalfH = Player1.Height / 2;
	int player2HalfW = Player2.Width / 2;
	int player2HalfH = Player2.Height / 2;

	{ // if the Ball is heading in the negative direction( left), check to see if it has hit player 1's paddle.
		if(iSpeed < 0 &&
			Ball.Position.X - BallHalfW < Player1.Position.X + Player1HalfW && 
			Ball.Position.X - BallHalfW > Player1.Position.X - Player1HalfW &&
			Ball.Position.Y > Player1.Position.Y - Player1HalfH &&
			Ball.Position.Y < Player1.Position.Y + Player1HalfH)
		{

			Ball.Speed.X -=  0.3f;

			Ball.Speed.X *=-1;
		}

		else 
		{//If the Ball is heading in the positive direction (Right), Check to see if it has hit player 2's paddle.
			if(iSpeed > 0 &&
				Ball.Position.X + BallHalfW > Player2.Position.X - player2HalfW && 
				Ball.Position.X + BallHalfW < Player2.Position.X + player2HalfW &&
				Ball.Position.Y > Player2.Position.Y - player2HalfH &&
				Ball.Position.Y < Player2.Position.Y + player2HalfH)

			{
				Ball.Speed.Y = std::abs(Ball.Speed.Y);
				Ball.Speed.Y +=  0.2f;

				Ball.Speed.X *=-1;

			}
		}
	}
}

//Checking for CHANGEPLACES!!!!!!!!!!!!! - NOT USED
//bool changePlaces()
//{
//	if (IsKeyDown(32))
//	{
//	Player2.Position.X = SCREENHALFW;
//	Player2.Position.Y = SCREENHALFH - 370;
//
//	Player1.Position.Y = SCREENHALFH + 370;
//	Player1.Position.X = SCREENHALFW;
//
//	//checkPlayerMovementHoriz();
//	return true;
//	}
//
//	return false;
//}






// UPDATE THE GAME
void UpdateGame()
{
	// Create the Container
	// Create the Content
	// Draw the Content

	BallMovement();
	TestOnScreen(Ball);
	MoveSprite(Ball.Sprite, Ball.Position.X,Ball.Position.Y );
	CheckPaddleCollision();
	//changePlaces();
	PaddleWrapAround(Player1);
	PaddleWrapAround(Player2);
	//CheckPlayerMovementVert();
	CheckPlayerMovementVertSimp();
	DrawScores();
}

//DESTROY THE GAME
void DestroyGame() 
{
	DestroySprite(uiBackgroundImage);
	DestroySprite(Player1.Sprite);
	DestroySprite(Player2.Sprite);
	DestroySprite(Ball.Sprite);
}


//CHECK TO SEE IF THE USER HAS SELECTED BACKSPACE (GAMESTATE ONLY) AND CHANGES GAMESTATE TO MENU
bool CheckForMenu (GameState &eCurrentState)
{
	if (IsKeyDown(KEY_BACKSPACE))
	{
		eCurrentState = TITLE;
		return true;
	}

	return false;
}

//CHECK TO SEE IF THE USER HAS SELECTED SPACE (TITLE STATE ONLY) CHANGES CURRENT STATE TO GAME
bool CheckForStart (GameState &eCurrentState)
{
	if (IsKeyDown(KEY_SPACE))
	{
		eCurrentState = GAME_STATE;
		return true;
	}

	return false;
}
//CHECK TO SEE IF THE USER HAS SELECTED ESC (TITLE STATE ONLY) CHANGES CURRENT STATE TO END
bool CheckForQuit (GameState &eCurrentState)
{
	if (IsKeyDown(KEY_ESC)) 
	{
		eCurrentState = END_STATE;
		return true;
	}
	return false;
}
//CHECK TO SEE IF THE USER HAS SELECTED BACKSPACE GAME STATE ONLY SETS CURRENT STATE TO TITLE
bool CheckForQuitFromInGame (GameState &eCurrentState)
{
	if (IsKeyDown(KEY_BACKSPACE))
	{
		eCurrentState = TITLE;
		return true;
	}
	return false;
}

//CHECKS TO SEE IF PLAYER 1 HAS 10 POINTS AND IF PLAYER 2 HAS LESS POINTS THAN PLAYER 1, IF SO, CHANGES CURRENT STATE TO P1WIN.
bool DeclareWinnerPlayer1(GameState &eCurrentState)
{
	if ((uiPlayer1Score == 10)&&
		(uiPlayer2Score < uiPlayer1Score))
	{
		eCurrentState = P1WIN;
		uiPlayer2Score = 0;//RESETS PLAYER SCORES TO 0 SO THEY CAN START A FRESH NEW GAME IF THEY CHOOSE TO DO SO VIA THE MENU.
		uiPlayer1Score = 0;
		Ball.Speed.Y = 1;
		Ball.Speed.X = 1;
		return true;
	}
	return false;
}

//CHECKS TO SEE IF PLAYER 2 HAS 10 POINTS AND IF PLAYER 1 HAS LESS POINTS THAN PLAYER 2, IF SO, CHANGES CURRENT STATE TO P2WIN.
bool DeclareWinnerPlayer2(GameState &eCurrentState)
{
	if((uiPlayer2Score == 10)&&
		(uiPlayer1Score < uiPlayer2Score))
	{
		eCurrentState = P2WIN;
		uiPlayer2Score = 0; //RESETS PLAYER SCORES TO 0 SO THEY CAN START A FRESH NEW GAME IF THEY CHOOSE TO DO SO VIA THE MENU.
		uiPlayer1Score = 0;

		Ball.Speed.Y = 1;
		Ball.Speed.X = 1;
		return true;
	}
	return false;
}