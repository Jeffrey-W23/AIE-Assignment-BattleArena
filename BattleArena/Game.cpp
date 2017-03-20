#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
	for (int i = 0; i < 5; i++)
	{
		zombies[i] = new Zombies();
	}

	for (int i = 0; i < 3; i++)
	{
		couches[i] = new Couches();
	}
}

Game::~Game()
{
	//delete couches and zombies
}

void Game::StartGame(int playertype)
{
	int userInput;

	cout << "YOUR TURN:" << endl;

	cout << "1. ATTACK" << endl;
	cout << "2. TAUNT" << endl;
	cout << "3. CHEER SELF UP" << endl;

	cin >> userInput;

	if (userInput == 1)
	{
		
	}
	else if  (userInput == 2)
	{

	}
	else if (userInput == 3)
	{

	}


	if (playertype == 1)
	{

	}
	else if (playertype == 2)
	{

	}
}