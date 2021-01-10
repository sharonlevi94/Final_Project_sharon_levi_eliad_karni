//============================= include section ==============================
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Player::Player(const sf::Vector2f location,
		const EffectsHolder& effects,
		const sf::Vector2f& size )
	: MovingObject(location,effects,size,PLAYER_T) {}
//============================== gets section ================================

//============================ methods section ===============================
/*void Player::draw(sf::RenderWindow& window) const {
	window.draw(this->getSprite());
}*/
//============================================================================
void Player::playTurn(sf::Time deltaTime) {
	const auto SpeedPerSecond = 250.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
		//only to ledder
		this->setLocation(sf::Vector2f(0, -1)*SpeedPerSecond*deltaTime.asSeconds());
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->setLocation(sf::Vector2f(-1, 0) * SpeedPerSecond * deltaTime.asSeconds());
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->setLocation(sf::Vector2f(1, 0) * SpeedPerSecond * deltaTime.asSeconds());
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->setLocation(sf::Vector2f(0, 1) * SpeedPerSecond * deltaTime.asSeconds());
}
//============================================================================
//============================================================================
//============================ private section ===============================
//============================== sets section ================================
//============================ methods section ===============================