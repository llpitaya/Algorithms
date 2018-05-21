#include<iostream>
using namespace std;

void AdjustHeap(int a[], int cur, int last)
{
	int curVal = a[cur];
	for (size_t i = 2 * cur + 1; i < last; i = 2 * i + 1)
	{
		if (i + 1<last && a[i]<a[i + 1])
		{
			++i;
		}
		if (a[i]>curVal)
		{
			a[cur] = a[i];
			cur = i;
		}
	}
	a[cur] = curVal;
}

void heapSort(int a[], int len)
{
	for (int i = len/2; i >= 0; i--)
	{
		AdjustHeap(a, i, len);
	}
	for (int i = len - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		AdjustHeap(a, 0,i);
	}
}


int main()
{
	int a[] = { 4, 6, 8, 5, 9 };
	//heapSort(a, sizeof(a) / sizeof(int));

	int ival = 0x1000001;
	float fval = 2e32;
	cout << fval << endl;
	ival = fval;

	unsigned char uchar= 0;
	uchar = uchar - 1;


	 return 0;
}