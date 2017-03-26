//#include, using etc
#include "Human.h"

// Default Constructor
Human::Human()
{
	// initialize values
	monsterCount = 0;
}

// Constructor passing in the player type
Human::Human(int playertype)
{
	// initialize zombies army if zombies
	if (playertype == 0)
	{
		monsterCount = 5;
		army = new Monsters*[monsterCount];

		for (int i = 0; i < 5; i++)
		{
			army[i] = new Zombies();
			playerId = playertype;
		}
	}

	// initialize couches army if couches
	else if (playertype == 1)
	{
		monsterCount = 3;
		army = new Monsters*[monsterCount];

		for (int i = 0; i < 3; i++)
		{
			army[i] = new Couches();
			playerId = playertype;
		}
	}
}

// Default Destructor
Human::~Human()
{
	//delete human army
	for (int i = 0; i < monsterCount; ++i)
	{
		delete army[i];
	}

	delete[] army;
}

// Function for Attacking
int Human::Attack(int input) // return damage
{
	input = 0;

	int damage;

	// Make an attack if zombie
	if (playerId == 0)
	{
		// display options
		cout << endl;
		cout << "   SELECT ATTACK:" << endl;
		cout << "   1. BITE" << endl;
		cout << "   2. SCRATCH" << endl;
		cout << "   3. SIT" << endl;

		// get input
		cin >> input;
		cin.clear();
		cin.ignore(999999, '\n');

		// attacks
		if (input == 1)
		{
			damage = army[0]->Attack(bite);
			cout << "   You bite the couch dealing 30 damage!" << endl;
			return damage;
		}
		else if (input == 2)
		{
			damage = army[0]->Attack(scratch);
			cout << "   You scratch at the couch dealing 25 damage!" << endl;
			return damage;
		}
		else if (input == 3)
		{
			damage = army[0]->Attack(sit);
			cout << "   You sit on the couch.. this is a nasty move dealing 60 damage!" << endl;
			return damage;
		}
		else
		{
			cout << "   Thats not a valid attack.. you're not a couch, use your brain please." << endl;
			return 0;
		}
	}

	// Make an attack if couch
	else if (playerId == 1)
	{
		// display options
		cout << endl;
		cout << "   SELECT ATTACK:" << endl;
		cout << "   1. RECLIN" << endl;
		cout << "   2. RECLINER" << endl;
		cout << "   3. RECLINERER" << endl;

		// get input
		cin >> input;
		cin.clear();
		cin.ignore(999999, '\n');

		// attacks
		if (input == 1)
		{
			damage = army[0]->Attack(reclin);
			cout << "   You lay back and relax dealing 5 damage!" << endl;
			return damage;
		}
		else if (input == 2)
		{
			damage = army[0]->Attack(recliner);
			cout << "   You lay further back dealing 15 damage!" << endl;
			return damage;
		}
		else if (input == 3)
		{
			damage = army[0]->Attack(reclinerer);
			cout << "   You use your finishing move reclinerer! it deals an amazing 100 damage!" << endl;
			return damage;
		}
		else
		{
			cout << "   Thats not a valid attack.. you're not a couch, use your brain please." << endl;
			return 0;
		}
	}

	else
	{
		return 0;
	}
}

// Function for taunting
int Human::Taunt()
{
	//declare vars
	int sanity;
	int randTaunt;

	// set randoms input
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

	// get a random taunt message and taunt the player
	cout << endl;
	cout << "   You taunt your opponent:" << endl << endl;
	cout << "   " << army[0]->Taunts(randTaunt) << endl;

	// add some cheer points to the team member
	army[0]->cheer += (sanity / 2);

	cout << endl << endl << "   You got " << army[0]->cheer << " cheer points for this team member!" << endl;
	cout << "   Use these points in the cheer menu to make this team member feel better." << endl;
	return sanity;
}

// function for using the cheer store
void Human::Cheer(int input)
{
	input = 0;

	if (playerId == 0)
	{
		cout << endl;
		cout << "   CHEER STORE:" << endl;
		cout << "   You have " << army[0]->cheer << " cheer" << endl << endl;
		cout << "   1. RESTORE ALL SANITY - 65 cheer" << endl;
		cout << "   2. RESTORE 25 - Cost 35 cheer" << endl;
		cout << "   3. RESTORE 15 - Cost 30 cheer" << endl;

		cin >> input;
		cin.clear();
		cin.ignore(999999, '\n');

		if (army[0]->sanity < 250)
		{
			if (input == 1 && army[0]->cheer >= 65)
			{
				army[0]->sanity = 250;
				army[0]->cheer -= 65;
				cout << "   You have restored 250 of your sanity." << endl;
				army[0]->insane = false;
				cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
				_getch();
			}
			else if (input == 2 && army[0]->cheer >= 35)
			{
				army[0]->sanity += 25;
				army[0]->cheer -= 35;
				cout << "   You have restored 25 of your sanity." << endl;
				army[0]->insane = false;
				cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
				_getch();
			}
			else if (input == 3 && army[0]->cheer >= 30)
			{
				army[0]->sanity += 15;
				army[0]->cheer -= 30;
				cout << "   You have restored 15 of your sanity." << endl;
				army[0]->insane = false;
				cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
				_getch();
			}
			else
			{
				cout << "   Either you dont have enough cheer or thats not a valid option.. you're not a couch, use your brain please." << endl;
				cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
				_getch();
			}
		}
		else
		{
			cout << "   You dont need these man, trust me." << endl;
			cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
			_getch();
		}
	}

	else if (playerId == 1)
	{
		cout << endl;
		cout << "   CHEER STORE:" << endl;
		cout << "   You have " << army[0]->cheer << " cheer" << endl << endl;
		cout << "   1. RESTORE ALL SANITY - 45 cheer" << endl;
		cout << "   2. RESTORE 25 - Cost 30 cheer" << endl;
		cout << "   3. RESTORE 15 - Cost 15 cheer" << endl;

		cin >> input;
		cin.clear();
		cin.ignore(999999, '\n');

		if (army[0]->sanity < 150)
		{
			if (input == 1 && army[0]->cheer >= 45)
			{
				army[0]->sanity = 250;
				army[0]->cheer -= 45;
				cout << "   You have restored 250 of your sanity." << endl;
				army[0]->insane = false;
				cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
				_getch();
			}
			else if (input == 2 && army[0]->cheer >= 30)
			{
				army[0]->sanity += 25;
				army[0]->cheer -= 30;
				cout << "   You have restored 25 of your sanity." << endl;
				army[0]->insane = false;
				cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
				_getch();
			}
			else if (input == 3 && army[0]->cheer >= 15)
			{
				army[0]->sanity += 15;
				army[0]->cheer -= 15;
				cout << "   You have restored 15 of your sanity." << endl;
				army[0]->insane = false;
				cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
				_getch();
			}
			else
			{
				cout << "   Either you dont have enough cheer or thats not a valid option.. you are a couch right? please grow up and act like one." << endl;
				cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
				_getch();
			}
		}
		else
		{
			cout << "   You dont need these man, trust me." << endl;
			cout << endl << endl << "   PRESS ANY KEY TO CONTINUE..." << endl;
			_getch();
		}
	}

	if (army[0]->sanity > army[0]->sanityMax)
	{
		army[0]->sanity = army[0]->sanityMax;
	}
}
