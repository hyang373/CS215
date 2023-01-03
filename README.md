# CS215 Introduction to Program Design, Abstraction, and Problem Solving
### Assignments / Projects in C++

## Lab 1

**The purpose of this lab assignment is** :
 - to get familiar with Microsoft Visual Studio IDE 
 - to compile and run your first C++ program
 - follow Coding Style Guide criteria when writing code 
 - implement simple input and output code 
 - test behavior of the code 
 
## Lab 2

**The purpose of this lab assignment is** :
 - to get familiar with Microsoft Visual Studio IDE
 - to practice using input/output
 - to practice using variables, constants, fundamental data types and basic operations.
 
**Goal**: <br>
Write a program that directs a cashier how to give change. The program has two inputs: the amount due and the amount received from the customer (expressed in dollars). Display the dollars, dimes, nickels, and pennies that the customer should receive in return.

## Lab 3

**The purpose of this lab assignment is** :
 - to get familiar with Microsoft Visual Studio IDE
 - to continue practicing using input/output
 - to continue practicing using variables, constants, fundamental data types and basic operations
 - to practice using conditional statement.

**Prompt** : <br>
Students plan to rent some vehicles to drive from location A to location B. Suppose 
there are several choices for them:
 - A bus allows 56 passengers
 - A van allows 13 passengers
 - A SUV allows 7 passengers
 - A sedan allows 3 passengers. 
 
The restriction is that each vehicle must be used as full capacity as possible, in order 
to minimize the total number of vehicles to rent. If there is only one passenger, for 
example, we rent a sedan instead of other larger size vehicles. We also know that there 
are at maximum 4 buses and at maximum 5 vans available on that day, and no limited 
number for either SUVs or sedans.

Write a program to read the total number of students (as passengers), and determine the minimum number of vehicles they need to rent. For example, if there are 97 students, they need one bus, three vans, zero suv and one sedan. Your program should print the number of each type of vehicle needed, neatly formatted as shown in the sample output. However if the number of specified type of vehicle needed is zero, its name should not display. 

## Lab 4

**The purpose of this lab assignment is** :
 - to continue practicing conditional statements
 - to practice loop statements
 - to get familiar with Visual Studio Debugger
 
**Prompt** : <br>
Write a program that performs Credit Card Number Check. Your program should repeatedly ask the user to input an 8-digit number to check if it is valid, until the user enters -1 to quit. (Please note that for simplicity, now you can assume the user will always enter 8-digit numbers to check except for quitting the program with -1. Later we will learn how to handle the user input validation). 

**The program will implement the following algorithm** : <br> 
The last digit of a credit card number is the check digit, which protects against transactions errors such as an error in a single digit or switching two digits. The following method is for numbers with 8 digits:
 - Starting from the rightmost digit, form the sum of every other digit. For example, if the credit card number is 43589795. Then you form the sum 5 + 7 + 8 + 3 = 23
 - Double each of the digits, which were not included in the preceding step. Add all digits of the resulting numbers. For example, with the number given above, doubling the digits, starting with the next-to-last one, yields 18 18 10 8. Adding all digits in these values yields 1 + 8 + 1 + 8 + 1 + 0 + 8 = 27.
 - Add the sums of the two preceding steps. If the last digit of the result is 0, the number is valid. In our case, 23 + 27 = 50, so the number is valid. 

After the user supplies an 8-digit number, your program should implement the above algorithm, then print out whether the number is a valid credit card number or not. If it is not valid, you should print out the value of the check digit that would make the number valid.

## Lab 5

**The purpose of this lab assignment is** : <br>
 - to continue practicing conditional statements
 - to continue practicing loop statements
 - to validate the user input 

**Prompt** : <br>
Write a program that repeatedly reads a sequence of Positive integers from the user as inputs, until the user clicks “Q” or “q” to quit the problem. Each time after the user inputs a valid positive integer, it then prints:
 - The corresponding item in the cumulative total sequence. For example, if the user input sequence is 1 7 9 -4 5, its cumulative total sequence is 1 8 17 13 18 . When the user  first types 1, its corresponding item in the cumulative total sequence is 1; then the user types 7, its corresponding item is 8 (it is equal to 1+7); the user then types 9, its corresponding item is 17 (it is equal to 1+7+9); and so on
 - Whether the valid user input number is “a Power of Two Minus One”. “A power of Two Minus One” is a number which is equal to a power of two minus one, such as 1, 3, 7, 15, 31, 63, 127, ... and so on.

After finishing collecting user input, it prints the sum of all valid user input numbers. 
Then quit the program.

## Project 1 / Lab 6

In a game named Nim, two players alternately take marbles from a pile. In each turn, a player must make a legal move taking at least one but at most half of the marbles from the pile and then let the other player take a turn.  The player who is to take the last marble loses the game. 

You will write a C++ program that enables the computer to play against a human opponent. 
 - First, your program should generate a random integer between PILE_MIN and PILE_MAX to denote the initial pile size. 
 - Second,  your  program  should  generate  0  or  1  randomly  to  decide  which  player  (the computer or the user) takes the first turn.
 - Third, your program should again generate 0 or 1 randomly to decide that  the computer takes  either  “smart”  move  or  “non-smart”  move.
   - Under  “smart-move”  mode,  the computer  needs  to  make  the  following  legal  move  to win  the  game:  take  off  enough marbles to make the size of the remaining pile a power of two minus one (1, 3, 7, 15, 31 are some examples of the power of two minus 1) if the current pile size is not one of those power  of  two  minus  1.  When  the  current  pile  size  is  already a 2’s power –  1, make a random move taking at least one but at most half of the marbles.
   - On the other hand, when the  computer  is  under “non-smart-move” mode,  the  computer makes  a  random  legal move: taking at least one but at most half of the marbles. When human takes his/her turn, your program should ask how many marbles the user wants to remove and then collect the user input. If the user input is not valid, you program should repeatedly ask the user to enter how  many  marbles  the  user  wants  to  remove  from  the  pile  until  the  user  makes  a  legal move.
 - After each legal move either from the computer or the human player, your program should display the number of marbles on current pile
 - When there is only one marble left on the pile, if it is the computer’s turn, the computer loses the game, otherwise the human player loses the game.  

## Lab 8

**The purpose of this lab assignment** : <br>
 - to understand the concept of class, object, encapsulation, OOP 
 - to practice defining your own class 

**Prompt** : <br>
In this Lab assignment, you will help Professor P to implement a Gradebook Report, which allows Professor P enter Final scores for CS215 students, then displays each score and its corresponding letter grade, calculate the average score, and find the highest score and lowest score.

## Lab 9
## Lab 10
## Lab 11
