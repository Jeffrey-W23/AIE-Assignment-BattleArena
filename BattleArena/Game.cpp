//#include, using etc
#include "Game.h"
#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

// Default Constructor
Game::Game()
{
}

//  Constructor passing in the player type
Game::Game(int playertype)
{
	// create a new human and ai object
	human = new Human(playertype);
	ai = new AI(playertype);
}

// Default Destructor
Game::~Game()
{
	// delete player and ai
	delete human;
	delete ai;
}

// main game function
void Game::MainFunction()
{
	int userInput;

	// start match loop
	bool gameRunning = true;
	while (gameRunning)
	{
		//Sort teams by remaining health
		human->BubbleSort(); // Bubble Sort (Sort type 1) 
		ai->InsertionSort(); // Insertion Sort (Sort type 2)

		// Display both teams health
		system("cls");
		ShowHealth();

		//Check if a team has lost or won
		gameRunning = CheckWin();

		// Display the options for the players turn
		cout << endl << "   ACTIONS:" << endl;
		cout << "   1. ATTACK" << endl;
		cout << "   2. TAUNT" << endl;
		cout << "   3. CHEER UP" << endl << endl;

		// get input for player options
		cin >> userInput;
		cin.clear();
		cin.ignore(999999, '\n');

		// Do player turn
		PlayerTurn(userInput);

		//check if a team has lost or won
		gameRunning = CheckWin();

		// Do AI turn
		system("cls");
		ShowHealth();
		AITurn();

		//Check sanity
		CheckInsane();
	}
}

// function for checking if a team member is insane
void Game::CheckInsane()
{
	// get the team counts
	int AICount = ai->monsterCount;
	int HumanCount = human->monsterCount;

	// Check if the player is insane
	for (int i = 0; i < HumanCount; i++)
	{
		human->army[i]->Insane();

		if (human->army[i]->insane)
		{
			cout << endl << "   One of your team members is losing 10 health a turn. Better try and cheer them up." << endl;
			cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
			_getch();
		}
	}

	// Check if the AI is insane
	for (int i = 0; i < AICount; i++)
	{
		ai->army[i]->Insane();
		
		if (ai->army[i]->insane)
		{
			cout << endl << "   One of the AI team members is losing 10 health a turn. Keep up that taunting!" << endl;
			cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
			_getch();
		}
	}
}

// display health function
void Game::ShowHealth()
{
	// get the team counts
	int AICount = ai->monsterCount;
	int HumanCount = human->monsterCount;

	// Display player team health
	cout << endl;
	cout << "   YOUR TEAM: " << endl;

	for (int i = 0; i < HumanCount; i++)
	{
		cout << "   " << human->army[i]->health << "H " << human->army[i]->cheer << "C";
	}

	cout << endl << endl;

	// Display AI team health
	cout << "   ENEMY TEAM: " << endl;

	for (int i = 0; i < AICount; i++)
	{
		cout << "   " << ai->army[i]->health << "H";
	}

	cout << endl << endl << endl;
}

// Function to check if someone has won
bool Game::CheckWin()
{
	// get team count
	int AICount = ai->monsterCount;
	int HumanCount = human->monsterCount;
	int temp;

	temp = 0;

	// Display lose
	for (int i = 0; i < HumanCount; i++)
	{
		// check that all of the team is 0 health
		if (human->army[i]->health == 0)
		{
			temp += 1;

			if (temp == HumanCount)
			{
				system("cls");
				cout << endl << "     __     ______  _    _   _      ____   _____ ______ _ " << endl;
				cout << "     \\ \\   / / __ \\| |  | | | |    / __ \\ / ____|  ____| |" << endl;
				cout << "      \\ \\_/ / |  | | |  | | | |   | |  | | (___ | |__  | |" << endl;
				cout << "       \\   /| |  | | |  | | | |   | |  | |\\___ \\|  __| | |" << endl;
				cout << "        | | | |__| | |__| | | |___| |__| |____) | |____|_|" << endl;
				cout << "        |_|  \\____/ \\____/  |______\\____/|_____/|______(_)" << endl;
				cout << "              YOU LOSE :( SORRY THEY WERE SO MEAN.." << endl;

				cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
				_getch();
				return false;
			}
		}
	}

	temp = 0;

	// Display Win
	for (int i = 0; i < AICount; i++)
	{
		// check that all of the team is 0 health
		if (ai->army[i]->health == 0)
		{
			temp += 1;

			if (temp == AICount)
			{
				system("cls");
				cout << endl << "     __          _______ _   _ _   _ ______ _____  _ " << endl;
				cout << "     \\ \\        / /_   _| \\ | | \\ | |  ____|  __ \\| |" << endl;
				cout << "      \\ \\  /\\  / /  | | |  \\| |  \\| | |__  | |__) | |" << endl;
				cout << "       \\ \\/  \\/ /   | | | . ` | . ` |  __| |  _  /| |" << endl;
				cout << "        \\  /\\  /   _| |_| |\\  | |\\  | |____| | \\ \\|_|" << endl;
				cout << "         \\/  \\/   |_____|_| \\_|_| \\_|______|_|  \\_(_)" << endl;
				cout << "   YOU WIN! YOU HAVE KILLED/BULLIED ALL OF THE ENEMY TEAM!" << endl;

				cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
				_getch();
				return false;
			}
		}
	}

	return true;
}

// Run the players turn
void Game::PlayerTurn(int input)
{
	// Attack
	if (input == 1)
	{
		system("cls");
		ShowHealth();

		// set the damage
		int damage = human->Attack(input);
		
		// Apply the damage
		ai->army[0]->takeDamage(damage, 1);
		
		cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
		_getch();
	}

	// Taunt
	else if (input == 2)
	{
		if (ai->army[0]->sanity > 0)
		{
			system("cls");
			ShowHealth();

			// Set the taunt damage
			int taunt = human->Taunt();

			// Apply the taunt damage
			ai->army[0]->lowerSanity(taunt, 1);

			cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
			_getch();
		}

		// Message to display if youve taunted them to much
		else
		{
			system("cls");
			ShowHealth();
			cout << endl << "   You jerk.. they're crying thier eyes out! No more taunting.. " << endl;
			cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
			_getch();
		}
	}

	// Cheer
	else if (input == 3)
	{
		system("cls");
		ShowHealth();

		// Go to the cheer store
		human->Cheer(input);
	}

	// invalid input
	else
	{
		system("cls");
		ShowHealth();
		input = 0;
		cout << endl << "   You can do nothing if you like?" << endl;
		cout << "   Thats what I thought, please make a valid choice" << endl;
		cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
		_getch();
	}
}

// Run the AI teams turn
void Game::AITurn()
{
	// Create a random input for the AI attack selection
	int input = 0;
	input = rand() % 2 + 1;

	// Attack
	if (input == 1)
	{
		system("cls");
		ShowHealth();
		input = 0;
		input = rand() % 3 + 1;
		
		// Find out the damage
		int damage = ai->Attack(input);

		// Apply for damage
		human->army[0]->takeDamage(damage, 2);
		
		cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
		_getch();
	}

	// Taunt
	else if (input == 2)
	{
		if (human->army[0]->sanity > 0)
		{
			system("cls");
			ShowHealth();
			
			// Find out the taunt damage
			int taunt = ai->Taunt();

			// Apply the taunt damage
			human->army[0]->lowerSanity(taunt, 2);
			
			cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
			_getch();
		}

		// Message to display if youve been taunted to much
		else
		{
			system("cls");
			ShowHealth();
			cout << endl << "   They continue to taunt you even though you're already crying. Good thing you're so sad you hardly notice.. " << endl;
			cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
			_getch();
		}
	}
}