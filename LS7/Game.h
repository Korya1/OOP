#pragma once


class Game
{
public:
	Game(const std::vector<std::string>& name);
	void Play();
	~Game() = default;
private:
	Deck m_Deck;
	House m_House{ "Computer" };
	std::vector<Player> m_Players;

};

Game::Game(const std::vector<std::string>& name)
{
	std::vector<std::string>::const_iterator pName;
	for (pName = name.begin(); pName != name.end(); ++pName)
	{
		m_Players.emplace_back(Player(*pName));
	}

	srand(static_cast<size_t>(time(0)));

	m_Deck.Populate();
	m_Deck.Shuffle();
}

void Game::Play()
{
	std::vector<Player>::iterator pPlayer;
	for (int i = 0; i < 2; ++i)
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			m_Deck.Deal(*pPlayer);
		}
		m_Deck.Deal(m_House);
	}

	m_House.FlipFirstCard();

	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		std::cout << *pPlayer << "\n";
	}

	std::cout << m_House << "\n";

	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		m_Deck.AdditionalCards(*pPlayer);
	}


	m_House.FlipFirstCard();
	std::cout << "\n" << m_House;

	m_Deck.AdditionalCards(m_House);

	if (m_House.IsBusted())
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			if (!(pPlayer->IsBusted()))
			{
				pPlayer->Win();
			}
		}
	}
	else
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			if (!(pPlayer->IsBusted()))
			{
				if (pPlayer->getHandValue() > m_House.getHandValue())
				{
					pPlayer->Win();
				}
				else if (pPlayer->getHandValue() < m_House.getHandValue())
				{
					pPlayer->Lose();
				}
				else
				{
					pPlayer->Draw();
				}
			}
		}
	}

	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		pPlayer->clearCards();
	}
	m_House.clearCards();
}
