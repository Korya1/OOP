#pragma once
#include "Hand.h"
#include "Card.h"

class GenericPlayer : public Hand
{
public:
	GenericPlayer() = default;
	virtual void IsHitting() = 0;
	bool IsBoosted() 
	{ 
		if (getValue() > winSumm) { return true; }
		return false; 
	}

	void Bust() { std::cout << name << ": Boosted!\n"; }

	virtual ~GenericPlayer() = default;
protected:
	std::string name{};
private:
	short int winSumm{ 21 };
};