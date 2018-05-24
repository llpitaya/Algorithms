#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H
#include"Observer.h"
#include"Subject.h"
#include"ClockTimer.h"
class AnalogClock:public Observer{
public:
	AnalogClock(ClockTimer * p);
	virtual void Update(Subject * theChangedSubject);
	virtual ~AnalogClock();
private:
	ClockTimer * mClockTimer;
};
#endif