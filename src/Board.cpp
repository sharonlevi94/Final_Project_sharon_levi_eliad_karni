/*
   This file conatains all methods of the class Board.
*/
#include "Board.h"
#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Macros.h"
#include "EffectsHolder.h"
#include <vector>
#include "Utilities.h"
#include "Player.h"
#include "SmartEnemy.h"
#include "RandEnemy.h"
#include "FoolEnemy.h"
#include "Coin.h"
#include "Ladder.h" 
#include "Wall.h"
#include "Rod.h"
#include "Gift.h"
#include "Door.h"
using std::vector;
//==================== Constructors & distruors section ====================
Board::Board(const sf::Vector2f& location,
             const sf::Vector2f& size)
	: m_levelReader(DataReader()),
	m_background(sf::RectangleShape()),
	m_location(location),
	m_levelNumber(0),
 	m_backgroundSize(size),
	m_levelSize(size),
	m_levelTime(0),
	m_doorIndex({0,0}),
	m_playerIndex({0,0})
{}
//========================================================================
Board::~Board() {
	this->releaseMap();
}
//========================================================================
void Board::draw(sf::RenderWindow& window, 
	const sf::Time& animationTime){
	window.draw(m_background);
	for (int i = 0; i < m_levelSize.x; i++)
		for (int j = 0; j < m_levelSize.y; j++)
			if (m_map[i][j].get() != nullptr) {
				m_map[i][j]->draw(window, animationTime);
			}
}
//========================================================================
vector<MovingObject*> Board::loadNewLevel() {
	srand((unsigned int)time(NULL)); //for random gifts
	vector<vector<char>> map = m_levelReader.readNextLevel();

	sf::Vector2f boxSize(this->getlevelSize().x / map[0].size(),
		this->getlevelSize().y / map.size());

	vector<MovingObject*> movingsVec = {};

	this->m_levelNumber++;
	m_levelSize = m_levelReader.getLevelSize();
	this->releaseMap();
	for (int y = 0; y < map.size(); ++y) {
		std::vector<std::unique_ptr<GameObject>> row;
		row.resize(0);
		for (int x = 0; x < map[y].size(); x++) {
			switch (map[y][x])
			{
			case PLAYER: {
				row.push_back(std::make_unique <Player> (sf::Vector2f(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				movingsVec.push_back((MovingObject*)row[x].get());
				this->m_playerIndex.x = x;
				this->m_playerIndex.y = y;
				break;
			}
			case ENEMY: {
				row.push_back(std::make_unique <SmartEnemy>(sf::Vector2f(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				movingsVec.push_back((MovingObject*)row[x].get());
				break;
			}
			case COIN: {
				row.push_back(std::make_unique <Coin>(sf::Vector2f(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				break;
			}
			case WALL: {
				row.push_back(std::make_unique <Wall>(sf::Vector2f(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				break;
			}
			case LADDER: {
				row.push_back(std::make_unique <Ladder>(sf::Vector2f(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				break;
			}
			case ROD: {
				row.push_back(std::make_unique <Rod>(sf::Vector2f(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				break;
			}
			case GIFT: {
				row.push_back(std::make_unique <Gift>(sf::Vector2f(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				break;
			}
			case DOOR: {
				this->m_doorIndex.x = x;
				this->m_doorIndex.y = y;
				row.push_back(std::make_unique <Door>(sf::Vector2f(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));

				break;
			}
			default: {
				row.push_back(NULL); // inputed ' '
				break;
			}
			}
		}
		this->m_map.resize(m_map.size() + 1);
		this->m_map[y].resize(row.size());
		for (int i = 0; i < row.size(); ++i)
			this->m_map[y][i] = std::move(row[i]);
	}
	//set time level, if exist:
	this->m_levelTime = m_levelReader.getLevelTime();
	//set background of the level:
	m_background.setSize(m_backgroundSize);
	m_background.setPosition(m_location);
	m_background.setTexture(&EffectsHolder::instance().getBackground(m_levelNumber));

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
sf::Vector2f Board::getlevelSize()const {
	return this->m_backgroundSize;
}
//========================================================================
const sf::Vector2f& Board::getLocation() const { return this->m_location; }
//========================================================================
void Board::releaseMap() {
	this->m_map.resize(0);
}
//========================================================================
/* this method is not const because it gives its user ability to change
 * game objects statuses.
 */
GameObject* Board::getContent(const sf::Vector2f& location) {
	if (!this->m_background.getGlobalBounds().contains(location))
		return nullptr;
	int x = (int)((location.x - this->m_location.x) /
		(this->m_backgroundSize.x / this->m_map[0].size())),
		y = (int)((location.y - this->m_location.y) /
			(this->m_backgroundSize.y / this->m_map.size()));
	return this->m_map[y][x].get();
}
//========================================================================
const GameObject* Board::getContent(const sf::Vector2f& location) const {
	if (!this->m_background.getGlobalBounds().contains(location))
		return nullptr;
	int x = (int)((location.x - this->m_location.x) /
		(this->m_backgroundSize.x / this->m_map[0].size())),
		y = (int)((location.y - this->m_location.y) /
			(this->m_backgroundSize.y / this->m_map.size()));
	return this->m_map[y][x].get();
}
//========================================================================
int Board::getMovmentSpeed() const { return 250; }
//========================================================================
bool Board::isMovePossible(const sf::Vector2f& location) const {
	if (this->m_background.getGlobalBounds().contains(location)) {
		if (dynamic_cast <const Wall*> (this->getContent(location))) {
			if (((Wall*)this->getContent(location))->isDigged())
				return true;
			return false;
		}
		return true;
	}

	return false;
}
//========================================================================
void Board::resetLvl(){
	for (int i = 0; i < this->m_map.size(); ++i)
		for (int j = 0; j < this->m_map[i].size(); ++j) {
			if(this->m_map[i][j].get() != nullptr)
				this->m_map[i][j]->reset();
		}
}
//========================================================================
void Board::gameOver() {
	this->m_levelReader.resetRead();
	this->releaseMap();
	this->m_levelNumber = 0;
}
//========================================================================
const sf::Vector2f& Board::getDoorLocation()const {
	return this->m_map[this->m_doorIndex.y][this->m_doorIndex.x]
		->getLocation();
}
//========================================================================
const sf::Vector2f& Board::getPlayerLoc()const {
	return this->m_map[this->m_playerIndex.y][this->m_playerIndex.x]
		->getLocation();
}
