#include"iostream"
#include"ClockTimer.h"
#include"DigitialClock.h"
#include"AnalogClock.h"
using namespace std;
int main()
{
	ClockTimer * timer = new ClockTimer;
	DigitialClock * digitialClock = new DigitialClock(timer);
	AnalogClock * analogClock = new AnalogClock(timer);
	timer->SetTime("5/24/2018");
	timer->Notify();
}