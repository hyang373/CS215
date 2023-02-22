/* 
 * File:   magicString.cpp
 * Course: CS216-00x
 * Project: Lab 7
 * Purpose: provide the implementation of member functions of magicString class
 */
#include <iostream> 
#include <algorithm>
#include "magicString.h"

using namespace std;

//constructor
magicString::magicString(string ini_string)
{
    this->str = ini_string;
}

// set the current value of str
void magicString::setMagicString(string value)
{
    this->str = value;
}

// return the value of str
string magicString::getMagicString() const
{
    return this->str;
}

//returns a string which transforms each character of str into lower case
//note that str has not been changed
//(algorithm header file is needed for the definition of transform function)
string magicString::toLower() const
{
    string result = this->str;
    transform(this->str.begin(), this->str.end(), result.begin(), ::tolower);
    return result;
}

//returns a string which transforms each character of str into upper case
// use recursive function to implement
//note that str has not been changed
string magicString::toUpper() const
{
    static int fcount = 0; // use a static variable to count the function calling
    fcount++;   // increase count by one while calling the function
    cout << "Calling the recursive function named " << __func__ << " : " << fcount  << " times." << endl;   // note that __func__ is macro for the funciton name, it may be different for different compiler
    // Base case:
    if (this->str.length() == 0)
        return this->str;
    // Recursive case:
    string first = this->str.substr(0,1);
    const char* front = first.c_str();
    char upperFront[LEN];
    string result;
    upperFront[0] = toupper(front[0]);
    upperFront[1] = '\0';
    result = upperFront;
    magicString part(this->str.substr(1, this->str.length()-1));
    return result + part.toUpper();
}

//it remove the extra blank spaces(including tab) from str
//It defines as:
//   1. it remains only one space if str contains more than
//      one continuous blank spaces between two non-space characters
//      For example, if str is "hello,     world",
//      it should change into "hello, world"
//   2. it removes all spaces before the first non-space character
void magicString::removeExtraSpace()
{
    // your code should start here...
    string original = this->str;
    string new_string;

    replace(original.begin(), original.end(), '\t', ' ');
    
    for(int i = 0; i < original.length();i++){
        // check if character is whitespace
        if(original[i] == ' '){
            // if at beginning or end, skip
            if( (i == 0) || (i == original.length() - 1)){
                continue;
            }
            // skip if there is a space after a space consecutively
            else if(original[i+1] == ' '){
                continue;
            }
            else{
                new_string.push_back(original[i]);
        
            }
        }
        else{
            new_string.push_back(original[i]);
        }
    }

    // check if there is any more space in front of thstring
    while(new_string[0]==' '){
        new_string = new_string.substr(1,new_string.length()-1);
    }
    this->str = new_string;

}

// return a string which transforms only the first letter of each word in str into upper case letter
// the word in str is defined as a sequence of characters starting with non-space character and ending right before the next space
// note that str has not been changed
string magicString::wordFormat() const
{
    string result = this->str;
    // before the wordFormat transformation
    // make sure (1)the extra space(s) has been removed from str; 
    //           (2)apply to all lower case letters of str
    // your code should start here...
    
    // change result into a magicString variable in order to use its fucntions
    magicString new_str = magicString(result);
    new_str.removeExtraSpace();
    new_str = new_str.toLower();

    
    result = new_str.getMagicString();
    
    // find a space, capitalize the next letter
    for(int i = 0; i < result.length(); i++){
        if(result[i] ==' '){
            result[i+1] = toupper(result[i+1]);
        }
        else if(i == 0)
            result[i] = toupper(result[0]);
    }
    return result;
    
}
