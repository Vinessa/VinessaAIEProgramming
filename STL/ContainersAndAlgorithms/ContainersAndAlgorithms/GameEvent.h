#pragma once
#include <queue>
class GameEvent
{
public:
	GameEvent(void);
	GameEvent(char* a_EventName);
	~GameEvent(void);

	char* m_EventName;
};

