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
	double amount_due = 0.0;		// Declare a variable to store the total cost of purchase
	double amount_received = 0.0;	// Declare a variable to store the amount received for payment

		cout << "Enter the amount due : $  ";
		cin >> amount_due;
		cout << "Enter the amount received : $  ";
		cin >> amount_received;
		
		double change = amount_received - amount_due;	//declare a variable to store the total change the cashier needs to give back
		cout << "The change is: " << endl;
		const int DOLLAR_VALUE = 1;						//declare a constant: dollar = $1
		const double QUARTER_VALUE = 0.25;				//declare a constant: quarter = $0.25
		const double DIME_VALUE = 0.10;					//declare a constant: dime = $0.10
		const double NICKEL_VALUE = 0.05;				//declare a constant: nickel = $0.05
		const double PENNY_VALUE = 0.01;				//declare a constant: penny = $0.01
		const double ROUND_OFF = 0.005;					//declare a constant: round off value (make sure pennies round up)
		int dollar_change = change / DOLLAR_VALUE;			//declare a variable: change of dollars
		int quarter_change = (change - dollar_change) / QUARTER_VALUE;			//declare a variable: change of quarter needed
		int dime_change = (change - dollar_change - quarter_change * QUARTER_VALUE)/ DIME_VALUE;		//declare a variable: change of dimes needed
		int nickel_change = (change - dollar_change - quarter_change * QUARTER_VALUE - dime_change * DIME_VALUE) / NICKEL_VALUE;		//declare a variable: change of nickels needed
		int penny_change = ((change - dollar_change - quarter_change * QUARTER_VALUE - dime_change * DIME_VALUE - nickel_change * NICKEL_VALUE) / PENNY_VALUE) + ROUND_OFF;		//declare a variable: change of pennies needed
		cout << "Dollars:" << setw(8) << dollar_change << endl;
		cout << "Quarters:" << setw(7) << quarter_change << endl;
		cout << "Dimes:" << setw(10) << dime_change << endl;
		cout << "Nickels:" << setw(8) << nickel_change << endl;
		cout << "Pennies:" << setw(8) << penny_change << endl;

		return 0;

 }