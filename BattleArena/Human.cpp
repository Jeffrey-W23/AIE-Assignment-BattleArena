#include "Human.h"

Human::Human()
{
	monsterCount = 0;
}

Human::Human(int playertype)
{
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

Human::~Human()
{
	for (int i = 0; i < monsterCount; ++i)
	{
		delete army[i];
	}

	delete[] army;
}

int Human::Attack(int input) // return damage
{
	input = 0;

	int damage;

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
			damage = player[0]->Attack(bite);
			cout << "   You bite the couch dealing 30 damage!" << endl;
			return damage;
		}
		else if (input == 2)
		{
			damage = player[0]->Attack(scratch);
			cout << "   You scratch at the couch dealing 25 damage!" << endl;
			return damage;
		}
		else if (input == 3)
		{
			damage = player[0]->Attack(sit);
			cout << "   You sit on the couch.. this is a nasty move dealing 60 damage!" << endl;
			return damage;
		}
		else
		{
			cout << "   Thats not a valid attack.. you're not a couch, use your brain please." << endl;
			return 0;
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
			damage = player[0]->Attack(reclin);
			cout << "   You lay back and relax dealing 5 damage!" << endl;
			return damage;
		}
		else if (input == 2)
		{
			damage = player[0]->Attack(recliner);
			cout << "   You lay further back dealing 15 damage!" << endl;
			return damage;
		}
		else if (input == 3)
		{
			damage = player[0]->Attack(reclinerer);
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

int Human::Taunt() // return taunt
{
	int sanity;
	int randTaunt;

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

	cout << "   You taunt your opponent:" << endl << endl;
	cout << "   " << player[0]->Taunts(randTaunt) << endl;

	return sanity;

	player[0]->cheer += (sanity / 2);
}

void Human::Cheer(int input)
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
