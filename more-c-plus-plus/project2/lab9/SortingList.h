/* File: SortingList.h
 * Course: CS216-00x
 * Project: Project 2
 * Purpose: the declaration for the SortingList class.
 *          it stores a sequence of objects to perform sorting operation
 *          it is a template class
 *** DO NOT CHANGE THE DECLARATION OF SortingList CLASS ***
 *
 */

#ifndef SORTINGLIST_H
#define	SORTINGLIST_H

#include <vector>
#include <string>

using namespace std;

template <typename T>
class SortingList
{
   public:
    // inserts the newitem to the end of the current vector   
    void insert(T newitem);

    // return how many items in the list
    int size() const;

    // operator overloading for "[]"
    // provide the direct access by index number
    T& operator[](int index);

    // sort all items in ascending order 
    // the items are compared using operator "<"
    // using sort() from standard library
    void sort();

    // provide different sorting algorithms 
    // based on comparison defined by the function passing in as parameter
    
    // apply selection sorting algorithm
    void selection_sort(int (*compare)(T t1, T t2));

    // apply bubble sorting algorithm
    // pass in function name as the parameter
    // where function defines the comparison between two terms
    void bubble_sort(int (*compare)(T T1, T T2));

    // apply merge sorting algorithm
    void merge_sort(int (*compare)(T t1, T t2));

    // apply shuffle algorithm
    void shuffle();

    // display all the items in the sequence
    void print() const;
    
   private:
    vector<T> items;

    // helper functions
    void merge(int first, int mid, int last, int (*compare)(T t1, T t2));
    void merge_sortHelper(int min, int max, int (*compare)(T t1, T t2));
};


#endif	/* SORTINGLIST_H */

#include "SortingList.cpp"
