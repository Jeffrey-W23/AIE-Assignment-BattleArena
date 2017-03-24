#include "Game.h"
#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

Game::Game()
{
}

Game::Game(int playertype)
{
	human = new Human(playertype);
}

Game::~Game()
{
	//delete couches and zombies
}

void Game::MainFunction()
{
	bool gameRunning = true;
	int userInput;

	while (gameRunning)
	{
		//Sort
		human->BubbleSort(); // Bubble Sort 
		//BubbleSort(AI, AISize); // Do a different type of sort // IMPORTANT

		// make an action
		system("cls");
		cout << endl << "   ACTIONS:" << endl;
		cout << "   1. ATTACK" << endl;
		cout << "   2. TAUNT" << endl;
		cout << "   3. CHEER UP" << endl << endl;

		// get input for action
		cin >> userInput;
		cin.clear();
		cin.ignore(999999, '\n');

		// attack
		if (userInput == 1)
		{
			int damage = human->Attack(userInput); 
			//AI->takeDamage(damage);
		}

		// taunt
		else if (userInput == 2)
		{
			/*if (AI[0]->sanity > 0)
			{
				int taunt = human->Taunt();
				AI[0]->lowerSanity(taunt);
			}
			
			else
			{
				cout << "   You jerk.. they're crying thier eyes out! No more taunting.. " << endl;
				_getch();
			}*/
		}

		// cheer
		else if (userInput == 3)
		{
			human->Cheer(userInput);
		}

		// invalid input
		else
		{
			userInput = 0;
			cout << "   You can do nothing if you like?" << endl;
			cout << "   Thats what I thought, please make a valid choice" << endl;
			_getch();
		}

		// Do AI turn

		//repeat
	}
}