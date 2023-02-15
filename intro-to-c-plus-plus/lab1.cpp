/*
 * Course : CS 215-001
 * Project : Lab 1
 * Properties : introduction
 * Author : Helen Yang
 */

#include <iostream>
using namespace std;

int main()
{
	cout << "Hello!" << endl;
	cout << "My name is Helen Yang. Nice to meet you!" << endl;
	cout << "   @@@@@@  " << endl;
	cout << " |       |" << endl;
	cout << " | ~~  ~~|" << endl;
	cout << "{{__*__*_}}" << endl;
	cout << " |       |" << endl;
	cout << " |       |" << endl;
	cout << " |_______|" << endl;

	//collect user input and calculate the time spent 
	double hours = 0.0;     // declare a varible to store how many hours 
	cout << "How many hours are you going to spend on CS215 every week?" <<
		endl;
	cin >> hours;
	const int HOUR_TO_MIN = 60;        //declare a constant: 1 hour = 60 minutes 
	const int MIN_TO_SEC = 60;        //declare a constant: 1 minute = 60 seconds 
	double seconds = hours * HOUR_TO_MIN * MIN_TO_SEC;
	cout << "Good Luck! You will spend " << seconds << " seconds each week on CS215." << endl;

	return 0;
}
