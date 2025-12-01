// Chapter 6 Project.cpp : This file contains the 'main' function.
// Program to calculate the average of the middle three scores from five judges
// 

#include <iostream>
#include <iomanip>
using namespace std;

double getScore();
bool isLower(double a, double b);
bool isHigher(double a, double b);
double calcAverage(double total, double minScore, double maxScore);

// calculates the aveerage of the middle three scores from five judges 
// inputs are five scores from judges between 0 and 10

int main()
{

	double score;
	double total = 0;
	double minScore, maxScore; // to track min and max scores

	cout << fixed << setprecision(1);

	cout << "Enter score for judge 1: \n"; 
	score = getScore();
	total = score;

	minScore = score;
	maxScore = score;

	for (int i = 2; i <= 5; i++) 
	{
		cout << "Enter score for judge " << i << " : \n";
		score = getScore();
		total += score;

		if (isLower(score, minScore)) // update min score
			minScore = score;

		if (isHigher(score, maxScore)) // update max score
			maxScore = score;

	}

	double average = calcAverage(total, minScore, maxScore); // calculate average of middle three scores
	cout << "\nFinal Score (average of middle 3 scores): " << average << endl;
	return 0;


}

double getScore() // function to get a valid score between 0 and 10
{
	double score;
	do {
		cout << "Enter a score (0-10): ";
		cin >> score;

		if (score < 0 || score > 10)
			cout << "Invalid input. Score must be between 0 and 10.\n";
	} while (score < 0 || score > 10);

	return score;


}

bool isLower(double a, double b) // function to check if a is lower than or equal to b
{
	return a <= b;

}

bool isHigher(double a, double b) // funciton to chec if a is higher than or equal to b 
{
	return a >= b;
}

double calcAverage(double total, double minScore, double maxScore) 
{
	double middleTotal = total - minScore - maxScore;
	return middleTotal / 3.0;

}
