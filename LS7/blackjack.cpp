#include "Common.h"
#include "Card.h"
#include "Hand.h"
#include "GenericPlayer.h"
#include "Player.h"
#include "House.h"
#include "Deck.h"
#include "Game.h"

int main()
{
	std::vector<std::string> n{"Maksym"};
	bool valid;
	char symbol;
	bool restart;
	do
	{
		symbol = 'n';
		restart = false;
		valid = false;

		Game game(n);

		game.Play();

		do
		{			
			std::cout << "\nRestart? [y / n]\n";
			std::cin >> symbol;
			system("CLS");
			if (symbol == 'y' || symbol == 'Y' || symbol == 'n' || symbol == 'N')
			{
				valid = true;
			}

		} while (!valid);

		if (symbol == 'y' || symbol == 'Y') { restart = true;}

	} while (restart);

	
	return false;
	


	return 0;
}
