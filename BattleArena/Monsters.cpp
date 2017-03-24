#include "Monsters.h"

Monsters::Monsters()
{
	cheer = 0;
	insane = false;
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

void Monsters::Insane()
{
	if (insane)
	{
		health -= -10;
	}
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
