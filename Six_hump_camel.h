#pragma once
#include "Function.h"
#include <vector>
#include <math.h>


#define NMAX 35


using namespace std;

class Six_hump_camel :
	public Function
{
	double pi = 3.14159265358979323846;
	double TransformToDouble(vector<bool> x);
	double Decode(vector<bool> x);
	double GetFunctionValue(vector<bool> a[NMAX], int dim);
	double GetMinumInDomain();
	double GetMaximumInDomain();
public:
	Six_hump_camel();
};

