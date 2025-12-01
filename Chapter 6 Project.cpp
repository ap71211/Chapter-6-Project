// Chapter 6 Project.cpp : This file contains the 'main' function.
// Program one is about Rectange properties
// Using modular function for input, validation, calciulations and output
// Pass values by reference when functions retunr multiple results
// calculate and display the perimeter and area of a rectangle
// implement repition controlled by the user
//

#include <iostream>
using namespace std;

int main()
{

	void getLength_Width(double& length, double& width);
	double calcPerimeter(double length, double width);
	double calcArea(double length, double width);

	void displayProperties(double length, double width, double perimeter, double area);

	double length, width, perimeter, area;
	char choice;

	do {
		getLength_Width(length, width);

		perimeter = calcPerimeter(length, width); // function call to calculate perimeter
		area = calcArea(length, width);

		displayProperties(length, width, perimeter, area); // function call to display rectangle properties

		cout << "Would you like to process another rectangle? (Y/N); ";
		cin >> choice;

	} while (choice == 'Y' || choice == 'y');
	cout << "Goodbye " << endl;
	return 0;
} 
void getLength_Width(double& length, double& width) // pass by reference
{
	do {
		cout << "Enter the leght of the rectangle must be greater than 0: ";
		cin >> length;
		cout << endl;

		if (length <= 0)
			cout << "Invalid entry. Length must be greater than 0." << endl;
	} while (length <= 0);
	do {
		cout << "Enter the width of the rectangle must be greater than 0: ";
		cin >> width;
		cout << endl;

		if (width <= 0)
			cout << "Invalid entry. Width must be greater than 0." << endl;
	} while (width <= 0);

}
double calcPerimeter(double length, double width) 
{
	return 2 * (length + width);// formula for perimeter
}
double calcArea(double length, double width) 
{
	return length * width;// formula for area
}
void displayProperties(double length, double width, double perimeter, double area) // display rectangle properties
{
	cout << "Rectangle properties: " << endl;
	cout << "Length: " << length << endl;
	cout << "Width: " << width << endl;
	cout << "Perimeter: " << perimeter << endl;
	cout << "Area: " << area << endl;
	cout << endl;




}