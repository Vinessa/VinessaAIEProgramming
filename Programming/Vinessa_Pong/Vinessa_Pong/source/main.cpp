//////////////////////////////////////////////////////////////////////////
#define _USE_MATH_DEFINES

#include "AIE.h"
#include "KeyCodes.h"
#include <string>
#include <cmath>
#include <assert.h>
#include <crtdbg.h>
#include <ctime>

struct vector2{
	float x;
	float y;
};

struct movableObject{
	vector2 position;
	vector2 speed;
	int sprite;
	int width;
	int height;
};

const int SPEED = 10;
const int SCREEN_X = 1280;
const int SCREEN_Y = 780;

const int PLAYER1_X = 100;
const int PLAYER1_W = 100;
const int PLAYER1_H = 144;

const int PLAYER2_X = 1200;
const int PLAYER2_W = 83;
const int PLAYER2_H = 128;

const int BALL_W = 64;
const int BALL_H = 92;
const int STAR_W = 64;
const int STAR_H = 64;
const int CHERRY_W = 52;
const int CHERRY_H = 52;
const int NYANCAT_W = 250;
const int NYANCAT_H = 250;
const int PONY_W = 250;
const int PONY_H = 264;


// global variables 
unsigned int bgImage = -1;
movableObject player1 = {PLAYER1_X, 100, 0, 0, -1 , PLAYER1_W, PLAYER1_H};
movableObject player2 = {PLAYER2_X, 100, 0, 0, -1, PLAYER2_W, PLAYER2_H};
movableObject ball = {500, 500, 5+(rand()%40)/10, 5+(rand()%50)/10, -1, BALL_W, BALL_H};
movableObject nyanCat = {-NYANCAT_W, rand()%SCREEN_Y, 3, 0, -1, NYANCAT_W, NYANCAT_H};
movableObject pony = {SCREEN_X+PONY_W, rand()%SCREEN_Y, -3, 0, -1, PONY_W, PONY_H};
movableObject stars[30];
movableObject cherries[30];
movableObject nyans[10];
int g_highScores[5] = {0};
bool g_gameOver = false;

//Player score variable declaration and initial value
int player1Score = 0;
int player2Score = 0;
int frameCounter = 0;

// subtract a scalar from a vector, return the result as a new vector
vector2 vectorSubtract(vector2 &v, float s){
	vector2 result = {v.x - s, v.y - s};
	return result;
}

// adds a scalar to a vector, return the result as a new vector
vector2 vectorAdd(vector2 &v, float s){
	vector2 result = {v.x + s, v.y + s};
	return result;
}

// multiplies a vector by a scalar, returns the result as a new vector
vector2 multiplyScalar(vector2 &v, float s){
	vector2 result = {v.x * s, v.y * s};
	return result;
}

// subtract one vector from another, returns the result as a new vector
vector2 vectorSubtract(vector2 &v, vector2 &v2){
	vector2 result = {v.x - v2.x, v.y - v2.y};
	return result;
}

// add one vector to another, returns the result as a new vector
vector2 vectorAdd(vector2 &v, vector2 &v2){
	vector2 result = {v.x + v2.x, v.y + v2.y};
	return result;
}

// get the normal of a vector, returns the result as a new vector
vector2 getNormal(vector2 &v){
	float mag = sqrt(v.x*v.x + v.y*v.y);
	vector2 result = {v.x/mag, v.y/mag};
	return result;
}

// get the magnitude of a vector
float getMagnitude(vector2 &v){
	return sqrt(v.x*v.x + v.y*v.y);
}

// sort an array of integers in descending order
void sort(int array[], int size) {
	for(int i=0; i<size; i++) {
		for(int j=0; j<size; j++) {
			if(array[i] > array[j]) {
				int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;				
			}
		}	
	}
}

// will test if an object has gone outside the screen boundaries
// if the object has gone off the screen, this function will also modify
// the objects speed so that it will move back onto the screen
// returns true if the object's x or y coordinate is off the screen
bool testOnScreen(movableObject& obj){
	if(obj.position.x > SCREEN_X) {
		obj.speed.x *= -1;
		return true;
	}
	if(obj.position.x < 0) {
		obj.speed.x *= -1;
		return true;
	}
	if(obj.position.y > SCREEN_Y) {
		obj.speed.y *= -1;
	}
	if(obj.position.y < 0) {
		obj.speed.y *= -1;
	}
	return false;
}

// updates the position of the ball
// adds the balls current velocity to its current position to get the 
// new position
void updateBallPosition(movableObject &obj) {
	obj.position = vectorAdd(obj.position, obj.speed);
}

// check if the ball has collided with the paddle
// returns true if a collision occurred
bool checkPaddleCollision(movableObject& ball, movableObject& player) {
	int speed = ball.speed.x;
	
	int ballHalfW = ball.width>>1;
	int playerHalfW = player.width>>1;
	int playerHalfH = player.height>>1;
	
	if(speed == 0)
		return false;

	if(speed < 0){
		if(ball.position.x - ballHalfW < player.position.x + playerHalfW && 
			ball.position.y > player.position.y - playerHalfH &&
			ball.position.y < player.position.y + player.height){
				return true;
		}
	}
	else {
		if(ball.position.x + ballHalfW > player.position.x - playerHalfW && 
			ball.position.y > player.position.y - playerHalfH &&
			ball.position.y < player.position.y + player.height){
				return true;
		}
	}
	return false;
}

// check if one object has collided with another object
// returns true if the two objects have collided
bool checkCollision(movableObject& obj1, movableObject& obj2) {	
	vector2 diff = vectorSubtract(obj1.position, obj2.position);
	float mag = getMagnitude(diff);
	
	if(mag > 0 && mag < obj1.height){
		// collision
		obj1.speed = multiplyScalar( getNormal(diff), 5);
		obj2.speed = multiplyScalar( getNormal(diff), -5);
		return true;
	}
	return false;
}

// the player's paddle position will be updated according the position of the ball.
// this is how we get the computer players updating their paddles
void seek(movableObject &player, movableObject& ball){
	float speed = sqrt(ball.speed.x*ball.speed.x + ball.speed.y*ball.speed.y);

	if(player.position.y < ball.position.y - speed) {
		int diff = ball.position.y - player.position.y;
		if(diff > speed)
			player.position.y += speed;
		else
			player.position.y += diff;
	}
	else if (player.position.y > ball.position.y + speed) {
		int diff = player.position.y - ball.position.y;
		if(diff > speed)
			player.position.y -= speed;
		else
			player.position.y -= diff;
	}
}

// update all the cherries on the screen
// this will calculate the new position based on the current speed. The 
// cherries will also move across the screen following a sine wave
// will also check every cherry against every other cherry and if two
// cherries have collided they will bounce of each other
// cherries will also bounce off the edges of the screen
void updateCheeries(movableObject objs[], int size){
	for(int i = 0; i<30; i++)			
	{
		// check distance to ball
		vector2 dist = vectorSubtract(ball.position, objs[i].position);
		float mag = getMagnitude(dist);

		if(mag < ball.height<<1) {
			// move cherry away from ball
			objs[i].speed = multiplyScalar( getNormal(dist), -5);	
		}
		else
		{
			// cherries follow a sin wave
			if(objs[i].position.y >= 0 && objs[i].position.y <= SCREEN_Y) 
				objs[i].speed.y = sin( ((SCREEN_Y / 63.0f)*objs[i].position.x) * 0.001 ) * 5;
		
			for(int j = 0; j<30; j++)		
			{
				if(i == j)
					continue;
				// check for collision with other cherries
				checkCollision(objs[i], objs[j]);
			}
		}

		// update position using new speed
		objs[i].position = vectorAdd(objs[i].position, objs[i].speed);

		if(objs[i].position.x < 0) {
			objs[i].speed.x = abs(objs[i].speed.x);
		}
			
		if(objs[i].position.x > SCREEN_X) {
			objs[i].speed.x = abs(objs[i].speed.x)*-1;
		}

		if(objs[i].position.y < -objs[i].height)
			objs[i].position.y = SCREEN_Y+objs[i].height;
		if(objs[i].position.y > SCREEN_Y+objs[i].height)
			objs[i].position.y = -objs[i].height;

		MoveSprite(objs[i].sprite, objs[i].position.x, objs[i].position.y);	
	}
}

// this function will move the stars around in a circle
// the radius of the circle is hard-coded at 300. The origin
// of the circle is in the center of the screen
void updateStars(movableObject objs[], int size){
	static float angle = 0.0;

	angle += 0.01;
	float inc = 0.0;
	for(int i = 0; i<30; i++)			
	{
		objs[i].position.x = (SCREEN_X>>1) + cosf( angle+inc ) * 300;
		objs[i].position.y = (SCREEN_Y>>1) + sinf( angle+inc ) * 300;
		MoveSprite(objs[i].sprite, objs[i].position.x, objs[i].position.y);			
		inc += 2*M_PI / 30;
	}
}

int currentNyan = 0;
// this function will move the nyancat across the screen following a sine wave.
// there is also a trailing list of cats, which will also be updated. Every 7 frames
// the cat at the end of this list is moved to the leading cats current position
void updateNyanCat(movableObject& obj) {
	static int yOrigin = rand()%SCREEN_Y;
	
	obj.position.x += obj.speed.x;
	obj.position.y = yOrigin + sin( ((SCREEN_Y / 63.0f)*obj.position.x) * 0.001 ) * 100;

	if(obj.position.x > SCREEN_X+NYANCAT_W) {
		obj.position.x = -NYANCAT_W;
		yOrigin = rand()%SCREEN_Y;
	}

	if(frameCounter%7 == 0) {
		nyans[currentNyan].position.x = obj.position.x;
		nyans[currentNyan].position.y = obj.position.y;
		currentNyan++;
		if(currentNyan >= 10)
			currentNyan = 0;
	}

	for(int i=0; i<10; i++) {
		MoveSprite(nyans[i].sprite, nyans[i].position.x, nyans[i].position.y);
	}

	MoveSprite(obj.sprite, obj.position.x, obj.position.y);
}

// moves the pony across the screen following a cos wave
void updatePony(movableObject& obj) {
	static int yOrigin = rand()%SCREEN_Y;
	static int rotation = 0;

	rotation++;
	obj.position.x += obj.speed.x;
	obj.position.y = yOrigin + cos( ((SCREEN_Y / 63.0f)*obj.position.x) * 0.001 ) * 100;

	if(obj.position.x < -PONY_W) {
		obj.position.x = SCREEN_X+PONY_W;
		yOrigin = rand()%SCREEN_Y;
		rotation=0;
	}
	RotateSprite(obj.sprite, rotation);
	MoveSprite(obj.sprite, obj.position.x, obj.position.y);
}

// initialize all the variables in the game
void initGame() {
	srand(time(0));

	// Now load some sprites
	bgImage = CreateSprite( "./images/bg.png", SCREEN_X, SCREEN_Y, true );
	MoveSprite(bgImage, SCREEN_X>>1, SCREEN_Y>>1);

	player1.sprite = CreateSprite( "./images/cat1.png", PLAYER1_W, PLAYER1_H, true );
	player2.sprite = CreateSprite( "./images/cat2.png", PLAYER2_W, PLAYER2_H, true );
	ball.sprite = CreateSprite( "./images/icecream.png", BALL_W, BALL_H, true );
	nyanCat.sprite = CreateSprite( "./images/nyancat.png", NYANCAT_W, NYANCAT_H, true );
	pony.sprite = CreateSprite( "./images/pony.png", PONY_W, PONY_H, true );

	for(int i=0; i<10; i++){
		nyans[i].position.x = -100;
		nyans[i].position.y = -100;
		nyans[i].sprite = CreateSprite( "./images/nyancat.png", NYANCAT_W, NYANCAT_H, true );
	}

	for(int i=0; i<30; i++) {
		stars[i].sprite = CreateSprite( "./images/star.png", STAR_W, STAR_H, true );
	}

	for(int i=0; i<30; i++) {
		cherries[i].sprite = CreateSprite( "./images/cherry.png", CHERRY_W, CHERRY_H, true );
		cherries[i].position.x = rand()%SCREEN_X;
		cherries[i].position.y = rand()%SCREEN_Y;		
		cherries[i].speed.x = -5 + rand()% 5;
		cherries[i].speed.y = -5 + rand()% 5;
		float mag = sqrt(cherries[i].speed.x*cherries[i].speed.x + cherries[i].speed.y*cherries[i].speed.y);
		cherries[i].speed.x = (cherries[i].speed.x/mag)*5;
		cherries[i].speed.y = (cherries[i].speed.y/mag)*5;
		cherries[i].width = CHERRY_W;
		cherries[i].height = CHERRY_H;
	}
}

// destroy all the sprites and clean up any memory
void destroyGame() {
	DestroySprite(bgImage);
	DestroySprite(player1.sprite);
	DestroySprite(player2.sprite);
	DestroySprite(ball.sprite);
	DestroySprite(nyanCat.sprite);
	DestroySprite(pony.sprite);

	for(int i=0; i<30; i++){
		DestroySprite(stars[i].sprite);
		DestroySprite(cherries[i].sprite);
	}
}

// update the game logic here
void updateGame() {
	updateBallPosition(ball);

	updatePony(pony);
	updateNyanCat(nyanCat);
updateStars(stars, 30);
updateCheeries(cherries, 30);

	// player 1 on auto
	if(ball.speed.x < 0)
		seek(player1, ball);
	else
		seek(player2, ball);

	if( testOnScreen(ball) ) {
		// ball hit side of screen
		if(ball.position.x < 100) {
			// player 1 lost
			player2Score++;
		}
		else {
			// player 2 lost
			player1Score++;
		}
	}

	if(g_gameOver == false) {
		if( abs(player1Score - player2Score) >= 3) {
			// Game Over
			g_gameOver = true;

			int highestScore = player1Score;
			if(player2Score > highestScore) {
				highestScore = player2Score;
			}

			for(int i=0; i<5; i++) {
				if(highestScore > g_highScores[i]) {
					g_highScores[i] = highestScore;
					break;
				}
			}

			// sort the high scores array
			sort(g_highScores, 5);
		}
	}

	if(ball.speed.x < 0) {
		if(checkPaddleCollision(ball, player1) == true)  {
			ball.speed.x *= -1;
		}
	}
	else {
		if(checkPaddleCollision(ball, player2) == true)  {
			ball.speed.x *= -1;
		}
	}


	RotateSprite(player1.sprite, 0);
	MoveSprite(player1.sprite, player1.position.x, player1.position.y);

	RotateSprite(player2.sprite, 0 );
	MoveSprite(player2.sprite, player2.position.x, player2.position.y);

	MoveSprite(ball.sprite, (int)ball.position.x, (int)ball.position.y);
}

// draws each frame of the game
void drawGame() {
	static char outScore1[15] = {'\n'};
	static char outScore2[15] = {'\n'};

	DrawSprite(ball.sprite);
	DrawSprite(player1.sprite);
	DrawSprite(player2.sprite);

	sprintf(outScore1, "Player 1: %d", player1Score);
	sprintf(outScore2, "Player 2: %d", player2Score);
	// draw the scores
	DrawString(outScore1, 50, 50, SColour(255,0,0,255));
	DrawString(outScore2, 1000, 50, SColour(0,255,0,255));

	for(int i = 0; i<30; i++) {
		DrawSprite(stars[i].sprite);
	}

	for(int i = 0; i<30; i++) {
		DrawSprite(cherries[i].sprite);
	}

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
		}
	}

	DrawSprite(nyanCat.sprite);
	for(int i=currentNyan-1; i>=0; i--) {
		DrawSprite(nyans[i].sprite);
	}
	for(int i=9; i>=currentNyan; i--) {
		DrawSprite(nyans[i].sprite);
	}
	DrawSprite(pony.sprite);
	DrawSprite(bgImage);
}

// entry point of the program
int main( int arc, char* argv[] )
{	
	// First we need to create our Game Framework
	Initialise(SCREEN_X, SCREEN_Y, false );

	initGame();
		
	do {
		frameCounter++;

		if(frameCounter > 5000)
			frameCounter = 0;

		ClearScreen();
		
		updateGame();

		drawGame();
	} while ( FrameworkUpdate() == false );

	destroyGame();
	
	Shutdown();

	return 0;
}

