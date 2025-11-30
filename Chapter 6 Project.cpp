// Chapter 6 Project.cpp : This file contains the 'main' function.
// 

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double SQFT_PER_GALLON = 110.0;
const double LABOR_HOURS_PER_GALLON = 8.0;
const double LABOR_RATE = 25.0;

int getRooms();
double getSqFt();
double getPricePerGallon();
int gallonsForRoom(double sqft);
double laborForRoom(double sqft);

void displayEstimate(double paintCharge, int gallonsNeeded, double laborCharge, double laborHours);

int main()
{

	int numRooms;
	double paintCharge = 0, laborCharge = 0, laborHours = 0;
	int gallonsNeeded = 0;

	numRooms = getRooms();

	for (int i = 1; i <= numRooms; i++)
	{
		cout << "Room" << i << endl;

		double sqft = getSqFt();
		int gallons = gallonsForRoom(sqft);
		double pricePerGallon = getPricePerGallon();
		double labor = laborForRoom(sqft);

		gallonsNeeded += gallons;
		paintCharge += gallons * pricePerGallon;
		laborHours += labor;
		laborCharge += labor * LABOR_RATE;

	}
	displayEstimate(paintCharge, gallonsNeeded, laborCharge, laborHours);

	return 0;


}

int getRooms()
{

	int rooms;
	do {
		cout << "Enter number of rooms to be painted (>= 1): ";
		cin >> rooms;

		if (rooms < 1)
			cout << "Invalid. Must be at least 1. \n";


	} while (rooms < 1);

	return rooms;



}

double getSqFt()
{

	double sqft;
	do {
		cout << "Enter square feet of wall space (>0): ";
		cin >> sqft; 
		if (sqft <= 0)
			cout << "Invalid. Must be positive nunber. \n";

	} while (sqft <= 0);

	return sqft;


}

double getPricePerGallon()
{
	double price;
	do {


		cout << "Enter price per Gallon (>= $10): ";
		cin >> price;

		if (price < 10)
			cout << "Invalid. Must be at least $10. \n";


	} while (price < 10);

	return price;

}

int gallonsForRoom(double sqft)
{

	return ceil(sqft / SQFT_PER_GALLON);


}

double laborForRoom(double sqft)
{

	return (sqft / SQFT_PER_GALLON) * LABOR_HOURS_PER_GALLON;


}

void displayEstimate(double paintCharge, int gallonsNeeded, double laborCharge, double laborHours)

{

	cout << fixed << setprecision(2);

	double totalCost = paintCharge + laborCharge;

	cout << endl;
	cout << "--Paint Job Estimate per rooms inputed--\n";
	cout << "Gallons of paint required:    " << gallonsNeeded << endl;
	cout << "Hours of labor required:      " << laborHours << endl;
	cout << "Cost of paint :              $" << paintCharge << endl;
	cout << "Labor charges:               $" << laborCharge << endl;
	cout << endl;
	cout << "Total cost of paint job:     $" << totalCost << endl;
	cout << endl;




}


