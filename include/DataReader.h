#pragma once
#include "GameObject.h"
#include <fstream>

class DataReader{
public:
	//------------------------- constractors section -------------------------

	DataReader();
	~DataReader();

	//------------------------- method section -------------------------------

	bool isThereNextLevel();
	vector<vector<GameObject*>> readNextLevel();
private:
	//--------------------- privete methods section --------------------------

	void receiveLevelParameters();
	//------------------------ members section -------------------------------

	std::ifstream m_boardReader;
	sf::Vector2f m_fileSize;
	int m_timeLevel;
};