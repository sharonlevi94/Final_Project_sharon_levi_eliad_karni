#pragma once
#include <SFML/Graphics.hpp>
#include "EffectsHolder.h"
#include <vector>
using std::vector;
class GameObject
{
public:
	GameObject(
		const sf::Vector2f location = sf::Vector2f(0,0), 
		const sf::Vector2f size = sf::Vector2f(0, 0), 
		int state = 0,
		const sf::Sprite& (*)(char) = nullptr);

	virtual void draw     ()const;
	virtual char identify ()const;
	virtual void playTurn (const GameObject* (*)(const sf::Vector2f&));
	virtual void reset    (const sf::Vector2f&);

	const sf::Vector2f& getLocation()const;
	const sf::Vector2f& getSize    ()const;
	int                 getState   ()const;
	const sf::Sprite*   getSprite  ()const;

private:
	sf::Vector2f       m_location;
	sf::Vector2f           m_size;
	int                   m_state;
	vector<sf::Sprite*> m_sprites;

	virtual void setState              (const int);
	virtual void setLocation (const sf::Vector2f&);
	virtual void setSprite     (const sf::Sprite&);
};