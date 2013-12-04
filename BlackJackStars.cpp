//============================================================================
// Name        : BlackJackStars.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Deck.h"
void makeDeck(Deck*);

using namespace std;

int main()
{
	Card *hello = new Card(1,5); //Creates a new card (remember default visibility is true)
	cout << "This is a the first output: " << hello->getCardText() /*Displays the text of the card WITH NO NEW LINE */<< endl;
	Card *hello2 = new Card(1,5, false); // creates a new card that's not visible
	cout << "This is a the first output: " << hello2->getCardText() /*Displays the text of the card WITH NO NEW LINE */<< endl;
	Deck *deck = new Deck(); // creates a deck with no cards in it
	makeDeck(deck);
	deck->displayCards();
	deck->shuffle();
	deck->displayCards();
	return 0;
}

void makeDeck(Deck *deck)
{
	for (int x = 1; x < 5; x++)
	{
		for (int y = 1; y < 14; y++)
		{
			deck->addCard(new Card(x,y));
		}
	}
}
