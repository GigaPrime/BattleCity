/*********************************************************************/
/*                                                                   */
/*    ConsoleLib [Release 2]                                         */
/*    ���������� �������-������� ��� ������ � ��������               */
/*                                                                   */
/*    Copyright (�) 2006-2014, ������� �������                       */
/*                                                                   */
/*    E-mail:   dmitry@barabash.com                                  */
/*    Web:      http://itstep.barabash.com                           */
/*                                                                   */
/*********************************************************************/

#include <iostream>
using namespace std;

#include <windows.h>
#include "ConsoleLib.h"


// ������ �������
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);


// ����������/������ ��������� ������
void ShowCursor(bool visible)
{
	CONSOLE_CURSOR_INFO cci = { sizeof(cci), visible };
	SetConsoleCursorInfo(hStdOut, &cci);
}

// ������������� ���� �������� � ����
void SetColor(ConsoleColor text, ConsoleColor background)
{
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

// ���������� ������ � �������� �������
void GotoXY(int X, int Y)
{
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

// ������� �������� ������ � �������� �������
void WriteStr(int X, int Y, const char *Str)
{
    GotoXY(X, Y);
	cout << Str << flush;
}

// ������� �������� ������ ������� � �������� �������
void WriteChar(int X, int Y, char Ch)
{
	GotoXY(X, Y);
	cout << Ch;
}

// ������� ��������� ���������� �������� �������� ������� � �������� �������
void WriteChars(int X, int Y, char Ch, unsigned Len)
{
	GotoXY(X, Y);
	for (unsigned i = 0; i < Len; i++)
		cout << Ch;
}

// ������ ��������� ���������, ������� � �������� �������
void ChangeTextAttr(int X, int Y, ConsoleColor text, ConsoleColor background, unsigned Len)
{
	COORD coord = { X, Y };
	DWORD dwDummy;
	FillConsoleOutputAttribute(hStdOut, (WORD)((background << 4) | text), Len, coord, &dwDummy);
}
