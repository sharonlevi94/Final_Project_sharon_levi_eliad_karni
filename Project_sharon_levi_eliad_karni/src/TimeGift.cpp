//============================= include section ==============================
#include "TimeGift.h"
#include "Controller.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
TimeGift::TimeGift(const sf::Vector2f& location,
	const sf::Vector2f& size)
	:Gift(location, size) {
}
//============================ methods section ===============================
/*this method return the object itself to the dynamic object that collided with
this gift for double dispatch.*/
void TimeGift::handleCollision(MovingObject& obj, const sf::Vector2f& movement) {
	obj.handleCollision(*this, movement);
}
//============================================================================
/*this method return the object itself to the controller for double dispatch.*/
void TimeGift::handleColision(Controller& obj){
	obj.handleColision(*this);
}