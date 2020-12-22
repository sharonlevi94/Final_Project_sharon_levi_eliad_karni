#pragma once
#include "MovingObjects.h"
#include <SFML/Graphics.hpp>
class Enemy: public MovingObjects
{
public:
	Enemy();
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