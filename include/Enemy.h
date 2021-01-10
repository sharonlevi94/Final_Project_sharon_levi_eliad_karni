#pragma once
#include "MovingObject.h"
#include <SFML/Graphics.hpp>
class Enemy: public MovingObject
{
public:
	using MovingObject::MovingObject;

	bool isCatchedPlayer(const sf::Vector2f&);
	virtual void handleColision(Wall&)override;
	virtual void handleColision(Player&)override;
private:
	 
};