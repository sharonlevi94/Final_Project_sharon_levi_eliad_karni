/*
   This file conatains all methods of the class Board.
*/

#include "Board.h"
//========================================================================
Board::Board(){}
//========================================================================
void Board::draw(sf::RenderWindow& window)const{
	window.draw(m_background);
}
//========================================================================
vector<GameObject*> Board::loadLevel(){}
//========================================================================
bool Board::is_next_lvl_exist()const {
}
//========================================================================
const GameObject* Board::getContent(const sf::Vector2f& location)const{
	return m_map[location.x][location.y];
}