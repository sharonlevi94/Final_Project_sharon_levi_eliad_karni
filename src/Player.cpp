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
void Player::playTurn(const Board& board) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&
		board.getLocation().y <= this->getLocation().y - 1)
		this->setLocation(sf::Vector2f(0, -1));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
		board.getLocation().x <= this->getLocation().x -1)
		this->setLocation(sf::Vector2f(-1, 0));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&
		board.getLocation().x + board.getlevelSize().x >=
		this->getLocation().x + 1)
		this->setLocation(sf::Vector2f(1, 0));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
		board.getLocation().y + board.getlevelSize().y >=
		this->getLocation().y + 1)
		this->setLocation(sf::Vector2f(0, 1));
}
//============================================================================
//============================ private section ===============================
//============================== sets section ================================
//============================ methods section ===============================