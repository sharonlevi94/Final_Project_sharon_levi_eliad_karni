//============================= include section ==============================
#include "ScoreGift.h"
#include "Macros.h"
#include "Controller.h"
#include "MovingObject.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
ScoreGift::ScoreGift(const sf::Vector2f& location,
	const sf::Vector2f& size)
	:Gift(location, size) {
}
//============================ methods section ===============================
//============================================================================
void ScoreGift::handleCollision(MovingObject& obj, 
	const sf::Vector2f& movement) {
	obj.handleCollision(*this, movement);
}
//============================================================================
void ScoreGift::handleColision(Controller& obj) {
	obj.handleColision(*this);
}