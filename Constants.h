#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

//Direction constants
const int RIGHT = 0;
const int DOWN = 1;
const int LEFT = 2;
const int UP = 3;
const int TOTAL_DIRECTIONS = 4;

//BattleField dimentions
const int FIELD_X = 20;
const int FIELD_Y = 10;
const int FIELD_WIDTH = FIELD_X + 60;
const int FIELD_HEIGHT = FIELD_Y + 40;

//Action constants
const char FIRE = ' ';

//Symbols per seconds
const double ROUND_SPEED_H = 30;
const double ROUND_SPEED_V = ROUND_SPEED_H / 1.5;
const double TANK_SPEED_H = 15;
const double TANK_SPEED_V = TANK_SPEED_H / 1.5;

//FPS
const int FPS = 24;
const int MAIN_LOOP_SLEEP = 1000 / FPS;

//Tank wiev elements
const char CH = char(254); //caterpillar_horizontal
const char CV = char(220); //caterpillar_vertical
const char GH = char(205); //gun_horizontal
const char GV = char(186); //gun_vertical
const char BD = char(176); //body
const char SP = char(255); //space
const char FR = char('*'); //fire

//Tank size constants
const int TANK_WIDTH = 5;
const int TANK_HEIGHT = 3;

//Game constants
const int MAX_ENEMIES = 3;

#endif // !__CONSTANTS_H__
