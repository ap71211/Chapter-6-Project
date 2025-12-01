// This program estimates the cost of a paint job based on user input for number of rooms,
// square footage, and price per gallon of paint.


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double SQFT_PER_GALLON = 110.0; // square feet per gallon
const double LABOR_HOURS_PER_GALLON = 8.0; // labor hours per gallon
const double LABOR_RATE = 25.0; // labor rate per hour

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

	numRooms = getRooms(); // get number of rooms

	for (int i = 1; i <= numRooms; i++) // loop for each room
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

int getRooms() // function to get number of rooms
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

double getSqFt() // function to get square footage
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

double getPricePerGallon() // function to get price per gallon
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

int gallonsForRoom(double sqft) // function to calculate gallons needed
{

	return ceil(sqft / SQFT_PER_GALLON);


}

double laborForRoom(double sqft) // function to calculate labor hours needed
{

	return (sqft / SQFT_PER_GALLON) * LABOR_HOURS_PER_GALLON;


}

void displayEstimate(double paintCharge, int gallonsNeeded, double laborCharge, double laborHours) // function to display estimate

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


