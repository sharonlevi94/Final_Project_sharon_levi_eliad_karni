//============================= include section ==============================
#include "Player.h"
#include "SFML/Graphics.hpp"
//============================= public section ===============================
//==================== Constructors & distructors section ====================

//============================== gets section ================================

//============================ methods section ===============================
void Player::draw(sf::RenderWindow& window,const sf::Texture& texture) const {
	sf::Sprite player;
	player.setTexture(texture);
	window.draw(player);
}



//============================ private section ===============================
//============================== sets section ================================
//============================ methods section ===============================