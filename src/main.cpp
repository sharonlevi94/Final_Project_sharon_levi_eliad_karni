//============================= include section ==============================
#include "GameState.h"
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <stdlib.h>
#include <inttypes.h>
#include <functional>
//============================== main section ================================
int main()
{
	//const sf::Drawable&, const sf::RenderStates&

	sf::RenderWindow window = 
		sf::RenderWindow(sf::VideoMode::getDesktopMode(),
			"Rod Runner", sf::Style::Fullscreen);
	GameState gamestate;
	gamestate.draw(window);
	window.display();
	Sleep(1000);
	return EXIT_SUCCESS;
}
