#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
}

Game::Game(int playertype)
{
	if (playertype == 0)
	{
		playerSize = 5;
		AISize = 3;

		player = new Monsters*[playerSize];
		AI = new Monsters*[AISize];

		for (int i = 0; i < 5; i++)
		{
			player[i] = new Zombies();
		}

		for (int i = 0; i < 3; i++)
		{
			AI[i] = new Couches();
		}
	}
	else if (playertype == 1)
	{
		playerSize = 3;
		AISize = 5;

		player = new Monsters*[playerSize];
		AI = new Monsters*[AISize];

		for (int i = 0; i < 3; i++)
		{
			player[i] = new Couches();
		}

		for (int i = 0; i < 5; i++)
		{
			AI[i] = new Zombies();
		}
	}
}

Game::~Game()
{
	//delete couches and zombies
}

void Game::StartGame() // chnage name
{
	//Sort
	BubbleSort(player, playerSize); // Bubble Sort 
	BubbleSort(AI, AISize); // Do a different type of sort
	
	//take the first of each 2 lists


	int userInput;

	cout << "YOUR TURN:" << endl;

	cout << "1. ATTACK" << endl;
	cout << "2. TAUNT" << endl;
	cout << "3. CHEER SELF UP" << endl;

	cin >> userInput;

	//repeat
}

void Game::BubbleSort(Monsters** data, int count)
{
	Monsters* temp;

	for (int i = 0; i < (count - 1); i++)
	{
		for (int j = 0; j < (count - 1); i++)
		{
			if (data[j]->health > data[j + 1]->health)
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}