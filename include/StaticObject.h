#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
class StaticObject : public GameObjects
{
public:
	StaticObject();
	virtual void draw();
	virtual char identify()const;
	virtual void playTurn(char (*)(const sf::Vector2f&));
	virtual void reset(const sf::Vector2f&);
	virtual int getState();

private:
	sf::Vector2f m_location;
	sf::Vector2f m_size;
	int m_state;
	std::vector<sf::Sprite*> m_sprites;
};
