// Chapter 6 Project.cpp : This file contains project 2- Safest driving area program 
// Write modular functions to gather and validate accident date 
// use comparison functinos (isLower) to dtermine minumum values 
// Implement a program that identifies the safest region by number of accidents 
// display results clearly using modular output funcitons 
// 
// 

#include <iostream>
#include <string>
using namespace std;

int main()
{

	void getRegInfo(string & regionName, int& accidents);
	bool isLower(int firsr, int second);
	void showLowest(const string & safestRegion, int accidents);

	string regionName;
	int accidents;

	string safestRegion;
	int lowestAccidents;

	cout << "Enter accident data for 5 regions ( North, South, East, West, Central)  \n";

	getRegInfo(regionName, accidents);
	safestRegion = regionName;
	lowestAccidents = accidents;

	for (int i = 0; i < 4; i++)
	{
		getRegInfo(regionName, accidents);
		if (isLower(accidents, lowestAccidents))
		{
			lowestAccidents = accidents;
			safestRegion = regionName;

		}

	}

	showLowest(safestRegion, lowestAccidents);

	return 0;
}
void getRegInfo(string& regionName, int& accidents)
{
	cout << "Enter region name: ";
	cin >> regionName;

	do {
		cout << "Enter number of accidents (>= 0); ";
		cin >> accidents;

		if (accidents < 0)

			cout << "Invalid input. Number of accidents must be non-negative.\n";

	} while (accidents < 0);
}

bool isLower(int first, int second)
{

	return first <= second;
}

void showLowest(const string& safestRegion, int accidents)

{
	cout << "Safest Region: " << safestRegion << endl;
	cout << "Number of accidents: " << accidents << endl;


}
		