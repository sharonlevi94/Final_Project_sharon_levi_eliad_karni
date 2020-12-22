#pragma once
#include "MovingObjects.h"
class Player : public MovingObjects
{
public:
	Player();
	virtual void draw()const;
	virtual char identify()const;
	virtual void playTurn();
	virtual void reset(const sf::Vector2f&);
	int receive_command()const;

private:
	sf::Vector2f m_location;
	sf::Vector2f m_size;
	int state;
	vector<sf::Sprite*> m_sprites;
};