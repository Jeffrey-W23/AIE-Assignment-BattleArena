#include <iostream>
#include "MainMenu.h"
#include <conio.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
	// delete game
}

bool MainMenu::StartMenu()
{
	int menuOption;

	PrintMenu();

	cin >> menuOption;
	cin.clear();
	cin.ignore(999999, '\n');
	cout << endl;

	if (menuOption == 1)
	{
		game = new Game(0);
		game->MainFunction();

		menuOption = 0;
		return true;
	}
	else if (menuOption == 2)
	{
		game = new Game(1);
		game->MainFunction();

		menuOption = 0;
		return true;
	}
	else if (menuOption == 3)
	{
		return false;
	}
	else
	{
	cout << "     PLEASE ENTER A VALID MENU OPTION DUDE, THIS ISN'T A GAME." << endl << endl;
	cout << "     PRESS ANY KEY TO CONTINUE..." << endl;
		_getch();
		return true;
	}
}

void MainMenu::PrintMenu()
{
	system("cls");
	cout << "                                                                            " << endl;
	cout << "                                                                            " << endl;
	cout << "      _______  _______  _______  ______  _________ _______  _______         " << endl;
	cout << "     / ___   )(  ___  )(       )(  ___ \\ \\__   __/(  ____ \\(  ____ \\    " << endl;
	cout << "     \\/   )  || (   ) || () () || (   ) )   ) (   | (    \\/| (    \\/     " << endl;
	cout << "         /   )| |   | || || || || (__/ /    | |   | (__    | (_____         " << endl;
	cout << "        /   / | |   | || |(_)| ||  __ (     | |   |  __)   (_____  )        " << endl;
	cout << "       /   /  | |   | || |   | || (  \\ \\    | |   | (            ) |      " << endl;
	cout << "      /   (_/\\| (___) || )   ( || )___) )___) (___| (____/\\/\\____) |     " << endl;
	cout << "     (_______/(_______)|/     \\||/ \\___/ \\_______/(_______/\\_______)    " << endl;
	cout << "                                                                            " << endl;
	cout << "                            _______  _______                                " << endl;
	cout << "                           (  ___  )(  ____ )                               " << endl;
	cout << "                           | (   ) || (    )|                                                     1. Zombies" << endl;
	cout << "                           | |   | || (____)|                               " << endl;
	cout << "                           | |   | ||     __)                                                     2. Couches" << endl;
	cout << "                           | |   | || (\\ (                                 " << endl;
	cout << "                           | (___) || ) \\ \\__                                                     3. Quit" << endl;
	cout << "                           (_______)|/   \\__/                              " << endl;
	cout << "                                                                            " << endl;
	cout << "      _______  _______           _______           _______  _______         " << endl;
	cout << "     (  ____ \\(  ___  )|\\     /|(  ____ \\|\\     /|(  ____ \\(  ____ \\  " << endl;
	cout << "     | (    \\/| (   ) || )   ( || (    \\/| )   ( || (    \\/| (    \\/    " << endl;
	cout << "     | |      | |   | || |   | || |      | (___) || (__    | (_____         " << endl;
	cout << "     | |      | |   | || |   | || |      |  ___  ||  __)   (_____  )        " << endl;
	cout << "     | |      | |   | || |   | || |      | (   ) || (            ) |        " << endl;
	cout << "     | (____/\\| (___) || (___) || (____/\\| )   ( || (____/\\/\\____) |    " << endl;
	cout << "     (_______/(_______)(_______)(_______/|/     \\|(_______/\\_______)                             .---.---.---." << endl;
	cout << "      _  _     ___     _  ___       __                           __                            .-.           .-." << endl;
	cout << "     |_ |_  /\\  | | | |_)  |  |\\ | /__   |_| | | |\\/|  /\\  |\\ | (_  |                          | |---.---.---| |" << endl;
	cout << "     |  |_ /--\\ | |_| | \\ _|_ | \\| \\_|   | | |_| |  | /--\\ | \\| __) o                          |_|___________|_|" << endl;
}