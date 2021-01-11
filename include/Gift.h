#pragma once
#include "CollectableObject.h"
class Gift :public CollectableObject
{
public:
	Gift(const sf::Vector2f& location,
		const EffectsHolder& effects);
	virtual void playTurn(const sf::Time&, const Board&)override;
};