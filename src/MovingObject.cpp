/*
   This file conatains all methods of the base class MovingObject.
*/
//============================= include section ==============================
#include "MovingObject.h"
#include "Board.h"
#include "Ladder.h"
#include "Wall.h"
#include "Rod.h"
#include "Door.h"
#include "Macros.h"
#include "EffectsHolder.h"
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
sf::Vector2f MovingObject::getInitialLoc()const { 
	return this->m_initialLoc; 
}
//============================================================================
int MovingObject::getLookState()const { return this->m_lookingState; }
//============================ methods section ===============================
/*
* this function handle in spacial moves cases of each character:
* falling down & get into traps.
*/
bool MovingObject::physicsTurn(const sf::Time& deltaTime, Board& board) {
	//handle traping wall communication
	if (this->m_isTrapped) {
		if (!this->m_trappingWall->getTrappingState() ||
			(this->m_trappingWall->getSprite().getGlobalBounds()
				.contains(this->getCenter()) &&
				this->m_trappingWall->getSprite().getGlobalBounds()
				.contains(this->getAbove() - sf::Vector2f(0, 1)))) {
			this->getUntrapped();
		}
	}
	//the character is falling ?
	if (this->isFalling(board)) {
		//EffectsHolder::instance().playSound(FALLING_SOUND);
		moveDown(deltaTime, board);
		return true;
	}
	return false;
}
//============================================================================
/*
* this function handle the case of user pressed on up button. 
* the function set the new location only if the wanted move is possible.
*/
void MovingObject::moveUp(const sf::Time& deltaTime, Board& board){
	sf::Vector2f movement = sf::Vector2f(0, -1)
		* (MOVEMENT_SPEED * deltaTime.asSeconds());
	StaticObject* object = board.getContent(this->getAbove() + movement);
	if (board.isMovePossible(this->getAbove() + movement)) {
		if (object != nullptr)
			object->handleCollision(*this, movement);
		else if (this->getState() != RODDING){
			this->nullMovement(movement);
			setState(STAND);
		}
	}
}
//============================================================================
/*
* this function handle the case of user pressed on down button or if the 
* character is falling down.
* the function set the new location only if the wanted move is possible.
*/
void MovingObject::moveDown(const sf::Time& deltaTime, Board&  board){
	sf::Vector2f movement = sf::Vector2f(0, 1)
		* (MOVEMENT_SPEED * deltaTime.asSeconds());
	StaticObject* object = board.getContent(this->getBelow() + movement);
	if (board.isMovePossible(this->getBelow() +  movement)) {
		if(object != nullptr)
			object->handleCollision(*this, movement);
		else {
			this->nullMovement(movement);
			this->setState(STAND);
		}
	}
}
//============================================================================
/*
* this function handle the case of user pressed on left button.
* the function set the new location only if the wanted move is possible.
*/
void MovingObject::moveLeft(const sf::Time& deltaTime, Board& board){
	sf::Vector2f movement = sf::Vector2f(-1, 0)
		* (MOVEMENT_SPEED * deltaTime.asSeconds());
	StaticObject* object = board.getContent(this->getLeft() + movement),
		*center = board.getContent(this->getCenter()),
		* bot = board.getContent(this->getLocation() + 
			sf::Vector2f(0,this->getSize().y));

	if (board.isMovePossible(this->getRight() + movement)) {
		if (object != nullptr)
			object->handleCollision(*this, movement);
		else {
			if (dynamic_cast <Wall*> (bot))
				this->setLocation({ 0, (bot->getLocation() -
					(this->getLocation() + this->getSize())).y });
			this->nullMovement(movement);
			if (center == nullptr || dynamic_cast <Door*> (center))
				this->setState(STAND);
		}
	}
}
//============================================================================
/*
* this function handle the case of user pressed on right button.
* the function set the new location only if the wanted move is possible.
*/
void MovingObject::moveRight(const sf::Time& deltaTime, Board& board){
	sf::Vector2f movement = sf::Vector2f(1, 0)
		* (MOVEMENT_SPEED * deltaTime.asSeconds());
	StaticObject *object = board.getContent(this->getRight() + movement),
		*center = board.getContent(this->getCenter()),
		*bot = board.getContent(this->getLocation() + this->getSize());
	if (board.isMovePossible(this->getRight() + movement)) {
		if (object != nullptr)
			object->handleCollision(*this, movement);
		else {
			if (dynamic_cast <Wall*> (bot))
				this->setLocation({ 0, (bot->getLocation() -
					(this->getLocation() + this->getSize())).y });
			this->nullMovement(movement);
			if(center == nullptr || dynamic_cast <Door*> (center))
				this->setState(STAND);
		}
	}
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
	if (!this->m_trappingWall->isDigged() && this->m_trappingWall
		->CollidesWith(*this))
		this->setLocation({ 0, (this->m_trappingWall->getLocation() -
					(this->getLocation() + this->getSize())).y });
	this->m_trappingWall = nullptr;
}
//============================================================================
bool MovingObject::getTrapState()const { return this->m_isTrapped; }
//============================================================================
/*
* this function check if the character is in a middle of falling down.
* it checks all the cases of fallings.
*/
bool MovingObject::isFalling(const Board& board){
	if (this->getState() != CLIMBING && this->getState() != RODDING) {
		if (dynamic_cast <const Ladder*> (board.getContent
		(this->getCenter())) ||
			dynamic_cast <const Ladder*> 
			(board.getContent(this->getBelow())))
			return false;
		if (dynamic_cast <const Rod*> (board.getContent(this->getAbove()
			+ sf::Vector2f(0,2)))) {
			if (!dynamic_cast <const Rod*> (board.getContent(this
				->getBelow())))
				return true;
			return false;
		}
		if (dynamic_cast <const Wall*> (board.getContent
		(this->getBelow()))) {
			if (((const Wall*)board.getContent(this->getBelow()))
				->isDigged() &&
				(!((const Wall*)board.getContent(this->getBelow()))
				->getTrappingState())|| board.getContent(this->getBelow())
				== this->m_trappingWall)
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
/*
* this function return the character to his initial state.
*/
void MovingObject::reset(){
	this->GameObject::reset();
	this->setLocation(sf::Vector2f(this->m_initialLoc.x - 
		this->getLocation().x,
		this->m_initialLoc.y - this->getLocation().y));
	if(this->m_isTrapped)
		this->getUntrapped();
}
//============================ private section ===============================
//============================== sets section ================================
/*
* this function get a new location and set this location in hte object 
* location
*/
void MovingObject::setLocation(const sf::Vector2f& movement){
	this->GameObject::setLocation(movement);
}
//============================================================================
/*
* the function change the direction that the character looking to.
*/
void MovingObject::setLookState(int state) {
	if (state % 3 == LOOK_STRAIGHT)
		this->m_lookingState = LOOK_STRAIGHT;
	else if (state % 3 == LOOK_RIGHT)
		this->m_lookingState = LOOK_RIGHT;
	else
		this->m_lookingState = LOOK_LEFT;
}
//============================================================================
void MovingObject::handleCollision(const Ladder& obj,
	const sf::Vector2f& movement) {
	this->setState(CLIMBING);
	if (movement.y != 0)
		this->setLocation({ obj.getLocation().x - this->getLocation().x,
			movement.y });
	else
		this->setLocation(movement);
}
//============================================================================
void MovingObject::handleCollision(Wall& obj,
	const sf::Vector2f& movement) {
	if (obj.isDigged()) {
		this->setLocation(sf::Vector2f(obj.getLocation().x
			- this->getLocation().x, movement.y));
		this->getTrapped(&obj);
	}
	else if ((this->getLocation()+this->getSize()).y < obj.getLocation().y){
		this->setLocation({ movement.x, (obj.getLocation() - 
			(this->getLocation() + this->getSize())).y });
	}
}
//============================================================================
void MovingObject::handleCollision(const Rod& obj,
	const sf::Vector2f& movement) {
	if (RODDING && movement.y < 0)
		this->setState(STAND);
	else  {
		this->setLocation(sf::Vector2f(movement.x, obj.getLocation().y
			- this->getLocation().y));
		this->setState(RODDING);
		return;
	}
	
}
//============================================================================
void MovingObject::handleCollision(const StaticObject& obj,
	const sf::Vector2f& movement) {
	this->nullMovement(movement);
}
//============================================================================
void MovingObject::nullMovement(const sf::Vector2f& movement) {
	this->setLocation(movement);
}