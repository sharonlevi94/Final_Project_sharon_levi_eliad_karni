//============================= include section ==============================
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Utilities.h"
#include <iostream>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
GameObject::GameObject(const sf::Vector2f location,
	const EffectsHolder& effects, const sf::Vector2f& size, char objectType) :
    m_state(STAND), m_objectSprite() {
	this->m_objectSprite.setPosition(location);
	this->m_objectSprite.setTexture(effects.getTexture(objectType));
	this->m_objectSprite.setScale((float)size.x /this->m_objectSprite.getTexture()->getSize().x,
		(float)size.y / this->m_objectSprite.getTexture()->getSize().y);

}
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
const sf::Vector2f& GameObject::getSize()const{
	return sf::Vector2f(this->getSprite().getGlobalBounds().width, 
		this->getSprite().getGlobalBounds().height);
}
//============================================================================
const sf::Sprite& GameObject::getSprite() const {
	return (this->m_objectSprite); 
}
//============================================================================
void GameObject::reset(const sf::Vector2f& initialLoc) {
	this->m_state = STAND;
	this->m_objectSprite.setPosition(initialLoc);
}
//============================ methods section ===============================
void GameObject::draw(sf::RenderWindow& window){
	window.draw(this->m_objectSprite);
}
//============================================================================
bool GameObject::CollidesWith(const GameObject& obj)const {
	return m_objectSprite.getGlobalBounds().intersects
	(obj.getSprite().getGlobalBounds());
}
//============================================================================
void GameObject::setState(int state) { this->m_state = state; }
//=========================== protected section ==============================
//============================== sets section ================================
void GameObject::setLocation(const sf::Vector2f& movment) {
	this->m_objectSprite.move(movment);
}


