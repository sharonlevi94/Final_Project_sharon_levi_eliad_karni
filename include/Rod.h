//============================ include section ===============================
#pragma once
#include "StaticObject.h"
/*============================================================================*/
class Rod : public StaticObject
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	Rod(const sf::Vector2f & = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0));
	//=========================== method section ==============================
	virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
	//========================= private section ===============================
private:
};