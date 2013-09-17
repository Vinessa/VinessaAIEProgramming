
#include "Pong_Defines.h"
#include "AIE.h"
#include <time.h>
#include <stdlib.h>

movableObject player1 = {PLAYER1_X, 100, 0, 0, -1 , PLAYER1_W, PLAYER1_H};
movableObject player2 = {PLAYER2_X, 620, 0, 0, -1, PLAYER2_W, PLAYER2_H};
movableObject ball = {500, 500, 1,1, -1, BALL_W, BALL_H};

unsigned int bgImage = -0;

void initGame()
{
	srand(time(0));

	bgImage = CreateSprite( "./images/voidgrid.png", SCREEN_X, SCREEN_Y, true );
	MoveSprite(bgImage, SCREEN_X>>1, SCREEN_Y>>1);

	player1.sprite = CreateSprite( "./images/paddle1.png", PLAYER1_W, PLAYER1_H, true );
	player2.sprite = CreateSprite( "./images/paddle2.png", PLAYER2_W, PLAYER2_H, true );
	ball.sprite = CreateSprite( "./images/ball.png", BALL_W, BALL_H, true );
	MoveSprite(player1.sprite,player1.position.x,player1.position.y);
		MoveSprite(ball.sprite, ball.position.x ,ball.position.y);

}
void testOnScreen(movableObject &obj)
{
	int ballHalfW = ball.width / 2;
	int ballHalfH = ball.height /2;

	if(obj.position.x + ballHalfW > SCREEN_X)
		{
			obj.speed.x *= -1; 
		}
	else if(obj.position.x - ballHalfW < 0)
		{
			obj.speed.x *= -1;
		}
	else if(obj.position.y + ballHalfH > SCREEN_Y)
		{
			obj.speed.y *= -1;
		}
	else if(obj.position.y - ballHalfH < 0)
		{
			obj.speed.y *= -1;
		}
}

void BallMovement()
		{
	ball.position.x += ball.speed.x;
	ball.position.y += ball.speed.y;
		}

void drawGame ()
{
	DrawSprite(bgImage);
	DrawSprite(player1.sprite);
	DrawSprite(player2.sprite);
	DrawSprite(ball.sprite);
	MoveSprite(player1.sprite, player1.position.x,player1.position.y );
	MoveSprite(player2.sprite, player2.position.x,player2.position.y );
}

//checking collision with paddle

void checkPaddleCollision(movableObject& ball, movableObject& player1, movableObject& player2 ) 
{
	int speed = ball.speed.x;
	int ballHalfW = ball.width / 2;
	int ballHalfH = ball.height / 2;
	int player1HalfW = player1.width / 2;
	int player1HalfH = player1.height / 2;
	int player2HalfW = player2.width / 2;
	int player2HalfH = player2.height / 2;
	
	//Checks if ball has hit the left side of Player 2
		if(ball.position.x + ballHalfW > player2.position.x - player2HalfW)
		{
			if (ball.position.y + ballHalfH > player2.position.y - player2HalfH)
			{
				if(ball.position.y + ballHalfH < player2.position.y + player2HalfH)
				{
					ball.speed.x *= -1;
				}
			}
		}
		
		/*/Checks to see if the ball has hit the Right Side of Player 2
	else 
			if(ball.position.x - ballHalfW < player2.position.x + player2HalfW)
		{
			if (ball.position.y - ballHalfH > player2.position.y - player2HalfH)
			{
				if(ball.position.y - ballHalfH < player2.position.y + player2HalfH)
				{
					
					ball.speed.x *= -1;
				}
			}
		}
	
	
		//Checks to see if ball has hit the left side of Player 1
	else 
	
		if(ball.position.x + ballHalfW > player1.position.x - player1HalfW)
		{
			if (ball.position.y + ballHalfH > player1.position.y - player1HalfH)
			{
				if(ball.position.y + ballHalfH < player1.position.y + player1HalfH)
				{
					ball.speed.x *= -1;
				}
			}
		}*/
	
	//Checks to see if ball has hit the right side of Player 1
	else 
	
		if(ball.position.x - ballHalfW < player1.position.x + player1HalfW)
		{
			if (ball.position.y - ballHalfH > player1.position.y - player1HalfH)
			{
				if(ball.position.y - ballHalfH < player1.position.y + player1HalfH)
				{
					
					ball.speed.x *= -1;
				}
			}
		}
			
	}

	




	///if( obj.pos.x > screenx)
	//obj.speed.x *= -1;




void updateGame()
{
	BallMovement();
	testOnScreen(ball);
	MoveSprite(ball.sprite, ball.position.x,ball.position.y );
	checkPaddleCollision(ball,player1,player2);


}
