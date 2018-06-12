#include<iostream>
#include<vector>
using namespace std;

int FindOneIndexFromLSB(const int& x)
{
	if (x == 0)
	{
		return -1;
	}

	int indx = 0;
	unsigned temp = 1u;
	
	while ( ((x & temp)>>(indx)) == 0)
	{
		temp <<= (++indx);
	}
	return indx;
}

vector<int> FindUnqiueNumInArray(const vector<int>& data)
{
	if (data.size() <= 1)
	{
		vector<int> data;
		data.emplace_back(data[0]);
		return data;
	}

	int result = data[0];
	for (size_t i = 1; i < data.size();++i)
	{
		result ^= data.at(i);
	}

	size_t oneIndex = FindOneIndexFromLSB(result);
	vector<int> vec[2];
	for (size_t i = 0; i < data.size(); i++)
	{
		if ((data.at(i) >> oneIndex) & 0x1)
			vec[0].emplace_back(data[i]);
		else
			vec[1].emplace_back(data[i]);
	}

	vector<int> twoNum;
	result = vec[0].at(0);
	for (size_t i = 1; i < vec[0].size(); i++)
	{
		result ^= vec[0].at(i);
	}
	twoNum.emplace_back(result);

	result = vec[1].at(0);
	for (size_t i = 1; i < vec[1].size(); i++)
	{
		result ^= vec[1].at(i);
	}
	twoNum.emplace_back(result);
	return twoNum;
}

int main()
{
	int x = 10;
	vector<int> data{ 1, 1, 2, 2, 4, 5, 5, 4, -6, 7 };
	vector<int> result = FindUnqiueNumInArray(data);
	for (auto element : result)
	{
		cout << element << " ";
	}
	return 0;
}