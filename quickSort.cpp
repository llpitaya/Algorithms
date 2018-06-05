#include<iostream>
#include<algorithm>
using namespace std;
int Partition(int data[], int start, int end)
{
	if (start == end || data == nullptr)
	{
		return start;
	}
	int pivotVal = data[start];
	int midIndex = start;
	while (start<end)
	{
		while (end>start && data[end] >= pivotVal)
		{
			--end;
		}
		swap(data[end], data[midIndex]);
		midIndex = end;
		while (start<end && data[start] < pivotVal)
		{
			++start;
		}
		swap(data[start], data[midIndex]);
		midIndex = start;
	}

	return midIndex;
}
void QuickSort(int array[], int left, int right)
{
	if (left>=right)
	{
		return;
	}
	int pivotIdx = Partition(array, left, right);
	QuickSort(array, left, pivotIdx);
	QuickSort(array, pivotIdx + 1, right);

}


int main()
{
	int a[] = {0,1,2,3 };
	QuickSort(a, 0, sizeof(a)/sizeof(int) - 1);
	for (auto x : a)
	{
		cout << x << " ";
	}
	return 0;
}