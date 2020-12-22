#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "StaticObjects.h"
using std::vector;

class Coin: public StaticObjects
{
public:
	Coin();
	
	virtual void draw()const;
	virtual void playTurn();
	virtual void reset();
	bool is_collected()const;
	virtual char identify()const;
	void collect();

private:
	int m_state;
	const vector<sf::Sprite*> m_sprites;
	const sf::Vector2f m_Loc;
	const sf::Vector2f m_size;
};

Coin::Coin()
{
}

Coin::~Coin()
{
}