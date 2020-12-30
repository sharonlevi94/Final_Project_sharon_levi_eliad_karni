/*
   This file conatains all methods of the class Board.
*/
#include <SFML/Graphics.hpp>
#include "Board.h"
//========================================================================
Board::Board()
	: m_levelReader(DataReader()),
	  m_background(sf::RectangleShape()),
	  m_location(sf::Vector2f{ 0,0 }) {
	
}
//========================================================================
Board::~Board() {
	for (int i = 0; i < m_size.x; i++)
		for (int j = 0; j < m_size.y; j++)
			m_map[i][j]->~GameObject();
}
//========================================================================
void Board::draw(sf::RenderWindow& window)const{
	window.draw(m_background);
}
//========================================================================
void Board::loadLevel(){
	this->m_map = m_levelReader.readNextLevel(); //read the 1st lvl 
	m_size = m_levelReader.getLevelSize();
	m_background.setSize(m_size);
}
//========================================================================
bool Board::is_next_lvl_exist()const {
	return m_levelReader.isThereNextLevel();
}
//========================================================================
const GameObject* Board::getContent(const sf::Vector2f& location)const{
	return m_map[location.x][location.y];
}
//========================================================================
int Board::getLevelTime()const {
	if (this->m_timeLimit)
		return m_levelTime;
}