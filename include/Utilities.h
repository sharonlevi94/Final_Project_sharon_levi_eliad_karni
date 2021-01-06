#pragma once
#include <fstream> // for string
#include <SFML/Graphics.hpp>

void terminate(const std::string);

sf::Vector2f calcScale(const sf::Vector2f& size, 
const sf::Vector2f& scale, const sf::Vector2f& textureSize);
sf::Vector2f calcScreenLocation(const sf::Vector2f& ScreenSize,
	const sf::Vector2f& mapSize,
	const sf::Vector2f& location);