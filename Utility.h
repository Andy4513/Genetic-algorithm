#pragma once
#include <vector>

using namespace std;

class Utility
{
public:

	Utility();
	double GetAverage(vector<double> a);
	double GetMinimum(vector<double> a);
	double GetMaximum(vector<double> a);
	double GetSD(vector<double> a);
};

