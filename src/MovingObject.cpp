//============================= include section ==============================
#include "MovingObject.h"
#include <SFML/Graphics.hpp>
//============================= public section ===============================
//==================== Constructors & distructors section ====================

//============================== gets section ================================
//============================ methods section ===============================

//============================ private section ===============================
//============================== gets section ================================
//============================== sets section ================================
//============================================================================
void MovingObject::setLocation(const sf::Vector2f& movement,
const sf::Vector2f& areaSize){
	if (this->moveIsPossible(movement, areaSize))
		this->GameObject::setLocation(movement);
}
//============================================================================
bool MovingObject::moveIsPossible(const sf::Vector2f& movement,
const sf::Vector2f& areaSize) const {
	return (areaSize.x >
		movement.x + this->getLocation().x + this->getSize().x
		&& movement.x + this->getLocation().x > 0 &&
		areaSize.y > movement.y + this->getLocation().y + this->getSize().y
		&& 0 <= movement.y + this->getLocation().y);
}
//============================ methods section ===============================