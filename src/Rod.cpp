//============================= include section ==============================
#include "Rod.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
//============================== gets section ================================
//============================ methods section ===============================
void Rod::draw(sf::RenderWindow& window, const sf::Texture& texture) const {
	sf::Sprite rod;
	rod.setTexture(texture);
	rod.setPosition(this->getLocation());
	window.draw(rod);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================