/*
*Course: CS215-001
*Project: Lab 8 (As the first part of Project 2)
*Purpose: to implement a Gradebook Report
* it allows the user to repeatedly enter students' scores
* until the user types "q" or "Q" to quit
* then displays all the valid scores from user input
* and the corresponding letter grades;
* the average score, highest score and lowest score.
*Author: Helen Yang
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "FinalGrade.h"
#include "FinalGrade.cpp"		// need this to be able to run using iOS

using namespace std;


// TO determine the average score of grade scores
double calculateGradebook(const vector<FinalGrade>& gradebook, double& max_score, double& min_score) {
	double avg_score = 0;
	double sum = 0;
	for (int i = 0; i < gradebook.size(); i++)
	{
		sum = sum + gradebook[i].getScore();
	}
	avg_score = sum / gradebook.size();
	return avg_score;
}


int main()
{
	vector<FinalGrade> CS215gradebook;
	double input_score;

	while (true)
	{
		cout << "Please enter a score for CS215 (type 'Q' or 'q' to quit): " << endl;
		cin >> input_score;

		// check if the user input is invalid
		if (cin.fail())
		{
			string check_input;
			cin.clear();
			cin >> check_input;
			cin.ignore(256, '\n'); //extra and ignore any possible bad input from the input stream

			if (check_input == "Q" || check_input == "q")
				break;
			else {
				cout << "Invalid input, please try again..." << endl;
				continue;
			}
		}

		// check if the input score is in the correct range: [0,100]
		if (input_score < 0 || input_score > 100)
		{
			cout << "The score is not in the correct range, please try again..." << endl;
		}
		else // valid user input, store into gradeList object
		{
			FinalGrade inputFG(input_score);
			CS215gradebook.push_back(inputFG);
		}

		cin.ignore(256, '\n'); //extra and ignore any possible bad input from the input stream
	}

	// Check if the gradebook is empty
	// If it is empty, report it then quit the program
	if (CS215gradebook.size() == 0)
	{
		cout << "The gradebook for CS215 is empty!" << endl;
		return 1;
	}

	// if the gradebook is not empty
	// Display each score and corresponding letter grade in the grade 
	// Display the average score, the highest and lowest scores from the gradebook
	cout << endl << endl;
	cout << "The gradebook for CS215:" << endl;
	cout << fixed << setprecision(2);
	for (int i = 0; i < CS215gradebook.size(); i++)
	{
		CS215gradebook[i].print();
	}

	// determine the greatest score 
	double max_score = 0;
	max_score = CS215gradebook[0].getScore();
	for (int i = 0; i < CS215gradebook.size(); i++)
	{
		if (CS215gradebook[i].getScore() > max_score) {
			max_score = CS215gradebook[i].getScore();
		}
	}

	// determine the lowest score
	double min_score = 0;
	min_score = CS215gradebook[0].getScore();
	for (int i = 0; i < CS215gradebook.size(); i++)
	{
		if (CS215gradebook[i].getScore() < min_score) {
			min_score = CS215gradebook[i].getScore();
		}
	}
	double average = calculateGradebook(CS215gradebook, max_score, min_score);
	cout << "The average score is: " << average << endl;
	cout << "The highest score is: " << max_score << endl;
	cout << "The lowest score is: " << min_score << endl;
	return 0;
}