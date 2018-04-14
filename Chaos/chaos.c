/**
 * Name: Timmy Nguyen
 * Date: 4/27/17
 * BIOL 480 SPRING 2017
 * ASSIGNMENT #11: Chaos System Model
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	// INIT VARIABLE
	double a;

	// PROMPT USER INPUT
	printf("Enter value for variable a: \n");
	scanf("%lf", &a);

	// CREATING ARRAY
	double N_[1000];
	N_[0] = 0.101;
	int counter = 0;

	// MAIN CODE HERE
	for (int gen = 0; gen < 25; gen++)
	{
		N_[gen + 1] = a * N_[gen]*(1 - N_[gen]);
		counter++;
	}
	
	// OUTPUT DATA TO EXTERNAL FILE
	FILE *outfile;

	outfile = fopen("output.txt", "w+");
	for (int i = 0; i < counter; ++i)
	{
		/* code */
		fprintf(outfile, "%7.6f\n", N_[i] );
	}
	fclose(outfile);
	return 0;
}