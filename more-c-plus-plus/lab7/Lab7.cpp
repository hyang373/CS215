/*
 * Course: CS216-00x
 * Project: Lab 7 (As Project 1 extension)
 * Purpose: Provide extra features for Project 1
 *          It repeatedly asks the user to type an actor/actress name until the user types "quit" to quit the program
 *          The user-input name can be "best-matched".
 *          If the name is matched, then display all the co-actors in each movie which the user-input actor was in
 * Author: Yi Pike
 * ### Please Do Not Change This File. ###
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <set>
#include <map>
#include "imdb.h"
#include "magicString.h"

using namespace std;

// declare global variable (constant only)
const int ARGUMENTS = 2;   // define the required command line arguments

int main(int argc, char* argv[])
{
    // Check whether the number of command line arguments match the required one 
    if (argc != ARGUMENTS)
    {
        cout << "Warning: need exactly one command line argument." << endl;
        cout << "Usage: " << argv[0] << " inputfile_name" << endl;
        return 1;
    }

    ifstream in_file;
    in_file.open(argv[1]);
    // Check whether the input file can be open successfully or not
    if (!in_file.good())
    {
        cout << "Warning: cannot open file named " << argv[1] << "!" << endl;
        return 2;
    }
    
    // Read data from the input file, assume "good data" from the input file
    // each line of the input file: actor name; movie1; movie2; ...; movien
    // read one line at a time then tokenize it:
    // create a pair <actor_name, the set of movieTitles which the actor was in>
    //        and insert to IMDB object
    IMDB cs216_imdb;

    while (!in_file.eof())
    {
        string line;
        getline(in_file, line);
        string name, movie;
        istringstream iss(line);
        getline(iss, name,';');
        
        // Extract extra white space
        iss>>ws;

        // Create a new set of movies assocatiated with name
        set<string> movies;

        while (getline(iss, movie, ';'))
        {
            movies.insert(movie);
            // extract white space 
            iss>>ws;
        }

        // insert to IMDB object: cs216_imdb
        magicString actorName(name);
        cs216_imdb.insert_an_actor(actorName.toLower(), movies);
    }
    // close the input file
    in_file.close();

    // Repeatedly ask the user to type an actor's name until user types "quit"
    // to validate the user input:
    //  1. ignore case distinction
    //  2. ignore any space or tab before the first non-space character
    //  3. ignore extra spaces between two non-space characters
    // then display all the co-actors in each of the movies for the user-typed actor (excluding the user-typed actor)
    // the user-typed actor name is displayed in all upper case letters
    string inputname;
    cout << "This application helps you find the movies, which an actor/actress was in (including his/her co-actors):" << endl;
    cout << "Please input the name of the actor/actress (type \"quit\" to quit the program) ";
    getline(cin, inputname);
    
    magicString validName(inputname);
    validName.removeExtraSpace();

    while (validName.toLower() != "quit")
    {
        // find the set of movies that this actor is in
        // first, check if name is valid
        // if it is invalid
        if (!cs216_imdb.isExistingActor(validName.toLower()))
        {
            cout << "The actor name you entered is not in the database." << endl;
        }

        else   // if name is valid
        {
            set<string> movies_of_actor;
            movies_of_actor = cs216_imdb.find_movies_for_an_actor(validName.toLower());

            cout << endl << "You type: " << inputname << endl;
            cout << validName.toUpper() << " is in: " << endl;
    
            // set up a counter: movieCount, to count the number of movies
            int movieCount = 0;
            for (auto i = movies_of_actor.begin(); i != movies_of_actor.end(); i++)
            {        
                movieCount++;
                cout << "\t" << movieCount << ": \"" << *i << " \" with: "<< endl;
                // Display all the co-actors in one movie
                set<string> coactors = cs216_imdb.find_actors_in_a_movie(*i);
                for (auto j = coactors.begin(); j != coactors.end(); j++)
                {
                    // display all the co-actors, but not the actor himself/herself
                    if (*j != validName.toLower())
                    {       
                        magicString name_to_display(*j);
                        cout << "\t" << name_to_display.wordFormat()<< endl;
                    }
                }    
                cout << "***********************************" << endl;
            }
        }
        cout << "This application helps you find the movies an actor/actress is in (including co-actors):" << endl;
        cout << "Please input the name of the actor/actress (type \"quit\" to quit the program) ";
        getline(cin, inputname);
    
        validName.setMagicString(inputname);
        validName.removeExtraSpace();
    }
    
    cout << "Thank you for using this program..." << endl;
    return 0;
}
