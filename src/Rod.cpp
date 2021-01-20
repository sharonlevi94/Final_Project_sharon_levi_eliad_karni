//============================= include section ==============================
#include "Rod.h"
#include "Utilities.h"
#include "Board.h"
#include "MovingObject.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Rod::Rod(const sf::Vector2f& location,
		const sf::Vector2f& size )
	: StaticObject(location, size, ROD_T) {}
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
void Rod::handleCollision(MovingObject& obj, const sf::Vector2f& movement) {
	obj.handleCollision(*this, movement);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================