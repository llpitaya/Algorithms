#include<iostream>
#include<algorithm>
using namespace std;
//template<class T>
//typedef void(*Compare)(const T& x, const T& y);

template<class T>
size_t Partition(T data[], size_t start, size_t end,bool (*pFun)(const T&, const T&) )
{
	if (start == end || data == nullptr)
	{
		return start;
	}
	T pivotVal = data[start];
	size_t midIndex = start;
	
	while (start<end)
	{
		while (end>start && /*data[end] >= pivotVal*/ pFun(pivotVal, data[end]))
		{
			--end;
		}
		swap(data[end], data[midIndex]);
		midIndex = end;
		while (start<end && /*data[start] < pivotVal*/ !pFun(pivotVal, data[start]))
		{
			++start;
		}
		swap(data[start], data[midIndex]);
		midIndex = start;
	}

	return midIndex;
}

template<class T>
void MyQuickSort(T array[], size_t left, size_t right, bool (*pFun)(const T&, const T&) )
{
	if (left>=right)
	{
		return;
	}

	size_t pivotIdx = Partition(array, left, right,pFun);
	MyQuickSort(array, left, pivotIdx,pFun);
	MyQuickSort(array, pivotIdx + 1, right,pFun);

}


int Partition1(int data[], int start, int end)
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
	int pivotIdx = Partition1(array, left, right);
	QuickSort(array, left, pivotIdx);
	QuickSort(array, pivotIdx + 1, right);

}


int main()
{
	char a[] = { 'a', 'c', 'A', 'v' };
	auto pFun = [](const char& a, const char& b){return a <= b; };
	MyQuickSort<char>(a, size_t(0), size_t(sizeof(a) - 1), pFun);
	for (auto x : a)
	{
		cout << x << " ";
	}
	return 0;
}