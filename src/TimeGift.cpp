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
void TimeGift::handleCollision(MovingObject& obj, const sf::Vector2f& movement) {
	obj.handleCollision(*this, movement);
}
//============================================================================
void TimeGift::handleColision(Controller& obj){
	obj.handleColision(*this);
}