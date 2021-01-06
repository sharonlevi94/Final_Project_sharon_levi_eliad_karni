//============================= include section ==============================
#include "Coin.h"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
//============================== gets section ================================
//============================ methods section ===============================
void Coin::draw(sf::RenderWindow& window, const sf::Texture& texture) const {
	sf::Sprite coin;
	coin.setTexture(texture);
	coin.setPosition(calcScreenLocation(
		(sf::Vector2f)window.getSize(),
		sf::Vector2f(20, 20),
		this->getLocation()));
	coin.setScale(calcScale((sf::Vector2f)window.getSize(),
		sf::Vector2f(20, 20),
		(sf::Vector2f)coin.getTexture()->getSize()));
	window.draw(coin);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================