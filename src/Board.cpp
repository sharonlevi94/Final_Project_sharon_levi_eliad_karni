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
//==================== Constructors & distruors section ====================
Board::Board(const sf::Vector2f& location,
             const sf::Vector2f& size, 
			 const EffectsHolder& effects)
	: m_levelReader(DataReader()),
	m_background(sf::RectangleShape()),
	m_location(location),
	m_levelNumber(1),
	m_backgroundSize(size),
	m_map({}),
	m_levelSize(sf::Vector2f(0,0)),
	m_levelTime(0)
{}
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
				window.display();
			}
}
//========================================================================
std::vector<MovingObject*> Board::loadNewLevel(const EffectsHolder& effects){
	this->m_levelNumber++;
	//read new level & size from the dataReader:
	this->m_map = m_levelReader.readNextLevel(effects);
	m_levelSize = m_levelReader.getLevelSize();
	//set time level, if exist:
	this->m_levelTime = m_levelReader.getLevelTime();
	//set background of the level:
	m_background.setSize(m_backgroundSize);
	m_background.setPosition(m_location);
	m_background.setTexture(&effects.getTexture(m_levelNumber));
	return this->FindMovingObj();
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
vector<MovingObject*> Board::FindMovingObj(){
	vector<MovingObject*> characters = {};
	for(int i =0 ; i< this->m_map.size() ; i++)
		for(int j=0 ; j<this->m_map[i].size() ; j++){
			if (dynamic_cast <MovingObject*> (m_map[i][j]))
				characters.push_back((MovingObject*)m_map[i][j]);
		}
	return characters;
}