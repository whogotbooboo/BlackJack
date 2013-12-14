#include "deck.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

#include <cstdlib>
using namespace std;


//Displays the root menu
void displayMenu(int);
void makeDeck(Deck *);
void setupGame(vector<Card*> *, vector<Card*> *, Deck *, bool *, bool *);
bool playBlackjack(int *, Deck *, Deck *);
int calculateScore(vector<Card*> *);
void displayHands(vector<Card*> *, vector<Card*> *);
void reformDeck(Deck *, Deck *);
bool didPlayerWin(int, int);

int main()
{
	//make cards/deck
	Deck *drawDeck = new Deck(); // creates a deck with no cards in it
	Deck *discardDeck = new Deck();
	int wallet = 10;
	makeDeck(drawDeck);
	drawDeck->setReshuffleCount(15);
	//shuffle deck
	drawDeck->shuffle();
	while (1)
	{
		displayMenu(wallet);
		//wait for user's choice _getch()
		switch (toupper(_getch()))
		{
		case '1':
			reformDeck(drawDeck, discardDeck);
			break;
		case '2':
			//shuffle cards in deck
			drawDeck->shuffle();
			break;
		case '3':
			//display all remaining cards in deck
			drawDeck->displayCards();
			cout << "Press any key to continue...";
			_getch();
			break;
		case '4':
			while (playBlackjack(&wallet, drawDeck, discardDeck))
			{
			}
			break;
		case '5':
			//quit
			exit(1);
			break;
		default:
			//if another letter/number is pressed, ignore
			break;

		}
	}
	return 0;
}


/*************************************************************
 * Name				:	playBlackjack
 * Input			:	int *, Deck *, Deck *
 * Return			:	bool
 * Precondition		:	includes Deck, vector, iostream, Card, Windows,
 * 						conio, cstdlib, initialized Filled drawDeck
 * 						with at least 4 cards and discardDeck to
 * 						fill drawDeck as required by draws
 * PostCondition	:	Plays a single hand of blackjack.
 * 						Returns true if user wants to play another
 * 						hand.
 ************************************************************/
bool playBlackjack(int *playersPocketMoney, Deck *drawDeck, Deck *discardDeck)
{
	vector <Card*> playerHand, dealerHand;
	int playerScore, dealerScore;
	bool playerBust = false;
	bool dealerBust = false;
	int playerWager = 0;
	//show amount of money in your wallet
	while (playerWager > *playersPocketMoney || playerWager <= 0)
	{
		cout << "How much of your $" << *playersPocketMoney << " would you like to bet: " ;
		try
		{
			cin >> playerWager;
		}
			catch (exception e)
		{
			playerWager = 0;
		}
	}
	//deal cards
	//player cards are visible
	//show card type and rank
	//show total for hand
	//dealer cards are !visible
	//block out dealer's cards with #
	setupGame(&playerHand, &dealerHand, drawDeck, &playerBust, &dealerBust);
	//check to see if player or dealer has 21
	displayHands(&dealerHand, &playerHand);
	playerScore = calculateScore(&playerHand);
	dealerScore = calculateScore(&dealerHand);
	if (playerScore == 21 || dealerScore == 21)
	{
		//end hand and take or give money
		//deduct amount bet from user
		//send used cards to new deck for holding
		//show menu to bet again
		dealerHand[0]->toggleVisibility();
		displayHands(&dealerHand, &playerHand);
		Sleep(2000);

	}
	else
	{
		char userChoice = ' ';
		bool userStand = false;
		while (playerScore <= 21 && !userStand)
		{
			cout << "\n[H]it\tor\t[S]tand\n";
			userChoice = toupper(_getch());
			if (userChoice == 'H')
			{
				//check to see if the deck has enough cards to continue
				if (drawDeck->isLow())
					//move cards from discardDeck to drawDeck and shuffle
					reformDeck(drawDeck, discardDeck);
				playerHand.push_back(drawDeck->draw());
				//display hands
				displayHands(&dealerHand, &playerHand);
				playerScore = calculateScore(&playerHand);
				if (playerScore > 21)
					playerBust = true;
			}
			else if (userChoice == 'S')
				userStand = true;
		}
		dealerHand[0]->toggleVisibility();
		displayHands(&dealerHand, &playerHand);
		Sleep(2000);
		while (dealerScore < 17 && playerBust != true)
		{
			//check to see if the deck has enough cards to continue
			if (drawDeck->isLow())
				//move cards from discardDeck to drawDeck and shuffle
				reformDeck(drawDeck, discardDeck);

			dealerHand.push_back(drawDeck->draw());
			//display hands
			displayHands(&dealerHand, &playerHand);
			Sleep(2000);
			dealerScore = calculateScore(&dealerHand);
			if (dealerScore > 21)
				dealerBust = true;
		}
	}


	cout << "\nDealer Score: " << dealerScore << "\nPlayer Score: " << playerScore << "\n\n";

	if (dealerBust || (playerBust == false && didPlayerWin(playerScore, dealerScore)))
		{
			*playersPocketMoney += playerWager;
		}
		else
			*playersPocketMoney -= playerWager;
		if (*playersPocketMoney == 0)
		{
			// Remember how things were when we started
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi );
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x40);
			cout << "You're outta cash SUCKA!";
			Sleep(2000);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes); // Set things to how they were when we started
			exit(1);
		}


	discardDeck->addCard(playerHand);
	discardDeck->addCard(dealerHand);
	char userResponse = ' ';
	cout << "Play another hand? (Y/N) \n";
	while (userResponse != 'Y' && userResponse != 'N')
	{
		userResponse = toupper(_getch());
		if (userResponse == 'Y')
			return true;
	}
	return false;
}

/*************************************************************
 * Name				:	makeDeck
 * Input			:	Deck *
 * Return			:	None
 * Precondition		:	Includes Card, includes Deck
 * PostCondition	:	Fills the passed deck with 52 playing cards
 ************************************************************/
void makeDeck(Deck *deck)
{
	for (int x = 1; x < 5; x++)
	{
		for (int y = 1; y < 14; y++)
		{
			deck->addCard(new Card(x, y));
		}
	}
}

/*************************************************************
 * Name				:	setupGame
 * Input			:	vector<Card*> *, vector<Card*> *, Deck *,
 * 						bool *, bool *
 * Return			:	None
 * Precondition		:	Includes vector, includes Deck
 * PostCondition	:	Puts two cards in the player's and dealer's
 * 						hands and sets visibility of the first card
 * 						drawn by dealer to false, in short
 * 						it sets up a game of blackjack
 ************************************************************/
void setupGame(vector<Card*> *playerHand, vector<Card*> *dealerHand, Deck *deck, bool *playerBust, bool *dealerBust)
{
	*playerBust = false;
	*dealerBust = false;
	playerHand->push_back(deck->draw());
	dealerHand->push_back(deck->draw());
	dealerHand->at(0)->toggleVisibility();
	playerHand->push_back(deck->draw());
	dealerHand->push_back(deck->draw());
}

/*************************************************************
 * Name				:	displayMenu
 * Input			:	int
 * Return			:	None
 * Precondition		:	Includes Windows, includes iostream
 * PostCondition	:	Clears screen and displays option menu
 ************************************************************/
void displayMenu(int playersPocketMoney)
{
	system("cls");
	cout << "1. New Deck\n"
		"2. Shuffle cards in Deck\n"
		"3. Display all cards remaining in the Deck\n"
		"4. Play Blackjack\n"
		"5. Quit\n\n"
		"You have $" << playersPocketMoney << endl;
}

/*************************************************************
 * Name				:	calculateScore
 * Input			:	vector<Card*>
 * Return			:	int
 * Precondition		:	Includes vector, includes Card
 * PostCondition	:	Returns the value of cards in the vector
 * 						based on rules of blackjack
 ************************************************************/
int calculateScore(vector<Card*> *deck)
{
	int total = 0;
	int temp = 0;
	for (int x = 0; x < deck->size(); x++)
	{
		if (deck->at(x)->getVal() == 11)
		{
			temp += deck->at(x)->getVal();
		}
		else
			total += deck->at(x)->getVal();
	}

	while ((temp + total) > 21)
	{
		if (temp >= 11)
			temp -= 10;
		else
			break;
	}
	total += temp;
	return total;
}

/*************************************************************
 * Name				:	displayHands
 * Input			:	vector<Card*>, vector<Card*>
 * Return			:	None
 * Precondition		:	Includes vector, includes iostream, includes Card
 * PostCondition	:	Displays current hands of Cards to screen
 ************************************************************/
void displayHands(vector<Card*> *dealerHand, vector<Card*> *playerHand)
{
	system("cls");
	//Create display function for hands
	cout << "\nDealer";
	for (int x = 0; x < dealerHand->size(); x++)
	{
		cout << "\t:  " << dealerHand->at(x)->getCardText() << endl;
	}
	cout << endl << "Player";
	for (int x = 0; x < playerHand->size(); x++)
	{
		cout << "\t:  " << playerHand->at(x)->getCardText()  << endl;
	}
}

/*************************************************************
 * Name				:	reformDeck
 * Input			:	Deck *, Deck *
 * Return			:	None
 * Precondition		:	includes Deck
 * PostCondition	:	Takes the cards from discardDeck and
 * 						puts them into drawDeck
 ************************************************************/
void reformDeck(Deck *drawDeck, Deck *discardDeck)
{
	//make new deck
	drawDeck->addCard(discardDeck->getCards());
	//purge discardDeck/drawDeck
	discardDeck->purge();
	//make cards/deck and shuffle
	drawDeck->shuffle();
}

/*************************************************************
 * Name				:	didPlayerWin
 * Input			:	int, int
 * Return			:	bool
 * Precondition		:	playerScore and dealerScore initialized
 * PostCondition	:	returns true if the playerscore >= dealerscore
 ************************************************************/
bool didPlayerWin(int playerScore, int dealerScore)
{
	if (playerScore >= dealerScore) //as set in requirements tie wins
		return true;
	return false;
}
