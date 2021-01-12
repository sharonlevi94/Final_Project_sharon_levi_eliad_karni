//============================= include section ==============================
#include "RandEnemy.h"
#include "Board.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
RandEnemy::RandEnemy(const sf::Vector2f location,
	const EffectsHolder& effects,
	const sf::Vector2f& size)
	:Enemy(location, effects, size, ENEMY_T) {}
//============================== gets section ================================
//============================ methods section ===============================
void RandEnemy::playTurn(const sf::Time& deltaTime,const Board& board){
	srand(time(NULL));
	int rand_move =rand()%4;
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
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================
