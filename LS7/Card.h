#pragma once
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
	Card(CardValue cardValue, CardSuit cardSuit);

	void flip();
	int  getValue();
	CardValue getCardValue();

	friend std::ostream& operator<<(std::ostream& out, const Card& card);
private:
	CardValue cardValue{ DefV };
	CardSuit cardSuit{ DefS };
	bool isOpen{ false };
};

Card::Card(CardValue cardValue, CardSuit cardSuit)
	:
	cardValue(cardValue),
	cardSuit(cardSuit)
{};

void Card::flip() { isOpen = !isOpen; };

int Card::getValue() {
	if (cardValue >= Ace && cardValue <= Nine)
	{
		return static_cast<int>(cardValue) + 1;
	}
	else if (cardValue >= Ten && cardValue <= King)
	{
		return 10;
	}
	return 0;
};

CardValue Card::getCardValue() { return cardValue; };

std::ostream& operator<<(std::ostream& out, const Card& card)
{
	std::array<char, 13> valueArr = { 'A','2','3','4','5','6','7','8','9','10','J','Q','K' };
	std::array<char, 4> suitArr = { 'D','H','C','S' };

	if (card.isOpen)
	{
		out << suitArr[static_cast<int>(card.cardSuit)] << valueArr[static_cast<int>(card.cardValue)];
	}
	else
	{
		out << "XX";
	}
	return out;
};

