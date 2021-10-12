#pragma once
#include  "Common.h"

enum CardSuit
{
	DefS,
	Diamond,
	Heart,
	Club,
	Spade
};

enum CardValue
{
	DefV = 0,
	Ace = 1,
	Two = 2,
	Three = 3,
	Four = 4,
	Five = 5,
	Six = 6,
	Seven = 7,
	Eight = 8,
	Nine = 9,
	Ten = 10,
	Jack = 10,
	Queen = 10,
	King = 10

};

class Card
{
public:
	Card() = default;
	Card(CardSuit cardSuit, CardValue cardValue)
		:
		cardSuit(cardSuit),
		cardValue(cardValue)
	{};

	void flip() { isOpen = !isOpen; };
	int  getValue() { return static_cast<int>(cardValue); };
	CardValue getCardValue() { return cardValue; };
private:
	CardSuit cardSuit{ DefS };
	CardValue cardValue{ DefV };
	bool isOpen{ false };
};