/*
   This file conatains all methods of the class Board.
*/
#include "Board.h"
#include "MovingObject.h"
#include "Macros.h"
#include "Utilities.h"
#include "Player.h"
#include "SmartEnemy.h"
#include "Coin.h"
#include "Ladder.h" 
#include "Wall.h"
#include "Rod.h"
//==================== Constructors & distruors section ====================
Board::Board(const sf::Vector2f& location,
             const sf::Vector2f& size, 
			 const EffectsHolder& effects)
	: m_levelReader(DataReader()),
	m_location(location),
	m_map({}),
	m_background(),
	m_levelSize(size){
}
//========================================================================
void Board::draw(sf::RenderWindow& window)const {
	window.draw(m_background);
	for (int i = 0; i < m_levelSize.x; i++)
		for (int j =0; j < m_levelSize.y; j++)
			if (m_map[i][j] != nullptr) {
				m_map[i][j]->draw(window);
			}
}
//========================================================================
std::vector<MovingObject*> Board::loadNewLevel(const EffectsHolder& effects) {
	std::vector<std::vector<char>> map = m_levelReader.readNextLevel();
	sf::Vector2f boxSize(this->getlevelSize().x / map.size(),
		this->getlevelSize().y / map.size());
	std::vector<std::MovingObject*> movingsVec = {};

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
				movingsVec.push_back(new SmartEnemy(sf::Vector2f(boxSize.x * j, boxSize.y * i) + this->m_location, effects, boxSize));
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

	//set background of the level:
	m_background.setTexture(effects.getTexture(1));
	m_background.setScale(sf::Vector2f(this->m_levelSize.x / this->m_background.getTexture()->getSize().x,
		this->m_levelSize.y / this->m_background.getTexture()->getSize().y));
	m_background.setPosition(m_location);
	return movingsVec;
}
//========================================================================
bool Board::is_next_lvl_exist()const {
	return m_levelReader.isThereNextLevel();
}
//========================================================================
int Board::getLevelTime()const {
		return this->m_levelReader.getLevelTime();
}
//========================================================================
sf::Vector2f Board::getlevelSize()const{
	return this->m_levelSize;
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