/*
   This file conatains all methods of the class Board.
*/
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Macros.h"
#include "EffectsHolder.h"
#include <vector>
#include "Utilities.h"
#include "Player.h"
#include "RandEnemy.h"
#include "Coin.h"
#include "Ladder.h" 
#include "Wall.h"
#include "Rod.h"
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
	m_levelSize(size),
	m_levelTime(0)
{}
//========================================================================
Board::~Board() {
	releaseMap();
	this->m_map = {};
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
std::vector<MovingObject*> Board::loadNewLevel(const EffectsHolder& effects) {
	vector<vector<char>> map = m_levelReader.readNextLevel();
	sf::Vector2f boxSize(this->getlevelSize().x / map.size(),
		this->getlevelSize().y / map.size());
	vector<MovingObject*> movingsVec = {};

	this->m_levelNumber++;
	m_levelSize = m_levelReader.getLevelSize();
	this->releaseMap();
	for (int i = 0; i < map.size(); i++) {
		std::vector<GameObject*> row = {};
		for (int j = 0; j < map[i].size(); j++) {
			switch (map[i][j])
			{
			case PLAYER: {
				movingsVec.push_back(new Player(sf::Vector2f(boxSize.x * j, boxSize.y * i) + this->m_location, effects, boxSize));
				row.push_back(nullptr);
				break;
			}
			case ENEMY: {
				movingsVec.push_back(new RandEnemy(sf::Vector2f(boxSize.x * j, boxSize.y * i) + this->m_location, effects, boxSize));
				row.push_back(nullptr);
				break;
			}
			case COIN: {
				row.push_back(new Coin(sf::Vector2f(boxSize.x * j, boxSize.y * i) + this->m_location,  effects,boxSize));
				break;
			}
			case WALL: {
				row.push_back(new Wall(sf::Vector2f(boxSize.x * j, boxSize.y * i) + this->m_location,  effects, boxSize));
				break;
			}
			case LADDER: {
				row.push_back(new Ladder(sf::Vector2f(boxSize.x * j, boxSize.y * i) + this->m_location, effects, boxSize));
				break;
			}
			case ROD: {
				row.push_back(new Rod(sf::Vector2f(boxSize.x * j, boxSize.y * i) + this->m_location, effects, boxSize));
				break;
			}
			default: {
				row.push_back(NULL); // inputed ' '
				break;
			}
			}
		}
		this->m_map.push_back(row);
	}

	//set time level, if exist:
	this->m_levelTime = m_levelReader.getLevelTime();
	//set background of the level:
	m_background.setSize(m_backgroundSize);
	m_background.setPosition(m_location);
	m_background.setTexture(&effects.getTexture(m_levelNumber));
	return movingsVec;
}
//========================================================================
bool Board::is_next_lvl_exist()const {
	return m_levelReader.isThereNextLevel();
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
//========================================================================
sf::Vector2f Board::getlevelSize()const{
	return this->m_backgroundSize;
}
//========================================================================
const sf::Vector2f& Board::getLocation() const { return this->m_location; }
//========================================================================
void Board::releaseMap() {
	for (int i = 0; i < this->m_map.size(); ++i) {
		for (int j = 0; j < this->m_map[i].size(); ++j) {
			if (this->m_map[i][j] != nullptr)
				this->m_map[i][j]->~GameObject();
			this->m_map[i][j] = nullptr;
		}
	}
}
//========================================================================
GameObject* Board::getContent(const sf::Vector2f location) const{
if (!this->m_background.getGlobalBounds().contains(location))
		return nullptr;
	float objectWidth = this->m_backgroundSize.x / this->m_levelSize.x,
		objectHeight = this->m_backgroundSize.y / this->m_levelSize.y;
	
	return this->m_map[location.x / objectWidth]
	[location.y / objectHeight];
}