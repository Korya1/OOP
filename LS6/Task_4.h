#pragma once
#include "Common.h"
#include "Card.h"
#include "Hand.h"
#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
	House(const std::string& name) :
		GenericPlayer(name)
	{}

	virtual bool IsHitting() const override
	{
		const int MAX_VALUE = 16;

		if (getHandValue() > MAX_VALUE)
		{
			return false;
		}

		return true;
	}

	void FlipFirstCard()
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
};