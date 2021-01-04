//============================= include section ==============================
#include "Ladder.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
//============================== gets section ================================
//============================ methods section ===============================
void Ladder::draw(sf::RenderWindow& window, const sf::Texture& texture) const {
	sf::Sprite ladder;
	ladder.setTexture(texture);
	ladder.setPosition(this->getLocation());
	window.draw(ladder);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================