#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class GameObjects
{
public:
	GameObjects();
	virtual void draw()const;
	virtual char identify()const;
	virtual void playTurn();
	virtual void reset(const sf::Vector2f&);

private:
	sf::Vector2f m_location;
	sf::Vector2f m_size;
	int state;
	vector<sf::Sprite*> m_sprites;
};