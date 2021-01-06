//============================= include section ==============================
#include "Ladder.h"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
//============================== gets section ================================
//============================ methods section ===============================
void Ladder::draw(sf::RenderWindow& window, const sf::Texture& texture) const {
	sf::Sprite ladder;
	ladder.setTexture(texture);
	ladder.setPosition(calcScreenLocation(
		(sf::Vector2f)window.getSize(),
		sf::Vector2f(20, 20),
		this->getLocation()));
	ladder.setScale(calcScale((sf::Vector2f)window.getSize(),
		sf::Vector2f(20, 20),
		(sf::Vector2f)ladder.getTexture()->getSize()));
	window.draw(ladder);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================