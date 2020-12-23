#pragma once
#include <SFML/graphics.hpp>
class GameState
{
public:
	GameState          ();

	void draw          ();
	void levelup       ();
	void collectedCoin ();
	void died          ();

private:
	sf::Vector2f     m_size;
	sf::Vector2f m_location;
	sf::Time        m_clock;
	int             m_level;
	int             m_score;
	int             m_lifes;
};