#include <iostream>
#include <memory>

using namespace std;

class base{
public:
	int val;
	base(){ cout << "base init" << endl; }
	base(int x):val(x){ }
	virtual ~base(){ cout << "base over" << endl; }
	virtual void show(){ cout << "from base" << endl; }
};

class derived : public base{
public:
	derived(){ cout << "derived init" << endl; }
	derived(int y) :base(y){}
	~derived(){ cout << "derived over" << endl; }
	void show(){ cout << "from derived" << endl; }
};

int main() {
	shared_ptr<derived> ptr(new derived(1));
	shared_ptr<derived> ptr2(ptr);
	cout << ptr.get() << endl;
	cout << ptr2.get() << endl;
	cout << ptr.use_count() << endl;
	ptr2.reset();
	cout << ptr.use_count() << endl;
	
	class derived *dptr = ptr.get();
	cout << ptr.use_count() << endl;
	*dptr = derived(2);
	cout << dptr << endl;
	dptr = ptr.get();
	cout << ptr.get() << endl;

	auto_ptr<int> pr(new int(0));
	auto_ptr<int> pr1 = pr;
	cout << *pr1 << endl;

	int *p = new int;
	delete[] p;
	return 0;
}