#pragma once
#include "Common.h"
#include "Card.h"
#include "Hand.h"
#include "GenericPlayer.h"

class Player : public GenericPlayer
{
public:
	Player(const std::string& name) :
		GenericPlayer(name)
	{}

	virtual bool IsHitting()  const override
	{
		char symbol = 'n';
		bool valid = false;
		do
		{
			std::cout << "\nDo you need a card ? [y / n]\n";
			std::cin >> symbol;
			if (symbol == 'y' || symbol == 'Y' || symbol == 'n' || symbol == 'N')
			{
				valid = true;
			}
		} while (!valid);

		if (symbol == 'y' || symbol == 'Y') { return true; }
		return false;
	};

	void Win() const { std::cout << name << ": Won!\n"; }
	void Lose() const { std::cout << name << ": Lost!\n"; }
	void Draw() const { std::cout << "Draw!\n"; }
};