#include "GameEntity.h"


GameEntity::GameEntity(void)
{
}

GameEntity::GameEntity(const char* a_pTexture, int a_iWidth, int a_iHeight, tbyte::Vector4 a_v4Color,GLFWwindow* Window,float a_AniOffsetU,float a_AniOffsetV,float Z_Position, tbyte::Vector3 UVCoord1,tbyte::Vector3 UVCoord2,tbyte::Vector3 UVCoord3,tbyte::Vector3 UVCoord4)
	:Sprite(a_pTexture, a_iWidth, a_iHeight, a_v4Color, Window, float a_AniOffsetU,float a_AniOffsetV,float Z_Position, tbyte::Vector3 UVCoord1,tbyte::Vector3 UVCoord2,tbyte::Vector3 UVCoord3,tbyte::Vector3 UVCoord4)
{
	
}

GameEntity::~GameEntity(void)
{

}


void GameEntity::Move()
{

}