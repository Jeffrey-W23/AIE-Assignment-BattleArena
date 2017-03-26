//#include, using etc
#include "Couches.h"
#include <iostream>
#include <conio.h>
using namespace std;

// Default Constructor
Couches::Couches()
{
	// initialize values
	health = 250;
	sanity = 150;
	sanityMax = 150;
}

// Default Destructor
Couches::~Couches()
{
}

// Function for attacking
int Couches::Attack(AttackType attackType)
{
	// return different amount of damage for different attacktypes
	if (attackType == reclin)
	{
		return 5;
	}
	else if (attackType == recliner)
	{
		return 15;
	}
	else if (attackType == reclinerer)
	{
		return 100;
	}
	else
	{
		return 0;
	}
}

// Function for applying damage to the monster
void Couches::takeDamage(int damage, int playerType)
{
	// Take damage and apply it to monsters health
	health -= damage;

	// display message depending on who is playing
	if (playerType == 1)
	{
		cout << "   The couch has " << health << " remaining health." << endl;
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
void Couches::lowerSanity(int damage, int playerType)
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
void Couches::Insane()
{
	// if a team member goes insanse they lose 10 health per turn
	if (insane)
	{
		health -= 20;
	}
}

char* Couches::Taunts(int tauntId)
{
	// List of taunts that are randomly thrown at each player
	switch (tauntId)
	{
	case 0:		return "The couch sits back and relaxes. This greatly annoys the Zombie for some reason."; break;
	case 1:		return "The couch starts to make jokes about the lack of a brain. Couch is possibly confused, Zombie is offended anyway."; break;
	case 2:		return "All the couch does is open its recliner and the zombie is offended."; break;
	case 3:		return "You're as dumb as a Zombie from PvZ."; break;
	case 4:		return "You look like a tall ET."; break;
	case 5:		return "Couches are smarter."; break;
	case 6:		return "The Couch starts to imitate the zombie, doesnt look like its doing anything. Never the less the Zombie is effected."; break;
	case 7:		return "The dev who created you didnt like you."; break;
	case 8:		return "The Zombie is offended by the fact that you choose the taunt option."; break;
	case 9:		return "They wouldnt hire you for a horror film."; break;
	default:	return " ";	break;
	}
}