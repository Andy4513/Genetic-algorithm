#include "Utility.h"

Utility::Utility()
{
}

double Utility::GetAverage(vector<double> a)
{
	double ret = 0;
	for (unsigned i = 0; i < a.size(); i++)
	{
		ret += a[i];
	}
	ret = ret / (a.size());
	if (ret < 0.0001 && ret > 0)
		return 0;
	return ret;
}

double Utility::GetMinimum(vector<double> a)
{
	if (a.size() == 0)
		return 0;
	double min = a[0];
	for (unsigned i = 1; i < a.size(); i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	if (min < 0.0001 && min > 0)
		return 0;
	return min;
}

double Utility::GetMaximum(vector<double> a)
{
	if (a.size() == 0)
		return 0;
	double max = a[0];
	for (unsigned i = 1; i < a.size(); i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	if (max < 0.0001 && max > 0)
		return 0;
	return max;
}

double Utility::GetSD(vector<double> a)
{
	double mean = GetAverage(a), sd = 0;
	for (unsigned i = 0; i < a.size(); i++)
	{
		sd += pow(a[i] - mean, 2);
	}

	sd = sqrt(sd / a.size());
	if (sd < 0.0001 && sd > 0)
		return 0;
	return sd;
}
