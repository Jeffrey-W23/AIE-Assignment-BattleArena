//#include, using etc
#include "Zombies.h"
#include <iostream>
#include <conio.h>
using namespace std;

// Default Constructor
Zombies::Zombies()
{
	// initialize values
	health = 150;
	sanity = 250;
	sanityMax = 250;
}

// Default Destructor
Zombies::~Zombies()
{
}

// Function for attacking
int Zombies::Attack(AttackType attackType)
{
	// return different amount of damage for different attacktypes
	if (attackType == bite)
	{
		return 30;
	}
	else if (attackType == scratch)
	{
		return 25;
	}
	else if (attackType == sit)
	{
		return 60;
	}
	else
	{
		return 0;
	}
}

// Function for applying damage to the monster
void Zombies::takeDamage(int damage, int playerType)
{
	// Take damage and apply it to monsters health
	health -= damage;

	// display message depending on who is playing
	if (playerType == 1)
	{
		cout << "   The zombie has " << health << " remaining health." << endl;
	}
	else if (playerType == 2)
	{
		cout << "   You have " << health << " health remaining." << endl;
	}

	// make sure that if a monster dies it stays at zero
	if (health < 0)
	{
		health = 0;
	}
}

// Function for applying taunts to the monster
void Zombies::lowerSanity(int damage, int playerType)
{
	// lower sanity and apply it monsters
	sanity -= damage;

	// display message depend on how much sanity is left
	if (sanity < 100 && sanity > 20)
	{
		if (playerType == 1)
		{
			cout << endl << "   You see a tear forming under their eye.." << endl;

		}
		else if (playerType == 2)
		{
			cout << endl << "   You feel a tear forming under your eye.." << endl;
		}
	}

	else if (sanity < 20 && sanity > 0)
	{
		if (playerType == 1)
		{
			cout << endl << "   You really seem to be getting to them now.. starting to cry a little.." << endl;

		}
		else if (playerType == 2)
		{
			cout << endl << "   It seems that this guy is getting to you.. you start to cry a little.." << endl;
		}
	}

	// make sure sanity is 0 when a monster runs out
	if (sanity < 0)
	{
		sanity = 0;

		// set the monster to insane
		insane = true;
	}
}

// function for weather a monster is insane or not
void Zombies::Insane()
{
	// if a team member goes insanse they lose 10 health per turn
	if (insane)
	{
		health -= 10;
	}
}

// Function to taunt another monster
char* Zombies::Taunts(int tauntId)
{
	// List of taunts that are randomly thrown at each player
	switch (tauntId)
	{
	case 0:		return "Zombie points at the couch, puts one hand behind its back and with the other \n   makes it look like they are about to spill a $30 bottle of wine all over the couch."; break;
	case 1:		return "Lazyboy? more like lazy, am right?"; break;
	case 2:		return "You put the potatoe in couch potatoe."; break;
	case 3:		return "Id rather watch Netflix from a bed."; break;
	case 4:		return "I bet you're one of those 1 cushion couches."; break;
	case 5:		return "Zombie grabs a cracker out of its back pocket and starts crushing it in its hand. The zombie then starts to throw it towards the couch almost hitting."; break;
	case 6:		return "The most Id watch sitting on you would be the opening of The Walking Dead."; break;
	case 7:		return "Insert couch joke"; break;
	case 8:		return "I'll bend your recliner the wrong way."; break;
	case 9:		return "Is that a coin down your crack?"; break;
	default:	return " "; break;
	}
}