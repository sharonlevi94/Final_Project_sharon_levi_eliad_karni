//============================= include section ==============================
#include "Controller.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Controller::Controller() :m_board(Board()), m_effects(EffectsHolder()),
m_gameobjects({}), m_gameState(GameState()), m_menu(Menu()),
m_player(nullptr),
m_window(sf::RenderWindow(sf::VideoMode::getDesktopMode(), 
	"Rod Runner", sf::Style::Fullscreen)) {}

//============================== gets section ================================
//============================ methods section ===============================

//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================