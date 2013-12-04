

#include "Card.h"

Card::Card(void)
{
	m_visible = true;
	m_cardText = "";
	m_cardValue = 0;
}

Card::Card(int suit, int rank)
{
	makeCardTextAndValue(suit, rank);
	m_visible = true;

}
Card::Card(int suit, int rank, bool isVisible)
{
	m_visible = isVisible;
	makeCardTextAndValue(suit, rank);
}

string Card::getCardText()
{
	return m_cardText;
}

void Card::setCardText( const string& newCardText )
{
	m_cardText = newCardText;
}
void Card::toggleVisibility()
{
	m_visible = !m_visible;
}

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
Card::~Card(void)
{
}

