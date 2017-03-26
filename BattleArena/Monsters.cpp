//#include, using etc
#include "Monsters.h"

// Default Constructor
Monsters::Monsters()
{
	// initialize values
	cheer = 0;
	insane = false;
}

// Default Destructor
Monsters::~Monsters()
{
}

// Function for attacking
int Monsters::Attack(AttackType attackType)
{
	return 0;
}

// Function for applying damage to the monster
void Monsters::takeDamage(int damage, int playerType)
{

}

// Function for applying taunts to the monster
void Monsters::lowerSanity(int damage, int playerType)
{

}

// Function to taunt another monster
char* Monsters::Taunts(int tauntId)
{
	return "";
}

// function for weather a monster is insane or not
void Monsters::Insane()
{

}
