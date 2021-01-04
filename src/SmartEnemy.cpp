//============================= include section ==============================
#include "SmartEnemy.h"

//============================= public section ===============================
//==================== Constructors & distructors section ====================

//============================== gets section ================================
//============================ methods section ===============================
void SmartEnemy::draw(sf::RenderWindow& window, const sf::Texture& texture) const {
	sf::Sprite player;
	player.setTexture(texture);
	window.draw(player);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================