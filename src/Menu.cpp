//============================= include section ==============================
#include "Menu.h"
#include <SFML/Graphics.hpp>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Menu::Menu(const sf::Vector2f& size, const sf::Vector2f& location):
	m_location(location), m_size(size), temp_effects(EffectsHolder()){}
//============================== gets section ================================
//============================ methods section ===============================

//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================
void Menu::draw(sf::RenderWindow & window){
	sf::Sprite background;
	background.setTexture(this->temp_effects.)
}
