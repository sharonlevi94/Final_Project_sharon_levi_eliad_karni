//============================= include section ==============================
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "Utilities.h"
#include "Coin.h"
#include "Board.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Player::Player(const sf::Vector2f location,
		const EffectsHolder& effects,
		const sf::Vector2f& size )
	: MovingObject(location,effects,size,PLAYER_T),
	m_lives(NUM_OF_LIFE){

}
//============================ methods section ===============================
void Player::playTurn(const sf::Time& deltaTime,const Board& board) {
	if (this->isFalling(board) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->moveDown(deltaTime, board);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->moveUp(deltaTime, board);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->moveLeft(deltaTime, board);
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->moveRight(deltaTime, board);;
}
//============================================================================
int Player::getLives()const { return m_lives; }
void Player::death(){
	this->m_lives--;
}
//============================================================================
bool Player::is_alive()const{
	if (this->m_lives > 0)
		return true;
	return false;
}
//============================================================================
void Player::handleColision(Player&) {/*ignore*/ }
//============================================================================
void Player::handleColision(Enemy&) { this->m_lives--; }
//============================================================================
void Player::handleColision(GameObject& obj) {
	obj.handleColision(*this);
}
