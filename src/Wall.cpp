//============================= include section ==============================
#include "Wall.h"
#include "Utilities.h"
#include "Board.h"
#include <iostream>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Wall::Wall(const sf::Vector2f location, const sf::Vector2f& size )
	: StaticObject(location, size, WALL_T), m_isDigged(false) {}
//============================== gets section ================================
bool Wall::isDigged() const { return this->m_isDigged; }
//============================ methods section ===============================
//============================================================================
void Wall::dig(const sf::Time& deltaTime) {
	if (!this->m_isDigged) {
		this->m_isDigged = true;
		this->m_diggedTime = sf::seconds(0);
	}
}
//============================================================================
void Wall::unDigg(const sf::Time& deltaTime) {
	std::cout << deltaTime.asSeconds() << ' ' << m_diggedTime.asSeconds();
	this->m_diggedTime += deltaTime;
	std::cout << " = " << m_diggedTime.asSeconds() << std::endl ;
	if (this->m_diggedTime.asSeconds() > 5.f)
		this->m_isDigged = false;
}
//============================================================================
void Wall::playTurn(const sf::Time& deltaTime, Board& board) {}
//============================================================================
void Wall::draw(sf::RenderWindow& window, const sf::Time& animationTime) {
	if (!this->m_isDigged)
		GameObject::draw(window, animationTime);
}

void Wall::reset() {
	StaticObject::reset();
	this->m_isDigged = false;
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================