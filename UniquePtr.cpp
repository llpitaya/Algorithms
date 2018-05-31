#include<memory>
#include<iostream>
using namespace std;
void test_basic()
{
	unique_ptr<int> ptr(new int(3));
	cout << ptr.get() << endl;
	unique_ptr<int> ptr1(move(ptr));
	cout << ptr.get() << endl;
	cout << *ptr1 << endl;
	ptr1.release();
}


void test_custom_deleter()
{

	auto deleter = [](int *ptr){delete ptr; cout << "Call the custom deleter" << endl; };
	unique_ptr<int, decltype(deleter)> ptr(new int(3));
}

int main()
{
	test_custom_deleter();
	return 0;
}