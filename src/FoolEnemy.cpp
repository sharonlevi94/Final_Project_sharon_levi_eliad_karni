//============================= include section ==============================
#include "FoolEnemy.h"
#include "Rod.h"
#include "Wall.h"
#include "Board.h"
#include "Ladder.h"
#include <SFML/Graphics.hpp>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
FoolEnemy::FoolEnemy(const sf::Vector2f& location,
	const sf::Vector2f& size)
	:Enemy(location, size, ENEMY_T), m_turn(false) {}
//============================ methods section ===============================
void FoolEnemy::playTurn(const sf::Time& deltaTime, Board& board) {
	if (!this->physicsTurn(deltaTime, board)) {
		if (this->getLookState() == WALK_LEFT)
			this->moveLeft(deltaTime, board);
		else
			this->moveRight(deltaTime, board);
	}
	if (this->m_turn) {
		if (this->getLookState() == WALK_LEFT)
			setLookState(WALK_RIGHT);
		else
			setLookState(WALK_LEFT);
		this->m_turn = false;
	}
}
//============================================================================
void FoolEnemy::handleCollision(Wall& obj, const sf::Vector2f& movement) {
	if (movement.y > 0)
		this->MovingObject::handleCollision(obj, movement);
	this->m_turn = true;
}