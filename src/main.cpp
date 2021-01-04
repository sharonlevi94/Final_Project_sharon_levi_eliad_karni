//============================= include section ==============================
<<<<<<< HEAD
//#include "Menu.h"
#include "Board.h"
=======
#include "Menu.h"
//#include "Board.h"
#include "EffectsHolder.h"
>>>>>>> 39b3668305aeedb950c97089f8dc9e9fe8b71363
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <stdlib.h>
#include <iostream>
//============================== main section ================================
int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(),"Lode Runner", sf::Style::Fullscreen);
	EffectsHolder effects;
	//GameState gamestate;
<<<<<<< HEAD
    //Menu menu;
	Board board(window.getSize());
=======
    Menu menu(effects, (sf::Vector2f)window.getSize(), sf::Vector2f(0,0));
	//Board board(window.getSize());
>>>>>>> 39b3668305aeedb950c97089f8dc9e9fe8b71363
	
	while (window.isOpen())
	{
		window.clear();
		board.draw(window);
		//menu.draw(window);
		//board.draw(window);     

		window.display();
		sf::Event event{};
		while (window.waitEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				switch (menu.handleClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
				case 's':
					std::cout << "game started!\n";
					window.close();
					break;
				case 'q':
					std::cout << "quited game!\n";
					window.close();
					break;
				}
				break;
			default:
				if (menu.pointingHundle((sf::Vector2f)sf::Mouse::getPosition(window))) {
					menu.draw(window);
					window.display();
				}
				break;
			}
			
		}
	}
	//gamestate.test(gamestate.died);
	//gamestate.draw(window);
	return EXIT_SUCCESS;
}
