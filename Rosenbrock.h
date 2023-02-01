#pragma once
#include "Function.h"
class Rosenbrock :
	public Function
{
	double pi = 3.14159265358979323846;
	double TransformToDouble(vector<bool> x);
	double Decode(vector<bool> x);
	double GetFunctionValue(vector<bool> a[NMAX], int dim);
	double GetMinumInDomain();
	double GetMaximumInDomain();

public:
	Rosenbrock();
};

