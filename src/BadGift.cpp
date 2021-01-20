//============================= include section ==============================
#include "BadGift.h"
#include "Macros.h"
#include "MovingObject.h"
#include "EffectsHolder.h"
#include "Utilities.h"
#include "Controller.h"
class Controller;
//============================= public section ===============================
//==================== Constructors & distructors section ====================
BadGift::BadGift(const sf::Vector2f& location,
	const sf::Vector2f& size)
	:Gift(location, size) {
}
//============================ methods section ===============================
void BadGift::handleColision(Controller& controller) {
	controller.handleColision(*this);
}
//============================================================================
void BadGift::handleCollision(MovingObject& obj, const sf::Vector2f& movement) {
	obj.handleCollision(*this, movement);
}
//============================================================================