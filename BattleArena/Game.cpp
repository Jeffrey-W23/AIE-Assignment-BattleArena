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

void Game::MainFunction()
{
	srand(time(0));
	bool gameRunning = true;
	int userInput;

	while (gameRunning)
	{
		//Sort
		BubbleSort(player, playerSize); // Bubble Sort 
		BubbleSort(AI, AISize); // Do a different type of sort // IMPORTANT

		// make an action
		system("cls");
		cout << endl << "   ACTIONS:" << endl;
		cout << "   1. ATTACK" << endl;
		cout << "   2. TAUNT" << endl;
		cout << "   3. CHEER UP" << endl << endl;

		cin >> userInput;
		cin.clear();
		cin.ignore(999999, '\n');

		// attack
		if (userInput == 1)
		{
			Attack(userInput);
		}

		// taunt
		else if (userInput == 2)
		{
			Taunt();
		}

		// cheer
		else if (userInput == 3)
		{
			Cheer(userInput);
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

void Game::Attack(int input) // try to make this for both and pass in a rand for when it is the AI turn.
{
	input = 0;

	// Make an attack
	if (playerId == 0)
	{
		system("cls");
		cout << endl;
		cout << "   SELECT ATTACK:" << endl;
		cout << "   1. BITE" << endl;
		cout << "   2. SCRATCH" << endl;
		cout << "   3. SIT" << endl;

		cin >> input;
		cin.clear();
		cin.ignore(999999, '\n');

		if (input == 1)
		{
			int damage = player[0]->Attack(bite);
			AI[0]->takeDamage(damage);

			cout << "   You bite the couch dealing 30 damage!" << endl;
			cout << "   The couch has " << AI[0]->health << " remaining." << endl;
			_getch();
		}
		else if (input == 2)
		{
			int damage = player[0]->Attack(scratch);
			AI[0]->takeDamage(damage);

			cout << "   You scratch at the couch dealing 25 damage!" << endl;
			cout << "   The couch has " << AI[0]->health << " remaining." << endl;
			_getch();
		}
		else if (input == 3)
		{
			int damage = player[0]->Attack(sit);
			AI[0]->takeDamage(damage);

			cout << "   You sit on the couch.. this is a nasty move dealing 60 damage!" << endl;
			cout << "   The couch has " << AI[0]->health << " remaining." << endl;
			_getch();
		}
		else
		{
			cout << "   Thats not a valid attack.. you're not a couch, use your brain please." << endl;
			_getch();
		}
	}

	else if (playerId == 1)
	{
		system("cls");
		cout << endl;
		cout << "   SELECT ATTACK:" << endl;
		cout << "   1. RECLIN" << endl;
		cout << "   2. RECLINER" << endl;
		cout << "   3. RECLINERER" << endl;

		cin >> input;
		cin.clear();
		cin.ignore(999999, '\n');

		if (input == 1)
		{
			int damage = player[0]->Attack(reclin);
			AI[0]->takeDamage(damage);

			cout << "   You lay back and relax dealing 5 damage!" << endl;
			cout << "   The zombie has " << AI[0]->health << " remaining." << endl;
			_getch();
		}
		else if (input == 2)
		{
			int damage = player[0]->Attack(recliner);
			AI[0]->takeDamage(damage);

			cout << "   You lay further back dealing 15 damage!" << endl;
			cout << "   The zombie has " << AI[0]->health << " remaining." << endl;
			_getch();
		}
		else if (input == 3)
		{
			int damage = player[0]->Attack(reclinerer);
			AI[0]->takeDamage(damage);

			cout << "   You use your finishing move reclinerer! it deals an amazing 100 damage!" << endl;
			cout << "   The zombie has " << AI[0]->health << " remaining." << endl;
			_getch();
		}
		else
		{
			cout << "   Thats not a valid attack.. you're not a couch, use your brain please." << endl;
			_getch();
		}
	}
}

void Game::Taunt() // Balance // if sanity is lower then 0 stop it at 0 and cause -5 health a turn.
{
	int sanity;
	int randTaunt;

	if (AI[0]->sanity > 0)
	{
		if (playerId == 0)
		{
			sanity = rand() % 35;
			randTaunt = rand() % 10;
		}
		else if (playerId == 1)
		{
			sanity = rand() % 28;
			randTaunt = rand() % 10;
		}

		AI[0]->lowerSanity(sanity);
		player[0]->cheer += (sanity / 2);

		cout << "   You taunt your opponent:" << endl << endl;
		cout << "   " << player[0]->Taunts(randTaunt) << endl;

		if (AI[0]->sanity < 100 && AI[0]->sanity > 20)
		{
			cout << endl << "   You see a tear forming under their eye.." << endl;
		}

		else if (AI[0]->sanity < 20 && AI[0]->sanity > 0)
		{
			cout << endl << "   You really seem to be getting to them now.. starting to cry a little.." << endl;
		}

		_getch();
	}
	
	else
	{
		cout << "   You jerk.. they're crying thier eyes out! No more taunting.. " << endl;
		_getch();
	}
}

void Game::Cheer(int input) // maybe have different cheer store for couch and zombie
{
	input = 0;

	if (playerId == 0)
	{
		system("cls");
		cout << endl;
		cout << "   CHEER STORE:" << endl;
		cout << "   You have " << player[0]->cheer << " cheer" << endl << endl;
		cout << "   1. RESTORE ALL SANITY - 65 cheer" << endl;
		cout << "   2. RESTORE 25 - Cost 35 cheer" << endl;
		cout << "   3. RESTORE 15 - Cost 30 cheer" << endl;

		cin >> input;
		cin.clear();
		cin.ignore(999999, '\n');

		if (player[0]->sanity < 250)
		{
			if (input == 1 && player[0]->cheer > 65)
			{
				player[0]->sanity = 250;
				player[0]->cheer -= 65;
				cout << "   You have restored 250 of your sanity." << endl;
				player[0]->insane = false;
				_getch();
			}
			else if (input == 2 && player[0]->cheer > 35)
			{
				player[0]->sanity += 25;
				player[0]->cheer -= 35;
				cout << "   You have restored 25 of your sanity." << endl;
				player[0]->insane = false;
				_getch();
			}
			else if (input == 3 && player[0]->cheer > 30)
			{
				player[0]->sanity += 15;
				player[0]->cheer -= 30;
				cout << "   You have restored 15 of your sanity." << endl;
				player[0]->insane = false;
				_getch();
			}
			else
			{
				cout << "   Either you dont have enough cheer or thats not a valid option.. you're not a couch, use your brain please." << endl;
				_getch();
			}
		}
		else
		{
			cout << "   You dont need these man, trust me." << endl;
			_getch();
		}
	}
	
	else if (playerId == 1)
	{
		system("cls");
		cout << endl;
		cout << "   CHEER STORE:" << endl;
		cout << "   You have " << player[0]->cheer << " cheer" << endl << endl;
		cout << "   1. RESTORE ALL SANITY - 45 cheer" << endl;
		cout << "   2. RESTORE 25 - Cost 30 cheer" << endl;
		cout << "   3. RESTORE 15 - Cost 15 cheer" << endl;

		cin >> input;
		cin.clear();
		cin.ignore(999999, '\n');

		if (player[0]->sanity < 150)
		{
			if (input == 1 && player[0]->cheer > 65)
			{
				player[0]->sanity = 250;
				player[0]->cheer -= 45;
				cout << "   You have restored 250 of your sanity." << endl;
				player[0]->insane = false;
				_getch();
			}
			else if (input == 2 && player[0]->cheer > 30)
			{
				player[0]->sanity += 25;
				player[0]->cheer -= 30;
				cout << "   You have restored 25 of your sanity." << endl;
				player[0]->insane = false;
				_getch();
			}
			else if (input == 3 && player[0]->cheer > 15)
			{
				player[0]->sanity += 15;
				player[0]->cheer -= 15;
				cout << "   You have restored 15 of your sanity." << endl;
				player[0]->insane = false;
				_getch();
			}
			else
			{
				cout << "   Either you dont have enough cheer or thats not a valid option.. you are a couch right? please grow up and act like one." << endl;
				_getch();
			}
		}
		else
		{
			cout << "   You dont need these man, trust me." << endl;
			_getch();
		}
	}

	if (player[0]->sanity > player[0]->sanityMax)
	{
		player[0]->sanity = player[0]->sanityMax;
	}
}

//work on overall game balancing