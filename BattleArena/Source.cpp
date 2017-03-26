//#include, using etc
#include <iostream>
#include <chrono>
#include "MainMenu.h"
#include <windows.h>
#include <crtdbg.h>
using namespace std;

// Function to set the console windows width and height.
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

// Main function
void main()
{
	// Check for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Run the window size function
	SetWindowSize(130, 35);
	srand((unsigned int)time(0));

	// Start the game loop
	bool gameRunning = true;
	while (gameRunning)
	{
		// RUn the menu
		MainMenu menu;
		gameRunning = menu.StartMenu();
	}
}