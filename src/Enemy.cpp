//============================= include section ==============================
#include "Enemy.h"
#include "Wall.h"
//============================ methods section ===============================
bool Enemy::physicsTurn(const sf::Time& deltaTime, Board& board) {
	if (this->getTrapState() && this->getTrappingWall().isDigged())
		if (this->getLocation().y >= this->getTrappingWall().getLocation().y)
			return true;
	return this->MovingObject::physicsTurn(deltaTime, board);
}