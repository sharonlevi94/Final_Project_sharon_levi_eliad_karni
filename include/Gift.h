#ifndef _GIFT_H_
#define _GIFT_H_
#pragma once
#include "CollectableObject.h"
class Gift :public CollectableObject
{
public:
	Gift(const sf::Vector2f = sf::Vector2f(0, 0),
		const EffectsHolder & = EffectsHolder(),
		const sf::Vector2f & = sf::Vector2f(0, 0));

	virtual void          playTurn()  override;
private:
};
#endif //_BOARD_H_