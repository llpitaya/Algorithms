#ifndef _CLOCKTIMER_H
#define _CLOCKTIMER_H
#include"Subject.h"
#include<string>
using std::string;
class ClockTimer:public Subject{
public:
	string GetTime();
	void SetTime(string time);
private:
	string _time;
};
#endif