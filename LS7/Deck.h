#pragma once
class Deck : public Hand
{
public:
	Deck();
	void Populate();
	void Shuffle();
	void Deal(Hand& aHand);
	void AdditionalCards(GenericPlayer& aGenericPlayer);
	virtual ~Deck() = default;
private:
	const int deckSize{ 52 };
};

Deck::Deck()
{
	cards.reserve(deckSize);
	Populate();
}

void Deck::Shuffle()
{
	random_shuffle(cards.begin(), cards.end());
}

void Deck::Deal(Hand& aHand)
{
	if (!cards.empty())
	{
		aHand.addCard(cards.back());
		cards.pop_back();
	}
	else
	{
		std::cout << "Out of cards. Unable to deal.\n";
	}
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
	std::cout << "\n";
	while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
	{
		Deal(aGenericPlayer);
		std::cout << aGenericPlayer << "\n";

		if (aGenericPlayer.IsBusted())
		{
			aGenericPlayer.Bust();
		}
	}
}

void Deck::Populate()
{
	clearCards();
	for (int i = 0; i < static_cast<int>(DefS); ++i)
	{
		for (int j = 0; j < static_cast<int>(DefV); ++j)
		{
			addCard(new Card(static_cast<CardValue>(j), static_cast<CardSuit>(i)));
		}
	}
}