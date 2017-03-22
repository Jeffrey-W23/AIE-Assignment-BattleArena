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

void Zombies::lowerSanity(int damage)
{
	sanity -= damage;

	if (sanity < 0)
	{
		sanity = 0;
	}
}

char* Zombies::Taunts(int tauntId)
{
	switch (tauntId)
	{
	case 0:		return "iPhone";					break;
	case 1:		return "iPad";						break;
	case 2:		return "AirPods";					break;
	case 3:		return "Apple Watch";				break;
	case 4:		return "MacBook";					break;
	case 5:		return "iCloud";					break;
	case 6:		return "iMac";						break;
	case 7:		return "AirDrop";					break;
	case 8:		return "Apple Pencil";				break;
	case 9:		return "Night Shift";				break;
	}
}