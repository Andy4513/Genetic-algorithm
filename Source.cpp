#include <iostream>
#include <fstream>
#include "Function.h"
#include "GeneticAlg.h"
#include "Utility.h"
#include "Rastrigin.h"
#include "Six_hump_camel.h"
#include <stdio.h>
#include <time.h>
#include "Griewank.h"
#include "Rosenbrock.h"
using namespace std;

ofstream fout("data.txt");

void RasG(int dim)
{
	fout << "For dimension: " << dim << '\n';
	vector<double> rez;
	Rastrigin r;
	GeneticAlg a(&r, dim);
	Utility u;
	for (int i = 0; i < 30; i++)
	{
		rez.push_back(a.GetResult());
		cout << "Rastringing G dim " << dim << " iteration: " << i << '\n';
	}
	fout << "Average: " << u.GetAverage(rez) << '\n';
	fout << "Minim: " << u.GetMinimum(rez) << '\n';
	fout << "Maxium: " << u.GetMaximum(rez) << '\n';
	fout << "SD: " << u.GetSD(rez) << '\n';
}

void SHCG(int dim)
{
	fout << "For dimension: " << dim << '\n';
	vector<double> rez;
	Six_hump_camel r;
	GeneticAlg a(&r, dim);
	Utility u;
	for (int i = 0; i < 30; i++)
	{
		rez.push_back(a.GetResult());
		cout << "Six_hump_camel G dim " << dim << " iteration: " << i << '\n';
	}
	fout << "Average: " << u.GetAverage(rez) << '\n';
	fout << "Minim: " << u.GetMinimum(rez) << '\n';
	fout << "Maxium: " << u.GetMaximum(rez) << '\n';
	fout << "SD: " << u.GetSD(rez) << '\n';
}


void GriewankG(int dim)
{
	fout << "For dimension: " << dim << '\n';
	vector<double> rez;
	Griewank r;
	GeneticAlg a(&r, dim);
	Utility u;
	for (int i = 0; i < 30; i++)
	{
		rez.push_back(a.GetResult());
		cout << "Griewank G dim " << dim << " iteration: " << i << '\n';
	}
	fout << "Average: " << u.GetAverage(rez) << '\n';
	fout << "Minim: " << u.GetMinimum(rez) << '\n';
	fout << "Maxium: " << u.GetMaximum(rez) << '\n';
	fout << "SD: " << u.GetSD(rez) << '\n';
}

void rosenbroackG(int dim)
{
	fout << "For dimension: " << dim << '\n';
	vector<double> rez;
	Rosenbrock r;
	GeneticAlg a(&r, dim);
	Utility u;
	for (int i = 0; i < 30; i++)
	{
		rez.push_back(a.GetResult());
		cout << "Rosenbrock G dim " << dim << " iteration: " << i << '\n';
	}
	fout << "Average: " << u.GetAverage(rez) << '\n';
	fout << "Minim: " << u.GetMinimum(rez) << '\n';
	fout << "Maxium: " << u.GetMaximum(rez) << '\n';
	fout << "SD: " << u.GetSD(rez) << '\n';
}

int main()
{
	srand(time(NULL));
	fout << "Rastring:\n";
	RasG(2);
	RasG(5);
	RasG(20);
	fout << "Griewank:\n";
	GriewankG(2);
	GriewankG(5);
	GriewankG(20);
	fout << "Rosenbrock:\n";
	rosenbroackG(2);
	rosenbroackG(5);
	rosenbroackG(20);
	fout << "Six hump camel:\n";
	SHCG(2);
	SHCG(5);
	SHCG(20);
}