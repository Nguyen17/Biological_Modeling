/**
 * Name: Timmy Nguyen
 * Program: Euler's Method and the Logistic Model
 * BIOL 480 SPRING 2017
 * DATE: 3 - 13 - 17
 */


#include <stdio.h>
#include <string.h>


int main()
{
    // Initializing variables
    float dn,dt;


    // Initializing the rate of growth and carrying capacity
    float r = 1.5;
    float K = 100;


    printf("Enter step size: \n");
    scanf("%f", &dt);


    /**
     * PRECONDITION: Prompt user for time input
     * POSTCONDITION: Read the user input
     */
    float time_;
    
    printf("Enter time(in months): \n");
    scanf("%f" ,&time_);


    // Sets the stepsize
    int steps = time_ / dt;


    // Creating arrays of uknown size
    float N[steps + 1];
    float t[steps + 1];


    N[0] = 2;
    t[0] = 0;

    /**
     *
     * Logistic Formula
     *
     * N_t+1 = N_t + r * N * ( 1 - ( N / K) )
     *
     * dn = r * N * ( 1 - ( N / K) ) * dt
     * 
     */

    for (int i = 0; i < steps; i++)
    {
        dn = r * N[i] * ( 1 - (N[i] / K));
        N[i + 1] = N[i] + dn;
        t[i + 1] = t[i] + dt;
     }


    // Output the results
    
    for (int i = 0; i <= steps; i++)
    {
    	printf("time: %.2f \t population: %.2f\n",t[i],N[i] );
    }

    /**
     * FILE SAVE SNIPPET
     */
    
    char text[10];
    char filename[100];
    FILE *outfile;

    printf( "Save data to disk file ? (y/n) : " );
    scanf( "%s", text );
    if ( strcmp( text, "y" ) == 0 )
    {
        printf( "Enter filename for dataset : " );
        scanf( "%s", filename );
        outfile = fopen( filename, "w" );
        for ( int i = 0; i <= steps; i++ )
        {
            fprintf( outfile, "%4.1f \t%7.4f\n", t[i], N[i]);
        }
        fclose( outfile );
    }
    
}
