/*
* Lab 2
* Author: Helen Yang
* Course: CS 215-001
* Purpose: to direct a cashier how much change to give
*/

#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	// Declare a variable to store the total cost of purchase
	double amount_due = 0.0;
	
	// Declare a variable to store the amount received for payment
	double amount_received = 0.0;

	cout << "Enter the amount due : $  ";
	cin >> amount_due;
	cout << "Enter the amount received : $  ";
	cin >> amount_received;
		
	double change = amount_received - amount_due;	//declare a variable to store the total change the cashier needs to give back
	cout << "The change is: " << endl;
	
	const int DOLLAR_VALUE = 1;					//declare a constant: dollar = $1
	const double QUARTER_VALUE = 0.25;				//declare a constant: quarter = $0.25
	const double DIME_VALUE = 0.10;					//declare a constant: dime = $0.10
	const double NICKEL_VALUE = 0.05;				//declare a constant: nickel = $0.05
	const double PENNY_VALUE = 0.01;				//declare a constant: penny = $0.01
	const double ROUND_OFF = 0.005;					//declare a constant: round off value (make sure pennies round up)
	
	double current_change = change;
	int dollar_change;
	int quarter_change;
	int dime_change;
	int nickel_change;
	int pennies_change;
	
	for(int i = 0; i < 5; i++){
		switch(i){
			case 0:
				dollar_change = current_change / DOLLAR_VALUE;
				current_change = current_change - dollar_change * DOLLAR_VALUE;
				continue;
			case 1:
				quarter_change = current_change / QUARTER_VALUE;
				current_change = current_change - quarter_change * QUARTER_VALUE;
				continue;
			case 2:
				dime_change = current_change / DIME_VALUE;
				current_change = current_change - dime_change * DIME_VALUE;
				continue;
			case 3:
				nickel_change = current_change / NICKEL_VALUE;
				current_change = current_change - nickel_change * NICKEL_VALUE;
				continue;
			case 4:
				pennies_change = (current_change / PENNY_VALUE) + ROUND_OFF;
				current_change = current_change - pennies_change * PENNY_VALUE;
				continue;
			default:
				continue;
		}
	}
	
	cout << "Dollars:" << setw(8) << dollar_change << endl;
	cout << "Quarters:" << setw(7) << quarter_change << endl;
	cout << "Dimes:" << setw(10) << dime_change << endl;
	cout << "Nickels:" << setw(8) << nickel_change << endl;
	cout << "Pennies:" << setw(8) << pennies_change << endl;

	return 0;

 }
