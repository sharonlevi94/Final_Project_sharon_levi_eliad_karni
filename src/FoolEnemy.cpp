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
	/*
	if (this->isFalling(board))
		this->moveDown(deltaTime, board);
	else {
		if (this->getLookState() == LOOK_LEFT) {
			if ((dynamic_cast <Wall*> (board.getContent(this->getLeft())))) {
				this->moveRight(deltaTime, board);
				this->setLookState(LOOK_RIGHT);
			}
			else
				this->moveLeft(deltaTime, board);
		}
		else {
			if ((dynamic_cast <Wall*> (board.getContent(this->getRight())))) {
				this->moveLeft(deltaTime, board);
				this->setLookState(LOOK_LEFT);
			}
			else
				this->moveRight(deltaTime, board);
		}
	}
	*/
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================