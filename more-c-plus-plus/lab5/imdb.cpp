/*
 * File: imdb.cpp
 * Course: CS216-003
 * Project: Project 1
 * Purpose: Provide the implementation of the class named IMDB
 *          This class represents a movie-actor database
 */
#include <regex>  // needs c++11 standard
#include "imdb.h"

using namespace std;

// default constructor
IMDB::IMDB()
{
    //do nothing
    //since map class contains a default contructor
    //      which constructs an empty container, with no elements
}

// insert a pair<actorName, the set of movieTitle of this actor>
void IMDB::insert_an_actor(string actorName, set<string> movieTitles)
{
    // First upgrade actors_db
    // if the key actorName does not exist
    //        add the key to the map actors_db
    if (!isExistingActor(actorName))
        actors_db[actorName] = movieTitles;
    else // if the key actorName does exist
    {
        actors_db[actorName].insert(movieTitles.begin(), movieTitles.end());
    }
    // Second upgrade movies_db
    // for each movieTitle in the set of movieTitles,
    // insert actorName to its actors set
    for (auto it = movieTitles.begin(); it != movieTitles.end(); it++)
    {
        if(movies_db.find(*it) == movies_db.end())
        {
            set<string> names;
            names.insert(actorName);
            movies_db[*it] = names;
        }
        else
        {
            movies_db[*it].insert(actorName);
        }

    }
}

// insert a pair <movieTitle, the set of actor names in this movie>
// this function is optional to this project
void IMDB::insert_a_movie(string movieTitle, set<string> actorNames) 
{
    // First upgrade movies_db
    // if the key moiveTitle does not exist
    //        add the key to the map movies_db
    if (!isExistingMovie(movieTitle))
        movies_db[movieTitle] = actorNames;
    else // if the key movieTitle does exist
    {
        movies_db[movieTitle].insert(actorNames.begin(), actorNames.end());
    }

    // Second upgrade actors_db
    // for each actor name in the set of actorNames,
    // insert movieTitle to its movie set
    for (auto it = actorNames.begin(); it != actorNames.end(); it++)
    {
        if (actors_db.find(*it) == actors_db.end())
        {
            set<string> movies;
            movies.insert(movieTitle);
            actors_db[*it] = movies;
        }
        else
        {
            actors_db[*it].insert(movieTitle);
        }
    }
}
// use passing in parameter, movieTitle, as the pattern to match 
// one existing movie in the map
// return the matched movie title from the map
// otherwise return empty string
string IMDB::matchExistingMovie(string movieTitle) const
{
    string matchedMovie;
    bool found = false;
    // generate the regular expression to match 
    // which contains movieTitle as a substring
    // note that it performs case insensitive matching
    regex reg(movieTitle, regex_constants::icase);
    auto it = movies_db.begin();
    while (!found && it != movies_db.end())
    {
        if (regex_search(it->first, reg))
        {
            found = true;
            matchedMovie = it->first;
        }
        else
            it++;
    }
    return matchedMovie;
}

// check if a movieTitle does exist in the map
// return true if it does; otherwise return false
bool IMDB::isExistingMovie(string movieTitle) const
{
    if(movies_db.find(movieTitle) != movies_db.end())
        return true;
    else
        return false;
}

// check if an actorName does exist in the map
// return true if it does; otherwise return false
bool IMDB::isExistingActor(string actorName) const
{
    if(actors_db.find(actorName) != actors_db.end())
        return true;
    else
        return false;
}

// return a set of movie titles which actorName is in
// if the passing in parameter: actorName, is not in the database, 
//                   display message andreturn an empty set
set<string> IMDB::find_movies_for_an_actor(string actorName) const
{
    set<string> actor_movies;
    
    if(!isExistingActor(actorName)){
        cout << "No Movies could be found for " << actorName << " ." << endl;
        return actor_movies;
    }
    else{

        actor_movies = actors_db.at(actorName);
    }
    return actor_movies;
}


// return a set of actor names which are all in the movieTitle
// if the passing in parameter: movieTitle is not in the database, 
//                   display message and return an empty set
set<string> IMDB::find_actors_in_a_movie(string movieTitle) const
{
    set<string> movie_actors;

    if(!isExistingMovie(movieTitle)){
        cout << "No Actors could be found for " << movieTitle<< " ." << endl;
         return movie_actors;
     }
     else{
         movie_actors = movies_db.at(movieTitle);
     }
     return movie_actors;
}
