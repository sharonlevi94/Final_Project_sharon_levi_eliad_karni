#include "DataReader.h"
#include "Macros.h"
#include "Utilities.h"
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Coin.h"
#include "Ladder.h"
#include "Wall.h"
#include "Rod.h"
using std::endl;
//========================================================================
DataReader::DataReader(){
	this->m_boardReader.open(BOARD_PATH);
	if(!this->m_boardReader.is_open())
		terminate
		("Cannot open the levels file, pls make sure the file is exist");
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
	vector<vector<GameObject*>> newLevel = {};
	if (this->isThereNextLevel()) {
		char input;
		this->receiveLevelParameters();
		for (int i = 0; i < m_levelSize.x; i++) {
			std::vector<GameObject*> row = {};
			for (int j = 0; j < m_levelSize.y; j++) {
				m_boardReader >> input;
				switch (input)
				{
				case PLAYER: {
					row.push_back(new Player);
					break;
				}
				case ENEMY: {
					row.push_back(new Enemy);
					break;
				}
				case COIN: {
					row.push_back(new Coin);
					break;
				}
				case WALL: {
					row.push_back(new Wall);
					break;
				}
				case LADDER: {
					row.push_back(new Ladder);
					break;
				}
				case ROD: {
					row.push_back(new Rod);
					break;
				}
				default: {
					row.push_back(NULL); // inputed ' '
					break;
				}
				}
			}
			newLevel.push_back(row);
			m_boardReader >> input; //eat \n
		}
	}
	return newLevel;
}
//========================================================================
sf::Vector2f DataReader::getLevelSize()const { return this->m_levelSize; }
int DataReader::getLevelTime()const { return this->m_levelTime; }