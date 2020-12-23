#pragma once
#include "StaticObject.h"

class Rod : public StaticObject
{
public:
	Rod();
	virtual void draw();
	virtual char identify()const;
	virtual void playTurn(char (*)(const sf::Vector2f&));
	virtual void reset(const sf::Vector2f&);
	virtual int getState()const;

private:
	sf::Vector2f m_location;
	sf::Vector2f m_size;
	int m_state;
	std::vector<sf::Sprite*> m_sprites;
};
