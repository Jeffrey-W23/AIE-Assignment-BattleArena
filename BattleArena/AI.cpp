//#include, using etc
#include "AI.h"

// Default Constructor
AI::AI()
{
	// initialize values
	monsterCount = 0;
}

// Constructor passing in the player type
AI::AI(int playertype)
{
	// initialize couches army if couches
	if (playertype == 0)
	{
		monsterCount = 3;
		army = new Monsters*[monsterCount];

		for (int i = 0; i < 3; i++)
		{
			army[i] = new Couches();
			playerId = playertype;
		}
	}

	// initialize zombies army if zombies
	else if (playertype == 1)
	{
		monsterCount = 5;
		army = new Monsters*[monsterCount];

		for (int i = 0; i < 5; i++)
		{
			army[i] = new Zombies();
			playerId = playertype;
		}
	}
}

// Default Destructor
AI::~AI()
{
	//delete AI army
	for (int i = 0; i < monsterCount; ++i)
	{
		delete army[i];
	}

	delete[] army;
}

// Function for Attacking
int AI::Attack(int input) // return damage
{
	int damage = 0;

	// Make an attack if zombie
	if (playerId == 1)
	{
		if (input == 1)
		{
			damage = army[0]->Attack(bite);
			cout << "   The zombie bites you! this deals 30 damage!" << endl;
			return damage;
		}
		else if (input == 2)
		{
			damage = army[0]->Attack(scratch);
			cout << "   The zombie scratches you dealing 25 damage!" << endl;
			return damage;
		}
		else if (input == 3)
		{
			damage = army[0]->Attack(sit);
			cout << "   The zombie sits on you.. this is a nasty move dealing 60 damage!" << endl;
			return damage;
		}
	}

	// Make an attack if couch
	else if (playerId == 0)
	{
		if (input == 1)
		{
			damage = army[0]->Attack(reclin);
			cout << "   The couch lays back dealing 5 damage!" << endl;
			return damage;
		}
		else if (input == 2)
		{
			damage = army[0]->Attack(recliner);
			cout << "   The couch lays further back dealing 15 damage!" << endl;
			return damage;
		}
		else if (input == 3)
		{
			damage = army[0]->Attack(reclinerer);
			cout << "   The couch is using the finishing move reclinerer! it deals an amazing 100 damage!" << endl;
			return damage;
		}
	}

	else
	{
		return 0;
	}

	return 0;
}

// Function for taunting
int AI::Taunt()
{
	// declare vars
	int sanity;
	int randTaunt;

	// get random inputs for AI
	if (playerId == 1)
	{
		sanity = rand() % 35;
		randTaunt = rand() % 10;
	}
	else if (playerId == 0)
	{
		sanity = rand() % 28;
		randTaunt = rand() % 10;
	}

	// get a random taunt message and taunt the player
	cout << endl << "   The opponent taunts you:" << endl << endl;
	cout << "   " << army[0]->Taunts(randTaunt) << endl;

	// add some cheer points to the team member
	army[0]->cheer += (sanity / 2);
	return sanity;
}