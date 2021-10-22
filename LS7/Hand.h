#pragma once


class Hand
{
public:
	Hand() = default;
	void addCard(Card* c);

	void clearCards();

	int getHandValue() const;

protected:
	std::vector<Card*> cards;
};

void Hand::addCard(Card* c)
{
	cards.emplace_back(c);
}

void Hand::clearCards()
{
	cards.clear();
}

int Hand::getHandValue() const
{
	int temp = 0;
	const int CHECK_ACE = 11;
	const int ADD_BONUS_VALUE = 10;

	if (!cards.empty())
	{
		for (size_t i = 0; i < cards.size(); ++i)
		{
			temp += cards.at(i)->getValue();

			if (temp <= CHECK_ACE && cards.at(i)->getCardValue() == Ace)
			{
				temp += ADD_BONUS_VALUE;
			}
		}
	}
	return temp;
}