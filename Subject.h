#ifndef _SUBJECT_H
#define _SUBJECT_H
#include<list>
#include"Observer.h"
using std::list;
class Observer;
class Subject
{
public:
	virtual ~Subject();
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify();
private:
	list<Observer*> mObserverList;
};

#endif