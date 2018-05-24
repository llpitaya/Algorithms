#include<iostream>
using namespace std;

class Strategy{
public:
	virtual void AlgorithmPrint() = 0;

};

class Strategy_A:public Strategy{
public:
	void AlgorithmPrint()
	{
		cout << "This is strategy A" << endl;
	}
};

class Strategy_B :public Strategy{
public:
	void AlgorithmPrint()
	{
		cout << "This is strategy B" << endl;
	}
};

class Context{
public:
	Context(Strategy * p) :_strategy(p){}
	void DoAction(){
		_strategy->AlgorithmPrint();
	}
private:
	Strategy * _strategy;
};

int main(int argc, char argv[])
{
	Strategy * s1 = new Strategy_A();
	Strategy * s2 = new Strategy_B();
	Context con(s1);
	con.DoAction();
	con = Context(s2);
	con.DoAction();
	delete s1;
	delete s2;
	return 0;
}