//============================= include section ==============================
#include "RandEnemy.h"
#include "Board.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
RandEnemy::RandEnemy(const sf::Vector2f location,
	const sf::Vector2f& size)
	:Enemy(location, size, ENEMY_T) {}
//============================== gets section ================================
//============================ methods section ===============================
void RandEnemy::playTurn(const sf::Time& deltaTime, Board& board){
	if (!this->MovingObject::physicsTurn(deltaTime, board)) {
		srand((unsigned int)time(NULL));
		int rand_move = rand() % 4;
		switch (rand_move)
		{
		case 0:this->moveUp(deltaTime, board);
			break;
		case 1:this->moveLeft(deltaTime, board);
			break;
		case 2: this->moveRight(deltaTime, board);
			break;
		default:
			this->moveDown(deltaTime, board);
			break;
		}
	}
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================
