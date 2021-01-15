//============================= include section ==============================
#include "SmartEnemy.h"
#include "Utilities.h"
#include "Board.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
SmartEnemy::SmartEnemy(const sf::Vector2f location,
		const sf::Vector2f& size )
	:Enemy(location,size,ENEMY_T) {}
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
void SmartEnemy::playTurn(const sf::Time& deltaTime,const  Board& board) {
	//Location moveAns = this->m_location;
	if (this->getLocation().x != board.getPlayerLoc().x) {
		if (this->getLocation().x < board.getPlayerLoc().x)
			this->moveRight(deltaTime, board);
		else
			this->moveLeft(deltaTime, board);
	}
	else{
		if (this->getLocation().y < board.getPlayerLoc().y)
			this->moveUp(deltaTime, board);
		else
			this->moveDown(deltaTime, board);
	}
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================