#include<iostream>
#include<stack>
using namespace std;
bool IsPopOrder(const int* push, const int* pop, int len)
{
	if (pop==nullptr || push==nullptr || len==0)
	{
		return false;
	}

	stack<int> stackData;
	const int* _push = push;
	const int* _pop = pop;
	while (push != (_push + len) || pop != (_pop + len))
	{
		if (push == (_push + len) && !stackData.empty() &&stackData.top()!=*pop)
		{
			return false;
		}

		while (push != (_push + len) && *pop != *push)
		{
			stackData.push(*push);
			++push;
		}

		if (*pop == *push)
		{
			stackData.push(*push);
			++push;
		}

		while (pop!=(_pop+len) && !stackData.empty() && stackData.top()== *pop)
		{
			stackData.pop();
			++pop;
		}
	}
	return true;
}
int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 4, 3, 5, 1, 2 };
	cout << IsPopOrder(a, b, 5) << endl;
	return 0;
}