#include<iostream>
using namespace std;
class Base{
public:

	virtual void fun1(){ cout << "Base::fun1()" << endl; }
	
};
class Derived :public Base
{
public:
	Derived() :Base(), x(1){}
	void fun1(){ cout << "Derived::fun1()" << endl; }
	int x;
};
int main()
{	
	Base* pDerived = new Derived;
	if (Derived* p1 = dynamic_cast<Derived*>(pDerived))// It is euqal to static_cast in the downcast
	{
		p1->fun1();
	}
	Base* pBase = new Base;
	if (Derived * p1 = dynamic_cast<Derived*>(pBase))// p1 = null. 
	{
		cout << p1->x << endl;;
	}
	if (Derived * p1 = static_cast<Derived*>(pBase)) // It is not right in the upcast.
	{
		cout << p1->x << endl;
	}
	return 0;
}