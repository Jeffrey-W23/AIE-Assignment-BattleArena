#include "Couches.h"

Couches::Couches()
{
	health = 250;
	sanity = 100;
}

Couches::~Couches()
{
}

int Couches::Attack(AttackType attackType)
{
	if (attackType == reclin)
	{
		return 5;
	}
	else if (attackType == reclin)
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

void Couches::takeDamage(int damage)
{
	health -= damage;

	if (health < 0)
	{
		health = 0;
	}
}