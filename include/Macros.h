#pragma once
/*
  This file contains :
  #1. Symbols of the game objects.
  #2. macros of the paths to the sprites & sounds of game
  #3. macros of windows sizes.
  #4. states of the game objects.
*/
//========================== game objects symbols ===========================
constexpr auto PLAYER = '@';
constexpr auto ENEMY = '%';
constexpr auto COIN = '*';
constexpr auto WALL = '#';
constexpr auto NOTHING = ' ';
constexpr auto LADDER = 'H';
constexpr auto ROD = '-';
constexpr auto PLAYER_ON_LADDER = 'S';
constexpr auto GIFT = '+';
constexpr auto DOOR = 'D';

//obj size:
constexpr auto OBJ_HEIGHT = 30; //y
constexpr auto OBJ_WIDTH = 30; //x

//menu answers
constexpr auto QUIT_GAME = 'Q';
constexpr auto PLAY_GAME = 'P';
constexpr auto NONE_CHOSEN = 'N';

//========================== game objects states ============================
//MovingObject
constexpr auto STAND = 1;
constexpr auto WALK_LEFT = 2;
constexpr auto WALK_RIGHT = 3;
constexpr auto CLIMBING = 4;
constexpr auto DIGGING = 5;
constexpr auto RODDING = 6;
constexpr auto LOOK_LEFT = 1;
constexpr auto LOOK_RIGHT = 2;
constexpr auto LOOK_STRAIGHT = 1;
//coin
constexpr auto NOT_COLLECTED = 6;
constexpr auto COLLECTED = 7;
//wall
constexpr auto EXIST = 8;
constexpr auto DIGGED = 9;
//ladder/rod
constexpr auto CLIMBED = 10;
constexpr auto NOT_CLIMBED = 11;
//gift
constexpr auto TIME_BONUS = 0;
constexpr auto ADD_SCORE = 1;
constexpr auto ADD_LIFE = 2;
constexpr auto ADD_ENEMY = 3;
//=============================== game rules =================================

constexpr auto NUM_OF_LIFE = 3;
constexpr auto NO_LEVEL_TIME = -1;
constexpr auto NUM_OF_GIFT_TYPES = 4;

//============================  map's file path ==============================
//-------------------------- data files section ------------------------------
constexpr auto BOARD_PATH = "Levels.txt";

//---------------------------------- fonts -----------------------------------
constexpr auto ARIEL_FONT_PATH = "ARIALBD.TTF";

//---------------------------- picture section -------------------------------
constexpr auto MENU_BACKGROUND_PATH = "MenuBackground.jpg";
constexpr auto LEVEL1_BACKGROUND_PATH = "level1.jpeg";
constexpr auto LEVEL2_BACKGROUND_PATH = "level2.png";
constexpr auto LEVEL3_BACKGROUND_PATH = "level3.jpeg";
constexpr auto LEVEL4_BACKGROUND_PATH = "level4.jpeg";

constexpr auto PLAYER_PATH = "player.png";
constexpr auto ENEMY_PATH = "enemy.png";
constexpr auto COIN_PATH = "coin.png";
constexpr auto WALL_PATH = "wall.png";
constexpr auto LADDER_PATH = "ladder.png";
constexpr auto ROD_PATH = "rod.png";
constexpr auto GIFT_PATH = "gift.png";
constexpr auto DOOR_PATH = "door.png";
constexpr auto GAME_STATE_PATH = "game_state.jpg";

//---------------------------------- logos -----------------------------------
constexpr auto GAME_LOGO_PATH = "Logo.png";

//============================ game files consts =============================
//-------------------------------- textures ----------------------------------
//------------------------------- backgrounds --------------------------------
constexpr auto MENU_BACKGROUND = 1;
constexpr auto LEVEL_BACKGROUND = 2;
constexpr auto GAME_STATE = 9;
//------------------------------- objects -------------------------------------
constexpr auto PLAYER_T = 10;
constexpr auto ENEMY_T = 11;
constexpr auto COIN_T = 12;
constexpr auto WALL_T = 13;
constexpr auto LADDER_T = 14;
constexpr auto ROD_T = 15;
constexpr auto GIFT_T = 16;
constexpr auto DOOR_T = 17;

//--------------------------------- logos ------------------------------------
constexpr auto GAME_LOGO = 26;
//--------------------------------- sounds -----------------------------------
//---------------------------------- fonts -----------------------------------
constexpr auto ARIEL_FONT = 1;