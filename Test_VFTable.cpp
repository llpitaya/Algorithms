#include<iostream>
using namespace std;

typedef void(*pFun)();

class Base{
public:
	int m_data1;
	int m_data2;
	virtual void vfun1(){ cout << "Base::vfun1()" << endl; }
	virtual void vfun2(){ cout << "Base::vfun2()" << endl; }
	void fun3(){ cout << "Base::fun3()" << endl; }
	Base() :m_data1(0), m_data2(1){ cout << "Base::Base()" << endl; }
	virtual ~Base(){ cout << "Base::~Base()" << endl; }
};

class Derived :public Base{
public:
	int m_data3;
	//void vfun1(){ cout << "Derived::vfun1()" << endl; }
	void vfun2(){ cout << "Derived::vfun2()" << endl; }
	Derived() :Base(), m_data3(2){ m_data2 = -1; }
	~Derived(){ cout << "Derived::~Derived()" << endl; }
};


int main()
{
	Base b;
	// baseAddress is the VA of the object b.
	int * baseAddress = (int*)(&b);	
	pFun _vfun1 = (pFun)((int*)(*(baseAddress + 0)))[0];
	_vfun1();
	
	//derived class
	Base * pDerived = new Derived();
	int* baseAddress1 = (int*)pDerived;
	pFun _vfun2 = (pFun)((int*)baseAddress1[0])[1];
	_vfun2();

	Base * pDerived1 = dynamic_cast<Base*>(new Derived()); 
	Derived * pBase = dynamic_cast<Derived*>(new Base());

	delete pDerived1;
	delete pDerived;
	return 0;
}