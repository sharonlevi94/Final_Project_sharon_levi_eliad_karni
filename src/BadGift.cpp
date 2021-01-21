//============================= include section ==============================
#include "BadGift.h"
#include "Macros.h"
#include "MovingObject.h"
#include "ResoucesHolder.h"
#include "Utilities.h"
#include "Controller.h"
//========================== forward declarations ============================
class Controller;
//============================= public section ===============================
//==================== Constructors & distructors section ====================
BadGift::BadGift(const sf::Vector2f& location,
	const sf::Vector2f& size)
	:Gift(location, size) {
}
//============================ methods section ===============================
/*this method return the object itself to the controller for double dispatch.*/
void BadGift::handleColision(Controller& controller) {
	controller.handleColision(*this);
}
//============================================================================
/*this method return the object itself to the dynamic object that collided with  
this gift for double dispatch.*/
void BadGift::handleCollision(MovingObject& obj, const sf::Vector2f& movement) {
	obj.handleCollision(*this, movement);
}
//============================================================================