#pragma once
#include "Board.h"
#include "Menu.h"
#include "GameState.h"
#include "EffectsHolder.h"
#include "MovingObjects.h"
#include <SFML/Graphics.hpp>
class Controller
{
public:
	Controller();
	void runGame();
private:
	sf::RenderWindow m_window;
	Board m_board;
	Menu m_menu;
	GameState m_gameState;
	EffectsHolder m_effects;
	vector<MovingObjects*> m_movingObjects;
};

Controller::Controller()
{
}

Controller::~Controller()
{
}
