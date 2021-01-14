#pragma once
//============================ include section ===============================
#include "Board.h"
#include "Menu.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <vector>
//========================== forward declarations ============================
class MovingObject;
class Player;

class Controller
{
public:
	Controller();
	void run();
	void runGame();
	char runMenu();

	void enemiesTurns(const sf::Time&);
	void resetLevel();
	void seperateGameObjects(const vector<MovingObject*>&);
	void play_turns(const sf::Time&);
	void drawObjects();
	void gameOver();
	void checkColisions();


private:
	sf::RenderWindow m_window;
	Board m_board;
	Menu m_menu;
	GameState m_gameState;
	vector <MovingObject*> m_enemies;
	Player* m_player;
	sf::Clock m_clock;
};