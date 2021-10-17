#pragma once
#include  "Common.h"
enum CardSuit
{
	
	Diamond,
	Heart,
	Club,
	Spade,
	DefS
};

enum CardValue
{
	
	Ace,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	DefV
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
	int  getValue() { 
		if(cardValue >= Ace && cardValue <= Nine)
		{
			return static_cast<int>(cardValue) + 1;
		}
		else if(cardValue >= Ten && cardValue <= King)
		{
			return 10;
		}
		return 0; 
	};
	CardValue getCardValue() { return cardValue; };

	friend std::ostream& operator<<(std::ostream& os, const Card& c);
private:
	CardSuit cardSuit{ DefS };
	CardValue cardValue{ DefV };
	bool isOpen{ false };
}; 

std::ostream& operator<<(std::ostream& out, const Card& card) 
{		
	const std::array<char, 13> valueArr = {'A','2','3','4','5','6','7','8','9','10','J','Q','K'};
	const std::array<char, 4> suitArr = { 'D','H','C','S'};

	if(card.isOpen)
	{
		out << suitArr[static_cast<int>(card.cardSuit)] << valueArr[static_cast<int>(card.cardValue)];
	}
	else
	{
		out << "XX";
	}
	return out;
}