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
	Card *hello;
	Deck *deck = new Deck();
	makeDeck(deck);
	deck->displayCards();
	return 0;
}

void makeDeck(Deck *deck)
{
	for (int x = 1; x < 5; x++)
		for (int y = 1; y < 14; y++)
		{
			deck->addCard(new Card(x,y));
		}
	{}
}
