#include<iostream>
#include<vector>
using namespace std;

vector<int> FindTwoNumEqualToSum(const vector<int> &data, int sum)
{
	vector<int> result;
	if (data.empty())
	{
		return result;
	}
	if (data[0] > sum )
	{
		return result;
	}
	int left = 0;
	int right = data.size() - 1;
	while (left<right)
	{
		if (data[left] + data[right] == sum)
		{
			break;
		}
		else if (data[left] + data[right] > sum)
		{
			--right;
		}
		else if (data[left] + data[right] < sum)
		{
			++left;
		}
	}
	if (left < right)
	{
		result.push_back(data[left]);
		result.push_back(data[right]);
	}
	return result;
}
int main()
{
	vector<int> data{ 0, 1, 2, 3, 4, 4, 5, 6, 7, 10, 12, 23, 34 };
	vector<int> result(FindTwoNumEqualToSum(data,100 ));
	return 0;
}