/*
 * Course: CS216-00x
 * Project: Lab 7 sub-problem
 * Purpose: testing one member function named magicString::wordFormat()
 * Author: Yi Pike
 * ### Please Do Not Change This File. ###
 */
#include <iostream>
#include "magicString.h"

using namespace std;

int main()
{
    string to_test = "  hi,     yI l pIKe :)   ";
    magicString magic(to_test);

    cout << to_test << endl;
    cout << magic.wordFormat() << endl;

    return 0;
}


