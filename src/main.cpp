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
	Sleep(5000);
	return EXIT_SUCCESS;
}
