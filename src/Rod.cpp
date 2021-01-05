//============================= include section ==============================
#include "Rod.h"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
//============================== gets section ================================
//============================ methods section ===============================
void Rod::draw(sf::RenderWindow& window, const sf::Texture& texture) const {
	sf::Sprite rod;
	rod.setTexture(texture);
	rod.setPosition(calcScreenLocation(
		(sf::Vector2f)window.getSize(),
		sf::Vector2f(20, 20),
		this->getLocation()));
	rod.setScale(calcScale((sf::Vector2f)window.getSize(),
		sf::Vector2f(20, 20),
		(sf::Vector2f)rod.getTexture()->getSize()));
	window.draw(rod);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================