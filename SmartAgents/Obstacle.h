

#ifndef OBSTACLE_
#define OBSTACLE_


#include "main.h"
#include <vector>

using namespace std;



extern double maxForce;



class Obstacle
{

public:
		
	vec min;
	vec max;
	
	Obstacle(vec min_, vec max_)
	{
		min = min_;
		max = max_;

	}

	Obstacle()
	{}



	void Display()
	{

		drawRectangle(min, max);

		glColor3f(1, 1, 1);




	}




};





#endif

