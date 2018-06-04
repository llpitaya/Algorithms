#include<iostream>
using namespace std;

void InsertionSort(int a[],int len)
{
	for (size_t i = 0; i < len-1; i++)
	{
		for (size_t j = i+1; j >=1; )
		{
			if ( a[j-1] >= a[j] )
			{
				swap(a[j-1], a[j]);
				--j;
			}
			else
			{
				--j;
			}

		}
		for (size_t i = 0; i < len; i++)
		{
			cout << a[i] << " ";
			if (i == len - 1)
			{
				cout << endl;
			}
		}
	}
}


int main()
{
	int a[] = { 34, 8, 64, 51, 32, 21 };
	InsertionSort(a, 6);
	return 0;
}