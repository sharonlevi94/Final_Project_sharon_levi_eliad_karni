//============================= include section ==============================
#include "Door.h"
#include "Utilities.h"
#include "MovingObject.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Door::Door(const sf::Vector2f location,
	const sf::Vector2f& size)
	: StaticObject(location, size, DOOR_T) {}
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
void Door::handleCollision(MovingObject& obj, const sf::Vector2f& movement) {
	obj.handleCollision(*this, movement);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================