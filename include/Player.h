#pragma once
#include "MovingObject.h"
class Player : public MovingObject
{
public:
	Player();
	virtual void draw() const;
	virtual char identify()const;
	virtual void reset(const sf::Vector2f&);
	virtual void playTurn(char (*)(const sf::Vector2f&));
	int receive_command()const;
	virtual void fall();

private:
	sf::Vector2f m_location;
	sf::Vector2f m_size;
	int state;
	std::vector<sf::Sprite*> m_sprites;
};