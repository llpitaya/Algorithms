#include<iostream>
using namespace std;

/*
Case1: ParamType is a reference or pointer
	
>example1:

	template<class T>
	void f(T& param);

>example2:
	template<class T>
	void f(const T& param);

>example3:
	template<class T>
	void f(T * param);

	caller: f(expr)

Rules:
(1) if the expr is a reference, please ignore the reference part;
(2) Then pattern-match expr's type against ParamType to determine T.
*/

template<class T>
void fun1_case1(T& param)
{
	//param = 3;
}

void someFunc(int);
void test_fun1_case1()
{
	int x1;
	const int x2 = 0;
	int & x3 = x1;
	int && x4 = 0;
	const char name[] = "jack";
	fun1_case1(x1); // T is int, and ParamType is int&.
	//fun1_case1(x2); // It is wrong. T is const int, and ParamType is const int&.
	fun1_case1(x3); // T is int not int&, and ParamType is int&.
	fun1_case1(x4); // T is int, and ParamType is int&.
	fun1_case1(name);// T is const char[5], and ParamType is const char(&)[5].
	fun1_case1(someFunc); // ParamType is void(*)(int, double)
}

template<class T>
void fun2_case1(const T& param)
{
	cout << param << " ";
}

template<class T>
void fun3_case1(T * param)
{
	cout << (*param) << " ";
	
}

/*
Case2: ParamType is a universial reference

>example1:	
		 template<class T>
		 void f(T&& param);

		 caller: f(expr)
Rules:
(1) if expr is lvalue, both T and ParamType are deduced to be lvalue references.
(2) if expr is rvalue, refer to the Case1.

*/

template<class T>
void fun1_case2(T&& param)
{
	//...
}

void test_fun1_case2()
{
	int x = 0;
	const int cx = x;
	const int & rx = x;

	fun1_case2(x);// T is int&, and ParamType is int&.
	fun1_case2(cx);// T is const int& , and ParamType is const int&.
	fun1_case2(rx);// T is const int&, and ParamType is const int&.
	fun1_case2(3);// T is int, and ParamType is int&&.
}

/*
case3: ParamType is Neither a Pointer nor a Reference

>example1:
		  template<class T>
		  void f(T param);
Rules:
(1) if expr's type is a reference, and ignore the reference part;
(2) if expr is a const, ignore that too. If it is volatile, also ignore that.
*/
template<class T>
void fun1_case3(T param)
{
	
}

void test_fun1_case3()
{
	int x = 0;
	const int cx = x;
	const int & rx = x;
	const char* const ptr = "Fun with pointers";
	const char name[] = "jack";
	fun1_case3(x);// T is int, and ParamType is int.
	fun1_case3(cx); // T is int, and ParamType is int.
	fun1_case3(rx);// T is int , and ParamType is int.
	fun1_case3(ptr);// T and ParamType is const char*.
	fun1_case3(name); // T is const char*.

}
int main()
{
	test_fun1_case2();
	return 0;
}