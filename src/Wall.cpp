//============================= include section ==============================
#include "Wall.h"
#include "Utilities.h"
#include "Board.h"
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
	this->m_diggedTime += deltaTime;
	sf::Time a = sf::seconds(5);
	if (this->m_diggedTime.asSeconds() > a.asSeconds())
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