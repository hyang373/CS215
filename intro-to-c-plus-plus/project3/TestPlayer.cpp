/*
 * Course: CS215-00x
 * Project: Lab 11 (for the purpose of testing Player class)
 * Purpose: Testing the definition of Player class.
 *          First, it creates 52 cards on deck (no shuffle)
 *          Second, it deals 26 cards for one player: testPlayer (another 26 cards are put on the pile at table)
 *          Third, testPlayer plays one card from hand, then drop THREE cards from hand
 *          Fourth, testPlayer plays one more card from hand
 *          Then "pretend" testPlayer wins and get FIVE cards on the pile (at the table) and  it displays cards in player1's hand and in player2's hand respectively
 *          Last, display simulation: testPlayer repeatedly plays ONE card, then drops THREE cards,until no more card in hand.
 *
 */
#include <iostream>

#include "Player.cpp"

using namespace std;

int main()
{
    // Avoid magic numbers
    const int HANDS = 26;    // each player holds 26 cards to begin the game

    // create an object of Deck class to represent standard 52-card deck
    // create a 52-card deck first
    // for testing purpose:  DO NOT shuffle the cards
    Deck playDeck;
    playDeck.createDeck();
    //playDeck.shuffleDeck();

    // The purpose of this part is to test Player class defintion 
    Deck testDeck;
    testDeck.createDeck();

    // deal 26 cards from the deck to store into cards_Player (represent cards given to the player)
    // another 26 cards put on the pile (left on the table) 
    vector<Card> cards_Player;
    vector<Card> pile;      // represents the pile of cards on the table

    for (int i = 0; i < HANDS; i++)
    {
        cards_Player.push_back(testDeck.deal_a_card());
        pile.push_back(testDeck.deal_a_card());
    }

    // create an object of Player class: testPlayer
    Player testPlayer(cards_Player);
    cout << "Testing Player class..." << endl;
    cout << "At beginning, player has " << testPlayer.getNumCards() << " cards in hand!" << endl;
    cout << "Cards in player's hand are:" << endl;
    testPlayer.print();
    cout << "Player plays one card: ";
    Card faceup = testPlayer.play_a_card();
    faceup.print();

    vector<Card> dropCards = testPlayer.dropCards();
    if (dropCards.size() == 0)
    {
        cout << endl << "Not enough cards to drop, player now has " << testPlayer.getNumCards() << " cards in hand!" << endl;
    }
    else
    {
        cout << endl << "After dropping THREE cards, player now has " << testPlayer.getNumCards() << " cards in hand!" << endl;
    }

    faceup = testPlayer.play_a_card();
    cout << "Player plays one more card: ";
    faceup.print();

    cout << endl << "After playing one more card, player now has " << testPlayer.getNumCards() << " cards in hand!" << endl;

    // take 5 cards from the pile, pretend to be winning cards
    vector<Card> winningCards;
    for (int i = 0; i < 5; i++)
    {
        winningCards.push_back(pile.back());
        pile.pop_back();
    }

    //pretend that testPlayer wins, and gets all winning cards
    testPlayer.addCards(winningCards);
    cout << "After winning FIVE cards on the pile, player now has " << testPlayer.getNumCards() << " cards in hand!" << endl;
    cout << "Now cards in player's hand are: " << endl;
    testPlayer.print();

    //simulate that testPlayer repeatedly plays ONE card, then drops ThREE cards...
    //till testPlayer has no more card in hand
    cout << endl << "Simulation starts here:" << endl;
    cout << "\t\ttestPlayer repeatedly plays ONE card, then drops THREE cards..." << endl;
    cout << "\t\tUntil no more card in hand" << endl;
    while (testPlayer.getNumCards() > 0)
    {
        cout << "Cards in player's hand are:" << endl;
        testPlayer.print();
        cout << "Player plays one card: ";
        Card faceup = testPlayer.play_a_card();
        faceup.print();

        dropCards = testPlayer.dropCards();
        if (dropCards.size() == 0)
        {
            cout << endl << "Not enough cards to drop, player now has " << testPlayer.getNumCards() << " cards in hand!" << endl;
        }
        else
        {
            cout << endl << "After dropping THREE cards, player now has " << testPlayer.getNumCards() << " cards in hand!" << endl;
        }
    }
    cout << "Game is over!" << endl;

    return 0;
}
