#include "Rastrigin.h"

double Rastrigin::TransformToDouble(vector<bool> x)
{
	double toReturn = 0;
	toReturn = GetMinumInDomain() + Decode(x);
	return toReturn;
}

double Rastrigin::Decode(vector<bool> x)
{
	double ret = 0;
	int power = 1;
	for (int i = x.size() - 1; i>=0; i--)
	{
		ret = ret + power * x[i];
		power *= 2;
	}
	ret /= (power - 1);
	return ret * (GetMaximumInDomain() - GetMinumInDomain());
	// -5.12, 5,12
	// 10, 
}

double Rastrigin::GetFunctionValue(vector<bool> a[NMAX], int dim)
{
	double y, s;
	s = 0;
	for (int i = 0; i < dim; i++)
	{
		s = s + (TransformToDouble(a[i]) * TransformToDouble(a[i]) - 10 * cos(2 * pi * TransformToDouble(a[i])));
	}
	y = 10 * dim + s;
	return y;
}

double Rastrigin::GetMinumInDomain()
{
	return -5.12;
}

double Rastrigin::GetMaximumInDomain()
{
	return 5.12;
}


Rastrigin::Rastrigin()
{
}
