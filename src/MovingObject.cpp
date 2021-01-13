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
	m_initialLoc(location) {}
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
	return sf::Vector2f(this->getLocation().x + this->getSize().x + 1, 
		this->getCenter().y);
}
//============================================================================
sf::Vector2f MovingObject::getBotLeft()const {
	return (sf::Vector2f(this->getLocation().x, 
		this->getLocation().y + this->getSize().y));
}
//============================================================================
sf::Vector2f MovingObject::getBotRight()const {
	return (this->getLocation() + this->getSize());
}
//============================================================================
sf::Vector2f MovingObject::getInitialLoc()const { return this->m_initialLoc; }
//============================ methods section ===============================
//============================================================================
void MovingObject::moveUp(const sf::Time& deltaTime, const Board& board){
	if (board.isMovePossible(this->getAbove())){
		GameObject* below = board.getContent(this->getBelow() + 
			sf::Vector2f(0, -2));
		GameObject* above = board.getContent(this->getAbove() +
			sf::Vector2f(0, 1));
		if (dynamic_cast <Ladder*> (below) || 
			dynamic_cast <Ladder*> (above)) {
			if (!dynamic_cast <Ladder*> (below))
				below = above;
			this->setLocation(sf::Vector2f(0, -1)*(float)board
				.getMovmentSpeed()
				*deltaTime.asSeconds());
			this->setState(CLIMBING);
			this->setLocation(sf::Vector2f(below->getLocation().x - 
				this->getLocation().x, 0));
		}
		else
			this->setState(STAND);
	}
}
//============================================================================
void MovingObject::moveDown(const sf::Time& deltaTime, const Board&  board){
	if (board.isMovePossible(this->getBelow())) {
		GameObject* object = board.getContent(this->getBelow() + 
			sf::Vector2f(0, -1));
		if (dynamic_cast <Ladder*> (object)) {
			this->setState(CLIMBING);
			this->setLocation(sf::Vector2f(object->getLocation().x -
				this->getLocation().x, 0));
		}
		else if (dynamic_cast <Rod*> (board.getContent(this->getCenter())) &&
			dynamic_cast <Rod*> (object) && this->getState() != RODDING) {
			this->setLocation(sf::Vector2f(0, object->getLocation().y
				- this->getLocation().y));
			this->setState(RODDING);
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
			while (dynamic_cast <Wall*>
				(board.getContent(this->getBotLeft()))) {
				this->setLocation(sf::Vector2f(0, -1));
			}
			this->setLocation(sf::Vector2f(-1, 0) * (float)board.
				getMovmentSpeed() * deltaTime.asSeconds());
			if (dynamic_cast <Rod*>
				(board.getContent(this->getAbove()))) {
				this->setLocation(sf::Vector2f(0, board.getContent(
					this->getAbove())->getLocation().y - 
					this->getLocation().y));
				this->setState(RODDING);
			}
			else
				this->setState(STAND);
		}
}
//============================================================================
void MovingObject::moveRight(const sf::Time& deltaTime, const Board& board){
		if (board.isMovePossible(this->getRight())){
			while (dynamic_cast <Wall*>
				(board.getContent(this->getBotRight()))) {
				this->setLocation(sf::Vector2f(0, -1));
			}
			this->setLocation(sf::Vector2f(1, 0) * (float)board.
				getMovmentSpeed() * deltaTime.asSeconds());
			if (dynamic_cast <Rod*>
				(board.getContent(this->getAbove()))) {
				this->setLocation(sf::Vector2f(0, board.getContent(
					this->getAbove())->getLocation().y - 
					this->getLocation().y));
				this->setState(RODDING);
			}
			else
				this->setState(STAND);
		}
}
//============================================================================
bool MovingObject::isFalling(const Board& board){
	if (this->getState() != CLIMBING && this->getState() != RODDING) {
		if (dynamic_cast <Ladder*> (board.getContent(this->getCenter())) ||
			dynamic_cast <Ladder*> (board.getContent(this->getBelow())))
			return false;
		if (dynamic_cast <Rod*> 
			(board.getContent(this->getAbove())))
			return false;
		if (!dynamic_cast <Wall*> ((board.getContent(this->getBelow()))))
			return true;
	}
	return false;
}
//============================================================================
void MovingObject::reset(){
	this->GameObject::reset();
	sf::Vector2f temp = sf::Vector2f(this->m_initialLoc.x -this->getLocation().x,
		this->m_initialLoc.y - this->getLocation().y);

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

//============================ methods section ===============================