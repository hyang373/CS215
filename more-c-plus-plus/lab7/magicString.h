/* 
 * File:   magicString.h
 * Course: CS216-00x
 * Project: Lab 7
 * Purpose: provide the declaration of the class named magicString
 *          this class provides a few useful string manipulation.
 */
#ifndef MAGICSTRING_H
#define MAGICSTRING_H

#include <string> 

using namespace std;

const int LEN = 2;

class magicString
{
   public:
    //constructor
    magicString(string ini_string);
    
    // set the current value of str
    void setMagicString(string value);

    // return the value of str
    string getMagicString() const;

    //returns a string which transforms each character of str into lower case
    //note that str has not been changed
    //(algorithm header file is needed for the definition of transform function)
    string toLower() const;

    //return a string which transforms each character of str into upper case
    //note that str has not been changed
    string toUpper() const;
    
    //it removes the extra blank spaces(including tab) from str
    //It defines as:
    //   1. it remains only one space if str contains more than
    //      one continuous blank spaces between two non-space characters
    //      For example, if str is "hello,     world",
    //      it should change into "hello, world"
    //   2. it removes all spaces before the first non-space character
    void removeExtraSpace();

    // return a string which transforms only the first letter of each word in str into upper case letter
    // the word in str is defined as a sequence of characters starting with non-space character and ending right before the next space
    // For example, if str is "charlie brown",
    // it should return "Charlie Brown"
    // note that str has not been changed
    string wordFormat() const;

   private:
    string str;
};

#endif   /* MAGICSTRING_H */
