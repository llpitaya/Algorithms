#include"AnalogClock.h"
#include<iostream>
void AnalogClock::Update(Subject * theChangedSubject){
	if (theChangedSubject == mClockTimer)
	{
		string timeState = mClockTimer->GetTime();
		std::cout << "The current time in analog clock is: " << timeState << std::endl;
	}
}

AnalogClock::~AnalogClock()
{
	mClockTimer->Detach(this);
}

AnalogClock::AnalogClock(ClockTimer * p)
{
	mClockTimer = p;
	mClockTimer->Attach(this);
}