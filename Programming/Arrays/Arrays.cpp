// Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
int aiHighScores[10];
int iArrayPosition = 0;
int iScore;
cout<< "Players, please enter your high scores.\n";
	while (iArrayPosition < 10)
	{
		cin>> (iScore);
		aiHighScores [iArrayPosition] = iScore;
		iArrayPosition++;
	}


for (iArrayPosition = 0; iArrayPosition < 10; iArrayPosition++ )
{
	//iNext represents iArrayPositionNext
	int iNext = iArrayPosition +1;
	while (iNext < 10)
	{
		if (aiHighScores[iArrayPosition] < aiHighScores [iNext]){
			int iTemp = aiHighScores [iArrayPosition];

			aiHighScores [iArrayPosition] = aiHighScores [iNext];
			aiHighScores [iNext] = iTemp;
		}
		iNext++;
	}


}

cout<<"High Scores\n";
cout<< aiHighScores[0] <<endl;
cout<< aiHighScores[1] <<endl;
cout<< aiHighScores[2] <<endl;
cout<< aiHighScores[3] <<endl;
cout<< aiHighScores[4] <<endl;
cout<< aiHighScores[5] <<endl;
cout<< aiHighScores[6] <<endl;
cout<< aiHighScores[7] <<endl;
cout<< aiHighScores[8] <<endl;
cout<< aiHighScores[9] <<endl;
getchar();
getchar();
	return 0;
}

