#include "DataReader.h"
#include "Macros.h"
#include "Utilities.h"
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
	m_boardReader >> m_fileSize.x >> m_fileSize.y;
	m_boardReader >> m_timeLevel;

}
//========================================================================
bool DataReader::isThereNextLevel() {
	return (this->m_boardReader.peek() == '\n');
}
//========================================================================