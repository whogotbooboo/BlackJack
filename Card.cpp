

#include "Card.h"

	/*************************************************************
	 * Name				:	Card
	 * Input			:	None
	 * Return			:	None
	 * Precondition		:	includes string
	 * PostCondition	:	Sets rank, suit, cardText, and visibility
	 * 						of card
	 ************************************************************/
Card::Card(void)
{
	m_visible = true;
	m_cardText = "";
	m_cardValue = 0;
}

/*************************************************************
 * Name				:	Card
 * Input			:	int, int
 * Return			:	None
 * Precondition		:	includes string
 * PostCondition	:	Sets rank, suit, cardText, and visibility
 * 						of card
 ************************************************************/
Card::Card(int suit, int rank)
{
	makeCardTextAndValue(suit, rank);
	m_visible = true;

}

/*************************************************************
 * Name				:	Card
 * Input			:	int, int, bool
 * Return			:	None
 * Precondition		:	includes string
 * PostCondition	:	Sets rank, suit, cardText, and visibility
 * 						of card
 ************************************************************/
Card::Card(int suit, int rank, bool isVisible)
{
	m_visible = isVisible;
	makeCardTextAndValue(suit, rank);
}

/*************************************************************
 * Name				:	getCardText
 * Input			:	None
 * Return			:	string
 * Precondition		:	Includes string
 * PostCondition	:	Returns card's text if card is visible
 * 						otherwise returns "? ?? ???????"
 ************************************************************/
string Card::getCardText()
{
	if (m_visible)
		return m_cardText;
	else
		return "? ?? ???????";
}

/*************************************************************
 * Name				:	toggleVisibility
 * Input			:	None
 * Return			:	None
 * Precondition		:	m_visible initialized
 * PostCondition	:	switches value of m_visible true/false
 ************************************************************/
void Card::toggleVisibility()
{
	m_visible = !m_visible;
}

/*************************************************************
 * Name				:	isVisible
 * Input			:	None
 * Return			:	bool
 * Precondition		:	m_visible initialized
 * PostCondition	:	Returns true if the card is visible
 ************************************************************/
bool Card::isVisible()
{
	return m_visible;
}



void Card::makeCardTextAndValue(int suit, int rank)
{
		string cardSuit;
		string cardRank;
		switch (suit)
		{
			case 1:
				cardSuit = "Spades";
				break;
			case 2:
				cardSuit = "Diamonds";
				break;
			case 3:
				cardSuit = "Clubs";
				break;
			case 4:
				cardSuit = "Hearts";
				break;
		}
		switch (rank)
		{
			case 1:
				cardRank = "A";
				m_cardValue = 11;
				break;
			case 2:
				cardRank = "2";
				m_cardValue = 2;
				break;
			case 3:
				cardRank = "3";
				m_cardValue = 3;
				break;
			case 4:
				cardRank = "4";
				m_cardValue = 4;
				break;
			case 5:
				cardRank = "5";
				m_cardValue = 5;
				break;
			case 6:
				cardRank = "6";
				m_cardValue = 6;
				break;
			case 7:
				cardRank = "7";
				m_cardValue = 7;
				break;
			case 8:
				cardRank = "8";
				m_cardValue = 8;
				break;
			case 9:
				cardRank = "9";
				m_cardValue = 9;
				break;
			case 10:
				cardRank = "10";
				m_cardValue = 10;
				break;
			case 11:
				cardRank = "J";
				m_cardValue = 10;
				break;
			case 12:
				cardRank = "Q";
				m_cardValue = 10;
				break;
			case 13:
				cardRank = "K";
				m_cardValue = 10;
				break;
		}
		m_cardText = cardRank + " of " + cardSuit;
}

/*************************************************************
 * Name				:	getVal
 * Input			:	None
 * Return			:	int
 * Precondition		:	m_cardValue initialized
 * PostCondition	:	returns card's value
 ************************************************************/
int Card::getVal(void)
{
	return m_cardValue;
}

/*************************************************************
 * Name				:	~Card
 * Input			:	None
 * Return			:	None
 * Precondition		:	The card exists
 * PostCondition	:	Destroys the card
 ************************************************************/
Card::~Card(void)
{
}
