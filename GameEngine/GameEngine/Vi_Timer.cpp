#include "Vi_Timer.h"

//CHRONOS//////////////
Vi_Timer::Vi_Timer(void)
{
}


Vi_Timer::Vi_Timer(float af_Seconds)
{
	SetTimeReference = af_Seconds;
	DeltaTime = glfwGetTime();
	d_TimePoint = (ConvertSecondstoMiliseconds(af_Seconds));
}

Vi_Timer::~Vi_Timer(void)
{
}

void Vi_Timer::SetStartTime()
{
	glfwSetTime(0);
}

double Vi_Timer::GetDeltaTime()
{
	DeltaTime = glfwGetTime();
	return DeltaTime;
}

bool Vi_Timer::TimeUpCheck()
{
	if (!(d_TimePoint <= (GetDeltaTime())))
	{
		TimesUp = false;
		return false;
	}
	else
		TimesUp = true;
		return true;
}
double Vi_Timer::ConvertSecondstoMiliseconds(float a_Seconds)
{
	Sec2MillisResult = (a_Seconds * 1000);
	return (a_Seconds * 1000);

}
//END CHRONOS///////////


//Vi_Timer::Vi_Timer(float af_TimerTime)
//{
//	 mf_TimerTime = af_TimerTime;
//}
//
//Vi_Timer::Vi_Timer(float af_TimerTime, int ai_MaximumIntervals)
//{
//	 mf_TimerTime = af_TimerTime;
//	 mi_MaximumIntervals = ai_MaximumIntervals;
//	 CurrentTime = 0;
//	 
//}
//
//
//Vi_Timer::~Vi_Timer(void)
//{
//}
//
//void Vi_Timer::StartTimer()
//{
//	TimesUp = false;
//	f_StartTime = time(NULL);
//	
//
//}
//
//void Vi_Timer::UpdateTimer()
//{
//	TimesUp = (CheckTimer());
//	if (TimesUp != true)
//	CurrentTime = time(NULL);
//	TimePassed = (CurrentTime - f_StartTime);
//	
//	 
//}
//
//bool Vi_Timer::CheckTimer()
//{
//	if(TimePassed += mf_TimerTime)
//		 return true;
//	else
//		return false;
//}
//
//int Vi_Timer::GetMilliCount()
//{
//	timeb tb;
//	ftime(&tb);
//	int nCount = tb.millitm +(tb.time & 0xfffff) *1000;
//	return nCount;
//}
//
//int Vi_Timer::GetMilliSpan()
//{
//	int nSpan = GetMilliCount() - nTimeStart;
//	if(nSpan <0)
//		nSpan+= 0x10000 * 1000;
//	return nSpan;
//}