/* File: Player.h
 * Course: CS215-001
 * Project: Project 3
 * Purpose: the declaration for the Player class.
 * Author: Helen Yang
 */
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <queue>
#include "Deck.h"

#include "Deck.cpp" // need this to be able to run on macbook

using namespace std;
class Player 
{ 
   public: 
    // default constructor 
    Player(); 
 
    // alternative constructor 
    Player(vector<Card> ini_cards); 
 
    // return how many cards player holds currently 
    int getNumCards() const; 
 
    // player plays one card at the front of cards at hand 
    Card play_a_card(); 
 
    // player wins and adds winning cards to the end of the pile at hand  
    void addCards(vector<Card> winningCards); 
 
    // player drops THREE cards from the front of pile at hand 
   // when there is a tie 
    vector<Card> dropCards(); 
    
    // display cards at player's hand 
    void print() const; 
 
   // you are allowed to add other member functions if you want 
 
   private: 
    int numCards;  // how many cards in player's hand 
    vector<Card> cards;         // sequence of cards in player's hand 
}; 
#endif  /* PLAYER_H */
