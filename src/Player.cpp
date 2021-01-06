//============================= include section ==============================
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================

//============================== gets section ================================

//============================ methods section ===============================
void Player::draw(sf::RenderWindow& window,const sf::Texture& texture) const {
	sf::Sprite player;
	player.setTexture(texture);

	player.setPosition(calcScreenLocation(
		(sf::Vector2f)window.getSize(),
		sf::Vector2f(20, 20),
		this->getLocation()));

	player.setScale(calcScale((sf::Vector2f)window.getSize(),
		sf::Vector2f(20, 20),
		(sf::Vector2f)player.getTexture()->getSize()));

	window.draw(player);
}
//============================================================================
void Player::playTurn() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

	}
}
//============================================================================
//============================ private section ===============================
//============================== sets section ================================
//============================ methods section ===============================