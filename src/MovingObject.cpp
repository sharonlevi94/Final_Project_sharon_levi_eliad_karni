//============================= include section ==============================
#include "MovingObject.h"
#include "Board.h"
#include "Ladder.h"
#include "Wall.h"
#include "Rod.h"
#include "Macros.h"
#include <SFML/Graphics.hpp>

//============================= public section ===============================
//==================== Constructors & distructors section ====================
MovingObject::MovingObject(const sf::Vector2f location,
	const sf::Vector2f& size,
	char objectType)
	: GameObject(location, size, objectType), m_isTrapped(false),
	m_initialLoc(location), m_lookingState(LOOK_STRAIGHT), 
	m_trappingWall(nullptr){}
//============================== gets section ================================
//============================================================================
sf::Vector2f MovingObject::getInitialLoc()const { return this->m_initialLoc; }
//============================================================================
int MovingObject::getLookState()const { return this->m_lookingState; }
//============================ methods section ===============================
//============================================================================
bool MovingObject::physicsTurn(const sf::Time& deltaTime, Board& board) {
	if (this->m_isTrapped) {
		if (!this->m_trappingWall->getTrappingState() ||
			(this->m_trappingWall->getSprite().getGlobalBounds()
				.contains(this->getCenter()) &&
				this->m_trappingWall->getSprite().getGlobalBounds()
				.contains(this->getAbove() - sf::Vector2f(0, 1)))) {
			this->getUntrapped();
		}
	}
	if (this->isFalling(board)) {
		moveDown(deltaTime, board);
		return true;
	}
	if (dynamic_cast <Wall*> (board.getContent(this->getCenter()))) {
		if (!((Wall*)board.getContent(this->getCenter()))
			->getTrappingState()) {
			if (board.getContent(this->getCenter())->getCenter().y >= this
				->getCenter().y) {
				this->setLocation({ 0, board.getContent(this->getCenter())
					->getLocation().y -
			(this->getLocation().y + this->getSize().y) });
			}
		}
	}
	return false;
}
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
				* (MOVEMENT_SPEED * deltaTime.asSeconds())))
				this->setLocation(sf::Vector2f(0, -1) * (MOVEMENT_SPEED
					* deltaTime.asSeconds()));
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
		GameObject* object = board.getContent(this->getBelow());
		if (dynamic_cast <Ladder*> (object)) {
			this->setState(CLIMBING);
			if (board.isMovePossible(this->getLocation() + sf::Vector2f(0, 1)
				* (MOVEMENT_SPEED * deltaTime.asSeconds())))
				this->setLocation(sf::Vector2f(object->getLocation().x -
					this->getLocation().x, 0));
		}
		else if (dynamic_cast <Rod*> (board.getContent(this->getCenter()))) {
			if (dynamic_cast <Rod*> (object) && this->getState() != RODDING) {
				this->setLocation(sf::Vector2f(0, object->getLocation().y
					- this->getLocation().y));
				this->setState(RODDING);
				return;
			}
			else if (RODDING) {
				this->setState(STAND);
			}
		}
		else if (dynamic_cast <Wall*> (object)) {
			if (((Wall*)object)->isDigged()) {
				this->setLocation(sf::Vector2f(object->getLocation().x
					- this->getLocation().x, 0));
				this->getTrapped(((Wall*)object));
			}
		}
		else
			this->setState(STAND);
		if (board.isMovePossible((this->getBelow() + sf::Vector2f(0, -1)
		+ sf::Vector2f(0, 1)
		* (MOVEMENT_SPEED * deltaTime.asSeconds()))))
			this->setLocation(sf::Vector2f(0, 1) * 
				(MOVEMENT_SPEED * deltaTime.asSeconds()));
		
	}
	
}
//============================================================================
void MovingObject::moveLeft(const sf::Time& deltaTime, Board& board){
	if (!this->m_isTrapped && dynamic_cast <Wall*>
		(board.getContent(this->getLocation() + 
			sf::Vector2f(0, this->getSize().y)))) {
		Wall* object = (Wall*)board.getContent
		(this->getLocation() + sf::Vector2f(0, this->getSize().y));
		if(object->getTrappingState())
			this->setLocation({ 0, object->getLocation().y - 
				(this->getLocation().y + this->getSize().y) });
		if (object->CollidesWith(*this))
			this->setLocation({ 0, (object->getLocation() - (this->getLocation() + this->getSize())).y });
	}
	else if (dynamic_cast <Rod*>
		(board.getContent(this->getCenter()))) {
		GameObject* object = board.getContent(this->getCenter());
		this->setLocation({ 0, ((this->getLocation() - object->getLocation())).y });
	}
	else
		this->setState(STAND);

	if (board.isMovePossible((this->getLeft() + sf::Vector2f(1,0)) + 
		(sf::Vector2f(-1, 0) * (MOVEMENT_SPEED * deltaTime.asSeconds()))))
		this->setLocation(sf::Vector2f(-1, 0) * 
			(MOVEMENT_SPEED * deltaTime.asSeconds()));
}
//============================================================================
void MovingObject::moveRight(const sf::Time& deltaTime, Board& board){
	if (!this->m_isTrapped && dynamic_cast <Wall*>
		(board.getContent(this->getLocation() + this->getSize()))) {
		Wall* object = (Wall*)board.getContent(this->getLocation() +
			this->getSize());
		if(object->getTrappingState())
			this->setLocation({0, object->getLocation().y - 
				(this->getLocation().y + this->getSize().y) });
		if (object->CollidesWith(*this)) 
			this->setLocation({ 0, (object->getLocation() - (this->getLocation() + this->getSize())).y });
	}
	else if (dynamic_cast <Rod*>
		(board.getContent(this->getCenter()))) {
		GameObject* object = board.getContent(this->getCenter());
		this->setLocation({ 0, (this->getLocation() - object->getLocation()).y });
		this->setState(RODDING);
	}
	else
		this->setState(STAND);

	if (board.isMovePossible((this->getRight() + sf::Vector2f(-1, 0)) +
		(sf::Vector2f(1, 0) * (MOVEMENT_SPEED * deltaTime.asSeconds()))))
		this->setLocation(sf::Vector2f(1, 0) * 
			(MOVEMENT_SPEED * deltaTime.asSeconds()));
}
//============================================================================
void MovingObject::getTrapped(Wall* trappingWall) {
	this->m_isTrapped = true;
	trappingWall->changeTrapMode(true);
	this->m_trappingWall = trappingWall;
}
//============================================================================
void MovingObject::getUntrapped() {
	this->m_isTrapped = false;
	this->m_trappingWall->changeTrapMode(false);
	this->m_trappingWall = nullptr;
}
//============================================================================
bool MovingObject::getTrapState()const { return this->m_isTrapped; }
//============================================================================
bool MovingObject::isFalling(const Board& board){
	if (this->getState() != CLIMBING && this->getState() != RODDING) {
		if (dynamic_cast <const Ladder*> (board.getContent
		(this->getCenter())) ||
			dynamic_cast <const Ladder*> 
			(board.getContent(this->getBelow())))
			return false;
		if (dynamic_cast <const Rod*> (board.getContent(this->getAbove()))) {
			if (!dynamic_cast <const Rod*> (board.getContent(this->getBelow())))
				return true;
			return false;
		}
		if (dynamic_cast <const Wall*> (board.getContent
		(this->getBelow()))) {
			if (((const Wall*)board.getContent(this->getBelow()))->isDigged() &&
				(!((const Wall*)board.getContent(this->getBelow()))
				->getTrappingState())|| board.getContent(this->getBelow()) == this->m_trappingWall)
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
	this->setLocation(sf::Vector2f(this->m_initialLoc.x - 
		this->getLocation().x,
		this->m_initialLoc.y - this->getLocation().y));
	if(this->m_isTrapped)
		this->getUntrapped();
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