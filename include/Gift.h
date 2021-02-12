//============================ include section ===============================
#pragma once
#include "CollectableObject.h"
#include <vector>
#include "RandEnemy.h"
#include "GameState.h"
//============================== using section ===============================
using std::vector;
/*============================================================================
* Class: Gift.
* This is the base class of the gifts in the game. all the types of the 
* gifts derives from this class.
* This class derived from CollectableObject class.
 ============================================================================*/
class Gift :public CollectableObject
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	Gift(const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
};