#include "Deck.h"

	/*************************************************************
	 * Name				:	Deck
	 * Input			:	None
	 * Return			:	None
	 * Precondition		:	Includes ctime, includes cstdlib
	 * PostCondition	:	Creates an empty deck
	 ************************************************************/
Deck::Deck(void)
{
	srand(time(NULL)); //set the random seed
	cardsInDeck = new Card*[DECK_SIZE_LIMIT]; //as set in requirements an array of cards
	for(int x = 0; x < DECK_SIZE_LIMIT; x++)
		cardsInDeck[x] = NULL;
	count = 0;
	reshuffleCount = 0;
}

/*************************************************************
 * Name				:	Deck
 * Input			:	Card *[], int
 * Return			:	None
 * Precondition		:	Includes ctime, includes cstdlib
 * PostCondition	:	Creates a new deck of cards filled with
 * 						cards from the passed array
 ************************************************************/
Deck::Deck(Card* p_newCards[] , int p_count)
{
	srand(time(NULL));  //set the random seed
	cardsInDeck = new Card*[DECK_SIZE_LIMIT]; //as set in requirements an array of cards
	count = 0;
	reshuffleCount = 15;
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

/*************************************************************
 * Name				:	Deck
 * Input			:	vector<Card*>
 * Return			:	None
 * Precondition		:	Includes ctime, includes cstdlib
 * PostCondition	:	Creates a new deck of cards filled with
 * 						cards from the passed vector
 ************************************************************/
Deck::Deck(vector<Card*> p_newCards)
{
	srand(time(NULL));  //set the random seed
	cardsInDeck = new Card*[DECK_SIZE_LIMIT]; //as set in requirements an array of cards
	count = 0;
	reshuffleCount = 15;
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

/*************************************************************
 * Name				:	shuffle
 * Input			:	None
 * Return			:	None
 * Precondition		:	Includes cstdlib, srand already set,
 * 						cardsInDeck initialized
 * PostCondition	:	Cards in the deck are placed in a random order
 ************************************************************/
void Deck::shuffle()
{
	Card* hold = NULL;
	int randomCard = rand() % count;

	for(int x = 0; x < count; x++)
	{
		// switch places of 2 cards
		hold = cardsInDeck[x];
		cardsInDeck[x] = cardsInDeck[randomCard];
		cardsInDeck[randomCard] = hold;
		randomCard = rand() % count;
	}
}

/*************************************************************
 * Name				:	draw
 * Input			:	None
 * Return			:	Card *
 * Precondition		:	cardsInDeck initialized
 * PostCondition	:	Draws (returns) the top card of the deck.
 * 						All cards are logically moved up in the deck
 ************************************************************/
Card* Deck::draw()
{
	if(count > 0)
	{
		Card* ret = cardsInDeck[0];
		for(int x = 0; x < count; x++)
		{
			cardsInDeck[x] = cardsInDeck[x + 1];  //shift all cards in deck up 1 space
		}
		count--;

		return ret;
	}
	else
		return NULL;
}

/*************************************************************
 * Name				:	addCard
 * Input			:	Card *
 * Return			:	None
 * Precondition		:	cardsInDeck initialized
 * PostCondition	:	Adds the passed card to the deck
 ************************************************************/
void Deck::addCard(Card* p_newCard)
{
	if( p_newCard != NULL )
	{
		cardsInDeck[count] = p_newCard;
		count++;
	}
}

/*************************************************************
 * Name				:	addCard
 * Input			:	Card *[], int
 * Return			:	None
 * Precondition		:	cardsInDeck initialized
 * PostCondition	:	Adds all cards in the array to the deck
 ************************************************************/
void Deck::addCard(Card* p_newCards[] , int p_count)
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

/*************************************************************
 * Name				:	addCard
 * Input			:	vector<Card*>
 * Return			:	None
 * Precondition		:	Includes vector, addCard(Card*) exists
 * PostCondition	:	Adds all cards in the vector to the deck
 ************************************************************/
void Deck::addCard(vector<Card*> p_newCards)
{
	int j = 0;
	for(vector<Card*>::iterator x = p_newCards.begin(); x != p_newCards.end(); x++)
	{
		addCard(p_newCards[j]);
		j++;
	}
}

/*************************************************************
 * Name				:	getCards
 * Input			:	None
 * Return			:	vector<Card*>
 * Precondition		:	Includes vector, initialized cardsInDeck
 * 						and count
 * PostCondition	:	Returns all cards in deck
 ************************************************************/
vector<Card*> Deck::getCards()
{
	vector<Card*> returnedCards;
	for(int x = 0; x < count; x++)
		returnedCards.push_back(cardsInDeck[x]);

	return returnedCards;

}

/*************************************************************
 * Name				:	purge
 * Input			:	None
 * Return			:	None
 * Precondition		:	initialized cardsInDeck
 * PostCondition	:	Removes all cards from the deck
 ************************************************************/
void Deck::purge()
{
	for(int x = 0; x < DECK_SIZE_LIMIT; x++)
		cardsInDeck[x] = NULL;
	count = 0;
}

/*************************************************************
 * Name				:	displayCards
 * Input			:	None
 * Return			:	None
 * Precondition		:	Includes iostream, cardsInDeck is filled with count
 * 						cards
 * PostCondition	:	Displays the card text of all cards in deck
 ************************************************************/
void Deck::displayCards()
{
	for (int x = 0; x < count; x++)
	{
		
		cout << cardsInDeck[x]->getCardText() << endl;

	}
}

/*************************************************************
 * Name				:	isLow
 * Input			:	None
 * Return			:	bool
 * Precondition		:	count and reshuffleCount initialized
 * PostCondition	:	returns boolean if deck has less cards
 * 						then reshuffleCount
 ************************************************************/
bool Deck::isLow(void)
{
	if (count < reshuffleCount)
	{
		return true;
	}
	else
		return false;
}

/*************************************************************
 * Name				:	setReshuffleCount
 * Input			:	int
 * Return			:	None
 * Precondition		:	reshuffleCount declared
 * PostCondition	:	Sets reshuffleCount to input number
 ************************************************************/
void Deck::setReshuffleCount(int num)
{
	reshuffleCount = num;
}

/*************************************************************
 * Name				:	~Deck
 * Input			:	None
 * Return			:	None
 * Precondition		:	A initialized deck
 * PostCondition	:	Destroys the deck
 ************************************************************/
Deck::~Deck(void) // destroys the deck
{
	delete[] cardsInDeck;
}
