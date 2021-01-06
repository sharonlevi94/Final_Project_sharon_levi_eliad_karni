//============================= include section ==============================
#include "Wall.h"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
//============================== gets section ================================
//============================ methods section ===============================
void Wall::draw(sf::RenderWindow& window, const sf::Texture& texture) const {
	sf::Sprite wall;
	wall.setTexture(texture);
	wall.setPosition(calcScreenLocation(
		(sf::Vector2f)window.getSize(),
		sf::Vector2f(20, 20),
		this->getLocation()));
	
	wall.setScale(calcScale((sf::Vector2f)window.getSize(),
		sf::Vector2f(20,20),
		(sf::Vector2f)wall.getTexture()->getSize()));
	
	window.draw(wall);
}
//----------------------------------------------------------------------------
void Wall::dig(){}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================