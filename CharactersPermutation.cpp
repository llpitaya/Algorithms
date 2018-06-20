#include<iostream>
#include<vector>
using namespace std;

// need to consider this case that there exists equal elements in the array/
// there is some problem in this algorithm
void PermutationCharacters(char str[], int len, vector<char> & permutations, vector<char> &isValid)
{
	if (permutations.size() == len)
	{
		auto PrintVec = [](const vector<char>& vec){for (auto i : vec) cout << i << " "; cout << endl; };
		PrintVec(permutations);
		return;
	}
	for (size_t i = 0; i < len; i++)
	{
		if (permutations.empty())
		{
			bool isSame = false;
			for (size_t j = 0; j <i; j++)
			{
				if (str[j] == str[i])
				{
					isSame = true;
					break;
				}
			}
			if (isSame)
			{
				continue;
			}
		}
		if (!isValid[i])
		{
			continue;
		}
		else
		{
			permutations.push_back(str[i]);
			isValid[i] = 0;
			PermutationCharacters(str, len, permutations, isValid);
			isValid[i] = 1;
			permutations.pop_back();	
		}


	}
}

void Permutations(vector<int>& data, int start)
{
	if (start == data.size())
	{
		auto PrintVec = [](const vector<int>& vec){for (auto i : vec) cout << i << " "; cout << endl; };
		PrintVec(data);
	}
	else
	{
		for (int i = start; i < data.size();++i)
		{
			bool isSwap = true;
			for (size_t j = start; j < i; j++)
			{
				if (data[j] == data[i])
				{
					isSwap = false;
					break;
				}
			}

			if (isSwap)
			{
				swap(data[i], data[start]);
				Permutations(data, start+1);
				swap(data[i], data[start]);	
			}
		}
	}
}

// this combination algorithm is only valid for the array with no equal elements.
void CombinationCharacters(char str[], int len, int m, vector<char> & permutations)
{
	if (m == 0)
	{
		auto PrintVec = [](const vector<char>& vec){for (auto i : vec) cout << i << " "; cout << endl; };
		PrintVec(permutations);
		return;
	}

	if (len!=0)
	{
		// case1: select the first element
		permutations.push_back(str[0]);
		CombinationCharacters(str + 1, len - 1, m - 1, permutations);
		permutations.pop_back();
		// case2: not select the first element
		CombinationCharacters(str + 1, len - 1, m, permutations);
	}
}
int main()
{
	char str[]{ 'a', 'a','c'};
	vector<char> permutations;
	vector<char> isValid(sizeof(str), 1);
	//CombinationCharacters(str, sizeof(str), 2, permutations);
	//PermutationCharacters(str, sizeof(str), permutations, isValid);
	vector<int> data{ 1,2,3 };
	Permutations(data, 0);
	return 0;
}