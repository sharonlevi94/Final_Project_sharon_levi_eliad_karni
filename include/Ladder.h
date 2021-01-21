#pragma once
//============================ include section ===============================
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
//========================== forward declarations ============================
class MovingObject;
/*============================================================================
* Class: Ladder.
* This class derived from StaticObject class and reprsent the ladders in the 
* game.
 ============================================================================*/
class Ladder: public StaticObject
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	Ladder(const sf::Vector2f & = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0));
	//=========================== method section ==============================
	virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
	//========================= private section ===============================
private:
};