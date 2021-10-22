#pragma once


class GenericPlayer : public Hand
{
public:
	GenericPlayer() = default;
	GenericPlayer(const std::string& name);
	virtual bool IsHitting() const = 0;
	bool IsBusted();

	void Bust();

	friend std::ostream& operator<<(std::ostream& stream, const GenericPlayer& p);

	virtual ~GenericPlayer() = default;
protected:
	std::string name{};
private:
	short int winSumm{ 21 };
};

GenericPlayer::GenericPlayer(const std::string& name) :
	name(name)
{}

bool GenericPlayer::IsBusted()
{
	if (getHandValue() > winSumm) { return true; }
	return false;
}

void GenericPlayer::Bust() { std::cout << name << ": Boosted!\n"; }

std::ostream& operator<<(std::ostream& out, const GenericPlayer& player)
{
	out << player.name << ": ";

	if (player.cards.empty())
	{
		out << "Cards stack is empty!";
	}
	else
	{
		for (size_t i = 0; i < player.cards.size(); i++)
		{
			out << *player.cards[i] << " ";
		}

		out << "\nTotal value: " << player.getHandValue() << "\n";
	}

	return out;
}