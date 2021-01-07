#pragma once
#include "GameObject.h"
#include <vector>
#include <fstream>

class DataReader{
public:
	//------------------------- constractors section -------------------------
	DataReader();
	~DataReader();
	//------------------------- method section -------------------------------
	bool isThereNextLevel()const;
	vector<vector<char>> readNextLevel();
	sf::Vector2f getLevelSize()const;
	int getLevelTime()const;
private:
	//--------------------- privete methods section --------------------------
	void receiveLevelParameters();
	//------------------------ members section -------------------------------

	std::ifstream m_boardReader;
	sf::Vector2f m_levelSize;
	int m_levelTime;
};