#pragma once
#include "CollectableObject.h"
class Gift :public CollectableObject
{
public:
	Gift(const sf::Vector2f& location,
		const EffectsHolder& effects);


	virtual void draw                                          ()const;
	virtual char identify                                      ()const;
	virtual void playTurn (const GameObject* (*)(const sf::Vector2f&));
	virtual void reset                           (const sf::Vector2f&);

	const sf::Vector2f& getLocation                            ()const;
	const sf::Vector2f& getSize                                ()const;
	int                 getState                               ()const;
	const sf::Sprite*   getSprite                              ()const;

	bool                is_collected                           ()const;

private:

	virtual void       collect                                      ();
	virtual void       setState                            (const int);
	virtual void       setLocation               (const sf::Vector2f&);
	virtual void       setSprite                   (const sf::Sprite&);
\
	virtual void draw() const;
	virtual void playTurn(const GameObject* (*)(const sf::Vector2f&));
	virtual void reset(const sf::Vector2f&);

private:

	virtual void collect();
	virtual void setState(const int);
\
};