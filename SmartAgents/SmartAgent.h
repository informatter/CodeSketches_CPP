

#ifndef AGENT_
#define AGENT_


#include "main.h"
#include <vector>
#include "DNA.h"
#include "Target.h"
#include "Obstacle.h"




using namespace std;

extern double maxForce;
extern int geneCount;
extern int lifeSpan;





class SmartAgent
{

public:

	vec velocity;
	vec acceleration;
	vec location;
	double fitness;
	double distanceToTarget;
	bool hitTarget = false;
	bool collision = false;
	DNA dna;
	Target t = Target(vec(50, 70, 0), 10);
	Obstacle o = Obstacle(vec(-10, 20, 0), vec(60, 25, 0));
	//int geneCounter;

	

	//DNA dna;


	// CONSTRUCTOR ////////////////////////////////////////////////

	SmartAgent()
	{
		velocity = vec();
		acceleration = vec();
		location = vec(0, -20, 0);
		fitness = 0;

	}

	SmartAgent(vec location_,DNA dna_)
	{
	
		location = location_;
		dna = dna_;
	
	}


	
	  void  ApplyForce(vec force)
	{

		force.normalise();
		force *= maxForce; // constrain force by a scalar value
		acceleration += force; // Update acceleration

	}


	   void Fitness()
	  {

		  //double maxFitness = 0;

		   double distanceToTarget = location.distanceTo(t.location);
		

		  
		  //---------------------------------------------------------------------------------
		  // if distance between agent and target is small fitness will be higher (big amount)
		  // if the distance is to large, the fitness will ne lower( small amount)
		  //---------------------------------------------------------------------------------

		  fitness = pow(1 / distanceToTarget, 2);
		  //fitness = 1 / distanceToTarget;


	  }


	   void checkCollision()
	   {
		  

		   if (location.x>-10 && location.x <60  && location.y > 20 && location.y<25)
		   {
			   collision = true;
			   fitness *= 0.1;
		   }

		   if (!collision && location.y > 25);
		   {
			   fitness *= 2;
		   }

		   



	   }


	 


	   void checkTarget() 
	   {
		   double distanceToTarget = location.distanceTo(t.location);
		   if (distanceToTarget < 10)
		   {
			   hitTarget = true;
			   fitness *= 10;
		   }
	   }

	  // int geneCounter = 0;
	void Update()
	{
		//geneCounter++;
		checkTarget();
		checkCollision();
		if (!hitTarget && !collision)
		{
			Bounds();
			ApplyForce(dna.geneList[geneCount]);
			//geneCount = (geneCount + 1) % lifeSpan; // keep geneCount proportional to lifeSpan
			double maxSpeed = 0.05;
			velocity += acceleration;
			location += velocity * maxSpeed;
			acceleration *= 0;
		}
	}


	void Bounds()

	{
	
		if (location.x >50 && location.x < 0)
		{ 
			fitness *=0.1;
		}


		if (location.y >70 && location.y <0)
		{
			fitness *=0.1;
		}


	}


	double getFitness()
	{
		return fitness;
	}


	 DNA getDNA()
	{
		return dna;
	}





	 void Display(int ptSize, float r, float g, float b, bool vectorDir)
	 {

		 glPointSize(ptSize);
		 drawPoint(location);
		 glColor3f(r, g, b);

		 if (vectorDir)
		 {


			 glColor3f(1.0, 0, 0);
			 vec vel = velocity;
			 vel.normalise() * 100;
			 drawLine(location, location + vel);

			 
		 }

		
		
		
		
		

	}



};






#endif

