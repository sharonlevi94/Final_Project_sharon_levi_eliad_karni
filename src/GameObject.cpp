//============================= include section ==============================
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <EffectsHolder.h>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
GameObject::GameObject(const sf::Vector2f location,
	int state, const EffectsHolder& effects) :
    m_state(state), m_objectSprite(sf::Sprite()) {
	this->m_objectSprite.setPosition(location);
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
//=========================== protected section ==============================
//============================== sets section ================================
void GameObject::setLocation(const sf::Vector2f& movment) {
	this->m_objectSprite.move(movment);
}