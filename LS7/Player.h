#pragma once

class Player : public GenericPlayer
{
public:
	Player(const std::string& name);

	virtual bool IsHitting()  const override;

	void Win() const;
	void Lose() const;
	void Draw() const;
};

Player::Player(const std::string& name) :
	GenericPlayer(name)
{}

bool Player::IsHitting() const
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

void Player::Win() const { std::cout << name << ": Won!\n"; }
void Player::Lose() const { std::cout << name << ": Lost!\n"; }
void Player::Draw() const { std::cout << "Draw!\n"; }