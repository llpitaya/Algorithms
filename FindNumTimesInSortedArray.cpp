#include<iostream>
using namespace std;

int FindLeftNum(int arr[], int left, int right, int num)
{
	if (arr == nullptr)
	{
		return -1;
	}

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > num)
		{
			right = mid - 1;
		}
		else if (arr[mid] < num)
		{
			left = mid + 1;
		}
		else //arr[mid] == num
		{
			if (mid > left)
			{
				if (arr[mid - 1] == num)
					right = mid - 1;
				else if (arr[mid - 1] != num)
				{
					return mid;
				}
			}
			else
				return mid;
		}
	}
	return -1;
}

int FindRightNum(int arr[], int left, int right, int num)
{
	if (arr == nullptr)
	{
		return -1;
	}

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > num)
		{
			right = mid - 1;
		}
		else if (arr[mid] < num)
		{
			left = mid + 1;
		}
		else //arr[mid] == num
		{
			if (mid < right)
			{
				if (arr[mid + 1] == num)
					left = mid + 1;
				else if (arr[mid + 1] != num)
				{
					return mid;
				}
			}
			else
				return mid;
		}
	}
	return -1;
}

void test_FindLeftNum()
{
	// case1
	int a[] = { 0, 1, 2, 2, 5, 6 };
	cout << "FindLeftNum(a, 0, sizeof(a) / sizeof(int) - 1, 0) = "<<FindLeftNum(a, 0, sizeof(a) / sizeof(int) - 1, 0) << endl;
	cout << "FindLeftNum(a, 0, sizeof(a) / sizeof(int), 2) = " << FindLeftNum(a, 0, sizeof(a) / sizeof(int), 2) << endl;
	cout << "FindLeftNum(a, 0, sizeof(a) / sizeof(int), 6) = " << FindLeftNum(a, 0, sizeof(a) / sizeof(int), 6) << endl;
	cout << "FindLeftNum(a, 7, sizeof(a) / sizeof(int), 8) = " << FindLeftNum(a, 7, sizeof(a) / sizeof(int), 8) << endl;
	// case2
	int b[] = { 0, 0, 0, 0 };
	cout << "FindLeftNum(b,0,sizeof(b)/sizeof(int),0) = " << FindLeftNum(b, 0, sizeof(b) / sizeof(int), 0) << endl;
}
int main()
{
	int a[] = { 0, 1, 2,2,2, 2, 5, 6 };
	//cout << FindLeftNum(a, 0, sizeof(a) / sizeof(int), 2);
	cout << (FindRightNum(a, 0, sizeof(a) / sizeof(int) - 1, 2) - FindLeftNum(a, 0, sizeof(a) / sizeof(int) - 1, 2) + 1) << endl;
	return 0;
}