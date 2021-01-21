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
//============================ methods section ===============================
void FoolEnemy::playTurn(const sf::Time& deltaTime, Board& board) {
	if (!this->physicsTurn(deltaTime, board)) {
		if (this->getLookState() == WALK_LEFT)
			this->moveLeft(deltaTime, board);
		else
			this->moveRight(deltaTime, board);
	}
}
//============================================================================
void FoolEnemy::handleCollision(Wall& obj, const sf::Vector2f& movement) {
	if (movement.y > 0)
		this->MovingObject::handleCollision(obj, movement);
	if (this->getLookState() == WALK_LEFT)
		this->setLookState(WALK_RIGHT);
	else
		this->setLookState(WALK_LEFT);
}