//============================= include section ==============================
#include "GameState.h"
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <stdlib.h>
//============================== main section ================================
int main()
{
	//const sf::Drawable&, const sf::RenderStates&

	sf::RenderWindow window(sf::VideoMode::getDesktopMode(),"Lode Runner", sf::Style::Fullscreen);
		//(sf::VideoMode(800,600),"Rod Runner");
	GameState gamestate;
	
	sf::Texture tex;
	tex.loadFromFile("MenuBackground.jpg");
	sf::Sprite sp;
	
	sp.setTexture(tex);
	window.draw(sp);
	
	//gamestate.test(gamestate.died);
	//gamestate.draw(window);
	window.display();
	sf::Event event{};
	while (window.waitEvent(event)) {
		switch (event.type) {
		case sf::Event::KeyPressed:
			window.close();
			break;
		}
	}
	return EXIT_SUCCESS;
}
