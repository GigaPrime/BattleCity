/*********************************************************************/
/*                                                                   */
/*    ConsoleLib [Release 2]                                         */
/*    Библиотека функций-оберток для работы с консолью               */
/*                                                                   */
/*    Copyright (с) 2006-2014, Дмитрий Барабаш                       */
/*                                                                   */
/*    E-mail:   dmitry@barabash.com                                  */
/*    Web:      http://itstep.barabash.com                           */
/*                                                                   */
/*********************************************************************/

#include <iostream>
using namespace std;

#include <windows.h>
#include "ConsoleLib.h"


// Хендлы консоли
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);


// Показываем/прячем текстовый курсор
void ShowCursor(bool visible)
{
	CONSOLE_CURSOR_INFO cci = { sizeof(cci), visible };
	SetConsoleCursorInfo(hStdOut, &cci);
}

// Устанавливает цвет символов и фона
void SetColor(ConsoleColor text, ConsoleColor background)
{
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

// Перемещает курсор в заданную позицию
void GotoXY(int X, int Y)
{
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

// Выводит заданную строку в заданную позицию
void WriteStr(int X, int Y, const char *Str)
{
    GotoXY(X, Y);
	cout << Str << flush;
}

// Выводит заданный символ начиная с заданной позиции
void WriteChar(int X, int Y, char Ch)
{
	GotoXY(X, Y);
	cout << Ch;
}

// Выводит указанное количество заданных символов начиная с заданной позиции
void WriteChars(int X, int Y, char Ch, unsigned Len)
{
	GotoXY(X, Y);
	for (unsigned i = 0; i < Len; i++)
		cout << Ch;
}

// Меняет текстовые аттрибуты, начиная с заданной позиции
void ChangeTextAttr(int X, int Y, ConsoleColor text, ConsoleColor background, unsigned Len)
{
	COORD coord = { X, Y };
	DWORD dwDummy;
	FillConsoleOutputAttribute(hStdOut, (WORD)((background << 4) | text), Len, coord, &dwDummy);
}
