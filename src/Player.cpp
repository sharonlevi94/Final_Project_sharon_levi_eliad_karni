//============================= include section ==============================
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "Utilities.h"
#include "Board.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Player::Player(const sf::Vector2f location,
		const sf::Vector2f& size)
	: MovingObject(location,size,PLAYER_T){

}
//============================ methods section ===============================
void Player::playTurn(const sf::Time& deltaTime,const Board& board) {
	if (this->isFalling(board) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->moveDown(deltaTime, board);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->moveUp(deltaTime, board);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->moveLeft(deltaTime, board);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->moveRight(deltaTime, board);;
}
//============================================================================