//============================= include section ==============================
//#include "Menu.h"
#include "Board.h"
#include "EffectsHolder.h"
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <stdlib.h>
#include <iostream>
//============================== main section ================================
int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(),"Lode Runner", sf::Style::Fullscreen);
	Board board(window.getSize());
	while (window.isOpen())
	{
		window.clear();
		board.draw(window);
		window.display();
		sf::Event event;
		while (window.waitEvent(event)) {

		}
	}
	return EXIT_SUCCESS;
}
