//============================= include section ==============================
#include "GameState.h"
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <stdlib.h>
//============================== main section ================================
int main()
{
	sf::RenderWindow window = 
		sf::RenderWindow(sf::VideoMode::getDesktopMode(),
			"Rod Runner", sf::Style::Fullscreen);
	
	GameState gamestate;
	window.draw(sf::RectangleShape());
	gamestate(window.sf::RenderTarget::draw);
	//gamestate.draw(window);
	Sleep(10000);
	//gamestate.draw(&window.draw);
	return EXIT_SUCCESS;
}
