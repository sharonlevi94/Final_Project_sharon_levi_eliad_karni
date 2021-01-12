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
	const EffectsHolder& effects,
	const sf::Vector2f& size)
	: GameObject(location, effects, size, PLAYER_T),
	m_initialLoc(location){}
//============================== gets section ================================
sf::Vector2f MovingObject::getCenter() const{
	return sf::Vector2f(this->getLocation().x + (this->getSize().x/2),
		this->getLocation().y + (this->getSize().y/2));
}
//============================================================================
sf::Vector2f MovingObject::getAbove()const{
	return sf::Vector2f(this->getCenter().x, this->getLocation().y - 1);
}
//============================================================================
sf::Vector2f MovingObject::getLeft()const{
	return sf::Vector2f( this->getLocation().x - 1, this->getCenter().y);
}
//============================================================================
sf::Vector2f MovingObject::getBelow()const{
	return sf::Vector2f(this->getCenter().x, 
	this->getLocation().y + this->getSize().y + 1);
}
//============================================================================
sf::Vector2f MovingObject::getRight()const{
	return sf::Vector2f(this->getLocation().x + this->getSize().x + 1, this->getCenter().y);
}
//============================================================================
sf::Vector2f MovingObject::getInitialLoc()const { return this->m_initialLoc; }
//============================ methods section ===============================
//============================================================================
void MovingObject::moveUp(const sf::Time& deltaTime, const Board& board){
	if (board.isMovePossible(this->getAbove())){
		GameObject* ladder = board.getContent(this->getBelow() + 
			sf::Vector2f(0, -2));
		if (dynamic_cast <Ladder*> (ladder)) {
			this->setLocation(sf::Vector2f(0, -1)*(float)board.getMovmentSpeed()
				*deltaTime.asSeconds());
			this->setState(CLIMBING);
			this->setLocation(sf::Vector2f(ladder->getLocation().x - 
				this->getLocation().x, 0));
		}
		else
			this->setState(STAND);
	}
	
}
//============================================================================
void MovingObject::moveDown(const sf::Time& deltaTime, const Board&  board){
	if (board.isMovePossible(this->getBelow())) {
		GameObject* object = board.getContent(this->getBelow() + sf::Vector2f(0, -1));
		if (dynamic_cast <Ladder*> (object)) {
			this->setState(CLIMBING);
			this->setLocation(sf::Vector2f(object->getLocation().x -
				this->getLocation().x, 0));
		}
		else
			this->setState(STAND);
		this->setLocation(sf::Vector2f(0, 1) * (float)board.
			getMovmentSpeed() * deltaTime.asSeconds());
		
	}
	
}
//============================================================================
void MovingObject::moveLeft(const sf::Time& deltaTime, const Board& board){
		if (board.isMovePossible(this->getLeft())){
			if (!dynamic_cast <Wall*>
				(board.getContent(this->getLeft() + sf::Vector2f(-1, 0)))) {
				this->setLocation(sf::Vector2f(-1, 0)*(float)board.getMovmentSpeed()*deltaTime.asSeconds());
				this->setState(STAND);
			}
		}
}
//============================================================================
void MovingObject::moveRight(const sf::Time& deltaTime, const Board& board){
		if (board.isMovePossible(this->getRight())){
			if (!dynamic_cast <Wall*>
				(board.getContent(this->getRight() + sf::Vector2f(1, 0)))) {
				this->setLocation(sf::Vector2f(1, 0)*(float)board.getMovmentSpeed()*deltaTime.asSeconds());
				this->setState(STAND);
			}
		}
}
//============================================================================
bool MovingObject::isFalling(const Board& board){
	if (this->getState() != CLIMBING && this->getState() != RODDING) {
		if ((board.getContent(this->getBelow())) == nullptr)
			return true;
		if (dynamic_cast <Ladder*> (board.getContent(this->getCenter())))
			return false;
		if (!dynamic_cast <Rod*> (board.getContent(this->getAbove())))
			return true;
	}
	return false;
}
//============================================================================
bool isMovePossible(const Board&, const sf::Vector2f&);
//============================ private section ===============================
//============================== gets section ================================
//============================== sets section ================================
//============================================================================
void MovingObject::setLocation(const sf::Vector2f& movement){
	this->GameObject::setLocation(movement);
}
//============================================================================

//============================ methods section ===============================