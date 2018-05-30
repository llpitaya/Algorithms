#include<iostream>
#include<bitset>
#include<string>
using namespace std;

int main()
{
	const int n = 4;
	bitset<n> bs(2);
	for (size_t i = 0; i < bs.size(); i++)
	{
		cout << bs[i] << "";
	}
	cout << endl;

	string str("011");
	bitset<3> bs1(str);
	// bitset does not support range-based for loop
	
	cout << "bs1's initial value: " << endl;
	for (size_t i = 0; i < bs1.size(); i++)
	{
		cout << bs1[i] << "";
	}
	cout << endl;

	cout << "bs1.any(): "<< bs1.any() << endl;

	cout << "bs1.count(): " << bs1.count() << endl;
	
	bs1.set(2, 1);
	cout << "after bs1.set(2,1): " << endl;
	for (size_t i = 0; i < bs1.size(); i++)
	{
		cout << bs1[i] << "";
	}
	cout << endl;
	unsigned long longVal= bs1.to_ullong();
	cout << longVal << endl;
	
	bs1.set(0, 0);
	string str1 = bs1.to_string();
	cout << str1 << endl;
	return 0;
}