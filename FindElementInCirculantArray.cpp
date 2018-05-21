#include<iostream>
using namespace std;

int getIndex(int a[], int seek, int len)
{
	int start = 0;
	int end = len - 1;
	if (a[start] > a[end]) // µİÔöÊı×é
	{	
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (a[mid] > a[start])
			{
				if (seek == a[mid])
					return mid;
				else if (a[start] <= seek && seek < a[mid])
					end = mid - 1;
				else
					start = mid + 1;
			}
			else
			{
				if (seek == a[mid])
					return mid;
				else if (seek>a[mid] && seek <= a[end])
				{
					start = mid + 1;
				}
				else
					end = mid - 1;
			}
		}
	}
	else
	{
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (a[mid] < a[start])
			{
				if (a[mid] == seek)
				{
					return mid;
				}
				else if (a[mid]<seek && a[start]>=seek)
				{
					end = mid - 1;
				}
				else
					start = mid + 1;
			}
			else
			{
				if (seek == a[mid])
				{
					return mid;
				}
				else if (a[mid] > seek && seek >= a[end])
				{
					start = mid + 1;
				}
				else
					end = mid - 1;
			}
		}
	}
	return -1;
}

int main()
{
	int a[] = { 3, 4, 5, 0, 1, 2 };
	int b[] = { 2, 1, 0, 5, 4, 3 };
	cout << getIndex(a, 6,sizeof(a) / sizeof(int))<<endl;
	return 0;
}