#pragma once
#include <SFML/Graphics.hpp>
#include "EffectsHolder.h"
#include <vector>
#include "Macros.h"
using std::vector;
class Wall;
//class Ladder;
//class Coin;
class Player;
//class Enemy;
//class Rod;
class GameObject
{
public:
	GameObject(
		const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0),
		char objectType = NOTHING);
	                                      
	virtual void draw(sf::RenderWindow& window);
	virtual void playTurn(sf::Time) = 0;
	virtual void reset();

	bool CollidesWith(const GameObject&)const;
	/*virtual*/ void handleColision(GameObject&);
	virtual void handleColision(Wall&)=0;
	
	const sf::Vector2f& getLocation()const;
	const sf::Vector2f& getSize()const;
	int getState ()const;
	const sf::Sprite& getSprite()const;

protected:
	virtual void setLocation(const sf::Vector2f&);
private:
	sf::Sprite m_objectSprite;
	int m_state;

	//virtual void setState (const int)=0;
	//virtual void setTexture (const sf::Texture&)=0;
};