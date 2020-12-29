#pragma once
/*
  This file contains :
  #1. Symbols of the game objects.
  #2. macros of the paths to the sprites & sounds of game
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

constexpr auto WINDOW_HEIGHT = 1000;
constexpr auto WINDOW_WIDTH = 1800;
constexpr auto MESSAGE_WIDTH = 600;
constexpr auto MESSAGE_HEIGHT = 400;
constexpr auto MESSAGE_LOC_HEIGHT = WINDOW_HEIGHT / 2 - MESSAGE_HEIGHT;
constexpr auto MESSAGE_LOC_WIDTH = WINDOW_WIDTH / 2 - MESSAGE_WIDTH;
constexpr auto MENU_HEIGHT = WINDOW_HEIGHT;
constexpr auto MENU_WIDTH = WINDOW_WIDTH / 10;
constexpr auto BOARD_HEIGHT = WINDOW_HEIGHT;
constexpr auto BOARD_WIDTH = WINDOW_WIDTH - MENU_WIDTH;

//========================== saving map's file path ===========================
constexpr auto BOARD_PATH = "Levels.txt";