#ifndef _SCOREBOARD_H_
#define _SCOREBOARD_H_

#include "Class_Sprite.h"
#include "AIE.h"

class Scoreboard :
	public Sprite
{
public:
	Scoreboard(void);
	Scoreboard(const char* a_TextureName, int a_Sprite_W, int a_Sprite_H, float a_Position_X, float a_Position_Y, float a_Velocity_X, float a_Velocity_Y);
	~Scoreboard(void);

	void UpdateScoreBoard();
	void LosePoints();
	void GainPoints();
	unsigned int GetScoreState();
	int ScoreState;

	unsigned int m_ScoreEmptyID;
	unsigned int m_Score100ID;
	unsigned int m_Score200ID;
	unsigned int m_Score300ID;
	unsigned int m_Score400ID;
	unsigned int m_Score500ID;
	unsigned int m_Score600ID;
	unsigned int m_Score700ID;
	unsigned int m_Score800ID;
	unsigned int m_Score900ID;
	unsigned int m_Score1000ID;
	unsigned int m_Score1100ID;
	unsigned int m_Score1200ID;
	unsigned int m_Score1300ID;
	unsigned int m_Score1400ID;
	unsigned int m_Score1500ID;
	unsigned int m_Score1600ID;
	unsigned int m_Score1700ID;
	unsigned int m_Score1800ID;
	unsigned int m_Score1900ID;
	unsigned int m_Score2000ID;
};
#endif
