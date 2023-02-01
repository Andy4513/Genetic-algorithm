#include "Rosenbrock.h"

double Rosenbrock::TransformToDouble(vector<bool> x)
{
	double toReturn = 0;
	toReturn = GetMinumInDomain() + Decode(x);
	return toReturn;
}

double Rosenbrock::Decode(vector<bool> x)
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

double Rosenbrock::GetFunctionValue(vector<bool> a[NMAX], int dim)
{
	double result = 0;
	for (unsigned i = 0; i < dim - 1; i++)
	{
		result = result + 100 * pow((pow(TransformToDouble(a[i]), 2) - TransformToDouble(a[i+1])), 2) + pow((TransformToDouble(a[i]) - 1), 2);
	}
	return result;
}

double Rosenbrock::GetMinumInDomain()
{
	return -2.048;
}

double Rosenbrock::GetMaximumInDomain()
{
	return 2.048;
}

Rosenbrock::Rosenbrock()
{
}
