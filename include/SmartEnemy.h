#pragma once
#include "Enemy.h"
class SmartEnemy: public Enemy
{
public:
	SmartEnemy();
	virtual void draw() const;
	virtual char identify()const;
	virtual void reset(const sf::Vector2f&);
	virtual void playTurn(char (*)(const sf::Vector2f&));
	virtual void fall();

private:
	sf::Vector2f m_location;
	sf::Vector2f m_size;
	int state;
	std::vector<sf::Sprite*> m_sprites;
};