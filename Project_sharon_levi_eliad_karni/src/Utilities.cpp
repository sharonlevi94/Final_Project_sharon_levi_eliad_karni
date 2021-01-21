//============================= include section ==============================
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include "RandEnemy.h"
#include "SmartEnemy.h"
#include "FoolEnemy.h"
#include "Enemy.h"
//============================ functions section ==============================
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
//========================================================================
sf::Vector2f calcDistance(const sf::Vector2f& from, const sf::Vector2f& to) {
	return(sf::Vector2f(to.x - from.x, to.y - from.y));
}
//============================================================================
/*
* This function called in load new level function to raffle the type of the
* enemy. The function return a ptr to the type of enemy it raffled.
*/
Enemy* raffleEnemy(const sf::Vector2f& boxSize,
const sf::Vector2f& location) {
	//srand was declared in the controller
	switch (rand() % NUM_OF_ENEMIES_TYPES)
	{
	case 0:
		return new RandEnemy(location, boxSize);
	case 1:
		return new FoolEnemy(location, boxSize);
	default:
		return new SmartEnemy(location, boxSize);
	}
}