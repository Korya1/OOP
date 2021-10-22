#pragma once


class House : public GenericPlayer
{
public:
	House() = default;
	House(const std::string& name);

	virtual bool IsHitting() const override;

	void FlipFirstCard();
};

House::House(const std::string& name) :
	GenericPlayer(name)
{}

bool House::IsHitting() const
{
	const int MAX_VALUE = 16;

	if (getHandValue() > MAX_VALUE)
	{
		return false;
	}

	return true;
}

void House::FlipFirstCard()
{
	if (!(cards.empty()))
	{
		cards[0]->flip();
	}
	else
	{
		std::cout << "Cards stack is empty!\n";
	}
}