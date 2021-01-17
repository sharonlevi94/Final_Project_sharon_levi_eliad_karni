//============================= include section ==============================
#include "MovingObject.h"
#include "Board.h"
#include "Ladder.h"
#include "Wall.h"
#include "Rod.h"
#include <SFML/Graphics.hpp>

//============================= public section ===============================
//==================== Constructors & distructors section ====================
MovingObject::MovingObject(const sf::Vector2f location,
	const sf::Vector2f& size,
	char objectType)
	: GameObject(location, size, objectType),
	m_initialLoc(location), m_lookingState(LOOK_STRAIGHT) {}
//============================== gets section ================================
//============================================================================
sf::Vector2f MovingObject::getInitialLoc()const { return this->m_initialLoc; }
//============================================================================
int MovingObject::getLookState()const { return this->m_lookingState; }
//============================ methods section ===============================
//============================================================================
void MovingObject::moveUp(const sf::Time& deltaTime, Board& board){
	if (board.isMovePossible(this->getAbove())){
		GameObject* below = board.getContent(this->getBelow() + 
			sf::Vector2f(0, -2));
		GameObject* above = board.getContent(this->getAbove() +
			sf::Vector2f(0, 1));
		if (dynamic_cast <Ladder*> (below) || 
			dynamic_cast <Ladder*> (above)) {
			if (!dynamic_cast <Ladder*> (below))
				below = above;
			if(board.isMovePossible(this->getLocation() + sf::Vector2f(0, -1)
				* (float)board.getMovmentSpeed() * deltaTime.asSeconds()))
				this->setLocation(sf::Vector2f(0, -1)*(float)board
					.getMovmentSpeed() * deltaTime.asSeconds());
			this->setState(CLIMBING);
			if(board.isMovePossible(this->getLocation() +
				sf::Vector2f(below->getLocation().x - 
					this->getLocation().x, 0)))
				this->setLocation(sf::Vector2f(below->getLocation().x - 
					this->getLocation().x, 0));
		}
		else
			this->setState(STAND);
	}
}
//============================================================================
void MovingObject::moveDown(const sf::Time& deltaTime, Board&  board){
	if (board.isMovePossible(this->getBelow())) {
		GameObject* object = board.getContent(this->getBelow() + 
			sf::Vector2f(0, -1));
		if (dynamic_cast <Ladder*> (object)) {
			this->setState(CLIMBING);
			if(board.isMovePossible(this->getLocation() + sf::Vector2f(0, 1)
				* (float)board.getMovmentSpeed() * deltaTime.asSeconds()))
				this->setLocation(sf::Vector2f(object->getLocation().x -
					this->getLocation().x, 0));
		}
		else if (dynamic_cast <Rod*> (board.getContent(this->getCenter())) &&
			dynamic_cast <Rod*> (object) && this->getState() != RODDING) {
			if (board.isMovePossible(this->getLocation() + sf::Vector2f(0, 1)
				* (float)board.getMovmentSpeed() * deltaTime.asSeconds()))
				this->setLocation(sf::Vector2f(0, object->getLocation().y
					- this->getLocation().y));
			this->setState(RODDING);
		}
		else if (dynamic_cast <Wall*> (object)) {
			if (((Wall*)object)->isDigged())
				this->setLocation(sf::Vector2f(object->getLocation().x
					- this->getLocation().x, 0));

		}
		else
			this->setState(STAND);
		if (board.isMovePossible(this->getLocation() + sf::Vector2f(0, 1)
			* (float)board.getMovmentSpeed() * deltaTime.asSeconds()))
			this->setLocation(sf::Vector2f(0, 1) * (float)board.
				getMovmentSpeed() * deltaTime.asSeconds());
		
	}
	
}
//============================================================================
void MovingObject::moveLeft(const sf::Time& deltaTime, Board& board){
	if (dynamic_cast <Wall*>
		(board.getContent(this->getLocation() + sf::Vector2f(0,this->getSize().y)))) {
		GameObject* object = (GameObject*)board.getContent(this->getLocation() + sf::Vector2f(0, this->getSize().y));
		this->setLocation({ 0, object->getLocation().y - (this->getLocation().y + this->getSize().y) });
	}
	if (dynamic_cast <Rod*>
		(board.getContent(this->getAbove()))) {
		this->setState(RODDING);
	}
	else
		this->setState(STAND);

	for (int i = 0; i < (float)board.
		getMovmentSpeed() * deltaTime.asSeconds(); ++i) {
		if (board.isMovePossible(this->getLeft())) {
			this->setLocation(sf::Vector2f(-1, 0));
		}
		else
			break;
	}
}
//============================================================================
void MovingObject::moveRight(const sf::Time& deltaTime, Board& board){
	if (dynamic_cast <Wall*>
		(board.getContent(this->getLocation() + this->getSize()))) {
		GameObject* object = (GameObject*)board.getContent(this->getLocation() + this->getSize());
		this->setLocation({0, object->getLocation().y - (this->getLocation().y + this->getSize().y) });
	}
	if (dynamic_cast <Rod*>
		(board.getContent(this->getAbove()))) {
		this->setState(RODDING);
	}
	else
		this->setState(STAND);
	float move = (float)board.
		getMovmentSpeed() * deltaTime.asSeconds();


	for (int i = 0; i < (float)board.
		getMovmentSpeed() * deltaTime.asSeconds(); ++i) {
		if (board.isMovePossible(this->getRight())) {
			sf::Vector2f loc = this->getLocation() + sf::Vector2f(1, 0);
			if (loc.x > board.getlevelSize().x + board.getLocation().x || 
				loc.y > board.getlevelSize().y + board.getlevelSize().y)
				int i = 0;
			this->setLocation(sf::Vector2f(1, 0));
		}
		else
			break;
	}
}
//============================================================================
bool MovingObject::isFalling(const Board& board){
	if (this->getState() != CLIMBING && this->getState() != RODDING) {
		if (dynamic_cast <const Ladder*> (board.getContent(this->getCenter())) ||
			dynamic_cast <const Ladder*> (board.getContent(this->getBelow())))
			return false;
		if (dynamic_cast <const Rod*> 
			(board.getContent(this->getAbove())))
			return false;
		if (dynamic_cast <const Wall*> (board.getContent(this->getBelow()))) {
			if (((const Wall*)board.getContent(this->getBelow()))->isDigged())
				return true;
			return false;
		}
		if (board.isMovePossible(this->getBelow())) {
			return true;
		}
	}
	return false;
}
//============================================================================
void MovingObject::reset(){
	this->GameObject::reset();
	this->setLocation(sf::Vector2f(this->m_initialLoc.x -this->getLocation().x, 
		this->m_initialLoc.y - this->getLocation().y));
}
//============================ private section ===============================
//============================== gets section ================================
//============================== sets section ================================
//============================================================================
void MovingObject::setLocation(const sf::Vector2f& movement){
	this->GameObject::setLocation(movement);
}
//============================================================================
void MovingObject::setLookState(int state) {
	if (state % 3 == LOOK_STRAIGHT)
		this->m_lookingState = LOOK_STRAIGHT;
	else if (state % 3 == LOOK_RIGHT)
		this->m_lookingState = LOOK_RIGHT;
	else
		this->m_lookingState = LOOK_LEFT;
}

//============================ methods section ===============================