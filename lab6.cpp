/*
 Project : Lab 6 ( as part of Project 1)
 Author : Helen Yang
 Class : CS 215-001
 Date : February 16, 2022
 Purpose : 
    It focuses on testing the defintion of function named computer_play the computer takes either “smart” move or “non-smart” move, respectively. 
    Under “smart-move” mode, the computer needs to make the following legal move to win the game: 
        take off enough marbles to make the size of the remaining pile a power of two minus one (1, 3, 7, 15, 31 are some examples of the power of two minus 1) 
        if the current pile size is not one of those power of two minus 1. 
        When the current pile size is already a 2’s power – 1, make a random move taking at least one but at most half of the marbles. 
    On the other hand, when the computer is under “non-smart-move” mode, the computer makes a random legal move: taking at least one but at most half of the marbles.  
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int PILE_MAX = 50;
const int PILE_MIN = 10;
const char MARBLE = static_cast<char>(232);  //use code 232 in ASCII Table to represent marble
const int WIDTH = 10;   // for layout purpose
const int TWO = 2;  // for the smart move mode number of marbles to take

/* 
 * Name: computer_play
 * It represents the legal move when it is the computer's turn to play 
 *               computer's legal move is under either smart-move or  
 *               non-smart-move depending on the parameter named smart 
 *@param pile int&: the pile size before its turn and after its turn, call by reference  
 *@param smart bool: representing the computer takes smart move (if true) or non-smart move (if false) 
 *@return: void function 
*/ 
// represent the legal move when it is the computer's turn to play the game
void computer_play(int& pile, bool smart)
{

    // declare an integer variable for the number of mariables to take
    int numMarbles_take;
    int powerTest = 1;
    int powerTest2 = 1; // for if the powerTest value is greater that the pile number
    int halfPile;
    
    halfPile = pile / 2;
    srand(time(0));

    for (int i = 0; powerTest < pile; i++)
    {
        powerTest = powerTest * TWO;
    }
    powerTest = powerTest - 1;
    for (int i = 0; powerTest2 < pile; i++)
    {
        powerTest2 = powerTest2 * 2;
    }
    powerTest2 = powerTest2 / 2;    // to get the value of power of 2 minus 1 below the current value
    powerTest2 = powerTest2 - 1;

    if(pile == 2)
    {
        pile = pile - 1;
        return;
    }


 //******************** Smart Mode ****************//
    if (smart)
    {
        // if the current pile size is not one of those power of two minus 1....
        // take off enough marbles to make the size of the remaining pile a power of two minus one 

        //When the current pile size is already a power of two minus one, ....
        //make a random move taking at least one but at most half of the marbles.
        

        if (powerTest == pile)
        {
            numMarbles_take = (rand() % halfPile) + 1 ;
            pile = pile - numMarbles_take;
        }
        else
        {
            // to make the number of marbles to take to a power of two minus 1
            // find the closest power of two minus 1 number below current # to take
            // declare a another integers difference btn num n power of 2 - 1)
            // change current number of marbles to take to the power of 2 - 1 number

            if (powerTest < pile)
            {
                pile = powerTest;
            }
            else
            {
                pile = powerTest2;
            }
           
        }

    }
    else
    {
        int i = 0;
        while(i < pile)
        {
            numMarbles_take = ((rand() % halfPile) + 1);
            i++;
        }
        pile = pile - numMarbles_take;
    }
    
 //*******************************************///


}

/*
 * It displays the marbles on the pile: the number of marbles depends on passing in parameter
 *@param pile int: representing how many marbles are on the pile to display
 *@return: void function
 */
// display marbles on the pile
void printMarbles(int pile)
{
    cout << endl << "There are " << pile << " marbles in the pile." << endl;
    for (int i = 0; i < pile; i++)
    {
        cout << setw(WIDTH) << MARBLE << endl;
    }
}


int main()
{
    cout << "*****************************************************" << endl;
    cout << "*                 The game of Nim                   *" << endl;
    cout << "*    It demostrates two examples of the computer    *" << endl;
    cout << "*    under smart-move or non-smart-move mode        *" << endl;
    cout << "*****************************************************" << endl;

    // "hard-code" pile size for testing purpose
    // Testing case 1: the computer plays under smart-move mode:
    int pile = 20;
    // demonstrate the computer under smart-move mode
    bool smart = true;
    cout << "Testing case 1: " << endl;
    cout << "The computer will play smart." << endl;

    //use playCount to "fake" taking a turn between the computer and the player
    //after the loop, if playCount is even, it means it is computer's turn to take the last marble
    //                if playCount is odd, it means it is the player's turn to take the last marble
    int playCount = 0;  
    while (pile > 1)
    {
        printMarbles(pile);
        int origPile = pile;
        computer_play(pile, smart);
        int afterPile = pile;
        cout << "Computer plays : " << endl;
        int numMarbles = origPile - afterPile;
        cout << "The computer takes " << numMarbles << " marbles." << endl;
        playCount++;
    }

    
    if (playCount % 2 == 0) 
    {
        cout << "The computer takes the last marble!" << endl;
    }
    else
    {
        cout << "The computer leaves the last marble for you:)" << endl;
    }
    

    // Testing case 2: the computer plays under non-smart-move mode:
    pile = 5;
    // demonstrate the computer under non-smart-move mode
    smart = false;
    cout << endl << endl << "Testing case 2: " << endl;
    cout << "The computer will not play smart." << endl;

    playCount = 0;   // reset playCount back to 0
    while (pile > 1)
    {
        printMarbles(pile);
        int origPile = pile;
        computer_play(pile, smart);
        int afterPile = pile;
        int numMarbles_take = origPile - afterPile;
        cout << "Computer plays : " << endl;
        cout << "The computer takes " << numMarbles_take << " marbles." << endl;
        playCount++;
    }

    if (playCount % 2 == 0 )
    {
        cout << "The computer takes the last marble!" << endl;
    }
    else
    {
        cout << "The computer leaves the last marble for you:)" << endl;
    }

    return 0;
}


