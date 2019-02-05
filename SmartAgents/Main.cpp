#define _MAIN_

#ifdef _MAIN_

#include "main.h"
#include "SmartAgent.h"
#include "Population.h"
#include "DNA.h"
#include "Target.h"
#include "Obstacle.h"

 





//////////////////////////////////////				INCLUDES				//////////////////////////////////////







//////////////////////////////////////	OTHER DEFINITIONS / GLOBAL VARIABLES	//////////////////////////////////////
//double maxForce = 0.4;


char s[200];
char r[200];
char x[200];

int lifeSpan = 1300;
double maxForce = 0.05;
int generationCount;
int lifeCount;
int geneCount=0; 
int test;



Population pop;
SmartAgent sa;
Target t;
Obstacle o;






////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////				MVC APPLICATION				//////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
///// ---------------------------------------------------------- MODEL ------------------------------




void setup()
{
	pop = Population();
	t = Target(vec(50, 70, 0), 10);
	sa = SmartAgent();
	o = Obstacle(vec(-10, 20,0), vec(60, 25, 0));
	lifeCount = 0;

	 generationCount = 0;

	
	
}

void update(int value)
{

	if (geneCount < lifeSpan)
	{
		

		pop.live();
		geneCount++;
		lifeCount++;
		

	}

	else
	{

		geneCount = 0;
		lifeCount = 0;
		pop.fitness();
		pop.Selection();
		pop.Reproduction();

		//cout << pop.getMaxFitness() <<endl;
		//cout << generationCount;
		generationCount+=1;
		
	}






	
}


///// ---------------------------------------------------------- VIEW  ------------------------------

void draw()
{

	
	backGround(0.75);
	drawGrid(20);
	
	if (geneCount < lifeSpan)
	{
		pop.display();
		
	}
	t.Display();
	o.Display();

	sprintf_s(s, " total generations : %i", generationCount);
	sprintf_s(x, " Cicles left : %i", lifeSpan - lifeCount);
	sprintf_s(r, " Maximum fitness : %i", pop.getMaxFitness());


	setup2d();

	drawString(s, winW * 0.05, winH *0.1);
	drawString(x, winW * 0.05, winH *0.15);
	drawString(r, winW * 0.05, winH *0.20);
	

	restore3d();
	
}


///// ---------------------------------------------------------- CONTROLLER ------------------------------


void mousePress(int b, int state, int x, int y)
{

}

void mouseMotion(int x, int y)
{

	
}


void keyPress(unsigned char k, int xm, int ym)
{

	
}





#endif 
