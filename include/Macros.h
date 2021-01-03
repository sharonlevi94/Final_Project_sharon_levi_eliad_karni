#pragma once
/*
  This file contains :
  #1. Symbols of the game objects.
  #2. macros of the paths to the sprites & sounds of game
  #3. macros of windows sizes.
  #4. states of the game objects.
*/
//========================== game objects symbols ============================

constexpr auto PLAYER = '@';
constexpr auto ENEMY = '%';
constexpr auto COIN = '*';
constexpr auto WALL = '#';
constexpr auto NOTHING = ' ';
constexpr auto LADDER = 'H';
constexpr auto ROD = '-';
constexpr auto PLAYER_ON_LADDER = 'S';

//obj size:
constexpr auto OBJ_HEIGHT = 30; //y
constexpr auto OBJ_WIDTH = 30; //x

//========================== game objects states ============================

//player/enemy
constexpr auto STAND = 1;
constexpr auto WALK_LEFT = 2;
constexpr auto WALK_RIGHT = 3;
constexpr auto CLIMBING = 4;
constexpr auto DIGGING = 5;
//coin
constexpr auto NOT_COLLECTED = 6;
constexpr auto COLLECTED = 7;
//wall
constexpr auto EXIST = 8;
constexpr auto DIGGED = 9;
//ladder
constexpr auto CLIMBED = 10;
constexpr auto NOT_CLIMBED = 11;

//=========================== Window's parameters ============================

constexpr auto MESSAGE_WIDTH = 600;
constexpr auto MESSAGE_HEIGHT = 400;

//=============================== game rules =================================

constexpr auto NUM_OF_LIFE = 3;
constexpr auto NO_LEVEL_TIME = -1;

//============================  map's file path ==============================
//-------------------------- data files section ------------------------------
constexpr auto BOARD_PATH = "Levels.txt";

//---------------------------- picture section -------------------------------
constexpr auto MENU_BACKGROUND_PATH = "MenuBackground.jpg";
constexpr auto LEVEL1_BACKGROUND_PATH = "level1.jpeg";

//============================ game files consts =============================

constexpr auto MENU_BACKGROUND = 1;

//============================ levels consts =============================
constexpr auto LEVEL1 = 1;
constexpr auto LEVEL2 = 2;
constexpr auto LEVEL3 = 3;
constexpr auto LEVEL4 = 4;