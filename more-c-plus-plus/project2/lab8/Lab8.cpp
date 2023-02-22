/*
 * Course: CS216-00x
 * Project: Lab 8 (as first part of Project 2)
 * Purpose: repeatedly ask the user to type prefix to match
 *          then display the matched terms in two orders:
 *          in lexicographic order by query;
 *          in descending order by weight.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "term.h"
#include "TermSortingList.h"

using namespace std;

int main(int argc, char** argv) {
    const int ARGUMENTS = 2;
    
    // check the command line argument, an input file name is needed
    if (argc != ARGUMENTS)
    {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }    
    
    // check if the input file can be opened successfully
    ifstream infile;
    infile.open(argv[1]);
    if (!infile.good())
    {
        cout << "Cannot open the file named " << argv[1] << endl;
        return 2;
    }  
    
    // read in the terms from the input file
    // line by line and store into TermSortingList object
    TermSortingList termList;
    long weight;
    string query;
    
    while (infile >> weight)
    {
        infile >> ws;
        getline(infile, query);
        if (query != "")
        {    
            Term newterm(query, weight);
            termList.insert(newterm);
        }    
    } 

    // close the file stream
    infile.close();

    string prefix;
    cout << "Please input the search query (type \"exit\" to quit): " << endl;
    getline(cin, prefix);
    
    while (prefix != "exit")
    {
        // create a Term object from given prefix, weight is 0
        Term toMatch(prefix, 0);

        // create a SortingList object named matchedTerms to store the prefix-match terms
        TermSortingList matchedTerms;
        // use sequential search (linear search) to find the matched terms
        for (int i = 0; i < termList.size(); i++)
        {
            if (Term::compareByPrefix(termList[i], toMatch, prefix.length()) == 0)
                matchedTerms.insert(termList[i]);
        }
        
        if (matchedTerms.size() == 0)
            cout << "No matched query!" << endl;
        else //found matched terms
        {
            // sort the matched terms in lexicographic order by query
            cout << endl << "The matched terms are in lexicographic order by query: " << endl;
            matchedTerms.sort();
            matchedTerms.print();

            // sort the matched terms in descending order by weight
            cout << endl << "The matched terms are in descending order by weight: " << endl;
            // Use function pointer implicitly
            // by passing in the function name directly
            matchedTerms.selection_sort(Term::compareByWeight);
            /* 
            //another way: use function pointer explicitly by declaring a function pointer
            int (*compare)(Term t1, Term t2);
            compare = &Term::compareByWeight;
            matchedTerms.selection_sort((*compare));
            */
            matchedTerms.print();
        }
        cout << "Please input the search query (type \"exit\" to quit): " << endl;
        getline(cin, prefix);
    }    

    return 0;
}

