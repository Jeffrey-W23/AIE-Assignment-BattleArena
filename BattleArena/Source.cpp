#include <iostream>
#include <chrono>
#include "MainMenu.h"
#include <windows.h>
#include <crtdbg.h>
using namespace std;

void SetWindowSize(int WinWidth, int WinHeight)
{
	_COORD Coord;
	Coord.X = WinWidth;
	Coord.Y = WinHeight;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = WinHeight - 1;
	Rect.Right = WinWidth - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, Coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	SetWindowSize(130, 35);

	bool gameRunning = true;

	while (gameRunning)
	{
		MainMenu menu;
		gameRunning = menu.StartMenu();
	}
}