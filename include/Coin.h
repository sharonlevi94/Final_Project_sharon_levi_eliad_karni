//============================= include section ==============================
#pragma once
#include <SFML/Graphics.hpp>
#include "CollectableObject.h"
//========================== forward declarations ============================
/*============================================================================
 * This class represent the coin object and derived from CollectableObject. 
 */
 class Coin: public CollectableObject
{
public:
//================= constractors and destractors section =================
	Coin(const sf::Vector2f& = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0));
	virtual ~Coin()override;
//=========================== method section =============================
virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
	static unsigned int getCoinsCounter();
	virtual void reset()override;
	virtual void collect()override;
//====================== privete methods section =========================
private:
//========================= members section ==============================
static unsigned int m_coinsCounter;
};

