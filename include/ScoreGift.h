//============================ include section ===============================
#pragma once
#include "Gift.h"
//========================== forward declarations ============================
class Controller;
/*============================================================================*/
class ScoreGift : public Gift
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	ScoreGift(const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	//=========================== method section ==============================
	virtual void handleColision(Controller&)override;
	virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
	//========================= private section ===============================
private:
};
