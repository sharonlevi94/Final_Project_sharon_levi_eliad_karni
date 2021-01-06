//============================= include section ==============================
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
GameObject::GameObject(const sf::Vector2f location,
	const EffectsHolder& effects, char objectType) :
    m_state(STAND), m_objectSprite(sf::Sprite()) {
	this->m_objectSprite.setPosition(location);
	this->m_objectSprite.setTexture(effects.getTexture(objectType));
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
	return sf::Vector2f(this->m_objectSprite.getLocalBounds().width,
		this->m_objectSprite.getLocalBounds().height);
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
//============================================================================
void GameObject::draw(sf::RenderWindow& window) const{
	calcScale
	window.draw(this->m_objectSprite);
}
//=========================== protected section ==============================
//============================== sets section ================================
void GameObject::setLocation(const sf::Vector2f& movment) {
	this->m_objectSprite.move(movment);
}