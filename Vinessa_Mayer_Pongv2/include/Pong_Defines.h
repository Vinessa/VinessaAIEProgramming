#pragma once
#ifndef _PONG_DEFINES_
#define _PONG_DEFINES_
#include <ctime>
#include <stdlib.h>

const int SPEED = 10;
const int SCREEN_X = 1200;
const int SCREEN_Y = 720;

const int PLAYER1_X = 100;
const int PLAYER1_W = 50;
const int PLAYER1_H = 125;

const int PLAYER2_X = 1100;
const int PLAYER2_W = 50;
const int PLAYER2_H = 125;

const int BALL_W = 64;
const int BALL_H = 64;


//STRUCTS
struct vector2{
	float x;
	float y;
};

struct movableObject
{
	vector2 position;
	vector2 speed;
	int sprite;
	int width;
	int height;
};





#endif