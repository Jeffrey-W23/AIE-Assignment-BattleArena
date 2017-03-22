#include "Monsters.h"

Monsters::Monsters()
{
	cheer = 0;
}

Monsters::~Monsters()
{
}

int Monsters::Attack(AttackType attackType)
{
	return 0;
}

void Monsters::takeDamage(int damage)
{

}

void Monsters::lowerSanity(int damage)
{

}

char* Monsters::Taunts(int tauntId)
{
	return "";
}

bool Monsters::Alive()
{
	if (health > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
