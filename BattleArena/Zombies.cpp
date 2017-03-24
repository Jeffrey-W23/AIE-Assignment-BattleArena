#include "Zombies.h"
#include <iostream>
#include <conio.h>
using namespace std;

Zombies::Zombies()
{
	health = 150;
	sanity = 250;
	sanityMax = 250;
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

	cout << "   The zombie has " << health << " remaining." << endl;

	if (health < 0)
	{
		health = 0;
	}

	_getch();
}

void Zombies::lowerSanity(int damage)
{
	sanity -= damage;

	if (sanity < 100 && sanity > 20)
	{
		cout << endl << "   You see a tear forming under their eye.." << endl;
	}

	else if (sanity < 20 && sanity > 0)
	{
		cout << endl << "   You really seem to be getting to them now.. starting to cry a little.." << endl;
	}

	if (sanity < 0)
	{
		sanity = 0;
		insane = true;
	}

	_getch();
}

char* Zombies::Taunts(int tauntId)
{
	switch (tauntId)
	{
	case 0:		return "You point at the couch, put one hand behind your back and with the other you \n   make it look like you are about to spill a $30 bottle of wine all over them."; break;
	case 1:		return "iPad";						break;
	case 2:		return "AirPods";					break;
	case 3:		return "Apple Watch";				break;
	case 4:		return "MacBook";					break;
	case 5:		return "iCloud";					break;
	case 6:		return "iMac";						break;
	case 7:		return "AirDrop";					break;
	case 8:		return "Apple Pencil";				break;
	case 9:		return "Night Shift";				break;
	default:	return " ";							break;
	}
}