//============================= include section ==============================
#include "Enemy.h"
#include "Wall.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
//============================== gets section ================================
//============================ methods section ===============================
bool Enemy::isFalling(const Board& board){
	if(this->getTrapState())
		if (this->getTrappingWall().getLocation().y < this->getLocation().y)
			return false;
	return this->MovingObject::isFalling(board);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================