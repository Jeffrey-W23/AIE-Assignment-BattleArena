#include "Game.h"
#include <iostream>
#include <ctime>
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
			playerId = playertype;
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
			playerId = playertype;
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
	

	system("cls");
	int userInput;

	// make an action
	cout << endl << "   ACTIONS:" << endl;
	cout << "   1. ATTACK" << endl;
	cout << "   2. TAUNT" << endl;
	cout << "   3. CHEER SELF UP" << endl;
	cout << "__________________________________________________________________________________________________________________________________" << endl;

	cin >> userInput;
	cin.clear();
	cin.ignore(999999, '\n');

	// Make an attack
	cout << "SELECT ATTACK:" << endl;

	//clear current view

	// attack
	if (userInput == 1)
	{
		userInput = 0;

		cout << "1. BITE" << endl;
		cout << "2. SCRATCH" << endl;
		cout << "3. SIT" << endl;

		cin >> userInput;

		if (playerId == 0)
		{
			if (userInput == 1)
			{
				// draw
				//pause
				int damage = player[0]->Attack(bite);
				AI[0]->takeDamage(damage);
			}
			else if (userInput == 2)
			{
				//draw
				//pause
				int damage = player[0]->Attack(scratch);
				AI[0]->takeDamage(damage);
			}
			else if (userInput == 3)
			{
				//draw
				//pause
				int damage = player[0]->Attack(sit);
				AI[0]->takeDamage(damage);
			}
			else
			{
				cout << "Thats not a valid attack.. you're not a couch, use your brain please." << endl;
			}
		}
	}

	// taunt
	else if (userInput == 2)
	{
		userInput = 0;
		srand(time(0));
		int sanity = rand() % 46;
		AI[0]->lowerSanity(sanity);
		player[0]->cheer = (sanity / 2);

		int randTaunt = rand() % 11;
		cout << player[0]->Taunts(randTaunt) << endl;
	}

	// cheer
	else if (userInput == 3)
	{
		userInput = 0;

		cout << "You have " << player[0]->cheer << " cheer" << endl;
		cout << "1. RESTORE ALL SANITY - 65 cheer" << endl;
		cout << "2. RESTORE 25 - Cost 35 cheer" << endl;
		cout << "3. RESTORE 15 - Cost 30 cheer" << endl;

		cin >> userInput;

		if (player[0]->sanity < 250)
		{
			if (userInput == 1 && player[0]->cheer > 65)
			{
				player[0]->sanity = 250;
			}
			else if (userInput == 2 && player[0]->cheer > 35)
			{
				player[0]->sanity =+ 25;
			}
			else if (userInput == 3 && player[0]->cheer > 30)
			{
				player[0]->sanity =+ 15;
			}
			else
			{
				cout << "Either you dont have enough cheer or thats not a valid option.. you're not a couch, use your brain please." << endl;
			}
		}
		else
		{
			cout << "You dont need these man, trust me." << endl;
		}
	}

	// invalid input
	else
	{
		userInput = 0;
		cout << "You can do nothing if you like?" << endl;
		cout << "Thats what I thought, please make a valid choice" << endl;
	}





	//if sanity is lower then 0 stop it at 0 and cause -5 health a turn.
	//player[0]->Attack
	/*int damage = squad[i]->attack();
	swarm[0]->takeDamage(damage);*/

	//repeat
}

void Game::BubbleSort(Monsters** data, int count)
{
	Monsters* temp;

	for (int i = 0; i < (count - 1); i++)
	{
		for (int j = 0; j < (count - 1); j++)
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