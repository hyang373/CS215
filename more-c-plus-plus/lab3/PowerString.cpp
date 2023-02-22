/* 
 * File:   PowerString.cpp
 * Purpose: provide the definition of the PowerString class
 *
 * Author: Helen Uang
 *
 */
#include <iostream>
#include <stack>
#include <string>
#include "PowerString.h"

// initialize str with ini_str passing as a parameter
PowerString::PowerString(string ini_str)
{
	// set ini_str to the variable str
	str = ini_str;
}

// return the current value of the private data member: str
string PowerString::getString() const
{
	// return the value of string
	return str;
}

// set the value of str to be the passed in parameter input_str
void PowerString::setString(string input_str)
{
	// set str to equal input_str
	str = input_str;
}

// return a reverse string
// using a loop to implement
// Note that the private data member named str, has not been changed
string PowerString::rev_loop() const
{
	string rev_str = "";		// initize a new string variable named rev_str
	// using a for loop, add the i character of the string to the rev_str string
	for (int i = str.length() - 1;i >= 0;i = i - 1){
		rev_str = rev_str + str[i];
	}
	return rev_str;
}

// return a reverse string
// using recursion to implement
// Note that the private data member named str, has not been changed
string PowerString::rev_recursion() const
{
    size_t numChar = str.length();

    // base case
    if (numChar  == 1){
        return str.substr(0,1);
    }
    else{
        // recursive case
        PowerString string = PowerString(str.substr(0, numChar - 1));
        return str[numChar - 1] + string.rev_recursion();

    }

}

// return a reverse string
// using a stack to implement
// Note that the private data member named str, has not been changed
string PowerString::rev_stack() const
{
	stack<char> rev_str;	// initize stact
	string reversed_string = str;

	// given the first in last out structure of stack,
	// start adding the characters of the string into the stack from start to end of string
	for (int i = 0; i < str.length(); i++){
		rev_str.push(str[i]);
	}
	// starting from the top of the stack (the end of the string)
	// print the top value and remove it from stack
	for (int i = 0; i < str.length(); i++){
		reversed_string[i] = rev_str.top();;
		rev_str.pop();
	}
    return reversed_string;
}

// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// calling member function to  implement
// Note that the private data member named str, has not been changed
bool PowerString::isPalindrome() const
{
	// set initized rev_str to the reverse of that string
	string rev_str = rev_loop();
	
    // compare rev_str with str
    if (rev_str == str)
        return true;
    else
        return false;

}
        
// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// using recursion to implement
// Note that the private data member named str, has not been changed
bool PowerString::isPalindrome_recursion() const
{
    string rev_str = rev_recursion();

    if (rev_str == str)
        return true;
    else
        return false;
}
        
// displays str followed by a new line marker
// to the standard output
void PowerString::print() const
{
	cout << str << endl;	// print string
}
