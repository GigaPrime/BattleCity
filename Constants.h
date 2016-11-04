#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

//Direction constants
const int UP = 1;
const int RIGHT = 2;
const int DOWN = 3;
const int LEFT = 4;

//BattleField dimentions
const int WIDTH = 60;
const int HEIGHT = 30;

//Action constants
const char FIRE = ' ';

//Symbols per seconds
const int ROUND_SPEED_H = 10;
const int ROUND_SPEED_V = ROUND_SPEED_H / 2;

//FPS
const int FPS = 10;
const int MAIN_LOOP_SLEEP = 1000 / FPS;

//Tank wiev elements
const char CH = char(254); //caterpillar_horizontal
const char CV = char(220); //caterpillar_vertical
const char GH = char(205); //gun_horizontal
const char GV = char(186); //gun_vertical
const char BD = char(176); //body
const char SP = char(255); //space
const char FR = char('*'); //fire

#endif // !__CONSTANTS_H__

