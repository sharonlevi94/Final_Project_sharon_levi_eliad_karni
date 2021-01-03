//============================= include section ==============================
#include "GameState.h"
#include "Board.h"
#include "Menu.h"
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <stdlib.h>
//============================== main section ================================
int main()
{
	//const sf::Drawable&, const sf::RenderStates&

	sf::RenderWindow window(sf::VideoMode::getDesktopMode(),"Lode Runner", sf::Style::Fullscreen);
	//(sf::VideoMode(800,600),"Lode Runner");
	//GameState gamestate;
    //Menu menu;
	//Board board;
	sf::Texture menu_tex;
	menu_tex.loadFromFile("MenuBackground.jpg");
	sf::Sprite sp;
	sp.setTexture(menu_tex);

	while (window.isOpen())
	{
		window.clear();
		window.draw(sp);
		window.display();
		sf::Event event{};
		while (window.waitEvent(event)) {
			switch (event.type) {
			case sf::Event::KeyPressed:{
				window.close();
				break;
			}
			case sf::Event::Closed: {
				window.close();
				break;
			}
		}
	}
	//gamestate.test(gamestate.died);
	//gamestate.draw(window);
	
	return EXIT_SUCCESS;
}
