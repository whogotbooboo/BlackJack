/*
 * Card.h
 *
 *  Created on: Dec 3, 2013
 *      Author: BooBoo
 */

#ifndef CARD_H_
#define CARD_H_

#pragma once
#include <string>

using namespace std;

class Card
{
private:
	void makeCardTextAndValue(int suit, int rank);
protected:
	bool m_visible;
	string m_cardText;
	string m_displayRank;
	int m_cardValue;
	char m_suit;

public:
	Card(void);
	Card(int suit, int rank);
	Card(int suit, int rank, bool isVisible);
	~Card(void);
	string getCardText();
	void setCardText( const string& newCardText );
	void toggleVisibility();
	bool isVisible();
};



#endif /* CARD_H_ */
