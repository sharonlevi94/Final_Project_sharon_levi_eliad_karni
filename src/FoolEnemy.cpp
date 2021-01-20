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
	:Enemy(location, size, ENEMY_T) {}
//============================== gets section ================================
//============================ methods section ===============================
void FoolEnemy::playTurn(const sf::Time& deltaTime, Board& board) {
	if (!this->physicsTurn(deltaTime, board)) {
		if (this->getLookState() == LOOK_LEFT)
			this->moveLeft(deltaTime, board);
		else
			this->moveRight(deltaTime, board);
	}
}
//============================================================================
void FoolEnemy::handleCollision(Wall& obj, const sf::Vector2f& movement) {
	if (movement.y > 0)
		this->MovingObject::handleCollision(obj, movement);
	if (this->getLookState() == LOOK_LEFT)
		this->setLookState(LOOK_RIGHT);
	else
		this->setLookState(LOOK_LEFT);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================