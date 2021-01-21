//============================ include section ===============================
#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
//========================== forward declarations ============================
class MovingObject;
/*============================================================================
* Class: Door.
* This class represent the door in the game that the gift enemies are created,
* is get out from this door. The door can be load from file or located in 
* specific location in the board.
 */
class Door : public StaticObject
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	Door(const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	virtual ~Door()override = default;
	//=========================== method section =============================
	virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
	//========================= private section ==============================
private:
};