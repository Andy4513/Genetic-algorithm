#include "Griewank.h"

double Griewank::TransformToDouble(vector<bool> x)
{
	double toReturn = 0;
	toReturn = GetMinumInDomain() + Decode(x);
	return toReturn;
}

double Griewank::Decode(vector<bool> x)
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

double Griewank::GetFunctionValue(vector<bool> a[NMAX], int dim)
{
	double suma = 0, prod = 1;
	for (unsigned i = 0; i < dim; i++)
	{
		suma += TransformToDouble(a[i]) * TransformToDouble(a[i]);
		prod = prod * cos(TransformToDouble(a[i]) / sqrt(i + 1));
	}
	return 1 / 4000.0 * suma - prod + 1;
}

double Griewank::GetMinumInDomain()
{
	return -600.0;
}

double Griewank::GetMaximumInDomain()
{
	return 600.0;
}

Griewank::Griewank()
{
}
