#ifndef _MENU_H
#define _MENU_H
#pragma once
#include <SFML/Graphics.hpp>
#include <EffectsHolder.h>
class Menu
{
public:
	Menu(
		const EffectsHolder& effects = EffectsHolder(),
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
	sf::Sound* m_clickSound;
	sf::Sound* m_backgroundSound;
	sf::Sprite m_GameLogo;
	sf::Sprite m_background;

	void calcLogo(const EffectsHolder& effects);
	void calcStartButton(const EffectsHolder& effects);
	void calcQuitButton(const EffectsHolder& effects);
	void calcBackground(const EffectsHolder& effects);
}; 
#endif //_MENU_H_