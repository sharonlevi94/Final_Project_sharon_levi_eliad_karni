#pragma once
//============================ include section ===============================
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
//========================== forward declarations ============================
class Controller;
/*============================================================================
 * Class: CollectableObject.
 * This class represent all the collectable objects in the game: coins & gifts.
 */
class CollectableObject : public StaticObject{
public:
	//================= constractors and destractors section =================
	CollectableObject(const sf::Vector2f& = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0),
		char objectType = NOTHING);
	virtual ~CollectableObject() = default;
	//=========================== method section =============================
	virtual bool is_collected()const;
	virtual void draw(sf::RenderWindow&)override;
	virtual void reset()override;
	virtual void collect();
	virtual void handleColision(Controller&)=0;
	//====================== privete methods section =========================
private:
	//========================= members section ==============================
	bool m_is_collected;
};

