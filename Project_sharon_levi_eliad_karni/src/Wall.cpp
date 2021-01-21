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
/*This method handle in case of player dig this wall object. the method 
set true if the wall is not digged and set false on traping because there is 
nobody in the trap, then the method reset the time of digging.*/
void Wall::dig(const sf::Time& deltaTime) {
	if (!this->m_isDigged) {
		this->m_isDigged = true;
		this->m_isTrapping = false;
		this->m_diggedTime = sf::seconds(0);
	}
}
//============================================================================
/*This method change the state of the wall to undigged after 3 seconds.*/
void Wall::unDigg(const sf::Time& deltaTime) {
	this->m_diggedTime += deltaTime;
	if (this->m_diggedTime.asSeconds() > DIGG_DURATION) {
		this->m_isDigged = false;
		this->m_isTrapping = false;
	}
}
//============================================================================
bool Wall::getTrappingState()const { return this->m_isTrapping; }
//============================================================================
void Wall::changeTrapMode(bool mode) { this->m_isTrapping = mode; }
//============================================================================
void Wall::draw(sf::RenderWindow& window) {
	if (!this->m_isDigged)
		GameObject::draw(window);
}
//============================================================================
/*This method reset all the states of the wall*/
void Wall::reset() {
	StaticObject::reset();
	this->m_isDigged = false;
	this->m_isTrapping = false;
	this->m_diggedTime.Zero;
}
//============================================================================
/*this method return the object itself to the dynamic object that collided with
this wall or floor for double dispatch.*/
void Wall::handleCollision(MovingObject& obj, const sf::Vector2f& movement) {
	obj.handleCollision(*this, movement);
}