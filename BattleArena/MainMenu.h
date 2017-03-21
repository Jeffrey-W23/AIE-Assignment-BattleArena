#pragma once
#include "Game.h"

class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	bool StartMenu();
	void PrintMenu();

private:
	int menuOption;
	Game* game;
};