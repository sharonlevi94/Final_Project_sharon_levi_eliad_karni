#include "Board.h"
#include "Coin.h"
#include "Controller.h"
#include "Enemy.h"
#include "DataReader.h"
#include "EffectsHolder.h"
#include "GameObjects.h"
#include "MovingObjects.h"
#include "StaticObjects.h"
#include "GameState.h"
#include "SmartEnemy.h"
#include "RandEnemy.h"
#include "FoolEnemy.h"
#include "Gift.h"
#include "Menu.h"
#include "Player.h"

int main()
{
	Controller controller;
	controller.runGame();
	return EXIT_SUCCESS;
}
