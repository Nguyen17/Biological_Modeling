// Name: Timmy Nguyen
// Date: 2-8-2016
// Assignment 2: Logistics Growth Model
// Biol 480 Spring 2016

#include <stdio.h>
#include <string.h>

int main()
{
	// Initial variable length(in months)
	int length;
	
	// Given reproductive rate
	double r = 0.25;

	// Initial Carrying Capacity
	int K_ = 100;


	/**
	 * Prompt user for specific time period in months
	 */
	printf("Enter time(in months): \n");
	scanf("%i", &length);

	// Create First Array
	double pop_below_K[length];

	// Sets the population below carrying capacity
	pop_below_K[0] = 2;

	/**
	 * @brief Logistic Population Growth Equation
	 * @details Output prediction observation values
	 * @return prediction data
	 */
	for (int i = 0; i < length; ++i)
	{
		pop_below_K[i + 1] = pop_below_K[i] + r * pop_below_K[i] * (1 - (pop_below_K[i] / K_));
		printf("%.4f\n", pop_below_K[i]);
	}


	// Creating Second Array
	double pop_above_K[length];
	// Sets the population above carrying capacity
	pop_above_K[0] = 120;

	/**
	 * @brief Logistic Population Growth Equation
	 * @details Output prediction observation values
	 * @return prediction data
	 */
	for (int j = 0; j < length; ++j)
	{
		pop_above_K[j + 1] = pop_above_K[j] + r * pop_above_K[j] * (1 - (pop_above_K[j] / K_));
		printf("%.4f\n", pop_above_K[j] );
	}

	/**
	 * FILE SAVE
	 */

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
		for ( int i = 0; i <= length; i++ )
		{
			fprintf( outfile, "%4.1i\t%7.4f\n", i, pop_below_K[i]);
		}
		fclose( outfile );

		printf( "Enter filename for second dataset: " );
		scanf( "%s", filename );
		outfile = fopen( filename, "w" );
		for ( int i = 0; i <= length; i++ )
		{
			fprintf( outfile, "%4.1i\t%7.4f\n", i, pop_above_K[i] );
		}
		fclose( outfile );
	}



	return 0;


}