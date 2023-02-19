/*
 Lab 5
 Author : Helen Yang
 Purpose : to create a program that would add up all of the positive integer values of userinput
    and tell user if the number is a power of 2 minus 1 or not
 Class : CS 215-001
*/

#include <iostream>
#include <string>
#include <math.h>
#include <limits>
using namespace std;

int main() 
{
    int user_Input;
    int posNum;
    int sum = 0;    
    int powerTest = 1;

    // used to find power of 2
    const int TWO = 2;      

    cout << "Please enter a series of positive numbers, then type (Q or q) to process: ";
    cin >> user_Input;

    // while the user input is not a number value, check if input is "Q" or "q" to teminate program
    // otherwise also for a valid input
    while (cin.fail())
    {
        cin.clear();                       // clear bad input (values that are not integers)
        string check_Input;                // turn user Input into a string
        cin >> check_Input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //check if input is 'q' or 'Q'
        // if is -- show sum of all user input and terminate program
        // else -- tell user that input is invalid and ask to input a value again
        if ((check_Input == "Q") || (check_Input == "q"))
        {
            if (sum != 0)
            {
                cout << " " << endl;
                cout << "The sum of all user input is: "<< sum << endl;
            }
            else
            {
                cout << "No input number!" << endl;
            }
            
            cout << "Have a great day!" << endl;

            return 1;
        }
        else
        {
            cout << "Invalid input, please try again..." << endl;
            cout << "Please enter a series of positive numbers, then type (Q or q) to process: ";
            cin >> user_Input;
                
        }
            
    }

    /*infinite program until user tell program to terminate
     check if user input is postive
     if is, add input to cumative sequence and determine if input is a power of 2 minus 1
     else -- ask for a positive number
    */
    while(true)
    {   

        // reset powerTest for every input
        powerTest = 1;

        if (user_Input < 1)
        {
            // clear everything that is after the number input
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Please input a positive integer instead..." << endl;
            cout << "Please enter a series of positive numbers, then type (Q or q) to process: ";
            cin >> user_Input;
        }
        if (user_Input > 0)
        {
            // clear everything that is after the number input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // extract integer from user Input
            posNum = floor(user_Input);

            // add the user inputs together
            sum = posNum + sum;
            cout << "The corresponding element for the cumulative total sequence is : " <<  sum << endl;
            
            // determine if user input is a power of 2 minus 1
            for (int i = 0; powerTest <= posNum; i++)
            {
                powerTest = powerTest * TWO;
            }
            powerTest = powerTest - 1;
            if (powerTest == posNum)
            {
                cout << posNum << " is a Power of Two Minus One!" << endl;
            }
            else
            {
                cout << posNum << " is NOT a Power of Two Minus One!" << endl;
            }

            cout << "Please enter a series of positive numbers, then type (Q or q) to process: ";
            cin >> user_Input;
            
        }

        while (cin.fail())
        {
            cin.clear();                       // clear bad input (values that are not integers)
            string check_Input;                // turn userput into a string
            cin >> check_Input;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if ((check_Input == "Q") || (check_Input == "q"))
            {
                if (sum != 0)
                {
                    cout << " " << endl;
                    cout << "The sum of all user input is: "<< sum << endl;
                }
                else
                {
                    cout << "No input number!" << endl;
                }
                cout << "Have a great day!" << endl;

                return 1;
            }
            else
            {
                cout << "Invalid input, please try again..." << endl;
                cout << "Please enter a series of positive numbers, then type (Q or q) to process: ";
                cin >> user_Input;
                
            }
        }
        

    }    
           
    return 0;

}
