#pragma once
#include "CollectableObject.h"
class Gift :public CollectableObject
{
public:
	Gift(const sf::Vector2f = sf::Vector2f(0, 0),
		const EffectsHolder & = EffectsHolder(),
		const sf::Vector2f & = sf::Vector2f(0, 0));

	virtual void          playTurn(const Board&)  override;
private:
};