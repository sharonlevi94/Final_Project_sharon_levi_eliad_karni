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
void MovingObject::setLocation(const sf::Vector2f& newLocation) {
	this->m_currentLocation = newLocation;
}
//============================ methods section ===============================