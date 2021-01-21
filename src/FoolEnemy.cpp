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
/*this method manage the movement of the fool enemy. He can move only to right
direction or to the left direction.*/
void FoolEnemy::playTurn(const sf::Time& deltaTime, Board& board) {
	if (!this->physicsTurn(deltaTime, board)) {
		if (this->getLookState() == WALK_LEFT)
			this->moveLeft(deltaTime, board);
		else
			this->moveRight(deltaTime, board);
	}
}
//============================================================================
/*this method handle a colision of the fool enemy with wall or floor.
if the fool enemy collides with a wall from right he start to walk left.
if the fool enemy collides with a wall from left he start to walk right.*/
void FoolEnemy::handleCollision(Wall& obj, const sf::Vector2f& movement) {
	if (movement.y > 0)
		this->MovingObject::handleCollision(obj, movement);
	if (this->getLookState() == WALK_LEFT)
		this->setLookState(WALK_RIGHT);
	else
		this->setLookState(WALK_LEFT);
}