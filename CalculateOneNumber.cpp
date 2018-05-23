#include<iostream>
using namespace std;
// need to know right shift and left shift operator for signed value
size_t CalOneNumInBinary(int x)
{
	size_t num{ 0 };
	while (x)
	{
		if (x & 0x80000000)
			++num;
		x <<= 1;
	}
	return num;
}

size_t _CalOneNumInBinary(int x)
{
	size_t num{ 0 };
	while (x)
	{
		++num;
		x = x&(x - 1);
	}
	return num;
}
int main()
{
	cout << _CalOneNumInBinary(-1) << endl;
	return 0;
}