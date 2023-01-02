/*
Lab 4
Class: CS 215-001
Author: Helen Yang
Purpose: performs a Credit Card NUmber check
*/

#include <iostream>
using namespace std;

int main(){

    cout << "Please enter the 8-digit credit card number (enter -1 to quit) : ";
    
    int cc_num;
    cin >> cc_num;

    while (cc_num != -1)
    {
       

        // sum of every other number starting from rightmost digit
        int check_part1 = 0;
        int firstDigit = 0;
        int secondDigit = 0;
        int thirdDigit = 0;
        int fouthDigit = 0;
        int fifthDigit = 0;
        int sixthDigit = 0;
        int seventhDigit= 0;
        int eightDigit = 0;

        const int TEN = 10;
        const int HUNDRED = 100;
        const int THOUSANDS = 1000;
        const int TEN_THOUSANDS = 10000;
        const int HUNDRED_THOUSANDS = 100000;
        const int ONE_MILLION = 1000000;
        const int TEN_MILLION = 10000000;
        const int DOUBLE = 2;

        eightDigit = cc_num % TEN;               // to find digit in the ones place by finding the reminder of tenth place
        seventhDigit = cc_num / TEN % TEN;        // to find digit in the tens place by finding the reminder of hundredth place
        sixthDigit = cc_num / HUNDRED % TEN;         // to find digit in the hundreds place by finding the reminder of thousands place
        fifthDigit = cc_num / THOUSANDS % TEN;        // to find digit in the thousands place by finding the reminder of ten thousands place
        fouthDigit = cc_num / TEN_THOUSANDS % TEN;       // to find digit in the ten thousands place by finding the reminder of hundred thoudands place
        thirdDigit = cc_num / HUNDRED_THOUSANDS % TEN;      // to find digit in the hundred thoudands place by finding the reminder of one millionths place
        secondDigit = cc_num / ONE_MILLION % TEN;    // to find digit in the one millionths place by finding the reminder of ten millionths place
        firstDigit = cc_num / 10000000 % TEN;    // to find digit in the ten millionth place by finding the reminder of hundredth millionths place
    
        check_part1 = eightDigit + sixthDigit + fouthDigit+ secondDigit;

        // double each of digit -- sum of each indivial digit of sum, every other, start from left most
        int check_part2 = 0;

        firstDigit = firstDigit * DOUBLE;
            int firstDigit_onesPlace = firstDigit % TEN;      // to find digit in the ones place by finding the reminder of tenth place
            int firstDigit_tensPlace = firstDigit / TEN % TEN;   // to find digit in the tens place by finding the reminder of hundredth place
    
        thirdDigit = thirdDigit * DOUBLE;
            int thirdDigit_onesPlace = thirdDigit % TEN;       // to find digit in the ones place by finding the reminder of tenth place
            int thirdDigit_tensPlace = thirdDigit / TEN % TEN;     // to find digit in the tens place by finding the reminder of hundredth place

        fifthDigit = fifthDigit * DOUBLE;
            int fifthDigit_onesPlace = fifthDigit % TEN;       // to find digit in the ones place by finding the reminder of tenth place
            int fifthDigit_tensPlace = fifthDigit / TEN % TEN;    // to find digit in the tens place by finding the reminder of hundredth place

        seventhDigit = seventhDigit * DOUBLE;
            int seventhDigit_onesPlace = seventhDigit % TEN;   // to find digit in the ones place by finding the reminder of tenth place
            int seventhDigit_tensPlace = seventhDigit / TEN % TEN;   // to find digit in the tens place by finding the reminder of hundredth place

        check_part2 = firstDigit_onesPlace + firstDigit_tensPlace + thirdDigit_onesPlace + thirdDigit_tensPlace + fifthDigit_onesPlace + fifthDigit_tensPlace + seventhDigit_onesPlace + seventhDigit_tensPlace;

        int check_total = check_part1 + check_part2;

        if (check_total % 10 == 0)
        {
            cout << "Number is valid." << endl;
        }
        else
        {
            cout << "Number is invalid." << endl;

            // make sure the last digit is back to the original value
            eightDigit = cc_num % TEN; // to find digit in the ones place by finding the reminder of tenth place

            while (check_total % 10 != 0)
            {
                
                eightDigit++;
                check_total++;

            }

            if (eightDigit >= 10)
            {
                eightDigit = eightDigit - 10;   // make sure the eight digit stay within range 0-9
            }
            

            cout << "Check digit should have been "<< eightDigit << endl;

        }
        cout << "Please enter the 8-digit credit card number (enter -1 to quit) : ";
        cin >> cc_num;
        
    }

    if (cc_num == -1)
    {
        cout << "Thank you for using \"Credit Card Number Validation\"! " << endl;
    }

    return 0;
}