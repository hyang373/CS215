/*
 Project : Project 1
 Author : Helen Yang
 Date : February 24, 2022
 Purpose : To create a game that allow a player to play against a computer that is in a smart/non-smart mode 
*/


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

const int PILE_MAX = 50;
const int PILE_MIN = 10;
const char MARBLE = static_cast<char>(232);  //use code 232 in ASCII Table to represent marble
const int WIDTH = 10;   // for layout purpose
const int TWO = 2;  // for the smart move mode number of marbles to take

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


    if (smart)
    {   
        if (powerTest == pile)
        {
            numMarbles_take = (rand() % halfPile) + 1 ;
            pile = pile - numMarbles_take;
        }
        else
        {
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

}

// represent the legal move when it is the player's turn to play the game
void player_play(int& pile)
{
    int player_take;
    int halfPile = pile / 2;

    cout << "Your play....you may take 1 to " << halfPile << " marbles." << endl;
    cout << "You take : ";
    cin >> player_take;

    while (cin.fail())
    {
        cin.clear();                       // clear bad input (values that are not integers)

        // tell user that input is invalid and ask to input a value again
        cout << "Invalid input, please try again..." << endl;
        cout << "Your play....you may take 1 to " << halfPile << " marbles." << endl;
        cout << "You take : ";
        cin >> player_take;       
    }

    if (player_take < 1 || player_take > halfPile)
    {
        // clear everything that is after the number input
        cin.clear();  

        cout << "Ooops, you picked too many or not enough." << endl;
        cout << "Please try again..." << endl;
        cout << "Your play....you may take 1 to " << halfPile << " marbles." << endl;
        cout << "You take : ";
        cin >> player_take;
    }

    if (player_take > 0 && player_take <= halfPile)
    {
        
        //clear everything that is after the number input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // extract integer from user Input
        player_take = floor(player_take);

        cout << "You will take " << player_take << " marbles." << endl;
        pile = pile - player_take;
        if (pile > 1)
        {
            cout << " " << endl;
        }
        
            
    }

    while (cin.fail())
    {
        cin.clear();                       // clear bad input (values that are not integers)

        // tell user that input is invalid and ask to input a value again
        cout << "Invalid input, please try again..." << endl;
        cout << "Your play....you may take 1 to " << halfPile << " marbles." << endl;
        cout << "You take : ";
        cin >> player_take;       
    }


}

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
    cout << "*    Players alternate taking at least one but at   *" << endl;
    cout << "*    most half of the marbles in the pile.          *" << endl;
    cout << "*    The player who takes the last marble loses.    *" << endl;
    cout << "*            It is written by Helen Yang            *" << endl;
    cout << "*           I hope you beat the computer:)          *" << endl;
    cout << "*          No matter what, have a great day.        *" << endl;
    cout << "*****************************************************" << endl;


    srand(time(0));

    int pile = (rand() % (PILE_MAX - PILE_MIN + 1)) + PILE_MIN;     // generate initial value of pile
    int firstplay = rand() % 2;    // computer or human play first?
    bool computerTurn;
    bool playerTurn;
    bool smart;
    int compPlayCount = 0;
    int userPlayCount = 0;

    // randomly select if computer will play smart or non smart
    smart = rand() % 2;

    if (firstplay == 0)
    {
        computerTurn = true;
        playerTurn = false;
        cout << "The computer will play first." << endl;
    }
    else
    {
        playerTurn = true;
        computerTurn = false;
        cout << "You will play first." << endl;
    }

    while (computerTurn == true)
    {
        // demonstrate the computer under smart-move mode
        while(smart == true)
        {
            cout << "The computer will play smart." << endl; 
            while (pile > 1)
            {
                printMarbles(pile);
                int origPile = pile;
                computer_play(pile, smart);
                int afterPile = pile;
                cout << "Computer plays : " << endl;
                int numMarbles = origPile - afterPile;
                cout << "The computer takes " << numMarbles << " marbles." << endl;
                compPlayCount++;

                if (pile > 1)
                {
                    printMarbles (pile);
                    player_play(pile);
                    numMarbles = origPile - afterPile;
                    userPlayCount++;
                }
            }

            if (userPlayCount > compPlayCount) 
            {
                cout << "Computer must take the last marble. You win!" << endl;
            }
            else
            {
                cout << "You must take the last marble. You lose!" << endl;                
            }
            return 0;
        }
    
        while (smart== false)
        {
            // non-smart mode
            cout << "The computer will not play smart." << endl;
            while (pile > 1)
            {
                printMarbles(pile);
                int origPile = pile;
                computer_play(pile, smart);
                int afterPile = pile;
                int numMarbles_take = origPile - afterPile;
                cout << "Computer plays : " << endl;
                cout << "The computer takes " << numMarbles_take << " marbles." << endl;
                compPlayCount++;

                if (pile > 1)
                {
                    printMarbles (pile);
                    player_play(pile);
                    numMarbles_take = origPile - afterPile;
                    userPlayCount++;
                }

            }

            if (compPlayCount < userPlayCount) 
            {
                cout << "Computer must take the last marble. You win!" << endl;
            }
            else
            {
                cout << "You must take the last marble. You lose!" << endl;
            }
            return 0;
        }
    }

    while (playerTurn == true)
    {
        // demonstrate the computer under smart-move mode
        while(smart == true)    
        {
            cout << "The computer will play smart." << endl; 
            while (pile > 1)
            {
                printMarbles (pile);
                player_play(pile);
                userPlayCount++;

                if (pile > 1)
                {
                    printMarbles(pile);
                    int origPile = pile;
                    computer_play(pile, smart);
                    int afterPile = pile;
                    cout << "Computer plays : " << endl;
                    int numMarbles = origPile - afterPile;
                    cout << "The computer takes " << numMarbles << " marbles." << endl;
                    compPlayCount++;
                }
            }

            if (userPlayCount > compPlayCount) 
            {
                cout << "Computer must take the last marble. You win!" << endl;
            }
            else
            {
                cout << "You must take the last marble. You lose!" << endl;                
            }
            return 0;
        }
    
        while (smart== false)
        {
            // non-smart mode
            cout << "The computer will not play smart." << endl;
            while (pile > 1)
            {
                printMarbles (pile);
                player_play(pile);
                userPlayCount++;

                if (pile > 1)
                {
                    printMarbles(pile);
                    int origPile = pile;
                    computer_play(pile, smart);
                    int afterPile = pile;
                    cout << "Computer plays : " << endl;
                    int numMarbles = origPile - afterPile;
                    cout << "The computer takes " << numMarbles << " marbles." << endl;
                    compPlayCount++;
                }
            }

            if (userPlayCount > compPlayCount) 
            {
                cout << "Computer must take the last marble. You win!" << endl;
            }
            else
            {
                cout << "You must take the last marble. You lose!" << endl;                
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
