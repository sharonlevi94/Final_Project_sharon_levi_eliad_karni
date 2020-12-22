#pragma once
#include "GameObject.h"
#include <fstream>
class DataReader{
public:
	//------------------------- constractors section -------------------------

	DataReader();

	//------------------------- method section -------------------------------

	bool isThereNextLevel()const;
	vector<vector<GameObjects*>> readNextLevel();
private:
	//--------------------- privete methods section --------------------------

	int receiveMapSize();

	//------------------------ members section -------------------------------

	std::ifstream m_boardReader;
	int m_fileSize;
};