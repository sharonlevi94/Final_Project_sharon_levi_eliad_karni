//============================= include section ==============================
#include "RandEnemy.h"
#include "Board.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
RandEnemy::RandEnemy(const sf::Vector2f& location,
	const sf::Vector2f& size)
	:Enemy(location, size, ENEMY_T), m_rand_move(rand() % 4),
	m_randTime(sf::seconds(0)){}
//============================== gets section ================================
//============================ methods section ===============================
void RandEnemy::playTurn(const sf::Time& deltaTime, Board& board){
	if (!this->physicsTurn(deltaTime, board)) {
		//every level has its own rands at the controller
		this->m_randTime += deltaTime;
		if (m_randTime.asSeconds() >= RAND_ENEMY_TIME) {
			this->m_randTime = sf::seconds(0);
			this->m_rand_move = rand() % 4;
		}
		switch (this->m_rand_move)
		{
		case 0:
			this->moveUp(deltaTime, board);
			break;
		case 1:
			this->moveLeft(deltaTime, board);
			break;
		case 2: 
			this->moveRight(deltaTime, board);
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
