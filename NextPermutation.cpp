#include<iostream>
#include<algorithm>
using namespace std;
template<typename BidirectionalIterator>
bool _next_permutation(BidirectionalIterator first, BidirectionalIterator last)
{
	if (first == last)
	{
		return false;
	}
	BidirectionalIterator i = first;
	if (++i == last)
	{
		return false;
	}
	i = last;
	--i;
	BidirectionalIterator ii = i;
	while (true)
	{
		if (*i < *ii)
		{
			BidirectionalIterator j = last;
			--j;
			while (*i >= *j)
			{
				--j;
			}
			iter_swap(i, j);
			reverse(ii, last);
			return true;
		}
		if (i == first)
		{
			reverse(first, last);
			return false;
		}
		ii = i;
		--i;
	}
}

template<class BidirectionalIterator>
bool _prev_permutation(BidirectionalIterator first, BidirectionalIterator last)
{
	if (first == last)
	{
		return false;
	}
	BidirectionalIterator i = first;
	if (++i = last)
	{
		return false;
	}
	i = last;
	++i;
	BidirectionalIterator ii = i;
	while (true)
	{
		if (*i > *ii)
		{
			BidirectionalIterator j = last;
			while (*i<*(--j))
			{

			}
			swap_iter(i, j);
			reverse(j, last);
			return true;
		}
		if (i == first)
		{
			reverse(first, last);
			return false;
		}
	}
}
int main()
{
	int a[] = { 1, 2, 3, 4 };

	while (_next_permutation(a, a + 4))
	{
		for (size_t i = 0; i < sizeof(a)/sizeof(int); i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 1;
}