#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	float y = 1.5f;
	unsigned int x = *((unsigned int*)&y);
	cout  << x << endl;
	return 0;
}