#pragma once
#include <vector>

#define NMAX 35

using namespace std;


class Function
{
public:
	virtual double GetFunctionValue(vector<bool> a[NMAX], int dim) = 0;
	virtual double GetMinumInDomain() = 0;
	virtual double GetMaximumInDomain() = 0;
};

