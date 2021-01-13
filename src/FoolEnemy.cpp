//============================= include section ==============================
#include "FoolEnemy.h"
#include "Rod.h"
#include "Wall.h"
#include "Board.h"
#include "Ladder.h"
#include <SFML/Graphics.hpp>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
FoolEnemy::FoolEnemy(const sf::Vector2f location,
	const sf::Vector2f& size)
	:Enemy(location, size, ENEMY_T) {}
//============================== gets section ================================
//============================ methods section ===============================
void FoolEnemy::playTurn(const sf::Time& deltaTime, const Board& board) {
	if (this->getLookState() == LOOK_RIGHT ||
		!(dynamic_cast <Wall*> (board.getContent(this->getBotLeft())) ||
			dynamic_cast <Rod*> (board.getContent(this->getLeft()))) ||
		dynamic_cast <Ladder*> ((board.getContent(this->getLeft())))) {
		this->moveLeft(deltaTime, board);
		this->setLookState(LOOK_RIGHT);
	}
	else {
		this->moveRight(deltaTime, board);
		this->setLookState(LOOK_RIGHT);
	}
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================