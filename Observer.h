#ifndef _OBSERVER_H
#define _OBSERVER_H
#include"Subject.h"
class Subject;
class Observer{
public:
	//virtual ~Observer();
	virtual void Update(Subject * theChangedSubject) = 0;
//protected:
//	Observer();
};
#endif