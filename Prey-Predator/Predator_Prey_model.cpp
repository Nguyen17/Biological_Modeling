#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <string.h>



using namespace std;

int main()
{
	int n; // size of array


	// Initializing model parameters
	double r = 0.1;
	double a = 0.0005;
	double d = 0.1;
	double b = 0.2;


	cout << "Enter time(months): " << endl;
	cin >> n;

	double V[n]; // V_t is the prey model
	double P[n]; // Predator model

	V[0] = 1500; // initialize the prey to 1500 starting size
	P[0] = 50;



	for (int t = 0; t < n; ++t)
	{
		V[t + 1] = V[t] + (r * V[t]) - (a * V[t] * P[t]);

		P[t + 1] = P[t] + ( a * b * V[t] * P[t]) - (d * P[t]);
	}

/*	ofstream outFile;
	outFile.open("input.txt");

	for (int i = 0; i < n; ++i)
	{	
		string data;
		outFile << 	printf("%7.1d\t%7.2f\t%7.2f\n", i ,V[i], P[i] );
		
	}

	outFile.close();*/

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
		for ( int i = 0; i <= n; i++ )
		{
			fprintf( outfile, "%7.1d\t%7.2f\t%7.2f\n", i ,V[i], P[i] ) ;
		}
		fclose( outfile );


	}
}