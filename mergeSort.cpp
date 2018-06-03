#include<iostream>
using namespace std;

void Merge(int arr[], int left, int mid, int right, int tempArray[])
{
	int idx = left;
	size_t i, j;
	for ( i = left, j = mid+1; i <=mid && j<=right ; )
	{
		if (arr[i] <= arr[j])
		{
			tempArray[idx++] = arr[i];
			++i;
		}
		else if (arr[i] > arr[j])
		{
			tempArray[idx++] = arr[j];
			++j;
		}
	}

	while(i<=mid)
	{
		tempArray[idx++] = arr[i++];
	}
	while (j<=right)
	{
		tempArray[idx++] = arr[j++];
	}
	for (size_t i = left; i <= right; i++)
	{
		arr[i] = tempArray[i];
	}
	
}
void MergeSort(int arr[], int first, int last, int tempArray[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		MergeSort(arr, first, mid,tempArray);
		MergeSort(arr, mid+1, last, tempArray);
		Merge(arr, first, mid, last, tempArray);
		cout << " first=" << first << " mid= " << mid << " last=" << last << endl;
		cout << endl;
	}
}


int main()
{
	int a[] = { 0, 2, -2, 10,1 };
	int temp[] = { 0, 2, -2, 10, 1};
	MergeSort(a, 0, sizeof(a) / sizeof(int) -1 , temp);
	return 0;
}