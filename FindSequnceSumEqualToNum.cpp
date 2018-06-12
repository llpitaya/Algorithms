#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> FindContinuousSequence(int sum)
{
	vector<vector<int>> results;
	int small = 1;
	int big = 2;
	int mid = (sum + 1) / 2;
	int currentSum = small + big;
	while (small < mid )
	{
		if (currentSum == sum)
		{
			vector<int> temp;
			for (size_t i = small; i <= big; i++)
			{
				temp.push_back(i);
			}
			results.emplace_back(temp);
		}
		while (currentSum > sum && small < mid)
		{
			currentSum -= small;
			++small;
			if (currentSum == sum)
			{
				vector<int> temp;
				for (size_t i = small; i <= big; i++)
				{
					temp.push_back(i);
				}
				results.emplace_back(temp);
			}
		}
		++big;
		currentSum += big;
	}
	return results;
}

int main()
{
	vector<vector<int>> result = FindContinuousSequence(10);
	return 0;
}