#pragma once
//============================ include section ===============================
#include <SFML/Graphics.hpp>
#include "Macros.h"
//========================== forward declarations ============================
class Board;

class GameObject{
public:
	GameObject(
		const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0),
		char objectType = NOTHING,
		bool isAnimated = false);
	virtual ~GameObject() = 0;

	virtual void draw(sf::RenderWindow&);
	virtual void reset();
	virtual void resetAnimationTime();
	void updateAnimation(const sf::Time&);

	bool CollidesWith(const GameObject&)const;
	
	sf::Vector2f getAbove()const;
	sf::Vector2f getLeft()const;
	sf::Vector2f getBelow()const;
	sf::Vector2f getRight()const;
	sf::Vector2f getCenter()const;
	sf::Vector2f getBotLeft()const;
	sf::Vector2f getBotRight()const;

	const sf::Vector2f& getLocation()const;
	sf::Vector2f getSize()const;
	int getState ()const;
	const sf::Sprite& getSprite()const;
	void flipSprite();

protected:
	virtual void setLocation(const sf::Vector2f&);
	virtual void setState(int);
private:
	sf::Sprite m_objectSprite;
	int m_state;
	bool m_isAnimated;
	//here and not on moving object to give an option to static objects
	//animation
	sf::IntRect m_intRect;
	sf::Time m_animationTime;
};