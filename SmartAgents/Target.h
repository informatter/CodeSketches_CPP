

#ifndef TARGET_
#define TARGET_


#include "main.h"
#include <vector>



using namespace std;

// external  variable initializaion. variables live in sketch.cpp

extern double maxForce;



class Target
{

public:
		
	
	vec location;
	 double radius;

	 Target(vec Location, double Radius)
	{
		location = Location;
		radius = Radius;

	}

	 Target()
	{
		 location = vec(0, 0, 0);
		 radius = 10;
	}


	 void Display()
	{

		 drawCircle(location, radius,400);

		 glColor3f(0, 0, 0);

		 

		 
	}





};





#endif

