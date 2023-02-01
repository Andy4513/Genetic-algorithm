#include "GeneticAlg.h"

void GeneticAlg::Init()
{
	double lg = ceil(log2(F->GetMaximumInDomain() - F->GetMinumInDomain() * 100000));
	individ curent;
	for (int i = 0; i < dimensions; i++)
	{
		curent.value[i].resize(lg + 1);
	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < dimensions; j++)
		{
			for (int k = 0; k < lg; k++)
			{
				curent.value[j][k] = rand() % 2;
			}
		}
		population.push_back(curent);
	}
	//PrintPopulation();
}

void GeneticAlg::Del()
{
	population.clear();
}

void GeneticAlg::Mutation()
{
	random_device rand;
	mt19937 gen(rand());
	uniform_int_distribution <> dis(1, 100);
	for (int i = 0; i < dimensiunePopulatieStandard; i++)
	{
		for (int j = 0; j < dimensions; j++)
		{
			for (int k = 0; k < population[i].value[j].size() ; k++)
			{
				double prob = dis(gen);
				if (prob/100 <= mutantionProb)
				{
					population[i].value[j][k] = !population[i].value[j][k];
					//cout << "Succes\n";
				}
			}
		}
	}
	//PrintPopulation();
}

void GeneticAlg::CrossOver()
{
	individ child1, child2;
	random_device rand;
	mt19937 gen(rand());
	uniform_int_distribution <> dis(1, 100);
	vector<ForProb> prob;
	ForProb x;
	// calculez prob pt fiecare individ
	for (unsigned i = 0; i < population.size(); i++)
	{
		x.poz = i;
		x.prob = dis(gen) / 100.0;
		prob.push_back(x);
	}
	// sortez prob pt fiecare individ
	for (unsigned i = 0; i < prob.size() - 1; i++)
	{
		for (unsigned j = i + 1; j < prob.size(); j++)
		{
			if (prob[i].prob > prob[j].prob)
			{
				swap(prob[i], prob[j]);
			}
		}
	}
	// crossover uniform pt indivizi
	for (unsigned i = 0; i < prob.size() - 1 && prob[i].prob < crossOverProb; i++)
	{
		if (prob[i + 1].prob < crossOverProb || (dis(gen) / 100.0) < 0.5)
		{
			for (int j = 0; j < dimensions; j++)
			{
				for (unsigned k = 0; k < population[prob[i].poz].value[j].size(); k++)
				{
					if ((dis(gen) / 100.0) < 0.5)
					{
						child1.value[j].push_back(population[prob[i].poz].value[j][k]);
						child2.value[j].push_back(population[prob[i+1].poz].value[j][k]);
					}
					else
					{
						child1.value[j].push_back(population[prob[i+1].poz].value[j][k]);
						child2.value[j].push_back(population[prob[i].poz].value[j][k]);
					}
				}
			}
			population.push_back(child1);
			population.push_back(child2);
			for (int j = 0; j < dimensions; j++)
			{
				child1.value[j].clear();
				child2.value[j].clear();
			}

		}
	}
	//PrintPopulation();
}


void GeneticAlg::RouletteWhell()
{
	random_device rand;
	mt19937 gen(rand());
	uniform_int_distribution <> dis(1, 100);
	vector<double> eval;
	double curentFit, TotFit = 0, r;
	vector<ForProb> prob;
	ForProb x;
	vector<double> probForIndivid, q;
	vector<individ> newPop;
	priority_queue<pair<double,int>> pqForElit;
	// calculez eval-ul populatiei curente

	for (unsigned i = 0; i < population.size(); i++)
	{
		curentFit = F->GetFunctionValue(population[i].value, dimensions);
		eval.push_back(curentFit);
	}

	// Calculez total fitness
	for (unsigned i = 0; i < population.size(); i++)
	{
		eval[i] = 1 / (eval[i] + 1);
		TotFit += eval[i];
		pqForElit.push(make_pair(eval[i], i));
	}

	//Prob. select. individuale

	for (unsigned i = 0; i < population.size(); i++)
	{
		probForIndivid.push_back(eval[i] / TotFit);
	}

	//Prob. select. cumulate

	q.push_back(0);
	for (unsigned i = 0; i < population.size(); i++)
	{
		q.push_back(q[i] + probForIndivid[i]);
	}
	/*
	for (unsigned i = 0; i < q.size(); i++)
	{
		cout << q[i] << '\n';
	}
	*/
	//cout << "Incepe selecta in roulet \n";
	for (unsigned i = 0; i < dimensiunePopulatieStandard - elitism; i++)
	{
		r = dis(gen) / 100.0;
		unsigned int j = 0;
		//cout << "Am intrat in while \n";
		for (j = 0; j < population.size() && !(q[j] < r && r <= q[j + 1]); j++)
		{
		}
		//cout << "Am iesit din while \n";
		if (j < population.size())
		{
			newPop.push_back(population[j]);
			//cout << "i= " << i << '\n';
		}
		else
		{
			i--;
		}
	}
	//cout << "Mij selectie \n";
	int contor = 0;
	while (contor != elitism)
	{
		contor++;
		pair<double, int> k;
		k = pqForElit.top();
		pqForElit.pop();
		newPop.push_back(population[k.second]);
	}
	//cout << "Am terminat selectia \n";
	population.clear();
	population = newPop;
	//PrintPopulation();
}

void GeneticAlg::PrintPopulation()
{
	for (int i = 0; i < population.size(); i++)
	{
		cout << "Population: " << i << '\n';
		for (int j = 0; j < dimensions; j++)
		{
			for (int k = 0; k < population[i].value[j].size(); k++)
			{
				cout << population[i].value[j][k];
			}
			cout << '\n';
		}
	}
}

void GeneticAlg::PrintFitness(vector<double> fit)
{
	for (auto x : fit)
	{
		cout << x << '\n';
	}
}

double GeneticAlg::GetBestAns()
{
	double ans, curent;
	ans = F->GetFunctionValue(population[0].value, dimensions);
	for (unsigned i = 1; i < population.size(); i++)
	{
		curent = F->GetFunctionValue(population[i].value, dimensions);
		if (curent < ans)
		{
			ans = curent;
		}
	}
	return ans;
}


GeneticAlg::~GeneticAlg()
{
}

double GeneticAlg::GetResult()
{
	double result = 0.0;
	Init();
	for (int i = 0; i < 3000; i++)
	{
		//cout << "Am incept mutatia \n";
		Mutation();
		//cout << "Am trecut de mutatie \n";
		//cout << "Am incept crossoverul \n";
		CrossOver();
		//cout << "Am trecut de crossover \n";
		//cout << "Am incept RouletWhell \n";
		RouletteWhell();
		//cout << "Am trecut de crossover \n";
		//cout << "Am facut tura: " << i << "\n";
	}
	result = GetBestAns();
	Del();
	return result;
}

