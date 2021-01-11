//============================= include section ==============================
#include "MovingObject.h"
#include <SFML/Graphics.hpp>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
MovingObject::MovingObject(const sf::Vector2f location,
	const EffectsHolder& effects,
	const sf::Vector2f& size)
	: GameObject(location, effects, size, PLAYER_T){}
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
//============================ methods section ===============================
/*
void MovingObject::moveUp(const sf::Time& time, const Board& board){
	
}
void MovingObject::moveDown(const sf::Time&, const Board&){}
void MovingObject::moveLeft(const sf::Time&, const Board&){}
void MovingObject::moveRight(const sf::Time&, const Board&){}
void MovingObject::fall(){

}

bool MovingObject::isFalling(const Board& board){
	return(board.getContent(this->getLocation() - 
	sf::Vector2f(this->getSize().x, this->getSize().y + 1)) != nullptr &&
	board.getContent(this->getLocation() - 
	sf::Vector2f(0, this->getSize().y + 1)) != nullptr);
}*/
//============================ private section ===============================
//============================== gets section ================================
//============================== sets section ================================
//============================================================================
void MovingObject::setLocation(const sf::Vector2f& movement){
	this->GameObject::setLocation(movement);
}
//============================================================================

//============================ methods section ===============================