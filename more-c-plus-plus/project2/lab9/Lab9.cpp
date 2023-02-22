/*
 * Course: CS216-00x
 * Project: Lab 9 (as second part of Project 2)
 * Purpose: repeatedly ask the user to type prefix to match
 *          and generate all the prefix-matched terms 
 *          then display the prefix-matched terms in descending order by weight.
 ***** PLEASE DO NOT CHANGE THIS FILE *****
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include "term.h"
#include "SortingList.h"
#include "autocomplete.h"

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
    // line by line and store into Autocomplete object
    Autocomplete autocomplete;
    long weight;
    string query;
    
    while (!infile.eof())
    {
        infile >> weight >> ws;
        getline(infile, query);
        if (query != "")
        {    
            Term newterm(query, weight);
            autocomplete.insert(newterm);
        }    
    } 

    // read the time clock 
    // before calling sort() function and after it
    // to measure the time spent for sorting operation
    clock_t tstart, tstop;
    tstart = clock();
    autocomplete.sort();
    tstop = clock();
    double  elapsed = (double)(tstop-tstart)/CLOCKS_PER_SEC;
    cout << "Time for sorting all terms: "<<  elapsed << " seconds." << endl;
    
    string input;
    string prefix;
    cout << "Please input the search query (type \"exit\" to quit): " << endl;
    getline(cin, input);
    prefix = input;
    while (prefix != "exit")
    {
        // measure the time spent for searching one prefix-matched term
	    clock_t tstart, tstop;
    	tstart = clock();
        SortingList<Term> matchedTerms = autocomplete.allMatches(prefix);
        tstop = clock();
        double  elapsed = (double)(tstop-tstart)/CLOCKS_PER_SEC;
        cout << "Time for searching the maximum three of matched terms: "<<  elapsed << " seconds." << endl;
        
        if (matchedTerms.size() == 0)
        {    
            cout << "No matched query!" << endl;
        }
        else
        {
            matchedTerms.print();
        }

        cout << "Please input the search query (type \"exit\" to quit): " << endl;
        getline(cin, input);
        prefix = input;
    }    
    return 0;
}

