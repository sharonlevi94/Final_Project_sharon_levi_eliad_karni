//============================= include section ==============================
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "EffectsHolder.h"
#include "Board.h"
#include "Utilities.h"
#include <iostream>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
GameObject::GameObject(const sf::Vector2f location, const sf::Vector2f& size,
	char objectType) : m_state(STAND), m_objectSprite() {
	this->m_objectSprite.setPosition(location);
	this->m_objectSprite.setTexture(EffectsHolder::instance().
		getTexture(objectType));
	this->m_objectSprite.setScale((float)size.x /this->m_objectSprite
		.getTexture()->getSize().x,
		(float)size.y / this->m_objectSprite.getTexture()->getSize().y);

}
GameObject::~GameObject() {}
//============================== gets section ================================
//============================================================================
const sf::Vector2f& GameObject::getLocation()const { 
	return this->m_objectSprite.getPosition();
}
//============================================================================
int GameObject::getState()const {
	return this->m_state;
}
//============================================================================
 sf::Vector2f GameObject::getSize()const{
	return sf::Vector2f(this->getSprite().getGlobalBounds().width, 
		this->getSprite().getGlobalBounds().height);
}
//============================================================================
const sf::Sprite& GameObject::getSprite() const {
	return (this->m_objectSprite); 
}
//============================================================================
void GameObject::reset() {
	this->m_state = STAND;
}
//============================ methods section ===============================
void GameObject::draw(sf::RenderWindow& window, 
	const sf::Time& animationClock){
	window.draw(this->m_objectSprite);
}
//============================================================================
bool GameObject::CollidesWith(const GameObject& obj)const {
	return m_objectSprite.getGlobalBounds().intersects
	(obj.getSprite().getGlobalBounds());
}
//============================================================================
void GameObject::setState(int state) { this->m_state = state; }
//============================================================================
sf::Vector2f GameObject::getCenter() const {
	return sf::Vector2f(this->getLocation().x + (this->getSize().x / 2),
		this->getLocation().y + (this->getSize().y / 2));
}
//============================================================================
sf::Vector2f GameObject::getAbove()const {
	return sf::Vector2f(this->getCenter().x, this->getLocation().y - 1);
}
//============================================================================
sf::Vector2f GameObject::getLeft()const {
	return sf::Vector2f(this->getLocation().x - 1, this->getCenter().y);
}
//============================================================================
sf::Vector2f GameObject::getBelow()const {
	return sf::Vector2f(this->getCenter().x,
		this->getLocation().y + this->getSize().y + 1);
}
//============================================================================
sf::Vector2f GameObject::getRight()const {
	return sf::Vector2f(this->getLocation().x + this->getSize().x + 1,
		this->getCenter().y);
}
//============================================================================
sf::Vector2f GameObject::getBotLeft()const {
	return sf::Vector2f(this->getCenter().x - this->getSize().x,
		this->getCenter().y + this->getSize().y);
}
//============================================================================
sf::Vector2f GameObject::getBotRight()const {
	return this->getCenter() + this->getSize();
}
//=========================== protected section ==============================
//============================== sets section ================================
void GameObject::setLocation(const sf::Vector2f& movment) {
	this->m_objectSprite.move(movment);
}