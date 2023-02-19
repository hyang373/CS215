/*
Lab 3
Class: CS 215-001
Author: Helen Yang
Purpose: to determine the amount and type of vechicle needed for the trip
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// number of students planning to travel
	int numStudents;
	cout << "Please enter the number of students: ";
	cin >> numStudents;
	
	// how many cars to rent?
	int numBus = 0;
	int numVan = 0;
	int numSUV = 0;
	int numSedan = 0;

	if (numStudents < 0) {
		cout << "Invalid number of passengers!" << endl;
		return 0;
	}

	// limitaions : each vechicle must be at full capacity; 
	// bus - 56 people (MAX 4 buses)
	// van - 13 people (MAX 5 vans)
	// SUV - 7 people (unlimited)
	// sedan - 3 people (unlimited)

	cout << "The travel team need to rent: " << endl;

	const int MAX_CAPACITY_BUS = 56;
	const int MAX_CAPACITY_VAN = 13;
	const int MAX_CAPACITY_SUV = 7;
	const int MAX_CAPACITY_SEDAN = 3;
	const int MAX_AMT_BUS = 4;
	const int MAX_AMT_VAN = 5;

	// calculate types of vechicle needed
	if (numStudents / MAX_CAPACITY_BUS != 0) {
		numBus = numStudents / MAX_CAPACITY_BUS;
		
		if (numBus > MAX_AMT_BUS) {
			numBus = MAX_AMT_BUS;
		}
		numStudents = numStudents - numBus * MAX_CAPACITY_BUS;
		if (numStudents / MAX_CAPACITY_VAN != 0) {
			numVan = numStudents / MAX_CAPACITY_VAN;
			if (numVan > MAX_AMT_VAN) {
				numVan = MAX_AMT_VAN;
			}
			numStudents = numStudents - numVan * MAX_CAPACITY_VAN;
		}
		if (numStudents / MAX_CAPACITY_SUV != 0) {
			numSUV = numStudents / MAX_CAPACITY_SUV;
			numStudents = numStudents - numSUV * MAX_CAPACITY_SUV;
		}
		if (numStudents / MAX_CAPACITY_SEDAN != 0) {
			numSedan = numStudents / MAX_CAPACITY_SEDAN;
			numStudents = numStudents - numSedan * MAX_CAPACITY_SEDAN;
		}
		if (numStudents > 0) {
			numSedan++;
		}
	}

	// display numbers and types of vechicle needed
	if (numBus > 0) 
		cout << numBus << " bus(es)." << endl;
	
	if (numVan > 0)
		cout << numVan << " van(s)." << endl;
	
	if (numSUV > 0)
		cout << numSUV << " SUV(s)." << endl;
	
	if (numSedan > 0)
		cout << numSedan << " sedan(s)." << endl;

	return 0;
}
