// A timer for when I need to set timers, by Vinessa Mayer 2/18/2014. Last revised 2/18/2013
#ifndef _VI_TIMER_H_
#define _VI_TIMER_H_
#pragma once

#include <time.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <ctime>
#include <GL/glfw3.h>


using namespace std;


class Vi_Timer
{
public:

	Vi_Timer(void);
	Vi_Timer(float af_TimerTime); 
	~Vi_Timer(void);

	double DeltaTime;
	double GetDeltaTime();
	void SetStartTime(); // sets the start time of the timer to 0.
	double ConvertSecondstoMiliseconds(float a_Seconds); // converts the user's imput in seconds to milliseconds. Used in timer constructor.
	double Sec2MillisResult; // for reference only, stores what the ConvertSecondstoMiliseconds function returned in miliseconds
	float SetTimeReference; //for reference only, stores what the user set the timer for in seconds.
	double d_TimePoint; //time in which time is up in milliseconds for the function's use.

	bool TimeUpCheck();


	//Vi_Timer(void);
	//Vi_Timer(float af_TimerTime); // sets a timer that does something (prolly returns a bool to be used later)
	//Vi_Timer(float af_TimerTime, int MaximumIntervals); //Sets a timer that will go off at intervals, up to a maximum.
	//~Vi_Timer(void);

	//time_t mf_TimerTime;
	//time_t CurrentTime;
	//time_t TimePassed;
	//int mi_MaximumIntervals;
	bool TimesUp;
	//time_t f_StartTime;

	//void StartTimer();
	//void UpdateTimer();
	//bool CheckTimer();
	//int GetMilliSpan(int nTimeStart);
	//int GetMilliCount();

};

#endif //_VI_TIMER_H_