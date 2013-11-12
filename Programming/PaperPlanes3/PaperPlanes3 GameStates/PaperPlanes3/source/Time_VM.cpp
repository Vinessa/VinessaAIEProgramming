#include "Time_VM.h"

//////////////////////////////////////////////////////////////////////////////////////////////
//CLASS CONSTRUCTORS/////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

//Default Constructor
Timer::Timer ()
{
	m_SecondsPassed = 0;
}
// Constructor that lets me creat a timer object with a custom countdown time.
Timer::Timer(float a_SecondsPassed)
{	
	m_SecondsPassed = a_SecondsPassed;

}

//Deconstructor for blowing that shiz up.
Timer::~Timer()
{

}


/////////////////////////////////////////////////////////////////////////////////////////////
//MEMBER FUNCTIONS///////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


//Class member function that updates the countdown (count up? 0_o) for the timer object called in Timer::SetTimer (below)
void Timer::UpdateCountdown()
{
	float temp =GetDeltaTime();
	CurrentTime += temp;
}

// Class member function that allows me to set the timer (gives the amount of time I want to pass to the UpdateCountdown function and starts the countdown.
void Timer::SetTimer(float a_SecondsPassed)
{
	m_SecondsPassed = a_SecondsPassed;
	CurrentTime = 0;

	Timeup = false;
	UpdateCountdown();
}
//class member function that checks to see if the timer is up and if so lets us know by returning true
bool Timer::IsTimeUp()
{
	if (CurrentTime >= m_SecondsPassed)
	{
		CurrentTime = 0;
		return true;
	}

	return false;

}