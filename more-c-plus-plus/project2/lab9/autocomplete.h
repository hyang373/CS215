/* File: autocomplete.h
 * Course: CS216-00x
 * Project: Project 2
 * Purpose: the declaration for the class named Autocomplete.
 *** DO NOT CHANGE THE DECLARATION OF Autocomplete CLASS ***
 *** BUT YOU ARE ALLOWED TO ADD MEMBER FUNCTIONS IF YOU NEED ***
 *
 */

#ifndef AUTOCOMPLETE_H
#define	AUTOCOMPLETE_H

#include <string>
#include "term.h"
#include "SortingList.h"

using namespace std;

class Autocomplete
{
    public:
        // default constructor
        Autocomplete();

        // inserts the newterm to the sequence
        // note that a SortingList<Term> object, named terms,
        //          represents the sequence
        void insert(Term newterm);

        // sort all the terms by query in lexicographical order
        // note that this function needs to be called before applying binary search
        void sort();

        // return the index number of the term whose query 
        // prefix-matches the given prefix, using binary search algorithm
        // Note that binary search can only be applied to sorted sequence
        // Note that you may want a binary search helper function
        int binary_search(string prefix);

        // first: the index of the first query whose prefix matches
        //          the search key, or -1 if no such key
        // last: the index of the last query whose prefix matches 
        //         the search key, or -1 if no such key
        // key: the given prefix to match
        // hints: you can call binary_search() first to find one matched index number,
        //        say hit, then look up and down from hit, to find first and last respectively
        void search(string key, int& first, int& last);

        // return all terms whose queries match the given prefix, 
        // in descending order by weight
        SortingList<Term> allMatches(string prefix);

        // display all the terms in the sequence
        void print();

    private:
        SortingList<Term> terms;

        // binary search helper function
        // as private function
        // since it serves binary_search member function only
        int binary_searchHelper(SortingList<Term> terms, string key, int left_index, int right_index);
};

#endif	/* AUTOCOMPLETE_H */

