/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File: Time_VM.h (PaperPlanes)
// Author: Vinessa Mayer
// Date Created: October 14th 2013
// Brief: header for custom Time Class originally made for PaperPlanes, but intended for later use.
// Copyright: Vinessa Mayer 2013
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _TIME_VM_H_
#define _TIME_VM_H_

#include <time.h>
#include "AIE.h"
class Timer
{

public:
	Timer();
	Timer(float a_SecondsPassed);
	~Timer();

	void SetTimer(float a_SecondsPassed);

	bool IsTimeUp();
	void TimerEvent();
	void UpdateCountdown();

	bool Timeup;

private:
	float CurrentTime;
	float m_SecondsPassed;
	float TimePassed;

};



#endif