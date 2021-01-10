//============================= include section ==============================
#include "MovingObject.h"
#include <SFML/Graphics.hpp>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
MovingObject::MovingObject(const sf::Vector2f location,
	const EffectsHolder& effects,
	const sf::Vector2f& size)
	: GameObject(location, effects, size, PLAYER_T),
      m_lastLocation(location){}
//============================== gets section ================================
const sf::Vector2f& MovingObject::getLastLocation()const {
	return this->m_lastLocation;
}
//============================ methods section ===============================

//============================ private section ===============================
//============================== gets section ================================
//============================== sets section ================================
//============================================================================
void MovingObject::setLocation(const sf::Vector2f& movement){
	this->GameObject::setLocation(movement);
}
//============================================================================
void MovingObject::setLastLocation() {
	m_lastLocation = this->getLocation();
}
//============================ methods section ===============================