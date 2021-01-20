//============================= include section ==============================
#include "Wall.h"
#include "Utilities.h"
#include "Board.h"
#include "MovingObject.h"
#include <iostream>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Wall::Wall(const sf::Vector2f& location, const sf::Vector2f& size )
	: StaticObject(location, size, WALL_T), m_isDigged(false), 
	m_isTrapping(false) {}
//============================== gets section ================================
bool Wall::isDigged() const { return this->m_isDigged; }
//============================ methods section ===============================
//============================================================================
void Wall::dig(const sf::Time& deltaTime) {
	if (!this->m_isDigged) {
		this->m_isDigged = true;
		this->m_isTrapping = false;
		this->m_diggedTime = sf::seconds(0);
	}
}
//============================================================================
void Wall::unDigg(const sf::Time& deltaTime) {
	this->m_diggedTime += deltaTime;
	if (this->m_diggedTime.asSeconds() > 3.f) {
		this->m_isDigged = false;
		this->m_isTrapping = false;
	}
}
//============================================================================
bool Wall::getTrappingState()const { return this->m_isTrapping; }
//============================================================================
void Wall::changeTrapMode(bool mode) { this->m_isTrapping = mode; }
//============================================================================
void Wall::draw(sf::RenderWindow& window, const sf::Time& animationTime) {
	if (!this->m_isDigged)
		GameObject::draw(window, animationTime);
}
//============================================================================
void Wall::reset() {
	StaticObject::reset();
	this->m_isDigged = false;
	this->m_isTrapping = false;
	this->m_diggedTime.Zero;
}
//============================================================================
void Wall::handleCollision(MovingObject& obj, const sf::Vector2f& movement) {
	obj.handleCollision(*this, movement);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================