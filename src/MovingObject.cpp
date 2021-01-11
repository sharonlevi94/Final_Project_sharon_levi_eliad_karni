//============================= include section ==============================
#include "MovingObject.h"
#include "Board.h"
#include "Ladder.h"
#include <SFML/Graphics.hpp>

//============================= public section ===============================
//==================== Constructors & distructors section ====================
MovingObject::MovingObject(const sf::Vector2f location,
	const EffectsHolder& effects,
	const sf::Vector2f& size)
	: GameObject(location, effects, size, PLAYER_T),
	m_initialLoc(location){}
//============================== gets section ================================
sf::Vector2f MovingObject::getAbove()const{
	return sf::Vector2f(this->getSprite().getOrigin().x, this->getLocation().y - 1);
}
sf::Vector2f MovingObject::getLeft()const{
	return sf::Vector2f( this->getLocation().x - 1, this->getSprite().getOrigin().y);
}
sf::Vector2f MovingObject::getBelow()const{
	return sf::Vector2f(this->getSprite().getOrigin().x, 
	this->getLocation().y + this->getSprite().getLocalBounds().height + 1);
}
sf::Vector2f MovingObject::getRight()const{
	return sf::Vector2f(this->getLocation().x + this->getSize().x + 1, this->getSprite().getOrigin().y);
}
sf::Vector2f MovingObject::getInitialLoc()const { return this->m_initialLoc; }
//============================ methods section ===============================
//============================================================================
void MovingObject::moveUp(const sf::Time& deltaTime, const Board& board){
	for (int i = 0; i < board.getMovmentSpeed() * deltaTime.asSeconds() ; ++i){
		if (board.isMovePossible(this->getAbove() + sf::Vector2f(0, 1))){
			if (dynamic_cast <Ladder*>
				(board.getContent(this->getBelow() + sf::Vector2f(0, -1)))) {
				Ladder* ladder = (Ladder*)board.getContent(this->getBelow() + 
					sf::Vector2f(0, -1));
				if (this->getLocation().y != ladder->getSprite().getOrigin().y)
					this->setLocation(ladder->getLocation() - this->getLocation());
				this->setLocation(sf::Vector2f(0, -1)*(float)board.getMovmentSpeed()*deltaTime.asSeconds());
				this->setState(CLIMBING);
			}
		}
		else {
			break;
		}
	}
}
//============================================================================
void MovingObject::moveDown(const sf::Time&, const Board&){}
//============================================================================
void MovingObject::moveLeft(const sf::Time& deltaTime, const Board& board){
	for(int i = 0; i < board.getMovmentSpeed()*deltaTime.asSeconds() ; ++i)
	if(board.isMovePossible(this->getLocation() + sf::Vector2f(-1, 0)) &&
		board.isMovePossible(this->getLocation() + 
			sf::Vector2f(-1, this->getSize().y)))
	this->setLocation(sf::Vector2f(-1,0)*(float)board.getMovmentSpeed()*deltaTime.asSeconds());
}
//============================================================================
void MovingObject::moveRight(const sf::Time&, const Board&){}
//============================================================================
void MovingObject::fall(){
	
}
//============================================================================
bool MovingObject::isFalling(const Board& board){
	return(board.getContent(this->getLocation() - 
	sf::Vector2f(this->getSize().x, this->getSize().y + 1)) != nullptr &&
	board.getContent(this->getLocation() - 
	sf::Vector2f(0, this->getSize().y + 1)) != nullptr);
}
//============================================================================
bool MovinleftIsFloor(const Board&);
//============================================================================
bool rightIsFloor(const Board&);
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