#include<iostream>
using namespace std;
class Base
{
public:
	virtual int VirtualFun1()
	{
		cout << "Base::VirtualFun1()" << endl;
		return 0;
	}

	Base* VirtualFun2()
	{
		cout << "Base::VirtualFun2()" << endl;
		return new Base;
	}
	
};

class Derived:public Base
{
public:
	//float VirtualFun1()
	//{
	//	return 1.0f;
	//}
	int VirtualFun1() const // overload
	{
		cout << "Derived::VirtualFun1() const" << endl;
		return 1;
	}
	
	int VirtualFun1() //override
	{
		cout << "Derived::VitualFun1()" << endl;
		return 2;
	}

	Derived* VirtualFun2() //override
	{
		cout << "Derived::VirtualFun2()" << endl;
		return new Derived;
	}
};

int main()
{
	const Derived * p1 = new Derived;
	p1->VirtualFun1();

	Derived* p2 = new Derived;
	Derived* p3 = p2->VirtualFun2();
	delete p3;
	delete p2;
	return 0;
}