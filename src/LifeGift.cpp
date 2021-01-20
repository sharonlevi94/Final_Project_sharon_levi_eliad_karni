//============================= include section ==============================
#include "LifeGift.h"
#include "Macros.h"
#include "Controller.h"
#include "MovingObject.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
LifeGift::LifeGift(const sf::Vector2f& location,
	const sf::Vector2f& size)
	:Gift(location, size) {
}
//============================ methods section ===============================
//============================================================================
void LifeGift::handleColision(Controller& obj) {
	obj.handleColision(*this);
}
//============================================================================
void LifeGift::handleCollision(MovingObject& obj, 
	const sf::Vector2f& movement) {
	obj.handleCollision(*this, movement);
}