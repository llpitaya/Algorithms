#include<iostream>
#include<vector>
using namespace std;
class Subject;
class Observer{
public:
	virtual void Update(int value) = 0;
};

class ConcreteObserver_A:public Observer{
public:
	ConcreteObserver_A(Subject * input) :mSubject(input){}
	void Update(int value){
		_val = value;
		cout << "ObserverA Update state" << endl;
	}
private:
	Subject * mSubject;
	int _val;
};

class ConcreteObserver_B:public Observer{
public:
	ConcreteObserver_B(Subject * input) :mSubject(input){}
	void Update(int value){
		_val = value;
		cout << "ObserverB Update state" << endl;
	}
private:
	Subject * mSubject;
	int _val;
};

class Subject{
public:
	virtual void Attach(Observer* p) = 0;
	virtual void Detach(Observer* p) = 0;
	virtual void Notify() = 0;
};

class ConcreteSubject:public Subject{
public:
	void Attach(Observer* p)
	{
		mObserverList.push_back(p);
	}

	void Detach(Observer* p)
	{
		mObserverList.pop_back();
	}

	void SetState(int x){
		_val = x;
	}

	void Notify()
	{
		for (size_t i = 0; i < mObserverList.size(); i++)
		{
			mObserverList[i]->Update(_val);
		}
	}
private:
	vector<Observer*> mObserverList;
	int _val;
};

int main(int argc, char argv[])
{
	ConcreteSubject * concreteSub = new ConcreteSubject();

	Observer * observer_A = new ConcreteObserver_A(concreteSub);
	Observer * observer_B = new ConcreteObserver_B(concreteSub);

	concreteSub->SetState(1);
	concreteSub->Attach(observer_A);
	concreteSub->Attach(observer_B);
	concreteSub->Notify();

	delete observer_B;
	delete observer_A;
	delete concreteSub;
	return 0;
}