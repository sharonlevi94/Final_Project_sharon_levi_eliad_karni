//============================= include section ==============================
#include "Controller.h"
#include "Menu.h"
#include "Board.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Controller::Controller() :
	m_window(sf::VideoMode::getDesktopMode(), "Rod Runner",
		sf::Style::Fullscreen),
	m_effects(),
	m_board(sf::Vector2f(0, this->m_window.getSize().y / 10),
		sf::Vector2f(m_window.getSize().x, m_window.getSize().y* (9 / 10)),
		this->m_effects),
	m_gameobjects({}),
	m_player(nullptr){
	this->m_menu = Menu(this->m_effects,
		(sf::Vector2f)this->m_window.getSize(),
		sf::Vector2f(0, 0));
	this->m_gameState = GameState(this->m_effects, sf::Vector2f(0, 0), sf::Vector2f(this->m_window.getSize().x,
		this->m_window.getSize().y / 10));
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
	this->m_board.loadNewLevel(this->m_effects);
	while (this->m_window.isOpen()){
		this->m_window.clear();
		this->m_board.draw(m_window);
		this->m_window.display();
		//this->m_gameState.draw(this->m_window);
		if (m_clock.getElapsedTime().asSeconds() == 0.05) {
			m_clock.restart();
			this->play_turns();
		}
	}
}
//============================================================================
void Controller::play_turns() {
	for (int i = 0; i < this->m_gameobjects.size(); ++i)
		this->m_gameobjects[i]->playTurn();
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================