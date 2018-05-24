#include"DigitialClock.h"
#include<iostream>

DigitialClock::DigitialClock(ClockTimer * p)
{
	mClockTimer = p;
	mClockTimer->Attach(this);
}

DigitialClock::~DigitialClock()
{
	mClockTimer->Detach(this);
}

void DigitialClock::Update(Subject * theChangedSubject){
	if (theChangedSubject == mClockTimer)
	{
		string timeState = mClockTimer->GetTime();
		std::cout << "The current time in digitial clock is: " << timeState << std::endl;
	}
}
