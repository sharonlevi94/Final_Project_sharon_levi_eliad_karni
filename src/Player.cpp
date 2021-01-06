//============================= include section ==============================
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Player::Player(const sf::Vector2f& location ,
	const EffectsHolder& effects)
	: MovingObject(location,effects,PLAYER_T) {}
//============================== gets section ================================

//============================ methods section ===============================
void Player::draw(sf::RenderWindow& window) const {
	window.draw(this->getSprite());
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