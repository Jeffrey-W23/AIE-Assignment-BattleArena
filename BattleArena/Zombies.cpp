#include "Zombies.h"

Zombies::Zombies()
{
	health = 150;
	sanity = 250;
}

Zombies::~Zombies()
{
}

int Zombies::Attack(AttackType attackType)
{
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

void Zombies::takeDamage(int damage)
{
	health -= damage;

	if (health < 0)
	{
		health = 0;
	}
}