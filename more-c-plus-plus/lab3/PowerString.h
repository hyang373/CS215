/* 
 * File:   PowerString.h
 * Purpose: provide the declaration of the PowerString class
 *
 * Author: Pike
 ******PLEASE DO NOT CHANGE THIS FILE!******
 *
 */

#ifndef POWERSTRING_H
#define	POWERSTRING_H

#include <string>

using namespace std;

class PowerString
{
    public:
        // constructor: initialize str with ini_str passing as a parameter
        PowerString(string ini_str);

        // return the current value of the private data member: str
        string getString() const;

        // set the value of str to be the passed in parameter input_str
        void setString(string input_str);

        // return a reverse string
        // using a loop to implement
        // Note that the private data member named str, has not been changed
        string rev_loop() const;

        // return a reverse string
        // using recursion to implement
        // Note that the private data member named str, has not been changed
        string rev_recursion() const;

        // return a reverse string
        // using a stack to implement
        // Note that the private data member named str, has not been changed
        string rev_stack() const;

        // return true if str is a palindrome
        // otherwise return false
        // A palindrome is defined as a sequence of characters which reads the same backward as forward
        // calling member function to  implement
        // Note that the private data member named str, has not been changed
        bool isPalindrome() const;
        
        // return true if str is a palindrome
        // otherwise return false
        // A palindrome is defined as a sequence of characters which reads the same backward as forward
        // using recursion to implement
        // Note that the private data member named str, has not been changed
        bool isPalindrome_recursion() const;
        
        // displays str, followed by a new line marker, 
        // to the standard output
        void print() const;

    private:
        string str;
};

#endif	/* POWERSTRING_H */
