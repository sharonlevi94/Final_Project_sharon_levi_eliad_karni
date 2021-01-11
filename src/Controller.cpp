//============================= include section ==============================
#include "Controller.h"
#include "Menu.h"
#include "Board.h"
#include "GameState.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Controller::Controller() :
	m_window(sf::VideoMode::getDesktopMode(), "Lode Runner",
		sf::Style::Fullscreen),
	m_effects(),
	m_board(sf::Vector2f(0, (float)this->m_window.getSize().y * 0.1f),
		sf::Vector2f((float)m_window.getSize().x, (float)m_window.getSize().y * (0.9f)),
		this->m_effects),
	m_enemies({}),
	m_player(nullptr){
	this->m_menu = Menu(this->m_effects,
		(sf::Vector2f)this->m_window.getSize(),
		sf::Vector2f(0, 0));
	this->m_gameState = GameState(this->m_effects, sf::Vector2f(0, 0),
		sf::Vector2f((float)(this->m_window.getSize().x),
		this->m_window.getSize().y * 0.08f));
}
//============================== gets section ================================
//============================ methods section ===============================
void Controller::run() {
	while (true) {
		this->m_window.clear();
		char choose = this->runMenu();
		if (!this->m_window.isOpen() || choose == 'q')
			break;
		if (choose == 's')
			this->runGame();
		if (!this->m_window.isOpen())
			break;
	}
}
//============================================================================
char Controller::runMenu() {
	while (this->m_window.isOpen())
	{
		//displaying menu state
		this->m_window.clear();
		this->m_menu.draw(this->m_window);
		this->m_window.display();
		//recevive user movments
		sf::Event event{};
		while (this->m_window.waitEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				this->m_window.close();
				break;
			case sf::Event::MouseButtonReleased:
				switch (this->m_menu.handleClick(sf::Vector2f(
					(float)event.mouseButton.x, 
					(float)event.mouseButton.y))) {
				case 's':
					return 's';
				case 'q':
					return 'q';
					break;
				}
				break;
			default:
				if (this->m_menu.pointingHundle((sf::Vector2f)
					sf::Mouse::getPosition(this->m_window))) {
					this->m_menu.draw(this->m_window);
					this->m_window.display();
				}
				break;
			}

		}
	}
	return 'q';
}
//============================================================================
void Controller::runGame() {
	this->m_gameState.levelup(-1);
	this->seperateGameObjects(this->m_board.loadNewLevel(this->m_effects));
	while (this->m_window.isOpen()){
				this->m_window.clear();
				this->m_gameState.draw(this->m_window);
				this->m_board.draw(m_window);
				this->drawObjects();
				this->m_window.display();

				sf::Event event = {};
				while (m_window.pollEvent(event)) {
					if (event.type == sf::Event::MouseButtonReleased)
						//m_window.close();
						this->runMenu();
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
						m_window.close();

				}
				sf::Time deltaTime = m_clock.restart();
				this->play_turns(deltaTime);
					if (this->m_player->is_alive())
						this->resetLevel();
					else
						this->gameOver();			
	}
}
//============================================================================
void Controller::play_turns(const sf::Time& deltaTime) {
	//the player is playing:
	this->m_player->playTurn(deltaTime, this->m_board);
	//enemies are playing:
	for (int i = 0; i < this->m_enemies.size(); ++i) {
		this->m_enemies[i]->playTurn(deltaTime, this->m_board);
		if (this->m_enemies[i]->CollidesWith(*this->m_player))
			this->m_player->handleColision(*(Enemy*)this->m_enemies[i]);
	}
}
//============================================================================
void Controller::drawObjects() {
	this->m_player->draw(this->m_window);
	for (int i = 0; i < this->m_enemies.size(); ++i)
		this->m_enemies[i]->draw(this->m_window);
}
//============================================================================
void Controller::seperateGameObjects(const vector<MovingObject*>& list) {
	for (int i = 0; i < list.size(); ++i) {
		if (dynamic_cast <Player*> (list[i]))
			this->m_player = (Player*)list[i];
		else
			this->m_enemies.push_back(list[i]);
	}
}
//============================================================================
void Controller::resetLevel(){
	this->m_player->setLocation(m_player->getInitialLoc());
	for (int i=0; i < m_enemies.size(); i++)
		this->m_enemies[i]->setLocation(this->m_enemies[i]->getInitialLoc());
}
//============================================================================
void Controller::gameOver() { }
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================