#include "Scoreboard.h"



Scoreboard::Scoreboard(void)
{
}

Scoreboard::Scoreboard(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_X, float a_Position_Y, float a_Velocity_X, float a_Velocity_Y)
{
	Init(a_TextureName, a_Sprite_W,  a_Sprite_H, a_Position_X, a_Position_Y);
	m_SpriteID = CreateSprite( m_TextureName, m_Sprite_W, m_Sprite_H, true );
//	IsAlive = true;
//	m_SpriteType = 'UI';
	Vector2D Velocity (a_Velocity_X, a_Velocity_Y);
	
	//m_Collider.SetRadius(8.0f);
	//Vector2D tempPosition(200,300);
	m_ScoreEmptyID = CreateSprite("./images/ScoreZero.png",1065,100,532.5,50);
	m_Score100ID = CreateSprite("./images/Score100.png",1065,100,532.5,50);
	m_Score200ID = CreateSprite("./images/Score200.png",1065,100,532.5,50);
	m_Score300ID = CreateSprite("./images/Score300.png",1065,100,532.5,50);
	m_Score400ID = CreateSprite("./images/Score400.png",1065,100,532.5,50);
	m_Score500ID = CreateSprite("./images/Score500.png",1065,100,532.5,50);
	m_Score600ID = CreateSprite("./images/Score600.png",1065,100,532.5,50);
	m_Score700ID = CreateSprite("./images/Score700.png",1065,100,532.5,50);
	m_Score800ID = CreateSprite("./images/Score800.png",1065,100,532.5,50);
	m_Score900ID = CreateSprite("./images/Score900.png",1065,100,532.5,50);
	m_Score1000ID = CreateSprite("./images/Score1000.png",1065,100,532.5,50);
	m_Score1100ID = CreateSprite("./images/Score1100.png",1065,100,532.5,50);
	m_Score1200ID = CreateSprite("./images/Score1200.png",1065,100,532.5,50);
	m_Score1300ID = CreateSprite("./images/Score1300.png",1065,100,532.5,50);
	m_Score1400ID = CreateSprite("./images/Score1400.png",1065,100,532.5,50);
	m_Score1500ID = CreateSprite("./images/Score1500.png",1065,100,532.5,50);
	m_Score1600ID = CreateSprite("./images/Score1600.png",1065,100,532.5,50);
	m_Score1700ID = CreateSprite("./images/Score1700.png",1065,100,532.5,50);
	m_Score1800ID = CreateSprite("./images/Score1800.png",1065,100,532.5,50);
	m_Score1900ID = CreateSprite("./images/Score1900.png",1065,100,532.5,50);
	m_Score2000ID = CreateSprite("./images/Score2000.png",1065,100,532.5,50);

	ScoreState = 0;
}
Scoreboard::~Scoreboard(void)
{
}


unsigned int Scoreboard::GetScoreState()
{
	return ScoreState;
}

void Scoreboard::UpdateScoreBoard()
{
	switch (ScoreState)
	{

	case 0:
		m_SpriteID = m_ScoreEmptyID;
		break;

	case 1:
		m_SpriteID = m_Score100ID;
		break;

	case 2:
		m_SpriteID = m_Score200ID;
		break;

	case 3:
		m_SpriteID = m_Score300ID;;
		break;

	case 4:
		m_SpriteID = m_Score400ID;
		break;

	case 5:
		m_SpriteID = m_Score500ID;
		break;

	case 6:
		m_SpriteID = m_Score600ID;
		break;

	case 7:
		m_SpriteID = m_Score700ID;
		break;

	case 8:
		m_SpriteID = m_Score800ID;
		break;

	case 9:
		m_SpriteID = m_Score900ID;
		break;

	case 10:
		m_SpriteID = m_Score1000ID;
		break;

	case 11:
		m_SpriteID = m_Score1100ID;
		break;

	case 12:
		m_SpriteID = m_Score1200ID;
		break;

	case 13:
		m_SpriteID = m_Score1300ID;
		break;

	case 14:
		m_SpriteID = m_Score1400ID;
		break;

	case 15:
		m_SpriteID = m_Score1500ID;
		break;

	case 16:
		m_SpriteID = m_Score1600ID;
		break;

	case 17:
		m_SpriteID = m_Score1700ID;
		break;

	case 18:
		m_SpriteID = m_Score1800ID;
		break;

	case 19:
		m_SpriteID = m_Score1900ID;
		break;

	case 20:
		m_SpriteID = m_Score2000ID;
		break;
	}
}

void Scoreboard::LosePoints()
{ 
	if(ScoreState != 0)
	{
		--ScoreState;
	}

}


void Scoreboard::GainPoints()
{
	if(ScoreState < 20)
	{
		++ScoreState;
	}

}
	
	