//============================= include section ==============================
#include "FoolEnemy.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
FoolEnemy::FoolEnemy(const sf::Vector2f location,
	const EffectsHolder& effects,
	const sf::Vector2f& size)
	:Enemy(location, effects, size, ENEMY_T) {}
//============================== gets section ================================
//============================ methods section ===============================
void FoolEnemy::playTurn(const sf::Time& deltaTime, const Board& board) {
srand(time(NULL));
	int rand_move =rand()%2;
	switch (rand_move)
	{
	case 0:this->moveLeft(deltaTime, board);
		break;
	default: this->moveRight(deltaTime, board);
		break;
	}
}
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================