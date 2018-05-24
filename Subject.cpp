#include"Subject.h"
Subject::~Subject(){

}

void Subject::Attach(Observer* o){
	mObserverList.push_back(o);
}

void Subject::Detach(Observer* o){
	mObserverList.remove(o);
}

void Subject::Notify(){
	for (auto iter = mObserverList.begin(); iter != mObserverList.end(); iter++)
	{
		(*iter)->Update(this);
	}
}