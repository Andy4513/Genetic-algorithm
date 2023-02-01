#include "Six_hump_camel.h"

double Six_hump_camel::TransformToDouble(vector<bool> x)
{
	double toReturn = 0;
	toReturn = GetMinumInDomain() + Decode(x);
	return toReturn;
}

double Six_hump_camel::Decode(vector<bool> x)
{
	double ret = 0;
	int power = 1;
	for (int i = x.size() - 1; i >= 0; i--)
	{
		ret = ret + power * x[i];
		power *= 2;
	}
	ret /= (power - 1);
	return ret * (GetMaximumInDomain() - GetMinumInDomain());
}

double Six_hump_camel::GetFunctionValue(vector<bool> a[NMAX], int dim)
{
	double sum = 0;
	double cur1=TransformToDouble(a[0]), cur2 = TransformToDouble(a[1]);
	sum = (4 - 2.1 * cur1 * cur1 + cur1 * cur1 * cur1 * cur1 / 3) * cur1 * cur1 + cur1 * cur2 + (-4 + 4 * cur2 * cur2) * cur2 * cur2;
	return sum;
}

double Six_hump_camel::GetMinumInDomain()
{
	return -3;
}

double Six_hump_camel::GetMaximumInDomain()
{
	return 3;
}

Six_hump_camel::Six_hump_camel()
{
}
