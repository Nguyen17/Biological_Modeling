/**
 * Name: Timmy Nguyen
 * Lab Exercise 7: Newton Method
 * BIO 480 Spring 2017
 * Date: 3-21-17
 */

#include <stdio.h>
#include <math.h>

// Global Constants
double x1,x2;
double e = 0.00001;

// Create function f(x)
/**
 * 
 * Y = x^2 ; y = 7
 * x^2 - 7 = 0
 * 
 */
double f(double x)
{
	return x * x - 7;
}

// Finds the derivative of f(x)
double fderiv(double x)
{
	double h = 0.0001;

	// Difference Quotient
	double diff_q =  ( f(x+h) - f(x-h) ) / (2 * h);
	return diff_q;
}


int main(int argc, char const *argv[])
{	
	// Prompt User for initial x1 value
	printf("Set initial guess: \n");
	scanf("%lf", &x1);

	/**
	 * Iteratives until tolerance +- 0.00001 is met
	 * - maximum 100 steps
	 */
	int steps = 100;

	for (int i = 0; i < steps; ++i)
	{
		x2 = x1 - f(x1) / fderiv(x1);
		
		// When tolerance condition is met, end the loop
		if (fabs(x2-x1) < e)
		{
			break;
		}
		
		printf("Results are %f\n", x2);

		x1 = x2;

	
	}

	return 0;
}