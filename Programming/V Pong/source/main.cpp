//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include <ctime>

const int iLevelWidth = 1280;
const int iLevelHeight = 780;

const int iSPEED = 10;
const int SCREEN_X = 1280;
const int SCREEN_Y = 780;

const int iPLAYER1_X = 100;
const int iPLAYER1_W = 100;
const int iPLAYER1_H = 144;

const int iPLAYER2_X = 1200;
const int iPLAYER2_W = 83;
const int iPLAYER2_H = 128;

int iLevelSize = iLevelHeight * iLevelWidth;

const int iBALL_W = 64;
const int iBALL_H = 92;


// Struct for Vecors
struct vector2{
	float x;
	float y;
};

// Struct for moveable object
struct movableObject{
	vector2 position;
	vector2 speed;
	int sprite;
	int width;
	int height;
};



unsigned int bgImage = -1;
movableObject iPlayer1 = {iPLAYER1_X, 100, 0, 0, -1 , iPLAYER1_W, iPLAYER1_H};
movableObject iPlayer2 = {iPLAYER2_X, 100, 0, 0, -1, iPLAYER2_W, iPLAYER2_H};
movableObject iBall = {500, 500, 5+(rand()%40)/10, 5+(rand()%50)/10, -1, iBALL_W, iBALL_H};

int g_highScores[5] = {0};
bool g_gameOver = false;

//Player score variable declaration and initial value
int player1Score = 0;
int player2Score = 0;
int frameCounter = 0;

//Declaring an enum for Game States
typedef enum GameStates
{
	MENU_STATE,
	GET_USER_INPUT,
	GAME_STATE,
	END
}GameState;

struct Tile
{
	float fXPos;
	float fYPos;
	unsigned int iSpriteID;
};
void initGame() {
	srand(time(0));

	// Now load some sprites
	bgImage = CreateSprite( "./images/Void.png", SCREEN_X, SCREEN_Y, true );
	MoveSprite(bgImage, SCREEN_X>>1, SCREEN_Y>>1);

	iPlayer1.sprite = CreateSprite( "./images/Player1_Paddle.png", iPLAYER1_W, iPLAYER1_H, true );
	iPlayer2.sprite = CreateSprite( "./images/Player2_Paddle", iPLAYER2_W, iPLAYER2_H, true );
	iBall.sprite = CreateSprite( "./images/Ball.png", iBALL_W, iBALL_H, true );

}

void drawGame() {
	static char outScore1[15] = {'\n'};
	static char outScore2[15] = {'\n'};

	DrawSprite(iBall.sprite);
	DrawSprite(iPlayer1.sprite);
	DrawSprite(iPlayer2.sprite);

	sprintf(outScore1, "Player 1: %d", player1Score);
	sprintf(outScore2, "Player 2: %d", player2Score);

	// draw the scores
	DrawString(outScore1, 50, 50, SColour(255,0,0,255));
	DrawString(outScore2, 1000, 50, SColour(0,255,0,255));
	//}

	if(g_gameOver == true) {
		DrawString("Game Over", SCREEN_X / 2, 300);

		char score[15];
		int y = 350;
		for(int i=0; i<5; i++) {
			if(g_highScores[i] != 0) {
				sprintf(score, "player %d: %d", i, g_highScores[i]);
				DrawString(score, SCREEN_X / 2, y);
				y += 30;
			}
		
			{
	DrawSprite(bgImage);
}

int main( int argc, char* argv[] )
{	
	
	float fYOffset = 0.f;

	GameState eCurrentState = GET_USER_INPUT;
	srand( time(NULL) );
	
	do 
	{
		
		//Test the current game state
		switch(eCurrentState)
		{
		case GET_USER_INPUT:
		
		

			// First we need to create our Game Framework
			unsigned int iVisibleLevelHeight = iLevelHeight;
			unsigned int iVisibleLevelWidth = iLevelWidth;
			Initialise( iVisibleLevelWidth, iVisibleLevelHeight , false, "V's Pongy Pong!" );
			unsigned int iSprite = CreateSprite( "./images/Void.png", iLevelWidth, iLevelHeight, false );
			

			eCurrentState = GAME_STATE;
			break;
		
		
		case GAME_STATE:
		
			float fDeltaT = GetDeltaTime();
			ClearScreen();
			if( IsKeyDown('W') )
			{
					fYOffset = 1.f;
			}


			
			break;
		
		default:
			break;
		}//End of Switch Statement


	} while ( FrameworkUpdate() == false );
	
	for( int i = 0; i < iLevelSize; ++i )
	
	Shutdown();

	return 0;
}

