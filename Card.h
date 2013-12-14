/*
 * Card.h
 *
 *  Created on: Dec 3, 2013
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
	void toggleVisibility();
	bool isVisible();
	int getVal(void);
};



#endif /* CARD_H_ */
