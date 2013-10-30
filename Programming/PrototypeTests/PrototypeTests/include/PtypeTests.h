#ifndef _PTYPETESTS_H_
#define _PTYPETESTS_H_

Class CTimer
{
Public:
	bool SetTimer(float SecondsPassed)

private:
	float CurrentTime;
	float EventTime;
	float TimePassed = SecondsPassed * 1000;
}Timer;

#endif