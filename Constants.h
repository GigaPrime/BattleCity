#include <windows.h>
#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

//Direction constants
const int RIGHT = 0;
const int DOWN = 1;
const int LEFT = 2;
const int UP = 3;
const int TOTAL_DIRECTIONS = 4;
const int NO_DIRECTION = -1;

//BattleField dimentions
const int FIELD_X = 20;
const int FIELD_Y = 14;
const int FIELD_WIDTH = FIELD_X + 78;
const int FIELD_HEIGHT = FIELD_Y + 45;

//Action constants
const char FIRE = ' ';

//Symbols per seconds
const double ROUND_SPEED_H = 50;
const double ROUND_SPEED_V = ROUND_SPEED_H / 2;
const double TANK_SPEED_H = 25;
const double TANK_SPEED_V = TANK_SPEED_H / 2;

//FPS
const int FPS = 25;
const int MAIN_LOOP_SLEEP = 1000 / FPS;

//Tank wiev elements
const char CH = char(254); //caterpillar_horizontal
const char CV = char(220); //caterpillar_vertical
const char GH = char(205); //gun_horizontal
const char GV = char(186); //gun_vertical
const char BD = char(176); //body
const char SP = char(255); //space
const char FR = char('*'); //fire

//Intro wiev elements
const int TOTAL_CHARS = 8; //quantity of unique letters
const int CHARS_SIZE = 12; //Letter size
const int CHARS_DIST = 14; // distance between letters
const double GAME_NAME_START_X = 10; //name start position x
const double GAME_NAME_START_Y = 12; //name start position y
const char BB = char(177); //brick blank
const char BF = char(178); //brick full
const int B = 0;
const int A = 1;
const int T = 2;
const int L = 3;
const int E = 4;
const int C = 5;
const int I = 6;
const int Y = 7;

//counter wiev elements
const int COUNTER_DIMENTIONS = 3;
const int COUNTER_NUMBER = 10;
const char HS = char(95);
const char VS = char(179);

//Tank size constants
const int TANK_WIDTH = 5;
const int TANK_HEIGHT = 3;

//Game constants
const int MAX_ENEMIES = 10;
const int MAX_ALIVE_ENEMIES = 3;
const double MIN_ENEMY_KEEP_DIRECTION_TIME = 0.8;
const double MAX_ENEMY_KEEP_DIRECTION_TIME = 3.0;
const double TANK_RESP_TIMER = 5.0;
const double INITAIL_TANK_RESP_TIMER = 1.0;
const COORD TOP_LEFT_RESP = { (FIELD_X + 1), (FIELD_Y + 1) };
const COORD TOP_RIGHT_RESP = { (FIELD_WIDTH - TANK_WIDTH), (FIELD_Y + 1) };
const COORD TOP_CENTER_RESP = { ((FIELD_WIDTH - TANK_WIDTH) / 2), (FIELD_Y + TANK_HEIGHT) };
const COORD PLAYER_RESP = { ((FIELD_WIDTH - TANK_WIDTH) / 2), (FIELD_HEIGHT - TANK_HEIGHT) };

#endif // !__CONSTANTS_H__
