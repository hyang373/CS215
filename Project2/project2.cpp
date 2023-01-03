/*
 Course: CS215-001
 Project: Project 2
 Purpose: to implement the Grade Curve Calculator
    to calculate the average score for CS215 Final grade and curve the scores based on her expected average.  
 Author: Helen Yang
*/

#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include <string>
#include <cmath>        // std::abs   
#include "FinalGrade.h"
#include "FinalGrade.cpp" 
#include "Gradebook.h"
#include "Gradebook.cpp"

using namespace std;

int main()
{
    Gradebook CS215gradebook_original;
    Gradebook CS215gradebook_curved;
    double input_score;
    double original_avg;
    double expected_avg;

    cout << endl;
    cout << endl;

    while(true)
    {
        cout << "Please enter a score for CS215 (type 'Q' or 'q' to quit): " << endl;
        cin >> input_score;

        if (cin.fail())
        {
            cin.clear();                       // clear bad input (values that are not integers)
            string check_Input;                // turn user Input into a string
            cin >> check_Input;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            //check if input is 'q' or 'Q'
            // if is -- terminate while loop and move on to grade curve calculate part 
            // else -- tell user that input is invalid and ask to input a value again
            if ((check_Input == "Q") || (check_Input == "q"))
            {
                break;
            }
            else
            {
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
			CS215gradebook_original.insert(inputFG);
		}

        cin.ignore(256, '\n'); //extra and ignore any possible bad input from the input stream
    }

    // Check if the gradebook is empty
	if (CS215gradebook_original.getSize() == 0)
	{
		cout << "The gradebook for CS215 is empty!" << endl;
        cout << "Thank you for using the Grade Curve Calculator." << endl;
        cout << endl;
		return 1;
	}

    // If Gradebook is not empty.......
    cout << endl;
    cout << endl;

    original_avg = CS215gradebook_original.getAverage();

    while(true)
    {
        cout << "The original average score is: " << fixed << setprecision(2) << original_avg << endl;
        cout << "The Grade Curve Calculator can help you reach your expected average score" << endl;
        cout << "If you are not satisfied with the current average score" << endl;
        cout << "It is written by Helen Yang, who can read your mind:)" << endl;

        cout << "Please enter your expected average score to curve (type 'Q' or 'q' to quit): " << endl;
        cin >> expected_avg;

        if (cin.fail())
        {
            cin.clear();                       // clear bad input (values that are not integers)
            string check_Input;                // turn user Input into a string
            cin >> check_Input;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            //check if input is 'q' or 'Q'
            // if is -- terminate while loop and move on to grade curve calculate part 
            // else -- tell user that input is invalid and ask to input a value again
            if ((check_Input == "Q") || (check_Input == "q"))
            {
                cout << "Thank you for using the Grade Curve Calculator." << endl;
                break;
            }
            else
            {
                cout << "Invalid input, please try again..." << endl;
                cout << endl;
                cout << endl;
                continue;
            }
            
        }

        double difference = expected_avg - CS215gradebook_original.getAverage();
        const double EPSILON = 1.0e-2;

        // check if the input score is in the correct range: [0,100]
		if (expected_avg < original_avg || expected_avg > 100)
		{
			cout << "The expected average is not in the correct range, please try again..." << endl;
            cout << endl;
            cout << endl;
		}
        else if (abs(difference) < EPSILON)
        {
            cout << "The scores are perfect, no need for the grading curve!" << endl;
            cout << endl;
            cout << endl;
            continue;
        }
		else // valid user input, store into gradeList object
		{
			cout << "The original gradebook for CS215: " << endl;
            cout << fixed << setprecision(2);
		    CS215gradebook_original.print();
	        
            // display number of score
            cout << "The number of score is:\t" << CS215gradebook_original.getSize() << endl;
            //display max score
            cout << "The maximum score is:\t";
            CS215gradebook_original.getMax().print();
            // display min score
            cout << "The minimum score is:\t";
            CS215gradebook_original.getMin().print();
            // display original average score
            cout << "The original score is:\t" << original_avg << endl;

            cout << endl;
            cout << endl;

            CS215gradebook_curved = CS215gradebook_original;
            // display user input of expexted average score
            cout << "The expected average score:\t" << expected_avg << endl;
            cout << "The curved gradebook for CS215: " << endl;
            CS215gradebook_curved.incrementScore(difference);
            CS215gradebook_curved.print();
            // display nmber of scores
            cout << "The number of score is:\t" << CS215gradebook_curved.getSize() << endl;
            // display curved maximum score
            cout << "The maximum score is:\t";
            CS215gradebook_curved.getMax().print();
            // display curved minimum score
            cout << "The minimum score is:\t";
            CS215gradebook_curved.getMin().print();
            // display the curved average score
            cout << "The actual average score is:\t" << CS215gradebook_curved.getAverage() << endl;
            cout << endl << endl;
	        
		}

        cin.ignore(256, '\n'); //extra and ignore any possible bad input from the input stream
    
    }

}