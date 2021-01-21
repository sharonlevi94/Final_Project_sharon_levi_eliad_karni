//============================= include section ==============================
#include "SmartEnemy.h"
#include "Utilities.h"
#include "Board.h"
#include "Ladder.h"
#include "Rod.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
SmartEnemy::SmartEnemy(const sf::Vector2f& location,
		const sf::Vector2f& size )
	:Enemy(location,size,ENEMY_T) {}
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
/*this method manage the movements of the smart enemy. the method get the 
delta time of the movment & the board. the method check where is the enemy
exist in a relate to the location of the player and move to the direction 
of the player.*/
void SmartEnemy::playTurn(const sf::Time& deltaTime, Board& board) {
	if (!this->physicsTurn(deltaTime, board)) {
		//the enemy is above player:	
		if ((this->getCenter().y < board.getPlayerLoc().y &&
			(dynamic_cast <Ladder*> (board.getContent(this->getBelow()))) &&
			board.isMovePossible(this->getBelow())))
			this->moveDown(deltaTime, board);
		//enemy is below player:
		else if (this->getLocation().y > board.getPlayerLoc().y &&
			dynamic_cast <Ladder*> (board.getContent(this->getCenter())) &&
			board.isMovePossible(this->getAbove()))
			this->moveUp(deltaTime, board);
		//enemy is in the same line and right to player:
		//(in 1 pixel accuration)
		else if (this->getLocation().x - 1 > board.getPlayerLoc().x)
			this->moveLeft(deltaTime, board);
		//enemy is in the same line and left to player:
		//(in 2 pixels accuration)
		else if (this->getLocation().x + 1 < board.getPlayerLoc().x)
			this->moveRight(deltaTime, board);
		else
			this->setState(STAND);
	}
}
