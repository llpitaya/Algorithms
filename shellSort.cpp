#include<iostream>
using namespace std;

void shellSort(int a[], int len)
{
	for (size_t gap = len/2; gap >0; gap /= 2)
	{
		for (int i = gap; i < len;i++)
		{
			int j = i;
			int temp = a[i];
			for (;j>=gap && a[j-gap]>temp;j-=gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}

	}
}


int main()
{
	return 0;
}