//============================= include section ==============================
#include "SmartEnemy.h"
#include "Utilities.h"
#include "Board.h"
#include "Ladder.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
SmartEnemy::SmartEnemy(const sf::Vector2f location,
		const sf::Vector2f& size )
	:Enemy(location,size,ENEMY_T) {}
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
void SmartEnemy::playTurn(const sf::Time& deltaTime, Board& board) {
	if (!this->MovingObject::physicsTurn(deltaTime, board)) {
		//the enemy is above player:	
		if ((this->getCenter().y < board.getPlayerLoc().y &&
			dynamic_cast <Ladder*> (board.getContent(this->getBelow())) &&
			board.isMovePossible(this->getBelow())))
			this->moveDown(deltaTime, board);
		//enemy is below player:
		else if (this->getLocation().y > board.getPlayerLoc().y &&
			dynamic_cast <Ladder*> (board.getContent(this->getCenter())) &&
			board.isMovePossible(this->getAbove()))
			this->moveUp(deltaTime, board);
		//enemy is in the same line and right to player:
		else if (this->getLocation().x > board.getPlayerLoc().x)
			this->moveLeft(deltaTime, board);
		//enemy is in the same line and left to player:
		else
			this->moveRight(deltaTime, board);
	}
}
