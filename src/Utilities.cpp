//============================= include section ==============================
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
//============================ functions section ==============================

//========================================================================
/* The function print the received error message and close the program
 * with -1 return value.
 * input: string
 * output: none.
*/
void terminate(const std::string errorMessage) {
	std::cerr << errorMessage << std::endl;
	exit(EXIT_FAILURE);
}
//========================================================================
sf::Vector2f calcScale(const sf::Vector2f& size, 
	const sf::Vector2f& scale, 
	const sf::Vector2f& textureSize){
	float x = (size.x / scale.x) / textureSize.x,
		y = (size.y / scale.y)/ textureSize.y;

	return sf::Vector2f((size.x / scale.x) / textureSize.x, 
	 (size.y / scale.y)/ textureSize.y);
}
//========================================================================
sf::Vector2f calcScreenLocation(const sf::Vector2f& ScreenSize, 
	const sf::Vector2f& mapSize,
	const sf::Vector2f& location){
	return sf::Vector2f((ScreenSize.x / mapSize.x) * location.x,
		(ScreenSize.y / mapSize.y) * location.y);
	}

