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
		while (end>start && data[end]>=pivotVal)
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

void FindKMinValue(int data[], int len, int kIdx)
{
	if (data == nullptr && len<=1)
	{
		return;
	}

	int start = 0;
	int end = len - 1;
	int idx = -1;
	while (start <= end)
	{
		idx = Partition(data, start, end);
		if (idx < kIdx)
		{
			end = idx - 1;
		}
		else if (idx > kIdx)
		{
			start = idx + 1;
		}
		else
		{
			break;
		}
	}

	for (size_t i = 0; i < kIdx; i++)
	{
		cout << data[i] << " ";
	}
}

void QuickSort(int array[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int pivotIdx = Partition(array, left, right);
	QuickSort(array, left, pivotIdx);
	QuickSort(array, pivotIdx + 1, right);

}

int main()
{
	int data[] = { 4, 3, 2, 1, 0 };
	auto printFun = [](int a[], int n){for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl; };
	printFun(data, sizeof(data) / sizeof(int));
	FindKMinValue(data, sizeof(data) / sizeof(int),3);
	return 0;
}
