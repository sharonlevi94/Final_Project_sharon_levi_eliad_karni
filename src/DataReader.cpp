#include "DataReader.h"
#include "Macros.h"
#include "Utilities.h"
#include <vector>
#include <iostream>

using std::endl;
using std::vector;
//========================================================================
DataReader::DataReader() 
	: m_levelSize({}),m_levelTime(NO_LEVEL_TIME){
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
	//eat white space
	m_boardReader.get();
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
vector<vector<char>> DataReader::readNextLevel(){
	//1. allocate 2D vector of chars
	vector<vector<char>> newLevel = {};
	//2. check first if there is more level in the file
	if (this->isThereNextLevel()) {
		char input;
		//3. receive size & time of the level
		this->receiveLevelParameters();
	    //4. read the level itself from the file
		for (int i = 0; i < m_levelSize.x; i++) {
			std::vector<char> row = {};
			for (int j = 0; j < m_levelSize.y; j++) {
				m_boardReader.get(input);
				switch (input)
				{
				case PLAYER: {
					row.push_back(PLAYER);
					break;
				}
						   
				case ENEMY: {
					row.push_back(ENEMY);
					break;
				}
				case COIN: {
					row.push_back(COIN);
					break;
				}
				case WALL: {
					row.push_back(WALL);
					break;
				}
				case LADDER: {
					row.push_back(LADDER);
					break;
				}
				case ROD: {
					row.push_back(ROD);
					break;
				}
				case GIFT: {
					row.push_back(GIFT);
					break;
				}
				case DOOR: {
					row.push_back(DOOR);
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
		m_boardReader.get(input);
	}
	return newLevel;
}
//========================================================================
sf::Vector2f DataReader::getLevelSize()const { return this->m_levelSize; }
//========================================================================
int DataReader::getLevelTime()const { return this->m_levelTime; }
//========================================================================
void DataReader::resetRead() {
	this->m_boardReader.clear();
	this->m_boardReader.seekg(0);
	this->m_levelSize = {0, 0};
}