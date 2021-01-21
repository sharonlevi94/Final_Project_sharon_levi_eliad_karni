//============================= include section ==============================
#include "Ladder.h"
#include "Utilities.h"
#include "MovingObject.h"
#include <SFML/Graphics.hpp>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Ladder::Ladder(const sf::Vector2f& location,
		const sf::Vector2f& size)
	: StaticObject(location ,size, LADDER_T) {}
//============================== gets section ================================
//============================ methods section ===============================
/*this method return the object itself to the dynamic object that collided with
this ladder for double dispatch.*/
void Ladder::handleCollision(MovingObject& obj, const sf::Vector2f& movement) {
	obj.handleCollision(*this, movement);
}