//============================= include section ==============================
#include "SmartEnemy.h"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================

//============================== gets section ================================
//============================ methods section ===============================
void SmartEnemy::draw(sf::RenderWindow& window, const sf::Texture& texture) const {
	sf::Sprite smart_enemy;
	smart_enemy.setTexture(texture);

	smart_enemy.setPosition(calcScreenLocation(
		(sf::Vector2f)window.getSize(),
		sf::Vector2f(20, 20),
		this->getLocation()));

	smart_enemy.setScale(calcScale((sf::Vector2f)window.getSize(),
		sf::Vector2f(20, 20),
		(sf::Vector2f)smart_enemy.getTexture()->getSize()));
	window.draw(smart_enemy);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================