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

#ifndef __CONSOLELIB_H__
#define __CONSOLELIB_H__

#include <windows.h>

// ������ �������
extern HANDLE hStdOut;
extern HANDLE hStdIn;

// �����
enum ConsoleColor
{
	Black         = 0,
	Blue          = 1,
	Green         = 2,
	Cyan          = 3,
	Red           = 4,
	Magenta       = 5,
	Brown         = 6,
	LightGray     = 7,
	DarkGray      = 8,
	LightBlue     = 9,
	LightGreen    = 10,
	LightCyan     = 11,
	LightRed      = 12,
	LightMagenta  = 13,
	Yellow        = 14,
	White         = 15
};

// ����������/������ ��������� ������
void ShowCursor(bool visible);

// ������������� ���� �������� � ����
void SetColor(ConsoleColor text, ConsoleColor background);

// ���������� ������ � �������� �������
void GotoXY(int X, int Y);

// ������� �������� ������ � �������� �������
void WriteStr(int X, int Y, const char *Str);

// ������� �������� ������ ������� � �������� �������
void WriteChar(int X, int Y, char Ch);

// ������� ��������� ���������� �������� �������� ������� � �������� �������
void WriteChars(int X, int Y, char Ch, unsigned Len);

// ������ ��������� ���������, ������� � �������� �������
void ChangeTextAttr(int X, int Y, ConsoleColor text, ConsoleColor background, unsigned Len);

#endif // __CONSOLELIB_H__
