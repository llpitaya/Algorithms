#ifndef _DIGITIALCLOCK_H
#define _DIGITIALCLOCK_H
#include"Observer.h"
#include"Subject.h"
#include"ClockTimer.h"
class DigitialClock :public Observer{
public:
	DigitialClock(ClockTimer * p);
	~DigitialClock();
	void Update(Subject * theChangedSubject);
private:
	ClockTimer * mClockTimer;
};
#endif