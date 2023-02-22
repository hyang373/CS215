/* File: term.h
 * Course: CS216-00x
 * Project: Project 2
 * Purpose: the declaration for the Term class.
 *** DO NOT CHANGE THE DECLARATION OF Term CLASS ***
 *
 */
#ifndef TERM_H
#define	TERM_H

#include <string>

using namespace std;

class Term
{
    public:
        // default constructor
        Term();

        // initializes a term with the given query string and weight
        Term(string query, long weight);

        // compares the two terms in descending order by weight
        // if the order of T1 and T2 in descending order by weight, return 1;
        // if T1 and T2 are of the same weight, return 0;
        // otherwise return -1
        static int compareByWeight(Term T1, Term T2);

        // compares the two terms in lexicographic order but using only the first r characters of each query
        static int compareByPrefix(Term T1, Term T2, int r);

        // operator overloading for operators "<" and "<<"
        // they are defined as friend functions

        // define the operator "<" for Term class
        // T1 < T2 if and only if the query of T1 is less than the query of T2 (based on string comparison)
        friend bool operator<(Term T1, Term T2);

        // define the operator "<<" for Term class
        // to send the Term object to the cout, in the following format:
        // the weight, followed by a tab key, followed by the query
        friend ostream& operator<<(ostream &out, const Term& t);

        //assign "friendship" to the class named Autocomplete
        //so that Autocomplete class can directly access the private date members
        //        of Term class. Not the other way around.
        friend class Autocomplete;

    private:
        string query;
        long weight;
};

#endif	/* TERM_H */

