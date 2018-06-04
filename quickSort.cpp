#include<iostream>
#include<algorithm>
using namespace std;
int GetPivot(int array[], int left, int right)
{
	int pivot = left;
	
	while (left<right)
	{
		int pivotValue = array[pivot];
		while (array[right] >= pivotValue)
			--right;
		swap(array[right], pivotValue);
		while (array[left] <=pivotValue)
			++left;
		swap(array[left], pivotValue);
		pivot = left;
	}
	return pivot;
}
void QuickSort(int array[], int left, int right)
{
	if (left>=right)
	{
		return;
	}
	int pivotIdx = GetPivot(array, left, right);
	QuickSort(array, left, pivotIdx);
	QuickSort(array, pivotIdx + 1, right);

}


int main()
{
	int a[] = { 4,5,4,100,-2,4,34};
	QuickSort(a, 0, sizeof(a)/sizeof(int) - 1);

	return 0;
}