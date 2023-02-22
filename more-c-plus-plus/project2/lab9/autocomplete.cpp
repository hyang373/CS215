/* File: autocomplete.cpp
 * Course: CS216-00x
 * Project: Project 2
 * Purpose: the implementation of member functions for the class named Autocomplete.
 *
 */
#include <iostream>
#include "autocomplete.h"
#include "term.h"

// default constructor
Autocomplete::Autocomplete()
{
    // You can leave it blank
    // since the private data member terms has been initialized through default constructor of SortingList class 
}


// inserts the newterm to the sequence
// note that a SortingList<Term> object, named terms
//          represents the sequence
void Autocomplete::insert(Term newterm)
{
    terms.insert(newterm);
}


// sort all the terms by query in the lexicographical order  
void Autocomplete::sort()
{
    terms.sort();
        
}

// binary search helper function
// as private function
// since it serves binary_search member function only
int Autocomplete::binary_searchHelper(SortingList<Term> terms, string key, int left_index, int right_index)
{
    if(right_index < left_index)
    {
        int KEY_NOT_FOUND = -1;
        return KEY_NOT_FOUND;
    }
    else
    {
        Term keyterm(key, 0);
        int r = key.length();
        int middle = (left_index + right_index) / 2;
        if(Term::compareByPrefix(keyterm,terms[middle],r) > 0)
        {
            return binary_searchHelper(terms, key, left_index, middle - 1);

        }
        else if(Term::compareByPrefix(keyterm,terms[middle],r)  < 0)
        {
            return binary_searchHelper(terms, key, middle + 1, right_index);
        }
        else
        {
            return middle;
        }
    }
}

// return the index number of the term whose query 
// prefix-matches the given prefix, using binary search algorithm
// Note that binary search can only be applied to sorted sequence
// Note that you may want a binary search helper function
int Autocomplete::binary_search(string prefix)
{
    // this function is finding one name(any name) in the SortingLIst<Term> that matches the string prefix
    terms.sort();
    int left_index = 0;
    int right_index = terms.size() - 1;
    return binary_searchHelper(terms, prefix, left_index, right_index);
}

// first: the index of the first query whose prefix matches
//          the search key, or -1 if no such key
// last: the index of the last query whose prefix matches 
//         the search key, or -1 if no such key
// key: the given prefix to match
// hints: you can call binary_search() first to find one matched index number,
//        say hit, then look up and down from hit, to find first and last respectively
void Autocomplete::search(string key, int& firstIndex, int& lastIndex)
{
    // this function takes the location of binary_search() 
    int foundIndex = binary_search(key);
    if(foundIndex == -1){
        firstIndex = -1;
        lastIndex = -1;
        return;
    }
    // - search all matchs before that location that also matchs the prefix
    int r = key.length();
    int tryingFirst = foundIndex;
    while(tryingFirst >= 0 && Term::compareByPrefix(terms[tryingFirst],terms[foundIndex], r) == 0){
        tryingFirst--;
    }
    firstIndex = tryingFirst + 1;
    // - search all matchs after that location
    tryingFirst = foundIndex;
    while(tryingFirst < terms.size() && Term::compareByPrefix(terms[tryingFirst],terms[foundIndex],r) == 0){
        tryingFirst++;
    }
    lastIndex = tryingFirst - 1;
    
}

// returns all terms that start with the given prefix, in descending order of weight
SortingList<Term> Autocomplete::allMatches(string prefix)
{
    SortingList<Term> matches;
    int first = 0;
    int last = terms.size() - 1;
    search(prefix, first, last);
    if(first == -1 || last == -1){
        return matches;
    }
    else{
        for(int i = first; i <= last; i++){
            matches.insert(terms[i]);
        }
    }
    matches.bubble_sort(Term::compareByWeight);
    return matches;
}

void Autocomplete::print()
{
    terms.print(); 
}
