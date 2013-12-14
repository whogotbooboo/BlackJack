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
	int reshuffleCount;

public:


	Deck(void);
	Deck(Card* p_newCards[], int p_count);
	Deck(vector<Card*> p_newCards);
	void shuffle();
	Card* draw();
	void addCard(Card* p_newCard);
	void addCard(Card* p_newCards[], int p_count);
	void addCard(vector<Card*> p_newCards);
	vector<Card*> getCards();
	void purge();
	bool isLow();
	void setReshuffleCount(int);
	void displayCards();
	~Deck(void);
};

