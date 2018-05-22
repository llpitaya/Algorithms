#include<iostream>
#include<cassert>
using namespace std;
int FindMinInRotatedArray(const int a[], int len)
{
	assert(len >= 1);
	if (len==1)
	{
		return a[0];
	}
	size_t pLeft = 0;
	size_t pRight = len - 1;
	while (pLeft < pRight)
	{
		size_t mid = (pLeft + pRight) / 2;
		if (a[mid] == a[pRight] && a[mid] == a[pLeft])
		{
			return -1;
		}
		if (a[mid] == a[pRight] || a[mid] == a[pLeft])
		{
			return a[pRight];
		}
		if (a[mid] < a[pRight])
		{
			pRight = mid;
		}
		else if (a[mid] > a[pLeft])
		{
			pLeft = mid;
		}
	}
	return -1;
}

int main()
{
	int a[] = { 4, 4, 5,6 , 0, 1, 2, 3 };
	cout << FindMinInRotatedArray(a, sizeof(a) / sizeof(int))<<endl;
	return 0;
}