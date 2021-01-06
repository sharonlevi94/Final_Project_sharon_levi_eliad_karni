#pragma once
#include "Board.h"
#include "Menu.h"
#include "GameState.h"
#include "EffectsHolder.h"
#include "MovingObject.h"
//#include "Board.h"
#include "Enemy.h"
#include "Player.h"
#include "Coin.h"
#include <SFML/Graphics.hpp>
class Controller
{
public:
	Controller();
	void run();
	void runGame();
	char runMenu();
	//void resetLevel() const;
	//void play_turns();

private:
	sf::RenderWindow m_window;
	//Board m_board;
	Menu m_menu;
	GameState m_gameState;
	EffectsHolder m_effects;
	//vector <GameObject*> m_gameobjects;
	//Player* m_player;
};