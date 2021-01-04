//============================= include section ==============================
#include "Coin.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
//============================== gets section ================================
//============================ methods section ===============================
void Coin::draw(sf::RenderWindow& window, const sf::Texture& texture) const {
	sf::Sprite coin;
	coin.setTexture(texture);
	window.draw(coin);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================