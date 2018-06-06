#include<iostream>
#include<string>
using namespace std;

void * operator new(size_t) throw(bad_alloc); // standard version
void * operator new(size_t, const nothrow_t&) throw(); // placement version
void operator delete(void *) throw();
void operator delete(void*, const nothrow_t&) throw();

void test_nothrow_new()
{
	int * pInt = new(std::nothrow) int;
	if (!pInt)
	{
		cerr << "Allocation failure" << endl;
		exit(1);
	}
	delete pInt;
}

class Base{
public:
	Base(){ cout << "Base::Base()" << endl; }
	~Base(){ cout << "Base::~Base()" << endl; }
};

void test_placement_new()
{
	char *buf = new char[10];
	Base *base = new(buf)Base;
	base->~Base();
	delete[]buf;
}

int main()
{
	return 0;
}