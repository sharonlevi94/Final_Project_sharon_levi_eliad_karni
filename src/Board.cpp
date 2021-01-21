/*
   This file conatains all methods of the class Board.
*/
//============================= include section ==========================
#include "Board.h"
#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Macros.h"
#include "ResoucesHolder.h"
#include <vector>
#include "Utilities.h"
#include "Player.h"
#include "Enemy.h"
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
//====================== Constructors & distructors section ==================
Board::Board(const sf::Vector2f& location,
             const sf::Vector2f& size)
	: m_levelReader(DataReader()),
	m_background(sf::RectangleShape()),
	m_location(location),
	m_door(nullptr),
	m_player(nullptr){
	this->m_background.setSize(size);
	m_background.setPosition(m_location);
}
//================================ gets section ==============================
//============================================================================
const sf::Vector2f& Board::getlevelSize()const {
	return this->m_background.getSize();
}
//============================================================================
const sf::Vector2f& Board::getLocation() const {
	return this->m_location;
}
//============================================================================
int Board::getLevelTime()const {
	return this->m_levelReader.getLevelTime();
}
//============================================================================
const sf::Vector2f& Board::getDoorLocation()const {
	return this->m_door.get()->getLocation();
}
//============================================================================
const sf::Vector2f& Board::getPlayerLoc()const {
	return this->m_player->getLocation();
}
//============================================================================
/* this method is not const because it gives its user ability to change
 * game objects statuses.
 */
StaticObject* Board::getContent(const sf::Vector2f& location) {
	if (!this->m_background.getGlobalBounds().contains(location))
		return nullptr;
	int x = (int)((location.x - this->m_location.x) /
		(this->getlevelSize().x / this->m_map[0].size())),
		y = (int)((location.y - this->m_location.y) /
			(this->getlevelSize().y / this->m_map.size()));
	if(dynamic_cast <StaticObject*> (this->m_map[y][x].get()))
		return ((StaticObject*)this->m_map[y][x].get());
	return nullptr;
}
//============================================================================
const StaticObject* Board::getContent(const sf::Vector2f& location) const {
	if (!this->m_background.getGlobalBounds().contains(location))
		return nullptr;
	int x = (int)((location.x - this->m_location.x) /
		(this->getlevelSize().x / this->m_map[0].size())),
		y = (int)((location.y - this->m_location.y) /
			(this->getlevelSize().y / this->m_map.size()));
	if (dynamic_cast <StaticObject*> (this->m_map[y][x].get()))
		return ((StaticObject*)this->m_map[y][x].get());
	return nullptr;
}
//============================================================================
sf::Vector2f Board::getObjectSize()const{
	return sf::Vector2f{ this->getlevelSize().x / this->m_map[0].size(),
		this->getlevelSize().y / this->m_map.size() };
}
//============================ methods section ===============================
void Board::draw(sf::RenderWindow& window, 
	const sf::Time& deltaTime){
	window.draw(m_background);
	this->m_door->draw(window);
	for (int i = 0; i < this->m_map.size(); i++)
		for (int j = 0; j < this->m_map[i].size(); j++)
			if (m_map[i][j].get() != nullptr) {
				m_map[i][j]->draw(window);
			}
}
//============================================================================
/* 
 * This function update the objects of the game to the current level game.
 * the function build a vector of moving objects ptrs & return it.
 */
vector<MovingObject*> Board::loadNewLevel() {
	vector<vector<char>> map = m_levelReader.readNextLevel();
	vector<MovingObject*> movingsVec = {};
			sf::Vector2f boxSize(this->getlevelSize().x / map[0].size(),
		this->getlevelSize().y / map.size());

	//reset last load parameters:
	this->releaseMap();
	this->clearParameters();
	this->m_map.resize(map.size());

	//allocating level's objects:
	for (int y = 0; y < map.size(); ++y) {
		for (int x = 0; x < map[y].size(); x++) {
			switch (map[y][x])
			{
			case PLAYER: 
				this->m_map[y].push_back(std::make_unique <Player> (sf::Vector2f
				(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				movingsVec.push_back((MovingObject*)this->m_map[y][x].get());
				this->m_player = (Player*)this->m_map[y][x].get();
				//door location:
				if (!this->m_door)
					this->m_door = std::make_unique <Door>(sf::Vector2f
					(boxSize.x * x, boxSize.y * y) + this->m_location, 
						boxSize);
				break;
			case ENEMY:
				this->m_map[y].push_back(std::unique_ptr <Enemy>
					(raffleEnemy(boxSize, sf::Vector2f(boxSize.x * x, boxSize.y * y) + this->m_location)));
				movingsVec.push_back((MovingObject*)this->m_map[y][x].get());
				break;
			case COIN:
				this->m_map[y].push_back(std::make_unique <Coin>(sf::Vector2f
				(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				break;
			case WALL:
				this->m_map[y].push_back(std::make_unique <Wall>(sf::Vector2f
				(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				break;
			case LADDER:
				this->m_map[y].push_back(std::make_unique <Ladder>(sf::Vector2f
				(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				break;
			case ROD:
				this->m_map[y].push_back(std::make_unique <Rod>(sf::Vector2f
				(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize));
				break;
			case GIFT:
				this->m_map[y].push_back(std::unique_ptr <Gift>
					(raffleGift(boxSize, { x,y })));
				break;
			case DOOR:
				this->m_door = std::make_unique <Door>(sf::Vector2f
				(boxSize.x * x, boxSize.y * y) + this->m_location, boxSize);
				this->m_map[y].push_back(nullptr);
				break;
			default:
				this->m_map[y].push_back(nullptr); // inputed ' '
				break;
			}
		}
	}
	return movingsVec;
}
//============================================================================
//the method isn't const because fstream's peek method isn't const
bool Board::is_next_lvl_exist() const{
	return m_levelReader.isThereNextLevel();
}
//============================================================================
bool Board::isMovePossible(const sf::Vector2f& location) const {
	if (this->m_background.getGlobalBounds().contains(location))
		return true;
	return false;
}
//============================================================================
/*
* This function pass all the map and reset every object to the initial location
* and state.
*/
void Board::resetLvl(){
	for (int i = 0; i < this->m_map.size(); ++i)
		for (int j = 0; j < this->m_map[i].size(); ++j) {
			if(this->m_map[i][j].get() != nullptr)
				this->m_map[i][j]->reset();
		}
}
//============================================================================
void Board::gameOver() {
	this->m_levelReader.resetRead();
	this->releaseMap();
	//this->m_door.release();
	this->m_player = nullptr;
}
//============================================================================
/*
* This function load the background and the music of the current level.
*/
void Board::loadLevelEffects(int level) {
	this->m_background.setTexture(&ResoucesHolder::instance()
		.getBackground(level));
	ResoucesHolder::instance().playMusic(level);
}
//============================== private section =============================
void Board::releaseMap() {
	this->m_map.clear();
}
//============================================================================
void Board::clearParameters() {
	this->releaseMap();
	this->m_door.release();
	this->m_player = nullptr;
}
//============================================================================
/*
* This function called in load new level function to raffle the type of the
* gift. The function return a ptr to the type of gift it raffled.
*/
Gift* Board::raffleGift(const sf::Vector2f& boxSize,const sf::Vector2i& index) {
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
//============================================================================