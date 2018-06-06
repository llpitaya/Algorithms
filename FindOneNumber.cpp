#include<iostream>
using namespace std;

typedef unsigned long long ULONGLONG;

ULONGLONG Sum1s(ULONGLONG n)
{
	ULONGLONG count = 0;
	ULONGLONG iFactor = 1;
	ULONGLONG iLowerNum = 0;
	ULONGLONG iCurNum = 0;
	ULONGLONG iHigherNum = 0;
	while (n/iFactor!=0)
	{
		iLowerNum = n - (n/iFactor)*iFactor;
		iCurNum = n / iFactor % 10;
		iHigherNum = n / (iFactor * 10);
		switch (iCurNum)
		{
		case 0:
			count += iHigherNum * iFactor;
			break;
		case 1:
			count += iHigherNum * iFactor + iLowerNum + 1;
			break;
		default:
			count += (iHigherNum + 1) * iFactor;
			break;
		}
		iFactor *= 10;
	}
	return count;
}
int main()
{
	cout << Sum1s(93) << endl;
	return 0;
}