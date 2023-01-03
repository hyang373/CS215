
/* File: Card.h
 * Course: CS215-00x
 * Project: Project 3
 * Purpose: the declaration for the Card class.
 *** DO NOT CHANGE THIS FILE ***
 *
 */

#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

// define the unicode for four suits for display purpose
const char SPADE[] = "\x03";
const char CLUB[] = "\x04";
const char HEART[] = "\x05";
const char DIAMOND[] = "\x06";

class Card
{
public:
    // Default constructor.
    // We allow uninitialized Cards to be created.
    // This allows arrays of Cards.
    // Uninitialized cards should have Invalid for its suit
    // and 0 for its points.
    Card();

    // Alternate constructor
    // Create a Card with specified suit and points.
    Card(char s, int p);

    // access the card point value
    int getPoint() const;

    // access the card suit value
    char getSuit() const;

    // compare with another Card object passed in as parameter: other
    // if the object your are working on has higher point than other, return 1;
    // if the object your are working on has lower point than other, return -1;
    // otherwise, return 0
    int compareTo(Card other) const;

    // Display a description of the Card object to standard output.
    // The output should look like:
    //   the sign of suit, followed by the point, then followed by the sign of suit again
    void print() const;

private:
    char suit;    // suit of the card: I--Invalid, S--Spade, C--Club, H--Heart, D--Diamond
    int point;    // point value of the card, in the range of [2, 14]  J--11; Q--12; k--13 and A--14
    // For the suit of a playing card:
    // I means Invalid, which represents the Card object has not been initialized.
    // S represents Spade; C represents Club; H represents Heart and D represents Diamond

    // For the point value of a playing card:
    // A point value of 0 means the Card object has not been initialized.
    // J = 11, Q = 12, K = 13, A = 14.
    // A point value of 1 is not used.
};
#endif  /* CARD_H */
