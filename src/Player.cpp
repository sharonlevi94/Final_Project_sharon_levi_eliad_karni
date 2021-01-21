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
void Player::playTurn(const sf::Time& deltaTime, Board& board) {
	if (!this->physicsTurn(deltaTime, board)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			this->moveDown(deltaTime, board);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			dig(board, this->getBotRight(), deltaTime);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			dig(board, this->getBotLeft(), deltaTime);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			this->moveUp(deltaTime, board);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			this->moveLeft(deltaTime, board);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			this->moveRight(deltaTime, board);
	}
	//EffectsHolder::instance().playSound(STEP_SOUND);
	updateDiggedWalls(deltaTime);
}
//============================================================================
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
void Player::updateDiggedWalls(const sf::Time& deltaTime) {
	for (int i = 0; i < this->m_diggedWalls.size(); ++i) {
		this->m_diggedWalls[i]->unDigg(deltaTime);
		if(!this->m_diggedWalls[i]->isDigged())
			this->m_diggedWalls.erase(this->m_diggedWalls.begin() + i);
	}
}