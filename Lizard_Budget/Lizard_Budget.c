/**
 * Name: Timmy Nguyen
 * Lab Exercise 8: Lizard Budget
 * BIO 480 Spring 2017
 * Date: 3-30 -17
 */

#include <stdio.h>
#include <string.h>
#include <math.h>


// Global Constants
double x1, x2;
double e = 0.00001;
double k1 = 3.49;


// Euler's number
double e_ = 2.7182818284590452353602874713527;

// Stefan - Boltzmann Constant
double q_ = 0.0000000567;

/**
 * -- Lizard Budget Variables --
 *
 * Qa -> radiation inflow
 * Qout -> radiation outflow
 * V -> Wind speed
 * D -> lizard diameter
 * I -> insulation resistance
 * C -> Convection term
 * M -> Metabolic term
 * Hc -> convection coefficient
 * Ta -> air temperature
 * Tb -> lizard body core temp
 *
 */


double Qa, V, D, I_, emissitivity, Ta;
double  Tb, Qout, C, lamda_e, M, Hc;

double lizard_budget;
double lizard_mass, lizard_sa;

// Create function f(x) -> Lizard Budget
// Solving for Tb
double f(double x)
{
	Tb = x;

	Qout = emissitivity
	       * q_
	       * pow(Tb + 273.15 - I_ * ( M - lamda_e), 4);


	M = 0.0258 * pow(e_, (Tb / 10));


	Hc = k1 * sqrt(V / D);



	if (Tb <= 20)
	{
		lamda_e = 0.27;
	}
	else if (20 < Tb && Tb < 36)
	{
		lamda_e = 0.08 * pow(e_, 0.0586 * Tb);
	}
	else
	{
		lamda_e = 0.00297 * pow(e_, 0.1516 * Tb );
	}

	C = Hc * ( Tb - Ta - I_ * ( M - lamda_e));


	lizard_budget = M - lamda_e + Qa - Qout - C;

	return lizard_budget;
}

// Finds the derivative of f(x)
double fderiv(double x)
{
	double h = 0.0001;

	// Difference Quotient
	double diff_q =  ( f(x + h) - f(x - h) ) / (2 * h);
	return diff_q;
}


double solve(double x)
{
	int steps = 100;
	for (int i = 0; i < steps; ++i)
	{
		x2 = x1 - f(x1) / fderiv(x1);

		// When tolerance condition is met, end the loop
		if (fabs(x2 - x1) < e)
		{
			break;
		}

		x1 = x2;

	}

	return x;
}

int main(int argc, char const *argv[])
{

// Prompt user inputs

	/*	printf("Enter Qa: \n");
		// scanf("%lf", &Qa );

		printf("Enter Wind Speed(V): \n");
		// scanf("%lf", &V );

		printf("Enter Lizard Size(D): \n");
		// scanf("%lf", &D );

		printf("Enter Lizard Mass: \n");
		// scanf("%lf", &lizard_mass );

		printf("Enter Lizard Area: \n");
		// scanf("%lf", &lizard_sa );


		printf("Enter Insulation Resistance(I): \n");
		// scanf("%lf", &I_ );

		printf("Enter emissitivity: \n");
		// scanf("%lf", &emissitivity );

		printf("Enter air temperature(Ta): \n");
		// scanf("%lf", &Ta );*/

	// Init variables
	Qa = 700;
	V = 2.0;
	D = 0.01;
	I_ = 0.002;
	emissitivity = 0.95;
	Ta = 40;
	lizard_mass = 0.067;
	lizard_sa = 0.018;

	printf("Input variables: \n");
	printf("Qa: %lf\n", Qa);
	printf("V: %lf\n", V);
	printf("D: %lf\n", D);
	printf("I_: %lf\n", I_);
	printf("emissitivity: %lf\n", emissitivity);
	printf("Ta: %lf\n", Ta);
	printf("lizard mass: %lf\n", lizard_mass);
	printf("lizard area: %lf\n", lizard_sa);

	printf("\n");

	// Settings maximum body core temp
	x1 = 45;


	// Saving file

	char text[100];
	char filename[100];
	FILE *outfile;

	printf( "Save data to disk file ? (y/n) : " );
	scanf( "%s", text );
	if ( strcmp( text, "y" ) == 0 )
	{
		printf( "Enter filename for first dataset : " );
		scanf( "%s", filename );
		outfile = fopen( filename, "w" );

		while (x2 < 45)
		{
			solve(x1);
			D = D + 0.001;
			fprintf(outfile, "%lf \t %lf\n", D, x2);
		}

		fclose( outfile );

	}

	double lizard_ratio = lizard_mass / lizard_sa;

	// Output to console
	
	printf("Energy Terms: \n");
	printf("Qa = %lf\n", Qa);
	printf("Tb = %lf\n", Tb);
	printf("Qout = %lf\n", Qout);
	printf("C = %lf\n", C);

	lamda_e = lamda_e * lizard_ratio;
	M = M * lizard_ratio;

	printf("E = %lf\n", lamda_e);
	printf("M = %lf\n", M);


	return 0;
}