/* File: TermSortingList.h
 * Course: CS216-00x
 * Project: Project 2
 * Purpose: the declaration for the TermSortingList class.
 *          it stores a sequence of Term objects to perform sorting operation
 *** DO NOT CHANGE THE DECLARATION OF TermSortingList CLASS ***
 *
 */

#ifndef TERMSORTINGLIST_H
#define	TERMSORTINGLIST_H

#include <vector>
#include <string>
#include "term.h"

using namespace std;

class TermSortingList
{
   public:
    // inserts the newitem to the end of the current vector   
    void insert(Term newitem);

    // return how many items in the list
    int size() const;

    // operator overloading for "[]"
    // provide the direct access by index number
    Term& operator[](int index);

    // sort all items in ascending order 
    // the items are compared using operator "<"
    // using sort() from standard library
    void sort();

    // provide different sorting algorithms 
    // based on comparison defined by the function passing in as parameter
    
    // apply selection sorting algorithm
    void selection_sort(int (*compare)(Term t1, Term t2));

    // apply bubble sorting algorithm
    // pass in function name as the parameter
    // where function defines the comparison between two terms
    void bubble_sort(int (*compare)(Term T1, Term T2));

    // apply merge sorting algorithm
    void merge_sort(int (*compare)(Term t1, Term t2));

    // apply shuffle algorithm
    void shuffle();

    // display all the items in the sequence
    void print() const;
    
   private:
    vector<Term> items;

    // helper functions
    void merge(int first, int mid, int last, int (*compare)(Term t1, Term t2));
    void merge_sortHelper(int min, int max, int (*compare)(Term t1, Term t2));
};

#endif	/* TERMSORTINGLIST_H */

