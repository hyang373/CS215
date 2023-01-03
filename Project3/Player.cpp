/* File: Player.cpp
 * Course: CS215-001
 * Project: Project 3
 * Purpose: the implementation of member functions for the Player class.
 * Author: Helen Yang
*/


#include "Player.h"
#include <stdlib.h>

using namespace std;
// default constructor 
Player::Player(){
    numCards = 0;       // start with 0 cards
    vector<Card> cards; // an empty vector
}
 
// alternative constructor 
Player::Player(vector<Card> ini_cards){
    numCards = ini_cards.size();    // initial number of cards
    cards = ini_cards;  // initial hand of cards
}
 
// return how many cards player holds currently 
int Player::getNumCards() const{
    //numCards = cards.size();
    return numCards;
}
 
// player plays one card at the front of cards at hand 
Card Player::play_a_card(){
    Card played_card;

    played_card = cards.front();    // call the card at front of deck
    cards.erase(cards.begin());     // remove that card from deck
    numCards = numCards - 1;        // update the number of cards you have

    return played_card;
}
 
// player wins and adds winning cards to the end of the pile at hand  
void Player::addCards(vector<Card> winningCards){
    for (int i = 0; i < winningCards.size(); i++){
        cards.push_back(winningCards[i]);   // add new cards to your deck
        numCards++; // update the number of cards player have
    }
}
 
// player drops THREE cards from the front of pile at hand 
// when there is a tie 
vector<Card> Player::dropCards(){
    vector<Card> droppedcards;

    for(int i = 0; i < 3; i++){
        Card card_dropped;
        card_dropped = play_a_card();
        droppedcards.push_back(card_dropped);
        if (cards.size() < 2)
        {
            cout << endl;
            cout << "Not enough cards to drop!" << endl;
            cout << endl;
            cout << "Not enough cards to drop, player now has 0 cards in hand! Game is over!" << endl;
            cout << endl;
            exit(EXIT_SUCCESS);
        }
    }
    return droppedcards;
}
    
// display cards at player's hand 
void Player::print() const{
    for (int i = 0; i < cards.size(); i++){
        cards[i].print();
        cout << " ";
    }
    cout << endl;
}