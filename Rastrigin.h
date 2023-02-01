#pragma once
#include "Function.h"
#include <vector>
#include <math.h>

#define NMAX 35
#define DMAX 3

using namespace std;


class Rastrigin: public Function
{
	double pi = 3.14159265358979323846;
	double TransformToDouble(vector<bool> x);
	double Decode(vector<bool> x);
	double GetFunctionValue(vector<bool> a[NMAX], int dim);
	double GetMinumInDomain();
	double GetMaximumInDomain();

public:
	Rastrigin();
	
};

