#pragma once
#include "CollectableObject.h"
class Gift :public CollectableObject
{
public:
	Gift(const sf::Vector2f& location);
	virtual void playTurn(const sf::Time&, const Board&)override;
};