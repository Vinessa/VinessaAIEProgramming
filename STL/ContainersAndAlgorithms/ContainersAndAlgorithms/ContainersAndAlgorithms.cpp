// ContainersAndAlgorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <queue>
#include <vector>
#include "GameEvent.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	queue<GameEvent> Events;

	Events.push(GameEvent("You died!"));
	Events.push(GameEvent("You took damage!"));
	Events.push(GameEvent("You got an item!"));

	vector<GameEvent> States;

	States.push_back(GameEvent("Intro"));
	States.push_back(GameEvent("TitleScreen"));
	States.push_back(GameEvent("GameState"));


	return 0;
}

