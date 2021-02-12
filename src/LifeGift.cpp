//============================= include section ==============================
#include "LifeGift.h"
#include "Macros.h"
#include "Controller.h"
#include "MovingObject.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
LifeGift::LifeGift(const sf::Vector2f& location,
	const sf::Vector2f& size)
	:Gift(location, size) {}
//============================ methods section ===============================
/*this method return the object itself to the controller for double dispatch.*/
void LifeGift::handleColision(Controller& obj) {
	obj.handleColision(*this);
}
//============================================================================
/*this method return the object itself to the dynamic object that collided with
this gift for double dispatch.*/
void LifeGift::handleCollision(MovingObject& obj, 
	const sf::Vector2f& movement) {
	obj.handleCollision(*this, movement);
}