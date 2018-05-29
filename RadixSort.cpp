#include<iostream>
using namespace std;

const int dn = 3;
const int DigitNum = 10;
int C[DigitNum];

//get the d-th digit of x
int GetDigit(int x, int d)
{
	int radix[] = { 1, 10, 100 };
	return (x / radix[d - 1]) % (10);
}

void _sort(int arr[], int len, int d)
{
	memset(C, 0x00, DigitNum*sizeof(int));
	
	for (size_t i = 0; i < len; i++)
	{
		++C[GetDigit(arr[i], d)];
	}

	for (size_t i = 1; i < DigitNum; i++)
	{
		C[i] = C[i] + C[i - 1];
	}

	int * tempArr = new int[len];

	for (int i = len - 1; i>=0; i--)
	{
		int digit = GetDigit(arr[i], d);
		tempArr[--C[digit]] = arr[i];
	}

	for (size_t i = 0; i < len; i++)
	{
		arr[i] = tempArr[i];
	}
	delete[] tempArr;
}

void RadixSort(int arr[], int len)
{
	for (size_t i = 1; i <= dn; i++)
	{
		_sort(arr, len, i);
	}
}

int main()
{
	int a[] = { 0,1,2,10};
	RadixSort(a, sizeof(a) / sizeof(int));
	return 0;
}