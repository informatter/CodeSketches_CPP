

#ifndef DNA_
#define DNA_


#include "main.h"
#include <vector>
#include <list>



using namespace std;

// external  variable initializaion. variables live in sketch.cpp

extern double maxForce;



class DNA
{

public:

	// Create  a Gene list composed of random 3D vectors

	vec geneList[1300]; // geneList length = lifeSpan
	int n = 1300;
	

	DNA( vec newGenes[1300])
	{
		//geneList = newGenes;

		for (int i = 0; i < n; i++)
		{
			geneList[i] = newGenes[i];
			
		}

	}


	DNA()

	{

		// create random vector and add it to gene list
		// each agent needs a velocity vector during
		// each iteration during its life time
		for (int i = 0; i < n; i++)
		{
			geneList[i] = vec(ofRandom(-10, 10), ofRandom(-10, 10), 0);
			geneList[i].normalise();
			geneList[i] * ofRandom(0, maxForce);

			
		}



	}



	//---------------CROSSOVER-----------------//
	 DNA CrossOver(DNA partner)
	{
		
		 vec child[1300]; // initialize a static array of n children

		int midValue = ofRandom(0, n);

		for (int i = 0; i <n; i++) // take half of the genes from both parents
		{
			if (i > midValue)
			{
				child[i] = geneList[i];
				
			}

			else
			{
				child[i] = partner.geneList[i];
				
			}
		}

		DNA newGenes = DNA(child);

		return newGenes;
	}



	  void Mutation(double mutationRate)
	 {
		 for (int i = 0; i < n; i++)
		 {
			 if (ofRandom(0,1) < mutationRate) // pick random velocity vec based on a probability
			 {
				 geneList[i] = vec(ofRandom(-10, 10), ofRandom(-10, 10), 0);
				 geneList[i] *  ofRandom(0, maxForce);
			 }
		 }

	 }


	



};





#endif

