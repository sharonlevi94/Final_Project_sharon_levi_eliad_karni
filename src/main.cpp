//============================= include section ==============================
#include "Controller.h"
#include <stdlib.h>
//============================== main section ================================
int main()
{
	//Controller controller;
	//controller.run();

	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Test");
	sf::Event event;

	sf::Texture texture;
	texture.loadFromFile("player.png");
	
	sf::IntRect rect(0, 512, 128, 128);
	sf::Sprite sprite(texture, rect);

	sf::Clock clock;

	while (renderWindow.isOpen()) {
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();
		}

		if (clock.getElapsedTime().asSeconds() > 0.1f) {
			if (rect.left == 896)
				rect.left = 0;
			else
				rect.left += 128;

			sprite.setTextureRect(rect);
			clock.restart();
		}

		renderWindow.clear();
		renderWindow.draw(sprite);
		renderWindow.display();
	}
	return EXIT_SUCCESS;
}
