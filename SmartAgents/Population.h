

#ifndef POPULATION_
#define POPULATION_


#include "main.h"
#include <vector>
#include <list>
#include "SmartAgent.h"
#include "Target.h"

using namespace std;



extern int size;





class Population
{

public:

	

	int n = 200;
	double mutationRate = 0.01;

	SmartAgent agentPopulation[200];  // initialize a static array of 100 agents
	vector <SmartAgent> matingPool;
	Target t;
	

	//vector<SmartAgent> agentList;
	

	

	Population()

	{}

	void fitness()
	{
	
		for(int i = 0;i < n;i++)
		 {
			agentPopulation[i].Fitness();
		 }
	
	}

	/*void GetDistances()
	{
	
		for (int i = 0; i < n; i++)
		{
			agentPopulation[i].distanceToTarget;
		}
	}*/


	//--------------SELECTION-------------///

	void Selection()
	{

		matingPool.clear();
		double maxFitness = getMaxFitness();

		// multiply all fitness values by 100 (just a value) to make the probability
		// higher in adding the agents with higher fitness values to the mating pool

		for(int i = 0;i < n;i++)
		
		{

			
			double fitnessNormal = Map(agentPopulation[i].getFitness(), 0, maxFitness, 0, 1);
			int a = (int)(fitnessNormal * 100);
			

			for (int j = 0; j < a; j++)
			{
				matingPool.push_back(agentPopulation[i]);  // Add agents to mating pool with highest fitness values
			}
		}


	}

	//--------------REPRODUCTION-------------///
	 void Reproduction()
	{

		for(int i = 0;i < n;i++)
		
		{

			int indexA = ofRandom(0, matingPool.size());
			int indexB = ofRandom(0, matingPool.size());
			
			// pick parents

			SmartAgent parentA = matingPool[indexA];

			SmartAgent parentB = matingPool[indexB];

			// get parent genes
			DNA parentAGenes = parentA.getDNA();
			DNA parentBGenes = parentB.getDNA();

			// produce child
			DNA child = parentBGenes.CrossOver(parentAGenes);

			// gene mutation
			child.Mutation(mutationRate);

			// create new population with next generation
			vec location = vec ();
			agentPopulation[i] = SmartAgent(location, child);

		}

		//generations++;
	}

	//--------------GET MAX FITNESS-------------///
	 double getMaxFitness()
	{
		double record = 0;

		for(int i = 0;i < n;i++)
		
		{
			if (agentPopulation[i].getFitness() > record)
			{
				record = agentPopulation[i].getFitness();

			}


		}

		return record;
	}





	double getFitnessVal()
	{
		double temp = 0;
		for ( int i = 0; i < n; i++)
		{
			
			temp = agentPopulation[i].getFitness();
		}

		return temp;
	
	}





	
	void live()

	{
		

		for (int i = 0; i < n; i++)
		{
			
			agentPopulation[i].Update();

			//agentPopulation[i].Bounds();
		}

	}

	void display()
	{

		

		for (int i = 0; i < n; i++)
		{

			agentPopulation[i].Display(1,0.1,0.1,0.1,true);

		}



	}


	




	//--------------------------- PRIVATE METHODS-------------------------------------------------///
	private:



		double Map(double valueToMap, double sourceDomainMin, double  sourceDomainMax, double targetDomainMin, double targetDomainMax)
		{
			return targetDomainMin + (targetDomainMax - targetDomainMin) * ((valueToMap - sourceDomainMin) / (sourceDomainMax - sourceDomainMin));
		}





};




#endif

