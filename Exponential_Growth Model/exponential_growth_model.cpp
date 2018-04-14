// Name: Timmy Nguyen
// Date: 1-30-2016
// Assignment 1: Exponential Growth Model
// Biol 480 Spring 2016

#include <iostream>
#include <iomanip>
#include <string>
// For output file writing.
#include <fstream>
using namespace std;

// # of Months: 10
const int length = 10;

// Spacing function for formatting
string spacing()
{
	string spacing_ = "    ";
	return spacing_;
}

int main()
{	
	// Given reproductive rate
	double r = 0.5;

	// Initial time
	double t = 0.0;

	// Initial Population
	double *N_array;
	N_array = new double[length];
	N_array[0] = 2;
	
	/**
	 * @brief Exponential Growth Equation
	 * @details Output prediction observation values
	 * @return prediction data
	 */
	for (int i = 0; i < 11; ++i)
	{
			N_array[i + 1] = N_array[i] + r * N_array[i];
	}

	/**
	 * @brief Output file
	 * @details write to a separate file
	 * @return written data.
	 */
	ofstream outFile;
	outFile.open("input.txt");

	for (int i = 0; i < 11; ++i)
	{
		outFile << t << spacing() << N_array[i] << endl;
		t++;
	}

	outFile.close();
	delete [] N_array;

	return 0;


}