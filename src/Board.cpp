/*
   This file conatains all methods of the class Board.
*/
//============================= include section ==========================
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
#include "TimeGift.h"
#include "LifeGift.h"
#include "ScoreGift.h"
#include "BadGift.h"
#include "Door.h"
using std::vector;
//==================== Constructors & distructors section ================
Board::Board(const sf::Vector2f& location,
             const sf::Vector2f& size)
	: m_levelReader(DataReader()),
	m_background(sf::RectangleShape()),
	m_location(location),
	m_levelSize(size),
	m_door(nullptr),
	m_player(nullptr){
	this->m_background.setSize(size);
	m_background.setPosition(m_location);
}
//========================================================================
Board::~Board() {
	this->releaseMap();
}
//============================== gets section ============================
sf::Vector2f Board::getlevelSize()const {
	return this->m_background.getSize();
}
//========================================================================
const sf::Vector2f& Board::getLocation() const {
	return this->m_location;
}
//========================================================================
int Board::getLevelTime()const {
	return this->m_levelReader.getLevelTime();
}
//========================================================================
const sf::Vector2f& Board::getDoorLocation()const {
	return this->m_door->getLocation();
}
//========================================================================
const sf::Vector2f& Board::getPlayerLoc()const {
	return this->m_player->getLocation();
}
//========================================================================
/* this method is not const because it gives its user ability to change
 * game objects statuses.
 */
GameObject* Board::getContent(const sf::Vector2f& location) {
	if (!this->m_background.getGlobalBounds().contains(location))
		return nullptr;
	int x = (int)((location.x - this->m_location.x) /
		(this->getlevelSize().x / this->m_map[0].size())),
		y = (int)((location.y - this->m_location.y) /
			(this->getlevelSize().y / this->m_map.size()));
	return this->m_map[y][x].get();
}
//========================================================================
const GameObject* Board::getContent(const sf::Vector2f& location) const {
	if (!this->m_background.getGlobalBounds().contains(location))
		return nullptr;
	int x = (int)((location.x - this->m_location.x) /
		(this->getlevelSize().x / this->m_map[0].size())),
		y = (int)((location.y - this->m_location.y) /
			(this->getlevelSize().y / this->m_map.size()));
	return this->m_map[y][x].get();
}

//============================ methods section ===========================
void Board::draw(sf::RenderWindow& window, 
	const sf::Time& deltaTime){
	window.draw(m_background);
	this->m_door->draw(window, deltaTime);
	for (int i = 0; i < m_levelSize.x; i++)
		for (int j = 0; j < m_levelSize.y; j++)
			if (m_map[i][j].get() != nullptr) {
				m_map[i][j]->draw(window, deltaTime);
			}
}
//========================================================================
vector<MovingObject*> Board::loadNewLevel() {
	vector<vector<char>> map = m_levelReader.readNextLevel();

	sf::Vector2f boxSize(this->getlevelSize().x / map[0].size(),
		this->getlevelSize().y / map.size());

	vector<MovingObject*> movingsVec = {};

	m_levelSize = m_levelReader.getLevelSize();
	this->releaseMap();

	this->clearParameters();
	for (int y = 0; y < map.size(); ++y) {
		std::vector<std::unique_ptr<GameObject>> row;
		row.resize(0);
		for (int x = 0; x < map[y].size(); x++) {
			switch (map[y][x])
			{
			case PLAYER: {
				row.push_back(std::make_unique <Player> (sf::Vector2f
				(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				movingsVec.push_back((MovingObject*)row[x].get());
				this->m_player = (Player*)row[x].get();
				//door location:
				if (!this->m_door)
					this->m_door = std::make_unique <Door>(sf::Vector2f
					(boxSize.x * x, boxSize.y * y) + this->m_location, 
						boxSize);
				break;
			}
			case ENEMY: {
				row.push_back(std::unique_ptr <Enemy>
					(raffleEnemy(boxSize, { x,y })));
				movingsVec.push_back((MovingObject*)row[x].get());
				break;
			}
			case COIN: {
				row.push_back(std::make_unique <Coin>(sf::Vector2f
				(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				break;
			}
			case WALL: {
				row.push_back(std::make_unique <Wall>(sf::Vector2f
				(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				break;
			}
			case LADDER: {
				row.push_back(std::make_unique <Ladder>(sf::Vector2f
				(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				break;
			}
			case ROD: {
				row.push_back(std::make_unique <Rod>(sf::Vector2f
				(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				break;
			}
			case GIFT: {
				row.push_back(std::unique_ptr <Gift>
					(raffleGift(boxSize, { x,y })));
			}
				break;
			case DOOR: {
				this->m_door = std::make_unique <Door>(sf::Vector2f
				(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize);
				row.push_back(NULL);
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
	return movingsVec;
}
//========================================================================
//the method isn't const because fstream's peek method isn't const
bool Board::is_next_lvl_exist() const{
	return m_levelReader.isThereNextLevel();
}
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
	this->m_door.release();
	this->m_player = nullptr;
}
//========================================================================
void Board::loadLevelEffects(int level) {
	this->m_background.setTexture(&EffectsHolder::instance()
		.getBackground(level));
	EffectsHolder::instance().playMusic(level);
}
//========================================================================

//============================ private section ===========================
void Board::releaseMap() {
	this->m_map.clear();
}
//========================================================================
void Board::clearParameters() {
	this->releaseMap();
	this->m_door.release();
	this->m_player = nullptr;
}
//========================================================================
Gift* Board::raffleGift(const sf::Vector2f& boxSize,
	const sf::Vector2i& index) {
	//srand was declared in the controller
	switch (rand() % NUM_OF_GIFT_TYPES)
	{
	case 0:
		return new TimeGift(sf::Vector2f(boxSize.x *
			index.x, boxSize.y * index.y) + this->m_location, boxSize);
	case 1:
		return new BadGift(sf::Vector2f(boxSize.x *
			index.x, boxSize.y * index.y) + this->m_location, boxSize);
	case 2:
		return new ScoreGift(sf::Vector2f(boxSize.x *
			index.x, boxSize.y * index.y) + this->m_location, boxSize);
	default:
		return new LifeGift(sf::Vector2f(boxSize.x *
			index.x, boxSize.y * index.y) + this->m_location, boxSize);
	}
}
//========================================================================
Enemy* Board::raffleEnemy(const sf::Vector2f& boxSize,
	const sf::Vector2i& index) {
	//srand was declared in the controller
	switch (rand() % NUM_OF_ENEMIES_TYPES)
	{
	case 0:
		return new RandEnemy(sf::Vector2f(boxSize.x *
			index.x, boxSize.y * index.y) + this->m_location, boxSize);
	case 1:
		return new FoolEnemy(sf::Vector2f(boxSize.x *
			index.x, boxSize.y * index.y) + this->m_location, boxSize);
	default:
		return new SmartEnemy(sf::Vector2f(boxSize.x *
			index.x, boxSize.y * index.y) + this->m_location, boxSize);
	}
}