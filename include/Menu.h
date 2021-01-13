#pragma once
#include <SFML/Graphics.hpp>

class Menu
{
public:
	Menu(
		const sf::Vector2f& size = sf::Vector2f(800,600),
		const sf::Vector2f& location = sf::Vector2f(0,0));

	void draw(sf::RenderWindow& window);
	char handleClick(const sf::Vector2f&)const;
	bool pointingHundle(const sf::Vector2f&);

private:
	sf::Vector2f m_size;
	sf::Vector2f m_location;
	sf::Text m_startGameButton;
	sf::Text m_quitGameButton;
	sf::Sprite m_GameLogo;
	sf::Sprite m_background;

	void calcLogo();
	void calcStartButton();
	void calcQuitButton();
	void calcBackground();
};