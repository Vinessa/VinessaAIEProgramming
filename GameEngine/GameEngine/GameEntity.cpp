#include "GameEntity.h"


GameEntity::GameEntity(void)
{
}

GameEntity::GameEntity(const char* a_pTexture, int a_iWidth, int a_iHeight, tbyte::Vector4 a_v4Color,GLFWwindow* Window)
	:Sprite(a_pTexture, a_iWidth, a_iHeight, a_v4Color, Window)
{
	
}

GameEntity::~GameEntity(void)
{

}


void GameEntity::Move()
{

}