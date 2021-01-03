/*
   This file conatains all methods of the class Board.
*/
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Macros.h"
#include "EffectsHolder.h"
#include <vector>
using std::vector;
//==================== Constructors & distructors section ====================
Board::Board(vector<sf::Sprite> levelsprites)
	: m_levelReader(DataReader()),
	m_background(sf::RectangleShape()),
	m_location(sf::Vector2f{ 0,0 }),
	m_levelSprites(levelsprites)
{
	this->m_levelNumber = 0;
	this->m_size = m_levelReader.getLevelSize();
	this->m_levelTime = m_levelReader.getLevelTime();
	if (m_levelTime == NO_LEVEL_TIME)
		this->m_timeLimit = false;
	else
		this->m_timeLimit = true;

	this->loadLevel();
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
	
	this->m_levelNumber++;
}
//========================================================================
bool Board::is_next_lvl_exist()const {
	return m_levelReader.isThereNextLevel();
}
//========================================================================
const GameObject* Board::getContent(const sf::Vector2f& location)const{
	return m_map[(unsigned)location.x][(unsigned)location.y];
}
//========================================================================
int Board::getLevelTime()const {
		return m_levelTime;
}
//========================================================================
bool Board::is_time_lvl_exist()const {
	return this->m_timeLimit;
}
//========================================================================
