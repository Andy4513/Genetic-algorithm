#pragma once
#include <vector>
#include "Function.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <queue>

using namespace std;


class GeneticAlg
{
	struct individ {
		vector<bool> value[NMAX];
	};
	struct ForProb {
		int poz;
		double prob;
	};
	vector<individ> population;
	
	int elitism = 10;
	int dimensiunePopulatieStandard = 100;
	double mutantionProb = 0.001;
	double crossOverProb = 0.3;
	int dimensions;
	Function* F;
	void Init();
	void Del();
	void Mutation();
	void CrossOver();
	void RouletteWhell();
	void PrintPopulation();
	void PrintFitness(vector<double> fit);
	double GetBestAns();
public:
	GeneticAlg(Function* Fun, int dim)
	{
		F = Fun;
		dimensions = dim;
	}
	~GeneticAlg();
	double GetResult();
};

