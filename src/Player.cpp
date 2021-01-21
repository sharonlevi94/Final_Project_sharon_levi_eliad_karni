//============================= include section ==============================
#include "Player.h" 
#include "SFML/Graphics.hpp"
#include "Utilities.h"
#include "Board.h"
#include "Wall.h"
#include "Macros.h"
#include "ResoucesHolder.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Player::Player(const sf::Vector2f& location,
		const sf::Vector2f& size)
	: MovingObject(location, size, PLAYER_T), m_diggedWalls({}) {}
//============================ methods section ===============================
/*this method manage the movements of the player. the method realize if the 
user pressed on key and move the player by the key that user pressed if the
move is possible.*/
void Player::playTurn(const sf::Time& deltaTime, Board& board) {
	if (!this->physicsTurn(deltaTime, board)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			this->moveDown(deltaTime, board);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			dig(board, this->getBotRight(), deltaTime);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			dig(board, this->getBotLeft(), deltaTime);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			this->moveUp(deltaTime, board);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			this->moveLeft(deltaTime, board);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			this->moveRight(deltaTime, board);
		else {
			if (this->getState() == RUNNING)
				this->setState(STAND);
			else {
				this->resetAnimationTime();
				updateAnimation(sf::seconds(0));
			}
		}
	}
	updateDiggedWalls(deltaTime);
}
//============================================================================
/*This method execute the digging action that made by the user, it communicate
with the board and digg the right wall.*/
void Player::dig(Board& board, const sf::Vector2f& location, 
	const sf::Time& deltatime) {
	if (board.getContent(location) == board.getContent(this->getBelow()))
		return;
	if (dynamic_cast <Wall*> (board.getContent(location))) {
		if (!((Wall*)(board.getContent(location)))->isDigged()) {
			this->m_diggedWalls.push_back((Wall*)board.getContent(location));
			((Wall*)(board.getContent(location)))->dig(deltatime);
			ResoucesHolder::instance().playSound(DIGGING_SOUND);
		}
	}
}
//============================================================================
/*This method update the vector of the digged walls by the time passed.*/
void Player::updateDiggedWalls(const sf::Time& deltaTime) {
	for (int i = 0; i < this->m_diggedWalls.size(); ++i) {
		this->m_diggedWalls[i]->unDigg(deltaTime);
		if(!this->m_diggedWalls[i]->isDigged())
			this->m_diggedWalls.erase(this->m_diggedWalls.begin() + i);
	}
}