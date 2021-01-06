#include "DataReader.h"
#include "Macros.h"
#include "Utilities.h"
#include <vector>
#include "Player.h"
#include "SmartEnemy.h"
#include "Coin.h"
#include "Ladder.h" 
#include "Wall.h"
#include "Rod.h"
#include <iostream>
using std::endl;
//========================================================================
DataReader::DataReader() 
	: m_levelSize({}),m_levelTime(NO_LEVEL_TIME){
	this->m_boardReader.open(BOARD_PATH);
	if(!this->m_boardReader.is_open())
		terminate
		("Cannot open the levels file, pls make sure the file is exist");

	//this->readNextLevel(); //read the first level
}
//========================================================================
DataReader::~DataReader() {
	this->m_boardReader.close();
}
//========================================================================
void DataReader::receiveLevelParameters(){
	m_boardReader >> m_levelSize.x >> m_levelSize.y;
	m_boardReader >> m_levelTime;
	char eat_space;
	m_boardReader >> eat_space;
}
//========================================================================
/*
  This function return true if a new level is exist in the inputed file
  or false if all the levels is over.
*/
bool DataReader::isThereNextLevel()const {
	return (!this->m_boardReader.eof());
}
//========================================================================
vector<vector<GameObject*>> DataReader::readNextLevel() {
	//1. allocate 2D vector of game objs
	vector<vector<GameObject*>> newLevel = {};
	//2. check first if there is more level in the file
	if (this->isThereNextLevel()) {
		char input;
		//3. receive size & time of the level
		this->receiveLevelParameters();
	    //4. read the level itself from the file
		for (int i = 0; i < m_levelSize.x; i++) {
			std::vector<GameObject*> row = {};
			for (int j = 0; j < m_levelSize.y; j++) {
				m_boardReader.get(input);
				switch (input)
				{
				case PLAYER: {
					row.push_back(new Player(sf::Vector2f((float)j,(float)i),
						sf::Vector2f((float)OBJ_WIDTH,(float)OBJ_HEIGHT),
						STAND,PLAYER_T));
					break;
				}
						   
				case ENEMY: {
					row.push_back(new SmartEnemy(sf::Vector2f((float)j, (float)i),
						sf::Vector2f((float)OBJ_WIDTH, (float)OBJ_HEIGHT),
						STAND, ENEMY_T));
					break;
				}
				case COIN: {
					row.push_back(new Coin(sf::Vector2f((float)j, (float)i),
						sf::Vector2f((float)OBJ_WIDTH, (float)OBJ_HEIGHT),
						NOT_COLLECTED, COIN_T));
					break;
				}
				case WALL: {
					row.push_back(new Wall(sf::Vector2f((float)j, (float)i),
						sf::Vector2f((float)OBJ_WIDTH, (float)OBJ_HEIGHT),
						EXIST, WALL_T));

					break;
				}
				case LADDER: {
					row.push_back(new Ladder(sf::Vector2f((float)j, (float)i),
						sf::Vector2f((float)OBJ_WIDTH, (float)OBJ_HEIGHT),
						NOT_CLIMBED,  LADDER_T));
					break;
				}
				case ROD: {
					row.push_back(new Rod(sf::Vector2f((float)j, (float)i),
						sf::Vector2f((float)OBJ_WIDTH, (float)OBJ_HEIGHT),
						NOT_CLIMBED,  ROD_T));
					break;
				}
				
				default: {
					row.push_back(NULL); // inputed ' '
					break;
				}
				}
			}
			if (m_boardReader.peek() != '\0')
				m_boardReader.get(input);
			newLevel.push_back(row);
		}
	}
	return newLevel;
}
//========================================================================
sf::Vector2f DataReader::getLevelSize()const { return this->m_levelSize; }
int DataReader::getLevelTime()const { return this->m_levelTime; }