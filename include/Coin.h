#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "CollectableObject.h"
using std::vector;

class Coin: public CollectableObject
{
public:
	Coin(const sf::Vector2f location = sf::Vector2f(0, 0),
		const sf::Vector2f size = sf::Vector2f(0, 0),
		int state = 0,
		const sf::Sprite& (*)(char) = nullptr);
	
	virtual void draw() const;
	virtual void playTurn(const GameObject* (*)(const sf::Vector2f&));
	virtual void reset(const sf::Vector2f&);

private:

	virtual void collect();
	virtual void setState(const int);
};