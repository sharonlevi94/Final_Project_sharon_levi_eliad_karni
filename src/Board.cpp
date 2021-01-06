/*
   This file conatains all methods of the class Board.
*/
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Macros.h"
#include "EffectsHolder.h"
#include <vector>
#include "Utilities.h"
using std::vector;
//==================== Constructors & distructors section ====================
Board::Board(sf::Vector2u size)
	: m_levelReader(DataReader()),
	m_background(sf::RectangleShape()),
	m_location(sf::Vector2f{ 0,0 }),
	m_effectsHolder(EffectsHolder()),
	m_levelNumber(1),
	m_backgroundSize((sf::Vector2f)size)
{
	this->loadNewLevel();
}
//========================================================================
Board::~Board() {
	for (int i = 0; i < m_levelSize.x; i++)
		for (int j = 0; j < m_levelSize.y; j++)
			m_map[i][j]->~GameObject();
}
//========================================================================
void Board::draw(sf::RenderWindow& window)const{
	window.draw(m_background);
	for (int i = 0; i < m_levelSize.x; i++)
		for (int j =0; j < m_levelSize.y; j++)
			if (m_map[i][j] != nullptr) {
				m_map[i][j]->draw(window);
			}
}
//========================================================================
void Board::loadNewLevel(/* sf::Texture *texturelevel */){
	this->m_levelNumber++;
	//read new level & size from the dataReader:
	this->m_map = m_levelReader.readNextLevel();  
	m_levelSize = m_levelReader.getLevelSize();
	//set time level, if exist:
	this->m_levelTime = m_levelReader.getLevelTime();
	if (m_levelTime == NO_LEVEL_TIME)
		this->m_timeLimit = false;
	else
		this->m_timeLimit = true;
	//set background of the level:
	m_background.setSize(m_backgroundSize);
	m_background.setPosition(m_location);
	m_background.setTexture(&m_effectsHolder.getTexture(m_levelNumber));
	//m_background.setTexture(*textureLevel);
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
