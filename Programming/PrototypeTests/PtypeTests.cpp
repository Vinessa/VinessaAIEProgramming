/*bool Timecheck (float SecondsPassed) //s = seconds passed
{
	time_t StartTime; // Saves a place to store the the Current time as start time
	time_t CurrentTime; // saves a place to temporarily store the currenttime
	float s = *SecondsPassed // Assigns a pointer to a place where the variable is stored.

		//time_t SetTime();// puts the initial setting of current time in it's own function seperate from the check loop so that it doesn't simply reset the start each loop forever.
		//{
			time(&CurrentTime);// gets the current time and assigns it to CurrentTime
			StartTime = CurrentTime; // says that Start Time has the same value as CurrentTime
		//};

	return TimeReached(StartTime, s);
}

bool TimeReached(StartTime, s){
	bool triggerTime = false;

	while (TriggerTime = false);
	{
		if (StartTime <= CurrentTime + s)
		{
			std::cout << "Nope!" << endl;
			//return false;
		}

		else
			if(StartTime > CurrentTime + s)
		{
			std::cout <<" yep!" << endl;
			return true;
		}
	}

	return true;
}*/

/*bool SetTimer(float SecondsPassed);
{
	float Timepassed = 0;
	float StartTime = 0;
	
	float convertSec2Mill ();
	{
		TimePassed = SecondsPassed * 1000;
	}

	void StartTimer();
	{
	StartTime += GetDeltaTime();
	}

	if (StartTime >= TimePassed)
		{
			std::cout <<"Time is up!"<<endl;
		}


}*/


void