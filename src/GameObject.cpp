//============================= include section ==============================
#include "GameObject.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
GameObject::GameObject(const sf::Vector2f location,
	const sf::Vector2f size,
	int state,
	sf::Texture* texturs,
	char type) :
	m_type(type),
	m_location(location),
	m_size(size),
    m_state(state),
    m_textures(texturs) {}
//============================== gets section ================================
const sf::Vector2f& GameObject::getLocation()const { return this->m_location; }
const sf::Vector2f& GameObject::getSize()const { return this->m_size; }
int  GameObject::getState()const { return this->m_state; }
const sf::Sprite* GameObject::getSprite()const{}
char GameObject::identify()const { return this->m_type; }
//============================ methods section ===============================

//============================ private section ===============================
//============================== sets section ================================
//============================ methods section ===============================