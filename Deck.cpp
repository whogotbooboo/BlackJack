#include "Deck.h"

Deck::Deck(void)
{
	srand(time(NULL));
	cardsInDeck = new Card*[DECK_SIZE_LIMIT];
	for(int x = 0; x < DECK_SIZE_LIMIT; x++)
		cardsInDeck[x] = NULL;
	count = 0;
}

Deck::Deck(Card* p_newCards[] , int p_count)
{
	srand(time(NULL));
	cardsInDeck = new Card*[DECK_SIZE_LIMIT];
	count = 0;

	for(int x = 0; x < DECK_SIZE_LIMIT; x++)
		cardsInDeck[x] = NULL;

	if(p_count <= DECK_SIZE_LIMIT && p_count > 0)
	{
		count = p_count;
		for(int x = 0; x < count; x++)
		{
			cardsInDeck[x] = p_newCards[x];
		}
	}
}
Deck::Deck(vector<Card*> p_newCards)
{
	srand(time(NULL));
	cardsInDeck = new Card*[DECK_SIZE_LIMIT];
	count = 0;

	for(int x = 0; x < DECK_SIZE_LIMIT; x++)
		cardsInDeck[x] = NULL;

	int j = 0;
	for(vector<Card*>::iterator x = p_newCards.begin(); x != p_newCards.end(); x++)
	{
		cardsInDeck[j] = p_newCards[j];
		j++;
	}
	count = j;
}
void Deck::shuffle()		// Postcondition: Cards in the deck are placed in a random order
{
	Card* hold = NULL;
	int randomCard = rand() % count;

	for(int x = 0; x < count; x++)
	{
		hold = cardsInDeck[x];
		cardsInDeck[x] = cardsInDeck[randomCard];
		cardsInDeck[randomCard] = hold;
		randomCard = rand() % count;
	}
}
Card* Deck::draw()
{
	if(count > 0)
	{
		Card* ret = cardsInDeck[0];

		for(int x = 0; x < count; x++)
		{
			cardsInDeck[x] = cardsInDeck[x + 1];
		}
		count--;

		return ret;
	}
	else
		return NULL;
}
vector<Card*> Deck::draw( int &p_amount )	// Postcondition: Draws p_amount cards. If there are not enough cards in the deck, p_amount is
								// changed to the maximum number of cards available to draw.
{
	vector<Card*> cardsDrawn;
	if( p_amount < count )
	{
		for(int i = 0; i < p_amount; i++)
		{
			cardsDrawn.push_back(cardsInDeck[0]);
			for(int y = 0; y < count; y++)
			{
				cardsInDeck[y] = cardsInDeck[y + 1];
			}
			count--;
		}
	}
	else
	{
		int cardsAmount = count;
		for(int x = 0; x < cardsAmount; x++)
		{
			cardsDrawn.push_back(cardsInDeck[0]);
			for(int y = 0; y < count; y++)
			{
				cardsInDeck[y] = cardsInDeck[y + 1];
			}
			count--;
		}
		if( count != 0 )
		{
			count = 0;
		}
	}

	return cardsDrawn;
}
void Deck::addCard(Card* p_newCard)	// Postcondition: Adds the new card to the deck
{
	if( p_newCard != NULL )
	{
		cardsInDeck[count] = p_newCard;
		count++;
	}
}
void Deck::addCard(Card* p_newCards[] , int p_count)	// Postcondition: Adds all cards in the array to the deck
{
	for(int x = 0; x < p_count; x++)
	{
		if(p_newCards[x] != NULL)
		{
			cardsInDeck[count] = p_newCards[x];
			count++;
		}
	}
}
void Deck::addCard(vector<Card*> p_newCards)			// Postcondition: Adds all cards in the vector to the deck
{
	int j = 0;
	for(vector<Card*>::iterator x = p_newCards.begin(); x != p_newCards.end(); x++)
	{
		addCard(p_newCards[j]);
		j++;
	}
}
vector<Card*> Deck::getCards()	// Postcondition: Returns all cards in deck as a vector of Card pointers
{
	vector<Card*> returnedCards;
	for(int x = 0; x < count; x++)
		returnedCards.push_back(cardsInDeck[x]);

	return returnedCards;

}
void Deck::purge() //Postcondition: Removes all cards from the deck
{
	for(int x = 0; x < DECK_SIZE_LIMIT; x++)
		cardsInDeck[x] = NULL;
	count = 0;
}
void Deck::displayCards()
{
	for (int x = 0; x < count; x++)
			cout << cardsInDeck[x]->getCardText() << endl;
}
Deck::~Deck(void)
{
	delete[] cardsInDeck;
}
