#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "CollectableObject.h"
using std::vector;

class Coin: public CollectableObject
{
public:
	Coin(const sf::Vector2f location = sf::Vector2f(0, 0),
		const sf::Vector2f size = sf::Vector2f(OBJ_WIDTH, OBJ_HEIGHT),
		int state = STAND,
		const sf::Sprite& (*)(char) = nullptr,
		char type = '\0');
	
	virtual  sf::Drawable draw     ()const  override;
	//virtual char          identify ()const  override;
	virtual void          playTurn (const GameObject* (*)(const sf::Vector2f&))  override;
	virtual void          reset    (const sf::Vector2f&)  override;
	virtual void addSprite(const sf::Sprite&) override;

	const sf::Vector2f& getLocation  ()const;
	const sf::Vector2f& getSize      ()const;
	int                 getState     ()const;
	const sf::Sprite*   getSprite    ()const;

	bool                is_collected ()const  override;

private:

	virtual void        collect () override;
	virtual void        setState (const int)  override;
	//virtual void        setLocation (const sf::Vector2f&) override;
	virtual void        setSprite  (const sf::Sprite&) override;
};