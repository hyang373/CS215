/* File: term.cpp
 * Course: CS216-00x
 * Project: Project 2
 * Purpose: the implementation of member functions for the Term class.
 *
 */
#include <iostream>
#include "term.h"

// default constructor
Term::Term()
{
    this->query = "";
    this->weight = 0;
}

// initializes a term with the given query string and weight
Term::Term(string query, long weight)
{
    this->query = query;
    if (weight >= 0){
        this->weight = weight;
    }
    else{
        cout << "Invalid Input." << endl;
        this->weight = 0;
    }

}

// compares the two terms in descending order by weight
// if the order of T1 and T2 in descending order by weight, return 1;
// if T1 and T2 are of the same weight, return 0;
// otherwise return -1
int Term::compareByWeight(Term T1, Term T2)
{
    //compare T1 and T2
    if(T1.weight == T2.weight){
        return 0;
    }
    else if (T1.weight > T2.weight){
        return 1;
    }
    else{
        return -1;
    }
}

// compares the two terms in lexicographic order but using only the first r characters of each query
int Term::compareByPrefix(Term T1, Term T2, int r)
{
    if (r < 0)
    {
        cout << "The length of the prefix should be a positive number!" << endl;
        return 2;
    }    
    string T1_prefix = (T1.query).substr(0,r);
    string T2_prefix = (T2.query).substr(0,r);

    if (T1_prefix < T2_prefix)
        return 1;
    if (T1_prefix == T2_prefix)
        return 0;
    else
        return -1;
}

// operator overloading for operators "<" and "<<"
// they both are defined as friend functions

// define the operator "<" for Term class
// T1 < T2 if and only if the query of T1 is less than the query of T2 (based on string comparison)
bool operator<(Term T1, Term T2)
{
    if(T1.query < T2.query){
        // T1 < T2
        return true;
    }
    else{
        return false;
    }
}

// define the operator "<<" for Term class
// to send the Term object to the cout, in the following format:
// the weight, followed by a tab key, followed by the query
ostream& operator<<(ostream &out, const Term& t)
{
    out << t.weight << "\t" << t.query;
    return out;
}
