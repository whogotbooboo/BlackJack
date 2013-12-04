#pragma once
#include "Card.h"
#include <time.h>
#include <vector>
#include <cstdlib>
#include <iostream>

const int DECK_SIZE_LIMIT = 52;

class Deck
{
	Card** cardsInDeck;
	int count;

public:
	Deck(void);
	Deck( Card* p_newCards[] , int p_count );
	Deck( vector<Card*> p_newCards );
	void shuffle();		// Postcondition: Cards in the deck are placed in a random order
	Card* draw();		// Postcondition: Draws the top card of the deck.
	vector<Card*> draw( int &p_amount );	// Postcondition: Draws p_amount cards. If there are not enough cards in the deck, p_amount is
											// changed to the maximum number of cards available to draw.
	void addCard( Card* p_newCard );	// Postcondition: Adds the new card to the deck
	void addCard( Card* p_newCards[] , int p_count );	// Postcondition: Adds all cards in the array to the deck
	void addCard( vector<Card*> p_newCards );			// Postcondition: Adds all cards in the vector to the deck
	vector<Card*> getCards();	// Postcondition: Returns all cards in deck
	void purge(); //Postcondition: Removes all cards from the deck
	void displayCards();
	~Deck(void);
};

