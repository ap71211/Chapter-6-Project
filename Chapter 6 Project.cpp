// Chapter 6 Project.cpp : Project 3 is a program that converts farenheit temperatures to celsius temperatures
// and displays a table of the conversions from 0 to 20 degrees farenheit.
//
//

#include <iostream>
#include <iomanip>
using namespace std;

const int MIN_F = 0;
const int MAX_F = 20;
double getCelsius(double fTemp);

// Function is able to exchance the max and min to adjust program to different ranges
// converts the farenheit temperature to celsius temperature
// using the formula C = (5/9) * (F - 32)
// displays a table of farenheit temperatures and their celsius equivalents
// from 0 to 20 degrees farenheit


int main()
{

	cout << "Celsius Temperature Table\n"; // Title of the table
	cout << endl;

	cout << setw(12) << "Fahrenheit" << setw(12) << "Celsius" << endl; //  Header for the table 
	cout << "----------------------------------" << endl;

	cout << fixed << setprecision(1);

	for (int f = MIN_F; f <= MAX_F; f++) // Loop to display the table from 0 to 20 degrees farenheit
	{
		double c = getCelsius(f); 

		cout << setw(12) << f << setw(12) << c << endl;
	}

	return 0;

}
double getCelsius(double fTemp)	// Function to convert farenheit to celsius
{
	double cTemp = (5.0 / 9.0) * (fTemp - 32); // Conversion formula
	return cTemp;
}
