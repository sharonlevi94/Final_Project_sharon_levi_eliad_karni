#pragma once
#include "MovingObject.h"
#include <SFML/Graphics.hpp>
class Enemy: public MovingObject
{
public:
	Enemy(const sf::Vector2f location,
		const sf::Vector2f size,
		int state,
		const sf::Sprite& (*)(char),
		char type);

	bool isCatchedPlayer(const sf::Vector2f&);
private:
	 
};