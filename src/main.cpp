//============================= include section ==============================
//#include "Menu.h"
#include "Board.h"
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <stdlib.h>
//============================== main section ================================
int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(),"Lode Runner", sf::Style::Fullscreen);

	//GameState gamestate;
    //Menu menu;
	Board board(window.getSize());
	
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
			case sf::Event::KeyPressed:
				window.close();
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
	}
	//gamestate.test(gamestate.died);
	//gamestate.draw(window);
	return EXIT_SUCCESS;
}
