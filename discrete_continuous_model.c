/**
 * Name: Timmy Nguyen
 * 
 * Assignment #1: Discrete and Continous Modeling
 * Exercise 1.4
 * 	Assume you have a culture of bacteria growing in a petri dish, 
 *  and each cell divides into two identical copies of itself every 10 minutes
 *
 */

#include <stdio.h>
#include <math.h>


#define e 3.14

int main(int argc, char const *argv[])
{
	/**
	 * code
	 * d) solve both models.
	 * 
	 */
	
	// Init Variables
	// let gereration be the duration in minutes
	int generation;	

	printf("Enter # of generations(in minutes): \n");
	scanf("%d", &generation);

	// Time Step
	double step;
	printf("Enter time step: \n");
	scanf("%lf", &step);

	// let N[] be population size
	double N[generation];	
	

	// let r = growth rate
	// since cell divides once every 10min
	double r = 0.1;

	for (int t = 0; t < generation; t = t + step)
	{	
		/**
		 * Discrete model 
		 *  - N_t+1 = N_t + r * N_t
		 */
		if (t == 0)
		{
			// let initial pop. be 20 bacteria
			N[0] = 10;	
			printf("%f\n", N[t] );
			continue;
		}
		N[t] = N[t-1] + (r * N[t-1]);
		printf("%f\n", N[t] );

	}

	printf("\n");
	
	/**
	 * Continuous Model
	 */
	double P[generation];

	for (int t = 0; t < generation; t = t + step)
	{
		/* code */
		if (t == 0)
		{
			P[0] = 10;
			printf("%f\n", P[t] );
			continue;
		}
		P[t] = P[0] * pow(e, (r * t));
		printf("%f\n", P[t] );
	}



	



	return 0;
}