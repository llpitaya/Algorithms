#include<iostream>
using namespace std;
bool EqualToZero(double base)
{
	return (base >= -0.000001) && (base <= 0.000001);
}

double core(double base, int exponent)
{
	if (exponent == 0)
	{
		return 1.0;
	}

	if (exponent == 1)
	{
		return base;
	}

	double result = core(base, exponent >> 1);
	result *= result;
	if (exponent & 1)
	{
		result *= base;
	}
	return result;
	
}
double PowerWithExponent(double base, int exponent)
{
	if (EqualToZero(base))
	{
		return 0.0;
	}
	int absExponent = exponent > 0.0 ? exponent : (-exponent);
	double result = core(base, absExponent);
	if (exponent < 0)
	{
		result = 1.0 / result;
	}
	return result;
}



int main()
{
	for (int i = -10; i < 10; i++)
	{
		cout << PowerWithExponent(2.0, i) << " ";
	}
	return 0;
}