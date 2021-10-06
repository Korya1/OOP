#pragma once
#include "Common.h"
#include "Card.h"

class Hand
{
public:
	Hand() = default;
	void addCard(Card* c)
	{
		cards.emplace_back(c);
	}

	void clearCards()
	{
		cards.clear();
	}

	int getValue()
	{
		int temp = 0;
		if (!cards.empty())
		{
			for (size_t i = 0; i < cards.size(); ++i)
			{
				temp += cards.at(i)->getValue();

				if (temp <= 11 && cards.at(i)->getCardValue() == Ace)
				{
					temp += 10;
				}
			}
		}
		return temp;
	}

private:
	std::vector<Card*> cards;
};